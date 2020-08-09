// Arduino RBD Button Library v2.1.0 - Read and debounce buttons and switches.
// https://github.com/alextaujenis/RBD_Button
// Copyright 2016 Alex Taujenis
// MIT License

#include <Arduino.h>
#include <RBD_Timer.h>           // https://github.com/alextaujenis/RBD_Timer
#include <RBD_ButtonExtern.h>    // https://github.com/alextaujenis/RBD_Button

uint8_t global_input;

namespace RBD {
  // input pullup enabled by default
  ButtonExtern::ButtonExtern(uint8_t pin)
  {
    _pin    = pin;
  }

  bool ButtonExtern::isPressed()
  {
     _temp_reading = global_input & ( 1 << _pin );
     if(_invert)
     {
        return !_temp_reading;
     }
     else
     {
        return _temp_reading;
     }
  }

  bool ButtonExtern::isReleased()
  {
     return !isPressed();
  }

  bool ButtonExtern::onPressed()
  {
    if(isPressed())
    {
      if(!_has_been_pressed)
      {
         return _has_been_pressed = true;
      }
      return false;
    }
    else
    {
       return _has_been_pressed = false;
    }
  }

  bool ButtonExtern::onReleased()
  {
     if(isReleased())
     {
        if(!_has_been_released)
        {
           return _has_been_released = true;
        }
        return false;
     }
     else
     {
        return _has_been_released = false;
     }
  }

  void ButtonExtern::invertReading() {
    _invert = !_invert;
  }
}
