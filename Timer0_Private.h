/*
 * Timer0_Private.h
 *
 * Created: 4/1/2023 10:24:47 PM
 *  Author: Mahmoud Emad
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
 // DEFINE VARIABLE FOR TCCR0 REGISTER AT TIMER 0
#define CS00_ITI   0
#define CS01_ITI   1
#define CS02_ITI   2
#define WGM01_ITI  3 
#define COM00_ITI  4 
#define COM01_ITI  5
#define WGM00_ITI  6
#define FOC0_ITI   7   
// DEFINE VARIABLE FOR TIMSK REGISTER AT TIMER 0
#define TOIE0_ITI   0   
#define OCIE0_ITI   1
// DEFINE VARIABLE FOR TIFR REGISTER AT TIMER 0
#define TOV0_ITI    0   
#define OCF0_ITI    1   















#endif /* TIMER0_PRIVATE_H_ */