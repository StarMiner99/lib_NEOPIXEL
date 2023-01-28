//
// Created by thijs on 1/28/23.
//

#include "NEOPIXEL.h"

NEOPIXEL::NEOPIXEL(int numPixel, PinName neoPixelPin) {

    dOut = new DigitalOut(neoPixelPin);

    this->numPixels = numPixel;

    this->dataSend = new int[numPixels];

    dataSend[0] = 0xFFFFFF; // white
    dataSend[1] = 0x000000; // black
    dataSend[2] = 0xFF0000; // green
    dataSend[3] = 0x00FF00; // red
    dataSend[4] = 0x0000FF; // blue
    //RCC->APB1ENR |= 0b10000; // enable tim6
    //TIM6->PSC =
}

void NEOPIXEL::updatePixels() {
    __disable_irq();

    for(int i = 0; i < numPixels; i++) {
        for (int j = 23; j >= 0; j--) { // iterate through bits
            if ((dataSend[i] >> j & 1) == 1) {
                send1();
            } else {
                send0();
            }
        }
    }


    wait_us(50);
}

void NEOPIXEL::send1() {
    dOut->write(1);
    wait_ns(T1H);
    dOut->write(0);
    //wait_ns(T1L); // no delay is good (wait_ns(0) does not work)
}

void NEOPIXEL::send0() {
    dOut->write(1);
    //wait_ns(T0H); // delay 0 is good (wait_ns(0) does not work)
    dOut->write(0);
    wait_ns(T0L);
}

void NEOPIXEL::setPixel(int index, int color) {
    this->dataSend[i] = color;
}
