/*
 * Timer0_Register.h
 *
 * Created: 4/1/2023 10:09:57 PM
 *  Author: Mahmoud Emad
 */ 


#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_

#define TCCR0_ITI *((volatile u8*)0x53)
#define TCNT0_ITI *((volatile u8*)0x52)
#define OCR0_ITI  *((volatile u8*)0x5c)
#define TIMSK_ITI *((volatile u8*)0x59)
#define TIFR_ITI  *((volatile u8*)0x58)




#endif /* TIMER0_REGISTER_H_ */