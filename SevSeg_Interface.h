/*
 * SevSeg_Interface.h
 *
 *  Created on: Mar 23, 2023
 *      Author: Mahmoud Emad
 */

#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include  "SevSeg_Private.h"
#include  "SevSeg_Configuration.h"

SevErrState    SevSeg_SevErrStateSetNumber(u8 Copy_Number , SevSeg_info * SevenSegment1);

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 Copy_start , u8 Copy_End );

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1);


#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
