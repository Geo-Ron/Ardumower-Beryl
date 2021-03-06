#pragma once

#include <Arduino.h>
#include "MotorDriver.h"

namespace Ardumower
{
	class L298NMotorDriver : public MotorDriver
	{
	public:
		L298NMotorDriver(bool isEnabled, bool isVerbose, unsigned int pinEnable, unsigned int pinInput1, unsigned int pinInput2);

		// Implements the method inherited from the base MotorDriver class
		void SetSpeed(int speed);

		// Implements the method inherited from the base MotorDriver class
		int GetSpeed() const;

	private:
		unsigned int _pinEnable;
		unsigned int _pinInput1;
		unsigned int _pinInput2;

		// Keeps track of the current speed of the Motor driver
		int _currentSpeed = 0;
	};
};
