#include "UltrasonicSensorArrayDriver.h"

using namespace Ardumower;

// As I cant do everything object oriented, this instance will be the way to merge both paradigms
UltrasonicSensorArrayDriver* UltrasonicSensorArrayDriverInstance;

void GlobalEchoCheck() { // If ping received, set the sensor distance to array.
	UltrasonicSensorArrayDriverInstance->EchoCheck();
}

UltrasonicSensorArrayDriver::UltrasonicSensorArrayDriver(bool isEnabled, bool isVerbose) : Driver(isEnabled, isVerbose)
{
	UltrasonicSensorArrayDriverInstance = this;

	if (IsEnabled())
	{
		pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
		for (uint8_t i = 1; i < SONAR_ARRAY_SENSORS; i++) // Set the starting time for each sensor.
			pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;

		if (IsVerbose())
		{
			Serial.println(F("Sonar configured."));
		}
	}
}

void UltrasonicSensorArrayDriver::Setup()
{
}

void UltrasonicSensorArrayDriver::Update()
{
	if (IsEnabled())
	{
		for (uint8_t i = 0; i < SONAR_ARRAY_SENSORS; i++)
		{
			// Loop through all the sensors.
			if (millis() >= pingTimer[i])
			{
				// Is it this sensor's time to ping?
				pingTimer[i] += PING_INTERVAL * SONAR_ARRAY_SENSORS;  // Set next time this sensor will be pinged.
				if (i == 0 && currentSensor == SONAR_ARRAY_SENSORS - 1)
				{
					OneSensorCycle(); // Sensor ping cycle complete, do something with the results.
				}
				sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
				currentSensor = i;                          // Sensor being accessed.
				cm[currentSensor] = MAX_RANGEFINDER_DISTANCE;           // Make distance MAX_DISTANCE in case there's no ping echo for this sensor.
				sonar[currentSensor].ping_timer(GlobalEchoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
			}
		}
	}
}

void UltrasonicSensorArrayDriver::PrintSonarArrayReadings()
{
	Serial.print("SAR|");
	for (int i = 0; i < SONAR_ARRAY_SENSORS; i++)
	{
		Serial.print(cm[i]);
		Serial.print("|");
	}
	Serial.println();
}

void UltrasonicSensorArrayDriver::PrintSonarArrayAverageReadings()
{
	Serial.print("SAA|");
	for (int i = 0; i < SONAR_ARRAY_SENSORS; i++)
	{
		Serial.print(averages[i].Get());
		Serial.print("|");
	}
	Serial.println();
}

unsigned int UltrasonicSensorArrayDriver::GetSonarSensorReading(byte sensorNumber)
{
	if (sensorNumber<0 || sensorNumber > SONAR_ARRAY_SENSORS)
	{
		if (IsVerbose())
		{
			Serial.print(F("ERROR: sensorNumber out of range: "));
			Serial.println(sensorNumber);
		}

		return 0;
	}

	return cm[sensorNumber];
}

unsigned int UltrasonicSensorArrayDriver::GetSonarSensorAverageReading(byte sensorNumber)
{
	if (sensorNumber<0 || sensorNumber > SONAR_ARRAY_SENSORS)
	{
		if (IsVerbose())
		{
			Serial.print(F("ERROR: sensorNumber out of range: "));
			Serial.println(sensorNumber);
		}

		return 0;
	}

	return averages[sensorNumber].Get();
}

unsigned int UltrasonicSensorArrayDriver::GetSonarSensorAngle(byte sensorNumber)
{
	if (sensorNumber<0 || sensorNumber > SONAR_ARRAY_SENSORS)
	{
		if (IsVerbose())
		{
			Serial.print(F("ERROR: sensorNumber out of range: "));
			Serial.println(sensorNumber);
		}

		return 0;
	}

	return angles[sensorNumber];
}

void UltrasonicSensorArrayDriver::EchoCheck()
{
	// If ping received, set the sensor distance to array.
	if (sonar[currentSensor].check_timer())
	{
		cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;

		//Add the reading to the averages of this specific sensor
		averages[currentSensor].Add(cm[currentSensor]);
	}
}

void UltrasonicSensorArrayDriver::OneSensorCycle()
{
	if (IsVerbose())
	{
		PrintSonarArrayReadings();
		PrintSonarArrayAverageReadings();
	}
}
