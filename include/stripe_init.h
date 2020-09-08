//##################################################################
//### Stripe Define                                              ###
//##################################################################

#ifndef STRIPE_INIT_H
#define STRIPE_INIT_H
#endif

// LED Anordnung
#ifndef DEBUG_LED

#define STRIPE_HOR_NUM      58
#define STRIPE_VER_NUM      32

// 24 x Horizontale Stripes
// Flugbahnen des Weltraumschrott
// 1. DDB-Modul 
#define STRIPE_01_DDB       0
#define STRIPE_01_START     0
#define STRIPE_01_NUM       STRIPE_HOR_NUM  

#define STRIPE_02_DDB       0
#define STRIPE_02_START     STRIPE_01_NUM
#define STRIPE_02_NUM       STRIPE_HOR_NUM

#define STRIPE_03_DDB       0
#define STRIPE_03_START     ( STRIPE_01_NUM + STRIPE_02_NUM )
#define STRIPE_03_NUM       STRIPE_HOR_NUM          

#define STRIPE_04_DDB       0
#define STRIPE_04_START     ( STRIPE_01_NUM + STRIPE_02_NUM + STRIPE_03_NUM )
#define STRIPE_04_NUM       STRIPE_HOR_NUM          

// 2. DDB-Modul
#define STRIPE_05_DDB       1
#define STRIPE_05_START     0
#define STRIPE_05_NUM       STRIPE_HOR_NUM          

#define STRIPE_06_DDB       1
#define STRIPE_06_START     ( STRIPE_05_NUM )
#define STRIPE_06_NUM       STRIPE_HOR_NUM          

#define STRIPE_07_DDB       1
#define STRIPE_07_START     ( STRIPE_05_NUM + STRIPE_06_NUM )
#define STRIPE_07_NUM       STRIPE_HOR_NUM          

#define STRIPE_08_DDB       1
#define STRIPE_08_START     ( STRIPE_05_NUM + STRIPE_06_NUM + STRIPE_07_NUM )
#define STRIPE_08_NUM       STRIPE_HOR_NUM          

// 3. DDB-Modul
#define STRIPE_09_DDB       2
#define STRIPE_09_START     0
#define STRIPE_09_NUM       STRIPE_HOR_NUM

#define STRIPE_10_DDB       2
#define STRIPE_10_START     ( STRIPE_10_NUM )
#define STRIPE_10_NUM       STRIPE_HOR_NUM          

#define STRIPE_11_DDB       2
#define STRIPE_11_START     ( STRIPE_10_NUM + STRIPE_11_NUM )
#define STRIPE_11_NUM       STRIPE_HOR_NUM          

#define STRIPE_12_DDB       2
#define STRIPE_12_START     ( STRIPE_10_NUM + STRIPE_11_NUM + STRIPE_12_NUM )
#define STRIPE_12_NUM       STRIPE_HOR_NUM          

// 4. DDB-Modul
#define STRIPE_13_DDB       3
#define STRIPE_13_START     0
#define STRIPE_13_NUM       STRIPE_HOR_NUM

#define STRIPE_14_DDB       3
#define STRIPE_14_START     ( STRIPE_13_NUM )
#define STRIPE_14_NUM       STRIPE_HOR_NUM          

#define STRIPE_15_DDB       3
#define STRIPE_15_START     ( STRIPE_13_NUM + STRIPE_14_NUM )
#define STRIPE_15_NUM       STRIPE_HOR_NUM          

#define STRIPE_16_DDB       3
#define STRIPE_16_START     ( STRIPE_13_NUM + STRIPE_14_NUM + STRIPE_15_NUM )
#define STRIPE_16_NUM       STRIPE_HOR_NUM          

// 5. DDB-Modul
#define STRIPE_17_DDB       4
#define STRIPE_17_START     0
#define STRIPE_17_NUM       STRIPE_HOR_NUM

