#ifndef TAKE_PHOTO_AND_PREDICT_H
#define TAKE_PHOTO_AND_PREDICT_H

#include <stdint.h> 

#define ESP32_CAM 1 // flag para indicar si se está ejecutando en esp32-cam o una version en simulador para probar la lógica del programa

// PUBLICAS: 
void initial_setup();
uint16_t take_photo_and_get_prediction();

// NO PUBLICAS:
void printImage();
void printVectors();
void printVectorInt(uint8_t * v);
void printVectorFloat(float * v);
#if ESP32_CAM == 1
	void averagePooling(uint8_t * input, float* output, int origSize, int poolSize);
	void maxPooling(uint8_t * input, float* output, int origSize, int poolSize);
#else
	void averagePooling(float * input, float* output, int origSize, int poolSize);
	void maxPooling(float * input, float* output, int origSize, int poolSize);
#endif

#endif
