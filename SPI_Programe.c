/*
 * SPI_Programe.c
 *
 * Created: 4/8/2023 9:36:14 PM
 *  Author: Mahmoud Emad
 */ 
#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "../DIO/DIO_Interface.h"
#include "../../Common/STD_TYPES.h"
#include "../../Common/Bit_Math.h"
void SPI_VoidSPISlaveInit()
{
	DIO_ErrStateSetPinDirection(Group_B_ITI,P4_ITI,InPut);    //set this pin as output for slave selecting
	DIO_ErrStateSetPinDirection(Group_B_ITI,P5_ITI,InPut);	  //set this pin as output for MOSI
	DIO_ErrStateSetPinDirection(Group_B_ITI,P7_ITI,InPut);	  //set this pin as output for SCK
	DIO_ErrStateSetPinDirection(Group_B_ITI,P6_ITI,OutPut);	  //set this pin as output for MISO
	Set_Bit(SPCR_ITI,SPE_ITI);// enable SPI
	Set_Bit(SPCR_ITI,DORD_ITI);// enable LSB
	Clr_Bit(SPCR_ITI,MSTR_ITI);// enable slave
	Set_Bit(SPCR_ITI,CPOL_ITI);// set CLK polarity as falling Leading Edge
	Set_Bit(SPCR_ITI,CPHA_ITI);// set CLK phase as setup Leading Edge
}



void SPI_VoidSPIMasterInit()
{
	DIO_ErrStateSetPinDirection(Group_B_ITI,P3_ITI,OutPut); //set this pin as output for slave selecting
	DIO_ErrStateSetPinDirection(Group_B_ITI,P5_ITI,OutPut);	//set this pin as output for MOSI
	DIO_ErrStateSetPinDirection(Group_B_ITI,P7_ITI,OutPut);	//set this pin as output for SCK
	DIO_ErrStateSetPinDirection(Group_B_ITI,P6_ITI,InPut);	//set this pin as output for MISO
	DIO_ErrStateSitPinValue(Group_B_ITI,P3_ITI,PinLow);     //set this pin as HIGH for slave selecting
	Set_Bit(SPCR_ITI,SPE_ITI);// enable SPI
	Set_Bit(SPCR_ITI,DORD_ITI);// enable LSB
	Clr_Bit(SPCR_ITI,MSTR_ITI);// enable Master
	Set_Bit(SPCR_ITI,CPOL_ITI);// set CLK polarity as falling Leading Edge
	Set_Bit(SPCR_ITI,CPHA_ITI);// set CLK phase as setup Leading Edge
	Set_Bit(SPCR_ITI,SPRI0_ITI);//SELECT RE SCALER 16
	Set_Bit(SPCR_ITI,SPRI1_ITI);//SELECT RE SCALER 16
	
}

u8 SPI_U8SPISendRecive(u8 data)
{
	DIO_ErrStateSitPinValue(Group_B_ITI,P3_ITI,PinLow);// select the slave
	SPDR_ITI=data;
	while (Get_Bit(SPSR_ITI,SPIE_ITI)==0);
	return SPDR_ITI;
	
}