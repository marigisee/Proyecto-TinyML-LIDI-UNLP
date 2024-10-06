#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "points_handler.h"
#include "take_photo_and_predict.h"

#include <stdint.h> 

#include <Arduino.h>

#define TIME_PLAYER_MS 200   // Tiempo de espera en milisegundos entre capturas de imagen de la mano (no considerado el tiempo de inferencia)
#define TIME_NOTHING_MS 100  // Tiempo de espera en milisegundos entre capturas de imagen de "NADA" (no considerado el tiempo de inferencia)

#define CONSECUTIVE_DETECTIONS_REQUIRED 3 // Cantidad de veces consecutivas que debe salir la misma predicción para decidir la opción del jugador
#define CONSECUTIVE_NOTHING_REQUIRED 3    // Cantidad de veces consecutivas que debe salir "NADA" antes de empezar a detectar la opción del jugador

void iteration();
Move getPlayerMove();
Move getMachineMove();
void waitForNothings();
Move takePhoto();
Move decideMove();
void activateServo(Move move);

#endif