#define CURRENTVERSION 31
// Now using Gir and github!!
// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 150
#define TS_MINY 130
#define TS_MAXX 3800
#define TS_MAXY 4000
#define DEBOUNCEDELAY 50  // For buttons, in millisec
#define DEBOUNCE_NUM 10   // For potentiometers, in value difference
#define TFT_DC      9
#define TFT_CS      14
#define TFT_RST    255  // 255 = unused, connect to 3.3V
#define TFT_MOSI    11
#define TFT_SCLK    13
#define TFT_MISO    12
#define TIRQ_PIN    1
#define TS_CS       8

#define DEBUG_TOUCH_SQUARES 0

#define FREQ_POS 0
#define MIX_POS 1     // Not in Wave
#define FORM_POS 1   // Not in Drum
#define LNG_POS 2
#define PITCH_POS 3  // Not in Wave
#define PLACEHOLDER 3 // Not in Drum
#define NOTE_POS 4
#define VOL_POS 5
#define VERB_POS 6
#define COLOR_POS 7
#define ATTACK_POS 8
#define HOLD_POS 9
#define DECAY_POS 10
#define SUSTAIN_POS 11
#define RELEASE_POS 12
#define TRIP_POS 13

// Note lengths
#define WHOLENOTE 4
#define HALFNOTE  2
#define QUARTERNOTE 1
#define EIGHTHNOTE .5
#define SIXTEENTHNOTE .25


#define CLICK 1
#define PRESS 2

#define GREEN_LED1 27
#define GREEN_LED2 30
#define RED_LED1 32
#define RED_LED2 25
#define BLUE_LED1 33
#define BLUE_LED2 26
#define YELLOW_LED1 29
#define YELLOW_LED2 24
#define WHITE_LED1 28
#define WHITE_LED2 31

