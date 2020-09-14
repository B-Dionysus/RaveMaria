#include "Arduino.h"
#include "Sample.h"

//*******************************************************************************************************************
//*******************************************************************************************************************
//*                                                                                             Sample Class
//*******************************************************************************************************************
//*******************************************************************************************************************
//Sample::Sample(){}
void Sample::setupSample(){Serial.print("Hey, it's the wrong setup!!");}
void Sample::changePattern(int hits, int rests){
  _patternLength=hits+rests;
  _pattern=findBeats(hits,rests);
//  Serial.print("The new pattern is: ");
//  Serial.println(_pattern, BIN);
  printPattern(_pattern,_isInverted, _patternLength);
}

void Sample::setupPattern(int beats, int rests){
  changePattern(beats, rests);
}  
int Sample::getId(){
  return _id;
}
void Sample::setVol(float v){
  _volume=v;  
  _amp->gain(v);
}
float Sample::getVol(){
  return _volume;
}
void Sample::setVerb(float v){
  _roomSize=v;  
  _reverb->roomsize(v);
  _reverb->damping(0);  
}
int Sample::getSampleColor(){
  return _color;
}
void Sample::setSampleColor(int x){
  if(x<24 || x>33){
    x=24;
//  sprintf(msg,"Incorrect Color Value");
//  msgChanged=true;
  }
  _color=x;
}
float Sample::getVerb(){
  return _roomSize;
}
bool Sample::getTrip(){
  return _triplets;
}
void Sample::setTrip(bool t){
  _triplets=t;
}
void Sample::setInternalBPM(int bpm){
  _bpm=bpm;
}
int Sample::getInternalBPM(){
  return _bpm;
}
int Sample::getPatternLength(){
  return _patternLength;
}
int Sample::getPatternAt(int x){
  return nowIsTheTimeToParty(x);
}
float Sample::getNoteType(){
  return _noteType;
}
void Sample::setNoteType(float n){
  _noteType=n;
}
void Sample::flipPatternAt(int pos){
  int mask=1;
  int i=_patternLength-pos-1;
  Serial.print("pattern = ");
  Serial.println(_pattern,BIN);

  mask=mask<<i;
  _pattern=_pattern^mask;
  Serial.print("mask = ");
  Serial.println(mask,BIN);
  Serial.print("new Pattern = ");
  Serial.println(_pattern,BIN);
}
int Sample::nowIsTheTimeToParty(int pos){
  /*    So, pattern 1101001, pos 0 = 1, pos 1=1, pos 2=0
   *    for pos 2, shift it left length-pos (5) = 11 and then just BITWISE AND 1       */
  int p=_pattern>>((_patternLength-1)-pos);
 int x=p&1;
 if(!_isInverted) x=x^1; // Got confused with the inverting, so if it *isn't* inverted, we flip the bit here
 return x;
  // See, I'm told that bitwise AND return 0 if the rightmost digit is 0, and 1 if 1. I'm told.      
}
//virtual void Sample::thenLetsParty(){}
  
