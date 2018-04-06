/*
  LandjeRobot.h - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons 
  Attribution-NonCommercial-ShareAlike 4.0 International License. 
  To view a copy of this license, visit 
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#ifndef LandjeRobot_h
#define LandjeRobot_h

// #include "Arduino.h"
#include "LandjeIntHandler.h"
#include "LandjeLineSensor.h"
#include "LandjePingSensor.h"
#include "LandjeRobotHead.h"
#include "LandjeRobotMouth.h"
#include "LandjeRobotSwitch.h"

class LandjeRobot
{
public:
  // Scoped enumeration for DIRECTION of travel
  enum class LINE
  {
    NONE = 0,  // No line detected by any sensor
    LEFT = 1,  // Left sensor detected line
    RIGHT = 2, // Right sensor detected line
    BOTH = 3   // Both left and right sensor detected line
  };

  // Scoped enumeration  for DIRECTION of travel
  enum class DIRECTION
  {
    STOP = 0,    // Stop
    FORWARD = 1, // Move forward
    BACKWARD = 2 // Move backward
  };

  // Scoped enumeration  for DIRECTION of rotation
  enum class TURN
  {
    STRAIGHT = 0, // Right on
    LEFT = 1,     // TURN left
    RIGHT = 2     // TURN right
  };

  // Scoped enumeration for looking DIRECTION
  enum class LOOK
  {
    FORWARD = 90,   // Look forward
    LEFT = 135,     // Look left
    RIGHT = 45,     // Look Right
    FAR_LEFT = 180, // Look far left
    FAR_RIGHT = 0   // Look far right
  };

  LandjeRobot(int motor_data[2][4], LandjeRobotMotorController::STEPMODE, int, int, int lineSensors[2], bool, int, int, int, int);

  LandjeRobot::talk(int);
  bool LandjeRobot::amITalking();
  LandjeRobot::mouthOpen();
  LandjeRobot::mouthClosed();

  int measureDistance();
  LINE detectLine();
  move(LandjeRobot::DIRECTION);
  move(LandjeRobot::DIRECTION, int);
  move(LandjeRobot::DIRECTION, int, bool);
  bool doIMove();

  turn(LandjeRobot::TURN);
  turn(LandjeRobot::TURN, int);
  turn(LandjeRobot::TURN, int, bool);
  look(LandjeRobot::LOOK);

  int mode();

private:
  LandjeLineSensor s;
  LandjePingSensor p;
  LandjeRobotHead h;
  LandjeIntHandler m;
  LandjeRobotMouth *o;
  LandjeRobotMotorController *mcc;
  LandjeRobotSwitch *t;

  // default direction and turn
  LandjeRobotMotorController::DIRECTION _moveDirection = LandjeRobotMotorController::DIRECTION::FORWARD;
  LandjeRobotMotorController::TURN _turnDirection = LandjeRobotMotorController::TURN::STRAIGHT;

  // default to half step mode, more power but slower
  LandjeRobotMotorController::STEPMODE _stepperMode = LandjeRobotMotorController::STEPMODE::HALF_STEP;
};

#endif
