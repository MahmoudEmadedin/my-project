/*
 * DIO_Register.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Mahmoud Emad
 */

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

				  
#define DDRA_ITI  *((volatile u8*)0x3A)
#define DDRB_ITI  *((volatile u8*)0x37)
#define DDRC_ITI  *((volatile u8*)0x34)
#define DDRD_ITI  *((volatile u8*)0x31)
				 
				  
#define PORTA_ITI *((volatile u8*)0x3B)
#define PORTB_ITI *((volatile u8*)0x38)
#define PORTC_ITI *((volatile u8*)0x35)
#define PORTD_ITI *((volatile u8*)0x32)
				  
				  
 #define PINA_ITI *((volatile u8*)0x39)
 #define PINB_ITI *((volatile u8*)0x36)
 #define PINC_ITI *((volatile u8*)0x33)
 #define PIND_ITI *((volatile u8*)0x30)


#endif /* DIO_REGISTER_H_ */
