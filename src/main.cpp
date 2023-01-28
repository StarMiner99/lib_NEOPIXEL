#include "NEOPIXEL.h"

NEOPIXEL np(10, PA_7);

int main() {
    np.setAllPixels(0xFF0000);
    np.setPixel(3, 0x00FF00);
    np.updatePixels();

    while(true) {

    };
}
