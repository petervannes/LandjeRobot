/*
  LandjeLineSensor.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons 
  Attribution-NonCommercial-ShareAlike 4.0 International License. 
  To view a copy of this license, visit 
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "LandjeLineSensor.h"

LandjeLineSensor::Init(int lineSensors[], bool inverse)
{
    
    _inverse = inverse;

    for (int m = 0; m <= 1; m++)
    {
        _lineSensorBitmaskData[m] = digitalPinToBitMask(lineSensors[m]);                   // translate pin number to port register bitmask for selected pin.
        *portModeRegister(digitalPinToPort(lineSensors[m])) &= ~_lineSensorBitmaskData[m]; // Set pin to input in DDR register
        _lineSensorRegisterData[m] = portInputRegister(digitalPinToPort(lineSensors[m]));  // Get the input port register for selected pin.
    }
};

LandjeLineSensor::LINEDETECT LandjeLineSensor::DetectLine()
{
    // Return value based on line detection
    //  LEFT (1)  // Left sensor line detected
    //  RIGHT (2) // Right sensor line detected
    //  BOTH (3)  // Left and right sensor line deteced
    return (LINEDETECT)((((((*(_lineSensorRegisterData[0])) & (_lineSensorBitmaskData[0])) ? 1 : 0) ^ _inverse) << 0) |
                        (((((*(_lineSensorRegisterData[1])) & (_lineSensorBitmaskData[1])) ? 1 : 0) ^ _inverse) << 1));
}