int Sample::findBeats(int beats, int rests){
  if(rests==0){
    Serial.println("Nothing but hits!");
    _isInverted=1;
    _patternLength=beats;
    int x= pow(2,(beats+1))-1;
    Serial.println(x, BIN);
    return x;
  }
  else if(beats==0){
    Serial.println("Rests only");
    _isInverted=0;
    _patternLength=rests;
    int x =pow(2,(rests+1))-1;
    Serial.println(x, BIN);
    return x;
  }
  else{
    Serial.print(beats); Serial.print(" beats and "); Serial.print(rests); Serial.println(" rests.");
    Serial.print("This pattern is called '");
    Serial.print(findPatternName(beats,rests));
    Serial.println("'.");
    _isInverted=0;
    _patternLength=beats+rests;
    int large=rests;
    int sm=beats;
    if(beats>rests){
      _isInverted=1;
      large=beats;
      sm=rests;
    }
    int bigArray[large];
    int smallArray[sm];
    //Make two arrays, a big one and a little. Fill the big one with the specified number of beats or rests (1 or ) 
    //Depending on which one there is more of.
    int r=0;
    for(int i=0;i<large;i++){
        bigArray[i]=1;
      if(r<sm) smallArray[r]=0;
      r++;
    }
  // Serial.println("here we go");
    // The euclid function ultimately squeezes the two arrays together according to Euclids GCF algorhythm 
    // MaxRuns (starting at 20) prevents the recursive function from looping forever.
    int x=euclid(beats,rests,bigArray, smallArray, 20);
    return x;
  }
}  
int Sample::euclid(int beats, int rests, int bigArray[], int smallArray[], int maxRuns){
  int big=beats;
  int small=rests;
  if(beats<rests){ 
    big=rests;
    small=beats;
  }  
  int remainder=big - small;
  // Ok, we have an array, bigArray, of arrays of 1s and 0s
  // And we have a smaller array, 
  int newBigArray[small];
  for(int i=0;i<small;i++){
    // Start with bigArray=[1][1][1] or whatever and smallArray=[0][0][0]
    // and end with newBigArray=[10][10][10] somehow
    newBigArray[i]=bigArray[i];
    int t=smallArray[i];
    while(t>1){
      newBigArray[i]=newBigArray[i]<<1;
      t=t>>1;
    }
    newBigArray[i]=newBigArray[i]<<1;
    newBigArray[i]=newBigArray[i] | smallArray[i];
  }    
  if(remainder==0 || maxRuns<=0) {
    for(int i=1;i<(small);i++){
      // Starting with the element in [1]
      int t=newBigArray[i];
      // We go through and count down the number of digits, shifting [i]
      while(t>1){
        newBigArray[0]=newBigArray[0]<<1;      
        t=t>>1;
      }
      newBigArray[0]=newBigArray[0]<<1;
      newBigArray[0]=newBigArray[0] | newBigArray[i];
    }
    return newBigArray[0];
  }
  else{
   int newSmallArray[remainder];
    for(int i=0;i<remainder;i++){    
      newSmallArray[i]=bigArray[small+i];
    }
    if(remainder>small){ //i.e., if small array is larger than bigArray
      return euclid(remainder, small, newSmallArray, newBigArray, maxRuns-1);
    }
    else{ 
      return euclid(small, remainder, newBigArray, newSmallArray, maxRuns-1);
    }
  }
}
void Sample::synch(){
  _myInternalClock=0;
}
void Sample::printPattern(int p, int inverted, int pl){
  const char* a=".";
  const char *b="X";
  if(inverted){
    a="X";
    b=".";
  }  
  int j=p;
  for(int i=pl-1;i>=0;i--){
      // Shift the pattern to the left by its length-1
      j=p>>i;
      if(j&1) Serial.print(a);
      else Serial.print(b);
  }
  Serial.println("     <------ Ta da!!!");
}
int Sample::getHits(){
  int p=_pattern;
  int pl=_patternLength;
  int j=p;
  int hits=0;
  for(int i=pl-1;i>=0;i--){
      // Shift the pattern to the left by its length-1
      j=p>>i;
      if(j&1) {
        if(_isInverted) hits++;
      }
      else {
        if(!_isInverted) hits++;
      }
  }
  Serial.print(hits);
  Serial.println(" hits.");
  return hits;
}
const char* Sample::findPatternName(int a, int b){
  b=b+a;
  if(a==4 && b==12) return "Fandango";
  else if(a==2 && b==3) return "Swing Tumbao";
  else if(a==2 && b==5) return "Khafif-e-ramal";
  else if(a==3 && b==4) return "Cumbia";
  else if(a==3 && b==5) return "Khalif-e-ramal";
  else if(a==3 && b==7) return "Ruchenitza";
  else if(a==3 && b==8) return "Tresillo";
  else return "Something cool.";
}
  

