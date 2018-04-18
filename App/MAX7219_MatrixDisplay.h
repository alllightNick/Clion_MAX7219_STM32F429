//
// Created by root on 08/02/18.
//

#ifndef __MAX7219_MATRIXDISPLAY_H
#define __MAX7219_MATRIXDISPLAY_H

#include "MAX7219.h"
#include <array>

template<std::uint8_t X, std::uint8_t Y>
class MAX7219_MatrixDispay{

    MAX7219<X*Y>& max;

public:
   typedef std::array<uint8_t,X*Y> DigitData;
    /*   std::array<DigitData, 8> buffer;*/
        std::array<std::array<uint8_t, X*Y>, 8> buffer;


    uint8_t& getByte(uint8_t x, uint8_t y){
        int digit = x % 8;      //Разряд внутри матрицы
        int row = y / 8;
        int col = x / 8;
        int bytePos = col  + row * X;
   //     return buffer[bytePos][digit];
        return buffer[digit][bytePos];
    }


    MAX7219_MatrixDispay(MAX7219<X*Y>& max)
    : max(max) {

    }
    void writePixel(uint8_t x, uint8_t y, bool value){


        if(value){
            getByte(x,y) |= 1 << (y % 8);
        }else{
            getByte(x, y) &= ~ (1 << (y % 8));
        }

    }
    bool getPixel(uint8_t x, uint8_t y){
        /*return static_cast<bool>(getByte(x,y) & (1 << (x % 8)));*/
        return static_cast<bool>(getByte(x,y) & (1 << (y % 8)));
    }
    void write(){
        for( uint8_t i = 0; i < 8; i++){
            max.sendDigit(i,  buffer[i]);
        }
    }

};

#endif //MAX7219_MAX7219_MATRIXDISPLAY_H
