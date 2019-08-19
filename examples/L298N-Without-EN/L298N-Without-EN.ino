#include <L298N.h>

//pin definition (They should be PWM pins)
#define IN1_PWM 10
#define IN2_PWM 9
#define IN3_PWM 6
#define IN4_PWM 5

//create a motor instance
L298N motor1(IN1_PWM, IN2_PWM);
L298N motor2(IN3_PWM, IN4_PWM);

void setup() {

  //used for display information
  Serial.begin(9600);

  motor1.setSpeed(180); // an integer between 0 and 255
  motor2.setSpeed(180); // an integer between 0 and 255

}

void loop() {

  //tell the motor to go forward (may depend by your wiring)
  motor1.forward();
  motor2.forward();

  //print the motor satus in the serial monitor
  Serial.print("Is moving motor1 = ");
  Serial.println(motor1.isMoving());
  Serial.print("Is moving motor2 = ");
  Serial.println(motor2.isMoving());

  delay(3000);

  //stop running
  motor1.stop();
  motor2.stop();

  Serial.print("Is moving motor1= ");
  Serial.println(motor1.isMoving());
  Serial.print("Is moving motor2= ");
  Serial.println(motor2.isMoving());

  delay(3000);

  //change the initial speed
  motor1.setSpeed(200);
  motor2.setSpeed(200);

  //tell the motor to go back (may depend by your wiring)
  motor1.backward();
  motor2.backward();

  Serial.print("Is moving motor1= ");
  Serial.println(motor1.isMoving());
  Serial.print("Is moving motor2= ");
  Serial.println(motor2.isMoving());

  delay(3000);

  //stop running
  motor1.stop();
  motor2.stop();
  Serial.print("Is moving motor1= ");
  Serial.println(motor1.isMoving());
  Serial.print("Is moving motor2= ");
  Serial.println(motor2.isMoving());

  //change the initial speed
  motor1.setSpeed(255);
  motor2.setSpeed(255);

  Serial.print("Get new speed motor1= ");
  Serial.println(motor1.getSpeed());
  Serial.print("Get new speed motor2= ");
  Serial.println(motor2.getSpeed());

  delay(3000);
}
