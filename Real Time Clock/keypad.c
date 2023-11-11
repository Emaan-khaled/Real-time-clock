/*
 * keypad.c
 *
 * Created: 10/20/2023 6:08:26 PM
 *  Author: eman
 */ 
#include "keypad.h"
void keypad_int (char port)
{
	DIO_set_port_direction (port, 0x0f);
	DIO_pullup (port, 4,1);
	DIO_pullup (port, 5,1);
	DIO_pullup (port, 6,1);
	DIO_pullup (port, 7,1);
}

char keypad_press (char port)
{
	char keypad_value [4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
		char x,return_value=NOTPRESSED,row,column;
		for(row=0;row<4;row++)
		{
			DIO_write_pin (port,0,1);
			DIO_write_pin (port,1,1);
			DIO_write_pin (port,2,1);
			DIO_write_pin (port,3,1);
			DIO_write_pin (port,row,0);
			
		     	for(column=0;column<4;column++)
			    {
					x=DIO_read_pin (port,column+4);
					if (x==0)
					{
						return_value=keypad_value [row][column];
						break;
					}
				
			    }
				if (x==0)
				{
					break;
				}
		}
		return return_value;
	}		