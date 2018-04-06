/*
  LandjeRobotMouth.h - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons 
  Attribution-NonCommercial-ShareAlike 4.0 International License. 
  To view a copy of this license, visit 
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#ifndef LandjeRobotMouth_h
#define LandjeRobotMouth_h

#include <Arduino.h>

static int _ledPin;

class LandjeRobotMouth
{

public:
  LandjeRobotMouth(int);
  Talk(int);
  Talk();
  bool IsTalking();
  MouthOpen();
  MouthShut();
  // long readVcc() ;
  static unsigned int rng();

private:
  long _endTalk;

  int _mouthPinBitmaskData;

  volatile uint8_t *_mouthRegisterData;

  bool _blinkPattern[50];
  const int _blinkPatternLength = 50;
  int _pc = 0;
  const int _intDivision = 10;
  int _intDivCnt = _intDivision;

  volatile uint8_t *_seedInputRegister;
  volatile uint8_t *_seedModeRegister;
};

#endif
