#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 16

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7
//#define CLOCK_PIN 3 //not used

#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    16
#define BRIGHTNESS_HIGH 255
#define BRIGHTNESS_LOW 20
#define BRIGHTNESS_SWITCH 11


// Define the array of leds
CRGB leds[NUM_LEDS];
int brightness;

void setup() {
	LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);
	LEDS.setBrightness(BRIGHTNESS_HIGH);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
	static uint8_t hue = 0;
        int leader1, leader2, leader3, leader4;
	Serial.print("x");
        //first chose brightness level based on user switch
        //if(digitalRead(BRIGHTNESS_SWITCH)) brightness = BRIGHTNESS_HIGH;
        //else brightness = BRIGHTNESS_LOW;
        //LEDS.setBrightness(brightness);
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		leds[i] = CHSV(hue++,255,255);
                leader1 = (i + 10) % NUM_LEDS;
                leader2 = (i + 20) % NUM_LEDS;
                leader3 = (i + 30) % NUM_LEDS;
                leader4 = (i + 40) % NUM_LEDS;
                leds[leader1] = CHSV(hue++,255,255); 
		leds[leader2] = CHSV(hue++,255,255);
                leds[leader3] = CHSV(hue++,255,255);
                leds[leader4] = CHSV(hue++,255,255);
                // Show the leds
		FastLED.show(); 
		// now that we've shown the leds, reset the i'th led to black
	        leds[i] = CRGB::Black;
                leds[leader1] = CRGB::Black;
		leds[leader2] = CRGB::Black;
                leds[leader3] = CRGB::Black;
                leds[leader4] = CRGB::Black;
                //fadeall();
		// Wait a little bit before we loop around and do it again
		delay(100);
	}
	Serial.print("x");
}
