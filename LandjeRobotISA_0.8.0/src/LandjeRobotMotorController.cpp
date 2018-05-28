/*
  LandjeRobotMotorController.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "Arduino.h"
#include "LandjeRobotMotorController.h"

LandjeRobotMotorController::LandjeRobotMotorController(int motor_data[][4], LandjeRobotMotorController::STEPMODE stepperMode, int wheelRadiusMM, int trackWidthMM)
{

    _stepCount = 0;
    _stepperMode = stepperMode;
    _wheelCircumferenceMM = 2 * PI * wheelRadiusMM;
    _turnRadiusCircumferenceMM = 2 * PI * trackWidthMM;

    // Convert pin numbers to pinbit mask, set input/output mode,
    // store the output port register per pin
    for (int m = 0; m <= 1; m++)
    {
        for (int n = 0; n <= 3; n++)
        {
            _motorPinBitmaskData[m][n] = digitalPinToBitMask(motor_data[m][n]);                  // translate pin number to port register bitmask for selected pin.
            *portModeRegister(digitalPinToPort(motor_data[m][n])) |= _motorPinBitmaskData[m][n]; // Set pin to output in DDR register
            _motorRegisterData[m][n] = portOutputRegister(digitalPinToPort(motor_data[m][n]));   // Get the output port register for selected pin.

            *_motorRegisterData[m][n] &= ~_motorPinBitmaskData[m][n]; // LOW
        }
    }
}

boolean LandjeRobotMotorController::isMoving()
{
    return ((_moveDirection != LandjeRobotMotorController::DIRECTION::STOP) ||
            (_turnDirection != LandjeRobotMotorController::TURN::STRAIGHT));
}

LandjeRobotMotorController::SetDirection(LandjeRobotMotorController::DIRECTION newMoveDirection)
{
    _moveDirection = newMoveDirection;
    // No specified distance
    _stepCount = 0;
}

LandjeRobotMotorController::SetDirection(LandjeRobotMotorController::DIRECTION newMoveDirection, int cm)
{
    _stepCount = (cm * 10) / (_wheelCircumferenceMM / (_stepsPerRotation / (int)_stepperMode));
    _moveDirection = newMoveDirection;
}

LandjeRobotMotorController::SetTurn(LandjeRobotMotorController::TURN newTurnDirection)
{
    SetTurn(newTurnDirection, 90);
}

LandjeRobotMotorController::SetTurn(LandjeRobotMotorController::TURN newTurnDirection, int degrees)
{
    SetDirection(LandjeRobotMotorController::DIRECTION::STOP);
    _stepCount = ((_turnRadiusCircumferenceMM / 360) * degrees) / (_wheelCircumferenceMM / (_stepsPerRotation / (int)_stepperMode));
    _turnDirection = newTurnDirection;
}

LandjeRobotMotorController::Move()
{

    // Execute same step for all motors
    for (int m = 0; m <= 1; m++)
    {

        // Move one step
        switch (_moveDirection)
        {
        // forward
        case DIRECTION::FORWARD:
            _motorStep[m] = _motorStep[m] + ((int)_stepperMode * (int)_motorDirection[m]);
            break;
        // backward
        case DIRECTION::BACKWARD:
            _motorStep[m] = _motorStep[m] - ((int)_stepperMode * (int)_motorDirection[m]);
            break;
        }

        // Turn one step
        switch (_turnDirection)
        {
        // left
        case TURN::LEFT:
            _motorStep[m] = _motorStep[m] - ((int)_stepperMode * (m == 0 ? (int)_motorDirection[m] : (int)-_motorDirection[m]));
            break;
        // right
        case TURN::RIGHT:
            _motorStep[m] = _motorStep[m] + ((int)_stepperMode * (m == 0 ? (int)_motorDirection[m] : (int)-_motorDirection[m]));

            break;
        }

        // if step is past last, begin at first step
        if (_motorStep[m] > 7)
        {
            _motorStep[m] = 0 + ((int)_stepperMode - 1);
        }

        // if step is behind first, begin at last step
        if (_motorStep[m] < 0)
        {
            _motorStep[m] = 7;
        }

        switch (_motorStep[m])
        {
        case 0:
            *_motorRegisterData[m][0] &= ~_motorPinBitmaskData[m][0]; // LOW
            *_motorRegisterData[m][1] &= ~_motorPinBitmaskData[m][1]; // LOW
            *_motorRegisterData[m][2] &= ~_motorPinBitmaskData[m][2]; // LOW
            *_motorRegisterData[m][3] |= _motorPinBitmaskData[m][3];  // HIGH
            break;
        case 1:
            *_motorRegisterData[m][0] &= ~_motorPinBitmaskData[m][0]; // LOW
            *_motorRegisterData[m][1] &= ~_motorPinBitmaskData[m][1]; // LOW
            *_motorRegisterData[m][2] |= _motorPinBitmaskData[m][2];  // HIGH
            *_motorRegisterData[m][3] |= _motorPinBitmaskData[m][3];  // HIGH
            break;
        case 2:
            *_motorRegisterData[m][0] &= ~_motorPinBitmaskData[m][0]; // LOW
            *_motorRegisterData[m][1] &= ~_motorPinBitmaskData[m][1]; // LOW
            *_motorRegisterData[m][2] |= _motorPinBitmaskData[m][2];  // HIGH
            *_motorRegisterData[m][3] &= ~_motorPinBitmaskData[m][3]; // LOW
            break;
        case 3:
            *_motorRegisterData[m][0] &= ~_motorPinBitmaskData[m][0]; // LOW
            *_motorRegisterData[m][1] |= _motorPinBitmaskData[m][1];  // HIGH
            *_motorRegisterData[m][2] |= _motorPinBitmaskData[m][2];  // HIGH
            *_motorRegisterData[m][3] &= ~_motorPinBitmaskData[m][3]; // LOW
            break;
        case 4:
            *_motorRegisterData[m][0] &= ~_motorPinBitmaskData[m][0]; // LOW
            *_motorRegisterData[m][1] |= _motorPinBitmaskData[m][1];  // HIGH
            *_motorRegisterData[m][2] &= ~_motorPinBitmaskData[m][2]; // LOW
            *_motorRegisterData[m][3] &= ~_motorPinBitmaskData[m][3]; // LOW
            break;
        case 5:
            *_motorRegisterData[m][0] |= _motorPinBitmaskData[m][0];  // HIGH
            *_motorRegisterData[m][1] |= _motorPinBitmaskData[m][1];  // HIGH
            *_motorRegisterData[m][2] &= ~_motorPinBitmaskData[m][2]; // LOW
            *_motorRegisterData[m][3] &= ~_motorPinBitmaskData[m][3]; // LOW
            break;
        case 6:
            *_motorRegisterData[m][0] |= _motorPinBitmaskData[m][0];  // HIGH
            *_motorRegisterData[m][1] &= ~_motorPinBitmaskData[m][1]; // LOW
            *_motorRegisterData[m][2] &= ~_motorPinBitmaskData[m][2]; // LOW
            *_motorRegisterData[m][3] &= ~_motorPinBitmaskData[m][3]; // LOW
            break;
        case 7:
            *_motorRegisterData[m][0] |= _motorPinBitmaskData[m][0];  // HIGH
            *_motorRegisterData[m][1] &= ~_motorPinBitmaskData[m][1]; // LOW
            *_motorRegisterData[m][2] &= ~_motorPinBitmaskData[m][2]; // LOW
            *_motorRegisterData[m][3] |= _motorPinBitmaskData[m][3];  // HIGH
            break;
        default:
            *_motorRegisterData[m][0] &= ~_motorPinBitmaskData[m][0]; // LOW
            *_motorRegisterData[m][1] &= ~_motorPinBitmaskData[m][1]; // LOW
            *_motorRegisterData[m][2] &= ~_motorPinBitmaskData[m][2]; // LOW
            *_motorRegisterData[m][3] &= ~_motorPinBitmaskData[m][3]; // LOW
            break;
        }
    }

    // If limited number of steps has set,
    // decrease counted steps by one and
    // stop movement if stepcount has reached 0
    if (_stepCount > 0)
    {
        if (--_stepCount == 0)
        {
            SetDirection(DIRECTION::STOP);
            SetTurn(TURN::STRAIGHT);
        }
    }
}
