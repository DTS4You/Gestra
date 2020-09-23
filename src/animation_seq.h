#include <Arduino.h>
#include "Ledsegment.h"
#include "global_init.h"
#include "stripe_init.h"
#include "random.h"

extern class Ledsegment track[];
extern class Ledsegment radar[];
extern uint8_t animation_state;
extern bool anim_flag;
extern bool ddb_refresh;
//extern global_input;
extern uint8_t global_output;
extern uint8_t state_value;

// Alles einen Schritt weiter
void animation_step() {
	#ifdef DEBUG_COM
		Serial.println("Animation -> Step");
	#endif

	// Radarstrahlen von unten nach oben, bei Kollision zurück nach unten.
	for(uint8_t i=0; i<4; i++) {
		radar[i].stepUp();
	}
	

	// ------------------------------------------------------------------------
    // DDB Refresh
	ddb_refresh = true;
	// ------------------------------------------------------------------------
}