/*
 * SPI_Interface.h
 *
 * Created: 4/8/2023 9:26:07 PM
 *  Author: Mahmoud Emad
 */ 
#include "../../Common/STD_TYPES.h"


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_VoidSPISlaveInit();
void SPI_VoidSPIMasterInit();
u8 SPI_U8SPISendRecive(u8 data);



#endif /* SPI_INTERFACE_H_ */