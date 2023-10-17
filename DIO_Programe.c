/*
 * DIO_Programe.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Mahmoud Emad
 */
#include "DIO_Interface.h"
#include "DIO_Register.h"
#include "DIO_Private.h"
#include"../../Common/Bit_Math.h"
 ErrState  DIO_ErrStateSetPinDirection(GroupNumber Copy_GroupNumber, u8 Copy_PinNumber,PinDirection Copy_DirectionState)
{
	 /*if the up layer enter the pins in range of 7->0*/
	 if((Copy_PinNumber>=PO_ITI) && (Copy_PinNumber<=P7_ITI))
	 {
		 /*if the up layer wants the pin to be as input*/
		if(Copy_DirectionState==InPut)
		{
			switch( Copy_GroupNumber)
			{
			/* TO Set the specific pin as input*/
			/*Group A -> portA*/
			case Group_A_ITI: Clr_Bit(DDRA_ITI,Copy_PinNumber);break;
			/*Group B -> portB*/
			case Group_B_ITI: Clr_Bit(DDRB_ITI,Copy_PinNumber);break;
			/*Group C -> portC*/
			case Group_C_ITI: Clr_Bit(DDRC_ITI,Copy_PinNumber);break;
			/*Group D -> portD*/
			case Group_D_ITI: Clr_Bit(DDRD_ITI,Copy_PinNumber);break;
			/*if the user enter group not from the four ports in the micro controller*/
			/*the user will up layer will gets group error as return*/
			default:
				return GroupError;

			}

		}
		/*if the up layer wants the pin to be as output*/
		else if(Copy_DirectionState==OutPut)
		{
			switch( Copy_GroupNumber)
						{
			/* TO Set the specific pin as output*/
			/*Group A -> portA*/
			case Group_A_ITI: Set_Bit(DDRA_ITI,Copy_PinNumber);break;
			/*Group B -> portB*/
			case Group_B_ITI: Set_Bit(DDRB_ITI,Copy_PinNumber);break;
			/*Group C -> portC*/
			case Group_C_ITI: Set_Bit(DDRC_ITI,Copy_PinNumber);break;
			/*Group D -> portD*/
			case Group_D_ITI: Set_Bit(DDRD_ITI,Copy_PinNumber);break;
			/*if the user enter group not from the four ports in the micro controller*/
			/*the user will up layer will gets group error as return*/
			default:
				return GroupError;
				break;
						}
		}
		/*if the up layer put value not out or input*/
		else
		{
			return DirectionError;
		}
	 }
	 /*if the up layer put over ranger of pins*/
	 else
	 {
		 return PinNumberErorr;
	 }
}
 ErrState  DIO_ErrStateSitPinValue(u8 Copy_GroupNumber, u8 Copy_PinNumber,PinValue Copy_ValueState)
 {
	 if((Copy_PinNumber>=PO_ITI) && (Copy_PinNumber<=P7_ITI))
	 {
		 if(Copy_ValueState==PinLow)
		{
			switch( Copy_GroupNumber)
			{
			case Group_A_ITI: Clr_Bit(PORTA_ITI,Copy_PinNumber);break;

			case Group_B_ITI: Clr_Bit(PORTB_ITI,Copy_PinNumber);break;

			case Group_C_ITI: Clr_Bit(PORTC_ITI,Copy_PinNumber);break;

			case Group_D_ITI: Clr_Bit(PORTD_ITI,Copy_PinNumber);break;

			default:
				return GroupError;

			}

		}
		else if(Copy_ValueState==PinHigh)
		{
			switch( Copy_GroupNumber)
			 {
			case Group_A_ITI: Set_Bit(PORTA_ITI,Copy_PinNumber);break;

			case Group_B_ITI: Set_Bit(PORTB_ITI,Copy_PinNumber);break;

			case Group_C_ITI: Set_Bit(PORTC_ITI,Copy_PinNumber);break;

			case Group_D_ITI: Set_Bit(PORTD_ITI,Copy_PinNumber);break;

			default:
				return GroupError;
			 }
		}
		else
		{
			return DirectionError;
		}
	 }
	 else
		 {
			 return PinNumberErorr;
		 }
 }

 ErrState  DIO_ErrStateReadPinValue(GroupNumber Copy_GroupNumber, u8 Copy_PinNumber,u8 *status)
 {
	 if((Copy_PinNumber>=PO_ITI) && (Copy_PinNumber<=P7_ITI))
	 	 {

		 switch( Copy_GroupNumber)
				{
				case Group_A_ITI: *status=Get_Bit(PINA_ITI,Copy_PinNumber);break;

				case Group_B_ITI: *status=Get_Bit(PINB_ITI,Copy_PinNumber);break;

				case Group_C_ITI: *status=Get_Bit(PINC_ITI,Copy_PinNumber);break;

				case Group_D_ITI: *status=Get_Bit(PIND_ITI,Copy_PinNumber);break;

				default:
					return GroupError;

				}
	 	 }
	 else
	 		 {
	 			 return PinNumberErorr;
	 		 }
 }



 ErrState  DIO_ErrStateSetGroupDirection(GroupNumber Copy_GroupNumber,u8 Copy_DirectionState)
 {
	 switch(Copy_GroupNumber)
	 {
	 case Group_A_ITI: DDRA_ITI=Copy_DirectionState; break;
	 case Group_B_ITI: DDRB_ITI=Copy_DirectionState; break;
	 case Group_C_ITI: DDRC_ITI=Copy_DirectionState; break;
	 case Group_D_ITI: DDRD_ITI=Copy_DirectionState; break;
	 default: return GroupError; break;
	 }
 }
 ErrState  DIO_ErrStateSitGroupValue(GroupNumber Copy_GroupNumber, u8 Copy_ValueState)
 {
	 switch(Copy_GroupNumber)
	 {
	 case Group_A_ITI: PORTA_ITI=Copy_ValueState; break;
	 case Group_B_ITI: PORTB_ITI=Copy_ValueState; break;
	 case Group_C_ITI: PORTC_ITI=Copy_ValueState; break;
	 case Group_D_ITI: PORTD_ITI=Copy_ValueState; break;
	 default: return GroupError; break;
	 }

 }
  ErrState  DIO_ErrStateReadGroupValue(GroupNumber Copy_GroupNumber, u8 Copy_PinNumber,u8 *status)
  {
	  switch(Copy_GroupNumber)
	  	 {
	  	 case Group_A_ITI: *status =PINA_ITI; break;
	  	 case Group_B_ITI: *status =PINB_ITI; break;
	  	 case Group_C_ITI: *status =PINC_ITI; break;
	  	 case Group_D_ITI: *status =PIND_ITI; break;
	  	 default: return GroupError; break;
	  	 }
  }
