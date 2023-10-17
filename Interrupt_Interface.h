/*
 * Interrupt_Interface.h
 *
 * Created: 4/14/2023 5:15:16 PM
 *  Author: Mahmoud Emad
 */ 


#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_
void __vector_0 (void) __attribute__ ((signal));//Reset Interrupt
void __vector_1 (void) __attribute__ ((signal));//External Interrupt 0
void __vector_2 (void) __attribute__ ((signal));//External Interrupt 1
void __vector_3 (void) __attribute__ ((signal));//External Interrupt 2
void __vector_4 (void) __attribute__ ((signal));//Timer\ counter 2 compare match Interrupt
void __vector_5 (void) __attribute__ ((signal));//Timer\ counter 2 over flow Interrupt
void __vector_6 (void) __attribute__ ((signal));//Timer\ counter 1 capture event Interrupt
void __vector_7 (void) __attribute__ ((signal));//Timer\ counter 1compare match A Interrupt
void __vector_8 (void) __attribute__ ((signal));//Timer\ counter 1compare match B Interrupt
void __vector_9 (void) __attribute__ ((signal));// Timer\ counter 1 over flow Interrupt
void __vector_10(void) __attribute__ ((signal));//Timer\counter 0 compare match Interrupt
void __vector_11(void) __attribute__ ((signal));//Timer\counter 0 over flow Interrupt
void __vector_12(void) __attribute__ ((signal));//serial Transfer complete Interrupt
void __vector_13(void) __attribute__ ((signal));//USART,RX complete Interrupt
void __vector_14(void) __attribute__ ((signal));//USART Data Register empty Interrupt
void __vector_15(void) __attribute__ ((signal));//USART, TX complete Interrupt
void __vector_16(void) __attribute__ ((signal));//ADC conversion complete Interrupt
void __vector_17(void) __attribute__ ((signal));//EEPROM Ready Interrupt
void __vector_18(void) __attribute__ ((signal));//Analog comparator Interrupt
void __vector_19(void) __attribute__ ((signal));//TWO - wire serial interface Interrupt
void __vector_20(void) __attribute__ ((signal));// Store program memory ready Interrupt
						  



#endif /* INTERRUPT_INTERFACE_H_ */