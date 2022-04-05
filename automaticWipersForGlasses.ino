#include <Servo.h> // Servo libary is used to control servo motors that are used as wipers.

#define SERVO_RIGHT_PIN 9 // Arduino pin for servo
#define SERVO_LEFT_PIN 10
#define RAIN_SENSOR_PIN A0 // Arduino pin for rain sensor

#define RAIN_MAX 1023                  // Rain sensor max value
#define RAIN_MIN 0                     // Rain sensor min value
#define SERVO_LEFT_START_POSITION 90   // Starting position for servos
#define SERVO_LEFT_STOP_POSITION 180   // End position for servos
#define SERVO_RIGHT_START_POSITION 180 // Starting position for servos
#define SERVO_RIGHT_STOP_POSITION 90   // End position for servos
#define SERVO_WIPE_SPEED 5             // Delay speed for swiping
#define HEAVY_RAIN_MARGIN 300          // Rain sensor margins
#define MEDIUM_RAIN_MARGIN 500
#define NO_RAIN_MARGIN 700

#define BAUD_RATE 9600 // Baud rate for serial communication

#define HEAVY_RAIN_DELAY 300  // Delay values in ms
#define MEDIUM_RAIN_DELAY 100 // Delay values in ms
#define LOW_RAIN_DELAY 2000   // Delay values in ms
#define NO_RAIN_DELAY 2000    // Delay values in ms

Servo ServoRight; // initialising Servo object
Servo ServoLeft;
int sensorValue = 0; // initialising variable to store analouge value of rain sensor
// int servoPositionRight = SERVO_START_POSITION; // intialising variable to store value of servos position
// (servo can move from 0 degres to 180 degres, more accuratly sg90 can move from -90 to 90 degres)

int servoPositionRight = 180;
int servoPositionLeft = 90;

void setup()
{
  ServoRight.attach(SERVO_RIGHT_PIN); // Sets servo object pin to forwarded value
  ServoRight.write(servoPositionRight);

  ServoLeft.attach(SERVO_LEFT_PIN);
  ServoLeft.write(servoPositionLeft);

  Serial.begin(BAUD_RATE);
}

void loop()
{

  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sensorValue > NO_RAIN_MARGIN) // No rain
  {
    Serial.println("No rain!");
    ServoRight.write(servoPositionRight);
    ServoLeft.write(servoPositionLeft);
    delay(NO_RAIN_DELAY);
  }
  if (sensorValue <= NO_RAIN_MARGIN && sensorValue > MEDIUM_RAIN_MARGIN) // Low rain fall
  {
    Serial.println("Low rain fall!");
    for (servoPositionRight = SERVO_RIGHT_START_POSITION, servoPositionLeft = SERVO_LEFT_START_POSITION; servoPositionRight > SERVO_RIGHT_STOP_POSITION && servoPositionLeft < SERVO_LEFT_STOP_POSITION; servoPositionRight--, servoPositionLeft++)
    {
      ServoRight.write(servoPositionRight);
      ServoLeft.write(servoPositionLeft);
      delay(SERVO_WIPE_SPEED);
    }

    for (servoPositionRight = SERVO_RIGHT_STOP_POSITION, servoPositionLeft = SERVO_LEFT_STOP_POSITION; servoPositionRight < SERVO_RIGHT_START_POSITION && servoPositionLeft > SERVO_LEFT_START_POSITION; servoPositionRight++, servoPositionLeft--)
    {
      ServoRight.write(servoPositionRight);
      ServoLeft.write(servoPositionLeft);
      delay(SERVO_WIPE_SPEED);
    }
    delay(LOW_RAIN_DELAY);
  }

  if (sensorValue <= MEDIUM_RAIN_MARGIN && sensorValue > HEAVY_RAIN_MARGIN) // Medium rain fall
  {
    Serial.println("Medium rain fall!");
    for (servoPositionRight = SERVO_RIGHT_START_POSITION, servoPositionLeft = SERVO_LEFT_START_POSITION; servoPositionRight > SERVO_RIGHT_STOP_POSITION && servoPositionLeft < SERVO_LEFT_STOP_POSITION; servoPositionRight--, servoPositionLeft++)
    {
      ServoRight.write(servoPositionRight);
      ServoLeft.write(servoPositionLeft);
      delay(SERVO_WIPE_SPEED);
    }

    for (servoPositionRight = SERVO_RIGHT_STOP_POSITION, servoPositionLeft = SERVO_LEFT_STOP_POSITION; servoPositionRight < SERVO_RIGHT_START_POSITION && servoPositionLeft > SERVO_LEFT_START_POSITION; servoPositionRight++, servoPositionLeft--)
    {
      ServoRight.write(servoPositionRight);
      ServoLeft.write(servoPositionLeft);
      delay(SERVO_WIPE_SPEED);
    }
    delay(MEDIUM_RAIN_DELAY);
  }

  if (sensorValue < HEAVY_RAIN_MARGIN) // high rain fall
  {
    Serial.println("High rain fall!");
    for (servoPositionRight = SERVO_RIGHT_START_POSITION, servoPositionLeft = SERVO_LEFT_START_POSITION; servoPositionRight > SERVO_RIGHT_STOP_POSITION && servoPositionLeft < SERVO_LEFT_STOP_POSITION; servoPositionRight--, servoPositionLeft++)
    {
      ServoRight.write(servoPositionRight);
      ServoLeft.write(servoPositionLeft);
      delay(SERVO_WIPE_SPEED);
    }

    for (servoPositionRight = SERVO_RIGHT_STOP_POSITION, servoPositionLeft = SERVO_LEFT_STOP_POSITION; servoPositionRight < SERVO_RIGHT_START_POSITION && servoPositionLeft > SERVO_LEFT_START_POSITION; servoPositionRight++, servoPositionLeft--)
    {
      ServoRight.write(servoPositionRight);
      ServoLeft.write(servoPositionLeft);
      delay(SERVO_WIPE_SPEED);
    }
    delay(HEAVY_RAIN_DELAY);
  }
}
