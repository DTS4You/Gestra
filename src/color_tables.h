#include "Arduino.h"

// Farbtabelle -> Index -> R / G / B
const uint8_t color_[11][3] = {
		{   0 ,   0,    0 },		//  0. Farbe	Schwarz -> Aus
		{ 250 ,   0 ,   0 },		//  1. Farbe	Rot		90 %
		{   0 , 220 ,   0 },		//  2. Farbe	Grün	90 %
		{   0 ,   0 , 220 },		//  3. Farbe	Blau	90 %
		{   0 ,   0 , 120 },		//  4. Farbe	Blau 	50 %
		{   0 ,   0 ,   3 },		//  5. Farbe	Blau	-> Default
		{   0 ,   0 ,  20 },		//  6. Farbe	Blau
		{ 160 ,  10 ,  60 },		//  7. Farbe	Magenta
		{   0 , 220 ,   0 },		//  8. Farbe	Grün 100%
		{ 220 ,   0 ,   0 },		//  9. Farbe	Rot  100%
		{ 220 , 220 , 220 }			// 10. Farbe	Weiß 70%
};

