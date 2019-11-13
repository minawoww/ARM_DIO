/*
 * dio.c
 *
 *  Created on: Jul 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../../mcal/mcu_hw.h"
/* */

#include "dio.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    STD_levelType ret;
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case  Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }

    if( *( (uint8 *)(&(PORT_Addr->GPIODATA)) + (uint8)(1 << (ChannelPos + 2) ) ) > 0 )
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }

    if(Level == STD_high)
    {
       // PORT_Addr->GPIODATA + (uint32)(1 << (ChannelPos + 2) )  = (uint32)(1 << (ChannelPos + 2) );
     //  *( (uint32*)0x40004008) = (uint32)(1 << (ChannelPos + 2) );
      // *( (uint32*)0x40004008) = (uint32)2;
       //*( (uint32*)0x40004004) = (uint32)1;
      //  PORT_Addr->GPIODATA + ()
      //  PORT_Addr->GPIODATA|= (uint32)(1<<ChannelPos);
        *( (uint8 *)(&(PORT_Addr->GPIODATA)) + (uint8)(1 << (ChannelPos + 2) ) ) = (uint8)(1<<ChannelPos);


    }
    else
    {
        *( (uint8 *)(&(PORT_Addr->GPIODATA)) + (uint8)(1 << (ChannelPos + 2) ) ) =  (uint8)0;
    }

}

uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }


    ret = *( (uint8*)(&(PORT_Addr->GPIODATA)) + 0x3FC);

    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{

    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }

    *( (uint8*)(&(PORT_Addr->GPIODATA)) + 0x3FC) = (uint8)value;

}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;
    volatile PORT_RegType* PORT_Addr;

    switch (PortId)
    {
    case Dio_Port_A:
        PORT_Addr = &PORTA_REG;
        break;
    case Dio_Port_B:
        PORT_Addr = &PORTB_REG;
        break;
    case Dio_Port_C:
        PORT_Addr = &PORTC_REG;
        break;
    case Dio_Port_D:
        PORT_Addr = &PORTD_REG;
        break;
    case Dio_Port_E:
        PORT_Addr = &PORTE_REG;
        break;
    case Dio_Port_F:
        PORT_Addr = &PORTF_REG;
        break;
    }

    *( (uint8 *)(&(PORT_Addr->GPIODATA)) + (uint8)(1 << (ChannelPos + 2) ) ) ^= (uint8)(1<<ChannelPos);



}
void Dio_FlipPort(Dio_PortType PortId)
{

    volatile PORT_RegType* PORT_Addr;

       switch (PortId)
       {
       case Dio_Port_A:
           PORT_Addr = &PORTA_REG;
           break;
       case Dio_Port_B:
           PORT_Addr = &PORTB_REG;
           break;
       case Dio_Port_C:
           PORT_Addr = &PORTC_REG;
           break;
       case Dio_Port_D:
           PORT_Addr = &PORTD_REG;
           break;
       case Dio_Port_E:
           PORT_Addr = &PORTE_REG;
           break;
       case Dio_Port_F:
           PORT_Addr = &PORTF_REG;
           break;
       }

       *( (uint8*)(&(PORT_Addr->GPIODATA)) + 0x3FC) ^=  (uint8)0xFF;

}



