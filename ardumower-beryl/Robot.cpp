#include "Robot.h"

using namespace Ardumower;

Robot::Robot() :
	rightMotor(true, false, PIN_L298N_ENA, PIN_L298N_IN1, PIN_L298N_IN2),
	leftMotor(true, false, PIN_L298N_ENB, PIN_L298N_IN3, PIN_L298N_IN4),
	difDrive(true, true, &rightMotor, &leftMotor),
	sonar(true, true)
{
}

void Ardumower::Robot::Update()
{
	difDrive.Update();
	sonar.Update();

	// Do anything else we want to do...
	if ((previousTime + updateFreq) < millis())
	{
		previousTime = millis();

		if (difDrive.GetSpeed() > 0)
		{
			difDrive.SetSpeed(0, 180);
		}
		else
		{
			difDrive.SetSpeed(255, 180);
		}
	}
}
