#ifndef LEDSEGMENT_H
#define LEDSEGMENT_H

#include <Arduino.h>

class Ledsegment
{
	public:
		Ledsegment();
      virtual ~Ledsegment();
		void setup(uint8_t, uint8_t, uint8_t);
		void setColorDef(uint8_t);
		void setColorOff(uint8_t);
		void setColorOn(uint8_t);
		void reset();
		void start();
		void stop();
		void showRange(uint8_t);
		void showPosition(uint8_t);
		bool stepUp();
		void setRunLeft();
		void setRunRight();
		void setRunToggleOn();
		void setCollision(uint8_t, uint8_t, uint8_t);
		uint8_t getPosition();

    protected:

    private:
		uint8_t	_ddb;
		uint8_t	_num;
		uint8_t _begin;
		uint8_t _step;
		uint8_t	_pos;
		uint8_t _collision_h1;
		uint8_t _collision_h2;
		uint8_t _collision_v;
		uint8_t _color_off;
		uint8_t _color_def;
		uint8_t _color_on;
		bool	_dir;
		bool	_enable;
		bool	_toggle;
		bool	_end_of_run;
		bool	_blank_start_end;
};

#endif
