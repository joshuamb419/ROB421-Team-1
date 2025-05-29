
#include "NeoEyes.h"



cNeoEyes::cNeoEyes(CRGB* ledPtr, uint16_t nLeds, bool kMatrixSerpentineLayout = true, bool kMatrixVertical = true, bool isSeparate = true) 
  :
	_leds(ledPtr)
{
    //setPinPositions(kMatrixSerpentineLayout, kMatrixVertical);
    _kMatrixSerpentineLayout = kMatrixSerpentineLayout;
    _kMatrixVertical = kMatrixVertical;
    _isSeparate = isSeparate;
}

void cNeoEyes::begin(CLEDController& ctrl) {
  controller = &ctrl;
}

void cNeoEyes::setExpression(Emote expression) {
  currentEmote = expression;
  for (int i = 0; i < _kMatrixHeight; i ++) {
    for (int j = 0; j < _kMatrixWidth; j++) {
      // so, this is for a static index...
      _leds[XY(j,i)] = expression.colorList[expression.pattern[i][j]];
    }
  }
  FastLED.show(_brightness);
}

void cNeoEyes::setExpression(CRGB expression[8][16]) {
    // set the matrix based on the chosen existing expression... or a custom matrix
    for (int i = 0; i < _kMatrixHeight; i ++) {
        for (int j = 0; j < _kMatrixWidth; j++) {
            // so, this is for a static index...
            _leds[XY(j,i)] = expression[i][j];
        }
    }
    FastLED.show(_brightness);
}

void cNeoEyes::setStandardEmote(StandardEmote emote) {
  switch(emote) {
    case Off:
      setOff();
      break;
    case Neutral:
      setNeutral();
      break;
    case Happy:
     setHappy();
      break;
    case Sad:
      setSad();
      break;
    case Angry:
      setAngry();
      break;
    case Confused:
      setConfused();
      break;
    case Closed:
      setClosed();
      break;
    case Sleepy:
      setSleepy();
      break;
    case Dead:
      setDead();
      break;
    case SlightRight:
      setRight(true);
      break;
    case Right:
      setRight(false);
      break;
    case SlightLeft:
      setLeft(true);
      break;
    case Left:
      setLeft(false);
      break;
    case SlightUp:
      setUp(true);
      break;
    case Up:
      setUp(false);
      break;
    case SlightDown:
      setDown(true);
      break;
    case Down:
      setDown(false);
      break;
    case D_1:
      setD_1();
      break;
    case D_2:
      setD_2();
      break;
    case D_3:
      setD_3();
      break;
    case D_4:
      setD_4();
      break;
    case D_5:
      setD_5();
      break;
    case D_6:
      setD_6();
      break;
    case D_7:
      setD_7();
      break;
    case D_8:
      setD_8();
      break;
    case D_9:
      setD_9();
      break;
    case D_10:
      setD_10();
      break;
    case D_11:
      setD_11();
      break;
    case D_12:
      setD_12();
      break;
    case D_13:
      setD_13();
      break;
    case D_14:
      setD_14();
      break;
    case D_15:
      setD_15();
      break;
    case D_16:
      setD_16();
      break;
    case D_17:
      setD_17();
      break;
    case D_18:
      setD_18();
      break;
    case D_19:
      setD_19();
      break;
    case D_20:
      setD_20();
      break;

      
      
    default:
      setOff();
      break;
  }
}

