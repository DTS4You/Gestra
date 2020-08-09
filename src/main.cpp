// ################################################################################
// ###                                                                          ###
// ### Projekt			: Satelitten Cluster									###
// ### Version			: 1.00													###
// ### Datum			: 21.06.2020											###
// ###                                                                          ###
// ### Änderung			: keine													###
// ###																			###
// ### Hardware			: Arduino Nano											###
// ###					: Leiterplatte 17-0023-02 und 17-0027-02				###
// ###					: 2 x Digi-Dot-Booster, vom max. 8 Stück				###
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

const uint8_t ddb_cs_pin[DDB_COUNT] 	= { DDB_1_CS_PIN, DDB_2_CS_PIN };
const uint8_t ddb_num_led[DDB_COUNT]	= { DDB_1_MAX_LED, DDB_2_MAX_LED };
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
Ledsegment seg_1;
Ledsegment seg_2;
Ledsegment seg_3;
Ledsegment seg_4;
Ledsegment seg_5;
Ledsegment seg_6;
Ledsegment seg_7;
Ledsegment seg_8;
Ledsegment seg_9;

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
	seg_1.setup(STRIPE_1_DDB, STRIPE_1_START, STRIPE_1_NUMBER);
	seg_2.setup(STRIPE_2_DDB, STRIPE_2_START, STRIPE_2_NUMBER);
	seg_3.setup(STRIPE_3_DDB, STRIPE_3_START, STRIPE_3_NUMBER);
	seg_4.setup(STRIPE_4_DDB, STRIPE_4_START, STRIPE_4_NUMBER);
	seg_5.setup(STRIPE_5_DDB, STRIPE_5_START, STRIPE_5_NUMBER);
	seg_6.setup(STRIPE_6_DDB, STRIPE_6_START, STRIPE_6_NUMBER);
	seg_7.setup(STRIPE_7_DDB, STRIPE_7_START, STRIPE_7_NUMBER);
	seg_8.setup(STRIPE_8_DDB, STRIPE_8_START, STRIPE_8_NUMBER);
	seg_9.setup(STRIPE_9_DDB, STRIPE_9_START, STRIPE_9_NUMBER);
	seg_1.setColorDef(F_LED_DEF);
	seg_1.setColorOn(F_LED_ON);
	seg_2.setColorDef(F_LED_DEF);
	seg_2.setColorOn(F_LED_ON);
	seg_3.setColorDef(F_LED_DEF);
	seg_3.setColorOn(F_LED_ON);
	seg_4.setColorDef(F_LED_DEF);
	seg_4.setColorOn(F_LED_ON);
	seg_5.setColorDef(F_LED_DEF);
	seg_5.setColorOn(F_LED_ON);
	seg_6.setColorDef(F_LED_DEF);
	seg_6.setColorOn(F_LED_ON);
	seg_7.setColorDef(F_LED_DEF);
	seg_7.setColorOn(F_LED_ON);
	seg_8.setColorDef(F_LED_DEF);
	seg_8.setColorOn(F_LED_ON);
	seg_9.setColorDef(F_LED_DEF);
	seg_9.setColorOn(F_LED_ON);


	//-------------------------------------------------------------------------
	// Grundeinstellungen LED Stripes
	//-------------------------------------------------------------------------
	seg_1.showRange(F_LED_DEF);
	seg_2.showRange(F_LED_DEF);
	seg_3.showRange(F_LED_DEF);
	seg_4.showRange(F_LED_DEF);
	seg_5.showRange(F_LED_DEF);
	seg_6.showRange(F_LED_DEF);
	seg_7.showRange(F_LED_DEF);
	seg_8.showRange(F_LED_DEF);
	seg_9.showRange(F_LED_DEF);

	seg_1.setRunToggleOn();
	seg_2.setRunToggleOn();
	seg_3.setRunToggleOn();
	seg_4.setRunToggleOn();
	seg_5.setRunToggleOn();
	seg_6.setRunToggleOn();
	seg_7.setRunToggleOn();
	seg_8.setRunToggleOn();
	seg_9.setRunToggleOn();

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
			seg_1.stepUp();
			seg_2.stepUp();
			seg_3.stepUp();
			seg_4.stepUp();
			seg_5.stepUp();
			seg_6.stepUp();
			seg_7.stepUp();
			seg_8.stepUp();
			seg_9.stepUp();
			ddb_refresh = true;
		}
 	}
	//---------------------------------------------------------------------------
	// User Funktionen
	//---------------------------------------------------------------------------
	if(sequence_timer.onRestart()) {
		if(animation_state > 0) {
			animation_state++;
			animation_seq();
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
			animation_seq();
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
