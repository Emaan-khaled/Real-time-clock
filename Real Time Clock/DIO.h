/*
 * DIO.h
 *
 * Created: 10/5/2023 1:22:09 PM
 *  Author: eman
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_set_pin_direction (char port, char pin, char direction);
void DIO_write_pin (char port, char pin, char outputvalue);
void DIO_toggle_pin (char port, char pin);
char DIO_read_pin (char port, char pin);
void DIO_set_port_direction (char port,char direction);
char DIO_read_port (char port, char pin);
void DIO_write_port(char port,char outputvalue);
void write_low_nibble(char portname, char value);
void write_high_nibble( char portname, char value);
void DIO_pullup (char portname ,char pinnumber, char pullup);




#endif /* DIO_H_ */