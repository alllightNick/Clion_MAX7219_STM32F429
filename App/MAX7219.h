//
// Created by root on 07/02/18.
//

#ifndef __MAX7219_H
#define __MAX7219_H



//#include <cmsis_armcc_V6.h>
#include "stm32f4xx_hal.h"
#include "MAX7219_Register.h"
#include "MAX7219_Pin.h"
#include <array>
#include <stm32f429xx.h>


template<std::size_t N>
class MAX7219{

    SPI_HandleTypeDef &spi;


    MAX7219_Pin cs;


    template< std::size_t Length>
    void sendPackets(const std::array<uint16_t, Length> &packets){
        cs.low();

        HAL_SPI_Transmit_DMA(&spi,reinterpret_cast<uint8_t *>(const_cast<uint16_t *>(packets.data())),Length);

 /*       HAL_SPI_Transmit(&spi,reinterpret_cast<uint8_t *>(const_cast<uint16_t *>(packets.data())),
        Length, 5000);*/
            if(spi.Instance == SPI5){
                while(HAL_IS_BIT_CLR(spi.Instance->SR, SPI_SR_TXE));
                while (HAL_IS_BIT_SET(spi.Instance->SR, SPI_SR_BSY));
               cs.high();
        }

  /*  */



    }

//создать пакет данных для пересылки в регистр  MAX7219
//старший байт - регистр
//младщий байт  = содержимое регистра
uint16_t makePacket(MAX7219_Register reg,uint8_t value){
    return (static_cast <uint8_t >(reg) <<8) | value;
}
void sendPacket(MAX7219_Register reg,uint8_t value){
        std::array<uint16_t,N> packets;
        for(uint16_t &v :packets){
            v = makePacket(reg,value);
        }
        sendPackets(packets);
    }

public:
    MAX7219(SPI_HandleTypeDef &spi, MAX7219_Pin cs)
            :spi(spi),cs(cs){
        }
    void powerOn(){
        sendPacket(MAX7219_Register::Shutdown, 1);
    }
    void powerOff(){
        sendPacket(MAX7219_Register::Shutdown, 0);
    }
    void intensity(uint8_t value){
        sendPacket(MAX7219_Register::Intensity, value & 0x0F);
    }
    void scanLimit(uint8_t limit){
        sendPacket(MAX7219_Register::ScanLimit ,limit & 0x07);
    }
    void sendDigit(uint8_t digit, const std::array<uint8_t,N>& data){
        digit &= 0x07;
        std::array<uint16_t, N> packets;
        for(std::size_t i=0; i < N; i++){
            packets[i] = makePacket(MAX7219_Register(static_cast<uint8_t>(MAX7219_Register::Digit0)
            +digit), data[i]);
        }
        sendPackets(packets);
    }

};


#endif //MAX7219_MAX7219_H
