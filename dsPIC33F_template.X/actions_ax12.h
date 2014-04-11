/* 
 * File:   actions_ax12.h
 * Author: zoltarius
 *
 * Created on 4 avril 2014, 18:41
 */

#ifndef ACTIONS_AX12_H
#define	ACTIONS_AX12_H

int S1;
int S2;
int S3;

#define SD1             4
#define SD2             13
#define SD3             17

#define SG1             12
#define SG2             42
#define SG3             2

void choose_arm(int);
void init_bras(int);
void catch_bras(int);
void stock_bras(int);
void face1(int);
void face2(int);
#endif	/* ACTIONS_AX12_H */

