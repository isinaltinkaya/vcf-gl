#include "lut.h"


// [R] paste0("const int lut_qscore2[", n + 1, "] = {", paste(sapply(0:n, function(n) n*n),collapse = ", "),"};")
const int lut_qscore2[64] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844, 3969};


const char SIM_ALLELES[5]={'A','C','G','T','N'};

const int acgt_genotype_order_lut[10]={0,1,4,2,5,7,3,6,8,9};

const int offsets[4][10]={
	{0,1,2,3,  4,5,6,7,8,9},//AA,AC,AG,AT,therest
	{4,1,5,6,  0,2,3,7,8,9},//CC,AC,CG,CT,therest
	{7,2,5,8,  0,1,3,4,6,9},//GG,AG,CG,GT,therest
	{9,3,6,8,  0,1,2,4,5,7},//TT,AT,CT,GT,therest
};


