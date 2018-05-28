/*
  LandjeLineSensor.h - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#ifndef LandjeLineSensor_h
#define LandjeLineSensor_h

#include "Arduino.h"

class LandjeLineSensor
{

public:
  // Symbolic names for line detection
  typedef enum {
    NONE,  // No line detected
    LEFT,  // Left sensor  line detected
    RIGHT, // Right sensor line detected
    BOTH   // Left and right sensor line detected
  } LINEDETECT;

public:
  // methods
  Init(int lineSensors[2], bool);

  // types
  LINEDETECT DetectLine();

private:
  // Line detection
  // false ; dark lines light colored floor
  // true  ; light lines dark colored floor
  bool _inverse;

  // Store bitmask for line sensor pins
  uint8_t _lineSensorBitmaskData[2];

  // Store input registers for line sensor pins
  volatile uint8_t *_lineSensorRegisterData[2];
};

#endif
