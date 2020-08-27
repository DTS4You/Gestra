// ################################################################################
// ###                                                                          ###
// ### Projekt			: Gestra												###
// ### Version			: 0.10													###
// ### Datum			: 27.08.2020											###
// ###                                                                          ###
// ### Änderung			: keine													###
// ###																			###
// ### Hardware			: Arduino Nano											###
// ###					: Leiterplatte 17-0023-02 und 17-0027-02				###
// ###					: 8 x Digi-Dot-Booster									###
// ###					: 1 x Taster mit LED Ring								###
// ################################################################################

// #define DEBUG_LED

#include <arduino.h>
// #include "ascii_codes.h"
#include "global_init.h"
#include "stripe_init.h"


#include "DDBooster.h"
#include "RBD_Timer.h"  			// https://github.com/alextaujenis/RBD_Timer
#include "RBD_ButtonExtern.h"		// https://github.com/alextaujenis/RBD_Button
#include "color_tables.h"


#include "I2C.h"

#include "Ledsegment.h"
#include "animation_seq.h"

const uint8_t ddb_cs_pin[DDB_COUNT] 	= { DDB_1_CS_PIN, DDB_2_CS_PIN, DDB_3_CS_PIN, DDB_4_CS_PIN, DDB_5_CS_PIN, DDB_6_CS_PIN, DDB_7_CS_PIN, DDB_8_CS_PIN};
const uint8_t ddb_num_led[DDB_COUNT]	= { DDB_1_MAX_LED, DDB_2_MAX_LED, DDB_3_MAX_LED, DDB_4_MAX_LED, DDB_5_MAX_LED, DDB_6_MAX_LED, DDB_7_MAX_LED, DDB_8_MAX_LED };
uint8_t	ddb_refresh = false;

//uint8_t	global_input	= 0;	 // Wird im Objekt ButtonExtern erzeugt
uint8_t	global_output	= 0;
uint8_t blink_flag		= 0;
uint8_t state_value		= 0;
uint8_t animation_state	= 0;

// Digi-Dot-Booster Objekte erzeugen
DDBooster led_stripe[DDB_COUNT];			// Objekt anlegen

// Timer Objekte anlegen
RBD::Timer io_task;
RBD::Timer button_blink;
RBD::Timer animation_timer;
RBD::Timer sequence_timer;

// Button Objekte anlegen
RBD::ButtonExtern button_1(0);

// LED Segmente Objekte anlegen
Ledsegment track[24];
Ledsegment radar[4];

// ----------------------------------------------------------------------------
// Setup
// ----------------------------------------------------------------------------
void setup() {

	// I2C Setup
	I2c.begin();
	I2c.setSpeed(1);
	I2c.write(MCP23017,0x05,0x00);
	I2c.write(MCP23017,0x00,0x00);	// Setup MCP23017 GPIO-A to Output
	I2c.write(MCP23017,0x01,0xFF);	// Setup MCP23017 GPIO-B to Input
	I2c.write(MCP23017,0x14,   0);	// MCP23017 auf Startwert -> Ausgänge 1-8 auf aus

	// Digi-Dot-Booster init
	for (uint8_t i = 0; i < DDB_COUNT; i++)
	{
		// Digi-Dot-Booster CS-Pin konfigurieren
		led_stripe[i].configurePins(ddb_cs_pin[i]);
		delay(DDB_INIT_DELAY);
		// Digi-Dot-Booster -> Anzahl der LEDs pro Digi-Dot-Booster
		led_stripe[i].init(ddb_num_led[i]);
		delay(DDB_INIT_DELAY);
		led_stripe[i].clearAll();
		delay(DDB_INIT_DELAY);
		led_stripe[i].show();
		delay(DDB_INIT_DELAY);
	}

	button_1.invertReading();

	// Timer definieren und starten
	io_task.setTimeout(IO_LOOP_TIME);
	io_task.restart();
	//refresh_task.setTimeout(Refresh_Time);
	//refresh_task.restart();
	button_blink.setTimeout(BUTTON_BLINK_TIME);
	button_blink.restart();
	animation_timer.setTimeout(ANIMATION_TIME);
	animation_timer.restart();
	sequence_timer.setTimeout(SEQUENCE_TIME);
	sequence_timer.stop();

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
	

	ddb_refresh = true;
	//-------------------------------------------------------------------------

	global_output = 0xFF;
}

// ----------------------------------------------------------------------------
// Main Loop
// ----------------------------------------------------------------------------
void loop() {

	// IO-Timer
	if(io_task.onRestart()) {
		// MCP23017 Input einlesen und auf Output ausgeben
		I2c.write(MCP23017, 0x13);
		I2c.read(MCP23017, 1);
		global_input	= I2c.receive();
		//global_output	= global_input;
		I2c.write(MCP23017,0x14,global_output);
	}
	// Blink-Timer
	if(button_blink.onRestart()) {
		if (blink_flag) {
			global_output = global_output | state_value;
		}
		else {
			global_output = global_output & ~state_value;
		}
		blink_flag = !blink_flag;
	}
	//---------------------------------------------------------------------------
	// Animation Timer
	//---------------------------------------------------------------------------
	if(animation_timer.onRestart()) {
		if(animation_state > 0) {
			track[0].stepUp();
			/*
			seg_2.stepUp();
			seg_3.stepUp();
			seg_4.stepUp();
			seg_5.stepUp();
			seg_6.stepUp();
			seg_7.stepUp();
			seg_8.stepUp();
			seg_9.stepUp();
			*/
			ddb_refresh = true;
		}
 	}
	//---------------------------------------------------------------------------
	// User Funktionen
	//---------------------------------------------------------------------------
	if(sequence_timer.onRestart()) {
		if(animation_state > 0) {
			animation_state++;
			//animation_seq();
		}
 	}
	//---------------------------------------------------------------------------
	// Tasten abfragen
	//---------------------------------------------------------------------------
	// Taste 1 ist betätiget worden
	if(button_1.onPressed()) {
		global_output	= global_output & ~( 1 << 0 );
		state_value		= state_value   |  ( 1 << 0 );
		// Nur wenn keine Animation mehr läuft kann neu gestartet werden
		if(animation_state == 0) {
			animation_state = 1;
			//animation_seq();
			sequence_timer.restart();
		}
	}
	//-------------------------------------------------------------------------
	// Refresh Task -> Alle Digi-Dot Booster ddb.show() aufrufen
	//-------------------------------------------------------------------------
	if(ddb_refresh)
	{
		delay(DDB_INIT_DELAY);			// Workaround for DDB SPI Problem
		for (uint8_t i = 0; i < DDB_COUNT; i++)
		{
			led_stripe[i].show();
			delay(DDB_INIT_DELAY);		// Workaround for DDB SPI Problem
		}
		ddb_refresh = false;
	}
}
