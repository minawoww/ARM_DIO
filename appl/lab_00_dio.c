/*
 * lab_03_spi.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../mcal/global_interrupt.h"
#include "../mcal/sys_ctr/SysCtr.h"
#include "../mcal/port_driver/port.h"
#include "../mcal/dio/dio.h"

void lab_00_dio(void)
{
    uint8 PortData = 0;
    uint8 ChannelData = 0;
    SysCtr_init();
    PORT_init();

  //  Dio_WritePort(Dio_Port_A, 0x0F0);
   // PortData = Dio_ReadPort(Dio_Port_A);

    Dio_FlipChannel(Dio_Channel_F1);
    Dio_FlipChannel(Dio_Channel_F2);
    Dio_FlipChannel(Dio_Channel_F3);
  //  ChannelData =  Dio_ReadChannel(Dio_Channel_F1);

  //  Dio_WriteChannel(Dio_Channel_A0, ChannelData);
   // Dio_WriteChannel(Dio_Channel_A1, STD_high);
  //  Dio_WriteChannel(Dio_Channel_F2, STD_high);

    while(1)
    {

    }
}


