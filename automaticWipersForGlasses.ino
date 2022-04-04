#include <Servo.h> // Servo libary is used to control servo motors that are used as wipers.

#define SERVO_PIN 9        // Arduino pin for servo
#define RAIN_SENSOR_PIN A0 // Arduino pin for rain sensor

#define RAIN_MAX 1023           // Rain sensor max value
#define RAIN_MIN 0              // Rain sensor min value
#define SERVO_START_POSITION 90 // Starting position for servos
#define SERVO_STOP_POSITION 0   // End position for servos
#define SERVO_WIPE_SPEED 5      // Delay speed for swiping
#define HEAVY_RAIN_MARGIN 300   // Rain sensor margins
#define MEDIUM_RAIN_MARGIN 500
#define NO_RAIN_MARGIN 700

#define HEAVY_RAIN_DELAY 500   // Delay values in ms
#define MEDIUM_RAIN_DELAY 1000 // Delay values in ms
#define LOW_RAIN_DELAY 2000    // Delay values in ms
#define NO_RAIN_DELAY 2000     // Delay values in ms

Servo myServo;                            // initialising Servo object
int sensorValue = 0;                      // initialising variable to store analouge value of rain sensor
int servoPosition = SERVO_START_POSITION; // intialising variable to store value of servos position
                                          // (servo can move from 0 degres to 180 degres, more accuratly sg90 can move from -90 to 90 degres)

void setup()
{
  myServo.attach(SERVO_PIN); // Sets servo object pin to forwarded value
  myServo.write(servoPosition);

  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sensorValue > NO_RAIN_MARGIN) // No rain
  {
    Serial.println("No rain!");
    myServo.write(SERVO_START_POSITION);
    delay(NO_RAIN_DELAY);
  }
  if (sensorValue <= NO_RAIN_MARGIN && sensorValue > MEDIUM_RAIN_MARGIN) // Low rain fall
  {
    Serial.println("Low rain fall!");
    for (servoPosition = SERVO_START_POSITION; servoPosition >= SERVO_STOP_POSITION; servoPosition -= 1) // these two for loops move srvo motor in controled fashion,
    {                                                                                                    // and cycle from SERVO_START_POSITION to SERVO_STOP_POSITION.
      myServo.write(servoPosition);                                                                      // It repeats for
      delay(SERVO_WIPE_SPEED);
    }
    for (servoPosition = SERVO_STOP_POSITION; servoPosition <= SERVO_START_POSITION; servoPosition += 1)
    {
      myServo.write(servoPosition);
      delay(SERVO_WIPE_SPEED);
    }
    delay(LOW_RAIN_DELAY);
  }

  if (sensorValue <= MEDIUM_RAIN_MARGIN && sensorValue > HEAVY_RAIN_MARGIN) // Medium rain fall
  {
    Serial.println("Medium rain fall!");
    for (servoPosition = SERVO_START_POSITION; servoPosition >= SERVO_STOP_POSITION; servoPosition -= 1)
    {
      myServo.write(servoPosition);
      delay(SERVO_WIPE_SPEED);
    }
    for (servoPosition = SERVO_STOP_POSITION; servoPosition <= SERVO_START_POSITION; servoPosition += 1)
    {
      myServo.write(servoPosition);
      delay(SERVO_WIPE_SPEED);
    }
    delay(MEDIUM_RAIN_DELAY);
  }

  if (sensorValue < HEAVY_RAIN_MARGIN) // high rain fall
  {
    Serial.println("high rain fall!");
    for (servoPosition = SERVO_START_POSITION; servoPosition >= SERVO_STOP_POSITION; servoPosition -= 1)
    {
      myServo.write(servoPosition);
      delay(SERVO_WIPE_SPEED);
    }
    for (servoPosition = SERVO_STOP_POSITION; servoPosition <= SERVO_START_POSITION; servoPosition += 1)
    {
      myServo.write(servoPosition);
      delay(SERVO_WIPE_SPEED);
    }
    delay(HEAVY_RAIN_DELAY);
  }
}
