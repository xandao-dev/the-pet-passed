#include <Arduino.h>
#include "Adafruit_VL53L0X.h"

#define SCL_PIN D1
#define SDA_PIN D2
#define BUZZER_PIN D3
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup()
{
	pinMode(BUZZER_PIN, OUTPUT);
	/* Serial.begin(115200);
	while (!Serial)
	{
		delay(1);
	} */
	if (!lox.begin())
	{
		exit(1);
	}
	lox.startRangeContinuous();
}

void loop()
{
	if (!lox.isRangeComplete())
	{
		return;
	}
	int distance = lox.readRange();
	// Serial.println(distance);
	if (distance >= 560 && distance <= 1000)
	{
		digitalWrite(BUZZER_PIN, HIGH);
	}
	else
	{
		digitalWrite(BUZZER_PIN, LOW);
	}
}
