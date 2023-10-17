/*
 * DIO_Private.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Mahmoud Emad
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


typedef enum
{
	PO_ITI,
	P1_ITI,
	P2_ITI,
	P3_ITI,
	P4_ITI,
	P5_ITI,
	P6_ITI,
	P7_ITI
}PinsNumber;
typedef enum
{
	GroupError,
DirectionError,
PinNumberErorr

}ErrState;


typedef enum
{
	Group_A_ITI,
	Group_B_ITI,
	Group_C_ITI,
	Group_D_ITI
}GroupNumber;

typedef enum
{
	InPut,
	OutPut,
}PinDirection;


typedef enum
{
	
	PinLow,
	PinHigh
}PinValue;

















#endif /* DIO_PRIVATE_H_ */