#include <ILI9341_t3.h>
#include <font_Arial.h> // from ILI9341_t3
#include <font_DroidSans.h>
#include <XPT2046_Touchscreen.h>
#include <Encoder.h>
#include "Sample.h"
#include "Button_BAD.h"
#include <T4_PowerButton.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioPlaySerialflashRaw  playFlashRaw1;  //xy=102,20
AudioPlaySerialflashRaw  playFlashRaw3; //xy=110,99
AudioPlaySerialflashRaw  playFlashRaw2;  //xy=78,55
AudioPlaySerialflashRaw  playFlashRaw4; //xy=86,134
AudioSynthSimpleDrum     drum1;          //xy=86,380
AudioSynthSimpleDrum     drum2;          //xy=94,408
AudioSynthSimpleDrum     drum4;          //xy=98,527
AudioSynthSimpleDrum     drum3;          //xy=100,454
AudioSynthWaveform       waveform1;      //xy=110,182
AudioSynthWaveform       waveform2;      //xy=116,224
AudioSynthWaveform       waveform3; //xy=64,260
AudioSynthWaveform       waveform4; //xy=70,302
AudioEffectEnvelope      envelope3; //xy=235,265
AudioEffectEnvelope      envelope4; //xy=246,309
AudioAmplifier           amp6;           //xy=248,466
AudioAmplifier           amp4;           //xy=265,424
AudioAmplifier           amp5;           //xy=268,524
AudioAmplifier           amp1;           //xy=271,20
AudioAmplifier           amp2;           //xy=272,58
AudioAmplifier           amp7; //xy=279,99
AudioAmplifier           amp8; //xy=280,137
AudioAmplifier           amp3;           //xy=280,379
AudioEffectEnvelope      envelope1;      //xy=281,187
AudioEffectEnvelope      envelope2;      //xy=292,231
AudioEffectFreeverb      freeverb12; //xy=514,309
AudioEffectFreeverb      freeverb11;  //xy=515,270
AudioEffectFreeverb      freeverb9; //xy=542,145
AudioEffectFreeverb      freeverb10; //xy=543,107
AudioEffectFreeverb      freeverb2;      //xy=544,70
AudioEffectFreeverb      freeverb1;      //xy=545,32
AudioEffectFreeverb      freeverb4;      //xy=560,231
AudioEffectFreeverb      freeverb3;      //xy=561,192
AudioEffectFreeverb      freeverb5;      //xy=588,363
AudioEffectFreeverb      freeverb6;      //xy=604,405
AudioEffectFreeverb      freeverb7;      //xy=610,484
AudioEffectFreeverb      freeverb8;      //xy=612,559
AudioMixer4              SDSampleMixer;         //xy=785,144
AudioMixer4              SynthWaveMixer;         //xy=802,250
AudioMixer4              SynthDrumMixer;         //xy=814,350
AudioMixer4              masterMix;      //xy=992,256
AudioOutputI2S           i2s1;           //xy=1007,396
AudioConnection          patchCord1(waveform3, envelope3);
AudioConnection          patchCord2(waveform4, envelope4);
AudioConnection          patchCord3(playFlashRaw2, amp2);
AudioConnection          patchCord4(playFlashRaw4, amp8);
AudioConnection          patchCord5(drum1, amp3);
AudioConnection          patchCord6(drum2, amp4);
AudioConnection          patchCord7(drum4, amp5);
AudioConnection          patchCord8(drum3, amp6);
AudioConnection          patchCord9(playFlashRaw1, amp1);
AudioConnection          patchCord10(playFlashRaw3, amp7);
AudioConnection          patchCord11(waveform1, envelope1);
AudioConnection          patchCord12(waveform2, envelope2);
AudioConnection          patchCord13(envelope3, freeverb11);
AudioConnection          patchCord14(envelope4, freeverb12);
AudioConnection          patchCord15(amp6, freeverb7);
AudioConnection          patchCord16(amp4, freeverb6);
AudioConnection          patchCord17(amp5, freeverb8);
AudioConnection          patchCord18(amp1, freeverb1);
AudioConnection          patchCord19(amp2, freeverb2);
AudioConnection          patchCord20(amp7, freeverb10);
AudioConnection          patchCord21(amp8, freeverb9);
AudioConnection          patchCord22(amp3, freeverb5);
AudioConnection          patchCord23(envelope1, freeverb3);
AudioConnection          patchCord24(envelope2, freeverb4);
AudioConnection          patchCord25(freeverb12, 0, SynthWaveMixer, 1);
AudioConnection          patchCord26(freeverb11, 0, SynthWaveMixer, 0);
AudioConnection          patchCord27(freeverb9, 0, SDSampleMixer, 3);
AudioConnection          patchCord28(freeverb10, 0, SDSampleMixer, 2);
AudioConnection          patchCord29(freeverb2, 0, SDSampleMixer, 1);
AudioConnection          patchCord30(freeverb1, 0, SDSampleMixer, 0);
AudioConnection          patchCord31(freeverb4, 0, SynthWaveMixer, 3);
AudioConnection          patchCord32(freeverb3, 0, SynthWaveMixer, 2);
AudioConnection          patchCord33(freeverb5, 0, SynthDrumMixer, 0);
AudioConnection          patchCord34(freeverb6, 0, SynthDrumMixer, 1);
AudioConnection          patchCord35(freeverb7, 0, SynthDrumMixer, 2);
AudioConnection          patchCord36(freeverb8, 0, SynthDrumMixer, 3);
AudioConnection          patchCord37(SDSampleMixer, 0, masterMix, 0);
AudioConnection          patchCord38(SynthWaveMixer, 0, masterMix, 2);
AudioConnection          patchCord39(SynthDrumMixer, 0, masterMix, 3);
AudioConnection          patchCord40(masterMix, 0, i2s1, 0);
AudioConnection          patchCord41(masterMix, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=849,637
AudioPlaySdRaw  playSDRaw;
AudioConnection patchCord42( playSDRaw, 0, masterMix, 0 );
// GUItool: end automatically generated code

//AudioOutputI2S     headphones;


// Global Variables:
bool firstTime = true;
int bpm = 120;
int rawObjects = 0;
int wavObjects = 0;
int synthObjects = 0;
elapsedMillis mainTimer;
char msg[100] = "";
bool msgChanged = false;
bool timeToSynch = false;
float tempX = 0;
float tempY = 0;
int screenInstXShift=0;
int screenInstYShift=0;
SynthDrum * synthDrumBeingEdited;
SynthWave * synthWaveBeingEdited;
FlashSample * flashSampleBeingEdited;
int currentType=0;

float vol = .65;
int currentInstEdit = 0;
// Touchscreen variables
elapsedMillis screenRefresh;
int screenColor = 0x37E6; // Apple II Green
//int screenColor=0xFD80;   // Amber
//int screenColor=0xFE60;   // Another Amber
int bgColor = 0x2945;     // light black
//int bgColor=0x0000;       // black
boolean wasTouched = false;
boolean isTouched = false;

int lastSensor = 0;

TS_Point mappedTouch;
XPT2046_Touchscreen ts(TS_CS, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling
ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_MISO);

Encoder firstKnob(15, 22);
Encoder secondKnob(16, 17);
long oldFirstKnobPos = -999;
long oldSecondKnobPos = -999;


// Menu variables
bool screenChanged = true;
int howManyButtons = 0;
int currentScreen = SCREEN_TITLE;
//int currentScreen=SCREEN_INST;
File currentlySelectedFile;
int currentLed = 0;

int titleCounter = 3;  // How many times do we play the title animation before allowing touch inputs? (there are a ton of bogus touch inputs at startup)
// Arrays of the sound objects declared up above.

#define HOW_MANY_SYNTH_DRUMS 4
#define HOW_MANY_SYNTH_WAVES 1
#define HOW_MANY_FLASH_FILES 4


FlashSample flash1("RAW", "ASIA.RAW", EIGHTHNOTE,&playFlashRaw1,&amp1, &freeverb1, bpm, 0,0,0);
FlashSample flash2("RAW", "DRUM.RAW", EIGHTHNOTE,&playFlashRaw2,&amp2, &freeverb2, bpm, 0,0,0);
FlashSample flash3("RAW", "ARG.RAW", EIGHTHNOTE,&playFlashRaw3,&amp3, &freeverb3, bpm, 0,0,0);
FlashSample flash4("RAW", "DAMN.RAW", EIGHTHNOTE,&playFlashRaw4,&amp4, &freeverb4, bpm, 0,0,0);
SynthDrum synthD1(60, 80, 0.55, 1, QUARTERNOTE, &drum1, &amp3, &freeverb5, bpm, 0);
SynthDrum synthD2(440, 40, 1, 1, EIGHTHNOTE, &drum2, &amp4, &freeverb6, bpm, 0);
SynthDrum synthD3(60, 80, 0.55, 1, QUARTERNOTE, &drum3, &amp6, &freeverb7, bpm, 0);
SynthDrum synthD4(440, 40, 1, 1, QUARTERNOTE, &drum4, &amp5, &freeverb8, bpm, 0);

SynthWave sWave1(&waveform1, &envelope1, &freeverb3, EIGHTHNOTE, 440, 0.01, 125, WAVEFORM_TRIANGLE);

SynthDrum * synthDrumArray[HOW_MANY_SYNTH_DRUMS] = {&synthD1, &synthD2, &synthD3, &synthD4};
SynthWave * synthWaveArray[HOW_MANY_SYNTH_WAVES] = {&sWave1};
FlashSample * flashArray[HOW_MANY_FLASH_FILES]={&flash1, &flash2, &flash3, &flash4};

Button * buttonArray[40];

void drawFooter() {
  tft.fillRect(225, 215, 95, 25, bgColor); // Expand to cover msg, I guess?
  tft.setTextColor(screenColor);
  tft.setFont(DroidSans_8);
  tft.setCursor(225, 215);
  tft.print("Memory: ");
  tft.print(memfree());
  tft.setCursor(225, 230);
  tft.print("Version: ");
  tft.print(CURRENTVERSION);

  if (msgChanged) {
    tft.fillRect(0, 200, 224, 320, bgColor);
    tft.setTextColor(screenColor);
    tft.setFont(DroidSans_9);
    tft.setCursor(5, 200);
    tft.print(msg);
    msgChanged = false;
  }

}


////*                                                                                           Update LED
void updateLEDScreen(const char *msg) {

  drawMenu();
 
 
 if(DEBUG_TOUCH_SQUARES) tft.drawRect(mappedTouch.x - 5, mappedTouch.y - 5, 10, 10, screenColor);    // Puts a little square right where the touch was. For debugging!
  if (currentScreen != SCREEN_TITLE) drawFooter();
}


//--------------------------------------------------------------------------------------------------------------DrawMenu is here
// Depending on what the current menu shows, there may be a number of interactive button elements.
void drawMenu() {
  if (screenChanged) {
    screenChanged = false;
    // We've changed to a new screen! Clean up after the old one.
    if (currentScreen != SCREEN_TITLE) tft.fillScreen(bgColor);
    for (int i = 0; i < howManyButtons; i++) {
      // if(*b[i]) delete b[i];
    }
    if (howManyButtons == 1) {
      //delete &buttonArray[0];           /// Eventually we'll need to delete more than just one button!
    }
    howManyButtons = 0;
    switch (currentScreen) {
      case SCREEN_TITLE:
        {
          drawTitleScreen();
          break;
        }
      case SCREEN_EDIT_FLASH_FILE:
      {
        drawFlashFiles();
        break;
      }
      case SCREEN_MENU:
        {
          tft.setTextColor(screenColor);
          tft.setFont(DroidSans_24);
          tft.setCursor(5, 5);
          if (random(100) > 60) tft.println("WE COME to DRUM");
          else tft.println("WELCOME to DRUM");
          char label[] = "Control";
          char label2[] = "Launch";
          char label3[] = "System";
          char label4[] = "Test";

          buttonArray[howManyButtons] = new Button(75, 75, 60, 20, label, CTRL_MENU);
          buttonArray[howManyButtons]->setButtonScreen(SCREEN_CTRLS);
          howManyButtons++;
          buttonArray[howManyButtons] = new Button(175, 75, 45, 20, label2, CTRL_MENU);
          buttonArray[howManyButtons]->setButtonScreen(SCREEN_INST);
          howManyButtons++;
          buttonArray[howManyButtons] = new Button(75, 125, 45, 20, label3, CTRL_MENU);
          buttonArray[howManyButtons]->setButtonScreen(SCREEN_SYSTEM);
          howManyButtons++;
          buttonArray[howManyButtons] = new Button(175, 125, 45, 20, label4, CTRL_MENU);
          buttonArray[howManyButtons]->setButtonScreen(SCREEN_TEST);
          howManyButtons++;
          break;
        }
      case SCREEN_INST:
        {
          const int BUTTON_WIDTH = 100;
          const int EDIT_WIDTH = 40;
          const int BUTTON_HEIGHT = 30;
          const int BUTTON_Y_START = 35;
          const int BUTTON_X_START = 5;
          int buttonX=BUTTON_X_START;
          int buttonY=BUTTON_Y_START;
          
          int totalButtons=(HOW_MANY_SYNTH_DRUMS+HOW_MANY_SYNTH_WAVES+HOW_MANY_FLASH_FILES)*2; // Each type of button also has an edit button
          int buttonsPerColumn=totalButtons/2;
          
          tft.setTextColor(screenColor);
          tft.setFont(DroidSans_24);
          tft.setCursor(5, 5);
          tft.println("HAVE the DRUMS");
          for (int i = 0; i < HOW_MANY_SYNTH_DRUMS; i++) {
            char label[] = {"Loading..."};
            buttonArray[howManyButtons] = new Button(buttonX, buttonY + screenInstYShift, BUTTON_WIDTH, BUTTON_HEIGHT, label, CTRL_INST);
            buttonArray[howManyButtons]->setButtonSynthDrum(synthDrumArray[i]);
            howManyButtons++;
            char label3[] = {"Edit"};
            buttonArray[howManyButtons] = new Button(buttonX+BUTTON_WIDTH+10, buttonY+ screenInstYShift, EDIT_WIDTH, BUTTON_HEIGHT, label3, CTRL_EDIT_SYNTHDRUM);
            buttonArray[howManyButtons]->setButtonSynthDrum(synthDrumArray[i]);
            buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_SYNTHDRUM);
            howManyButtons++;

            if(howManyButtons-1==buttonsPerColumn){
              buttonY=BUTTON_Y_START;
              buttonX=BUTTON_X_START+BUTTON_WIDTH+EDIT_WIDTH+10+10;
            }
            else{
              buttonY+=BUTTON_HEIGHT+5;
            }
          }
          for (int i = 0; i < HOW_MANY_SYNTH_WAVES; i++) {
            char label[] = {"Loading..."};
            buttonArray[howManyButtons] = new Button(buttonX, buttonY + screenInstYShift, BUTTON_WIDTH, BUTTON_HEIGHT, label, CTRL_INST);
            buttonArray[howManyButtons]->setButtonSynthWave(synthWaveArray[i]);
            howManyButtons++;
            char label3[] = {"Edit"};
            buttonArray[howManyButtons] = new Button(buttonX + BUTTON_WIDTH + 10, buttonY + screenInstYShift, EDIT_WIDTH, BUTTON_HEIGHT, label3, CTRL_EDIT_SYNTHWAVE);
            buttonArray[howManyButtons]->setButtonSynthWave(synthWaveArray[i]);
            buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_SYNTHWAVE);
            howManyButtons++;

            if(howManyButtons-1==buttonsPerColumn){
              buttonY=BUTTON_Y_START;
              buttonX=BUTTON_X_START+BUTTON_WIDTH+EDIT_WIDTH+10+10;
            }
            else{
              buttonY+=BUTTON_HEIGHT+5;
            }
          }
          for (int i = 0; i < HOW_MANY_FLASH_FILES; i++) {
            char label4[] = {"Loading..."};
            buttonArray[howManyButtons] = new Button(buttonX, buttonY + screenInstYShift, BUTTON_WIDTH, BUTTON_HEIGHT, label4, CTRL_INST);
            buttonArray[howManyButtons]->setButtonFlashSample(flashArray[i]);
            howManyButtons++;
            char label5[] = {"Edit"};
            buttonArray[howManyButtons] = new Button(buttonX + BUTTON_WIDTH + 10, buttonY + screenInstYShift, EDIT_WIDTH, BUTTON_HEIGHT, label5, CTRL_EDIT_FLASH);
            buttonArray[howManyButtons]->setButtonFlashSample(flashArray[i]);
            buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_FLASH);
            howManyButtons++;

            if(howManyButtons-1==buttonsPerColumn){
              buttonY=BUTTON_Y_START;
              buttonX=BUTTON_X_START+BUTTON_WIDTH+EDIT_WIDTH+10+10;
            }
            else{
              buttonY+=BUTTON_HEIGHT+5;
            }
          }
          char label2[] = {"Main"};
          buttonArray[howManyButtons] = new Button(200 + screenInstXShift, 180, 45, 20, label2, CTRL_MENU);
          buttonArray[howManyButtons]->setButtonScreen(SCREEN_MENU);
          howManyButtons++;
          break;
        }
      case SCREEN_SYSTEM:
        {
          tft.setTextColor(screenColor);
          tft.setFont(DroidSans_24);
          tft.setCursor(5, 5);
          tft.println("BPM");
          tft.setCursor(200, 5);
          tft.println("VOL");
          tft.setFont(DroidSans_20);
          tft.setCursor(5, 30);
          tft.println(bpm);
          tft.setCursor(200, 30);
          tft.println(vol);

          char label[] = {"Main"};
          buttonArray[howManyButtons] = new Button(150, 180, 45, 20, label, CTRL_MENU);
          buttonArray[howManyButtons]->setButtonScreen(SCREEN_MENU);
          howManyButtons++;

          break;
        }
      case SCREEN_EDIT_PATTERN:
        {
          drawPatternEdit(SYNTHDRUM);
          break;
        }
      case SCREEN_EDIT_SYNTH_PATTERN:
        {
          drawPatternEdit(SYNTHWAVE);
          break;
        }
      case SCREEN_EDIT_FLASH_PATTERN:
      {
        drawPatternEdit(FLASHSAMPLE);
        break;
      }
      case SCREEN_EDIT_SYNTHDRUM:
        {
          drawSynthDrumEdit();
          break;
        }
      case SCREEN_EDIT_SYNTHWAVE:
        {
          drawSynthWaveEdit();
          break;
        }
      case SCREEN_EDIT_FLASH:
      {
        drawFlashSampleEdit();
        break;
      }
      case SCREEN_TEST:
        {
          char label[] = "Cycle";
          buttonArray[howManyButtons] = new Button(20, 170, 45, 20, label, CTRL_LED);
          howManyButtons++;
          char label3[] = "Synch";
          buttonArray[howManyButtons] = new Button(20, 20, 45, 20, label3, CTRL_SYNCH);
          howManyButtons++;
          char label2[] = "Back";
          char *ptr = label2;
          buttonArray[howManyButtons] = new Button(150, 170, 45, 20, ptr, CTRL_MENU);
          buttonArray[howManyButtons]->setButtonScreen(SCREEN_MENU);
          howManyButtons++;
          break;
        }
      case SCREEN_CTRLS:
        {
          tft.setTextColor(screenColor);
          tft.setFont(DroidSans_24);
          tft.setCursor(5, 5);
          tft.println("YOU have CONTROL!");
          sprintf(msg, "You've got control!");
          msgChanged = true;
          for (int i = 0; i <= 30; i++) {
            char label[] = {"Back"};
            buttonArray[howManyButtons] = new Button(15 + ((i % 6) * 50), (50 + (i % 5) * 30), 45, 20, label, CTRL_MENU);
            buttonArray[howManyButtons]->setButtonScreen(SCREEN_MENU);
            howManyButtons++;
          }
          break;
        }
    }
  }
}
TS_Point findPoint(int angle, int rad) {
  // Convert angle to radians
  float radianAngle = ((float)angle / 180) * M_PI;
  // X is the adjacent side, so A/H=cos
  float x = cos(radianAngle) * (float)rad;
  // and y is the opposite side
  float y = sin(radianAngle) * (float)rad;
  TS_Point p;
  p.x = x;
  p.y = y;
  return p;
}
//                                                                                                          //////////////
//------------------------------------------------------------------------------------------------   SETUP /

