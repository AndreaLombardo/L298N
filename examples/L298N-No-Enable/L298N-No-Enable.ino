/*
Author  : Andrea Lombardo
Site    : https://www.lombardoandrea.com
Source  : https://github.com/AndreaLombardo/L298N/

Here you can see how to work in a common configuration without the needed of Enable pin. 

Make sure your module has a jumper in place.

When L298N has a jumper instead of Enable pin, the speed is always 255.

Wiring schema in file "L298N - Schema_without_EN_pin.png"
*/

// Include the library
#include <L298N.h>

// Pin definition
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;

// Create one motor instance
L298N motor(IN1, IN2);

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

  // Tell the motor to go forward (may depend by your wiring)
  motor.forward();

  // Alternative method:
  // motor.run(L298N::FORWARD);

  //print the motor status in the serial monitor
  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  // Stop
  motor.stop();

  // Alternative method:
  // motor.run(L298N::STOP);

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  // Tell the motor to go back (may depend by your wiring)
  motor.backward();

  // Alternative method:
  // motor.run(L298N::BACKWARD);

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  // Stop
  motor.stop();

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);
}
