#ifndef ALARMSAMPLE_H
#define ALARMSAMPLE_H

#include "esp_types.h"
// Sample data imported from Matlab
double OriAlrm[] = {0.01007, -0.01343, -0.03470, -0.05750, -0.07355, -0.07938, -0.08267, -0.08279, -0.07336, -0.05826, -0.03894, -0.01105, 0.01559, 0.03934, 0.06192, 0.07828, 0.08777, 0.08923, 0.08267, 0.07010, 0.04999, 0.02515, 0.00189, -0.01950, -0.04102, -0.06128, -0.07242, -0.07834, -0.08267, -0.08023, -0.06741, -0.05045, -0.02676, 0.00089, 0.02618, 0.05054, 0.07227, 0.08630, 0.09103, 0.08868, 0.07935, 0.06393, 0.04077, 0.01416, -0.01083, -0.03302, -0.05612, -0.07297, -0.07837, -0.08194, -0.08148, -0.07224, -0.05746, -0.03702, -0.01010, 0.01675, 0.03992, 0.06076, 0.07797, 0.08740, 0.08902, 0.08374, 0.07178, 0.05280, 0.02811, 0.00339, -0.01810, -0.04031, -0.06131, -0.07346, -0.07840, -0.08328, -0.08112, -0.06921, -0.05301, -0.02960, -0.00317, 0.02228, 0.04651, 0.06821, 0.08261, 0.08865, 0.08740, 0.07755, 0.06113, 0.03864, 0.01279, -0.01028, -0.03278, -0.05582, -0.07336, -0.08002, -0.08401, -0.08606, -0.07849, -0.06357, -0.04349, -0.01624, 0.01041, 0.03357, 0.05521, 0.07364, 0.08414, 0.08627, 0.08087, 0.06897, 0.05048, 0.02585, 0.00082, -0.02051, -0.04187, -0.06311, -0.07501, -0.07990, -0.08398, -0.08212, -0.07062, -0.05411, -0.03201, -0.00443, 0.02026, 0.04462, 0.06631, 0.08124, 0.08804, 0.08746, 0.07864, 0.06277, 0.04108, 0.01590, -0.00763, -0.02948, -0.05307, -0.07153, -0.07941, -0.08292, -0.08511, -0.07813, -0.06375, -0.04480, -0.01752, 0.01068, 0.03409, 0.05627, 0.07495, 0.08551, 0.08798, 0.08267, 0.07074, 0.05298, 0.02899, 0.00366, -0.01779, -0.03888, -0.06036, -0.07281, -0.07806, -0.08170, -0.08090, -0.07031, -0.05521, -0.03299, -0.00610, 0.01965, 0.04398, 0.06644, 0.08200, 0.08972, 0.09003, 0.08087, 0.06552, 0.04477, 0.01834, -0.00464, -0.02667, -0.05002, -0.06921, -0.07733, -0.08069, -0.08264, -0.07538, -0.06088, -0.04269, -0.01675, 0.01044, 0.03409, 0.05606, 0.07532, 0.08688, 0.08975, 0.08527, 0.07428, 0.05649, 0.03165, 0.00574, -0.01474, -0.03619, -0.05756, -0.07153, -0.07718, -0.08109, -0.08136, -0.07028, -0.05432, -0.03241, -0.00497, 0.02069, 0.04419, 0.06732, 0.08368, 0.09229, 0.09277, 0.08475, 0.06937, 0.04819, 0.02197, -0.00275, -0.02484, -0.04865, -0.06815, -0.07681, -0.08041, -0.08273, -0.07648, -0.06326, -0.04526, -0.01910, 0.00888, 0.03217, 0.05472, 0.07468, 0.08643, 0.09064, 0.08698, 0.07645, 0.05936, 0.03510, 0.00888, -0.01355, -0.03430, -0.05615, -0.07214, -0.07751, -0.08139, -0.08179, -0.07184, -0.05536, -0.03458, -0.00793, 0.01807, 0.04227, 0.06537, 0.08267, 0.09189, 0.09338, 0.08551, 0.07144, 0.04987, 0.02396, -0.00085, -0.02322, -0.04636, -0.06686, -0.07544, -0.07870, -0.08176, -0.07675, -0.06360, -0.04578, -0.02115, 0.00687, 0.03073, 0.05322, 0.07358, 0.08661, 0.09122, 0.08774, 0.07813, 0.06161, 0.03854, 0.01263, -0.01041, -0.03146, -0.05310, -0.06879, -0.07556, -0.07999, -0.08179, -0.07330, -0.05807, -0.03793, -0.01065, 0.01605, 0.04062, 0.06372, 0.08130, 0.09061, 0.09265, 0.08554, 0.07074, 0.05008, 0.02438, -0.00073, -0.02301, -0.04657, -0.06717, -0.07758, -0.08173, -0.08450, -0.08005, -0.06787, -0.05075, -0.02634, 0.00137, 0.02667, 0.04950, 0.07031, 0.08356, 0.08768, 0.08496, 0.07547, 0.05893, 0.03552, 0.00864, -0.01471, -0.03479, -0.05676, -0.07309, -0.07944, -0.08359, -0.08551, -0.07715, -0.06259, -0.04181, -0.01538, 0.01019, 0.03519, 0.05869, 0.07748, 0.08798, 0.09103, 0.08456, 0.07187, 0.05215, 0.02701, 0.00195, -0.02097, -0.04416, -0.06543, -0.07724, -0.08191, -0.08432, -0.08038, -0.06790, -0.05063, -0.02750, 0.00098, 0.02551, 0.04852, 0.06949, 0.08301, 0.08859, 0.08636, 0.07690, 0.06168, 0.03970, 0.01376, -0.00897, -0.03040, -0.05231, -0.06931, -0.07684, -0.08109, -0.08423, -0.07730, -0.06271, -0.04300, -0.01685, 0.01028, 0.03516, 0.05856, 0.07745, 0.08856, 0.09149, 0.08646, 0.07336, 0.05426, 0.02997, 0.00583, -0.01688, -0.04114, -0.06375, -0.07458, -0.07883, -0.08212, -0.07938, -0.06760, -0.05081, -0.02753, -0.00015, 0.02435, 0.04663, 0.06723, 0.08176, 0.08792, 0.08612, 0.07712, 0.06329, 0.04126, 0.01544, -0.00836, -0.02878, -0.05081, -0.06830, -0.07562, -0.07977, -0.08209, -0.07587, -0.06284, -0.04645, -0.02075, 0.00711, 0.03131, 0.05319, 0.07220, 0.08456, 0.08890, 0.08472, 0.07306, 0.05789, 0.03641, 0.00916, -0.01389, -0.03244, -0.04990, -0.06149, -0.06866, -0.07263, -0.07031, -0.06186, -0.05115, -0.03693, -0.02014, -0.00397, 0.01315, 0.02753, 0.04034, 0.05258, 0.06137, 0.06396, 0.06113, 0.05182, 0.04062, 0.02817, 0.01254, -0.00601, -0.02548, -0.04187, -0.05673, -0.06561, -0.06781, -0.06384, -0.05405, -0.03918, -0.02441, -0.00870, 0.00812, 0.02405, 0.03687, 0.04440, 0.04987, 0.05273, 0.05096, 0.04459, 0.03647, 0.02847, 0.01740, 0.00418, -0.00912, -0.02130, -0.03348, -0.04172, -0.04807, -0.05090, -0.04935, -0.04251, -0.03140, -0.01965, -0.00629, 0.00885, 0.02219, 0.03363, 0.04196, 0.04776, 0.05063, 0.04901, 0.04349, 0.03430, 0.02206, 0.00797, -0.00616, -0.01947, -0.03015, -0.03708, -0.04147, -0.04294, -0.04144, -0.03696, -0.02905, -0.01868, -0.00842, 0.00278, 0.01306, 0.02151, 0.02966, 0.03497, 0.03864, 0.03940, 0.03586, 0.03049, 0.02142, 0.01117, 0.00024, -0.01007, -0.01926, -0.02679, -0.03183, -0.03427, -0.03336, -0.03094, -0.02628, -0.01831, -0.01022, -0.00168, 0.00681, 0.01437, 0.02069, 0.02573, 0.02914, 0.02966, 0.02710, 0.02182, 0.01517, 0.00766, -0.00098, -0.00867, -0.01599, -0.02155, -0.02475, -0.02686, -0.02664, -0.02344, -0.01974, -0.01456, -0.00940, -0.00345, 0.00217, 0.00882, 0.01349, 0.01773, 0.02090, 0.02130, 0.02036, 0.01703, 0.01175, 0.00571, -0.00085, -0.00821, -0.01379, -0.01855, -0.02124, -0.02191, -0.02057, -0.01825, -0.01505, -0.01117, -0.00687, -0.00229, 0.00284, 0.00732, 0.01093, 0.01459, 0.01685, 0.01770, 0.01529, 0.01221, 0.00699, 0.00217, -0.00244, -0.00720, -0.01132, -0.01358, -0.01468, -0.01483, -0.01389, -0.01202, -0.00961, -0.00684, -0.00314, 0.00073, 0.00562, 0.00873, 0.01181, 0.01382, 0.01465, 0.01425, 0.01190, 0.00766, 0.00397, -0.00070, -0.00348, -0.00696, -0.00955, -0.01089, -0.01190, -0.01212, -0.01123, -0.00894, -0.00723, -0.00476, -0.00174, 0.00125, 0.00360, 0.00607, 0.00781, 0.01001, 0.00958, 0.00818, 0.00699, 0.00449, 0.00128, -0.00150, -0.00418, -0.00638, -0.00723, -0.00815, -0.00885, -0.00867, -0.00790, -0.00702, -0.00592, -0.00336, -0.00089, 0.00241, 0.00488, 0.00705, 0.00815, 0.00797, 0.00803, 0.00699, 0.00504, 0.00311, 0.00067, -0.00125, -0.00302, -0.00470, -0.00467, -0.00513, -0.00513, -0.00485, -0.00418, -0.00302, -0.00266, -0.00003, 0.00159, 0.00302, 0.00510, 0.00620, 0.00815, 0.00873, 0.00751, 0.00638, 0.00406, 0.00217, 0.00000, -0.00192, -0.00330, -0.00317, -0.00317, -0.00238, -0.00192, -0.00189, -0.00116, -0.00034, 0.00037, 0.00156, 0.00256, 0.00403, 0.00549, 0.00659, 0.00739, 0.00757, 0.00592, 0.00497, 0.00281, 0.00134, -0.00095, -0.00201, -0.00204, -0.00229, -0.00180, -0.00146, -0.00049, -0.00082, -0.00085, -0.00027, 0.00012, 0.00089, 0.00262, 0.00388, 0.00443, 0.00598, 0.00671, 0.00626, 0.00424, 0.00204, 0.00070, -0.00027, -0.00162, -0.00220, -0.00311, -0.00327, -0.00314, -0.00223, -0.00192, -0.00269, -0.00253, -0.00208, -0.00021, 0.00043, 0.00269, 0.00400, 0.00491, 0.00580, 0.00461, 0.00421, 0.00287, 0.00107, -0.00046, -0.00198, -0.00317, -0.00330, -0.00336, -0.00314, -0.00327, -0.00259, -0.00235, -0.00186, -0.00171, -0.00012, 0.00049, 0.00052, 0.00143, 0.00259, 0.00345, 0.00323, 0.00372, 0.00314, 0.00177, 0.00027, -0.00131, -0.00232, -0.00339, -0.00363, -0.00388, -0.00415, -0.00394, -0.00272, -0.00269, -0.00189, -0.00110, -0.00031, 0.00079, 0.00177, 0.00311, 0.00412, 0.00473, 0.00488, 0.00439, 0.00348, 0.00183, -0.00009, -0.00143, -0.00229, -0.00330, -0.00284, -0.00204, -0.00067, -0.00049, -0.00040, -0.00034, -0.00043, -0.00009, 0.00101, 0.00156, 0.00327, 0.00439, 0.00494, 0.00467, 0.00427, 0.00397, 0.00311, 0.00140, 0.00027, -0.00107, -0.00217, -0.00302, -0.00293, -0.00259, -0.00214, -0.00208, -0.00217, -0.00146, -0.00104, -0.00046, 0.00116, 0.00220, 0.00317, 0.00339, 0.00497, 0.00439, 0.00345, 0.00278, 0.00134, -0.00006, -0.00180, -0.00290, -0.00323, -0.00391, -0.00388, -0.00269, -0.00314, -0.00220, -0.00229, -0.00229, -0.00070, -0.00009, 0.00134, 0.00131, 0.00177, 0.00275, 0.00299, 0.00259, 0.00195, 0.00146, 0.00015, -0.00168, -0.00302, -0.00388, -0.00446, -0.00436, -0.00354, -0.00284, -0.00275, -0.00272, -0.00256, -0.00244, -0.00174, -0.00085, -0.00064, -0.00052, 0.00003, 0.00092, 0.00043, 0.00058, -0.00027, -0.00079, -0.00189, -0.00259, -0.00339, -0.00385, -0.00397, -0.00430, -0.00327, -0.00345, -0.00381, -0.00333, -0.00299, -0.00262, -0.00211, -0.00153, -0.00052, 0.00021, 0.00119, 0.00201, 0.00177, 0.00165, 0.00027, -0.00058, -0.00229, -0.00311, -0.00351, -0.00446, -0.00391, -0.00296, -0.00317, -0.00287, -0.00262, -0.00253, -0.00223, -0.00134, -0.00049, -0.00015, 0.00000, 0.00067, 0.00146, 0.00211, 0.00183, 0.00137, 0.00140, 0.00110, -0.00006, -0.00101, -0.00104, -0.00253, -0.00241, -0.00290, -0.00266, -0.00211, -0.00214, -0.00101, -0.00098, 0.00012, 0.00040, 0.00189, 0.00293, 0.00375, 0.00394, 0.00378, 0.00369, 0.00327, 0.00299, 0.00146, 0.00085, 0.00052, 0.00064, 0.00006, -0.00073, 0.00012, 0.00027, 0.00000, -0.00101, -0.00052, -0.00031, -0.00079, -0.00015, 0.00137, 0.00217, 0.00348, 0.00284, 0.00314, 0.00317, 0.00253, 0.00153, 0.00043, 0.00049, 0.00037, -0.00003, 0.00009, 0.00085, 0.00037, 0.00024, -0.00064, -0.00064, -0.00043, -0.00006, 0.00052, 0.00140, 0.00223, 0.00256, 0.00308, 0.00293, 0.00241, 0.00211, 0.00165, 0.00067, -0.00006, -0.00052, -0.00015, -0.00055, -0.00034, 0.00009, 0.00024, 0.00092, 0.00064, 0.00015, -0.00015, 0.00021, 0.00107, 0.00195, 0.00162, 0.00189, 0.00201, 0.00244, 0.00293, 0.00229, 0.00195, 0.00079, 0.00009, -0.00003, -0.00034, -0.00119, -0.00116, -0.00122, -0.00104, -0.00098, -0.00055, -0.00046, 0.00000, 0.00040, 0.00055, 0.00153, 0.00214, 0.00208, 0.00226, 0.00165, 0.00107, 0.00137, 0.00085, -0.00015, -0.00037, -0.00034, -0.00040, -0.00031, -0.00113, -0.00095, -0.00095, -0.00089, -0.00134, -0.00110, -0.00009, -0.00046, 0.00049, 0.00140, 0.00165, 0.00186, 0.00211, 0.00192, 0.00177, 0.00070, 0.00006, -0.00055, -0.00082, -0.00104, -0.00153, -0.00137, -0.00125, -0.00098, -0.00116, -0.00204, -0.00223, -0.00214, -0.00204, -0.00150, -0.00085, 0.00037, 0.00098, 0.00131, 0.00122, 0.00061, 0.00052, -0.00067, -0.00146, -0.00168, -0.00208, -0.00171, -0.00140, -0.00101, -0.00146, -0.00171, -0.00192, -0.00262, -0.00168, -0.00122, -0.00122, -0.00024, -0.00018, -0.00003, 0.00092, 0.00122, 0.00076, 0.00067, -0.00009, -0.00061, -0.00107, -0.00101, -0.00058, -0.00082, -0.00125, -0.00140, -0.00201, -0.00201, -0.00229, -0.00204, -0.00235, -0.00177, -0.00073, -0.00015, 0.00034, 0.00110, 0.00192, 0.00201, 0.00195, 0.00137, 0.00024, 0.00018, -0.00037, -0.00153, -0.00208, -0.00275, -0.00262, -0.00269, -0.00256, -0.00266, -0.00262, -0.00198, -0.00171, -0.00128, -0.00098, 0.00040, 0.00055, 0.00006, 0.00012, 0.00009, 0.00018, 0.00049, -0.00015, -0.00027, -0.00049, -0.00122, -0.00162, -0.00159, -0.00189, -0.00159, -0.00131, -0.00104, -0.00137, -0.00098, -0.00052, -0.00003, 0.00104, 0.00134, 0.00162, 0.00262, 0.00168, 0.00229, 0.00101, 0.00070, 0.00006, -0.00027, -0.00073, -0.00043, -0.00043, -0.00079, -0.00006, -0.00046, -0.00021, -0.00061, -0.00012, -0.00076, 0.00003, 0.00012, 0.00049, 0.00131, 0.00156, 0.00140, 0.00107, 0.00122, 0.00089, 0.00067, -0.00009, -0.00049, -0.00128, -0.00119, -0.00128, -0.00150, -0.00195, -0.00211, -0.00125, -0.00140, -0.00128, -0.00110, -0.00119, -0.00082, -0.00052, 0.00040, 0.00037, 0.00046, 0.00082, 0.00040, 0.00024, -0.00040, -0.00174, -0.00165, -0.00168, -0.00131, -0.00113, -0.00064, -0.00095, 0.00021, -0.00006, 0.00031, -0.00040, 0.00043, 0.00043, 0.00079, 0.00122, 0.00198, 0.00162, 0.00128, 0.00098, 0.00095, 0.00058, 0.00064, 0.00122, 0.00089, -0.00009, 0.00037, -0.00040, -0.00037, 0.00049, 0.00012, 0.00092, 0.00165, 0.00198, 0.00235, 0.00232, 0.00278, 0.00302, 0.00235, 0.00290, 0.00290, 0.00208, 0.00180, 0.00122, 0.00058, 0.00070, 0.00085, 0.00009, -0.00064, -0.00082, -0.00067, -0.00076, -0.00101, -0.00098, -0.00003, 0.00052, 0.00137, 0.00122, 0.00165, 0.00272, 0.00217, 0.00140, 0.00171, 0.00104, 0.00003, -0.00095, -0.00150, -0.00146, -0.00073, -0.00027, -0.00049, -0.00027, -0.00018, -0.00055, -0.00043, 0.00018, -0.00082, 0.00000, 0.00027, 0.00043, 0.00110, 0.00165, 0.00177, 0.00150, 0.00113, 0.00073, 0.00107, 0.00046, 0.00040, 0.00027, 0.00012, 0.00027, 0.00006, -0.00003, 0.00027, 0.00027, 0.00031, 0.00064, 0.00049, 0.00107, 0.00232, 0.00284, 0.00308, 0.00269, 0.00296, 0.00281, 0.00232, 0.00128, 0.00076, 0.00043, 0.00015, 0.00024, 0.00018, 0.00006, 0.00000, 0.00052, 0.00037, 0.00064, -0.00006, 0.00043, 0.00058, 0.00131, 0.00143, 0.00159, 0.00217, 0.00156, 0.00125, 0.00101, 0.00070, -0.00018, -0.00058, -0.00128, -0.00113, -0.00150, -0.00195, -0.00204, -0.00226, -0.00269, -0.00241, -0.00354, -0.00375, -0.00381, -0.00320, -0.00256, -0.00217, -0.00192, -0.00122, -0.00037, -0.00049, -0.00024, -0.00076, -0.00220, -0.00198, -0.00214, -0.00406, -0.00385, -0.00436, -0.00449, -0.00391, -0.00400, -0.00452, -0.00436, -0.00342, -0.00308, -0.00259, -0.00266, -0.00238, -0.00180, -0.00253, -0.00168, -0.00250, -0.00314, -0.00330, -0.00385, -0.00339, -0.00433, -0.00424, -0.00409, -0.00409, -0.00446, -0.00488, -0.00525, -0.00516, -0.00494, -0.00522, -0.00479, -0.00372, -0.00320, -0.00305, -0.00311, -0.00269, -0.00375, -0.00330, -0.00342, -0.00363, -0.00287, -0.00348, -0.00351, -0.00357, -0.00409, -0.00427, -0.00470, -0.00500, -0.00467, -0.00458, -0.00378, -0.00378, -0.00323, -0.00241, -0.00314, -0.00223, -0.00204, -0.00250, -0.00284, -0.00244, -0.00302, -0.00351, -0.00333, -0.00360, -0.00333, -0.00375, -0.00354, -0.00360, -0.00348, -0.00339, -0.00311, -0.00351, -0.00317, -0.00241, -0.00232, -0.00156, -0.00140, -0.00134, -0.00159, -0.00198, -0.00201, -0.00156, -0.00266, -0.00302, -0.00320, -0.00366, -0.00369, -0.00333, -0.00275, -0.00317, -0.00281, -0.00266, -0.00208, -0.00186, -0.00165, -0.00180, -0.00137, -0.00055, -0.00015, 0.00024, -0.00015, -0.00003, -0.00027, -0.00076, -0.00046, -0.00055, -0.00076, -0.00128, -0.00146, -0.00089, -0.00092, -0.00067, -0.00052, -0.00101, -0.00168, -0.00067, -0.00116, -0.00034, -0.00040, 0.00082, 0.00171, 0.00113, 0.00201, 0.00247, 0.00153, 0.00110, 0.00034, -0.00012, 0.00000, -0.00012, -0.00046, -0.00015, -0.00046, -0.00061, -0.00122, -0.00122, -0.00101, -0.00073, -0.00125, -0.00043, -0.00046, 0.00027, 0.00052, -0.00037, -0.00009, 0.00052, 0.00006, -0.00073, -0.00092, -0.00058, -0.00125, -0.00146, -0.00125, -0.00070, -0.00064, -0.00122, -0.00168, -0.00259, -0.00214, -0.00217, -0.00180, -0.00165, -0.00223, -0.00220, -0.00150, -0.00186, -0.00110, -0.00079, -0.00156, -0.00171, -0.00168, -0.00223, -0.00186, -0.00143, -0.00110, -0.00150, -0.00211, -0.00214, -0.00198, -0.00241, -0.00281, -0.00192, -0.00165, -0.00162, -0.00153, -0.00089, 0.00000, -0.00046, -0.00067, 0.00037, -0.00006, 0.00024, -0.00021, -0.00024, -0.00027, -0.00003, -0.00052, -0.00140, -0.00104, -0.00195, -0.00214, -0.00266, -0.00198, -0.00110, -0.00064, -0.00064, 0.00009, -0.00031, -0.00076, -0.00015, 0.00015, 0.00052, 0.00012, 0.00073, 0.00003, -0.00046, 0.00006, 0.00037, 0.00024, 0.00003, 0.00003, -0.00110, -0.00076, -0.00067, -0.00095, -0.00082, -0.00134, -0.00156, -0.00064, -0.00098, -0.00024, 0.00070, 0.00079, 0.00116, 0.00110, 0.00110, 0.00113, 0.00006, 0.00015, -0.00052, -0.00052, -0.00073, -0.00153, -0.00137, -0.00220, -0.00247, -0.00211, -0.00156, -0.00125, -0.00055, -0.00006, -0.00098, -0.00131, -0.00110, -0.00131, -0.00098, -0.00095, -0.00043, -0.00058, -0.00015, -0.00009, -0.00095, -0.00089, -0.00070, -0.00143, -0.00131, -0.00168, -0.00171, -0.00183, -0.00183, -0.00192, -0.00208, -0.00195, -0.00107, -0.00146, -0.00116, -0.00104, -0.00104, -0.00156, -0.00211, -0.00131, -0.00177, -0.00214, -0.00229, -0.00269, -0.00336, -0.00375, -0.00412, -0.00372, -0.00333, -0.00385, -0.00311, -0.00253, -0.00195, -0.00198, -0.00116, -0.00052, -0.00031, 0.00009, -0.00073, -0.00012, -0.00043, -0.00040, 0.00052, -0.00055, -0.00110, -0.00146, -0.00165, -0.00189, -0.00146, -0.00079, -0.00128, -0.00049, -0.00116, -0.00037, 0.00000, 0.00000, -0.00006, -0.00003, 0.00070, 0.00070, 0.00165, 0.00208, 0.00143, 0.00092, 0.00156, 0.00113, 0.00089, 0.00021, 0.00012, -0.00073, -0.00052, -0.00003, -0.00003, 0.00061, 0.00055, 0.00082, 0.00098, 0.00119, 0.00128, 0.00061, 0.00073, 0.00085, 0.00110, 0.00143, 0.00143, 0.00174, 0.00171, 0.00125, 0.00037, -0.00031, -0.00076, -0.00040, -0.00067, 0.00037, 0.00006, 0.00043, 0.00104, 0.00146, 0.00125, 0.00146, 0.00180, 0.00195, 0.00275, 0.00238, 0.00262, 0.00198, 0.00159, 0.00232, 0.00208, 0.00162, 0.00156, 0.00046, 0.00070, 0.00058, -0.00031, -0.00012, -0.00021, 0.00003, -0.00049, -0.00012, 0.00067, 0.00085, 0.00098, 0.00085, 0.00122, 0.00134, 0.00079, 0.00162, 0.00235, 0.00198, 0.00180, 0.00162, 0.00153, 0.00101, 0.00049, 0.00058, 0.00101, 0.00140, 0.00137, 0.00208, 0.00153, 0.00241, 0.00211, 0.00143, 0.00162, 0.00177, 0.00134, 0.00110, 0.00070, 0.00156, 0.00128, 0.00162, 0.00250, 0.00244, 0.00247, 0.00189, 0.00171, 0.00226, 0.00262, 0.00272, 0.00208, 0.00116, 0.00076, 0.00070, 0.00015, -0.00027, 0.00107, 0.00125, 0.00125, 0.00165, 0.00284, 0.00293, 0.00357, 0.00336, 0.00238, 0.00220, 0.00134, -0.00037, -0.00027, 0.00037, 0.00006, 0.00089, 0.00156, 0.00168, 0.00189, 0.00217, 0.00134, 0.00107, 0.00146, 0.00146, 0.00131, 0.00052, 0.00067, 0.00095, 0.00034, 0.00024, 0.00009, -0.00003, 0.00070, 0.00037, 0.00085, 0.00116, 0.00037, 0.00079, 0.00024, -0.00015, -0.00095, -0.00168, -0.00128, -0.00128, -0.00143, -0.00046, -0.00043, -0.00018, -0.00018, 0.00031, 0.00055, -0.00049, -0.00058, -0.00064, -0.00031, -0.00024, -0.00006, 0.00031, 0.00058, 0.00098, 0.00113, 0.00101, 0.00076, 0.00058, 0.00140, 0.00089, 0.00052, 0.00052, 0.00052, 0.00073, 0.00107, 0.00180, 0.00156, 0.00131, 0.00156, 0.00186, 0.00143, 0.00095, 0.00040, 0.00015, -0.00015, 0.00006, 0.00009, 0.00055, 0.00113, 0.00131, 0.00125, 0.00153, 0.00189, 0.00192, 0.00235, 0.00198, 0.00171, 0.00146, 0.00125, 0.00082, 0.00024, 0.00018, 0.00006, 0.00043, 0.00073, 0.00058, 0.00131, 0.00186, 0.00287, 0.00259, 0.00217, 0.00302, 0.00262, 0.00226, 0.00201, 0.00180, 0.00192, 0.00186, 0.00226, 0.00281, 0.00244, 0.00168, 0.00177, 0.00183, 0.00226, 0.00153, 0.00146, 0.00098, 0.00049, 0.00049, 0.00018, -0.00061, -0.00092, -0.00009, 0.00021, 0.00073, 0.00134, 0.00180, 0.00290, 0.00250, 0.00183, 0.00183, 0.00150, 0.00067, 0.00089, 0.00034, 0.00006, 0.00107, 0.00046, 0.00089, 0.00061, 0.00146, 0.00089, 0.00131, 0.00110, 0.00186, 0.00180, 0.00208, 0.00174, 0.00314, 0.00342, 0.00317, 0.00360, 0.00305, 0.00278, 0.00238, 0.00226, 0.00195, 0.00220, 0.00214, 0.00259, 0.00220, 0.00214, 0.00226, 0.00223, 0.00247, 0.00275, 0.00287, 0.00247, 0.00269, 0.00275, 0.00311, 0.00269, 0.00272, 0.00320, 0.00366, 0.00342, 0.00299, 0.00290, 0.00262, 0.00272, 0.00229, 0.00296, 0.00140, 0.00153, 0.00165, 0.00204, 0.00269, 0.00266, 0.00226, 0.00232, 0.00275, 0.00293, 0.00354, 0.00394, 0.00323, 0.00305, 0.00253, 0.00281, 0.00256, 0.00174, 0.00217, 0.00217, 0.00208, 0.00186, 0.00229, 0.00116, 0.00137, 0.00150, 0.00140, 0.00217, 0.00201, 0.00183, 0.00214, 0.00293, 0.00278, 0.00308, 0.00293, 0.00253, 0.00299, 0.00366, 0.00269, 0.00226, 0.00259, 0.00214, 0.00208, 0.00165, 0.00137, 0.00098, 0.00116, 0.00143, 0.00143, 0.00153, 0.00235, 0.00250, 0.00320, 0.00311, 0.00314, 0.00317, 0.00308, 0.00333, 0.00247, 0.00177, 0.00162, 0.00174, 0.00113, 0.00128, 0.00137, 0.00168, 0.00174, 0.00110, 0.00113, 0.00104, 0.00101, 0.00159, 0.00137, 0.00131, 0.00223, 0.00226, 0.00308, 0.00327, 0.00290, 0.00296, 0.00186, 0.00159, 0.00089, 0.00116, 0.00104, 0.00140};

#endif