void setup() {

  Serial.begin( 9600 );
  // Audio connections require memory to work
  AudioMemory( 40 );

  delay(1);
  SPI.setMOSI(11);
  SPI.setSCK(13);

  if ( !SerialFlash.begin() )
    Serial.println( "Unable to access SPI Flash chip" );

  sgtl5000_1.enable();
  sgtl5000_1.volume( 0.3 );

  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  tft.begin();
  ts.begin();
  tft.setRotation(1);
  ts.setRotation(3);
  //
  while (!Serial && (millis() <= 1000));

  tft.fillScreen(0xFD80);
  if (currentScreen == SCREEN_TITLE) drawTitleScreen();
  else {
    screenChanged = true;
    sprintf(msg, "Skipping Title Screen");
    updateLEDScreen(msg);

  }

  //  AudioMemory(80);
  //  sgtl5000_1.enable();

  for (int i = 24; i <= 33; i++) {
    pinMode(i, OUTPUT);
  }

  sgtl5000_1.volume(1);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      sprintf(msg, "Unable to access the SD card");
      delay(500);
    }
  }
  delay(1000);
  updateMixerVolume(vol);
  masterMix.gain(0, 1);
  masterMix.gain(3, 1);
  masterMix.gain(1, 1);
  masterMix.gain(2, 1);

  synthDrumArray[0]->setupPattern(5, 7);
  synthDrumArray[1]->setupPattern(5, 3);
  synthDrumArray[2]->setupPattern(2, 2);
  synthDrumArray[3]->setupPattern(2, 2);

  synthWaveArray[0]->setupPattern(3, 9);

  flashArray[0]->setupPattern(5,3);
  flashArray[1]->setupPattern(2,2);
  flashArray[2]->setupPattern(1,3);
  flashArray[3]->setupPattern(2,2);


}
void updateMixerVolume(float v) {
  SDSampleMixer.gain(0, v);
  SDSampleMixer.gain(1, v);
  SDSampleMixer.gain(2, v);
  SDSampleMixer.gain(3, v);
  SynthWaveMixer.gain(0, v);
  SynthWaveMixer.gain(1, v);
  SynthWaveMixer.gain(2, v);
  SynthWaveMixer.gain(3, v);
  SynthDrumMixer.gain(0, v);
  SynthDrumMixer.gain(1, v);
  SynthDrumMixer.gain(2, v);
  SynthDrumMixer.gain(3, v);
}
////*******************************************************************************************************************
////                                                                                              Main loop!
////*******************************************************************************************************************

