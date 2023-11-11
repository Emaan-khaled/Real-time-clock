/*
 * keypad.h
 *
 * Created: 10/20/2023 6:08:47 PM
 *  Author: eman
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define NOTPRESSED 0xff
#include "DIO.h"
void keypad_int (char port);
char keypad_press (char port);



#endif /* KEYPAD_H_ */