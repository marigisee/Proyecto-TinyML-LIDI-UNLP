#include "points_handler.h"

int cantWinsPlayer = 0;
int cantWinsMachine = 0;

#define cantWinsToEndGame 3

void calculateAndShowResult(Move lastDetectedMove, Move programMove)
{
  Winner winner = calculateWinner(lastDetectedMove, programMove);
  if (winner == PLAYER) cantWinsPlayer++;
  if (winner == MACHINE) cantWinsMachine++;

  prender_leds(cantWinsPlayer, cantWinsMachine);

  if (cantWinsPlayer == cantWinsToEndGame ||cantWinsMachine == cantWinsToEndGame ){
      endGame();
      cantWinsPlayer=0;
      cantWinsMachine=0;
  } 
}

Winner calculateWinner(Move playerMove, Move programMove) {
  Winner winner;
  if (playerMove == programMove) {
    winner = NONE;  // Tie
  } else if ((playerMove == ROCK && programMove == SCISSORS) ||
             (playerMove == PAPER && programMove == ROCK) ||
             (playerMove == SCISSORS && programMove == PAPER)) {
    winner = PLAYER;  // Player wins
  } else {
    winner = MACHINE;  // Program wins
  }
  
  return winner;
}

void prender_leds(int cantWinsPlayer, int cantWinsMachine)
{
  for (int i = 0 ; i < cantWinsPlayer; i+=1) Serial.print("x");
  for( int i = cantWinsPlayer; i<(6-cantWinsMachine); i++) Serial.print(" ");
  for (int i = 0 ; i < cantWinsMachine; i+=1) Serial.print("x");
  Serial.println(" ");
}

void endGame(){
  Serial.println("FIN DEL JUEGOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
  delay(100);

  //LOGICA EXTRA AL FINALIZAR EL JUEGO, POR EJEMPLO ESPERAR A UN BOTON

}