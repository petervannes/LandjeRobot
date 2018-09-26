/*
  LandjeRobot.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "LandjeRobot.h"
#include "LandjeRobotMotorController.h"
#include "LandjeRobotHead.h"
#include "LandjeRobotMouth.h"
#include "LandjeRobotSwitch.h"

// LandjeRobotHead *h ;

LandjeRobot::LandjeRobot(int motor_data[][4], LandjeRobotMotorController::STEPMODE stepperMode, int wheelRadiusMM, int trackWidthMM, int lineSensors[], bool lineSensorInverse, int pingSensor, int headServo, int mouthLed, int switchPin)
{

    // mcc = m.Init(motor_data, stepperMode, wheelRadiusMM, trackWidthMM);

    LandjeIntHandler::interruptControlledClasses icc = m.Init(motor_data, stepperMode, wheelRadiusMM, trackWidthMM, mouthLed);

    mcc = icc.rmc;
    o = icc.rm;

    s.Init(lineSensors, lineSensorInverse);

    p.Init(pingSensor);

    h.Init(headServo);

    t = new LandjeRobotSwitch(switchPin);
}

LandjeRobot::talk(int talkDurSec)
{
    o->Talk(talkDurSec);
}

bool LandjeRobot::amITalking()
{
    return o->IsTalking();
}

LandjeRobot::mouthOpen()
{
    o->MouthOpen();
}

LandjeRobot::mouthClosed()
{
    o->MouthShut();
}

LandjeRobot::look(LandjeRobot::LOOK lookDirection)
{
    h.Look((LandjeRobotHead::LOOK)lookDirection);
}

int LandjeRobot::measureDistance()
{
    p.Ping();
    return p.GetDistanceInCM();
}

LandjeRobot::LINE LandjeRobot::detectLine()
{

    LINE a = (LINE)s.DetectLine();

    return a;
}

bool LandjeRobot::doIMove()
{

    return mcc->isMoving();
}

LandjeRobot::move(LandjeRobot::DIRECTION moveDirection)
{

    mcc->SetDirection((LandjeRobotMotorController::DIRECTION)moveDirection);
}

LandjeRobot::move(LandjeRobot::DIRECTION moveDirection, int cm)
{

    mcc->SetDirection((LandjeRobotMotorController::DIRECTION)moveDirection, cm);
}

LandjeRobot::move(LandjeRobot::DIRECTION moveDirection, int cm, bool wait)
{
    mcc->SetDirection((LandjeRobotMotorController::DIRECTION)moveDirection, cm);

    while (wait && mcc->isMoving())
    {
        delay(200);
    }
}

LandjeRobot::turn(LandjeRobot::TURN turnDirection)
{

    mcc->SetTurn((LandjeRobotMotorController::TURN)turnDirection);
}

LandjeRobot::turn(LandjeRobot::TURN turnDirection, int graden)
{

    mcc->SetTurn((LandjeRobotMotorController::TURN)turnDirection, graden);
}

LandjeRobot::turn(LandjeRobot::TURN turnDirection, int graden, bool wait)
{

    mcc->SetTurn((LandjeRobotMotorController::TURN)turnDirection, graden);

    while (wait && mcc->isMoving())
    {
        delay(200);
    }
}

int LandjeRobot::mode()
{
    return t->getMode();
}
