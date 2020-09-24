#include <Arduino.h>
#include "Tracksegment.h"
#include "global_init.h"
#include "DDBooster.h"

#include "color_tables.h"

#define DEBUG_COM_Tracksegment

extern class DDBooster led_stripe[];

extern uint8_t color[];

Tracksegment::Tracksegment() {
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
}

Tracksegment::~Tracksegment() {
    //dtor
}
// Led Segmnent Setup
// ddb , begin , number
void Tracksegment::setup(uint8_t ddb, uint8_t begin, uint8_t number) {
	_ddb		= ddb;
	_begin 		= begin;
	_num		= number;
}
// Led Segment set color def
void Tracksegment::setColorDef(uint8_t c_index) {
	_color_def 	= c_index;
}
// Led Segment set color off
void Tracksegment::setColorOff(uint8_t c_index) {
	_color_off 	= c_index;
}
// Led Segment set color off
void Tracksegment::setColorOn(uint8_t c_index) {
	_color_on 	= c_index;
}
void Tracksegment::setCollision(uint8_t col_h1, uint8_t col_h2, uint8_t col_v) {
	_collision_h1	= col_h1;
	_collision_h2	= col_h2;
	_collision_v	= col_v;
}
uint8_t Tracksegment::getCollision_h1() {
	return _collision_h1;
}
uint8_t Tracksegment::getCollision_h2() {
	return _collision_h2;
}
uint8_t Tracksegment::getCollision_v() {
	return _collision_v;
}

// Track Segment Reset
void Tracksegment::reset() {
	_dir 		= false;
	_end_of_run	= false;
	stop();
}
// Led segment set to default with Color-Index
void Tracksegment::showRange(uint8_t c_index) {
	led_stripe[_ddb].setRGB(color_[c_index][0], color_[c_index][1], color_[c_index][2]);
	led_stripe[_ddb].setRange(_begin, _begin + _num - 1);
	delay(DDB_CMD_DELAY);
	//led_stripe[_ddb].show();
}
// Led segment color on position with Color-Index
void Tracksegment::showPosition(uint8_t c_index) {
	led_stripe[_ddb].setRGB(color_[c_index][0], color_[c_index][1], color_[c_index][2]);
	led_stripe[_ddb].setLED(_begin + _pos);
	//led_stripe[_ddb].show();
}
void Tracksegment::start() {
	_enable = true;
	_end_of_run = false;
}
void Tracksegment::stop() {
	_step		= 0;
	_enable 	= false;
	showRange(_color_def);
}
// Led segment set direction right
void Tracksegment::setRunRight() {
	_dir	= false;
}
// Led segment set direction left
void Tracksegment::setRunLeft() {
	_dir 	= true;
}
// Led animation step
void Tracksegment::stepUp() {
	#ifdef DEBUG_COM_Tracksegment
		Serial.print("Tracksegment -> Step Up -> ");
	#endif
	if(_enable) {
		#ifdef DEBUG_COM_Tracksegment
			Serial.print("Enable -> ");
		#endif
		// Alle LEDs auf Default Wert
		showRange(_color_def);
	
		if (_step < _num ) {
		// Ein Schritt -> +
		#ifdef DEBUG_COM_Tracksegment
			Serial.print(_step);
		#endif
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
			#ifdef DEBUG_COM_Tracksegment
				Serial.print("Stop");
			#endif
			stop();
			_end_of_run = true;
		}
	}
	#ifdef DEBUG_COM_Tracksegment
		Serial.println(" <");
	#endif
}

uint8_t Tracksegment::getPosition() {
	return _step;
}

bool Tracksegment::isEndPosition() {
	return _end_of_run;
}