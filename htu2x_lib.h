/*
	Name:    htu2x_humidity_temperature.ino
	Author:  Roshan S
*/

#include <Wire.h>

#ifndef _HTU2X_LIB_h
#define _HTU2X_LIB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Htu2x_libClass
{
 private:

	#define SENSOR_ADDRESS 0x40
	#define TEMP_HOLD 0XE3
	#define HUMIDITY_HOLD 0XE5
	#define TEMP_NO_HOLD 0xF3
	#define HUMIDITY_NO_HOLD 0xF5


 public:
	void init();
	int read(byte commandByte);
	float rh_calc();
	float temp_calc();
};

extern Htu2x_libClass Htu2x;

#endif

