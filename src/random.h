#ifndef RANDOM_H
#define RANDOM_H

//-----------------------------------------------------------------------------
// Zufallsgenerator mit bestimmter Verteilung
//-----------------------------------------------------------------------------
// Arduino in Section Setup
// setup -> randomSeed(analogRead(0));
// loop  -> generate_random();
//-----------------------------------------------------------------------------

// #ifdef DEBUG_COM
// Serial.println(generate_random());
// #endif


#include <Arduino.h>


const PROGMEM uint8_t list[] = {1,2,3,4,5,5,6,6,7,7,8,8,8,9,9,9,10,10,10,10,11,11,11,11,11,12,12,12,12,12,12,13,13,13,13,13,13,14,14,14,14,14,15,15,15,15,16,16,16,17,17,17,18,18,19,19,20,20,21,22,23,24};

uint8_t generate_random() {
  uint8_t z;
  uint8_t temp = 0;
  extern uint8_t get_value_of_list();
  z = get_value_of_list();
  if(z == temp) {
      z = get_value_of_list();
  }
  
  temp = z;
  return z;			// Rückgabewert -> Zufallszahl
}

uint8_t get_value_of_list() {
  uint8_t i;
  uint8_t x;
  i = random(sizeof(list)-1);
  x = pgm_read_byte(&list[i]);
  return x;
}

#endif