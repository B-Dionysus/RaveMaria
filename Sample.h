#ifndef Sample_h
#define Sample_h
#endif
#include "Arduino.h"
#include <SD.h>
#include <Audio.h>

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13

#define FLASH_CS  6
//*******************************************************************************************************************
//*******************************************************************************************************************
//*                                                                                             Sample Class
//*******************************************************************************************************************
//*******************************************************************************************************************
class Sample{
  protected:
    elapsedMillis _myInternalClock;
    float _noteType;       // i.e., what percentage of bpm is this note (e.g., a quarternote is 1 bpm, an eigthnote is .5)
    int _pattern=0;
    int _patternPosition=0;
    int _patternLength=0;
    int _isInverted=0;
    AudioAmplifier *_amp;
    AudioEffectFreeverb *_reverb;
    int _id;
    int _change;
    int _bpm;
    float _volume;
    float _roomSize;
    bool _enabled=false;    
    char _name[9];
    int _color;    
    bool _triplets=false;
      
  public:
    void setupSample();
    bool sampleIsEnabled();
    void enableSample(bool a);
    void loop(long t);
    void setInternalBPM(int bpm);
    int getInternalBPM();
    void setVol(float v);
    float getVol();
    void setVerb(float v);
    float getVerb();
    void setupPattern(int beats, int rests);
    int getPatternLength();
    int getHits();
    int getPatternAt(int x);
    void flipPatternAt(int pos);
    int getSampleColor();
    void setSampleColor(int x);
    bool getTrip();
    void setTrip(bool t);

    //float getNoteType();
    //void setNoteType(int n);
    void changePattern(int beats, int rests);
    int nowIsTheTimeToParty(int pos);
    virtual void thenLetsParty(){}
    int findBeats(int beats, int rests);
    int euclid(int beats, int rests, int bigArray[], int smallArray[], int maxRuns);  
    void printPattern(int p, int inverted, int pl);
    const char* findPatternName(int a, int b);
    int getId();
    void printDirectory(File dir, int numTabs);
    void synch();    
    float getNoteType();
    void setNoteType(float n);
};

//*******************************************************************************************************************
//*******************************************************************************************************************
//                                                                                          Flash SAMPLE!!!
//*******************************************************************************************************************
//*******************************************************************************************************************
class FlashSample : public Sample{
  protected:
    File _currentDir;
    SerialFlashFile _currentSample;
    const char *_sampleName;
    char _fullSamplePath[50];
    AudioPlaySerialflashRaw *_flash;
    int _startTime;
    int _endTime;

  public:
    FlashSample(const char *dn,const char *sn, float noteType,AudioPlaySerialflashRaw *flash,AudioAmplifier *amp,AudioEffectFreeverb *verb, int bpm=120, int objects=0, int startTime=0, int endTime=0);
    File loadDir(const char* dir);
    File getCurrentDir();
    void loadSample(const char* sampleName);
    void setName(char* n);
    char* getName();
    bool compareFiles(File &file, SerialFlashFile &ffile);
    SerialFlashFile copyFileToFlash(File f, const char* fileName, bool shouldIDelete);    
    void thenLetsParty();    
    void flashLoop(int bpm);
    void listFiles();
    
    
    
};
//*******************************************************************************************************************
//*******************************************************************************************************************
//                                                                                          SD SAMPLE!!!
//*******************************************************************************************************************
//*******************************************************************************************************************
//class SDSample : public Sample{
//  protected:
//    File _currentDir;
//    File _currentSample;
//    const char *_sampleName;
//    char _fullSamplePath[50];
//    int _isItRaw;
//    AudioPlaySdWav _playSD;
//
//  public:
//    int setupSample(const char *dn,const char *sn,float n, int beats, int rests, AudioPlaySdWav playSD, int bpm=120, int raw=0, int objects=0);
//    File loadDir(const char* dir);
//    File loadSample(const char* sampleName);
//    void thenLetsParty();
//};
//*******************************************************************************************************************
//*******************************************************************************************************************
//                                                                                          Synth Drum!!!
//*******************************************************************************************************************
//*******************************************************************************************************************
class SynthDrum : public Sample{
  private:
    long _oldT=0;
    int _bpm;
    AudioSynthSimpleDrum *_drum;
    int _synthLength;
    int _freq;
    float _pitch;
    float _mix;
    
  public:
    SynthDrum(int f, int l, float m, float p, float n,AudioSynthSimpleDrum *drum,AudioAmplifier *amp,AudioEffectFreeverb *verb, int bpm=120, int objects=0);
    void thenLetsParty();
    void synthLoop(int bpm);
    char* getName();
    int getFreq();
    void setFreq(int f);
    void setName(char* n);
    bool saveDrum();
    void setSynthLength(int l);
    int getSynthLength();
    void setSynthMix(float m);
    float getSynthMix();
    void setSynthPitch(float p);
    float getSynthPitch();
};

//*******************************************************************************************************************
//*******************************************************************************************************************
//                                                                                          Synth WAVE!!!
//*******************************************************************************************************************
//*******************************************************************************************************************
class SynthWave : public Sample{
  private:
    int _freq;
    float _waveAmp;
    int _waveform;
    AudioSynthWaveform *_synthWave;
    AudioEffectEnvelope *_env;
    float _attack;
    float _hold;
    float _decay;
    float _sustain;
    float _release;
    int _synthWaveLength;
    int _arpPos;
    bool _arp;

  public:
    SynthWave(AudioSynthWaveform *synthWave, AudioEffectEnvelope *env, AudioEffectFreeverb *verb,float note, int f=440, float a=0.15, int lng=250, int w=WAVEFORM_SINE, float att=9.2, float h=2.1, float d=31.4, float s=0.6, float r=84.5, int bpm=120, int objects=0);
    void thenLetsParty();
    void stopPlaying();
    void waveLoop(int bpm);
    char* getName();
    void setName(char* n);
    void setWaveFreq(int f);
    void setWaveAmp(float a);
    void setWaveform(int w);
    void setWaveAttack(float a);
    void setWaveHold(float h);
    void setWaveDecay(float d);
    void setWaveSustain(float s);
    void setWaveRelease(float r);
    void setSynthWaveLength(int lng);
    int getWaveFreq();
    float getWaveAmp();
    int getWaveform();
    float getWaveAttack();
    float getWaveHold();
    float getWaveDecay();
    float getWaveSustain();
    float getWaveRelease();   
    int getSynthWaveLength(); 
};
