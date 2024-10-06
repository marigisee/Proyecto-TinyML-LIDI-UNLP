#ifndef POINTS_HANDLER_H
#define POINTS_HANDLER_H

#include <stdint.h> 
#include <Arduino.h>

enum Winner {PLAYER, MACHINE, NONE};
enum Move { ROCK, PAPER, SCISSORS, NOTHING };

void calculateAndShowResult(Move lastDetectedMove, Move programMove);
Winner calculateWinner(Move playerMove, Move programMove) ;
void prender_leds(int cantWinsPlayer, int cantWinsMachine);
void endGame();

#endif