void cNeoEyes::setNeutral() {
  //CRGB defaultColors[4] = {CRGB::Black, CRGB::Blue, CRGB::MediumSpringGreen, CRGB::Red};
  currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
      { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
      { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 3
      { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 4
      { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 5
      { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 6
      { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
      { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
    } };
  //currentEmote = neutralEmote;
  setExpression(currentEmote);
}

void cNeoEyes::setRight(bool isSlight = true) {
  //CRGB defaultColors[4] = {CRGB::Black, CRGB::Blue, CRGB::MediumSpringGreen, CRGB::Red};
  if(isSlight) {
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 3
        { 1, 0, 2, 2, 0, 0, 0, 1,   1, 0, 2, 2, 0, 0, 0, 1 }, // Row 4
        { 1, 0, 2, 2, 0, 0, 0, 1,   1, 0, 2, 2, 0, 0, 0, 1 }, // Row 5
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
    //currentEmote = slightRightEmote;
    //setExpression(currentEmote);
  }
  else {
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 3
        { 1, 2, 2, 0, 0, 0, 0, 1,   1, 2, 2, 0, 0, 0, 0, 1 }, // Row 4
        { 1, 2, 2, 0, 0, 0, 0, 1,   1, 2, 2, 0, 0, 0, 0, 1 }, // Row 5
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
    //currentEmote = rightEmote;
    //setExpression(currentEmote);
  }
  setExpression(currentEmote);
}

void cNeoEyes::setLeft(bool isSlight = true) {
  //CRGB defaultColors[4] = {CRGB::Black, CRGB::Blue, CRGB::MediumSpringGreen, CRGB::Red};
  if(isSlight) {
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 3
        { 1, 0, 0, 0, 2, 2, 0, 1,   1, 0, 0, 0, 2, 2, 0, 1 }, // Row 4
        { 1, 0, 0, 0, 2, 2, 0, 1,   1, 0, 0, 0, 2, 2, 0, 1 }, // Row 5
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
    // setExpression(currentEmote);
    //currentEmote = slightLeftEmote;
  }
  else {
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 3
        { 1, 0, 0, 0, 0, 2, 2, 1,   1, 0, 0, 0, 0, 2, 2, 1 }, // Row 4
        { 1, 0, 0, 0, 0, 2, 2, 1,   1, 0, 0, 0, 0, 2, 2, 1 }, // Row 5
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
    // setExpression(currentEmote);
    //currentEmote = leftEmote;
  }
  setExpression(currentEmote);
}

void cNeoEyes::setUp(bool isSlight = true) {
  //CRGB defaultColors[4] = {CRGB::Black, CRGB::Blue, CRGB::MediumSpringGreen, CRGB::Red};
  if(isSlight) {
    //currentEmote = slightUpEmote;
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 3
        { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 4
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 5
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
    // setExpression(currentEmote);
  }
  else {
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 2, 2, 0, 1, 0,   0, 1, 0, 2, 2, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 3
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 4
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 5
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
    // setExpression(currentEmote);
  }
  setExpression(currentEmote);
}

void cNeoEyes::setDown(bool isSlight = true) {
  if(isSlight) {
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 3
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 4
        { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 5
        { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
  }
  else {
    currentEmote = { defaultColors,
      {     // Right Eye                   Left Eye
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 1
        { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 3
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 4
        { 1, 0, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 0, 1 }, // Row 5
        { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 6
        { 0, 1, 0, 2, 2, 0, 1, 0,   0, 1, 0, 2, 2, 0, 1, 0 }, // Row 7
        { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 1, 1, 1, 0, 0 }, // Row 8
      } };
  }
  setExpression(currentEmote);
}

void cNeoEyes::setHappy() {
  currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 1
      { 0, 0, 0, 1, 1, 0, 0, 0,   0, 0, 0, 1, 1, 0, 0, 0 }, // Row 2
      { 0, 0, 1, 0, 0, 1, 0, 0,   0, 0, 1, 0, 0, 1, 0, 0 }, // Row 3
      { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 4
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 5
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 6
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 7
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 8
    } };
  setExpression(currentEmote);
}

void cNeoEyes::setSad() {
  currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 1
      { 0, 0, 0, 0, 1, 1, 1, 0,   0, 1, 1, 1, 0, 0, 0, 0 }, // Row 2
      { 0, 0, 0, 1, 0, 0, 0, 1,   1, 0, 0, 0, 1, 0, 0, 0 }, // Row 3
      { 0, 0, 1, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 1, 0, 0 }, // Row 4
      { 0, 1, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
      { 1, 0, 0, 0, 2, 2, 0, 1,   1, 0, 2, 2, 0, 0, 0, 1 }, // Row 6
      { 1, 0, 0, 0, 2, 2, 0, 1,   1, 0, 2, 2, 0, 0, 0, 1 }, // Row 7
      { 0, 1, 1, 1, 1, 1, 1, 0,   0, 1, 1, 1, 1, 1, 1, 0 }, // Row 8
    } };
  setExpression(currentEmote);
}

void cNeoEyes::setAngry() {
  currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 1
      { 0, 1, 1, 1, 0, 0, 0, 0,   0, 0, 0, 0, 1, 1, 1, 0 }, // Row 2
      { 1, 0, 0, 0, 1, 0, 0, 0,   0, 0, 0, 1, 0, 0, 0, 1 }, // Row 3
      { 1, 0, 0, 0, 0, 1, 0, 0,   0, 0, 1, 0, 0, 0, 0, 1 }, // Row 4
      { 1, 0, 0, 2, 2, 0, 1, 0,   0, 1, 0, 2, 2, 0, 0, 1 }, // Row 5
      { 1, 0, 0, 2, 2, 0, 0, 1,   1, 0, 0, 2, 2, 0, 0, 1 }, // Row 6
      { 0, 1, 0, 0, 0, 0, 0, 1,   1, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
      { 0, 0, 1, 1, 1, 1, 1, 1,   1, 1, 1, 1, 1, 1, 0, 0 }, // Row 8
    } };
  setExpression(currentEmote);
}

void cNeoEyes::setConfused(bool isSplit = true) {
  if(isSplit) {
    currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 1, 0, 0, 0 }, // Row 1
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 1, 0, 1, 0, 0 }, // Row 2
      { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 1, 0, 0, 0, 1, 0 }, // Row 3
      { 0, 1, 0, 0, 0, 0, 1, 0,   0, 0, 1, 0, 2, 0, 1, 0 }, // Row 4
      { 1, 0, 0, 2, 2, 0, 0, 1,   0, 0, 1, 0, 2, 0, 1, 0 }, // Row 5
      { 0, 1, 0, 0, 0, 0, 1, 0,   0, 0, 1, 0, 0, 0, 1, 0 }, // Row 6
      { 0, 0, 1, 1, 1, 1, 0, 0,   0, 0, 0, 1, 0, 1, 0, 0 }, // Row 7
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 1, 0, 0, 0 }, // Row 8
    } };
  }
  else {
    Emote currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 1, 0, 0 }, // Row 1
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 1, 0, 1, 0 }, // Row 2
      { 0, 0, 1, 1, 1, 1, 1, 1,   0, 0, 0, 1, 0, 0, 0, 1 }, // Row 3
      { 0, 1, 0, 0, 0, 0, 0, 0,   1, 0, 0, 1, 0, 2, 0, 1 }, // Row 4
      { 1, 0, 0, 0, 2, 2, 0, 0,   0, 1, 0, 1, 0, 2, 0, 1 }, // Row 5
      { 0, 1, 0, 0, 0, 0, 0, 0,   1, 0, 0, 1, 0, 0, 0, 1 }, // Row 6
      { 0, 0, 1, 1, 1, 1, 1, 1,   0, 0, 0, 0, 1, 0, 1, 0 }, // Row 7
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 1, 0, 0 }, // Row 8
    } };
  }
  setExpression(currentEmote);
}

