#include <p33Fxxxx.h>      /* Includes device header file                     */
#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "header.h"        /* Function / Parameters                           */
#include <libpic30.h>
#include "ax12.h"
#include <uart.h>
#include <delay.h>
#include "actions_ax12.h"

void init_bras(int a) {
    int t1 = 100;
    int t2 = 500;
    PutAX(AX_BROADCAST, AX_TORQUE_LIMIT, 500);
    __delay_ms(t2);
   int S1;
        int S2;
        int S3;




    if (a == 1) {

        int S1 = SD1;
        int S2 = SD2;
        int S3 = SD3;
    }

    else if (a == 2) {
        S1 = SG1;
        S2 = SG2;
        S3 = SG3;
    }




    switch (a) {
        case 2:
            PutAX(S1, AX_GOAL_POSITION, 358);
            __delay_ms(t1);
            PutAX(S2, AX_GOAL_POSITION, 205);
            __delay_ms(t1);
            PutAX(S3, AX_GOAL_POSITION, 205);
            __delay_ms(t2);

            break;
        case 1:

            PutAX(4, AX_GOAL_POSITION, 358);
            __delay_ms(t1);
            PutAX(13, AX_GOAL_POSITION, 205);
            __delay_ms(t1);
            PutAX(17, AX_GOAL_POSITION, 205);
            __delay_ms(t2);
            break;
    }

    PutAX(AX_BROADCAST, AX_TORQUE_LIMIT, 300);
}

void catch_bras(int b) {


    int t1 = 200;
    int t2 = 500;
    int t3 = 25;

    switch (b) {
        case 1:

            PutAX(4, AX_GOAL_POSITION, 358);
            __delay_ms(t1);
            PutAX(13, AX_GOAL_POSITION, 205);
            __delay_ms(t1);
            PutAX(17, AX_GOAL_POSITION, 205);
            __delay_ms(t2);
            break;



        case 2:


            PutAX(SG3, AX_TORQUE_LIMIT, 512);
            __delay_ms(t3);
            PutAX(SG1, AX_TORQUE_LIMIT, 512);
            __delay_ms(t3);
            PutAX(SG2, AX_TORQUE_LIMIT, 512);
            __delay_ms(t3);


            PutAX(SG3, AX_MOVING_SPEED, 650);
            __delay_ms(t3);
            PutAX(SG1, AX_MOVING_SPEED, 650);
            __delay_ms(t3);
            PutAX(SG2, AX_MOVING_SPEED, 650);
            __delay_ms(t3);



            PutAX(SG3, AX_GOAL_POSITION, 512);
            __delay_ms(t1);
            PutAX(SG1, AX_GOAL_POSITION, 512);
            __delay_ms(t1);


            PutAX(SG2, AX_GOAL_POSITION, 358);
            __delay_ms(10);
            PutAX(SG1, AX_GOAL_POSITION, 666);
            __delay_ms(t1);



            PutAX(SG3, AX_GOAL_POSITION, 220);
            __delay_ms(1000);
            PutAX(SG1, AX_GOAL_POSITION, 690);
            __delay_ms(t1);
            PutAX(SG3, AX_TORQUE_LIMIT, 250);
            __delay_ms(t3);
            PutAX(SG3, AX_GOAL_POSITION, 150);
            __delay_ms(500);
            break;

    }


}

void stock_bras(int a)
 {
    int t1 = 200;
    int t2 = 500;
    int t3 = 25;

    switch (a) {
        case 1:
            break;
        case 2:
            PutAX(SG3, AX_TORQUE_LIMIT, 250);
            __delay_ms(t3);
            PutAX(SG1, AX_TORQUE_LIMIT, 512);
            __delay_ms(t3);
            PutAX(SG2, AX_TORQUE_LIMIT, 512);
            __delay_ms(t3);


            PutAX(2, AX_MOVING_SPEED, 512);
            __delay_ms(t3);
            PutAX(SG1, AX_MOVING_SPEED, 512);
            __delay_ms(t3);
            PutAX(SG2, AX_MOVING_SPEED, 512);
            __delay_ms(t3);



            PutAX(SG1, AX_GOAL_POSITION, 512);
            __delay_ms(t1);
            PutAX(SG2, AX_GOAL_POSITION, 205);
            __delay_ms(t1);
            PutAX(SG3, AX_GOAL_POSITION, 150);
            __delay_ms(t2);


            break;

    }
}

void face1(int a) {
    int t1 = 200;
    int t2 = 500;
    int t3 = 25;
    switch (a) {
        case 1:


            break;
        case 2:

            PutAX(SG1, AX_GOAL_POSITION, 358);
            __delay_ms(t1);
            PutAX(SG1, AX_GOAL_POSITION, 780);
            __delay_ms(10);
            PutAX(SG2, AX_GOAL_POSITION, 666);
            __delay_ms(t1);
            PutAX(SG3, AX_GOAL_POSITION, 512);
            __delay_ms(1500);
            PutAX(SG1, AX_GOAL_POSITION, 512);
            __delay_ms(t1);
            PutAX(SG2, AX_GOAL_POSITION, 205);
            __delay_ms(t1);
            break;

    }
}

