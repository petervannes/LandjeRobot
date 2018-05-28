/*
  LandjeRobotSwitch.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "LandjeRobotSwitch.h"
#include <Arduino.h>

LandjeRobotSwitch::LandjeRobotSwitch(int switchPin)
{
    _switchPin = switchPin;
    pinMode(switchPin, INPUT_PULLUP);
}

int LandjeRobotSwitch::getMode()
{
    if (digitalRead(_switchPin) == HIGH)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
