#include "FastLED.h"

#define NUM_LEDS    200
#define DATA_PIN    5
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define DELAY_TIME  0.01

CRGB leds[NUM_LEDS];
CRGBPalette16 currentPalette;
TBlendType currentBlending;

uint8_t brightness = 100;
uint8_t colorIndex = 0;
uint8_t i = 0;
bool flag = true;

void isFirstPeriod() {
    
    (flag) ? (
            colorIndex = random() * 10,
            brightness = 250
        ) : (
            colorIndex = random() + 32000,
            brightness = 150
    );

    flag  = !flag;
}

void setup() {
  
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness( BRIGHTNESS );

    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}

void loop() {

    leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
    
    FastLED.show();
    delay(DELAY_TIME);

    if (i < NUM_LEDS) {
    
    ++i;
    
        if (i == NUM_LEDS) {
            i = 0;
            isFirstPeriod();
        }
        
        colorIndex += 1000; 
    } 
}