bool Sample::sampleIsEnabled(){
  return _enabled;
}
void Sample::enableSample(bool a){
  _enabled=a;
}
//*******************************************************************************************************************
//*******************************************************************************************************************
//                                                                                          Flash SAMPLE!!!
//*******************************************************************************************************************
//*******************************************************************************************************************
FlashSample::FlashSample(const char *dn,const char *sn, float noteType,AudioPlaySerialflashRaw *flash,AudioAmplifier *amp,AudioEffectFreeverb *verb, int bpm, int objects, int startTime, int endTime){
  _noteType=noteType;
  _bpm=bpm;
  _id=random(100);
  _flash=flash;
  _amp=amp;
  _reverb=verb;
  sprintf(_name,sn);
  _currentDir=loadDir(dn);
  loadSample(sn);
  
  //_flash->play(_sampleName);
  enableSample(false);
  setVol(.5);
  setVerb(0);
  setupPattern(2,2);
  _color=random(24,34);
}
File FlashSample::getCurrentDir(){
  return _currentDir;
}
File FlashSample::loadDir(const char* dir){
  SD.begin(SDCARD_CS_PIN);
  Serial.println(dir);
  File myFile;
  if(myFile=SD.open(dir)){
    Serial.print("Directory: ");Serial.println(myFile.name());
    return myFile;    
  }
  else Serial.println("Unable to access directory");
}
//                                                                            =================================
//                                                                            ==         LOAD SAMPLE!        ==
//                                                                            =================================
void FlashSample::loadSample(const char* sampleName){
  setName(sampleName);
  pinMode(SDCARD_CS_PIN, OUTPUT);
  digitalWrite(SDCARD_CS_PIN, HIGH);
  
  pinMode(14, OUTPUT);                        // r3eplace with defined terms instead!!!
  digitalWrite(14, HIGH);
  
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  
  delay(1);

  // Open the file on the SD card  
  SD.begin(SDCARD_CS_PIN);
  File myFile;
  sprintf(_fullSamplePath, "/%s/%s",_currentDir.name(),sampleName);
      Serial.print("Name 1: ");Serial.println(_fullSamplePath);          
  myFile=SD.open(_fullSamplePath);
  if(! myFile){
    Serial.println("Can't open file on SD card");
    return;
  }
  else{
    SerialFlash.begin(FLASH_CS);
    // Check to see if it is already on the flash chip
    Serial.print("Checking ");
    Serial.println(sampleName);
    if (SerialFlash.exists(sampleName)) {
      SerialFlashFile ff = SerialFlash.open(sampleName);
      // Is this the same file? Is it the same length, for example?
      if (ff && ff.size() == myFile.size()) {  
        if (compareFiles(myFile, ff) == true) {
          Serial.println("  File is already on flash chip.");
          myFile.close();
          _currentSample=ff;
        }
        else{
          Serial.println("There is a file with this name on the flash chip already, but it is a different file.");
          _currentSample=copyFileToFlash(myFile, sampleName, true);
        }
      }
      else{        
          Serial.println("There is a file with this name on the flash chip already, but it is a different file.");          
          _currentSample=copyFileToFlash(myFile, sampleName, true);
      }
    }
    else{
      Serial.println("This file is not (yet!) present on the flash chip.");      
      _currentSample=copyFileToFlash(myFile, sampleName, false);
    }
  }
}
SerialFlashFile FlashSample::copyFileToFlash(File f, const char* fileName, bool shouldIDelete){  
  if(shouldIDelete){
    // delete the old, incorrect copy on the Flash chip
    Serial.println("  delete file from Flash chip");
    SerialFlash.remove(fileName);
  }  
        // create the file on the Flash chip and copy data
  
//  SerialFlash.begin(FLASH_CS);
  unsigned long length = f.size();
  Serial.print("Size = ");
  Serial.println(length);
  if (SerialFlash.create(fileName, length)) {
    SerialFlashFile ff = SerialFlash.open(fileName);
    if (ff) {
      Serial.print("  copying");
      // copy data loop
      unsigned long count = 0;
      unsigned char dotcount = 9;
      while (count < length) {
        char buf[256];
        unsigned int n;
        n = f.read(buf, 256);
        ff.write(buf, n);
        count = count + n;
        Serial.print(".");
        if (++dotcount > 100) {
          Serial.println();
          dotcount = 0;
        }
      }
      return(ff);
      if (dotcount > 0) Serial.println();
    }
    else {
      Serial.println("  error opening freshly created file!");
      return ff;
    }
  }
  else {
     Serial.println("  unable to create file");
  }
  SerialFlashFile error;
  return error;
}
bool FlashSample::compareFiles(File &file, SerialFlashFile &ffile) {
  file.seek(0);
  ffile.seek(0);
  unsigned long count = file.size();
  while (count > 0) {
    char buf1[128], buf2[128];
    unsigned long n = count;
    if (n > 128) n = 128;
    file.read(buf1, n);
    ffile.read(buf2, n);
    if (memcmp(buf1, buf2, n) != 0) return false; // differ
    count = count - n;
  }
  return true;  // all data identical
}
void FlashSample::setName(char* n){
  strcpy(_name,n);
}
char* FlashSample::getName(){
  return _name;
}
void FlashSample::flashLoop(int bpm){
  float n=_noteType;
  if(getTrip()) n=n*.66;// If triplets are enabled, play everything 2/3s as slow. Er, 1.5 times faster. You know what I mean.
  if(_myInternalClock>=(n*(60000/bpm))){
    _myInternalClock=0;
    // e.g., an eighthnote at 120 bpm should play every 250 milliseconds, which is 4 times a secon or 240 times a minute
    _change=0;    
    if(nowIsTheTimeToParty(_patternPosition)){
      thenLetsParty();
    }
    _patternPosition++;
    if(_patternPosition>(_patternLength-1)) _patternPosition=0;
  }
  if(_myInternalClock>=((_noteType/2)*(60000/bpm))){    
      digitalWrite(_color,LOW);
  }
}
void FlashSample::thenLetsParty(){  
//                      #define SDCARD_CS_PIN    10
//                      #define SDCARD_MOSI_PIN  11
//                      #define SDCARD_SCK_PIN   13
//                      const int SD_CS_Pin = 10;
//                      const int Display_CS_Pin = 14;
//                      const int Touch_CS_Pin = 8;
//                      const int FlashChipSelect = 6; // digital pin for flash chip CS pin

  digitalWrite(_color,HIGH);
  _flash->play( _name );

}   


