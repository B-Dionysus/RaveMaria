#include "Arduino.h"
#include "Button_BAD.h"
Button::Button(int xi, int yi, int lngi, int hgti, char *labeli, int type, int fontSize){
    setup(xi, yi, lngi, hgti, labeli, type, fontSize);
  }
void Button::setup(int xi, int yi, int lngi, int hgti, char *labeli, int type, int fontSize){
  setButtonX(xi);
  setButtonY(yi);
  setButtonHgt(hgti);
  setButtonLng(lngi);
  setButtonLabel(labeli);
  _fontSize=fontSize;
  _borderColor=screenColor;
  _buttonType=type;
  
  if(_buttonType!=CTRL_FLIP_PATTERN){
    tft.setTextColor(screenColor);
    tft.drawRect(x,y,lng,hgt, _borderColor);
    tft.setFont(DroidSans_8);
    tft.setCursor(x+5, y+5);
    // It can't be a pointer because as soon as the creating function end the array that is being pointed to will be destroyed!!!!!!!!!
    strcpy(_label,labeli);
    tft.print(_label);
  }
}
void Button::onHover(bool hovering){
  if(hovering){    // If the user is hovering over a button that's not enabled, set it to hovered status
    if(_hoverTime>2000) _hoverTime=0;   // Only if the user hover over a button for at least a second (i.e. long presses)
    else if(_hoverTime>1000){
      _hovered=true;    
      if(getButtonType()!=CTRL_FLIP_PATTERN){
        tft.fillRect(x,y,lng,hgt, _hoveredColor);
        tft.setTextColor(bgColor);
        tft.setCursor(x+5, y+5);
        tft.print(_label); 
      } 
      if(getButtonType()==CTRL_SELECT_FILE){
        currentlySelectedFile=_file;
        screenChanged=true;
      }
    }
  }
  else if(!hovering){               // If the user is no longer hovering over this button, return it to whatever status it used to have
    _hovered=false;
    _hoverTime=3000;
    if(isButtonEnabled()){
      enableButton();
    }
    else{
      restoreNeutralButton();
    }
  }
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - onClick!!!
void Button::onClick(){
 _hoverTime=3000;
 if(safelyDebounced()){
    if(getButtonType()==CTRL_MENU){
      currentScreen=getButtonScreen();
      screenChanged=true;
    }
    if(getButtonType()==CTRL_EDIT_FILE){
      currentScreen=getButtonScreen();
      screenChanged=true;
      flashSampleBeingEdited=_flash;
    }
    if(getButtonType()==CTRL_EDIT_SYNTHDRUM){
      currentScreen=getButtonScreen();
      screenChanged=true;
      synthDrumBeingEdited=_synthDrum;
    }
    if(getButtonType()==CTRL_EDIT_SYNTHWAVE){
      currentScreen=getButtonScreen();
      screenChanged=true;
      synthWaveBeingEdited=_synthWave;
    }
    if(getButtonType()==CTRL_EDIT_FLASH){
      currentScreen=getButtonScreen();
      screenChanged=true;
      flashSampleBeingEdited=_flash;
    }
    if(getButtonType()==CTRL_EDIT_PATTERN){
      currentScreen=getButtonScreen();
      screenChanged=true;
      synthDrumBeingEdited=_synthDrum;
    }
    if(getButtonType()==CTRL_LOAD_FILE){
      currentScreen=getButtonScreen();
      screenChanged=true;
      Serial.println("Here");
      flashSampleBeingEdited=_flash;
      _flash->loadSample(currentlySelectedFile.name());      
    }
    else if(getButtonType()==CTRL_INST){      
      if(isButtonEnabled()){
        restoreNeutralButton();        
        if(_instType==SYNTHDRUM) _synthDrum->enableSample(false);
        else if(_instType==SYNTHWAVE){
          _synthWave->enableSample(false);
          _synthWave->stopPlaying();
        }
        else if(_instType==FLASHSAMPLE){
          _flash->enableSample(false);
        }
      } 
      else{    
        enableButton();     
        if(_instType==SYNTHDRUM) _synthDrum->enableSample(true);
        else if(_instType==SYNTHWAVE) _synthWave->enableSample(true);
        else if(_instType==FLASHSAMPLE) _flash->enableSample(true);
        timeToSynch=true;
      }
    }
    else if(getButtonType()==CTRL_SAVE){
      synthDrumBeingEdited->saveDrum();
    }
    else if(getButtonType()==CTRL_SYNCH){
      timeToSynch=true;
    }
    else if(getButtonType()==CTRL_LED){
      if(currentLed){
        digitalWrite(currentLed,LOW);
      }
      currentLed++;
      if(currentLed>33) currentLed=24;
      digitalWrite(currentLed,HIGH);
      sprintf(msg,"LED pin active= %i",currentLed);
      msgChanged=true;
    }
    else if(getButtonType()==CTRL_FLIP_PATTERN){
      if(_instType==SYNTHDRUM) _synthDrum->flipPatternAt(_patternNum);   
      else if(_instType==SYNTHWAVE) _synthWave->flipPatternAt(_patternNum);
      else if(_instType==FLASHSAMPLE) _flash->flipPatternAt(_patternNum);
      screenChanged=true;
    }
    else if(getButtonType()==CTRL_SELECT_FILE){
            

      char f[20];
      sprintf(f, "/RAW/%s",_file.name());
      Serial.println(f);
      playSDRaw.play(f);
    }
  }
}
void Button::restoreNeutralButton(){
  _enabled=false;
  _hovered=false;
  _hoverTime=3000;
  if(getButtonType()!=CTRL_FLIP_PATTERN){
    tft.fillRect(x,y,lng,hgt, bgColor);    
    tft.drawRect(x,y,lng,hgt, screenColor);    
    tft.setTextColor(screenColor);
    tft.setCursor(x+5, y+5);  
    tft.setFont(DroidSans_8);
    char t[100];
    strcpy(t,getButtonLabel());
    tft.print(_label);  
  }
}
void Button::enableButton(){
  _enabled=true;
  _hovered=false;
  tft.fillRect(x,y,lng,hgt, _enabledColor);
  tft.setTextColor(bgColor);
  tft.setFont(DroidSans_8);
  tft.setCursor(x+5, y+5);
  tft.print(_label);
}
bool Button::isButtonEnabled(){
  return _enabled;
}
bool Button::isButtonHovered(){
  return _hovered;
}

void Button::setButtonScreen(int screen){
  _screen=screen;
}
int Button::getButtonId(){
  return _id;
}
int Button::getButtonScreen(){
  return _screen;
}
int Button::getNum(){
  return _testNum;
}
void Button::setNum(int num){
  _testNum=num;
}
void Button::setButtonPatternNum(int num){
  _patternNum=num;
}
bool Button::safelyDebounced(){
  if(_debounceTime<DEBOUNCEDELAY){
    return false;
  }
  else{
    _debounceTime=0;
    return true;
  }
}
int Button::getButtonHeight(){
  return hgt;
}
int Button::getButtonLength(){
  return lng;
}
int Button::getButtonX(){
  return x;
}
int Button::getButtonY(){
  return y;
}
void Button::setButtonX(int i){
  x=i;
}
void Button::setButtonY(int i){
  y=i;
}
void Button::setButtonLng(int i){
  lng=i;
}
void Button::setButtonHgt(int i){
  hgt=i;
}//===================================================================== Set Label
void Button::setButtonLabel(char *i){
  strcpy(_label,i);
}
char* Button::getButtonLabel(){
  return _label;  
}
int Button::getButtonType(){
  return _buttonType;
}

bool Button::checkBounds(int a, int b){
  // Are x and y within this button's boundaries?
  if(a>x && a<(x+lng)){
    // It's within the width!
    if(b>y && b<(y+hgt)){
      // It's also within the height!
      return true;
    }
    else return false;
  }
  else return false;
}
void Button::setButtonSynthDrum(SynthDrum * inst){
  _synthDrum=inst;  
  if(_buttonType==CTRL_INST) setButtonLabel(inst->getName());
  if(inst->sampleIsEnabled() && getButtonType()==CTRL_INST) enableButton();
  else restoreNeutralButton();
  _instType=SYNTHDRUM;
}
void Button::setButtonSynthWave(SynthWave * inst){
  _synthWave=inst;  
  if(_buttonType==CTRL_INST) setButtonLabel(inst->getName());
  if(inst->sampleIsEnabled() && getButtonType()==CTRL_INST) enableButton();
  else restoreNeutralButton();
  _instType=SYNTHWAVE;
}
void Button::setButtonFlashSample(FlashSample * inst){
  _flash=inst;  
  if(_buttonType==CTRL_INST) setButtonLabel(inst->getName());
  if(inst->sampleIsEnabled() && getButtonType()==CTRL_INST) enableButton();
  else restoreNeutralButton();
  _instType=FLASHSAMPLE;
}
void Button::setButtonFile(File f, AudioPlaySdRaw sd){
  Serial.print("Setting ");
  Serial.println(f.name());
  _file=f;
}
