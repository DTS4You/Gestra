#include <Arduino.h>
#include "Radarsegment.h"
#include "global_init.h"
#include "DDBooster.h"

#include "color_tables.h"

extern class DDBooster led_stripe[];

extern uint8_t color[];

Radarsegment::Radarsegment() {
	_ddb				= 0;
	_num				= 0;
	_begin 				= 0;
	_step 				= 0;
	_pos				= 0;
	_color_def			= 0;
	_color_off			= 0;
	_color_on			= 0;
	_collision_value	= 0;			// Kollisionswert
	_dir 				= false;		// false -> right ; true -> left
	_end_of_run			= false;		// Animation Ende
	_collision_on		= false;
	_collision_flag		= false;		// Kollision -> Richtung zurück
}

Radarsegment::~Radarsegment() {
    //dtor
}
// Led Segmnent Setup
// ddb , begin , number
void Radarsegment::setup(uint8_t ddb, uint8_t begin, uint8_t number) {
	_ddb		= ddb;
	_begin 		= begin;
	_num		= number;
}
// Led Segment set color def
void Radarsegment::setColorDef(uint8_t c_index) {
	_color_def 	= c_index;
}
// Led Segment set color off
void Radarsegment::setColorOff(uint8_t c_index) {
	_color_off 	= c_index;
}
// Led Segment set color off
void Radarsegment::setColorOn(uint8_t c_index) {
	_color_on 	= c_index;
}
// Set Collision
void Radarsegment::setCollision(uint8_t col) {
	_collision_value = col;
	if(_collision_value > 0) {
		_collision_on = true;
	} else {
		_collision_on = false;
	}
}
// Led Segment Reset
void Radarsegment::reset() {
	_dir 		= false;
	_end_of_run	= false;
	stop();
}
// Led segment set to default with Color-Index
void Radarsegment::showRange(uint8_t c_index) {
	led_stripe[_ddb].setRGB(color_[c_index][0], color_[c_index][1], color_[c_index][2]);
	led_stripe[_ddb].setRange(_begin, _begin + _num - 1);
	delay(DDB_CMD_DELAY);
	//led_stripe[_ddb].show();
}
// Led segment color on position with Color-Index
void Radarsegment::showPosition(uint8_t c_index) {
	led_stripe[_ddb].setRGB(color_[c_index][0], color_[c_index][1], color_[c_index][2]);
	led_stripe[_ddb].setLED(_begin + _pos);
	//led_stripe[_ddb].show();
}
void Radarsegment::start() {
	_enable = true;
	_end_of_run = false;
}
void Radarsegment::stop() {
	_step		= 0;
	_enable 	= false;
	showRange(_color_def);
}
// Led segment set direction right
void Radarsegment::setRunRight() {
	_dir	= false;
}
// Led segment set direction left
void Radarsegment::setRunLeft() {
	_dir 	= true;
}
// Led animation step
void Radarsegment::stepUp() {
	if(_enable) {
		// Alle LEDs auf Default Wert
		showRange(_color_def);
	
		if(!_collision_flag) {
			if (_step < _num ) {
			// Ein Schritt -> +
			if(_collision_on) {
				if(_step == _collision_value) {
					_collision_flag = true;
				}
			}
			// Ausrichtung links <-> rechsts auswerten
			if (!_dir) {
				_pos = _step;
			} else {
				_pos = _num - _step - 1;
			}
			//showRange(_color_def);
			showPosition(_color_on);
			_step++;
			} else {
				stop();
				_end_of_run = true;
			}
		} else {
			if (_step > 0 ) {
				// Ein Schritt -> -
				_step--;
				if (!_dir) {
					_pos = _step;
				} else {
					_pos = _num - _step - 1;
				}
				//showRange(_color_def);
				showPosition(_color_on);
			} else {
				_collision_flag = false;
				_collision_on = false;
				stop();
				_end_of_run = true;
			}
		}
	}
}

uint8_t Radarsegment::getPosition() {
	return _step;
}

bool Radarsegment::isEndPosition() {
	return _end_of_run;
}