void FlashSample::listFiles() {
  #define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13
const int SD_CS_Pin = 10;
const int Display_CS_Pin = 14;
const int Touch_CS_Pin = 8;
const int FlashChipSelect = 6; // digital pin for flash chip CS pin
//const int FlashChipSelect = 21; // Arduino 101 built-in SPI Flash
  //uncomment these if using Teensy audio shield
  SPI.setSCK(SDCARD_SCK_PIN);  // Audio shield has SCK on pin 14
  SPI.setMOSI(SDCARD_MOSI_PIN);  // Audio shield has MOSI on pin 7

  pinMode(Touch_CS_Pin, OUTPUT);
  digitalWrite(Touch_CS_Pin, HIGH);
//  
  delay(1);

    SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
//  if (!(SD.begin(SD_CS_Pin))) {
//    while (1) {
//      Serial.println("Unable to access the SD card!!");
//      delay(500);
//    }
//  }
  Serial.begin(9600);

  // wait for Arduino Serial Monitor
  while (!Serial) ;
  delay(100);
  Serial.println("All Files on SPI Flash chip:");

  if (!SerialFlash.begin(FlashChipSelect)) {
    Serial.println("Unable to access SPI Flash chip");
  }

  SerialFlash.opendir();
  while (1) {
    char filename[64];
    uint32_t filesize;

    if (SerialFlash.readdir(filename, sizeof(filename), filesize)) {
      Serial.print("  ");
      Serial.print(filename);
      //spaces(20 - strlen(filename));
      Serial.print("  ");
      Serial.print(filesize);
      Serial.print(" bytes");
      Serial.println();
    } else {
      break; // no more files
    }
  }
}
////*******************************************************************************************************************
////*******************************************************************************************************************
////                                                                                          SD SAMPLE!!!
////*******************************************************************************************************************
////*******************************************************************************************************************
//int SDSample::setupSample(const char *dn,const char *sn,float n, int beats, int rests, AudioPlaySdWav playSD, int bpm, int raw, int objects){
//  _playSD=playSD;
//  _sampleName=sn;
////  strcpy(_name,sn);
//  _noteType=n;
//  changePattern(beats, rests);
//  _currentDir=loadDir(dn);
//  _currentSample=loadSample(sn);
//  _bpm=bpm;
//  _isItRaw=raw;
//  _id=objects;
//  return objects+1;  
//}
//File SDSample::loadDir(const char* dir){
//  Serial.println(dir);
//  File myFile;
//  myFile=SD.open(dir);
//  Serial.print("Directory: ");Serial.println(myFile.name());
//  return myFile;    
//}
//File SDSample::loadSample(const char* sampleName){
//  File myFile;
//  sprintf(_fullSamplePath, "/%s/%s",_currentDir.name(),_sampleName);
//      Serial.print("Name 1: ");Serial.println(_fullSamplePath);          
//  myFile=SD.open(_fullSamplePath);
//  if(! myFile){
//    Serial.println("Can't open file");
//    return myFile;
//  }
//  else{
//    return myFile;
//  }
//}
//void SDSample::thenLetsParty(){  
//  Serial.println("Partying?!");  
//  if(_isItRaw){
//    delay(30);
//    _playSD.play(_fullSamplePath);
//  }
//  else _playSD.play(_fullSamplePath);
//}   
//*******************************************************************************************************************
//*******************************************************************************************************************
//                                                                                          Synth Drum!!!
//*******************************************************************************************************************
//*******************************************************************************************************************
SynthDrum::SynthDrum(int f, int l, float m, float p, float n, AudioSynthSimpleDrum *drum, AudioAmplifier *amp, AudioEffectFreeverb *verb, int bpm, int objects){
  _noteType=n;
  _bpm=bpm;
  _id=random(100);
  _drum=drum;
  _amp=amp;
  _reverb=verb;
  sprintf(_name,"Drum_%i",(int)random(1000));
  setFreq(f);
  setSynthLength(l);
  setSynthMix(m);
  setSynthPitch(p);
  setVol(.5);
  setVerb(0);
  setupPattern(2,2);
  _color=random(24,34);
}

