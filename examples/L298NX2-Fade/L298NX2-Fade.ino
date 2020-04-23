/*
Author  : Andrea Lombardo
Site    : https://www.lombardoandrea.com
Source  : https://github.com/AndreaLombardo/L298N/

Based on Arduino Basic Fade example.

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

int speedness = 0;
int speedAmount = 1;

void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }
}

void loop()
{
  // Apply faded speed to both motors
  motors.setSpeed(speedness);

  // Tell motor A to go forward (may depend by your wiring)
  motors.forwardA();

  // Alternative method:
  // motors.runA(L298N::FORWARD);

  // Tell motor B to go forward (may depend by your wiring)
  motors.backwardB();

  // Alternative method:
  // motors.runB(L298N::BACKWARD);

  //print the motor status in the serial monitor
  printSomeInfo();

  // Change the "speedness" for next time through the loop:
  speedness = speedness + speedAmount;

  // Reverse the direction of the fading at the ends of the fade:
  if (speedness <= 0 || speedness >= 255)
  {
    speedAmount = -speedAmount;
  }
  // Wait for 30 milliseconds to see the dimming effect
  delay(30);
}

/*
Print some informations in Serial Monitor
*/
void printSomeInfo()
{
  Serial.print("Motor A is moving = ");
  Serial.print(motors.isMovingA() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedA());
  Serial.print("Motor B is moving = ");
  Serial.print(motors.isMovingB() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motors.getSpeedB());
}