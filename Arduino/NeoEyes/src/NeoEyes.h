/*
  NeoEyes.h - Library for turning an 8x16 or two 8x8 NeoPixel matrix into a pair of expressive eyes
  Created by Sean Buchmeier +++, December 2023.
  License blah goes here
*/
#ifndef NeoEyes_h
#define NeoEyes_h

#include <Arduino.h>
#include <FastLED.h>

#define _NLEDS 128

struct Emote {
    CRGB* colorList;
    int pattern[8][16];
};

// Emote index (used with setStandardEmote)
enum StandardEmote {
  Off,
  Neutral,
  Happy,
  Sad,
  Angry,
  Confused,
  Closed,
  Sleepy,
  Dead,
  SlightRight,
  Right,
  SlightLeft,
  Left,
  SlightUp,
  Up,
  SlightDown,
  Down,
  D_1,
  D_2,
  D_3,
  D_4,
  D_5,
  D_6,
  D_7,
  D_8,
  D_9,
  D_10,
  D_11,
  D_12,
  D_13,
  D_14,
  D_15,
  D_16,
  D_17,
  D_18,
  D_19,
  D_20
};

class cNeoEyes
{
  public:
    cNeoEyes(CRGB* ledPtr, uint16_t nLeds, bool kMatrixSerpentineLayout = true, bool kMatrixVertical = true, bool isSeparate = true);
    void begin(CLEDController& ctrl);
    
    void setExpression(Emote expression);
    void setExpression(CRGB expression[8][16]);
    void setStandardEmote(StandardEmote emote);
    
    void setNeutral();
    void setRight(bool isSlight = true);
    void setLeft(bool isSlight = true);
    void setUp(bool isSlight = true);
    void setDown(bool isSlight = true);
    void setHappy();
    void setSad();
    void setAngry();
    void setConfused(bool isSplit = true);
    void setClosed();
    void setSleepy();
    void setDead();
    void setOff();
    void setD_1();
    void setD_2();
    void setD_3();
    void setD_4();
    void setD_5();
    void setD_6();
    void setD_7();
    void setD_8();
    void setD_9();
    void setD_10();
    void setD_11();
    void setD_12();
    void setD_13();
    void setD_14();
    void setD_15(); 
    void setD_16();
    void setD_17();
    void setD_18();
    void setD_19();
    void setD_20();

    
    void blink(int closeTime = 50);
    void setBrightness(uint8_t scale);
    
    uint16_t XY(uint8_t x, uint8_t y);
    
    CRGB defaultColors[4] = {CRGB::Black, CRGB::Blue, CRGB::MediumSpringGreen, CRGB::Red};

  private:
    bool _isSeparate = false;
    const int _kMatrixHeight = 8;
    const int _kMatrixWidth = 16;
    bool _kMatrixSerpentineLayout = true;
    bool _kMatrixVertical = true;
    Emote currentEmote;
    uint8_t _brightness = 255;

    CRGB* const _leds;
    CLEDController* controller = nullptr;
};

// FastLED-compatible wrapper template
template<uint8_t DataPin>
class NeoEyes : public cNeoEyes {
public:
    NeoEyes(bool kMatrixSerpentineLayout, bool kMatrixVertical, bool isSeparate)
      : cNeoEyes(ledData, 128, kMatrixSerpentineLayout, kMatrixVertical, isSeparate) {
        memset(ledData, 0, sizeof(ledData));  // clear all LEDs
    }

    void begin() {
        cNeoEyes::begin(FastLED.addLeds<NEOPIXEL, DataPin>(ledData, 128));
    }

private:
    CRGB ledData[128];
};

#endif
