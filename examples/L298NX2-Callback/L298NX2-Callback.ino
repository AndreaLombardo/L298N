/*
Author  : Andrea Lombardo
Site    : https://www.lombardoandrea.com
Source  : https://github.com/AndreaLombardo/L298N/

Here you can see how to work with callback option.

L298NX2 is not a new version of module or IC, 
but it stands for a double implementation of L298N library.

With L298NX2 is possible to initialize two motors at once.

Speed range go from 0 to 255, default is 100.
Use setSpeed(speed) to change speed for both motors,
setSpeedA(speed) or setSpeedB(speed) for individual changes.

Sometimes at lower speed motors seems not running.
It's normal, may depends by motor and power supply.

Wiring schema in file "L298NX2 - Schema_with_EN_pin.png"
*/

// Include the (new) library
#include <L298NX2.h>

// Pin definition
const unsigned int EN_A = 3;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 6;

const unsigned int IN1_B = 7;
const unsigned int IN2_B = 8;
const unsigned int EN_B = 9;

// Initialize both motors
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);

// Initial speed
unsigned short theSpeedA = 55;
unsigned short theSpeedB = 255;

// Keep track of direction
unsigned int theDirection = 1;

void setup()
{

  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }

  Serial.println(F("Moving both motors for 4 seconds and print something at the end."));

  // Set individual speed
  motors.setSpeedA(theSpeedA);
  motors.setSpeedB(theSpeedB);

  // Print initial information
  printInfo();
}

void loop()
{

  // Move both motors for 4 seconds then execute callback function to switch direction
  // Each motor have opposite speed.
  if (theDirection)
  {
    motors.forwardFor(4000, callback);
  }
  else
  {
    motors.backwardFor(4000, callback);
  }
}

/*
Each time the callback function is called,
increase motorA speed and decrease motorB speed, then reset both.
*/
void callback()
{

  if (theSpeedA > 255 && theSpeedB < 55)
  {
    theDirection = !theDirection;
    Serial.println("Switching both direction.");
  }

  if (theSpeedA <= 255)
  {
    theSpeedA += 25;
  }
  else
  {
    theSpeedA = 55;
  }

  if (theSpeedB >= 55)
  {
    theSpeedB -= 25;
  }
  else
  {
    theSpeedB = 255;
  }

  // Set new speed for each motor
  motors.setSpeedA(theSpeedA);
  motors.setSpeedB(theSpeedB);

  // re-enable both motors movements
  motors.reset();

  // Print info
  printInfo();
}

/*
Print info in Serial Monitor
*/
void printInfo()
{
  Serial.print("Motor A Speed = ");
  Serial.println(motors.getSpeedA());

  Serial.print("Motor B Speed = ");
  Serial.println(motors.getSpeedB());
}
