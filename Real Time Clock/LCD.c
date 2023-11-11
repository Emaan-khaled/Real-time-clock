/*
 * LCD.c
 *
 * Created: 10/20/2023 3:07:29 PM
 *  Author: eman
 */ 
#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

void LCD_int (char Data_port)
{
	_delay_ms(200);
	#if defined eight_bits_mode
	DIO_set_port_direction (Data_port,0xff);
	DIO_set_pin_direction (RS_port,RS_pin ,1);
	DIO_set_pin_direction(RW_port,RW_pin,1);
	DIO_set_pin_direction (EN_port,EN_pin,1);
	DIO_write_pin(RW_port,RW_pin,0);
	LCD_send_command(Data_port,EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_send_command(Data_port,CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_send_command(Data_port,CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_send_command(Data_port,ENTRY_MODE); //entry mode
	_delay_ms(1);
	#elif defined four_bits_mode
	DIO_set_pin_direction(Data_port,4,1);
	DIO_set_pin_direction(Data_port,5,1);
	DIO_set_pin_direction(Data_port,6,1);
	DIO_set_pin_direction(Data_port,7,1);
	DIO_set_pin_direction(EN_port,EN_pin,1);
	DIO_set_pin_direction(RW_port,RW_pin,1);
	DIO_set_pin_direction(RS_port,RS_pin,1);
	DIO_write_pin(RW_port,RW_pin,0);
	LCD_send_command(Data_port,RETURN_HOME); //return home
	_delay_ms(10);
	LCD_send_command(Data_port,FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_send_command(Data_port,CURSOR_ON_DISPLAN_ON);//display on cursor on
	_delay_ms(1);
	LCD_send_command(Data_port,CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_send_command(Data_port,ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}


void LCD_send_char (char Data_port, char data)
{
	#if defined eight_bits_mode
	DIO_write_port (Data_port,data);
	DIO_write_pin (RS_port ,RS_pin ,1);
	enable ();
	#elif defined four_bits_mode
	write_high_nibble(Data_port,data>>4);
	DIO_write_pin (RS_port ,RS_pin ,1);
	enable ();
	write_high_nibble(Data_port,data);
	DIO_write_pin (RS_port ,RS_pin ,1);
	enable ();
	_delay_ms(1);
	#endif
	
}

static void enable (void)
{
	DIO_write_pin (EN_port ,EN_pin ,1);
	_delay_ms (2);
	DIO_write_pin (EN_port ,EN_pin ,0);
	_delay_ms (2);
}

void LCD_send_command (char Data_port, char command)
{
	#if defined eight_bits_mode
	DIO_write_port (Data_port,command);
	DIO_write_pin (RS_port ,RS_pin ,0);
	enable ();
	#elif defined four_bits_mode
	write_high_nibble(Data_port,command>>4);
	DIO_write_pin (RS_port ,RS_pin ,0);
	enable ();
	write_high_nibble(Data_port,command);
	DIO_write_pin (RS_port ,RS_pin ,0);
	enable ();
	_delay_ms(1);
	#endif
	
}

void LCD_send_string (char Data_port, char *ptr)
{
	while (*ptr!=0)
	{
		LCD_send_char ( Data_port, *ptr);
		*ptr++;
	}
}

void LCD_move_coursor (char Data_port, char row, char column)
{
	char data;
	if (row==1 || row ==2)
	{
		if (row==1)
		data= 0x80+column-1;
		else
		data= 0xc0+column-1;
	}
	else
	data= 0x80;
	
	LCD_send_command(Data_port,data);
	_delay_ms(1);
}