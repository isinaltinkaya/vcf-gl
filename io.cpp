#include "io.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <sys/stat.h>
#include <htslib/kstring.h> // kstring_t
#include <stdio.h>


void help_page(){
		fprintf(stderr,"\n");
		fprintf(stderr,"vcfgl\n\n");
		fprintf(stderr,"\tUsage: ./vcfgl -i <input> [options]\n\n");
		fprintf(stderr,"\n");
		fprintf(stderr,"Options:\n");


		fprintf(stderr,"\t-i/-in/--input\t\t\tInput file (required)\n");
		fprintf(stderr,"\t-o/-out/--output\t\tOutput file prefix (default:output)\n");
		fprintf(stderr,"\t-O/--output-mode\t\tOutput mode (default:b)\n");
		fprintf(stderr,"\t\t\t\t\tv\tVCF file\n");
		fprintf(stderr,"\t\t\t\t\tb\tBCF file\n");
		fprintf(stderr,"\t\t\t\t\tz\tCompressed VCF file (vcf.gz)\n");
		fprintf(stderr,"\t\t\t\t\tb\tUncompressed BCF file\n");
		fprintf(stderr,"\t-err/--error-rate\t\tError rate (default:0.01)\n");
		fprintf(stderr,"\t-d/-depth/--depth\t\tMean per-site read depth (default:1.0)\n");
		fprintf(stderr,"\t-df/--depths-file\t\tFile containing mean per-site read depth for each sample (conflicts with -d)\n");
		fprintf(stderr,"\t\t\t\t\tUse `--depth inf` to set the simulated values to known true variables\n");

		fprintf(stderr,"\t-pos0\t\t\t\tIs the start position 0-based? If -pos0 1 is used, all positions in the file will be shifted by +1\n");
		fprintf(stderr,"\t-seed\t\t\t\tRandom seed used to initialize the random number generator\n");
		fprintf(stderr,"\t-explode\t\t\tExplode to unobserved sites in the input file (default:0=disabled)\n");
		fprintf(stderr,"\n");
		fprintf(stderr,"\t-printBaseCounts\t\tPrint base counts (default:0=disabled)\n");
		fprintf(stderr,"\t-addGP\t\t\t\tAdd GP field (default:0=disabled)\n");
		fprintf(stderr,"\t-addPL\t\t\t\tAdd PL field (default:0=disabled)\n");
		fprintf(stderr,"\t-addI16\t\t\t\tAdd I16 field (default:0=disabled)\n");
		fprintf(stderr,"\t-addQS\t\t\t\tAdd QS field (default:0=disabled)\n");

		fprintf(stderr,"\n");
}


argStruct *args_init(){

	argStruct *args=(argStruct*)calloc(1,sizeof(argStruct));

	args->out_fp=NULL;

	args->in_fn=NULL;
	args->pos0=0;

	args->addGP=0;
	args->addPL=0;
	args->addI16=0;
	args->addQS=0;

	args->mps_depth=1.0;
	args->in_mps_depths=NULL;
	args->errate=0.01;
	args->seed=-1;
	args->explode = 0;
	args->printBaseCounts=0;
	return args;

}

void args_destroy(argStruct* args){
	
	free(args->in_fn);
	free(args->out_fp);
	free(args->output_mode);
	free(args);

}



