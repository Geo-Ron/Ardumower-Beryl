#pragma once

#include <Arduino.h>
#include <NewPing.h>
#include "Configuration.h"
#include "Driver.h"
#include "MovingAverage.h"

#define SONAR_ARRAY_SENSORS     6 // Number of sensors.
#define MAX_RANGEFINDER_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

namespace Ardumower
{
	class UltrasonicSensorArrayDriver : public Driver
	{

	public:
		UltrasonicSensorArrayDriver(bool isEnabled, bool isVerbose);

		void Update();
		void Setup();
		void PrintSonarArrayReadings();
		void PrintSonarArrayAverageReadings();
		unsigned int GetSonarSensorReading(byte sensorNumber);
		unsigned int GetSonarSensorAverageReading(byte sensorNumber);
		unsigned int GetSonarSensorAngle(byte sensorNumber);
		void EchoCheck();

		// Sensor object array.
		NewPing sonar[SONAR_ARRAY_SENSORS] =
		{
			NewPing(PIN_HCSR04_0, PIN_HCSR04_0, MAX_RANGEFINDER_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
			NewPing(PIN_HCSR04_1, PIN_HCSR04_1, MAX_RANGEFINDER_DISTANCE),
			NewPing(PIN_HCSR04_2, PIN_HCSR04_2, MAX_RANGEFINDER_DISTANCE),
			NewPing(PIN_HCSR04_3, PIN_HCSR04_3, MAX_RANGEFINDER_DISTANCE),
			NewPing(PIN_HCSR04_4, PIN_HCSR04_4, MAX_RANGEFINDER_DISTANCE),
			NewPing(PIN_HCSR04_5, PIN_HCSR04_5, MAX_RANGEFINDER_DISTANCE)
		};

		// This array will keep track of the moving averages of each sensor
		MovingAverage<unsigned int, 3> averages[SONAR_ARRAY_SENSORS] =
		{
			MovingAverage<unsigned int, 3>(MAX_RANGEFINDER_DISTANCE),
			MovingAverage<unsigned int, 3>(MAX_RANGEFINDER_DISTANCE),
			MovingAverage<unsigned int, 3>(MAX_RANGEFINDER_DISTANCE),
			MovingAverage<unsigned int, 3>(MAX_RANGEFINDER_DISTANCE),
			MovingAverage<unsigned int, 3>(MAX_RANGEFINDER_DISTANCE),
			MovingAverage<unsigned int, 3>(MAX_RANGEFINDER_DISTANCE)
		};
	private:
		void OneSensorCycle();

		unsigned long pingTimer[SONAR_ARRAY_SENSORS]; // Holds the times when the next ping should happen for each sensor.
		unsigned int cm[SONAR_ARRAY_SENSORS];         // Where the ping distances are stored.
		unsigned int angles[SONAR_ARRAY_SENSORS] = SONAR_ARRAY_ANGLES;  // Stores the angle of each of the sensors in the sonar

		uint8_t currentSensor = 0;          // Keeps track of which sensor is active.
	};
};