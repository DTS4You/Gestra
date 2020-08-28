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
    track[1].setCollision(TRACK_02_COL_H1, TRACK_02_COL_H2, TRACK_02_COL_V);
    track[2].setCollision(TRACK_03_COL_H1, TRACK_03_COL_H2, TRACK_03_COL_V);
    track[3].setCollision(TRACK_04_COL_H1, TRACK_04_COL_H2, TRACK_04_COL_V);
    track[4].setCollision(TRACK_05_COL_H1, TRACK_05_COL_H2, TRACK_05_COL_V);
    track[5].setCollision(TRACK_06_COL_H1, TRACK_06_COL_H2, TRACK_06_COL_V);
    track[6].setCollision(TRACK_07_COL_H1, TRACK_07_COL_H2, TRACK_07_COL_V);
    track[7].setCollision(TRACK_08_COL_H1, TRACK_08_COL_H2, TRACK_08_COL_V);
    track[8].setCollision(TRACK_09_COL_H1, TRACK_09_COL_H2, TRACK_09_COL_V);
    track[9].setCollision(TRACK_10_COL_H1, TRACK_10_COL_H2, TRACK_10_COL_V);
    track[10].setCollision(TRACK_11_COL_H1, TRACK_11_COL_H2, TRACK_11_COL_V);
    track[11].setCollision(TRACK_12_COL_H1, TRACK_12_COL_H2, TRACK_12_COL_V);
}




#endif
