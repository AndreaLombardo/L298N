#include <L298N.h>

//pin definition
#define EN 9
#define IN1 8
#define IN2 7

//create a motor instance
L298N motor(EN, IN1, IN2);

void setup() {

  //used for display information
  Serial.begin(9600);

  motor.setSpeed(80); // an integer between 0 and 255

}

void loop() {

  //tell the motor to go forward (may depend by your wiring)
  motor.forward();

  //print the motor satus in the serial monitor
  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  //stop running
  motor.stop();

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  //change the initial speed
  motor.setSpeed(100);

  //tell the motor to go back (may depend by your wiring)
  motor.backward();

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  delay(3000);

  //stop running
  motor.stop();

  Serial.print("Is moving = ");
  Serial.println(motor.isMoving());

  //change the initial speed
  motor.setSpeed(255);

  Serial.print("Get new speed = ");
  Serial.println(motor.getSpeed());

  delay(3000);
}