void loop() {

  pinMode(SDCARD_CS_PIN, OUTPUT);
  digitalWrite(SDCARD_CS_PIN, HIGH);

  pinMode(TFT_CS, OUTPUT);
  digitalWrite(TFT_CS, HIGH);

  pinMode(TS_CS, OUTPUT);
  digitalWrite(TS_CS, HIGH);


//  //----------------------------------------------Audio Loops
    for(int i=0;i<HOW_MANY_SYNTH_DRUMS;i++){
      if(synthDrumArray[i]->sampleIsEnabled()){
        synthDrumArray[i]->synthLoop(bpm);
      }
    }
    for(int i=0;i<HOW_MANY_SYNTH_WAVES;i++){
      if(synthWaveArray[i]->sampleIsEnabled()){
        synthWaveArray[i]->waveLoop(bpm);
      }
    }
    for(int i=0;i<HOW_MANY_FLASH_FILES;i++){
      if(flashArray[i]->sampleIsEnabled()){
        flashArray[i]->flashLoop(bpm);
      }
    }

//  //---------------------------------------------------------------------------Potentiometer  Stuff

  long newFirstKnobPos = (firstKnob.read() / 4);
  long newSecondKnobPos = (secondKnob.read() / 4);
 // if(currentScreen==SCREEN_EDIT_FLASH_PATTERN || currentScreen==SCREEN_EDIT_SYNTH_PATTERN) currentScreen=SCREEN_EDIT_PATTERN;
  switch (currentScreen) {
    case SCREEN_SYSTEM:
      {
        if (newFirstKnobPos != oldFirstKnobPos) {
          if (newFirstKnobPos > oldFirstKnobPos)bpm++;
          else bpm--;
          oldFirstKnobPos = newFirstKnobPos;
          if (bpm > 300) bpm = 300;
          if (bpm <= 1)bpm = 1;
          screenChanged = true;
        }
        if (newSecondKnobPos != oldSecondKnobPos) {
          if (newSecondKnobPos > oldSecondKnobPos) vol++;
          else vol--;
          oldSecondKnobPos = newSecondKnobPos;
          if (vol > 100) vol = 0;
          if (vol < 0) vol = 0;
          updateMixerVolume(vol);
          screenChanged = true;
        }        
        break;
      }
    case SCREEN_INST:
    {     
      if (newSecondKnobPos != oldSecondKnobPos) {
        if (newSecondKnobPos > oldSecondKnobPos) screenInstYShift+=5;
        else screenInstYShift-=5;
        oldSecondKnobPos = newSecondKnobPos;
        screenChanged = true;
      }
      break;
    }
    case SCREEN_EDIT_FLASH_FILE:
    {      
      if (newSecondKnobPos != oldSecondKnobPos) {
        if (newSecondKnobPos > oldSecondKnobPos) screenInstYShift+=5;
        else screenInstYShift-=5;
        oldSecondKnobPos = newSecondKnobPos;
        screenChanged = true;
      }
      break;
    }
    case SCREEN_EDIT_PATTERN:
      {
        patternEditEncoderCode(SYNTHDRUM, newFirstKnobPos, newSecondKnobPos);   
        break;
      }
    case SCREEN_EDIT_FLASH_PATTERN:
      {
        patternEditEncoderCode(FLASHSAMPLE, newFirstKnobPos, newSecondKnobPos);   
        break;
      }
    case SCREEN_EDIT_SYNTH_PATTERN:
      {
        patternEditEncoderCode(SYNTHWAVE, newFirstKnobPos, newSecondKnobPos);   
        break;
      }
    case SCREEN_EDIT_SYNTHDRUM:
      {
        if (newSecondKnobPos != oldSecondKnobPos) {
          const int menu[] = {FREQ_POS, MIX_POS, LNG_POS, PITCH_POS, NOTE_POS, VOL_POS, VERB_POS, COLOR_POS, TRIP_POS};
          int currentPos = 0;
          const int numberOfSettings = 8;
          for (int i = 0; i <= numberOfSettings; i++) {
            if (menu[i] == currentInstEdit) {
              currentPos = i;
              break;
            }
          }
          if (newSecondKnobPos > oldSecondKnobPos) currentPos++;
          else currentPos--;
          oldSecondKnobPos = newSecondKnobPos;
          if (currentPos < 0) currentPos = numberOfSettings;
          if (currentPos > numberOfSettings) currentPos = 0;
          currentInstEdit = menu[currentPos];
          oldSecondKnobPos = newSecondKnobPos;
          screenChanged = true;
        }
        if (newFirstKnobPos != oldFirstKnobPos) {
          switch (currentInstEdit) {
            case (FREQ_POS):
              {
                const float MAX_FREQ = 8000;
                int newValue = synthDrumBeingEdited->getFreq();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += 5;
                else newValue -= 5;
                if (newValue > MAX_FREQ) newValue = MAX_FREQ;
                if (newValue < 16) newValue = 16;
                synthDrumBeingEdited->setFreq(newValue);
                break;
              }
            case (MIX_POS):
              {
                float newValue = synthDrumBeingEdited->getSynthMix();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                synthDrumBeingEdited->setSynthMix(newValue);
                break;
              }
            case (LNG_POS):
              {
                const int MAX_L = 2000;
                int newValue = synthDrumBeingEdited->getSynthLength();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += 5;
                else newValue -= 5;
                if (newValue > MAX_L) newValue = MAX_L;
                if (newValue < 1) newValue = 1;
                synthDrumBeingEdited->setSynthLength(newValue);
                break;
              }
            case (PITCH_POS):
              {
                float newValue = synthDrumBeingEdited->getSynthPitch();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                synthDrumBeingEdited->setSynthPitch(newValue);
                break;
              }
            case (NOTE_POS):
              {
                float newValue = (synthDrumBeingEdited->getNoteType());
                Serial.println("-----");
                Serial.println(newValue);
                if (newValue == SIXTEENTHNOTE) newValue = 1;
                else if (newValue == EIGHTHNOTE) newValue = 2;
                else if (newValue == QUARTERNOTE) newValue = 3;
                else if (newValue == HALFNOTE) newValue = 4;
                else if (newValue == WHOLENOTE) newValue = 5;

                if (newFirstKnobPos > oldFirstKnobPos) newValue++;
                else newValue--;
                if (newValue > 5) newValue = 1;
                if (newValue < 1) newValue = 5;
                float n = WHOLENOTE;
                Serial.println(newValue);
                if (newValue == 4) n = HALFNOTE;
                if (newValue == 3)n = QUARTERNOTE;
                if (newValue == 2)n = EIGHTHNOTE;
                if (newValue == 1)n = SIXTEENTHNOTE;
                synthDrumBeingEdited->setNoteType(n);
                break;
              }
            case (VOL_POS):
              {
                float newValue = synthDrumBeingEdited->getVol();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                synthDrumBeingEdited->setVol(newValue);
                break;
              }
            case (VERB_POS):
              {
                float newValue = synthDrumBeingEdited->getVerb();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                synthDrumBeingEdited->setVerb(newValue);
                break;
              }
            case (COLOR_POS):
              {
                int newValue = synthDrumBeingEdited->getSampleColor();
                if (newFirstKnobPos > oldFirstKnobPos) newValue++;
                else newValue--;
                if (newValue > 33) newValue = 33;
                if (newValue < 24) newValue = 24;
                synthDrumBeingEdited->setSampleColor(newValue);
                break;
              }
            case (TRIP_POS):
              {
                if (synthDrumBeingEdited->getTrip())
                  synthDrumBeingEdited->setTrip(false);
                else synthDrumBeingEdited->setTrip(true);
                break;
              }
          }
          oldFirstKnobPos = newFirstKnobPos;
          screenChanged = true;
        }
        break;
      }
    case SCREEN_EDIT_SYNTHWAVE:
      {
        if (newSecondKnobPos != oldSecondKnobPos) {
          const int menu[] = {FREQ_POS, FORM_POS, LNG_POS, NOTE_POS, VOL_POS, VERB_POS, COLOR_POS, ATTACK_POS, HOLD_POS, DECAY_POS, SUSTAIN_POS, RELEASE_POS };
          int currentPos = 0;
          const int numberOfSettings = 11;
          for (int i = 0; i <= numberOfSettings; i++) {
            if (menu[i] == currentInstEdit) {
              currentPos = i;
              break;
            }
          }
          if (newSecondKnobPos > oldSecondKnobPos) currentPos++;
          else currentPos--;
          oldSecondKnobPos = newSecondKnobPos;
          if (currentPos < 0) currentPos = numberOfSettings;
          if (currentPos > numberOfSettings) currentPos = 0;
          currentInstEdit = menu[currentPos];
          oldSecondKnobPos = newSecondKnobPos;
          screenChanged = true;
        }
        if (newFirstKnobPos != oldFirstKnobPos) {
          switch (currentInstEdit) {
            case (FREQ_POS):
              {
                const float MAX_FREQ = 8000;
                int newValue = synthWaveBeingEdited->getWaveFreq();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += 5;
                else newValue -= 5;
                if (newValue > MAX_FREQ) newValue = MAX_FREQ;
                if (newValue < 16) newValue = 16;
                synthWaveBeingEdited->setWaveFreq(newValue);
                break;
              }
            case (LNG_POS):
              {
                const int MAX_L = 2000;
                int newValue = synthWaveBeingEdited->getSynthWaveLength();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += 5;
                else newValue -= 5;
                if (newValue > MAX_L) newValue = MAX_L;
                if (newValue < 1) newValue = 1;
                synthWaveBeingEdited->setSynthWaveLength(newValue);
                break;
              }
            case (NOTE_POS):
              {
                float newValue = (synthWaveBeingEdited->getNoteType());
                Serial.println("-----");
                Serial.println(newValue);
                if (newValue == SIXTEENTHNOTE) newValue = 1;
                else if (newValue == EIGHTHNOTE) newValue = 2;
                else if (newValue == QUARTERNOTE) newValue = 3;
                else if (newValue == HALFNOTE) newValue = 4;
                else if (newValue == WHOLENOTE) newValue = 5;

                if (newFirstKnobPos > oldFirstKnobPos) newValue++;
                else newValue--;
                if (newValue > 5) newValue = 1;
                if (newValue < 1) newValue = 5;
                float n = WHOLENOTE;
                Serial.println(newValue);
                if (newValue == 4) n = HALFNOTE;
                if (newValue == 3)n = QUARTERNOTE;
                if (newValue == 2)n = EIGHTHNOTE;
                if (newValue == 1)n = SIXTEENTHNOTE;
                synthWaveBeingEdited->setNoteType(n);
                break;
              }
            case (VOL_POS):
              {
                float newValue = synthWaveBeingEdited->getWaveAmp();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                synthWaveBeingEdited->setWaveAmp(newValue);
                break;
              }
            case (VERB_POS):
              {
                float newValue = synthWaveBeingEdited->getVerb();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                synthWaveBeingEdited->setVerb(newValue);
                break;
              }
            case (COLOR_POS):
              {
                int newValue = synthWaveBeingEdited->getSampleColor();
                if (newFirstKnobPos > oldFirstKnobPos) newValue++;
                else newValue--;
                if (newValue > 33) newValue = 33;
                if (newValue < 24) newValue = 24;
                synthWaveBeingEdited->setSampleColor(newValue);
                break;
              }
            case (TRIP_POS):
              {
                if (synthWaveBeingEdited->getTrip())
                  synthWaveBeingEdited->setTrip(false);
                else synthWaveBeingEdited->setTrip(true);
                break;
              }
            case (ATTACK_POS):
              {
                float newValue = synthWaveBeingEdited->getWaveAttack();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .5;
                else newValue -= .5;
                if (newValue > 33) newValue = 33;
                if (newValue < 0) newValue = 0;
                synthWaveBeingEdited->setWaveAttack(newValue);
                break;
              }
            case (HOLD_POS):
              {
                float newValue = synthWaveBeingEdited->getWaveHold();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .5;
                else newValue -= .5;
                if (newValue > 33) newValue = 33;
                if (newValue < 0) newValue = 0;
                synthWaveBeingEdited->setWaveHold(newValue);
                break;
              }
            case (DECAY_POS):
              {
                float newValue = synthWaveBeingEdited->getWaveDecay();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .5;
                else newValue -= .5;
                if (newValue > 100) newValue = 100;
                if (newValue < 0) newValue = 0;
                synthWaveBeingEdited->setWaveDecay(newValue);
                break;
              }
            case (SUSTAIN_POS):
              {
                float newValue = synthWaveBeingEdited->getWaveSustain();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .5;
                else newValue -= .5;
                if (newValue > 33) newValue = 33;
                if (newValue < 0) newValue = 0;
                synthWaveBeingEdited->setWaveSustain(newValue);
                break;
              }
            case (RELEASE_POS):
              {
                float newValue = synthWaveBeingEdited->getWaveRelease();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .5;
                else newValue -= .5;
                if (newValue > 200) newValue = 200;
                if (newValue < 0) newValue = 0;
                synthWaveBeingEdited->setWaveRelease(newValue);
                break;
              }
          }
          oldFirstKnobPos = newFirstKnobPos;
          screenChanged = true;
        }
        break;
      }
      case SCREEN_EDIT_FLASH:
      {
        if (newSecondKnobPos != oldSecondKnobPos) {
          const int menu[] = {NOTE_POS, VOL_POS, VERB_POS, COLOR_POS };
          int currentPos = 0;
          const int numberOfSettings = 4;
          for (int i = 0; i <= numberOfSettings; i++) {
            if (menu[i] == currentInstEdit) {
              currentPos = i;
              break;
            }
          }
          if (newSecondKnobPos > oldSecondKnobPos) currentPos++;
          else currentPos--;
          oldSecondKnobPos = newSecondKnobPos;
          if (currentPos < 0) currentPos = numberOfSettings-1;
          if (currentPos >= numberOfSettings) currentPos = 0;
          currentInstEdit = menu[currentPos];
          oldSecondKnobPos = newSecondKnobPos;
          screenChanged = true;
        }
        if (newFirstKnobPos != oldFirstKnobPos) {
          switch (currentInstEdit) {
            case (NOTE_POS):
              {
                float newValue = (flashSampleBeingEdited->getNoteType());
                Serial.println("-----");
                Serial.println(newValue);
                if (newValue == SIXTEENTHNOTE) newValue = 1;
                else if (newValue == EIGHTHNOTE) newValue = 2;
                else if (newValue == QUARTERNOTE) newValue = 3;
                else if (newValue == HALFNOTE) newValue = 4;
                else if (newValue == WHOLENOTE) newValue = 5;

                if (newFirstKnobPos > oldFirstKnobPos) newValue++;
                else newValue--;
                if (newValue > 5) newValue = 1;
                if (newValue < 1) newValue = 5;
                float n = WHOLENOTE;
                Serial.println(newValue);
                if (newValue == 4) n = HALFNOTE;
                if (newValue == 3)n = QUARTERNOTE;
                if (newValue == 2)n = EIGHTHNOTE;
                if (newValue == 1)n = SIXTEENTHNOTE;
                flashSampleBeingEdited->setNoteType(n);
                break;
              }
            case (VOL_POS):
              {
                float newValue = flashSampleBeingEdited->getVol();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                flashSampleBeingEdited->setVol(newValue);
                break;
              }
            case (VERB_POS):
              {
                float newValue = flashSampleBeingEdited->getVerb();
                if (newFirstKnobPos > oldFirstKnobPos) newValue += .05;
                else newValue -= .05;
                if (newValue > 1.0) newValue = 1.0;
                if (newValue < 0) newValue = 0;
                flashSampleBeingEdited->setVerb(newValue);
                break;
              }
            case (COLOR_POS):
              {
                int newValue = flashSampleBeingEdited->getSampleColor();
                if (newFirstKnobPos > oldFirstKnobPos) newValue++;
                else newValue--;
                if (newValue > 33) newValue = 33;
                if (newValue < 24) newValue = 24;
                flashSampleBeingEdited->setSampleColor(newValue);
                break;
              }
          }
          oldFirstKnobPos = newFirstKnobPos;
          screenChanged = true;
        }
        break;
      }
  }

//  ////--------------------------------------------------------------TouchScreen Stuff
    TS_Point touchCoords;

    if(ts.tirqTouched()){
  
      isTouched = ts.touched();
      touchCoords=ts.getPoint();
      mappedTouch.x = map(touchCoords.x, TS_MINX, TS_MAXX, 0, tft.width());
      mappedTouch.y = map(touchCoords.y, TS_MINY, TS_MAXY, 0, tft.height());
  
      wasTouched=true;
      checkButtons(mappedTouch.x, mappedTouch.y, PRESS);
    }
    else isTouched=false;
    if(wasTouched && !isTouched){
      checkButtons(mappedTouch.x, mappedTouch.y, CLICK);
      wasTouched=false;
    }
  
    if(timeToSynch){
      // Let's try synching all the drums.
      for(int i=0;i<HOW_MANY_SYNTH_DRUMS;i++){
        synthDrumArray[i]->synch();
      }
      timeToSynch=false;
    }
  
    if(screenRefresh>500){
      for(int i=24;i<=33;i++){
        digitalWrite(i,LOW);
      }
      screenRefresh=0;
      updateLEDScreen(msg);
    }
}
void patternEditEncoderCode(int type, long newFirstKnobPos, long newSecondKnobPos){
   if (newFirstKnobPos != oldFirstKnobPos || newSecondKnobPos != oldSecondKnobPos) {
      Serial.println("Here we are.");
      int hits=0;
      int rests=0;
      if (type == SYNTHDRUM) {
        hits=synthDrumBeingEdited->getHits();
        rests=synthDrumBeingEdited->getPatternLength()-hits;
      }
      else if (type == SYNTHWAVE) {
        hits=synthWaveBeingEdited->getHits();          
        rests=synthWaveBeingEdited->getPatternLength()-hits;
      }
      else if (type == FLASHSAMPLE) {
        hits=flashSampleBeingEdited->getHits();
        rests=flashSampleBeingEdited->getPatternLength()-hits;
      }
      //------------------------------------------
      //         Check Left Knob
      //------------------------------------------
      if (newFirstKnobPos != oldFirstKnobPos) {
        if (newFirstKnobPos > oldFirstKnobPos) hits++;
        else hits--;
        oldFirstKnobPos = newFirstKnobPos;
        if (hits<0) hits = 0;
      }
      //------------------------------------------
      //         Check Right Knob
      //------------------------------------------     
      if (newSecondKnobPos != oldSecondKnobPos) {
        if (newSecondKnobPos > oldSecondKnobPos) rests++;
        else rests--;
        oldSecondKnobPos = newSecondKnobPos;        
        if (rests<=0) rests = 0;
      }
      
      if (type == SYNTHDRUM) {
        synthDrumBeingEdited->changePattern(hits,rests); 
      }
      else if (type == SYNTHWAVE) {
        synthWaveBeingEdited->changePattern(hits,rests);
      }
      else if (type == FLASHSAMPLE) {
        flashSampleBeingEdited->changePattern(hits,rests);
      }
      screenChanged = true;
    }
}
//---------------------------------------------------------------------------------------------Check Buttons
void checkButtons(int x, int y, int type) {
  if (currentScreen == SCREEN_TITLE && type == PRESS && titleCounter <= 0) {
    // When we start, we're in the title animation. As long as it's had a chance to
    //run for a bit (titleCounter==0), if there's a PRESS we should go on to the MAIN screen
    currentScreen = SCREEN_MENU;
    screenChanged = true;
  }
  for (int i = 0; i < howManyButtons; i++) {
    if (type == PRESS) {
      if (buttonArray[i]->checkBounds(x, y)) {        // User is touching the screen, inside of this button. Button should (at some point in time) enter "hovered" state
        buttonArray[i]->onHover(true);
      }
      else if (buttonArray[i]->isButtonHovered()) { // User is touching the screen, but not inside this button. This button should return to neutral or enabled, whichever
        buttonArray[i]->onHover(false);
      }
    }
    else if (type == CLICK) {
      if (buttonArray[i]->checkBounds(x, y)) {        // User clicked inside this button. Button should run "onClick()";
        buttonArray[i]->onClick();
      }
      else if (buttonArray[i]->isButtonHovered()) { // User is touching the screen, but not inside this button. This button should return to neutral or enabled, whichever
        buttonArray[i]->onHover(false);
      }
    }
  }
}
word ConvertRGB( byte R, byte G, byte B)
{
  return ( ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3) );
}
void drawTitleScreen() {
  //8, 9, 10, 11, 12, 13, 14, 16, 18, 20, 24
  if (currentLed) digitalWrite(currentLed, LOW);
  currentLed++;
  if (currentLed > 33) currentLed = 24;
  else if (currentLed < 24) currentLed = 24;
  digitalWrite(currentLed, HIGH);

  float y = titleCounter * .1 * 128;
  int titleColor = ConvertRGB(y, y, y);
  if (random(15) == 5)tft.fillScreen(0xFD80);
  tft.setTextColor(titleColor);
  switch (random(5)) {
    case 1:
      tft.setFont(DroidSans_16);
      break;
    case 2:
      tft.setFont(DroidSans_24);
      break;
    case 3:
      tft.setFont(DroidSans_60);
      break;
    case 4:
      tft.setFont(DroidSans_8);
      break;
    case 5:
      tft.setFont(DroidSans_20);
      break;
  }
  tft.setCursor(random(40), random(225));
  tft.println("WELCOME to DRUM");
  screenChanged = true;
  if (titleCounter)titleCounter--;
}
void drawSynthDrumEdit() {      //currentInstEdit=0;
  tft.setTextColor(screenColor);
  tft.setFont(DroidSans_24);
  tft.setCursor(5, 5);
  tft.println("MAKE your DRUM");

  tft.setTextColor(screenColor);
  tft.setFont(DroidSans_12);
  tft.setCursor(5, 35);
  tft.print("NAME: ");
  tft.println(synthDrumBeingEdited->getName());
  int XPos = 5;
  int YPos = 60;
  int buttonW = 150;


  tft.setCursor(XPos, YPos);
  if (currentInstEdit == FREQ_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("FREQ: ");
  tft.println(synthDrumBeingEdited->getFreq());
  YPos += 20;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == MIX_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("5th MIX: ");
  tft.println(synthDrumBeingEdited->getSynthMix());
  YPos += 20;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == LNG_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("LENGTH: ");
  tft.println(synthDrumBeingEdited->getSynthLength());
  YPos += 20;

  char label3[] = {"Edit Pattern"};
  buttonArray[howManyButtons] = new Button(XPos - 5, YPos - 5, buttonW, 20, label3, CTRL_EDIT_PATTERN);
  buttonArray[howManyButtons]->setButtonSynthDrum(synthDrumBeingEdited);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_PATTERN);
  tft.setFont(DroidSans_12);
  howManyButtons++;
  YPos += 20;


  tft.setCursor(XPos, YPos);
  if (currentInstEdit == PITCH_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("PITCH MOD: ");
  tft.println(synthDrumBeingEdited->getSynthPitch());
  YPos += 20;

  XPos = buttonW;
  YPos = 60;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == NOTE_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("NOTE TYPE: ");
  float n = (float)synthDrumBeingEdited->getNoteType();
  char noteName[] = "SIXTEENTHNOTE";
  if (n == 4.0) strcpy(noteName, "Semibreve");
  if (n == 2.0) strcpy(noteName, "Minim");
  if (n == 1.0) strcpy(noteName, "Crotchet");
  if (n == .5) strcpy(noteName, "Quaver");
  if (n == .25) strcpy(noteName, "Semiquaver");
  tft.setFont(DroidSans_8);
  tft.println(noteName);
  tft.setFont(DroidSans_12);
  YPos += 20;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == VOL_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("VOLUME: ");
  tft.println((float)synthDrumBeingEdited->getVol());
  YPos += 20;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == VERB_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.setFont(DroidSans_12);
  tft.print("REVERB: ");
  tft.println((float)synthDrumBeingEdited->getVerb());
  YPos += 20;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == COLOR_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.setFont(DroidSans_12);
  tft.print("COLOR: ");
  int c = synthDrumBeingEdited->getSampleColor();
  switch (c) {
    case (GREEN_LED1): {
        tft.println("Green");
        break;
      }
    case (GREEN_LED2): {
        tft.println("Green 2");
        break;
      }
    case (RED_LED1): {
        tft.println("Red");
        break;
      }
    case (RED_LED2): {
        tft.println("Red 2");
        break;
      }
    case (BLUE_LED1): {
        tft.println("Blue");
        break;
      }
    case (BLUE_LED2): {
        tft.println("Blue 2");
        break;
      }
    case (YELLOW_LED1): {
        tft.println("Amber");
        break;
      }
    case (YELLOW_LED2): {
        tft.println("Amber 2");
        break;
      }
    case (WHITE_LED1): {
        tft.println("White");
        break;
      }
    case (WHITE_LED2): {
        tft.println("White 2");
        break;
      }
  }
  YPos += 20;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == TRIP_POS) {
    tft.fillRect(XPos - 5, YPos - 5, buttonW, 20, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("TRIPLETS: ");
  if (synthDrumBeingEdited->getTrip()) tft.println("ON");
  else tft.println("OFF");
  YPos += 20;

  char label[] = {"Save"};
  buttonArray[howManyButtons] = new Button(0, 170, 45, 20, label, CTRL_SAVE);
  buttonArray[howManyButtons]->setButtonSynthDrum(synthDrumBeingEdited);
  howManyButtons++;
  char label2[] = {"Back"};
  buttonArray[howManyButtons] = new Button(150, 170, 45, 20, label2, CTRL_MENU);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_INST);
  howManyButtons++;
}

// -------------------------------------------------------------------------Synth Wave Edit
void drawSynthWaveEdit() {
  tft.setTextColor(screenColor);
  tft.setFont(DroidSans_24);
  tft.setCursor(5, 5);
  tft.println("MAKE WAVES");
  tft.setFont(DroidSans_8);
  tft.setCursor(5, 35);
  tft.print("NAME: ");
  tft.println(synthWaveBeingEdited->getName());
  int XPos = 5;
  int YPos = 60;
  int buttonW = 150;
  int buttonH = 20;
  tft.setCursor(XPos, YPos);
  if (currentInstEdit == FREQ_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("FREQ: ");
  tft.println(synthWaveBeingEdited->getWaveFreq());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == FORM_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("FORM: ");
  tft.println(synthWaveBeingEdited->getWaveform());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == LNG_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("LENGTH: ");
  tft.println(synthWaveBeingEdited->getSynthWaveLength());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == PLACEHOLDER) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("NOTHING: ");
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == NOTE_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("NOTE TYPE: ");
  tft.println((float)synthWaveBeingEdited->getNoteType());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == VOL_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("VOLUME: ");
  tft.println((float)synthWaveBeingEdited->getWaveAmp());
  YPos += buttonH + 5;

  char label3[] = {"Edit Pattern"};
  buttonArray[howManyButtons] = new Button(XPos, YPos + 1, buttonW, buttonH + 3, label3, CTRL_EDIT_PATTERN);
  buttonArray[howManyButtons]->setButtonSynthWave(synthWaveBeingEdited);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_SYNTH_PATTERN);
  howManyButtons++;
  YPos += buttonH + 5;


  XPos += buttonW + 5;;
  YPos = 60;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == VERB_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("REVERB: ");
  tft.println((float)synthWaveBeingEdited->getVerb());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == COLOR_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("COLOR: ");
  int c = synthWaveBeingEdited->getSampleColor();
  switch (c) {
    case (GREEN_LED1): {
        tft.println("Green");
        break;
      }
    case (GREEN_LED2): {
        tft.println("Green 2");
        break;
      }
    case (RED_LED1): {
        tft.println("Red");
        break;
      }
    case (RED_LED2): {
        tft.println("Red 2");
        break;
      }
    case (BLUE_LED1): {
        tft.println("Blue");
        break;
      }
    case (BLUE_LED2): {
        tft.println("Blue 2");
        break;
      }
    case (YELLOW_LED1): {
        tft.println("Amber");
        break;
      }
    case (YELLOW_LED2): {
        tft.println("Amber 2");
        break;
      }
    case (WHITE_LED1): {
        tft.println("White");
        break;
      }
    case (WHITE_LED2): {
        tft.println("White 2");
        break;
      }
  }
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == ATTACK_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("ATTACK: ");
  tft.println((float)synthWaveBeingEdited->getWaveAttack());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == HOLD_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("HOLD: ");
  tft.println((float)synthWaveBeingEdited->getWaveHold());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == DECAY_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("DECAY: ");
  tft.println((float)synthWaveBeingEdited->getWaveDecay());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == SUSTAIN_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("SUSTAIN: ");
  tft.println((float)synthWaveBeingEdited->getWaveSustain());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == RELEASE_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("RELEASE: ");
  tft.println((float)synthWaveBeingEdited->getWaveRelease());
  YPos += buttonH + 5;

  char label[] = {"Save"};
  buttonArray[howManyButtons] = new Button(0, 200, 45, 20, label, CTRL_SAVE);
  buttonArray[howManyButtons]->setButtonSynthWave(synthWaveBeingEdited);
  howManyButtons++;
  char label2[] = {"Back"};
  buttonArray[howManyButtons] = new Button(150, 200, 45, 20, label2, CTRL_MENU);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_INST);
  howManyButtons++;
}

