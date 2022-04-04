#include <Servo.h>

#define SERVO_PIN 9
#define RAIN_SENSOR_PIN A0
#define RAIN_MAX 1023
#define RAIN_MIN 0
#define SERVO_START_POSITION 0
#define SERVO_STOP_POSITION 90
#define SERVO_WIPE_SPEED 5
#define HEAVY_RAIN_MARGIN 300
#define MEDIUM_RAIN_MARGIN 500
#define LOW_RAIN_MARGIN 700
#define NO_RAIN_MARGIN 1023

Servo myServo;

void setup()
{
  // put your setup code here, to run once:
  myServo.attach(SERVO_PIN);
  myServo.write(SERVO_START_POSITION);

    Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // Serial.println("radi");
  delay(1000);
}
