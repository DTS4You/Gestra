// Arduino RBD Button Library v2.1.0 - Read and debounce buttons and switches.
// https://github.com/alextaujenis/RBD_Button
// Copyright 2016 Alex Taujenis
// MIT License

#ifndef RBD_BUTTONEXTERN_H
#define RBD_BUTTONEXTERN_H

#include <Arduino.h>
//#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
extern uint8_t global_input;

namespace RBD {
  class ButtonExtern {
    public:
      ButtonExtern(uint8_t bit);   // constructor:
      bool isPressed();
      bool isReleased();
      bool onPressed();
      bool onReleased();
      void invertReading();
    private:
      uint8_t _pin;
      bool _has_been_pressed  = false;
      bool _has_been_released = false;
      bool _invert = true;
      bool _temp_reading;
  };
}
#endif
