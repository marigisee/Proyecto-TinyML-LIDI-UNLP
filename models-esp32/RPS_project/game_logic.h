#define GAME_LOGIC_H

#include <stdint.h> 

#include <Arduino.h>

enum Move { ROCK, PAPER, SCISSORS, NOTHING };


void iteration();
Move getPlayerMove();
Move getMachineMove();
void waitForNothings();
Move takePhoto();
Move decideMove();
void activateServo(Move move);
void calculateAndShowResult(Move playerMove, Move programMove);
void controlLEDs(int result);