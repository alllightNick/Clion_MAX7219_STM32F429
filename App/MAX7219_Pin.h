//
// Created by root on 07/02/18.
//Класс, описывающий вывод, используемый как CS
//

#ifndef __MAX7219_PIN_H
#define __MAX7219_PIN_H

//#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"
class MAX7219_Pin{
public:
    GPIO_TypeDef *port; //порт CS
    uint16_t pin;       //вывод CS

    void high(){
        HAL_GPIO_WritePin(port,pin, GPIO_PIN_SET);
    }
    void low(){
        HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
    }
};

#endif //MAX7219_MAX7219_PIN_H