argStruct *args_get(int argc, char **argv){

	argStruct *args = args_init(); 

	while(*argv){


		char *arv=*argv;
		char *val=*(++argv);

		if(strcasecmp("-in",arv)==0) args->in_fn=strdup(val);
		else if(strcasecmp("-i",arv)==0) args->in_fn=strdup(val);
		else if(strcasecmp("--input",arv)==0) args->in_fn=strdup(val);

		else if(strcmp("-o",arv)==0) args->out_fp=strdup(val); 
		else if(strcasecmp("-out",arv)==0) args->out_fp=strdup(val); 
		else if(strcasecmp("--output",arv)==0) args->out_fp=strdup(val); 

		else if(strcmp("-O",arv)==0) args->output_mode=strdup(val);
		else if(strcasecmp("--output-mode",arv)==0) args->output_mode=strdup(val);

		else if(strcasecmp("-err",arv)==0) args->errate=atof(val); 
		else if(strcasecmp("--error-rate",arv)==0) args->errate=atof(val); 

		else if( (strcasecmp("-d",arv)==0) || (strcasecmp("-depth",arv)==0) || (strcasecmp("--depth",arv)==0) ){
			char* tmp=strdup(val);
			bool is_number=true;
			int i=0;
			if(tmp[0]=='-') i=1;
			for (;tmp[i]!=0;++i){
				if(!isdigit(tmp[i])){
					if(tmp[i]=='.') continue;
					is_number=false;
					if(strcasecmp("inf",tmp+i)==0){
						args->mps_depth=-999;
					}
				}
			}
			free(tmp);
			tmp=NULL;
			if(is_number){
				args->mps_depth=atof(val);
			}else if(-999!=args->mps_depth){
				ERROR("--depth is set to unknown value %s",val);
			}
		}


		else if(strcasecmp("-df",arv)==0) args->in_mps_depths=strdup(val); 
		else if(strcasecmp("--depths-file",arv)==0) args->in_mps_depths=strdup(val); 

		else if(strcasecmp("-pos0",arv)==0) args->pos0=atoi(val);

		else if(strcasecmp("-seed",arv)==0) args->seed=atoi(val);

		else if(strcasecmp("-explode",arv)==0) args->explode=atoi(val);

		else if(strcasecmp("-printBaseCounts",arv)==0) args->printBaseCounts=atoi(val);

		else if(strcasecmp("-addGP",arv)==0) args->addGP=atoi(val);
		else if(strcasecmp("-addPL",arv)==0) args->addPL=atoi(val);
		else if(strcasecmp("-addI16",arv)==0) args->addI16=atoi(val);
		else if(strcasecmp("-addQS",arv)==0) args->addQS=atoi(val);

		else{
			fprintf(stderr,"Unknown arg:%s\n",arv);
			free(args);
			return 0;
		}
		++argv; 
	} 


	if (1==args->addI16){
		WARNING("-addI16 1 is used. Will set mapping quality-related I16 values to 0.");
	}

	if (args->seed == -1){
		int rseed=time(NULL);
		fprintf(stderr,"\n-> No seed was given. Setting the random seed to the randomly chosen value: %d",rseed);
		args->seed=rseed;
	}
	srand48(args->seed);

	if(args->in_fn==NULL){
		fprintf(stderr,"Must supply -in\n");
		free(args);
		return 0;
	}

	if(NULL==args->output_mode){
		args->output_mode=strdup("b");
	}

	if(NULL==args->out_fp){
		args->out_fp=strdup("output");
	}

	return args;

}


size_t fsize(const char* fname){
	struct stat st ;
	stat(fname,&st);
	return st.st_size;
}




//modified from msToGlf.c
double *read_depthsFile(const char* fname,int len){
	fprintf(stderr, "Reading depths file: %s for %d samples\n",fname, len);

	FILE *fp = NULL;
	if((fp=fopen(fname,"r"))==NULL){
		fprintf(stderr,"Problem opening file: %s\n",fname);
		exit(0);
	}

	char *buf = (char*) malloc(sizeof(char) * fsize(fname));
	double *ret = (double*) malloc(len*sizeof(double));
	if(fsize(fname)!=fread(buf,sizeof(char),fsize(fname),fp)){
		fprintf(stderr,"Problem reading file=%s\n",fname);
		exit(0);
	}
	int posi=0;

	ret[posi++] = atof(strtok(buf,"\n\t "));
	char *tok;
	while((tok=strtok(NULL,"\n\t "))) 
		ret[posi++] = atof(tok);

	return ret;
}


kstring_t *kbuf_init() {
    kstring_t *kbuf = new kstring_t;
    kbuf->l = 0;
    kbuf->m = 0;
    kbuf->s = NULL;
    return kbuf;
}

void kbuf_destroy(kstring_t *kbuf) {
    if (NULL != kbuf) {
        free(kbuf->s);
		kbuf->s=NULL;
        delete kbuf;
    }
}


