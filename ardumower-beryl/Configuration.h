/*

choose your robot type, PCB version, baud rates, pin definitions etc.

*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Arduino.h"


// ------- Choose motor driver (MC33926 is recommended) -----------------------
#define DRIVER_MC33926
//#define DRIVER_L298N

// Pin definitions for the L298N Motor driver 
// Change this defines according to your hardware configuration
#define PIN_L298N_ENA PIN2
#define PIN_L298N_IN1 PIN3
#define PIN_L298N_IN2 PIN4
#define PIN_L298N_IN3 PIN5
#define PIN_L298N_IN4 PIN6
#define PIN_L298N_ENB PIN7


// PIN CONFIGURATION - Sonar Array
#define PIN_HCSR04_0 34
#define PIN_HCSR04_1 45
#define PIN_HCSR04_2 35
#define PIN_HCSR04_3 44
#define PIN_HCSR04_4 36
#define PIN_HCSR04_5 43
#define SONAR_ARRAY_ANGLES { 75, 105, 45, 135, 15, 165 }

// Pin Definitions for the HC-SR04 DistanceSensor
#define MAX_RANGEFINDER_DISTANCE 200

#endif