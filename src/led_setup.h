// LED-Stripes werden initalisiert
#ifndef LED_SETUP_H
#define LED_SETUP_H

#include <Arduino.h>
#include "global_init.h"
#include "stripe_init.h"
#include "collision_value.h"
#include "Ledsegment.h"


extern class Ledsegment track[];
extern class Ledsegment radar[];

void led_setup() {
	// Segmente definieren
	track[0].setup(STRIPE_01_DDB, STRIPE_01_START, STRIPE_01_NUM);
	track[1].setup(STRIPE_02_DDB, STRIPE_02_START, STRIPE_02_NUM);
	track[2].setup(STRIPE_03_DDB, STRIPE_03_START, STRIPE_03_NUM);
	track[3].setup(STRIPE_04_DDB, STRIPE_04_START, STRIPE_04_NUM);
	track[4].setup(STRIPE_05_DDB, STRIPE_05_START, STRIPE_05_NUM);
	track[5].setup(STRIPE_06_DDB, STRIPE_06_START, STRIPE_06_NUM);
	track[6].setup(STRIPE_07_DDB, STRIPE_07_START, STRIPE_07_NUM);
	track[7].setup(STRIPE_08_DDB, STRIPE_08_START, STRIPE_08_NUM);
	track[8].setup(STRIPE_09_DDB, STRIPE_09_START, STRIPE_09_NUM);
	track[9].setup(STRIPE_10_DDB, STRIPE_10_START, STRIPE_10_NUM);
	track[10].setup(STRIPE_11_DDB, STRIPE_11_START, STRIPE_11_NUM);
	track[11].setup(STRIPE_12_DDB, STRIPE_12_START, STRIPE_12_NUM);
	track[12].setup(STRIPE_13_DDB, STRIPE_13_START, STRIPE_13_NUM);
	track[13].setup(STRIPE_14_DDB, STRIPE_14_START, STRIPE_14_NUM);
	track[14].setup(STRIPE_15_DDB, STRIPE_15_START, STRIPE_15_NUM);
	track[15].setup(STRIPE_16_DDB, STRIPE_16_START, STRIPE_16_NUM);
	track[16].setup(STRIPE_17_DDB, STRIPE_17_START, STRIPE_17_NUM);
	track[17].setup(STRIPE_18_DDB, STRIPE_18_START, STRIPE_18_NUM);
	track[18].setup(STRIPE_19_DDB, STRIPE_19_START, STRIPE_19_NUM);
	track[19].setup(STRIPE_20_DDB, STRIPE_20_START, STRIPE_20_NUM);
	track[20].setup(STRIPE_21_DDB, STRIPE_21_START, STRIPE_21_NUM);
	track[21].setup(STRIPE_22_DDB, STRIPE_22_START, STRIPE_22_NUM);
	track[22].setup(STRIPE_23_DDB, STRIPE_23_START, STRIPE_23_NUM);
	track[23].setup(STRIPE_24_DDB, STRIPE_24_START, STRIPE_24_NUM);

	radar[0].setup(STRIPE_25_DDB, STRIPE_25_START, STRIPE_25_NUM);
	radar[1].setup(STRIPE_26_DDB, STRIPE_26_START, STRIPE_26_NUM);
	radar[2].setup(STRIPE_27_DDB, STRIPE_27_START, STRIPE_27_NUM);
	radar[3].setup(STRIPE_28_DDB, STRIPE_28_START, STRIPE_28_NUM);

    for (uint8_t i=0; i<24; i++) {
		track[i].setColorDef(F_LED_DEF);
		track[i].setColorOn(F_LED_ON);
	}
	
	for (uint8_t i=0; i<4; i++) {
		radar[i].setColorDef(F_LED_DEF);
		radar[i].setColorOn(F_LED_ON);
	}

	//-------------------------------------------------------------------------
	// Grundeinstellungen LED Stripes
	//-------------------------------------------------------------------------

	for (uint8_t i=0; i<24; i++) {
		track[i].showRange(F_LED_DEF);
	}
	
	for (uint8_t i=0; i<4; i++) {
		radar[i].showRange(F_LED_DEF);
	}
}

#endif
