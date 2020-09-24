#include <Arduino.h>
#include "Ledsegment.h"
#include "global_init.h"
#include "stripe_init.h"
#include "random.h"
#include "collision_value.h"

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
			radar[i].stepUp();
		}
		radar_refresh = true;

		if((radar[0].isEndPosition()) and (radar[1].isEndPosition()) and (radar[2].isEndPosition()) and (radar[3].isEndPosition())) {
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
		Serial.println("Track -> Step");
	#endif
	for(uint8_t i=0; i<24; i++) {
		track[i].stepUp();
		#ifdef DEBUG_COM_TRACK_STEP_POSITION
			Serial.print("Position -> ");
			Serial.print(track[i].getPosition());
			Serial.println(" <");
		#endif
		if(track[i].getPosition() == COL_POS) {
			// Teil auf Radarposition
			#ifdef DEBUG_COM_TRACK_STEP
				Serial.print("Track -> ");
				Serial.print(i);
				Serial.print(" -> Col-Pos -> ");
				Serial.print(track[i].getCollision_v());
				Serial.print(" - ");
				Serial.print(track[i].getCollision_h1());
				Serial.print(" - ");
			#endif
			// track[i].getCollision_v())
			// track[i].getCollision_h1())
			if(track[i].getCollision_h2() > 0) {
				// Teil trifft 2 Radarstrahlen
				#ifdef DEBUG_COM_TRACK_STEP
					Serial.print(track[i].getCollision_h2());
					Serial.println(" <");
				#endif
			} else {
				#ifdef DEBUG_COM_TRACK_STEP
					Serial.println(" Kein H2 <");
				#endif
			}
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
