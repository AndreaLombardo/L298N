/*
Author  : Andrea Lombardo
Site    : https://www.lombardoandrea.com
Source  : https://github.com/AndreaLombardo/L298N/

Here you can see how to work in a common configuration without the needed of Enable pin. 

Make sure your module has a jumper in place.

L298NX2 is not a new version of module or IC, 
but it stands for a double implementation of L298N library.

With L298NX2 is possible to initialize two motors at once.

When L298N has a jumper instead of Enable pin, the speed is always 255.

Wiring schema in file "L298NX2 - Schema_without_EN_pin.png"
*/

// Include the (new) library
#include <L298NX2.h>

// Pin definition
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 6;

const unsigned int IN1_B = 7;
const unsigned int IN2_B = 8;

// Initialize both motors
L298NX2 motors(IN1_A, IN2_A, IN1_B, IN2_B);

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
  // Tell both motors to go forward (may depend by your wiring)
  motors.forward();

  // Alternative method:
  // motors.run(L298N::FORWARD);

  //print the motor status in the serial monitor
  printSomeInfo();

  delay(3000);

  // Stop
  motors.stop();

  // Alternative method:
  // motors.run(L298N::STOP);

  printSomeInfo();

  delay(3000);

  // Tell motor A to go back (may depend by your wiring)
  motors.backwardA();

  // Alternative method:
  // motors.runA(L298N::BACKWARD);

  // Tell motor B to go forward (may depend by your wiring)
  motors.backwardB();

  // Alternative method:
  // motors.runB(L298N::FORWARD);

  printSomeInfo();

  delay(3000);

  // Stop
  motors.stop();

  printSomeInfo();

  delay(3000);
}

/*
Print some informations in Serial Monitor
*/
void printSomeInfo()
{
  Serial.print("Motor A is moving = ");
  Serial.println(motors.isMovingA() ? "YES" : "NO");
  Serial.print("Motor B is moving = ");
  Serial.println(motors.isMovingB() ? "YES" : "NO");
}