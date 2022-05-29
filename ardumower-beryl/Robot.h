
/*
	Created:	2016-12-21
	Author:	Nahuel Taibo  savagemakers.com
*/

#ifndef ROBOT_H
#define ROBOT_H

#include "Arduino.h"
#include "Configuration.h"

#if defined DRIVER_MC33926
#include "DualMC33926MotorShield.h"
#elif defined DRIVER_MC33926
#include "L298NMotorDriver.h"
#endif

#include "DifferentialDriveController.h"
#include "UltrasonicSensorArrayDriver.h"

namespace Ardumower
{
	class Robot
	{
	public:
		Robot();
		void Update();
	private:
		//We will use this variables to change the robot speed on after some seconds (without using delays)
		unsigned long previousTime = millis();
		unsigned int updateFreq = 5000;


		L298NMotorDriver rightMotor;
		L298NMotorDriver leftMotor;
		DifferentialDriveController difDrive;
		UltrasonicSensorArrayDriver sonar; //The rest of the sonar configuration is placed in Configuration.h
	};
};

#endif