// -------------------------------------------------------------------------Flash Sample Edit
void drawFlashSampleEdit() {
  tft.setTextColor(screenColor);
  tft.setFont(DroidSans_24);
  tft.setCursor(5, 5);
  tft.println("WHY not SAMPLES!?");
  tft.setFont(DroidSans_8);
  tft.setCursor(5, 35);
  tft.print("NAME: ");
  tft.println(flashSampleBeingEdited->getName());
  int XPos = 5;
  int YPos = 60;
  int buttonW = 150;
  int buttonH = 30;
  tft.setFont(DroidSans_14);

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == NOTE_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("NOTE TYPE: ");
  tft.println((float)flashSampleBeingEdited->getNoteType());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == VOL_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("VOLUME: ");
  tft.println((float)flashSampleBeingEdited->getVol());
  YPos += buttonH + 5;

  char label3[] = {"Edit Pattern"};
  buttonArray[howManyButtons] = new Button(XPos, YPos + 1, buttonW, buttonH + 3, label3, CTRL_EDIT_PATTERN);
  buttonArray[howManyButtons]->setButtonFlashSample(flashSampleBeingEdited);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_FLASH_PATTERN);
  howManyButtons++;
  YPos += buttonH + 5;
  tft.setFont(DroidSans_14);


  XPos += buttonW + 5;;
  YPos = 60;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == VERB_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("REVERB: ");
  tft.println((float)flashSampleBeingEdited->getVerb());
  YPos += buttonH + 5;

  tft.setCursor(XPos, YPos);
  if (currentInstEdit == COLOR_POS) {
    tft.fillRect(XPos, YPos - 4, buttonW, buttonH, screenColor);
    tft.setTextColor(bgColor);
  }
  else tft.setTextColor(screenColor);
  tft.print("COLOR: ");
  int c = flashSampleBeingEdited->getSampleColor();
  switch (c) {
    case (GREEN_LED1): {
        tft.println("Green");
        break;
      }
    case (GREEN_LED2): {
        tft.println("Green 2");
        break;
      }
    case (RED_LED1): {
        tft.println("Red");
        break;
      }
    case (RED_LED2): {
        tft.println("Red 2");
        break;
      }
    case (BLUE_LED1): {
        tft.println("Blue");
        break;
      }
    case (BLUE_LED2): {
        tft.println("Blue 2");
        break;
      }
    case (YELLOW_LED1): {
        tft.println("Amber");
        break;
      }
    case (YELLOW_LED2): {
        tft.println("Amber 2");
        break;
      }
    case (WHITE_LED1): {
        tft.println("White");
        break;
      }
    case (WHITE_LED2): {
        tft.println("White 2");
        break;
      }
  }
  YPos += buttonH + 5;


  char label4[] = {"Edit File"};
  buttonArray[howManyButtons] = new Button(XPos, YPos + 3, buttonW, buttonH + 3, label4, CTRL_EDIT_FILE);
  buttonArray[howManyButtons]->setButtonFlashSample(flashSampleBeingEdited);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_FLASH_FILE);
  howManyButtons++;
  YPos += buttonH + 5;
  tft.setFont(DroidSans_14);

  char label[] = {"Save"};
  buttonArray[howManyButtons] = new Button(0, 200, 45, 20, label, CTRL_SAVE);
  buttonArray[howManyButtons]->setButtonFlashSample(flashSampleBeingEdited);
  howManyButtons++;
  char label2[] = {"Back"};
  buttonArray[howManyButtons] = new Button(150, 200, 45, 20, label2, CTRL_MENU);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_INST);
  howManyButtons++;
}
void drawPatternEdit(int type) {
  tft.setTextColor(screenColor);
  tft.setFont(DroidSans_8);
  tft.setCursor(5, 5);
  tft.println("ALL hail EUCLID!");
  tft.println("ALL hail EUCLID!");
  tft.println("ALL hail EUCLID!");
  tft.println("ALL hail EUCLID!");
  tft.println("ALL hail EUCLID!");
  tft.println("ALL hail EUCLID!");
  tft.println("Use RIGHT knob");
  tft.println("to change HITS!!");
  tft.println("Use LEFT knob");
  tft.println("to change RESTS!");
  int rad = 100;
  int dotRad = 20;
  int interiorRad = 80;
  int dia = 2 * rad;
  int centerX = 300 - dia + rad;
  int centerY = rad;
  tft.drawRect(300 - dia, 0, dia, dia, screenColor);
  tft.drawCircle(centerX, centerY, rad, screenColor);
  int patternSize = 0;
  currentType=type;
  Serial.println(type);
  if (type == FLASHSAMPLE) {
    Serial.print("name=");
    Serial.print(flashSampleBeingEdited->getName());
  }
  
  if (type == SYNTHDRUM) patternSize = synthDrumBeingEdited->getPatternLength(); //(i.e., number of dots, i.e. beats + rests)
  else if (type == SYNTHWAVE)patternSize = synthWaveBeingEdited->getPatternLength(); //(i.e., number of dots, i.e. beats + rests)
  else if (type == FLASHSAMPLE)patternSize = flashSampleBeingEdited->getPatternLength(); //(i.e., number of dots, i.e. beats + rests)
  if (patternSize >= 10) {
    dotRad = 15;
  }
  else if (patternSize >= 20) {
    dotRad = 10;
  }
  else if (patternSize >= 25) {
    dotRad = 5;
  }
  tft.drawCircle(centerX, centerY, interiorRad, screenColor); // Draw Inner Circle / Track
  // Draw pattern Circles
  for (int i = 0; i < patternSize; i++) {
    float slice = 360 / patternSize;
    TS_Point p = findPoint(slice * i, 80);
    tft.drawCircle(centerX + p.x, centerY + p.y, dotRad, screenColor);

    int pat = 0;
    if (type == SYNTHDRUM) pat = synthDrumBeingEdited->getPatternAt(i);
    else if (type == SYNTHWAVE)pat = synthWaveBeingEdited->getPatternAt(i);
    else if (type == FLASHSAMPLE)pat = flashSampleBeingEdited->getPatternAt(i);

    if (pat) tft.fillCircle(centerX + p.x, centerY + p.y, dotRad, screenColor);
    else tft.fillCircle(centerX + p.x, centerY + p.y, dotRad - 1, bgColor);
    char blankLabel[] = {""};
    buttonArray[howManyButtons] = new Button((centerX + p.x) - dotRad, (centerY + p.y) - dotRad, dotRad * 2, dotRad * 2, blankLabel, CTRL_FLIP_PATTERN);
    if (type == SYNTHDRUM) buttonArray[howManyButtons]->setButtonSynthDrum(synthDrumBeingEdited);
    else if (type == SYNTHWAVE) buttonArray[howManyButtons]->setButtonSynthWave(synthWaveBeingEdited);
    else if (type == FLASHSAMPLE) buttonArray[howManyButtons]->setButtonFlashSample(flashSampleBeingEdited);
    buttonArray[howManyButtons]->setButtonPatternNum(i);
    howManyButtons++;
  }
  msgChanged = true;
  char label[] = {"Back"};
  if (type == SYNTHDRUM) {
    buttonArray[howManyButtons] = new Button(0, 150, 45, 30, label, CTRL_EDIT_SYNTHDRUM);
    buttonArray[howManyButtons]->setButtonSynthDrum(synthDrumBeingEdited);
    buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_SYNTHDRUM);
    howManyButtons++;
  }
  else if (type == SYNTHWAVE) {
    buttonArray[howManyButtons] = new Button(0, 150, 45, 30, label, CTRL_EDIT_SYNTHWAVE);
    buttonArray[howManyButtons]->setButtonSynthWave(synthWaveBeingEdited);
    buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_SYNTHWAVE);
    howManyButtons++;
  }
  else if (type == FLASHSAMPLE) {
    buttonArray[howManyButtons] = new Button(0, 150, 45, 30, label, CTRL_EDIT_FLASH);
    buttonArray[howManyButtons]->setButtonFlashSample(flashSampleBeingEdited);
    buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_FLASH);
    howManyButtons++;
  }
}

