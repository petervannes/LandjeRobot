/*
  LandjeRobotHead.h - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#ifndef LandjeRobotHead_h
#define LandjeRobotHead_h

#include <Arduino.h>
#include <Servo.h>

class LandjeRobotHead
{

public:
   // Scoped enumeration for looking DIRECTION
       enum class LOOK {
    FORWARD = 90,   // Look forward
    LEFT = 135,     // Look left
    RIGHT = 45,     // Look Right
    FAR_LEFT = 180, // Look far left
    FAR_RIGHT = 0   // Look far right
  } ;

  Init(int);

  Look(LandjeRobotHead::LOOK);

private:
  int _servoPin;
  bool _attached;
  Servo _roboHeadServo;
};

#endif
