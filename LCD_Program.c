/*
 * LCD_Program.c
 *
 *  Created on: Mar 25, 2023
 *      Author: Mahmoud Emad
 */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"
#include  "LCD_Privet.h"
#include  "LCD_Configuration.h"
//#define F_CPU 8000000UL
#include <util/delay.h>

/*
	*function name:LCD_voidInit
	*return type:void
	*arguments: 
		*Lcd:is a struct pointer point to object of struct contain the data of LCD
	**short description:**
	*this function is Init the LCD 
*/
void LCD_voidInit(LCD_Info * Lcd)
{
	/*at the first before initialization we need to set pins as output */
	LCD_VoidSetPinDirectionValue(Lcd);
	_delay_ms(35);
	// send the set function to LCD
	LCD_VoidSendCommand( LCD_Reset,Lcd);
	_delay_ms(1);
	// send the display on/off command to LCD
	LCD_VoidSendCommand( LCD_CursorON,Lcd);
	_delay_ms(1);
	// send the clear display command to LCD
	LCD_VoidSendCommand( LCD_ClearDisplay,Lcd);
	_delay_ms(2);
	// send the entry mode set command to LCD
	LCD_VoidSendCommand( LCD_EntryMode2,Lcd);
	
}
/*
	*function name:LCD_VoidSendChar 
	*return type:void
	*arguments: 
		*Copy_Char:is the number you want to display in hex 
		*Lcd:is a struct pointer point to object of struct contain the data of LCD
	**short description:**
	*this function is set the char in the arugment to the data bus and r/s to 1 & r/w 0
*/
void LCD_VoidSendChar(u8 Copy_Char,LCD_Info * Lcd)
{
	/*set RS pin to git into display data mode*/
	DIO_ErrStateSitPinValue(Lcd->RSGroup,Lcd->RSPin,PinHigh);
	/*clearRW pin to git into write operation*/
	DIO_ErrStateSitPinValue(Lcd->RWGroup,Lcd->RWPin,PinLow);
	/*send the char to hex handler*/
	LCD_VoidHandleHex2Binary( Copy_Char,Lcd);
	/*give the LCD'S enable pin a pulse to till the LCD the process of writing data is done */
	DIO_ErrStateSitPinValue(Lcd->EGroup,Lcd->EPin,PinHigh);
	_delay_ms(1);
	DIO_ErrStateSitPinValue(Lcd->EGroup,Lcd->EPin,PinLow);
}
/*
	*function name:LCD_VoidSendCommand 
	*return type:void
	*arguments: 
		*Copy_Command:is the number you want to display in hex 
		*Lcd:is a struct pointer point to object of struct contain the data of LCD
	**short description:**
	*this function is set the command in the arugment to the data bus and r/s to 0 & r/w 0
*/
void LCD_VoidSendCommand(u8 Copy_Command,LCD_Info * Lcd)
{
	/*clear RS pin to git into display data mode*/
	DIO_ErrStateSitPinValue(Lcd->RSGroup,Lcd->RSPin,PinLow);
	/*clearRW pin to git into write operation*/
	DIO_ErrStateSitPinValue(Lcd->RWGroup,Lcd->RWPin,PinLow);
	/*send the command to hex handler*/
	LCD_VoidHandleHex2Binary( Copy_Command,Lcd);
	/*give the LCD'S enable pin a pulse to till the LCD the process of writing data is done */
	DIO_ErrStateSitPinValue(Lcd->EGroup,Lcd->EPin,PinHigh);
	_delay_ms(1);
	DIO_ErrStateSitPinValue(Lcd->EGroup,Lcd->EPin,PinLow);
}
/*
	*function name:LCD_VoidSend_string 
	*return type:void
	*arguments: 
		*Address_sring:is the string that you want to display 
		*Lcd:is a struct pointer point to object of struct contain the data of LCD
	**short description:**
	*this function is use the function of LCD_VoidSendChar in loop till the string ends
*/
void LCD_VoidSend_string(u8 *Address_sring, LCD_Info * Lcd)
{
	while (*Address_sring)
	{
		LCD_VoidSendChar(*Address_sring++,Lcd);
	}
}
/*
	*function name:LCD_VoidSetPinDirectionValue 
	*return type: void
	*arguments: 
		*Lcd:is a struct pointer point to object of struct contain the data of Lcd
	**short description:**
	*this function is set all pins of lcd as output 
*/
static void LCD_VoidSetPinDirectionValue(LCD_Info * Lcd)
{
	/*at the first before setting pins we need to set pins as output */
	/*if the LCD mode is 8bit*/
	if (Lcd->MODE==Mode_8Bit)
	{
		DIO_ErrStateSetPinDirection(Lcd->D0Group,Lcd->D0Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D1Group,Lcd->D1Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D2Group,Lcd->D2Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D3Group,Lcd->D3Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D4Group,Lcd->D4Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D5Group,Lcd->D5Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D6Group,Lcd->D6Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D7Group,Lcd->D7Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->RSGroup,Lcd->RSPin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->RWGroup,Lcd->RWPin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->EGroup,Lcd->EPin,OutPut);
		
	}
	
	/* if The LCD mode is 4 bit mode*/
	else if (Lcd->MODE==Mode_4Bit)
	{
		DIO_ErrStateSetPinDirection(Lcd->D4Group,Lcd->D4Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D5Group,Lcd->D5Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D6Group,Lcd->D6Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->D7Group,Lcd->D7Pin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->RSGroup,Lcd->RSPin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->RWGroup,Lcd->RWPin,OutPut);
		DIO_ErrStateSetPinDirection(Lcd->EGroup,Lcd->EPin,OutPut);
	}
	/*if the up layer user enter wrong mode*/
	else
	{
		return Lcd_ModeTypeErr;
	}
}
/*
	*function name:LCD_VoidHandleHex2Binary 
	*return type: void
	*arguments: 
		*Hex:is the char or command you want to send to LCD in hex 
		*Lcd:is a struct pointer point to object of struct contain the data of Lcd
	**short description:** 
	*this function is the hex number and get the first bit of the binary number and set the pin of lcd is as high or low depend on the bit if 0 or 1
*/
static void LCD_VoidHandleHex2Binary(u8 Hex,LCD_Info * Lcd)
{
	u8 Copy_Hex=Hex;											// take copy from hex to work on.
	u8 process;													// create variable to carry the bit of hex.
			
	/*at the first before setting pins we need to set pins as output */
	/*if the LCD mode is 8bit*/									
	if (Lcd->MODE==Mode_8Bit)
	{
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D0Group,Lcd->D0Pin,process);	//set the D0 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		/*we will repeat the last three steps 7 times to make change to the other 7 bits*/
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D1Group,Lcd->D1Pin,process);	//set the D1 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D2Group,Lcd->D2Pin,process);	//set the D2 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D3Group,Lcd->D3Pin,process);	//set the D3 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D4Group,Lcd->D4Pin,process);	//set the D4 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D5Group,Lcd->D5Pin,process);	//set the D5 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D6Group,Lcd->D6Pin,process);	//set the D6 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D7Group,Lcd->D7Pin,process);	//set the D7 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
	}
	
	/* if The LCD mode is 4 bit mode*/
	else if (Lcd->MODE==Mode_4Bit)
	{
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D4Group,Lcd->D0Pin,process);	//set the D4 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D5Group,Lcd->D0Pin,process);	//set the D5 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D6Group,Lcd->D0Pin,process);	//set the D6 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
		
		process=(Copy_Hex&0x01);									//we mask an 1 to hex number and store the result in process.
		DIO_ErrStateSitPinValue(Lcd->D7Group,Lcd->D0Pin,process);	//set the D7 bit data with 0/1 depend on process.
		Copy_Hex=(Copy_Hex>>1);										//we shift the hex by 1 right to get access to the next bit.
	}
	/*if the up layer user enter wrong mode*/
	else
	{
		return Lcd_ModeTypeErr;
	}
}




void CLCD_voidSendNumber(u32 Copy_u32Number,LCD_Info * Lcd)
{

	u32 LOC_u32Reversed = 1 ;

	if( Copy_u32Number == 0 )
	{ LCD_VoidSendChar('0',Lcd); }

	else{

		while( Copy_u32Number != 0 )
		{

			LOC_u32Reversed = ( LOC_u32Reversed * 10 ) + ( Copy_u32Number % 10 );
			Copy_u32Number /= 10 ;

		}
		while( LOC_u32Reversed != 1 )
		{

			LCD_VoidSendChar( ( LOC_u32Reversed % 10 ) + 48 ,Lcd);
			LOC_u32Reversed /= 10 ;

		}

	}

}




void LCD_Postion(u8 Row , u8 Column ,LCD_Info * Lcd)
{
	// Row 1 starts from 0x80 through 0x8f
	// Row 2 starts from 0xC0 through 0xCf
	
	u8 Position = 0;
	
	switch (Row)
	{
		case 0x01:
		Position = 0x80+ Column-1 ;
		break;
		case 0x02:
		Position = 0xC0+ Column-1 ;
		break;
		default:
		Position = 0x80 ;
		break;
	}
	LCD_VoidSendCommand(Position,Lcd);

}