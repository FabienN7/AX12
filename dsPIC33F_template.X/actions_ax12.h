/* 
 * File:   actions_ax12.h
 * Author: zoltarius
 *
 * Created on 4 avril 2014, 18:41
 */

#ifndef ACTIONS_AX12_H
#define	ACTIONS_AX12_H



#define S1             1  // le rabateur
#define S2             2  // la pince
#define S3             3  // l'ascenceur
#define S4             4  // le porte gobelet

void choose_arm(int);
void init_arm(int);
void charg_gobelet(void);

#endif	/* ACTIONS_AX12_H */

