/*
 * LED.h
 *
 * Created: 10/5/2023 5:55:09 PM
 *  Author: eman
 */ 


#ifndef LED_H_
#define LED_H_

void led_int(char port,char pin);
void led_on(char port, char pin);
void led_off(char port, char pin);
void led_tog(char port, char pin);



#endif /* LED_H_ */