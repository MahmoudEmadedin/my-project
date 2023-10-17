/*
 * DIO_Interface.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Mahmoud Emad
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "DIO_Private.h"
#include "DIO_Register.h"
#include"../../Common/STD_TYPES.h"
#include"../../Common/Bit_Math.h"
 ErrState  DIO_ErrStateSetPinDirection(GroupNumber Copy_GroupNumber, u8 Copy_PinNumber,PinDirection Copy_DirectionState);
 ErrState  DIO_ErrStateSitPinValue(GroupNumber Copy_GroupNumber, u8 Copy_PinNumber,PinValue Copy_DirectionState);
 ErrState  DIO_ErrStateReadPinValue(GroupNumber Copy_GroupNumber, u8 Copy_PinNumber,u8 *status);


 ErrState  DIO_ErrStateSetGroupDirection(GroupNumber Copy_GroupNumber,u8 Copy_DirectionState);
 ErrState  DIO_ErrStateSitGroupValue(GroupNumber Copy_GroupNumber, u8 Copy_ValueState);
 ErrState  DIO_ErrStateReadGroupValue(GroupNumber Copy_GroupNumber, u8 Copy_PinNumber,u8 *status);

#endif /* DIO_INTERFACE_H_ */
