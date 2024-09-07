#include "take_photo_and_predict.h"

// ----------- setup ----------- //
void setup() {
  initial_setup();
}

// ----------- loop ----------- //
void loop() {
  uint16_t prediction = take_photo_and_get_prediction(); 
}
