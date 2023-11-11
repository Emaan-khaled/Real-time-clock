/*
 * DIO.c
 *
 * Created: 10/5/2023 1:21:20 PM
 *  Author: eman
 */ 
#include <avr/io.h>
#include "DIO.h"
#include "std_macros.h"

//First function (set direction)

void DIO_set_pin_direction (char port, char pin, char direction)
{
	switch (port)
	{
		case 'A':
		case 'a':
		if (direction ==1)
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			CLR_BIT(DDRA,pin);
		}
		break;
		
		case 'B':
		case 'b':
		if (direction ==1)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLR_BIT(DDRB,pin);
		}
		break;
		
		case 'C':
		case 'c':
		if (direction ==1)
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			CLR_BIT(DDRC,pin);
		}
		break;
		
		case 'D':
		case 'd':
		if (direction ==1)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			CLR_BIT(DDRD,pin);
		}
	}
}

//Second function (Write)

void DIO_write_pin (char port, char pin, char outputvalue)

{
	switch (port)
	{
		case 'A':
		case 'a':
		if (outputvalue ==1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		
		case 'B':
		case 'b':
		if (outputvalue ==1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;
		
		case 'C':
		case 'c':
		if (outputvalue ==1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;
		
		case 'D':
		case 'd':
		if (outputvalue ==1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
	}
}

//Third function (Write)
void DIO_toggle_pin (char port, char pin)
{
	switch (port)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin);
		break;
		
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin);
		break;
		
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin);
		break;
		
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin);
	}
}

char DIO_read_pin (char port, char pin)
{
	char read_value=0;
	switch (port)
	{
		case 'A':
		case 'a':
		read_value=READ_BIT(PINA,pin);
		break;
		
		case 'B':
		case 'b':
		read_value=READ_BIT(PINB,pin);
		break;
		
		case 'C':
		case 'c':
		read_value=READ_BIT(PINC,pin);
		break;
		
		case 'D':
		case 'd':
		read_value=READ_BIT(PIND,pin);
	}
	return read_value;
}

void DIO_set_port_direction (char port,char direction)
{
	switch (port)
	{
		case 'A':
		case 'a':
		DDRA=direction;
		break;
		
		case 'B':
		case 'b':
		DDRB=direction;
		break;
		
		case 'C':
		case 'c':
		DDRC=direction;
		break;
		
		case 'D':
		case 'd':
		DDRD=direction;
	}
	
}

void DIO_write_port(char port,char outputvalue)
{
	switch (port)
	{
		case 'A':
		case 'a':
        PORTA=outputvalue;
		break;
		
		case 'B':
		case 'b':
		PORTB=outputvalue;
		break;
		
		case 'C':
		case 'c':
		PORTC=outputvalue;
		break;
		
		case 'D':
		case 'd':
		PORTD=outputvalue;
	}
	
}

/*char DIO_read_port (char port, char pin)
{
	char read_value=0;
	switch (port)
	{
		case 'A':
		case 'a':
		READ_BIT=PINA;
		break;
		
		case 'B':
		case 'b':
		READ_BIT=PINB;
		break;
		
		case 'C':
		case 'c':
		READ_BIT=PINC;
		break;
		
		case 'D':
		case 'd':
		READ_BIT=PIND;
	}
	return read_value;
}*/

void write_low_nibble( char port,char value)
{
	value&=0x0f;
	switch(port)
	{
		case 'A':
		PORTA&=0xf0;
		PORTA|=value;
		case 'B':
		PORTB&=0xf0;
		PORTB|=value;
		case 'C':
		PORTC&=0xf0;
		PORTC|=value;
		case 'D':
		PORTD&=0xf0;
		PORTD|=value;
	}
}

void write_high_nibble(char port,char value)
{
	value<<=4;
	switch(port)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=value;
		case 'B':
		PORTB&=0x0f;
		PORTB|=value;
		case 'C':
		PORTC&=0x0f;
		PORTC|=value;
		case 'D':
		PORTD&=0x0f;
		PORTD|=value;
	}
}

void DIO_pullup (char portname ,char pinnumber, char pullup)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if(pullup==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		if(pullup==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		case 'c':		
		if(pullup==1)
		{
			SET_BIT(PORTC,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(pullup==1)
		{
			SET_BIT(PORTD,pinnumber);
			
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		
	}
}
