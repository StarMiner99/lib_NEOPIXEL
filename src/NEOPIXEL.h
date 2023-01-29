//
// Created by thijs on 1/28/23.
//

#ifndef NEOPIXEL_NEOPIXEL_H
#define NEOPIXEL_NEOPIXEL_H

#include "mbed.h"

// bit timings
// one
#define T1H 650
//#define T1L 50 //(only no delay works)

//zero
//#define T0H 0 //(only no delay works)
#define T0L 650

class NEOPIXEL {
    DigitalOut* dOut;
    int numPixels;
    int *dataSend;
private:
    void send1();
    void send0();

public:
    NEOPIXEL(int numPixel, PinName neoPixelPin);
    void updatePixels();

    void setPixel(int index, int color);
    int getPixelColor(int index);

    void setAllPixels(int color);
};


#endif //NEOPIXEL_NEOPIXEL_H
