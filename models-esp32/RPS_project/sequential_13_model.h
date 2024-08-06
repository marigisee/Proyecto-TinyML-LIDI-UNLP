/* EmbedIA model definition file*/
#ifndef SEQUENTIAL_13_MODEL_H
#define SEQUENTIAL_13_MODEL_H

/*

+---------------+----------------------+------------+--------------+--------+------------+
| EmbedIA Layer | Name                 | #Param(NT) |    Shape     |   MACs | Size (KiB) |
+---------------+----------------------+------------+--------------+--------+------------+
| Conv2D        | conv2d_33            |          0 | (48, 48, 8)  | 165888 |     0.352  |
| Activation    | conv2d_331           |          0 | (48, 48, 8)  |      0 |     0.000  |
| Pooling       | average_pooling2d_21 |          0 | (24, 24, 8)  |      0 |     0.000  |
| Conv2D        | conv2d_34            |          0 | (24, 24, 13) | 539136 |     3.992  |
| Activation    | conv2d_341           |          0 | (24, 24, 13) |      0 |     0.000  |
| Pooling       | max_pooling2d_1      |          0 | (12, 12, 13) |      0 |     0.000  |
| Conv2D        | conv2d_35            |          0 | (12, 12, 18) | 303264 |     8.758  |
| Activation    | conv2d_351           |          0 | (12, 12, 18) |      0 |     0.000  |
| Flatten       | flatten_11           |          0 |   (2592,)    |      0 |     0.000  |
| Dense         | dense_44             |          0 |    (12,)     |  31104 |   121.547  |
| Activation    | dense_441            |          0 |    (12,)     |      0 |     0.000  |
| Dense         | dense_45             |          0 |    (10,)     |    120 |     0.508  |
| Activation    | dense_451            |          0 |    (10,)     |      0 |     0.000  |
| Dense         | dense_46             |          0 |     (8,)     |     80 |     0.344  |
| Activation    | dense_461            |          0 |     (8,)     |      0 |     0.000  |
| Dense         | dense_47             |          0 |     (4,)     |     32 |     0.141  |
| Activation    | dense_471            |          0 |     (4,)     |      0 |     0.000  |
+---------------+----------------------+------------+--------------+--------+------------+
Total params (NT)....: 0
Total size in KiB....: 135.641
Total MACs operations: 1039624

*/

#include "embedia.h"

#define INPUT_CHANNELS 1
#define INPUT_WIDTH 48
#define INPUT_HEIGHT 48

#define INPUT_SIZE 2304


void model_init();

void model_predict(data3d_t input, data1d_t * output);

int model_predict_class(data3d_t input, data1d_t * results);

#endif
