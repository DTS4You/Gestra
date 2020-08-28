
#include <Arduino.h>
#include "Ledsegment.h"
#include "global_init.h"
#include "DDBooster.h"

#include "color_tables.h"

extern class DDBooster led_stripe[];

extern uint8_t color[];

Ledsegment::Ledsegment() {
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
	_toggle				= false;
	_end_of_run			= false;
	_blank_start_end	= false;		// Start and end with a blank LED
}

Ledsegment::~Ledsegment() {
    //dtor
}
// Led Segmnent Setup
// ddb , begin , number
void Ledsegment::setup(uint8_t ddb, uint8_t begin, uint8_t number) {
	_ddb		= ddb;
	_begin 		= begin;
	_num		= number;
}
// Led Segment set color def
void Ledsegment::setColorDef(uint8_t c_index) {
	_color_def 	= c_index;
}
// Led Segment set color off
void Ledsegment::setColorOff(uint8_t c_index) {
	_color_off 	= c_index;
}
// Led Segment set color off
void Ledsegment::setColorOn(uint8_t c_index) {
	_color_on 	= c_index;
}
void Ledsegment::setCollision(uint8_t col_h1, uint8_t col_h2, uint8_t col_v) {
	_collision_h1	= col_h1;
	_collision_h2	= col_h2;
	_collision_v	= col_v;
}
// Led Segment Reset
void Ledsegment::reset() {
	_dir 		= false;
	_end_of_run	= false;
	stop();
}
// Led segment set to default with Color-Index
void Ledsegment::showRange(uint8_t c_index) {
	led_stripe[_ddb].setRGB(color_[c_index][0], color_[c_index][1], color_[c_index][2]);
	led_stripe[_ddb].setRange(_begin, _begin + _num - 1);
	//led_stripe[_ddb].show();
}
// Led segment color on position with Color-Index
void Ledsegment::showPosition(uint8_t c_index) {
	led_stripe[_ddb].setRGB(color_[c_index][0], color_[c_index][1], color_[c_index][2]);
	led_stripe[_ddb].setLED(_begin + _pos);
	//led_stripe[_ddb].show();
}
void Ledsegment::start() {
	_enable = true;
}
void Ledsegment::stop() {
	_step		= 0;
	_enable 	= false;
	_end_of_run	= false;
	showRange(_color_def);
}
// Led segment set direction right
void Ledsegment::setRunRight() {
	_dir	= false;
}
// Led segment set direction left
void Ledsegment::setRunLeft() {
	_dir 	= true;
}
// Led segment set toggle on
void Ledsegment::setRunToggleOn() {
	_toggle = true;
}
// Led animation step
bool Ledsegment::stepUp() {
	if(_enable) {
		showRange(_color_def);
		if (!_end_of_run) {
			_step 		= 0;
			_end_of_run	= true;
		}
		if (_step < _num  ) {
			if (!_dir) {
				_pos = _step;
			} else {
				_pos = _num - _step - 1;
			}
			//showRange(_color_def);
			showPosition(_color_on);
			_step++;
		} else {
			if(_toggle) {
				_dir = !_dir;
			}
			_end_of_run = false;
		}
	}
	return _end_of_run;
}

uint8_t Ledsegment::getPosition() {
	return _step;
}