void SynthDrum::setSynthMix(float m){
  _mix=m;
  _drum->secondMix(m);
}
void SynthDrum::setSynthPitch(float p){
  _pitch=p;
  _drum->pitchMod(p);
}
float SynthDrum::getSynthMix(){
  return _mix;
}
float SynthDrum::getSynthPitch(){
  return _pitch;
}
void SynthDrum::setFreq(int f){
  _freq=f;
  Serial.println(f);
  _drum->frequency(f);
}
int SynthDrum::getFreq(){
  return _freq;
}
void SynthDrum::setSynthLength(int l){
  _synthLength=l;
  _drum->length(l);
}
int SynthDrum::getSynthLength(){
  return _synthLength;
}
void SynthDrum::thenLetsParty(){   
  digitalWrite(_color,HIGH);
  _drum->noteOn();
}   

void SynthDrum::synthLoop(int bpm){
  float n=_noteType;
  if(getTrip()) n=n*.66;// If triplets are enabled, play everything 2/3s as slow. Er, 1.5 times faster. You know what I mean.
  if(_myInternalClock>=(n*(60000/bpm))){
    _myInternalClock=0;
    // e.g., an eighthnote at 120 bpm should play every 250 milliseconds, which is 4 times a secon or 240 times a minute
    _change=0;    
    if(nowIsTheTimeToParty(_patternPosition)){
      thenLetsParty();
    }
    _patternPosition++;
    if(_patternPosition>(_patternLength-1)) _patternPosition=0;
  }
  if(_myInternalClock>=((_noteType/2)*(60000/bpm))){    
      digitalWrite(_color,LOW);
  }
}
void SynthDrum::setName(char* n){
  strcpy(_name,n);
}
char* SynthDrum::getName(){
  return _name;
}

bool SynthDrum::saveDrum(){
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  SD.mkdir("/data/synth");
  char tempPath[]="/data/12345678.txt";
  sprintf(tempPath,"/data/%s.txt",_name);
  File myFile = SD.open(tempPath, FILE_WRITE);
  if (myFile) {
    Serial.print("Writing...");
    myFile.println(tempPath);
    myFile.println(_freq);
    myFile.println(_name);
    myFile.println(_pitch);
    myFile.println(_mix);
    myFile.println(_synthLength);
    myFile.println(_noteType);
// close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening ");
    Serial.println(tempPath);
  }
  
  // re-open the file for reading:
  myFile = SD.open(tempPath);
  if (myFile) {
    Serial.println("Reading:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
     Serial.print("error opening ");
     Serial.println(tempPath);
  }
   File root = SD.open("/");

//  printDirectory(root, 0);
  
  return true;
}
void Sample::printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}



