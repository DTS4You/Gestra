#ifndef RADARSEGMENT_H
#define RADARSEGMENT_H

#include <Arduino.h>

class Radarsegment
{
	public:
		Radarsegment();
      virtual ~Radarsegment();
		void setup(uint8_t, uint8_t, uint8_t);
		void setColorDef(uint8_t);
		void setColorOff(uint8_t);
		void setColorOn(uint8_t);
		void reset();
		void start();
		void stop();
		void showRange(uint8_t);
		void showPosition(uint8_t);
		void stepUp();
		void setRunLeft();
		void setRunRight();
		void setCollision(uint8_t);
		uint8_t getPosition();
		bool isEndPosition();

    protected:

    private:
		uint8_t	_ddb;
		uint8_t	_num;
		uint8_t _begin;
		uint8_t _step;
		uint8_t	_pos;
		uint8_t _color_off;
		uint8_t _color_def;
		uint8_t _color_on;
		uint8_t _collision_value;
		bool	_dir;
		bool	_enable;
		bool	_end_of_run;
		bool	_collision_on;
		bool	_collision_flag;
};

#endif
