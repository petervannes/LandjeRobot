/*
  LandjeRobotHead.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons 
  Attribution-NonCommercial-ShareAlike 4.0 International License. 
  To view a copy of this license, visit 
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "LandjeRobotHead.h"

LandjeRobotHead::Init(int servoPin)
{
    _servoPin = servoPin;
    pinMode(_servoPin, OUTPUT);
    _attached = false;
}

LandjeRobotHead::Look(LandjeRobotHead::LOOK lookDirection)
{

    if (!_attached)
    {
        _attached = true;
        _roboHeadServo.attach(_servoPin);
    }

    _roboHeadServo.write((int)lookDirection);
}
