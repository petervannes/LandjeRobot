/*
  LandjeIntHandler.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons 
  Attribution-NonCommercial-ShareAlike 4.0 International License. 
  To view a copy of this license, visit 
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "Arduino.h"
#include "LandjeIntHandler.h"

LandjeIntHandler::interruptControlledClasses icc;

LandjeIntHandler::interruptControlledClasses LandjeIntHandler::Init(int motor_data[][4], LandjeRobotMotorController::STEPMODE stepperMode, int wheelRadiusMM, int trackWidthMM, int mouth)
{

    // Create instance of Robot Motor Controller
    icc.rmc = new LandjeRobotMotorController(motor_data, stepperMode, wheelRadiusMM, trackWidthMM);
    // Create instance of Robot Mouth
    icc.rm = new LandjeRobotMouth(mouth);

    // CPU Freq 16Mhz
    // Need interval of 1Ms ==> 0,001/(1/16000000) = 16.000 ticks
    //
    // Prescaler 64 ==> resolution changes from 0,0000000625 to 0,000004
    // Need interval of 1Ms ==> (0,001/((1/16000000)*64)) - 1 = 249 ticks

    // Set prescaler to clk/64 ; (1 << CS22)
    // Clear Timer on Compare (CTC) mode ; (1 << WGM22)
    TCCR2B = 0;
    TCCR2B |= (1 << WGM22) | (1 << CS22);

    // Set prescaler to clk/1024 for debugging purposes
    // TCCR2B |= (1 << WGM22) | (1 << CS22) | (1 << CS21) | (1 << CS20) ;

    // set Output Compare Register to (250 - 1) ticks
    OCR2A = 0xF9;

    // initialize counter
    TCNT2 = 0;

    // TIMSK2
    // Set Timer Interrupt Mask Register to
    // Clear Timer on Compare channel A for timer 2
    TIMSK2 |= (1 << OCIE2A);

    return icc;
}

// Interrupt Service Routine calling delegated ISRs
ISR(TIMER2_COMPA_vect)
{
    icc.rmc->Move();
    icc.rm->Talk();
}