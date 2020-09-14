#ifndef Button_BAD_h
#define Button_BAD_h
#endif
#include "Arduino.h"
#ifndef Sample_h
#define Sample_h
#include "Sample.h"
#endif
#include <ILI9341_t3.h>
#include <font_DroidSans.h> 
#include <SD.h>
#include <Audio.h>
#ifndef DEBOUNCEDELAY 
#define DEBOUNCEDELAY 50
#endif

// Menu screens
#define SCREEN_MENU 1
#define SCREEN_TITLE 5
#define SCREEN_TEST 8
#define SCREEN_INST 3
#define SCREEN_CTRLS 4
#define SCREEN_SYSTEM 6
#define SCREEN_EDIT_SYNTHDRUM 7
#define SCREEN_EDIT_SYNTHWAVE 10
#define SCREEN_EDIT_PATTERN 9
#define SCREEN_EDIT_SYNTH_PATTERN 11
#define SCREEN_EDIT_FLASH 12
#define SCREEN_EDIT_FLASH_PATTERN 13
#define SCREEN_EDIT_FLASH_FILE 14
// Types of buttons
#define CTRL_INST 101
#define CTRL_MENU 100
#define CTRL_SAVE 102
#define CTRL_EDIT_SYNTHDRUM 103
#define CTRL_EDIT_PATTERN 104
#define CTRL_LED 105
#define CTRL_FLIP_PATTERN 106
#define CTRL_SYNCH 107
#define CTRL_EDIT_SYNTHWAVE 108
#define CTRL_EDIT_FLASH 109
#define CTRL_EDIT_FILE 110
#define CTRL_SELECT_FILE 111
#define CTRL_LOAD_FILE 112

// Types of Instruments
#define SYNTHDRUM 200
#define SYNTHWAVE 201
#define FLASHSAMPLE 202

extern ILI9341_t3 tft;
extern int bgColor;
extern int screenColor;
extern int currentScreen;
extern File currentlySelectedFile;
extern SynthDrum * synthDrumBeingEdited;
extern SynthWave * synthWaveBeingEdited;
extern FlashSample * flashSampleBeingEdited;
extern bool screenChanged;
extern int currentLed;
extern char msg[100];
extern bool msgChanged;
extern bool timeToSynch;
extern AudioPlaySdRaw playSDRaw;
//*******************************************************************************************************************
//*******************************************************************************************************************
//*                                                                                             Button Class
//*******************************************************************************************************************
//*******************************************************************************************************************
class Button{
  protected:
    bool _enabled=false;
    elapsedMillis _debounceTime;    
    elapsedMillis _hoverTime;
    int x, y, lng, hgt;
    char _label[15]; 
    int _borderColor;
    bool _hovered=false;
    int _hoveredColor=0xFD80;
    int _enabledColor=0x37E0;
    int _screen;
    int _testNum=666;
    int _id;
    int _fontSize;
    int _buttonType;
    int _instType;
    int _patternNum;
    File _file;
    SynthDrum * _synthDrum;
    SynthWave * _synthWave;
    FlashSample * _flash;
    
  public:
  Button(int xi, int yi, int lngi, int hgti, char *labeli, int type, int fontSize=8);
  void setup(int xi, int yi, int lngi, int hgti, char *labeli, int type, int fontSize);
  void onHover(bool hovering);
  void enableButton();
  bool isButtonEnabled();
  bool isButtonHovered();
  void restoreNeutralButton();
  void setButtonScreen(int screen);
  int getButtonId();
  int getButtonScreen();
  int getNum();
  void setupFont();
  void setNum(int num);
  bool isClicked(int x, int y);
  bool checkBounds(int a, int b);
  int getButtonHeight();
  int getButtonLength();
  int getButtonX();
  int getButtonY();
  void setButtonX(int i);
  void setButtonY(int i);
  void setButtonLng(int i);
  void setButtonHgt(int i);
  void setButtonLabel(char *i);
  void setButtonPatternNum(int num);
  char* getButtonLabel();
  int getButtonType();
  void onClick();
  bool safelyDebounced();
  void setButtonFile(File f, AudioPlaySdRaw sd);
  void setButtonSynthDrum(SynthDrum * inst);
  void setButtonSynthWave(SynthWave * inst);
  void setButtonFlashSample(FlashSample * inst);
};
