#include "HCSR04DistanceSensorDriver.h"

using namespace Ardumower;

HCSR04DistanceSensorDriver::HCSR04DistanceSensorDriver(bool isEnabled, bool isVerbose, unsigned int maxDistance, unsigned int pinTrigger, unsigned int pinEcho)
	: DistanceSensorDriver(isEnabled, isVerbose, maxDistance),
	sensor(pinTrigger, pinEcho, maxDistance), // create the NewPing sensor instance
	average(maxDistance) // Start the average readings at the maxDistance value
{
	// Set the latest distance to the maximum, so the sensor does not start with a fake super close reading
	_latestDistance = maxDistance;
}

unsigned int HCSR04DistanceSensorDriver::GetDistance()
{
	if (IsEnabled())
	{
		// We can only ping the sensor every 30ms, so we will do that, 
		// the rest of the calls to GetDistance will return the latest reading without pingig the sensor again  
		if (_lastReadingTime + MAX_READING_FREQUENCY <= millis())
		{
			// As enough time have passed, we can update the reading
			_latestDistance = sensor.ping_cm();

			// The NewPing library returns 0 when it does not detect an object.
			// We want this service to return the MaxDistance, so we dont get confuse this with a super close object
			if (_latestDistance == 0)
			{
				_latestDistance = GetMaxDistance();
			}

			average.Add(_latestDistance);

			if (IsVerbose())
			{
				// We will only print the distance when we got a real update
				Serial.print(F("HCSR04: d="));
				Serial.print(_latestDistance);
				Serial.println(F(" cm"));
			}
		}

		return _latestDistance;
	}
}

unsigned int HCSR04DistanceSensorDriver::GetAverageDistance()
{
	// Make the ping only if we shold
	GetDistance();

	// Now get the latest average
	unsigned int latestAverage = average.Get();

	if (IsVerbose())
	{
		// We will only print the distance when we got a real update
		Serial.print(F("HCSR04: a="));
		Serial.print(latestAverage);
		Serial.println(F(" cm"));
	}

	// return the average of the latest pings
	return latestAverage;
}
