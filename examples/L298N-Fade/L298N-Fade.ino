/*
Author  : Andrea Lombardo
Site    : https://www.lombardoandrea.com
Source  : https://github.com/AndreaLombardo/L298N/

Based on Arduino Basic Fade example.

Speed range go from 0 to 255, default is 100.
Use setSpeed(speed) to change.

Sometimes at lower speed motors seems not running.
It's normal, may depends by motor and power supply.

Wiring schema in file "L298N - Schema_with_EN_pin.png"
*/

// Include the library
#include <L298N.h>

// Pin definition
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int EN = 9;

// Create one motor instance
L298N motor(EN, IN1, IN2);

int speedness = 0;
int speedAmount = 1;

void setup() {
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial) {
    // do nothing
  }
}

void loop() {
  // Apply faded speed
  motor.setSpeed(speedness);

  // Tell motor A to go forward (may depend by your wiring)
  motor.forward();

  // Alternative method:
  // motor.run(L298N::FORWARD);

  // print the motor status in the serial monitor
  printSomeInfo();

  // Change the "speedness" for next time through the loop:
  speedness = speedness + speedAmount;

  // Reverse the direction of the fading at the ends of the fade:
  if (speedness <= 0 || speedness >= 255) {
    speedAmount = -speedAmount;
  }

  // Wait for 30 milliseconds to see the dimming effect
  delay(30);
}

/*
Print some informations in Serial Monitor
*/
void printSomeInfo() {
  Serial.print("Motor is moving = ");
  Serial.print(motor.isMoving() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(motor.getSpeed());
}