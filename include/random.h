// Gaussche Verteilung

#include <arduino.h>

const PROGMEM uint8_t list[] = {1,2,3,4,5,5,6,6,7,7,8,8,8,9,9,9,10,10,10,10,11,11,11,11,11,12,12,12,12,12,12,13,13,13,13,13,13,14,14,14,14,14,15,15,15,15,16,16,16,17,17,17,18,18,19,19,20,20,21,22,23,24};

uint8_t random_width = sizeof(list);

uint8_t random_value = random(1,random_width);
