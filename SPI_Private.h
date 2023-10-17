/*
 * SPI_Private.h
 *
 * Created: 4/8/2023 9:25:43 PM
 *  Author: Mahmoud Emad
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_ 





/***************************************************    SPCR Register    ***********************************************/
#define SPCR_ITI *((volatile u8*)0x2D) //SPI Control Register
		   		 /**********************************    SPCR BITS    *********************************/
#define SPRI0_ITI  0    //SET the prescaler
#define SPRI1_ITI  1	//SET the prescaler
#define CPHA_ITI   2	//clock phase
#define CPOL_ITI   3	//clock polarity 
#define MSTR_ITI   4	//Master OR slave select
#define DORD_ITI   5	//Data order(LSB,MSB) 
#define SPE_ITI    6	//SPI Enable
#define SPIE_ITI   7	//SPI interrupt Enable
/***********************************************************************************************************************/


/***************************************************    SPSR Register    ***********************************************/
#define SPSR_ITI *((volatile u8*)0x2E) //SPI Status Register
				 /**********************************    SPCR BITS    *********************************/
#define SPIF_ITI   0    //Double SPI SPEED Bit
#define SPE_ITI    6	//SPI write collision flag
#define SPIE_ITI   7	//SET Interrupt Flag
/***********************************************************************************************************************/


/***************************************************    SPDR Register    ***********************************************/
#define SPDR_ITI *((volatile u8*)0x2F) //SPI DATA Register
/***********************************************************************************************************************/


#endif /* SPI_PRIVATE_H_ */