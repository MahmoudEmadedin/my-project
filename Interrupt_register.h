/*
 * Interrupt_register.h
 *
 * Created: 4/14/2023 4:32:56 PM
 *  Author: Mahmoud Emad
 */ 


#ifndef Interrupt_register_H_
#define Interrupt_register_H_

#define SREG_ITI *((volatile u8*)0x5f)
#define GlobalInterrupt 7

#define EnableGlobalInterrupt() SREG_ITI|=(1<<GlobalInterrupt)



#endif /* Interrupt_register_H_ */