/*
  LandjeIntHandler.h - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#ifndef LandjeIntHandler_h
#define LandjeIntHandler_h

#include <Arduino.h>
#include "LandjeRobotMotorController.h"
#include "LandjeRobotMouth.h"

class LandjeIntHandler
{

public:
  struct interruptControlledClasses
  {
    LandjeRobotMotorController *rmc;
    LandjeRobotMouth *rm;
  };

  LandjeIntHandler::interruptControlledClasses Init(int motor_data[2][4], LandjeRobotMotorController::STEPMODE, int, int, int);
};

#endif
