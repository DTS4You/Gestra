#include <Arduino.h>
#include "Ledsegment.h"
#include "global_init.h"
#include "stripe_init.h"


extern class Ledsegment track[];
extern class Ledsegment radar[];
extern class RBD::Timer sequence_timer; 
extern uint8_t animation_state;
extern bool anim_flag;
extern bool ddb_refresh;
//extern global_input;
extern uint8_t global_output;
extern uint8_t state_value;

// Alles einen Schritt weiter
void animation_step() {
	// Radarstrahlen von unten nach oben, bei Kollision zurück nach unten.
	for(uint8_t i=0; i<4; i++) {
		radar[i].stepUp();
	}
	
}
/*
void animation_seq() {
    // ------------------------------------------------------------------------
    // Bodenstation -> Geo-SAT
    // ------------------------------------------------------------------------
	if(animation_state == 1) {
		seg_1.start();
	}
	// ------------------------------------------------------------------------
    // Bodenstation -> 1. Cluster-SAT
    // ------------------------------------------------------------------------
	if(animation_state == 2) {
		seg_3.start();
		//seg_3.start();
	}
	// ------------------------------------------------------------------------
    // 1. Cluster-SAT -> 2. Cluster-SAT
    // ------------------------------------------------------------------------
    if(animation_state == 3) {
        seg_4.start();
	}
	// ------------------------------------------------------------------------
    // 2. Cluster-SAT -> 3. Cluster-SAT
    // ------------------------------------------------------------------------
    if(animation_state == 4) {
        seg_5.start();
	}
    // ------------------------------------------------------------------------
    // 3. Cluster-SAT -> 4. Cluster-SAT
    // ------------------------------------------------------------------------
    if(animation_state == 5) {
		seg_6.start();
	}
    // ------------------------------------------------------------------------
    // 2. Cluster-SAT -> 4. Cluster-SAT
    // ------------------------------------------------------------------------
    if(animation_state == 6) {
		seg_9.start();
	}
    // ------------------------------------------------------------------------
    // 4. Cluster-SAT -> 1. Cluster-SAT
    // ------------------------------------------------------------------------
    if(animation_state == 7) {
		seg_7.start();
	}
    // ------------------------------------------------------------------------
    // 1. Cluster-SAT -> 3. Cluster-SAT
    // ------------------------------------------------------------------------
    if(animation_state == 8) {
		seg_8.start();
	}
	// ------------------------------------------------------------------------
    // Geo-SAT -> 3. Cluster-SAT
    // ------------------------------------------------------------------------
    if(animation_state == 9) {
		seg_2.start();
		sequence_timer.setTimeout(SEQUENCE_LAST_STATE);
	}
	// ------------------------------------------------------------------------
    // Sequenz-Ende !!!
    // ------------------------------------------------------------------------
    if(animation_state == 10) {
    	seg_1.reset();
		seg_2.reset();
		seg_3.reset();
		seg_4.reset();
		seg_5.reset();
		seg_6.reset();
		seg_7.reset();
		seg_8.reset();
		seg_9.reset();
        sequence_timer.stop();
		sequence_timer.setTimeout(SEQUENCE_TIME);
		animation_state = 0;

		global_output	= global_output |  ( 1 << 0 );
		state_value		= state_value   & ~( 1 << 0 );
	}
	// ------------------------------------------------------------------------
    // DDB Refresh
	ddb_refresh = true;
	// ------------------------------------------------------------------------
}

*/