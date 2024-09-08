#include "shared.h"

/* LOOKUP TABLES
 * --------------------------------------------------------------*/



const int lut_char_to_acgt_int[85] = {
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 0, ... ,8
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 9, ... ,17
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 18, ... ,26
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 27, ... ,35
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 36, ... ,44
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 45, ... ,53
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 54, ... ,62
  -1, -1, 0, -1, 1, -1, -1, -1, 2, // 63, ... (65=='A'==0) ... (67=='C'==1) ... (71=='G'==2)
  -1, -1, -1, -1, -1, -1, -1, -1, -1, // 72, ... ,80
  -1, -1, -1, 3  // 81, ... (84=='T'==3) ... ,89
};

const int lut_qs_to_qs2[63] = {
    0,    1,    4,    9,    16,   25,   36,   49,   64,   81,   100,
    121,  144,  169,  196,  225,  256,  289,  324,  361,  400,  441,
    484,  529,  576,  625,  676,  729,  784,  841,  900,  961,  1024,
    1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764, 1849,
    1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 2704, 2809, 2916,
    3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844 };

const int lut_nAlleles_to_nGenotypes[6] = { 0, 1, 3, 6, 10, 15 };

const double qScore_to_errorProb[63] = { 1,
                                        0.7943282,
                                        0.6309573,
                                        0.5011872,
                                        0.3981072,
                                        0.3162278,
                                        0.2511886,
                                        0.1995262,
                                        0.1584893,
                                        0.1258925,
                                        0.1,
                                        0.07943282,
                                        0.06309573,
                                        0.05011872,
                                        0.03981072,
                                        0.03162278,
                                        0.02511886,
                                        0.01995262,
                                        0.01584893,
                                        0.01258925,
                                        0.01,
                                        0.007943282,
                                        0.006309573,
                                        0.005011872,
                                        0.003981072,
                                        0.003162278,
                                        0.002511886,
                                        0.001995262,
                                        0.001584893,
                                        0.001258925,
                                        0.001,
                                        0.0007943282,
                                        0.0006309573,
                                        0.0005011872,
                                        0.0003981072,
                                        0.0003162278,
                                        0.0002511886,
                                        0.0001995262,
                                        0.0001584893,
                                        0.0001258925,
                                        0.0001,
                                        0.00007943282,
                                        0.00006309573,
                                        0.00005011872,
                                        0.00003981072,
                                        0.00003162278,
                                        0.00002511886,
                                        0.00001995262,
                                        0.00001584893,
                                        0.00001258925,
                                        0.00001,
                                        0.000007943282,
                                        0.000006309573,
                                        0.000005011872,
                                        0.000003981072,
                                        0.000003162278,
                                        0.000002511886,
                                        0.000001995262,
                                        0.000001584893,
                                        0.000001258925,
                                        0.000001,
                                        0.0000007943282,
                                        0.0000006309573
};

