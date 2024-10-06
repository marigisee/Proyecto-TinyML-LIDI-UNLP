#include "game_logic.h"

char * labels_classes[] = {"Piedra","Papel","Tijera","Nada "};

void iteration() {
  Move playerMove  = getPlayerMove();
  Move machineMove = getMachineMove();

  Serial.println("####################################################################");
  Serial.println("");
  Serial.print("playerMove  -> "); Serial.println(labels_classes[playerMove]);
  Serial.print("machineMove ->  "); Serial.println(labels_classes[machineMove]);
  Serial.println("");
  Serial.println("####################################################################");

  // Calculate and show result
  calculateAndShowResult(playerMove, machineMove);

  waitForNothings();
}

Move getPlayerMove(){
  int consecutiveDetections = 0;
  Move lastDetectedMove = NOTHING;

  // First phase: Detect a consistent move
  while (consecutiveDetections < CONSECUTIVE_DETECTIONS_REQUIRED) {
    Move currentMove = takePhoto();
    
    if (currentMove != NOTHING) {
      if (currentMove == lastDetectedMove) {
        consecutiveDetections++;
      } else {
        consecutiveDetections = 1;
        lastDetectedMove = currentMove;
      }
    } else {
      consecutiveDetections = 0;
      lastDetectedMove = NOTHING;
    }
    
    delay(TIME_PLAYER_MS);  // Adjust delay as needed
  }
  return lastDetectedMove;
}

Move getMachineMove(){
  // Player's move detected, now program decides and plays
  Move programMove = decideMove();
  activateServo(programMove);
  return programMove;
}

void waitForNothings(){
  // Wait for the player to remove their hand
  int consecutiveNothings = 0;
  while (consecutiveNothings < CONSECUTIVE_NOTHING_REQUIRED) {
    if (takePhoto() == NOTHING) {
      consecutiveNothings++;
    } else {
      consecutiveNothings = 0;
    }
    delay(TIME_NOTHING_MS);  // Adjust delay as needed
  }
}

Move takePhoto() {
  // Implement photo capture and analysis
  // Return the detected move (ROCK, PAPER, SCISSORS, or NOTHING)
  // This is a placeholder implementation
  uint16_t moveDetected = take_photo_and_get_prediction();

  //int moveDetected = random(4);
  // Serial.print("takePhoto, moveDetected ->  "); Serial.println(moveDetected);
  return static_cast<Move>(moveDetected);
}

Move decideMove() {
  int randomMove = random(3);  // 0, 1, or 2
  return static_cast<Move>(randomMove);
}

void activateServo(Move move) {
  // Control the servo based on the move
  // You'll need to adjust these values based on your servo setup
  switch (move) {
    case ROCK:
      // Set servo to rock position
      break;
    case PAPER:
      // Set servo to paper position
      break;
    case SCISSORS:
      // Set servo to scissors position
      break;
    case NOTHING:
      // Reset servo to neutral position
      break;
  }
}
