// Kollisionswerte werden initalisiert
#ifndef COLLISION_SETUP_H
#define COLLISION_SETUP_H

#include <Arduino.h>
#include "global_init.h"
#include "stripe_init.h"
#include "collision_value.h"
#include "Ledsegment.h"


extern class Ledsegment track[];
extern class Ledsegment radar[];

void collision_setup() {
    track[0].setCollision(TRACK_01_COL_H1, TRACK_01_COL_H2, TRACK_01_COL_V);
}




#endif
