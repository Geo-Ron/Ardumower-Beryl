#pragma once

#include <Arduino.h>
#include <NewPing.h>
#include "DistanceSensorDriver.h"
#include "MovingAverage.h"

#define MAX_READING_FREQUENCY 30 //The maximum frequency the HC-SR04 can be queried at

namespace Ardumower
{

	class HCSR04DistanceSensorDriver : public DistanceSensorDriver
	{

	public:
		HCSR04DistanceSensorDriver(bool isEnabled, bool isVerbose, unsigned int maxDistance, unsigned int pinTrigger, unsigned int pinEcho);

		unsigned int GetDistance();

		unsigned int GetAverageDistance();

	private:
		// The NewPing sensor instance
		NewPing sensor;

		// The last time we made a reading
		unsigned long _lastReadingTime = 0;

		// The last reading we made
		unsigned int _latestDistance;

		// The HC-SR04 returns fake readings from time to time.
		// We will be averaging the last 3 reading of the sensor, to get a more reallistic reading
		MovingAverage<unsigned int, 3> average;
	};
};
