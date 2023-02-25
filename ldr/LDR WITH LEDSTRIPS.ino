// WS2812 on off with LDR by c goulding aka groundFungus
// ldr connects to A0 and ground.  LDR load resistor internal pullup
// WS2812 strip connects to pin 4 through 330Ω resistor
// WS2812 strip has 1000uF cap across its power input
// hysteresis added to prevent chatter around the threshold.

#include <FastLED.h>

#define NUM_LEDS 3

const byte DATA_PIN = A5;
const byte ldrPin = A0;

const int lightThreshold = 512;
const int hysteresis = 20;

CRGB leds[NUM_LEDS];
CRGB color = {255, 255, 0};

void setup()
{
   Serial.begin(115200);
   pinMode(ldrPin, INPUT_PULLUP);
   LEDS.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
   LEDS.setBrightness(120);
   setColor(CRGB::Black);  // turn all LEDs off
   FastLED.show();
}

void loop()
{
   static unsigned long timer = 0;
   unsigned long interval = 200;
   if (millis() - timer >= interval)
   {
      timer = millis();
      int lightValue = analogRead(ldrPin);
      Serial.println(lightValue);
      if (lightValue > lightThreshold + hysteresis)
      {
         setColor(CRGB::White);
         FastLED.show();
      }
      else if (lightValue < lightThreshold - hysteresis)
      {
         setColor(CRGB::Black);
         FastLED.show();
      }
   }
}

void setColor(CRGB color)
{
   for (byte n = 0; n < NUM_LEDS; n++)
   {
      leds[n] = color;
   }
}