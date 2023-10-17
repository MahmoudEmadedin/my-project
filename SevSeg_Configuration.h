/*
 * SevSeg_Configuration.h
 *
 *  Created on: Mar 23, 2023
 *      Author: Mahmoud Emad
 */

#ifndef HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
#define HAL_SEVSEG_SEVSEG_CONFIGURATION_H_
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Register.h"
typedef struct
{
	u8 SevSeg_Type       ;
	GroupNumber SevSeg_Group      ;
	GroupNumber SevSeg_EnablePort ;
	PinsNumber SevSeg_EnablePin  ;
}SevSeg_info;



#endif /* HAL_SEVSEG_SEVSEG_CONFIGURATION_H_ */
