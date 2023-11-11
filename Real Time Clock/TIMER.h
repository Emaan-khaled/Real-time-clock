/*
 * TIMER.h
 *
 * Created: 10/25/2023 1:22:52 PM
 *  Author: eman
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#define normal 0
#define PWM 1
#define CTC 2
#define FAST_PWM 3
#define non_inverting 1
#define inverting 0
#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"
void TIMER_int (char mode, int prescaller, char MAX);
void Timer_wave_fast_PWM (char MAX, int prescaller , char mode);
void Timer_wave_phasecorrect_PWM (char MAX, int prescaller, char mode );
void Timer2_OVF_int (void);


#endif /* TIMER_H_ */