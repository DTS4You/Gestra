//##################################################################
//### Stripe Define                                              ###
//##################################################################

#ifndef STRIPE_INIT_H
#define STRIPE_INIT_H
#endif

// LED Anordnung
#ifndef DEBUG_LED

#define STRIPE_1_DDB        0
#define STRIPE_1_START      0
#define STRIPE_1_NUMBER     64  

#define STRIPE_2_DDB        0
#define STRIPE_2_START      STRIPE_1_NUMBER
#define STRIPE_2_NUMBER     64

#define STRIPE_3_DDB        0
#define STRIPE_3_START      ( STRIPE_1_NUMBER + STRIPE_2_NUMBER )
#define STRIPE_3_NUMBER     64          

#define STRIPE_4_DDB        0
#define STRIPE_4_START      ( STRIPE_1_NUMBER + STRIPE_2_NUMBER + STRIPE_3_NUMBER )
#define STRIPE_4_NUMBER     64          

#define STRIPE_5_DDB        1
#define STRIPE_5_START      ( STRIPE_4_START + STRIPE_4_NUMBER )
#define STRIPE_5_NUMBER     15          

#define STRIPE_6_DDB        1
#define STRIPE_6_START      ( STRIPE_5_START + STRIPE_5_NUMBER )
#define STRIPE_6_NUMBER     15          

#define STRIPE_7_DDB        1
#define STRIPE_7_START      ( STRIPE_6_START + STRIPE_6_NUMBER )
#define STRIPE_7_NUMBER     15          

#define STRIPE_8_DDB        1
#define STRIPE_8_START      ( STRIPE_7_START + STRIPE_7_NUMBER )
#define STRIPE_8_NUMBER     20          

#define STRIPE_9_DDB        1
#define STRIPE_9_START      ( STRIPE_8_START + STRIPE_8_NUMBER )
#define STRIPE_9_NUMBER     20          // 2. Cluster-SAT -> 4. Cluster-SAT diagonal

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
