

#include "htu2x_lib.h"

void Htu2x_libClass::init()
{
	Wire.begin();

}

int Htu2x_libClass::read(byte commandByte)
{
	Wire.beginTransmission(SENSOR_ADDRESS);
	Wire.write(commandByte);
	Wire.endTransmission();
	delay(100); // <--- delay more than 50ms

	Wire.requestFrom(SENSOR_ADDRESS, 2);

	byte msByte = Wire.read(); // <---Right most bit
	byte lsByte = Wire.read();  // <---Left most bit
	int data = msByte << 8 | lsByte;
	return data;
}

float Htu2x_libClass::rh_calc()
{
	float rh = -6 + (float)125 * read(HUMIDITY_NO_HOLD) / 65536;
	return rh;
}

float Htu2x_libClass::temp_calc()
{
	float temp = -46.85 + (float)175.72 * read(TEMP_NO_HOLD) / 65536;
	return temp;
}

Htu2x_libClass Htu2x;

