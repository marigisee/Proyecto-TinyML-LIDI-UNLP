#define GAME_LOGIC_H
#include "points_handler.h"
#include "take_photo_and_predict.h"

#include <stdint.h> 

#include <Arduino.h>



void iteration();
Move getPlayerMove();
Move getMachineMove();
void waitForNothings();
Move takePhoto();
Move decideMove();
void activateServo(Move move);