void cNeoEyes::setClosed() {
  currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 1
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 2
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 3
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 4
      { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 5
      { 0, 0, 1, 0, 0, 1, 0, 0,   0, 0, 1, 0, 0, 1, 0, 0 }, // Row 6
      { 0, 0, 0, 1, 1, 0, 0, 0,   0, 0, 0, 1, 1, 0, 0, 0 }, // Row 7
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 8
    } };
  setExpression(currentEmote);
}

void cNeoEyes::setSleepy() {
  currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 1
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 2
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 3
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 4
      { 0, 1, 1, 1, 1, 1, 1, 0,   0, 1, 1, 1, 1, 1, 1, 0 }, // Row 5
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 6
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 7
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 8
    } };
  setExpression(currentEmote);
}

void cNeoEyes::setDead() {
  currentEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 3, 0, 0, 0, 0, 0, 0, 3,   3, 0, 0, 0, 0, 0, 0, 3 }, // Row 1
      { 0, 3, 0, 0, 0, 0, 3, 0,   0, 3, 0, 0, 0, 0, 3, 0 }, // Row 2
      { 0, 0, 3, 0, 0, 3, 0, 0,   0, 0, 3, 0, 0, 3, 0, 0 }, // Row 3
      { 0, 0, 0, 3, 3, 0, 0, 0,   0, 0, 0, 3, 3, 0, 0, 0 }, // Row 4
      { 0, 0, 0, 3, 3, 0, 0, 0,   0, 0, 0, 3, 3, 0, 0, 0 }, // Row 5
      { 0, 0, 3, 0, 0, 3, 0, 0,   0, 0, 3, 0, 0, 3, 0, 0 }, // Row 6
      { 0, 3, 0, 0, 0, 0, 3, 0,   0, 3, 0, 0, 0, 0, 3, 0 }, // Row 7
      { 3, 0, 0, 0, 0, 0, 0, 3,   3, 0, 0, 0, 0, 0, 0, 3 }, // Row 8
    } };
  setExpression(currentEmote);
}

