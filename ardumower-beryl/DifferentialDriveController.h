#pragma once
#include "Controller.h"
#include "MotorDriver.h"

#define SPEED_UPDATE_FREQ 100

namespace Ardumower
{
	struct DifferentialVector
	{
		int Right;
		int Left;
	};

	class DifferentialDriveController : public Controller
	{
	public:
		DifferentialDriveController(bool isEnabled, bool isVerbose, MotorDriver* rightMotor, MotorDriver* leftMotor);

		void Update();

		void SetAcceleration(int acceleration);
		int GetAcceleration();

		// Sets the required speed and direction of movement
		// speed: valid range between 0 and 255
		// direction: between 0 and 360 degrees
		void SetSpeed(int speed, int direction);
		int GetSpeed();
		int GetDirection();

	private:
		MotorDriver* _rightMotor;
		MotorDriver* _leftMotor;

		// Acceleration (in speed units per 100 ms) used to modify the _currentSpeed, until we get to the _targetSpeed
		// Range goes between 1 and 255
		// If 255, the speed will be instantly assigned to the motors
		// ie: If _acceleration=1, _currentspeed will be increased in 1, every 100 ms, so if we start at _currentspeed=0 and _targetSpeed=255, it will take 25500ms (255*100) to get to full speed
		// ie: If _acceleration=10, _currentspeed will be increased in 10, every 100 ms, so if we start at _currentspeed=0 and _targetSpeed=255, it will take 2550ms ((255/10)*100) to get to full speed
		// ie: If _acceleration=100, _currentspeed will be increased in 100, every 100 ms, so if we start at _currentspeed=0 and _targetSpeed=255, it will take 255ms ((255/100)*100) to get to full speed
		unsigned int _acceleration = 15;

		// The last speed set to the motors
		int _currentspeed;

		// The speed we want to achieve, (we will get to this _targetSpeed ant _acceleration increments per second) 
		int _targetSpeed;
		int _direction;

		unsigned long _lastSpeedUpdate = 0;

		//calculates the speed each motor should have according with the calculated _currentspeed and updates them
		void UpdateMotorsSpeed();

		DifferentialVector CalculateDifferentialDrive(int radius, int angle);
	};
};
