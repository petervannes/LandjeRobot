/*
  LandjeRobotMotorController.h - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#ifndef LandjeRobotMotorController_h
#define LandjeRobotMotorController_h

#include <Arduino.h>

class LandjeRobotMotorController
{

  public:
    // Set to a value of >0 if a limited number of steps need to be made
    int _stepCount;

  // Symbolic names for DIRECTION of travel
    enum class DIRECTION {
        STOP = 0,    // Stop
        FORWARD = 1, // Move forward
        BACKWARD = 2 // Move backward
    } ;

    // Symbolic names for DIRECTION of rotation
     enum class TURN {
        STRAIGHT = 0, // Right on
        LEFT = 1,     // TURN left
        RIGHT = 2     // TURN right
    } ;

    // Stepper motor 28BYJ-48
    // 1 for half step 63.684 steps per rotation = 4076
    // 2 for full step 4076/2                    = 2038
    // Symbolic name for half or full step mode
    enum class STEPMODE {

        HALF_STEP = 1,
        FULL_STEP = 2
    } ;

    LandjeRobotMotorController(int motor_data[2][4], LandjeRobotMotorController::STEPMODE, int, int);
    SetDirection(LandjeRobotMotorController::DIRECTION);
    SetDirection(LandjeRobotMotorController::DIRECTION, int);
    SetTurn(LandjeRobotMotorController::TURN);
    SetTurn(LandjeRobotMotorController::TURN, int);
    bool isMoving();
    Move();

    boolean moving = false;

  private:
    // Steps per full rotation for 28BYJ-48 stepper motor in half step mode
    const int _stepsPerRotation = 4076;

    // Default step mode
    LandjeRobotMotorController::STEPMODE _stepperMode;

    // Wheel radius and calculated circumference
    float _wheelCircumferenceMM;
    float _turnRadiusCircumferenceMM;

    // Default direction
    LandjeRobotMotorController::DIRECTION _moveDirection = LandjeRobotMotorController::DIRECTION::STOP;
    LandjeRobotMotorController::TURN _turnDirection = LandjeRobotMotorController::TURN::STRAIGHT;

    // Store current motor position
    int _motorStep[2] = {0, 0};

    // Sets default forward direction per motor
    const int _motorDirection[2] = {1, -1};

    // Store bitmask for motor pins
    int _motorPinBitmaskData[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    // Store output registers for motor pins
    volatile uint8_t *_motorRegisterData[2][4];
};

#endif
