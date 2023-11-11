/*
 * seven_segmant.c
 *
 * Created: 10/7/2023 4:17:22 PM
 *  Author: eman
 */ 
#include "DIO.h"
void seven_segmant_int (char port)
{
	DIO_set_port_direction (port,0xFF);
}

void seven_segmant_write (char port, char counter)
{
	char array[] = {0x3f, 0x06, 0x5b, 0x4f,0x66, 0x6d, 0x7d,0x47, 0x7f, 0x6f};
	DIO_write_port (port,array[counter]);
}