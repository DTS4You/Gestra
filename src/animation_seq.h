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
	extern void anim_track_step(void);

	if(animation_state == 1) {
		for(uint8_t i=0; i<4; i++) {
			if(radar[i].stepUp()) {
				#ifdef DEBUG_COM_RADAR_STEP
					Serial.println("Animation -> Run");
				#endif
			} else {
				#ifdef DEBUG_COM_RADAR_STEP
					Serial.println("Animation -> Stop");
				#endif
				radar[i].stop();
			}
		}
	
		if((not radar[0].isEndPosition()) and (not radar[1].isEndPosition()) and (not radar[2].isEndPosition()) and (not radar[3].isEndPosition())) {
			#ifdef DEBUG_COM_RADAR_STEP
				Serial.println("Alles Radar Strahlen fertig");
			#endif
			animation_state = 2;
		}
	}
	if(animation_state == 2) {
		anim_track_step();
	}	
}

void anim_track_step() {
	#ifdef DEBUG_COM_TRACK_STEP
		Serial.println("Animation -> Track -> Step");
	#endif

	for(uint8_t i=0; i<24; i++) {
		if(track[i].stepUp()) {
			// Track step up
		} else {
			track[i].stop();
		}
	}

	radar[0].start();
	radar[1].start();
	radar[2].start();
	radar[3].start();

	animation_state = 1;

	track_refresh = true;
}

// Alles einen Schritt weiter
void animation_step() {
	#ifdef DEBUG_COM_STEP
		//Serial.println("Animation -> Step");
	#endif
	anim_radar_step();
}
