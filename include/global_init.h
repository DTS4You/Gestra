//##################################################################
//### Global Define                                              ###
//##################################################################
#ifndef GLOBAL_INIT_H
#define GLOBAL_INIT_H


#define EIN             	HIGH
#define AUS             	LOW

// Farbzuweisungen
#define F_LED_ON			1
#define F_LED_DEF			5
#define F_LED_OFF			0
// -> Radar
#define RADAR_LED_ON        2
#define RADAR_LED_COL       9
#define RADAR_LED_DEF       6
#define RADAR_LED_DEF_COL   7
#define RADAR_LED_OFF       0
// -> Track
#define TRACK_LED_ON        1
#define TRACK_LED_DEF       5
#define TRACK_LED_OFF       0

// Timer 
#define IO_LOOP_TIME		50		// in ms
#define BUTTON_BLINK_TIME	300     // in ms
#define ANIMATION_TIME      20      // Radar-Strahl Schrittzeit in ms
#define SEQUENCE_TIME       10000   // Anzeigedauer in ms
#define NEW_PART_DELAY      7000    // Dauer bis ein neues Teil losfligt in ms

// Digi-Dot-Booster
#define DDB_COUNT           8       // Anzahl der DigiDotBooster Module

#define DDB_1_CS_PIN        2       // Chip Select Pin DDB 1
#define DDB_2_CS_PIN        3       // Chip Select Pin DDB 2
#define DDB_3_CS_PIN        4       // Chip Select Pin DDB 3
#define DDB_4_CS_PIN        5       // Chip Select Pin DDB 4
#define DDB_5_CS_PIN        6       // Chip Select Pin DDB 5
#define DDB_6_CS_PIN        7       // Chip Select Pin DDB 6
#define DDB_7_CS_PIN        8       // Chip Select Pin DDB 7
#define DDB_8_CS_PIN        9       // Chip Select Pin DDB 8

#define DDB_1_MAX_LED      240      // Anzahl der LEDs am DDB 1
#define DDB_2_MAX_LED      240      // Anzahl der LEDs am DDB 2
#define DDB_3_MAX_LED      240      // Anzahl der LEDs am DDB 3
#define DDB_4_MAX_LED      240      // Anzahl der LEDs am DDB 4
#define DDB_5_MAX_LED      240      // Anzahl der LEDs am DDB 5
#define DDB_6_MAX_LED      240      // Anzahl der LEDs am DDB 6
#define DDB_7_MAX_LED      200      // Anzahl der LEDs am DDB 7
#define DDB_8_MAX_LED      200      // Anzahl der LEDs am DDB 8

#define DDB_INIT_DELAY		2		// DDB Initialisierungsverzögerung in ms (Min. 2 ms)
#define DDB_CMD_DELAY       2       // DDB Befehlsverzögerung in ms (Min. 2ms)

// Arduino Board LED
#define ARDUINOLED			13    	// Arduino LED on board

// MCP23017 I2C Adresse
#define MCP23017            0x20    // 1. MCP23017 Adresse


#endif
