//
// Created by root on 10/02/18.
//

#include "example.h"
#include "MAX7219.h"
#include "MAX7219_MatrixDisplay.h"
#include "main.h"



#include "cmsis_os.h"


#include "SEGGER_RTT.h"



extern SPI_HandleTypeDef hspi5;
const uint8_t xDimetion = 3;
const uint8_t yDimetion = 1;

void StartTaskDisplay(void const * argument){
    MAX7219<xDimetion*yDimetion > max(hspi5,{SPI_CS_GPIO_Port, SPI_CS_Pin});
    MAX7219_MatrixDispay<xDimetion, yDimetion> dispay(max);

    max.powerOn();
    max.intensity(5);
    max.scanLimit(7);


    uint8_t count = 0;

    while (true) {
        //Пример использовани матричного дисплея

            for (uint8_t y = 0; y < 8 * yDimetion; y++) {
                for (uint8_t x = 0; x < 8 * xDimetion; x++) {
                dispay.writePixel(x, y, x + y == count/*1*/);
                //               dispay.write();
            }

        }
        dispay.write();
        SEGGER_RTT_WriteString(0,"Внутри вечного цикла");
        count++;
        count %= (xDimetion+1)*8;

        osDelay(50);

    }
}
