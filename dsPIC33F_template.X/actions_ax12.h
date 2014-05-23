/* 
 * File:   actions_ax12.h
 * Author: zoltarius
 *
 * Created on 4 avril 2014, 18:41
 */

#ifndef ACTIONS_AX12_H
#define	ACTIONS_AX12_H



#define SD1             18
#define SD2             13
#define SD3             17

#define SG1             18
#define SG2             42
#define SG3             2

void choose_arm(int);
void init_arm(int);
void catch_arm(int);
void stock_arm(int);
void pull_arm(int);
void push_arm(int);
void launch_net(int);
#endif	/* ACTIONS_AX12_H */