void cNeoEyes::setOff() {
  currentEmote = { defaultColors, {}};
  setExpression(currentEmote);
}

void cNeoEyes::blink(int closeTime = 50) {
  //CRGB defaultColors[4] = {CRGB::Black, CRGB::Blue, CRGB::MediumSpringGreen, CRGB::Red};
  Emote closedEmote = { defaultColors,
    {     // Right Eye                   Left Eye
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 1
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 2
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 3
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 4
      { 0, 1, 0, 0, 0, 0, 1, 0,   0, 1, 0, 0, 0, 0, 1, 0 }, // Row 5
      { 0, 0, 1, 0, 0, 1, 0, 0,   0, 0, 1, 0, 0, 1, 0, 0 }, // Row 6
      { 0, 0, 0, 1, 1, 0, 0, 0,   0, 0, 0, 1, 1, 0, 0, 0 }, // Row 7
      { 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0 }, // Row 8
    } };
  setExpression(closedEmote);
  FastLED.show(_brightness);
  delay(closeTime);
  setExpression(currentEmote);
  FastLED.show(_brightness);
}
void cNeoEyes::setD_1() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 0, 0, 0, 1, 0, 0, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 1, 1, 0, 0, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 0, 1, 0, 1, 0, 0, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 0, 0, 0, 1, 0, 0, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 0, 0, 0, 1, 0, 0, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 0, 0, 0, 1, 0, 0, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 1, 0, 0, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 0, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}
void cNeoEyes::setD_2() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}
void cNeoEyes::setD_3() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}
void cNeoEyes::setD_4() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 0, 0, 0, 1, 0, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 1, 0, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 1, 0, 0, 0, 1, 0, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 1, 1, 1, 1, 1, 0, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 0, 0, 0, 0, 1, 0, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 1, 0, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 1, 0, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 0, 0, 0, 0, 1, 0, 0 }  // Row 8
} };
  setExpression(currentEmote);
}
void cNeoEyes::setD_5() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_6() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_7() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 0, 0, 0, 0, 0, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_8() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_9() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 1, 0, 0, 0, 0, 1, 0, 1,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 1, 0, 0, 0, 1, 0, 0, 1,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 1, 0, 0, 1, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 1, 0, 1, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 1, 0, 0, 0, 0, 0, 0, 1,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}
void cNeoEyes::setD_10() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     1, 0, 0, 0, 0, 0, 1, 1 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     1, 0, 0, 0, 0, 1, 0, 1 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     1, 0, 0, 0, 1, 0, 0, 1 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     1, 0, 0, 1, 0, 0, 0, 1 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     1, 0, 1, 0, 0, 0, 0, 1 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     1, 1, 0, 0, 0, 0, 0, 1 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}
void cNeoEyes::setD_11() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 1, 0, 0, 0, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 0, 1, 1, 0, 0, 0, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 1, 0, 1, 0, 0, 0, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 1, 0, 0, 0, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 1, 0, 0, 0, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 1, 0, 0, 0, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 1, 0, 0, 0, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 1, 1, 1, 1, 1, 0, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_12() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_13() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_14() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 1, 0, 0, 0, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 0, 1, 0, 0, 0, 1, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 0, 1, 0, 0, 0, 1, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_15() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_16() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 0, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_17() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_18() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_19() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 1, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 2
    { 0, 1, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 3
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 0, 0, 0, 0, 1, 0 }, // Row 4
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }, // Row 5
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 6
    { 0, 0, 0, 1, 0, 0, 0, 0,     0, 0, 0, 0, 0, 0, 1, 0 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 0, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}void cNeoEyes::setD_20() {
  currentEmote = { defaultColors,
{   // Right Eye (0)                Left Eye (1)
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 0, 1, 1, 1, 1, 1, 0 }, // Row 1
    { 0, 0, 0, 0, 0, 0, 1, 0,     1, 0, 0, 0, 0, 0, 1, 1 }, // Row 2
    { 0, 0, 0, 0, 0, 0, 1, 0,     1, 0, 0, 0, 0, 1, 0, 1 }, // Row 3
    { 0, 1, 1, 1, 1, 1, 1, 0,     1, 0, 0, 0, 1, 0, 0, 1 }, // Row 4
    { 0, 1, 0, 0, 0, 0, 0, 0,     1, 0, 0, 1, 0, 0, 0, 1 }, // Row 5
    { 0, 1, 0, 0, 0, 0, 0, 0,     1, 0, 1, 0, 0, 0, 0, 1 }, // Row 6
    { 0, 1, 0, 0, 0, 0, 0, 0,     1, 1, 0, 0, 0, 0, 0, 1 }, // Row 7
    { 0, 1, 1, 1, 1, 1, 1, 0,     0, 1, 1, 1, 1, 1, 1, 0 }  // Row 8
} };
  setExpression(currentEmote);
}
void cNeoEyes::setBrightness(uint8_t scale) {
  _brightness = scale;
  FastLED.show(_brightness);
}

