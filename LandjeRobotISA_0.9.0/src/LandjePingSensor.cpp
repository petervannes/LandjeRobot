/*
  LandjePingSensor.cpp - Part of the library "LandjeRobot"

  This file is part of the Reddipped.com Landje robot library.

  This work is licensed under the Creative Commons
  Attribution-NonCommercial-ShareAlike 4.0 International License.
  To view a copy of this license, visit
  http://creativecommons.org/licenses/by-nc-sa/4.0/.

  Created by Peter van Nes, October 16, 2017.
  Check Github latest release @ https://github.com/reddipped/LandjeRobot

 */

#include "LandjePingSensor.h"

LandjePingSensor::Init(int pingSensorPort)
{
    _distanceInCM = 0;
    _pingPinBitmask = digitalPinToBitMask(pingSensorPort);                             // translate pin number to port register bitmask for selected pin.
    _pingOutputRegister = portOutputRegister(digitalPinToPort(pingSensorPort));        // Get the output (PORT) port register for selected pin.
    _echoInputRegister = portInputRegister(digitalPinToPort(pingSensorPort));          // Get the input (PIN) port register for the echo pin.
    _pingModeRegister = (uint8_t *)portModeRegister(digitalPinToPort(pingSensorPort)); // get DDR register for pin

    // Sound has to travel to object and echoed back from the object.
    // The maximum time to wait for an echo is roughly the maximum distance detection
    // multiplied by 2 and divided by the traveling speed of sound in microseconds per cm.
    _maxEchoWaitTime = (long)((_maxPingDistanceCM * 20) * _speedSoundCmPerUsec);
};

LandjePingSensor::Ping()
{

    delay(10) ;

    // Trigger the HC-SR04
    *_pingModeRegister |= _pingPinBitmask;    // Set pin to output (HIGH) in DDR register
    *_pingOutputRegister &= ~_pingPinBitmask; // LOW
    delayMicroseconds(2);
    *_pingOutputRegister |= _pingPinBitmask; // HIGH
    delayMicroseconds(10);
    *_pingOutputRegister &= ~_pingPinBitmask; // LOW

    // Switch port to input mode to detect echo on same pin
    *_pingModeRegister &= ~_pingPinBitmask; // Set pin to input (LOW) in DDR register

    // Stop measuring if another ping is in progress
    if (*_echoInputRegister & _pingPinBitmask) {
        return; // pin still high probably waiting for other echo.
    }

    boolean timeout = false;
    _echoWaitTime = micros() + _maxEchoWaitTime; // max wait timestamp

    // Wait till the ping echo returns or timeout occurs
    while (!(*_echoInputRegister & _pingPinBitmask))
    { // wait till pin changes to HIGH
        if (micros() > _echoWaitTime)
        {
            timeout = true;
            break;
        } // stop waiting if it takes to long based on max ping distance
    }

    // If ping is received, measure pulse duration
    if (!timeout)
    {
        _echoWaitTime = micros() + _maxEchoWaitTime; // max wait timestamp
        _pingStartTime = micros();

        // Wait till ping echo is received
        while (*_echoInputRegister & _pingPinBitmask)
        { // Wait till ping changes to LOW
            if (micros() > _echoWaitTime)
            {
                timeout = true;
                _distanceInCM = _maxPingDistanceCM;
                break;
            } // stop waiting if it takes to long based on max ping distance
        }

        if (!timeout)
        {
            _distanceInCM = (micros() - _pingStartTime) / (_speedSoundCmPerUsec * 2);
        }
    }
}

int LandjePingSensor::GetDistanceInCM()
{
    // If recorded last sampled distance is > 2cm
    if (_distanceInCM >= _minPingDistanceCM)
    {
        return _distanceInCM; // return distance in cm
    }
    else
    {
        return 0; // return distance 0
    }
}
