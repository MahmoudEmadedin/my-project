/*
 * SevSeg_Private.h
 *
 *  Created on: Mar 23, 2023
 *     Author: Mahmoud Emad
 */

#ifndef HAL_SEVSEG_SEVSEG_PRIVATE_H_
#define HAL_SEVSEG_SEVSEG_PRIVATE_H_

#define SevSeg_ArrSize  10

/*Cathode -> Led On if write One*/
#define SevSegCA_0      0x3F
#define SevSegCA_1      0x06
#define SevSegCA_2      0x5B
#define SevSegCA_3      0x4F
#define SevSegCA_4      0x66
#define SevSegCA_5      0x6D
#define SevSegCA_6      0x7D
#define SevSegCA_7      0x07
#define SevSegCA_8      0x7F
#define SevSegCA_9      0x6F

/*anode -> Led On if write Zero*/
#define SevSegAN_0      0xc0
#define SevSegAN_1      0xF9
#define SevSegAN_2      0xA4
#define SevSegAN_3      0xB0
#define SevSegAN_4      0x99
#define SevSegAN_5      0x92
#define SevSegAN_6      0x82
#define SevSegAN_7      0xF8
#define SevSegAN_8      0x80
#define SevSegAN_9      0x90


typedef enum
{
	NumberErr,
	SevSegTypeErr,
	errOUT,
	ErrOutLow,

}SevErrState;


typedef enum
{
	commanCathode,
	commanAnode,
}SevSegComman_Type;



#endif /* HAL_SEVSEG_SEVSEG_PRIVATE_H_ */
