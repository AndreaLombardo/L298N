/*
Author  : Andrea Lombardo
Site    : https://www.lombardoandrea.com
Source  : https://github.com/AndreaLombardo/L298N/

Here you can see how to work with callback option.

Every five seconds callback function is called and increasing the speed.
When maximum speed is reached then starts again from zero.

In the meaning time your loop cycle is never blocked.

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

// Initial speed
unsigned short theSpeed = 0;

void setup()
{
  // Set initial speed
  motor.setSpeed(theSpeed);
}

void loop()
{
  // Move motor for 5 seconds and then execute the callback function
  // Easy way
  motor.forwardFor(5000, callback);

  // More flexible way
  // motor.runFor(5000, L298N::FORWARD, callback);
}

/*
Each time the callback function is called increase the speed of the motor or reset to 0.
This function can be named with any name. 
*/
void callback()
{

  // If speed is over 255 then encrease
  if (theSpeed <= 255)
  {
    theSpeed += 25;
  }
  else
  {
    theSpeed = 0;
  }

  /*
  Each time a callback function is called
  the motor is placed in "don't move" status
  To restore it's capability use reset() method.
  */
  motor.reset();

  // Set the new speed
  motor.setSpeed(theSpeed);
}
