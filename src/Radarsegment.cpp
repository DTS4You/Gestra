#include <Arduino.h>
#include "Radarsegment.h"
#include "global_init.h"
#include "DDBooster.h"

#include "color_tables.h"

#define DEBUG_COM_Radarsegment

extern class DDBooster led_stripe[];

extern uint8_t color[];

Radarsegment::Radarsegment() {
	_ddb				= 0;
	_num				= 0;
	_begin 				= 0;
	_step 				= 0;
	_pos				= 0;
	_collision_h1		= 0;
	_collision_h2		= 0;
	_collision_v		= 0;
	_color_def			= 0;
	_color_off			= 0;
	_color_on			= 0;
	_dir 				= false;		// false -> right ; true -> left
	_end_of_run			= false;
	_collision_on		= false;		// Kollision ein / aus
	_collision_flag		= false;		// Kollision erkannt -> Richtung zurück
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
void Radarsegment::setCollision(uint8_t col_h1, uint8_t col_h2, uint8_t col_v) {
	_collision_h1	= col_h1;
	_collision_h2	= col_h2;
	_collision_v	= col_v;
}
uint8_t Radarsegment::getCollision_h1() {
	return _collision_h1;
}
uint8_t Radarsegment::getCollision_h2() {
	return _collision_h2;
}
uint8_t Radarsegment::getCollision_v() {
	return _collision_v;
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
	#ifdef DEBUG_COM_Radarsegment
		Serial.print("Radarsegment -> Step Up -> ");
	#endif
	if(_enable) {
		#ifdef DEBUG_COM_Radarsegment
			Serial.print("Enable -> ");
		#endif
		// Alle LEDs auf Default Wert
		showRange(_color_def);
	
		if(!_collision_flag) {
			if (_step < _num ) {
			// Ein Schritt -> +
			#ifdef DEBUG_COM_Radarsegment
				Serial.print(_step);
				Serial.print(" - ");
				Serial.print(_collision_on);
				Serial.print(" - ");
				Serial.print(_collision_v);
			#endif
			if(_collision_on) {
				if(_step == _collision_v) {
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
				#ifdef DEBUG_COM_Radarsegment
					Serial.print("Stop");
				#endif
				stop();
				_end_of_run = true;
			}
		} else {
			if (_step > 0 ) {
				// Ein Schritt -> -
				#ifdef DEBUG_COM_Radarsegment
					Serial.print(_step);
				#endif
				if (!_dir) {
					_pos = _step;
				} else {
					_pos = _num - _step - 1;
				}
				//showRange(_color_def);
				showPosition(_color_on);
				_step--;
			} else {
				#ifdef DEBUG_COM_Radarsegment
					Serial.print("Hit-Stop!!!");
				#endif
				_collision_flag = false;
				stop();
				_end_of_run = true;
			}
		}
	}
	#ifdef DEBUG_COM_Radarsegment
		Serial.println(" <");
	#endif
}

uint8_t Radarsegment::getPosition() {
	return _step;
}

bool Radarsegment::isEndPosition() {
	return _end_of_run;
}