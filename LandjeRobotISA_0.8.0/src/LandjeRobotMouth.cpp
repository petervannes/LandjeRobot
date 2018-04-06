/*
  LandjeRobotMouth.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons 
  Attribution-NonCommercial-ShareAlike 4.0 International License. 
  To view a copy of this license, visit 
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "LandjeRobotMouth.h"
#include <Arduino.h>

LandjeRobotMouth::LandjeRobotMouth(int ledPin)
{
    _ledPin = ledPin;
    _endTalk = 0;

    _mouthPinBitmaskData = digitalPinToBitMask(_ledPin);                  // translate pin number to port register bitmask for selected pin.
    *portModeRegister(digitalPinToPort(_ledPin)) |= _mouthPinBitmaskData; // Set pin to output in DDR register
    _mouthRegisterData = portOutputRegister(digitalPinToPort(_ledPin));   // Get the output port register for selected pin.
    *_mouthRegisterData &= ~_mouthPinBitmaskData;                         // Turn led Off (LOW)
}

LandjeRobotMouth::Talk(int durationSecs)
{

    // Generate a random morse-like blink pattern
    randomSeed(LandjeRobotMouth::rng());
    int x = 0;
    bool ledStatus = true;

    while (x < (_blinkPatternLength - 1))
    {

        // set pulse length
        int l = random(_blinkPatternLength / 6);

        // correct overload of
        if ((x + l + 1) > _blinkPatternLength)
        {
            l = _blinkPatternLength - x - 1;
        }

        // fill array with length of pulse
        for (int z = 0; z <= l; z++)
        {
            _blinkPattern[x + z] = ledStatus;
        }

        x = x + l;
        ledStatus = !ledStatus;
    }

    // Start talking
    _endTalk = millis() + (durationSecs * 1000);
}

LandjeRobotMouth::Talk()
{

    if (_intDivCnt > 0)
    {
        _intDivCnt--;
    }
    else
    {

        if (_endTalk != 0)
        {
            if (_endTalk >= millis())
            {
                if (_blinkPattern[_pc])
                {
                    *_mouthRegisterData |= _mouthPinBitmaskData; // HIGH
                }
                else
                {
                    *_mouthRegisterData &= ~_mouthPinBitmaskData; // LOW
                }
                _pc++;
                if (_pc > 49)
                    _pc = 0;
            }
            else
            {
                _endTalk = 0;
                *_mouthRegisterData &= ~_mouthPinBitmaskData; // LOW
            }
        }

        _intDivCnt = _intDivision;
    }
}

bool LandjeRobotMouth::IsTalking()
{
    return (_endTalk != 0);
}

LandjeRobotMouth::MouthOpen()
{
    *_mouthRegisterData |= _mouthPinBitmaskData; // HIGH
}

LandjeRobotMouth::MouthShut()
{
    *_mouthRegisterData &= ~_mouthPinBitmaskData; // LOW
}

// Credits for David
// http://engineeringnotes.blogspot.nl/2015/07/a-fast-random-function-for-arduinoc.html
static unsigned int LandjeRobotMouth::rng()
{
    static unsigned int y = 0;
    y += micros(); // seeded with changing number
    y ^= y << 2;
    y ^= y >> 7;
    y ^= y << 7;
    return (y);
}