#define STRIPE_18_DDB       4
#define STRIPE_18_START     ( STRIPE_17_NUM )
#define STRIPE_18_NUM       STRIPE_HOR_NUM          

#define STRIPE_19_DDB       4
#define STRIPE_19_START     ( STRIPE_17_NUM + STRIPE_18_NUM )
#define STRIPE_19_NUM       STRIPE_HOR_NUM          

#define STRIPE_20_DDB       4
#define STRIPE_20_START     ( STRIPE_17_NUM + STRIPE_18_NUM + STRIPE_19_NUM )
#define STRIPE_20_NUM       STRIPE_HOR_NUM       

// 6. DDB-Modul
#define STRIPE_21_DDB       5
#define STRIPE_21_START     0
#define STRIPE_21_NUM       STRIPE_HOR_NUM

#define STRIPE_22_DDB       5
#define STRIPE_22_START     ( STRIPE_21_NUM )
#define STRIPE_22_NUM       STRIPE_HOR_NUM          

#define STRIPE_23_DDB       5
#define STRIPE_23_START     ( STRIPE_21_NUM + STRIPE_22_NUM )
#define STRIPE_23_NUM       STRIPE_HOR_NUM          

#define STRIPE_24_DDB       5
#define STRIPE_24_START     ( STRIPE_21_NUM + STRIPE_22_NUM + STRIPE_23_NUM )
#define STRIPE_24_NUM       STRIPE_HOR_NUM       

// 4 x Vertikale Stripes
// Raderstrahlen
// 7. DDB-Modul
#define STRIPE_25_DDB       6
#define STRIPE_25_START     0
#define STRIPE_25_NUM       STRIPE_VER_NUM

#define STRIPE_26_DDB       6
#define STRIPE_26_START     ( STRIPE_25_NUM )
#define STRIPE_26_NUM       STRIPE_VER_NUM          

#define STRIPE_27_DDB       6
#define STRIPE_27_START     ( STRIPE_25_NUM + STRIPE_26_NUM )
#define STRIPE_27_NUM       STRIPE_VER_NUM          

#define STRIPE_28_DDB       6
#define STRIPE_28_START     ( STRIPE_25_NUM + STRIPE_26_NUM + STRIPE_27_NUM )
#define STRIPE_28_NUM       STRIPE_VER_NUM       





#else

// Debug Aufbau
#define STRIPE_1_DDB        0
#define STRIPE_1_START      0
#define STRIPE_1_NUMBER     8           // Test

#define STRIPE_2_DDB        0
#define STRIPE_2_START      STRIPE_1_NUMBER
#define STRIPE_2_NUMBER     8           // Test

#define STRIPE_3_DDB        1
#define STRIPE_3_START      0
#define STRIPE_3_NUMBER     3           // Test

#define STRIPE_4_DDB        1
#define STRIPE_4_START      STRIPE_3_NUMBER
#define STRIPE_4_NUMBER     3           // Test

#define STRIPE_5_DDB        1
#define STRIPE_5_START      ( STRIPE_4_START + STRIPE_4_NUMBER )
#define STRIPE_5_NUMBER     3           // Test

#define STRIPE_6_DDB        1
#define STRIPE_6_START      ( STRIPE_5_START + STRIPE_5_NUMBER )
#define STRIPE_6_NUMBER     3           // Test 

#define STRIPE_7_DDB        1
#define STRIPE_7_START      ( STRIPE_6_START + STRIPE_6_NUMBER )
#define STRIPE_7_NUMBER     3           // Test

#define STRIPE_8_DDB        1
#define STRIPE_8_START      ( STRIPE_7_START + STRIPE_7_NUMBER )
#define STRIPE_8_NUMBER     3           // Test

#define STRIPE_9_DDB        1
#define STRIPE_9_START      ( STRIPE_8_START + STRIPE_8_NUMBER )
#define STRIPE_9_NUMBER     3           // Test

#endif
