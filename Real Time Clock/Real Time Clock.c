/*
 * Real_Time_Clock.c
 *
 * Created: 10/26/2023 3:20:17 PM
 *  Author: eman
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "LCD.h"
#include "keypad.h"
#include "TIMER.h"
#include "seven_segmant.h"
#include "std_macros.h"
#define F_CPU 8000000
#include <util/delay.h>

volatile char sec_counter=0;
char min_counter=0;
char hour_counter=0;
char val=NOTPRESSED, first_digit=NOTPRESSED, sec_digit=NOTPRESSED;

int main(void)
{
	seven_segmant_int ('b');
	LCD_int('A');
    keypad_int ('D');
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	
	LCD_send_string ('A',"press 1 to");
	LCD_move_coursor('A',2,1);
	LCD_send_string ('A',"set clock");
	Timer2_OVF_int();
    while(1)
    {
		
		val=keypad_press('D');
		//_delay_ms(200);
		if (val!=NOTPRESSED)
		{
			if (val=='1')
			{
				LCD_send_command('A',0X01);
				LCD_send_string('A',"hours=--");
				LCD_move_coursor('A',1,7);
				_delay_ms(500);
				do 
				{
					first_digit=keypad_press('D');
				} while (first_digit==NOTPRESSED);
				
				LCD_send_char('A',first_digit);
				_delay_ms(300);
				do
				{
				   sec_digit=keypad_press('D');
				} while (sec_digit==NOTPRESSED);
				LCD_send_char('A',sec_digit);
				_delay_ms(300);
				
				hour_counter=(first_digit-48)*10+(sec_digit-48);
				if (hour_counter>=24)
				hour_counter=0;
				////////////////////
				
				LCD_send_command('A',0X01);
				LCD_send_string('A',"minutes=--");
				_delay_ms(500);
				do
				{
					first_digit=keypad_press('D');
				} while (first_digit==NOTPRESSED);
				LCD_move_coursor('A',1,9);
				LCD_send_char('A',first_digit);
				_delay_ms(300);
				do
				{
					sec_digit=keypad_press('D');
				} while (sec_digit==NOTPRESSED);
				LCD_send_char('A',sec_digit);
				_delay_ms(300);
				
				min_counter=(first_digit-48)*10+(sec_digit-48);
				if (min_counter>=60)
				min_counter=0;
				//////////////////////////////
				LCD_send_command('A',0X01);
				LCD_send_string('A',"seconds=--");
				_delay_ms(500);
				do
				{
					first_digit=keypad_press('D');
				} while (first_digit==NOTPRESSED);
				LCD_move_coursor('A',1,9);
				LCD_send_char('A',first_digit);
				_delay_ms(300);
				do
				{
					sec_digit=keypad_press('D');
				} while (sec_digit==NOTPRESSED);
				LCD_send_char('A',sec_digit);
				_delay_ms(300);
				
				sec_counter=(first_digit-48)*10+(sec_digit-48);
				if (sec_counter>=60)
				sec_counter=0;
				
				LCD_send_command('A',0X01);
				LCD_send_string ('A',"press 1 to");
				LCD_move_coursor('A',2,1);
				LCD_send_string ('A',"set clock");
			}
		
		else
		{
			LCD_send_command('A',0X01);
			LCD_move_coursor('A',2,4);
			LCD_send_string('A',"WRONG");
			_delay_ms(300);
			LCD_send_command('A',0X01);
			LCD_send_string ('A',"press 1 to");
			LCD_move_coursor('A',2,1);
			LCD_send_string ('A',"set clock");
			
		}
		
		}
		
        //TODO:: Please write your application code 
		
		CLR_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		seven_segmant_write('B',sec_counter%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		CLR_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		seven_segmant_write('B',sec_counter/10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		CLR_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		seven_segmant_write('B',min_counter%10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		CLR_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		seven_segmant_write('B',min_counter/10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		CLR_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		seven_segmant_write('B',(hour_counter%10));
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		CLR_BIT(PORTC,5);
		seven_segmant_write('B',(hour_counter/10));
		_delay_ms(5);
		
		if (sec_counter==60)
		{
			sec_counter=0;
			min_counter++;
		}
		if (min_counter==60)
		{
			min_counter=0;
			hour_counter++;
		}
		if (hour_counter==24)
		{
			hour_counter=0;
		}
    }
}

ISR (TIMER2_OVF_vect)
{
	sec_counter++;
}