//*******************************************************************************************************************
//*******************************************************************************************************************
//                                                                                          Synth Waves!!!
//*******************************************************************************************************************
//*******************************************************************************************************************
SynthWave::SynthWave(AudioSynthWaveform *synthWave, AudioEffectEnvelope *env,AudioEffectFreeverb *verb,float note,int f, float a, int lng, int w, float att, float h, float d, float s, float r, int bpm, int objects){
  _synthWave=synthWave;
  //_synthWave.begin(a, f, w);
//  _amp=amp;
  _noteType=note;
  _env=env;
  _reverb=verb;
  _bpm=bpm;  
  sprintf(_name,"Wave_%i",(int)random(1000));  
  _color=random(24,34);
  _arp=true;
  _arpPos=0;

  setupPattern(2,2);
  setWaveFreq(f);
  setWaveAmp(a);
  setWaveform(w);
  setWaveAttack(att);
  setWaveHold(h);
  setWaveDecay(d);
  setWaveSustain(s);
  setWaveRelease(r);
  setSynthWaveLength(lng);
}

char* SynthWave::getName(){
  return _name;
}
void SynthWave::setName(char* n){  
  strcpy(_name,n);
}
void SynthWave::setWaveFreq(int f){
  _freq=f;
  _synthWave->frequency(f);
}
void SynthWave::setWaveAmp(float a){
  _waveAmp=a;
  _synthWave->amplitude(a);
}
void SynthWave::setWaveform(int w){
  _waveform=WAVEFORM_SINE;  
}
void SynthWave::setWaveAttack(float a){
  _env->attack(a);
  _attack=a;
}
void SynthWave::setWaveHold(float h){
  _hold=h;
  _env->hold(h);
}
void SynthWave::setWaveDecay(float d){
  _decay=d;
  _env->decay(d);
}
void SynthWave::setWaveSustain(float s){
  _sustain=s;
  _env->sustain(s);
}
void SynthWave::setWaveRelease(float r){
  _release=r;
  _env->release(r);
}
int SynthWave::getWaveFreq(){
  return _freq;
}
float SynthWave::getWaveAmp(){
  return _waveAmp;
}
int SynthWave::getWaveform(){
  return _waveform;
}
float SynthWave::getWaveAttack(){
  return _attack;
}
float SynthWave::getWaveHold(){
  return _hold;
}
float SynthWave::getWaveDecay(){
  return _decay;
}
float SynthWave::getWaveSustain(){
  return _sustain;
}
float SynthWave::getWaveRelease(){
  return _release;
}
void SynthWave::setSynthWaveLength(int l){
  _synthWaveLength=l;
}
int SynthWave::getSynthWaveLength(){
  return _synthWaveLength;
}
void SynthWave::thenLetsParty(){
  digitalWrite(_color,HIGH);
  if(_arp){
    // fn = f0 * (1.059463)^n
    // (currentNote / 440) = (1.059463)^n
    // n = 
    float  currentNote=pow(1.059463,(1/((float)_freq/440.0)));
    //Serial.println(currentNote);
  }
  _synthWave->begin(_waveform);
  _env->noteOn();
}
void SynthWave::stopPlaying(){
  _env->noteOff();
}
void SynthWave::waveLoop(int bpm){
    if(_myInternalClock>=(_noteType*(60000/bpm))){
    _myInternalClock=0;
    // e.g., an eighthnote at 120 bpm should play every 250 milliseconds, which is 4 times a secon or 240 times a minute
    _change=0;    
    if(nowIsTheTimeToParty(_patternPosition)){
      thenLetsParty();
    }
    _patternPosition++;
    if(_patternPosition>(_patternLength-1)) _patternPosition=0;
  }
  if(_myInternalClock>=((_noteType/2)*(60000/bpm))){    
      digitalWrite(_color,LOW);
  }
  if(_myInternalClock>=_synthWaveLength){
    stopPlaying();
  }
}
