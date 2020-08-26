//##################################################################
//### Stripe Define                                              ###
//##################################################################

#ifndef STRIPE_INIT_H
#define STRIPE_INIT_H
#endif

// LED Anordnung
#ifndef DEBUG_LED

#define STRIPE_HOR_NUM      64
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
#define STRIPE_09_DDB       1
#define STRIPE_09_START     0
#define STRIPE_09_NUM       STRIPE_HOR_NUM

#define STRIPE_10_DDB       1
#define STRIPE_10_START     ( STRIPE_10_NUM )
#define STRIPE_10_NUM       STRIPE_HOR_NUM          

#define STRIPE_11_DDB       1
#define STRIPE_11_START     ( STRIPE_10_NUM + STRIPE_11_NUM )
#define STRIPE_11_NUM       STRIPE_HOR_NUM          

#define STRIPE_12_DDB       1
#define STRIPE_12_START     ( STRIPE_10_NUM + STRIPE_11_NUM + STRIPE_12_NUM )
#define STRIPE_12_NUM       STRIPE_HOR_NUM          










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
