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

void choose_arm(int arm) {

}

/******************************************************************************/
/****************************** Init Position *********************************/
/******************************************************************************/

void init_arm(int arm) {

    PutAX(S1, AX_TORQUE_LIMIT, 650);
    __delay_ms(40);
    PutAX(S2, AX_TORQUE_LIMIT, 650);
    __delay_ms(40);
    PutAX(S3, AX_TORQUE_LIMIT, 650);
    __delay_ms(40);

    PutAX(S1, AX_MOVING_SPEED, 650);
    __delay_ms(40);
    PutAX(S2, AX_MOVING_SPEED, 650);
    __delay_ms(40);
    PutAX(S3, AX_MOVING_SPEED, 650);
    __delay_ms(40);

    PutAX(S1, AX_GOAL_POSITION, 512);
    __delay_ms(100);
    PutAX(S2, AX_GOAL_POSITION, 205);
    __delay_ms(100);
    PutAX(S3, AX_GOAL_POSITION, 205);
    __delay_ms(500);

}

void charg_gobelet(void)
{
    PutAX(S1, AX_TORQUE_LIMIT, 650);
    __delay_ms(40);
    PutAX(S2, AX_TORQUE_LIMIT, 650);
    __delay_ms(40);
    PutAX(S3, AX_TORQUE_LIMIT, 650);
    __delay_ms(40);
    PutAX(S4, AX_TORQUE_LIMIT, 650);
    __delay_ms(40);

    PutAX(S1, AX_MOVING_SPEED, 650);
    __delay_ms(40);
    PutAX(S2, AX_MOVING_SPEED, 650);
    __delay_ms(40);
    PutAX(S3, AX_MOVING_SPEED, 650);
    __delay_ms(40);
    PutAX(S4, AX_MOVING_SPEED, 650);
    __delay_ms(40);

    PutAX(S1,AX_GOAL_POSITION,00); //rabat la piece
    __delay_ms(100);
    PutAX(S1,AX_GOAL_POSITION,00); //reouvre
    __delay_ms(100);
    PutAX(S2,AX_GOAL_POSITION,00); //ouvre la pince
    __delay_ms(100);
    PutAX(S3,AX_GOAL_POSITION,00); //descent la pince
    __delay_ms(100);
    PutAX(S2,AX_GOAL_POSITION,00); //referme la pince
    __delay_ms(100);
    PutAX(S3,AX_GOAL_POSITION,00); //remonte a moitié la piece et bloque
    __delay_ms(100);
    PutAX(S4,AX_GOAL_POSITION,00); //reouvre legerement le porte gobelet
    __delay_ms(100);
    PutAX(S3,AX_GOAL_POSITION,00); //remonte la pince a max
    __delay_ms(100);
    PutAX(S4,AX_GOAL_POSITION,00); //referme le porte gob
    __delay_ms(100);
    PutAX(S2,AX_GOAL_POSITION,00); // reouvre la pince
    __delay_ms(100);
    PutAX(S3,AX_GOAL_POSITION,00); // la redescent a mi hauteur
    __delay_ms(100);


}

/******************************************************************************/