const double qScore_to_gl[3][257] = { 
  {0,0.2056718,0.3690427,0.4988128,0.6018928,0.6837722,0.7488114,0.8004738,0.8415107,0.8741075,0.9,0.9205672,0.9369043,0.9498813,0.9601893,0.9683772,0.9748811,0.9800474,0.9841511,0.9874107,0.99,0.9920567,0.9936904,0.9949881,0.9960189,0.9968377,0.9974881,0.9980047,0.9984151,0.9987411,0.999,0.9992057,0.999369,0.9994988,0.9996019,0.9996838,0.9997488,0.9998005,0.9998415,0.9998741,0.9999,0.9999206,0.9999369,0.9999499,0.9999602,0.9999684,0.9999749,0.99998,0.9999842,0.9999874,0.99999,0.9999921,0.9999937,0.999995,0.999996,0.9999968,0.9999975,0.999998,0.9999984,0.9999987,0.999999,0.9999992,0.9999994,0.9999995,0.9999996,0.9999997,0.9999997,0.9999998,0.9999998,0.9999999,0.9999999,0.9999999,0.9999999,0.9999999,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {0.1666667,0.2352239,0.2896809,0.3329376,0.3672976,0.3945907,0.4162705,0.4334913,0.4471702,0.4580358,0.4666667,0.4735224,0.4789681,0.4832938,0.4867298,0.4894591,0.491627,0.4933491,0.494717,0.4958036,0.4966667,0.4973522,0.4978968,0.4983294,0.498673,0.4989459,0.4991627,0.4993349,0.4994717,0.4995804,0.4996667,0.4997352,0.4997897,0.4998329,0.4998673,0.4998946,0.4999163,0.4999335,0.4999472,0.499958,0.4999667,0.4999735,0.499979,0.4999833,0.4999867,0.4999895,0.4999916,0.4999933,0.4999947,0.4999958,0.4999967,0.4999974,0.4999979,0.4999983,0.4999987,0.4999989,0.4999992,0.4999993,0.4999995,0.4999996,0.4999997,0.4999997,0.4999998,0.4999998,0.4999999,0.4999999,0.4999999,0.4999999,0.4999999,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5},
  {0.3333333,0.2647761,0.2103191,0.1670624,0.1327024,0.1054093,0.08372955,0.06650874,0.05282977,0.04196418,0.03333333,0.02647761,0.02103191,0.01670624,0.01327024,0.01054093,0.008372955,0.006650874,0.005282977,0.004196418,0.003333333,0.002647761,0.002103191,0.001670624,0.001327024,0.001054093,0.0008372955,0.0006650874,0.0005282977,0.0004196418,0.0003333333,0.0002647761,0.0002103191,0.0001670624,0.0001327024,0.0001054093,0.00008372955,0.00006650874,0.00005282977,0.00004196418,0.00003333333,0.00002647761,0.00002103191,0.00001670624,0.00001327024,0.00001054093,0.000008372955,0.000006650874,0.000005282977,0.000004196418,0.000003333333,0.000002647761,0.000002103191,0.000001670624,0.000001327024,0.000001054093,0.0000008372955,0.0000006650874,0.0000005282977,0.0000004196418,0.0000003333333,0.0000002647761,0.0000002103191,0.0000001670624,0.0000001327024,0.0000001054093,0.00000008372955,0.00000006650874,0.00000005282977,0.00000004196418,0.00000003333333,0.00000002647761,0.00000002103191,0.00000001670624,0.00000001327024,0.00000001054093,0.000000008372955,0.000000006650874,0.000000005282977,0.000000004196418,0.000000003333333,0.000000002647761,0.000000002103191,0.000000001670624,0.000000001327024,0.000000001054093,0.0000000008372955,0.0000000006650874,0.0000000005282977,0.0000000004196418,0.0000000003333333,0.0000000002647761,0.0000000002103191,0.0000000001670624,0.0000000001327024,0.0000000001054092,0.00000000008372954,0.00000000006650876,0.00000000005282978,0.00000000004196417,0.00000000003333334,0.0000000000264776,0.00000000002103192,0.00000000001670623,0.00000000001327024,0.00000000001054094,0.000000000008372969,0.000000000006650865,0.000000000005282959,0.000000000004196421,0.000000000003333334,0.000000000002647771,0.000000000002103206,0.000000000001670627,0.000000000001327013,0.000000000001054083,0.0000000000008372932,0.0000000000006650976,0.0000000000005282811,0.0000000000004196273,0.000000000000333326,0.0000000000002647882,0.0000000000002103132,0.0000000000001670516,0.0000000000001327087,0.0000000000001053972,0.00000000000008374782,0.00000000000006650236,0.00000000000005284662,0.00000000000004196643,0.0000000000000333437,0.00000000000002646032,0.00000000000002102022,0.00000000000001669035,0.00000000000001328567,0.00000000000001054712,0.00000000000000836368,0.000000000000006661338,0.000000000000005292063,0.00000000000000418184,0.000000000000003330669,0.000000000000002664535,0.000000000000002109424,0.000000000000001665335,0.000000000000001332268,0.000000000000001036208,0.000000000000000851171,0.0000000000000006661338,0.0000000000000005181041,0.0000000000000004070818,0.0000000000000003330669,0.000000000000000259052,0.0000000000000002220446,0.0000000000000001850372,0.0000000000000001480297,0.0000000000000001110223,0.00000000000000007401487,0.00000000000000007401487,0.00000000000000003700743,0.00000000000000003700743,0.00000000000000003700743,0.00000000000000003700743,0.00000000000000003700743,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


const double qScore_to_ln_gl[3][257] = {
  {NEG_INF,-1.581474,-0.996843,-0.6955245,-0.5076759,-0.3801304,-0.2892682,-0.2225515,-0.1725566,-0.134552,-0.1053605,-0.0827653,-0.06517417,-0.05141827,-0.04062484,-0.03213357,-0.02543973,-0.02015436,-0.01597587,-0.01266917,-0.01005034,-0.007974998,-0.006329563,-0.005024474,-0.003989017,-0.003167288,-0.002515047,-0.001997256,-0.00158615,-0.001259719,-0.0010005,-0.0007946439,-0.0006311565,-0.0005013129,-0.0003981864,-0.0003162778,-0.0002512202,-0.0001995461,-0.0001585019,-0.0001259005,-0.000100005,-0.00007943598,-0.00006309773,-0.00005011998,-0.00003981151,-0.00003162328,-0.00002511918,-0.00001995282,-0.00001584906,-0.00001258933,-0.00001000005,-0.000007943314,-0.000006309593,-0.000005011885,-0.00000398108,-0.000003162283,-0.00000251189,-0.000001995264,-0.000001584894,-0.000001258926,-0.000001000001,-0.0000007943286,-0.0000006309575,-0.0000005011874,-0.0000003981072,-0.0000003162278,-0.0000002511887,-0.0000001995263,-0.0000001584893,-0.0000001258925,-0.0000001,-0.00000007943283,-0.00000006309574,-0.00000005011872,-0.00000003981072,-0.00000003162278,-0.00000002511886,-0.00000001995262,-0.00000001584893,-0.00000001258925,-0.00000001,-0.000000007943282,-0.000000006309573,-0.000000005011872,-0.000000003981072,-0.000000003162278,-0.000000002511886,-0.000000001995262,-0.000000001584893,-0.000000001258925,-0.000000001,-0.0000000007943283,-0.0000000006309574,-0.0000000005011872,-0.0000000003981072,-0.0000000003162277,-0.0000000002511886,-0.0000000001995263,-0.0000000001584893,-0.0000000001258925,-0.0000000001,-0.00000000007943279,-0.00000000006309575,-0.00000000005011869,-0.00000000003981071,-0.00000000003162282,-0.00000000002511891,-0.0000000000199526,-0.00000000001584888,-0.00000000001258926,-0.00000000001,-0.000000000007943313,-0.000000000006309619,-0.00000000000501188,-0.000000000003981038,-0.000000000003162248,-0.00000000000251188,-0.000000000001995293,-0.000000000001584843,-0.000000000001258882,-0.0000000000009999779,-0.0000000000007943646,-0.0000000000006309397,-0.0000000000005011547,-0.000000000000398126,-0.0000000000003161915,-0.0000000000002512435,-0.0000000000001995071,-0.0000000000001585398,-0.0000000000001258993,-0.0000000000001000311,-0.00000000000007938095,-0.00000000000006306067,-0.00000000000005007106,-0.00000000000003985701,-0.00000000000003164136,-0.00000000000002509104,-0.00000000000001998401,-0.00000000000001587619,-0.00000000000001254552,-0.000000000000009992007,-0.000000000000007993606,-0.000000000000006328271,-0.000000000000004996004,-0.000000000000003996803,-0.000000000000003108624,-0.000000000000002553513,-0.000000000000001998401,-0.000000000000001554312,-0.000000000000001221245,-0.0000000000000009992007,-0.0000000000000007771561,-0.0000000000000006661338,-0.0000000000000005551115,-0.0000000000000004440892,-0.0000000000000003330669,-0.0000000000000002220446,-0.0000000000000002220446,-0.0000000000000001110223,-0.0000000000000001110223,-0.0000000000000001110223,-0.0000000000000001110223,-0.0000000000000001110223,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {-1.791759,-1.447217,-1.238975,-1.0998,-1.001583,-0.9299061,-0.8764201,-0.8358837,-0.8048159,-0.7808079,-0.7621401,-0.7475561,-0.7361213,-0.7271306,-0.7200462,-0.7144544,-0.7100349,-0.7065382,-0.7037694,-0.7015754,-0.6998362,-0.6984568,-0.6973624,-0.696494,-0.6958048,-0.6952576,-0.6948232,-0.6944782,-0.6942043,-0.6939868,-0.6938141,-0.6936769,-0.6935679,-0.6934814,-0.6934126,-0.693358,-0.6933147,-0.6932802,-0.6932528,-0.6932311,-0.6932138,-0.6932001,-0.6931892,-0.6931806,-0.6931737,-0.6931683,-0.6931639,-0.6931605,-0.6931577,-0.6931556,-0.6931538,-0.6931525,-0.6931514,-0.6931505,-0.6931498,-0.6931493,-0.6931489,-0.6931485,-0.6931482,-0.693148,-0.6931478,-0.6931477,-0.6931476,-0.6931475,-0.6931474,-0.6931474,-0.6931473,-0.6931473,-0.6931473,-0.6931473,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472,-0.6931472},
  {-1.098612,-1.328871,-1.559129,-1.789388,-2.019646,-2.249905,-2.480163,-2.710422,-2.94068,-3.170939,-3.401197,-3.631456,-3.861714,-4.091973,-4.322231,-4.55249,-4.782748,-5.013007,-5.243265,-5.473524,-5.703782,-5.934041,-6.164299,-6.394558,-6.624817,-6.855075,-7.085334,-7.315592,-7.545851,-7.776109,-8.006368,-8.236626,-8.466885,-8.697143,-8.927402,-9.15766,-9.387919,-9.618177,-9.848436,-10.07869,-10.30895,-10.53921,-10.76947,-10.99973,-11.22999,-11.46025,-11.6905,-11.92076,-12.15102,-12.38128,-12.61154,-12.8418,-13.07205,-13.30231,-13.53257,-13.76283,-13.99309,-14.22335,-14.45361,-14.68386,-14.91412,-15.14438,-15.37464,-15.6049,-15.83516,-16.06542,-16.29567,-16.52593,-16.75619,-16.98645,-17.21671,-17.44697,-17.67722,-17.90748,-18.13774,-18.368,-18.59826,-18.82852,-19.05878,-19.28903,-19.51929,-19.74955,-19.97981,-20.21007,-20.44033,-20.67059,-20.90084,-21.1311,-21.36136,-21.59162,-21.82188,-22.05214,-22.2824,-22.51265,-22.74291,-22.97317,-23.20343,-23.43369,-23.66395,-23.8942,-24.12446,-24.35472,-24.58498,-24.81524,-25.0455,-25.27575,-25.50601,-25.73627,-25.96653,-26.19679,-26.42705,-26.6573,-26.88756,-27.11782,-27.34809,-27.57835,-27.8086,-28.03884,-28.26915,-28.49941,-28.72966,-28.95985,-29.19018,-29.42047,-29.65062,-29.88104,-30.11097,-30.34154,-30.57138,-30.80191,-31.03191,-31.26313,-31.49329,-31.72395,-31.95209,-32.18292,-32.41488,-32.64246,-32.87257,-33.10803,-33.3356,-33.55875,-33.79236,-34.02875,-34.25189,-34.50321,-34.69992,-34.94504,-35.19636,-35.43752,-35.63819,-35.8895,-36.04365,-36.22597,-36.44912,-36.7368,-37.14227,-37.14227,-37.83541,-37.83541,-37.83541,-37.83541,-37.83541,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF,NEG_INF}
};


const double qScore_to_log10_gl[3][257] = {
  {NEG_INF,-0.6868253,-0.4329234,-0.3020624,-0.2204808,-0.1650885,-0.1256276,-0.0966529,-0.07494037,-0.05843517,-0.04575749,-0.03594451,-0.02830478,-0.02233067,-0.01764315,-0.01395543,-0.01104833,-0.008752929,-0.006938232,-0.005502151,-0.004364805,-0.003463498,-0.002748894,-0.002182101,-0.001732408,-0.001375536,-0.001092271,-0.000867397,-0.0006888564,-0.0005470888,-0.0004345118,-0.0003451095,-0.0002741078,-0.0002177174,-0.0001729302,-0.0001373577,-0.0001091035,-0.00008666179,-0.00006883649,-0.00005467788,-0.00004343162,-0.00003449861,-0.00002740299,-0.00002176683,-0.00001728992,-0.00001373381,-0.00001090912,-0.000008665401,-0.000006883158,-0.000005467478,-0.000004342967,-0.000003449737,-0.000002740222,-0.000002176634,-0.000001728961,-0.000001373362,-0.0000010909,-0.0000008665323,-0.0000006883109,-0.0000005467447,-0.0000004342947,-0.0000003449725,-0.0000002740214,-0.0000002176629,-0.0000001728958,-0.000000137336,-0.0000001090899,-0.00000008665315,-0.00000006883104,-0.00000005467444,-0.00000004342945,-0.00000003449724,-0.00000002740213,-0.00000002176629,-0.00000001728958,-0.0000000137336,-0.00000001090898,-0.000000008665314,-0.000000006883104,-0.000000005467444,-0.000000004342945,-0.000000003449724,-0.000000002740213,-0.000000002176629,-0.000000001728957,-0.00000000137336,-0.000000001090898,-0.0000000008665314,-0.0000000006883104,-0.0000000005467444,-0.0000000004342945,-0.0000000003449724,-0.0000000002740213,-0.0000000002176628,-0.0000000001728958,-0.0000000001373359,-0.0000000001090898,-0.00000000008665316,-0.00000000006883104,-0.00000000005467443,-0.00000000004342945,-0.00000000003449722,-0.00000000002740214,-0.00000000002176627,-0.00000000001728957,-0.00000000001373361,-0.000000000010909,-0.000000000008665302,-0.00000000000688308,-0.000000000005467447,-0.000000000004342945,-0.000000000003449737,-0.000000000002740233,-0.000000000002176632,-0.000000000001728943,-0.000000000001373347,-0.000000000001090895,-0.0000000000008665447,-0.0000000000006882887,-0.0000000000005467255,-0.0000000000004342849,-0.0000000000003449882,-0.0000000000002740136,-0.0000000000002176487,-0.0000000000001729039,-0.0000000000001373202,-0.0000000000001091137,-0.00000000000008664482,-0.00000000000006885298,-0.00000000000005467737,-0.00000000000004344295,-0.00000000000003447471,-0.0000000000000273869,-0.00000000000002174558,-0.00000000000001730968,-0.00000000000001374167,-0.0000000000000108969,-0.000000000000008678947,-0.000000000000006894941,-0.00000000000000544845,-0.000000000000004339474,-0.000000000000003471579,-0.000000000000002748333,-0.000000000000002169737,-0.000000000000001735789,-0.000000000000001350058,-0.000000000000001108977,-0.0000000000000008678947,-0.0000000000000006750292,-0.0000000000000005303801,-0.0000000000000004339474,-0.0000000000000003375146,-0.0000000000000002892982,-0.0000000000000002410819,-0.0000000000000001928655,-0.0000000000000001446491,-0.00000000000000009643275,-0.00000000000000009643275,-0.00000000000000004821637,-0.00000000000000004821637,-0.00000000000000004821637,-0.00000000000000004821637,-0.00000000000000004821637,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {-0.7781513,-0.6285185,-0.5380802,-0.4776372,-0.4349819,-0.4038531,-0.3806244,-0.3630197,-0.3495271,-0.3391006,-0.3309932,-0.3246595,-0.3196934,-0.3157888,-0.3127121,-0.3102836,-0.3083642,-0.3068456,-0.3056431,-0.3046903,-0.303935,-0.3033359,-0.3028607,-0.3024835,-0.3021842,-0.3019465,-0.3017579,-0.3016081,-0.3014891,-0.3013946,-0.3013196,-0.30126,-0.3012127,-0.3011751,-0.3011453,-0.3011216,-0.3011027,-0.3010878,-0.3010759,-0.3010664,-0.3010589,-0.301053,-0.3010483,-0.3010445,-0.3010415,-0.3010392,-0.3010373,-0.3010358,-0.3010346,-0.3010336,-0.3010329,-0.3010323,-0.3010318,-0.3010314,-0.3010311,-0.3010309,-0.3010307,-0.3010306,-0.3010305,-0.3010304,-0.3010303,-0.3010302,-0.3010302,-0.3010301,-0.3010301,-0.3010301,-0.3010301,-0.3010301,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103,-0.30103},
  {-0.4771213,-0.5771213,-0.6771213,-0.7771213,-0.8771213,-0.9771213,-1.077121,-1.177121,-1.277121,-1.377121,-1.477121,-1.577121,-1.677121,-1.777121,-1.877121,-1.977121,-2.077121,-2.177121,-2.277121,-2.377121,-2.477121,-2.577121,-2.677121,-2.777121,-2.877121,-2.977121,-3.077121,-3.177121,-3.277121,-3.377121,-3.477121,-3.577121,-3.677121,-3.777121,-3.877121,-3.977121,-4.077121,-4.177121,-4.277121,-4.377121,-4.477121,-4.577121,-4.677121,-4.777121,-4.877121,-4.977121,-5.077121,-5.177121,-5.277121,-5.377121,-5.477121,-5.577121,-5.677121,-5.777121,-5.877121,-5.977121,-6.077121,-6.177121,-6.277121,-6.377121,-6.477121,-6.577121,-6.677121,-6.777121,-6.877121,-6.977121,-7.077121,-7.177121,-7.277121,-7.377121,-7.477121,-7.577121,-7.677121,-7.777121,-7.877121,-7.977121,-8.077121,-8.177121,-8.277121,-8.377121,-8.477121,-8.577121,-8.677121,-8.777121,-8.877121,-8.977121,-9.077121,-9.177121,-9.277121,-9.377121,-9.477121,-9.577121,-9.677121,-9.777121,-9.877121,-9.977121,-10.07712,-10.17712,-10.27712,-10.37712,-10.47712,-10.57712,-10.67712,-10.77712,-10.87712,-10.97712,-11.07712,-11.17712,-11.27712,-11.37712,-11.47712,-11.57712,-11.67712,-11.77712,-11.87712,-11.97712,-12.07712,-12.17712,-12.27712,-12.37712,-12.47712,-12.57712,-12.67712,-12.77712,-12.87712,-12.97712,-13.07712,-13.17712,-13.27712,-13.37712,-13.47712,-13.57712,-13.67712,-13.77712,-13.87712,-13.97712,-14.07712,-14.17712,-14.27712,-14.37712,-14.47712,-14.57712,-14.67712,-14.77712,-14.87712,-14.97712,-15.07712,-15.17712,-15.27712,-15.37712,-15.47712,-15.57712,-15.67712,-15.77712,-15.87712,-15.97712,-16.07712,-16.17712,-16.27712,-16.37712,-16.47712,-16.57712,-16.67712,-16.77712,-16.87712,-16.97712,-17.07712,-17.17712,-17.27712,-17.37712,-17.47712,-17.57712,-17.67712,-17.77712,-17.87712,-17.97712,-18.07712,-18.17712,-18.27712,-18.37712,-18.47712,-18.57712,-18.67712,-18.77712,-18.87712,-18.97712,-19.07712,-19.17712,-19.27712,-19.37712,-19.47712,-19.57712,-19.67712,-19.77712,-19.87712,-19.97712,-20.07712,-20.17712,-20.27712,-20.37712,-20.47712,-20.57712,-20.67712,-20.77712,-20.87712,-20.97712,-21.07712,-21.17712,-21.27712,-21.37712,-21.47712,-21.57712,-21.67712,-21.77712,-21.87712,-21.97712,-22.07712,-22.17712,-22.27712,-22.37712,-22.47712,-22.57712,-22.67712,-22.77712,-22.87712,-22.97712,-23.07712,-23.17712,-23.27712,-23.37712,-23.47712,-23.57712,-23.67712,-23.77712,-23.87712,-23.97712,-24.07712,-24.17712,-24.27712,-24.37712,-24.47712,-24.57712,-24.67712,-24.77712,-24.87712,-24.97712,-25.07712,-25.17712,-25.27712,-25.37712,-25.47712,-25.57712,-25.67712,-25.77712,-25.87712,-25.97712,-26.07712}
};