void drawFlashFiles(){

  howManyButtons=0;
//  screenInstYShift=0;
  Serial.print("Just double-cheking that the current dir is: ");
  Serial.println(flashSampleBeingEdited->getCurrentDir().name());      // If this is RAW, change the next line to be currentDir instead
  File dir = SD.open("/RAW"); 
  printDirectory(dir);
  char label2[] = {"Cancel"};
  buttonArray[howManyButtons] = new Button(250, 10, 45, 20, label2, CTRL_MENU);
  buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_FLASH);
  buttonArray[howManyButtons]->setButtonFlashSample(flashSampleBeingEdited);   
  howManyButtons++;

  if(1){    // Make sure that a file to load has been selected
    char label3[] = {"Load"};
    buttonArray[howManyButtons] = new Button(150, 10, 45, 20, label3, CTRL_LOAD_FILE);
    buttonArray[howManyButtons]->setButtonScreen(SCREEN_EDIT_FLASH);
    buttonArray[howManyButtons]->setButtonFlashSample(flashSampleBeingEdited);
    howManyButtons++;
  }
}
void printDirectory(File dir) {
    
  tft.fillRect(0,0,320,30, bgColor);
  tft.setTextColor(screenColor);
  tft.setFont(DroidSans_8);
  tft.setCursor(5, 5);
  tft.print("Sample: ");
  tft.print(currentlySelectedFile.name());
  const int BUTTON_WIDTH = 100;
  const int BUTTON_HEIGHT = 30;
  const int BUTTON_Y_START = 35;
  const int BUTTON_X_START = 5;
  int XPos=BUTTON_X_START;
  int YPos=BUTTON_Y_START;
  int col=1;
  
   while(true) {   
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //Serial.println("**nomorefiles**");
       break;
     }
     Serial.print(entry.name());
      char label[12];
      strcpy(label,entry.name());
      buttonArray[howManyButtons] = new Button(XPos, YPos + screenInstYShift, BUTTON_WIDTH, BUTTON_HEIGHT + 3, label, CTRL_SELECT_FILE);
      buttonArray[howManyButtons]->setButtonFile(entry, playSDRaw);
      howManyButtons++;
     entry.close();
     if(col==1){
        XPos=BUTTON_X_START+BUTTON_WIDTH + 5;
        col=2;
     }
     else if(col==2){
        XPos=BUTTON_X_START+BUTTON_WIDTH +BUTTON_WIDTH + 10;
        col=3;
     }
     else{
        XPos=BUTTON_X_START;
        YPos+=BUTTON_HEIGHT+5;
        col=1;
     }
   }
}
