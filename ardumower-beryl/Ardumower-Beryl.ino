/*
Name:		Ardumower.ino
Created:	12/13/2016 10:27:53 AM
Author:	Nahuel Taibo  savagemakers.com
*/

#include <Arduino.h>
#include "Robot.h"
#include <Wire.h>
#include "Configuration.h"
//#include <Servo.h>
#if defined __AVR_ATmega2560__
  // Arduino Mega
  #include <EEPROM.h>
#elif defined __SAM3X8E__
	// Arduino Due
#else
  #error "Wrong Arduino board - Choose Arduino Mega or Arduino Due (recommended) in Arduino IDE"
#endif



using namespace Ardumower;

Robot robot;

void setup()
{
	// Configure the Serial to get the logging output
	Serial.begin(115200);

	Serial.println("Ardumower Started.");
}

void loop()
{
	robot.Update();
}