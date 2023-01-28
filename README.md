# NEOPIXEL (WS2812B) Library for arm MBED
## Quick ussage Guide:

Initialize Neopixel(strip):

`NEOPIXEL np(<length>, <pin>);`

- **np**: name of choice.
- **length**: number (int) of neopixels connected to each other. If only one is connected pass 1.
- **pin**: pin (PinName) on which the neopixels are connected (e.g. PA_7).

Set color of single LED:

`np.setPixel(<index>, <color>);`

- **np**: name given in initialization.
- **index**: index of LED (0: first LED, length-1: last LED)
- **color**: new color for the LED in GRB(Green Red Blue) HEX-Format (first byte Green, second byte Red, third byte Blue)

Write data to the LEDs:

`np.updatePixels();`
- **np**: name given in initialization.

