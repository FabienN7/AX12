#include <p33Fxxxx.h>      /* Includes device header file                     */
#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "header.h"        /* Function / Parameters                           */
#include <libpic30.h>
#include "ax12.h"
#include <uart.h>
#include <delay.h>
#include "actions_ax12.h"

/******************************************************************************/
/*************************** Arm Specification ********************************/
/******************************************************************************/

void choose_arm(int arm)
{
    if (arm == 1) {
        S1 = SD1;
        S2 = SD2;
        S3 = SD3;
    } else if (arm == 2) {
        S1 = SG1;
        S2 = SG2;
        S3 = SG3;
    }
}


/******************************************************************************/
/****************************** Init Position *********************************/
/******************************************************************************/
void init_bras(int arm) {

    choose_arm(arm);

    PutAX(AX_BROADCAST, AX_TORQUE_LIMIT, 600);
    __delay_ms(100);


    PutAX(S1, AX_GOAL_POSITION, 512);
    __delay_ms(100);
    PutAX(S2, AX_GOAL_POSITION, 205);
    __delay_ms(100);
    PutAX(S3, AX_GOAL_POSITION, 205);
    __delay_ms(500);


    PutAX(AX_BROADCAST, AX_TORQUE_LIMIT, 300);
}

/******************************************************************************/
/******************************* Catch a Fire *********************************/
/******************************************************************************/

void catch_bras(int arm) {

    choose_arm(arm);


    PutAX(S3, AX_TORQUE_LIMIT, 600);
    __delay_ms(25);
    PutAX(S1, AX_TORQUE_LIMIT, 600);
    __delay_ms(25);
    PutAX(S2, AX_TORQUE_LIMIT, 600);
    __delay_ms(25);


    PutAX(S3, AX_MOVING_SPEED, 650);
    __delay_ms(25);
    PutAX(S1, AX_MOVING_SPEED, 650);
    __delay_ms(25);
    PutAX(S2, AX_MOVING_SPEED, 650);
    __delay_ms(25);


    PutAX(S3, AX_GOAL_POSITION, 512);
    __delay_ms(500);

    PutAX(S2, AX_GOAL_POSITION, 358);
    __delay_ms(100);
    PutAX(S1, AX_GOAL_POSITION, 666);
    __delay_ms(100);


    PutAX(S3, AX_GOAL_POSITION, 210);
    __delay_ms(100);
    PutAX(S3, AX_TORQUE_LIMIT, 250);
    __delay_ms(25);
    PutAX(S3, AX_GOAL_POSITION, 180);
    __delay_ms(1000);

}
/******************************************************************************/
/********************************* Stock a Fire *******************************/
/******************************************************************************/

void stock_bras(int arm) {

    choose_arm(arm);

            PutAX(S3, AX_TORQUE_LIMIT, 250);
            __delay_ms(50);
            PutAX(S1, AX_TORQUE_LIMIT, 600);
            __delay_ms(50);
            PutAX(S2, AX_TORQUE_LIMIT, 600);
            __delay_ms(50);


            PutAX(S3, AX_MOVING_SPEED, 650);
            __delay_ms(50);
            PutAX(S1, AX_MOVING_SPEED, 650);
            __delay_ms(50);
            PutAX(S2, AX_MOVING_SPEED, 650);
            __delay_ms(50);



            PutAX(S1, AX_GOAL_POSITION, 512);
            __delay_ms(100);
            PutAX(S2, AX_GOAL_POSITION, 300);
            __delay_ms(100);
            PutAX(S3, AX_GOAL_POSITION, 180);
            __delay_ms(100);

            /////////lâcher le bordel////////
            __delay_ms(3000);
            PutAX(S3, AX_TORQUE_LIMIT, 600);
            __delay_ms(50);
            PutAX(S3, AX_GOAL_POSITION, 512);
            __delay_ms(1000);
            /////////////////////////////////

    }

/******************************************************************************/
/************************* Put Fire on the 1st Face ***************************/
/******************************************************************************/

void face1(int arm) {
    int t1 = 200;

    choose_arm(arm);


            PutAX(S1, AX_GOAL_POSITION, 358);
            __delay_ms(t1);
            PutAX(S1, AX_GOAL_POSITION, 780);
            __delay_ms(10);
            PutAX(S2, AX_GOAL_POSITION, 666);
            __delay_ms(t1);
            PutAX(S3, AX_GOAL_POSITION, 512);
            __delay_ms(1500);
            PutAX(S1, AX_GOAL_POSITION, 512);
            __delay_ms(t1);
            PutAX(S2, AX_GOAL_POSITION, 205);
            __delay_ms(t1);

    }


