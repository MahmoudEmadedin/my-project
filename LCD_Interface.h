/*
* LCD_Interface.h
*
*  Created on: Mar 25, 2023
*      Author: Mahmoud Emad
*/

#ifndef LCD_HAL_LCD_INTERFACE_H_
#define LCD_HAL_LCD_INTERFACE_H_

#include  "LCD_Privet.h"
#include  "LCD_Configuration.h"

void LCD_voidInit(LCD_Info * Lcd);
void LCD_VoidSendChar(u8 Copy_Char,LCD_Info * Lcd);
void LCD_VoidSendCommand(u8 Copy_Command,LCD_Info * Lcd);
void LCD_VoidSend_string(u8 *Address_sring, LCD_Info * Lcd);
static void LCD_VoidSetPinDirectionValue(LCD_Info * Lcd);
static void LCD_VoidHandleHex2Binary(u8 Hex,LCD_Info * Lcd);
void CLCD_voidSendNumber(u32 Copy_u32Number,LCD_Info * Lcd);
void LCD_Postion(u8 Row , u8 Column ,LCD_Info * Lcd);


#endif /* LCD_HAL_LCD_INTERFACE_H_ */
