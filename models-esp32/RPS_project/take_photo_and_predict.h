#define TAKE_PHOTO_AND_PREDICT_H

#include <stdint.h> 

void initial_setup();

uint16_t take_photo_and_get_prediction();



// NO PUBLICAS:

void printImage();

void printVectors();

void printVectorInt(uint8_t * v);

void printVectorFloat(float * v);

void averagePooling(uint8_t* input, float* output, int origSize, int poolSize);

void maxPooling(uint8_t* input, float* output, int origSize, int poolSize);