// Convert the x,y position to led index flexibly
uint16_t cNeoEyes::XY( uint8_t x, uint8_t y)
{
  uint16_t i;
  int _matrixWidth = _kMatrixWidth;
  int _matrixHeight = _kMatrixHeight;
  if (_isSeparate == true) {
    _matrixWidth = _kMatrixWidth/2;
    _matrixHeight = _kMatrixHeight*2;
    if (x >= _matrixWidth) {
      x = x - _matrixWidth;
      y = y + _kMatrixHeight;
    }
  }
  
  if( _kMatrixSerpentineLayout == false) {
    if (_kMatrixVertical == false) {
      i = (y * _matrixWidth) + x;
    } else {
      i = _matrixHeight * (_matrixWidth - (x+1))+y;
    }
  }

  if( _kMatrixSerpentineLayout == true) {
    if (_kMatrixVertical == false) {
      if( y & 0x01) {
        // Odd rows run backwards
        uint8_t reverseX = (_matrixWidth - 1) - x;
        i = (y * _matrixWidth) + reverseX;
      } else {
        // Even rows run forwards
        i = (y * _matrixWidth) + x;
      }
    } else { // vertical positioning
      if ( x & 0x01) {
        i = _matrixHeight * (_matrixWidth - (x+1))+y;
      } else {
        i = _matrixHeight * (_matrixWidth - x) - (y+1);
      }
    }
  }
  
  return i;
}

