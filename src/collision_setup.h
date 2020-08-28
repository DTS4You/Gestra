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
    track[12].setCollision(TRACK_13_COL_H1, TRACK_13_COL_H2, TRACK_13_COL_V);
    track[13].setCollision(TRACK_14_COL_H1, TRACK_14_COL_H2, TRACK_14_COL_V);
    track[14].setCollision(TRACK_15_COL_H1, TRACK_15_COL_H2, TRACK_15_COL_V);
    track[15].setCollision(TRACK_16_COL_H1, TRACK_16_COL_H2, TRACK_16_COL_V);
    track[16].setCollision(TRACK_17_COL_H1, TRACK_17_COL_H2, TRACK_17_COL_V);
    track[17].setCollision(TRACK_18_COL_H1, TRACK_18_COL_H2, TRACK_18_COL_V);
    track[18].setCollision(TRACK_19_COL_H1, TRACK_19_COL_H2, TRACK_19_COL_V);
    track[19].setCollision(TRACK_20_COL_H1, TRACK_20_COL_H2, TRACK_20_COL_V);
    track[20].setCollision(TRACK_21_COL_H1, TRACK_21_COL_H2, TRACK_21_COL_V);
    track[21].setCollision(TRACK_22_COL_H1, TRACK_22_COL_H2, TRACK_22_COL_V);
    track[22].setCollision(TRACK_23_COL_H1, TRACK_23_COL_H2, TRACK_23_COL_V);
    track[23].setCollision(TRACK_24_COL_H1, TRACK_24_COL_H2, TRACK_24_COL_V);
}

#endif
