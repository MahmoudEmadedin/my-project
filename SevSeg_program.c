/*
 * SevSeg_program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Mahmoud Emad
 */
#include "../../Common/STD_TYPES.h"
#include "../../Common/Bit_Math.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SevSeg_Interface.h"
#include <util/delay.h>

u8 SevSeg_ArrCA[SevSeg_ArrSize]=
{
	SevSegCA_0 ,
	SevSegCA_1 ,
	SevSegCA_2 ,
	SevSegCA_3 ,
	SevSegCA_4 ,
	SevSegCA_5 ,
	SevSegCA_6 ,
	SevSegCA_7 ,
	SevSegCA_8 ,
	SevSegCA_9 ,
};

u8 SevSeg_ArrAN[SevSeg_ArrSize]=
{
	SevSegAN_0 ,
	SevSegAN_1 ,
	SevSegAN_2 ,
	SevSegAN_3 ,
	SevSegAN_4 ,
	SevSegAN_5 ,
	SevSegAN_6 ,
	SevSegAN_7 ,
	SevSegAN_8 ,
	SevSegAN_9 ,
};


/*
	*function name:SevSeg_SevErrStateSetNumber 
	*return type: enum call SevErrState(return the type of error)
	*arguments: 
		*Copy_number:is the number you want to display in hex 
		*SevenSegment:is a struct pointer point to object of struct contain the data of seven segment
	**short description:**
	*this function is display one number that sent in function argument 
*/
SevErrState SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info *SevenSegment1)
{
	/*check if the number send in argument in limit of seven segment*/
// 	if(((Copy_Number>=SevSegCA_0)&&(Copy_Number<=SevSegCA_9))||((Copy_Number>=SevSegAN_0)&&(Copy_Number<=SevSegAN_9)))
// 	{
		/*check the type of seven segment common anode or common cathode*/
		
		/*if the type of seven segment is common cathode*/
		if(SevenSegment1->SevSeg_Type ==commanCathode)
		{
			/*
				*if the seven segment common cathode we set the pin of cathode output & the output is low
			*/
			DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort, SevenSegment1->SevSeg_EnablePin,OutPut);
			DIO_ErrStateSitPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,PinLow);
			/*
				*check if for errors from setting the pins of common cathode
				*if theres no error returns set the pins of seven segment that create number as output and as high
			*/
			//if(StatusOutLow!=GroupError && StatusOutLow!=PinNumberErorr && StatusOutLow!= DirectionError)
			//{
				u8 setSevSegOut =DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group, Copy_Number);
				u8 StatusOfNumber =DIO_ErrStateSitGroupValue(SevenSegment1->SevSeg_Group, Copy_Number);
		//	}
			/*
				if there is an error return error to app layer user
			*/
// 			else
// 			{
// 					return ErrOutLow  ;
// 			}
		}
		
		
		/*if the type of seven segment is common cathode*/
		else if(SevenSegment1->SevSeg_Type ==commanAnode)
		{
			/*
				*if the seven segment common anode we set the pin of anode output & the output is high
			*/
			u8 StatusOfOperation=DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort, SevenSegment1->SevSeg_EnablePin,OutPut);
			u8 StatusOutLow=DIO_ErrStateSitPinValue(SevenSegment1->SevSeg_EnablePort, SevenSegment1->SevSeg_EnablePin,PinHigh);
			/*
				*check if for errors from setting the pins of common cathode
				*if theres no error returns set the pins of seven segment that create number as output and as high
			*/
			if(StatusOutLow!=GroupError && StatusOutLow!=PinNumberErorr&& StatusOutLow!= DirectionError)
			{
			/*
				if there is an error return error to app layer user
			*/
				u8 setSevSegOut =DIO_ErrStateSetGroupDirection(SevenSegment1->SevSeg_Group, Copy_Number);
				u8 StatusOfNumber =DIO_ErrStateSitGroupValue(SevenSegment1->SevSeg_Group, Copy_Number);
			}
			/*
				if there is an error return error to app layer user
			*/
			else
			{
				return ErrOutLow;
			}
		}
		
		/*if the the type is wrong return error*/
		else
		{
			return SevSegTypeErr;
		}

	/*if the user enter value out of range*/
// 	}
// 	else
// 	{
// 		return NumberErr;
// 	}

}

/*
	*function name:SevSeg_SevErrStateDisplayRange
	*return type: enum call SevErrState(return the type of error)
	*arguments: 
		*Copy_Start:is the first number you want to display in hex 
		*Copy_End:is the Last number you want to display in hex 
		*SevenSegment:is a struct pointer point to object of struct contain the data of seven segment
	**short description:**
	*this function is display the range of numbers that sent in argument 
*/
SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End )
{
	/*check the type of seven segment is common cathode or anode*/
	
	/*if the seven segment is common cathode*/
	if(SevenSegment1->SevSeg_Type ==commanCathode)
	{
		/*send the value of wanted numbers to SevSeg_SevErrStateSetNumber*/
		for(u8 i=Copy_start;i<=Copy_End;i++)
		{
			SevErrState operation= SevSeg_SevErrStateSetNumber(SevSeg_ArrCA[i] ,SevenSegment1);
			_delay_ms(5000);
		}	
	}
	
	
	/*if the seven segment is common anode*/
	else if (SevenSegment1->SevSeg_Type ==commanAnode)
	{
		/*send the value of wanted numbers to SevSeg_SevErrStateSetNumber*/
		for(u8 i=Copy_start;i<=Copy_End;i++)
		{
			SevErrState operation=SevSeg_SevErrStateSetNumber(SevSeg_ArrAN[i] ,SevenSegment1);
		}
	}
	else
	{
		return SevSegTypeErr;
	}
	
}

/*
	*function name:SevSeg_SevErrStateDisplayMax
	*return type: enum call SevErrState(return the type of error)
	*arguments:  
		*SevenSegment:is a struct pointer point to object of struct contain the data of seven segment
	**short description:**
	*this function is display all the range of seven segment 
*/
SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1)
{
	/*check the type of seven segment is common cathode or anode*/
	
	/*if the seven segment is common cathode*/
	if(SevenSegment1->SevSeg_Type ==commanCathode)
	{
	SevErrState operation=SevSeg_SevErrStateDisplayRange(SevenSegment1 ,0 , 9);
	}
		
	/*if the seven segment is common anode*/
	else if (SevenSegment1->SevSeg_Type ==commanAnode)
	{
		SevErrState operation=SevSeg_SevErrStateDisplayRange(SevenSegment1 ,SevSegAN_0,SevSegAN_9);
	}
	else
	{
		return SevSegTypeErr;
	}
	
}

