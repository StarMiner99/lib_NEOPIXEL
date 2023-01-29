//
// Created by thijs on 1/28/23.
//

#include "NEOPIXEL.h"

NEOPIXEL::NEOPIXEL(int numPixel, PinName neoPixelPin) {

    dOut = new DigitalOut(neoPixelPin);

    this->numPixels = numPixel;

    this->dataSend = new int[numPixels];
}

void NEOPIXEL::updatePixels() {
    __disable_irq();

    for(int i = 0; i < numPixels; i++) {
        for (int j = 23; j >= 0; j--) { // iterate through bits
            if (dataSend[i] >> j & 1) {
                send1();
            } else {
                send0();
            }
        }
    }

    __enable_irq();


    wait_us(50);
}

void NEOPIXEL::send1() {
    dOut->write(1);
    wait_ns(T1H);
    dOut->write(0);
    //wait_ns(T1L); // no delay works (wait_ns(0) does not work)
}

void NEOPIXEL::send0() {
    dOut->write(1);
    //wait_ns(T0H); // works (wait_ns(0) does not work)
    dOut->write(0);
    wait_ns(T0L);
}

void NEOPIXEL::setPixel(int index, int color) {
    this->dataSend[index] = color;
}

void NEOPIXEL::setAllPixels(int color) {
    for (int i = 0; i < numPixels; i++) {
        dataSend[i] = color;
    }

}

int NEOPIXEL::getPixelColor(int index) {
    return dataSend[index];
}
