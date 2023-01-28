#include "NEOPIXEL.h"

NEOPIXEL np(10, PA_7);

int main() {


    while(true) {
        np.updatePixels();
    };
}
