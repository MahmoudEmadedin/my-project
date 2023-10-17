/*
* LCD_Configuration.h
*
*  Created on: Mar 25, 2023
*  Author: Mahmoud Emad
*/

#ifndef LCD_HAL_LCD_CONFIGURATION_H_
#define LCD_HAL_LCD_CONFIGURATION_H_
#include "../../MCAL/DIO/DIO_Private.h"
#include "LCD_Privet.h"
/*this struct will contain the information of the LCD(every pin number and group)*/
typedef struct
{
	/*first thing define the pins group*/
	GroupNumber RSGroup;
	GroupNumber RWGroup;
	GroupNumber EGroup;
	GroupNumber D0Group;
	GroupNumber D1Group;
	GroupNumber D2Group;
	GroupNumber D3Group;
	GroupNumber D4Group;
	GroupNumber D5Group;
	GroupNumber D6Group;
	GroupNumber D7Group;
	/*second thing define the pins group*/
	PinsNumber RSPin;
	PinsNumber RWPin;
	PinsNumber EPin;
	PinsNumber D0Pin;
	PinsNumber D1Pin;
	PinsNumber D2Pin;
	PinsNumber D3Pin;
	PinsNumber D4Pin;
	PinsNumber D5Pin;
	PinsNumber D6Pin;
	PinsNumber D7Pin;
	/*the operation of the LCD four or eight bit mode*/
	OperationOFLCDMode MODE;
}LCD_Info;


#endif /* LCD_HAL_LCD_CONFIGURATION_H_ */
