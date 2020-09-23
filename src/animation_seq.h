#include <Arduino.h>
#include "Ledsegment.h"
#include "global_init.h"
#include "stripe_init.h"
#include "random.h"

extern class Ledsegment track[];
extern class Ledsegment radar[];
extern uint8_t animation_state;
extern bool anim_flag;
extern bool track_refresh;
extern bool radar_refresh;
//extern global_input;
extern uint8_t global_output;
extern uint8_t state_value;


void anim_radar_step() {
// Radarstrahlen von unten nach oben, bei Kollision zurück nach unten.
	for(uint8_t i=0; i<4; i++) {
		if(radar[i].stepUp()) {
			#ifdef DEBUG_COM_STEP
				Serial.println("Animation -> Run");
			#endif
		} else {
			#ifdef DEBUG_COM_STEP
				Serial.println("Animation -> Stop");
			#endif
			radar[i].stop();
		}
	}
	if(radar[0].isEndPosition() && radar[1].isEndPosition() && radar[2].isEndPosition() && radar[3].isEndPosition()) {
		#ifdef DEBUG_COM_STEP
			Serial.println("Alles Radar Strahlen fertig");
		#endif
	}
}

// Alles einen Schritt weiter
void animation_step() {
	#ifdef DEBUG_COM_STEP
		//Serial.println("Animation -> Step");
	#endif
	anim_radar_step();
}
