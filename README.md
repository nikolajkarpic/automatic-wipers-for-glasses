# automatic-wipers-for-glasses
School project for sensors and actuators class.  
Arduino, two servos and a rain sensor are used to make wipers for glasses.

## Components used
Brief introduction to components that are used for this project.

### **Arduino Uno** 
The **Arduino Uno** is an open-source microcontroller board based on the Microchip **ATmega328P** microcontroller and developed by Arduino.cc.
The board is equipped with sets of digital and analog input/output (I/O) pins that may be interfaced to various expansion boards (shields)
and other circuits.The board has 14 digital I/O pins (six capable of PWM output), 6 analog I/O pins, and is programmable with the Arduino
IDE (Integrated Development Environment), via a type B USB cable. It can be powered by the USB cable or by an external 9-volt battery, 
though it accepts voltages between 7 and 20 volts. 

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Arduino_Uno_-_R3.jpg/330px-Arduino_Uno_-_R3.jpg">
</p>

For more information refer to [Arduino site](https://www.arduino.cc/).

### **Raindrop sensor** 
Raindrop Sensor is a tool used for sensing rain. It consists of two modules, a **rain board** that detects the rain and a **control module**, 
which compares the analog value, and converts it to a digital value. The raindrop sensors can be 
used in the automobile sector to control the windshield wipers automatically, in the agriculture sector to sense rain and it is also used in home automation systems. 
 
<p align="center">
<img width="300" height="300" src="https://components101.com/sites/default/files/component_pin/Raindrop-Sensor.jpg">
</p>
 
For more information refer to [article](https://components101.com/sensors/rain-drop-sensor-module).
 
### **SG-90** servo motor
Tiny and lightweight with high output power. Servo can rotate approximately 180 degrees (90 in each direction), and works just like the standard kinds
but smaller. You can use any servo code, hardware or library to control these servos. Good for beginners who want to make stuff move without building a
motor controller with feedback & gear box, especially since it will fit in small places.

Servo is controlled with [PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation) signal. Position "0" (1.5 ms pulse) is middle, "90" (~2ms pulse) is middle,
is all the way to the right, "-90" (~1ms pulse) is all the way to the left.


<p align="center">
<img width="300" height="300" src="https://cdn.bodanius.com/media/1/2ed102979_TowerPro-SG90-9G-micro-servo-motor_1500x750.webp"
</p>

For more information on this exact servo refer to this [datasheet](https://datasheetspdf.com/pdf/791970/TowerPro/SG90/1).
  
## Setup
To use this project you will need an Arduino uno board and the previosly stated sensors. 
The sowftware needed to compile and upload the code can be found on this [link](https://datasheetspdf.com/pdf/791970/TowerPro/SG90/1).
  
Define pins used to connect to arduino in automaticWipersForGlasses.ino file.
  
  `SERVO_RIGHT_PIN`
  
  `SERVO_LEFT_PIN`
  
  `RAIN_SENSOR_PIN `
  
Wire the sensor to `RAIN_SENSOR_PIN` and first servo to `SERVO_RIGHT_PIN` and the second to `SERVO_LEFT_PIN`  then wire up power suply. Push code to the Arduino board.
  
Code is hihgly modular, and it can be modified with ease by changing the couple of constants at the beggingin of the file. 
  
Sensor can be calibrated with these constants:
  
`HEAVY_RAIN_MARGIN`
  
`MEDIUM_RAIN_MARGIN` 

`NO_RAIN_MARGIN` 

  While servo speed, position and delay bettwen swipes can be calibrated with these constants:
  
  `SERVO_WIPE_SPEED`
  
  `SERVO_LEFT_START_POSITION`
  
  `SERVO_LEFT_STOP_POSITION`
  
  `SERVO_RIGHT_START_POSITION`
  
  `SERVO_RIGHT_STOP_POSITION`
  
  `HEAVY_RAIN_DELAY`
  
  `MEDIUM_RAIN_DELAY`
  
  `LOW_RAIN_DELAY`
  
  `NO_RAIN_DELAY`
  
  Baud rate is set with `BAUD_RATE`, serial communication is used for debbuging purposes mostly. As of now it shows wether its HEAVY, MEDIUM, LOW or NO rain fall.
  
  
  


  
  
  
