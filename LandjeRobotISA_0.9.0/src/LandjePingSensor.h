/*
  LandjePingSensor.h - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#ifndef LandjePingSensor_h
#define LandjePingSensor_h

#include "Arduino.h"
class LandjePingSensor
{

public:
  Init(int pingSensorPort);

  Ping();

  int GetDistanceInCM();

private:
  const unsigned int _maxPingDistanceCM = 400; //maximum distance detected by ping sensor in cm
  const unsigned int _minPingDistanceCM = 2;   // minimum detectable distance

  // The approximate speed of sound in dry air is given by the formula:
  // c = 331.5 (m/s) + 0.6 * [air temperature in degrees Celsius]
  // Give the temperatue of 21 Celcius;
  // 331.5 + (0.6 * 21) = 344.1 meter/sec = 34410 cm/sec
  // 34410 cm/sec = (34410 / 1000) cm/msec = 0.034410 cm/microsec
  const unsigned long _speedSoundCmPerUsec = 23;

  unsigned int _maxEchoWaitTime; // calculated max wait time in microseconds
  unsigned long _echoWaitTime;   // timestamp when ping echo response measurement ends
  unsigned long _pingStartTime;  // stores start of ping echo reception
  unsigned int _distanceInCM;

  uint8_t _pingPinBitmask;
  volatile uint8_t *_pingOutputRegister;
  volatile uint8_t *_echoInputRegister;
  volatile uint8_t *_pingModeRegister;
};

#endif
