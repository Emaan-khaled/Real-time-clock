/*
 * TIMER.c
 *
 * Created: 10/25/2023 1:22:38 PM
 *  Author: eman
 */ 
#include "TIMER.h"

void TIMER_int (char mode, int prescaller, char MAX)
{
	switch(mode)
	{
		case normal:
		CLR_BIT (TCCR0,WGM00);
		break;
		
		case PWM:
		SET_BIT (TCCR0,WGM00);
		break;
		
		case CTC:
		SET_BIT (TCCR0,WGM01);
		OCR0=MAX;
		break;
		
		case FAST_PWM:
		SET_BIT (TCCR0,WGM01);
		SET_BIT (TCCR0,WGM00);
		break;
		
	}
	
	switch(prescaller)
	{
		case 8:
		SET_BIT (TCCR0,CS01);
		break;
		
		case 64:
		SET_BIT (TCCR0,CS01);
		SET_BIT (TCCR0,CS00);
		break;
		
		case 256:
		SET_BIT (TCCR0,CS02);
		break;
		
		case 1024:
		SET_BIT (TCCR0,CS02);
		SET_BIT (TCCR0,CS00);
		break;
		
	}
	
	sei();
	SET_BIT(TIMSK,OCIE0);
}


void Timer_wave_fast_PWM (char MAX, int prescaller, char mode )
{
	SET_BIT (DDRB,3);
	SET_BIT (TCCR0,WGM01);
	SET_BIT (TCCR0,WGM00);
	OCR0=MAX;
		switch(prescaller)
		{
			case 8:
			SET_BIT (TCCR0,CS01);
			break;
			
			case 64:
			SET_BIT (TCCR0,CS01);
			SET_BIT (TCCR0,CS00);
			break;
			
			case 256:
			SET_BIT (TCCR0,CS02);
			break;
			
			case 1024:
			SET_BIT (TCCR0,CS02);
			SET_BIT (TCCR0,CS00);
			break;
			
		}
		
		switch(mode)
		{
			case inverting:
			SET_BIT (TCCR0,COM00);
			SET_BIT (TCCR0,COM01);
			break;
			
			case non_inverting:
			SET_BIT (TCCR0,COM01);
			break;
		}			
	
}

void Timer_wave_phasecorrect_PWM (char MAX, int prescaller, char mode )
{
	SET_BIT (DDRB,3);
	SET_BIT (TCCR0,WGM00);
	OCR0=MAX;
	switch(prescaller)
	{
		case 8:
		SET_BIT (TCCR0,CS01);
		break;
		
		case 64:
		SET_BIT (TCCR0,CS01);
		SET_BIT (TCCR0,CS00);
		break;
		
		case 256:
		SET_BIT (TCCR0,CS02);
		break;
		
		case 1024:
		SET_BIT (TCCR0,CS02);
		SET_BIT (TCCR0,CS00);
		break;
		
	}
	
	switch(mode)
	{
		case inverting:
		SET_BIT (TCCR0,COM00);
		SET_BIT (TCCR0,COM01);
		break;
		
		case non_inverting:
		SET_BIT (TCCR0,COM01);
		break;
	}
	
}

void Timer2_OVF_int (void)
{
	SET_BIT (ASSR,AS2);
	
	SET_BIT (TCCR2,CS22);
	SET_BIT (TCCR2,CS20);
	
	sei();
	SET_BIT(TIMSK,TOIE2);
	
	
}