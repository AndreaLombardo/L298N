# L298N Library

An easy to use L298N library to control DC Motors with Arduino.

## NOTICE

~~As you know, any L298N module has the ability to drive two motors at once, but you may not know that one instance of the library is intended to pilot only one motor. So if you need to drive two motors, you have to instantiate two L298N objects (one for each motor).~~

To instantiate both motors at once use the L298NX2 variant of the library.

L298NX2 is not a new version of module or IC,
but it stands for a double implementation of L298N library.

## INSTALL THE LIBRARY

Download this repository as a .zip file and from the Arduino IDE go to _Sketch -> Include library -> Add .ZIP Library_

## IMPORT

You can import the library in your code using the Arduino IDE going to _Sketch -> Include library -> L298N_
or directly writing the include statement in your code:

```
// For single motor instance
#include <L298N.h>
```

```
// For two motors instance at once
#include <L298NX2.h>
```

## INSTANTIATE THE MODULE

To drive a motor the first thing is to create an instance of the library.

```
// With Enable pin to control speed
L298N myMotor(EN, IN1, IN2);
```

```
// Without Enable pin with jumper in place
L298N myMotor(IN1, IN2);
```

- EN = is the Arduino pin (requires a PWM pin) connected to the Enable pin of the module
- IN1 and IN2 are the two digital pins connected to IN1 and IN2 pins of the module

### Same thing for L298NX2 variant

```
// With Enable pin to control speed

                     motor A            motor B
              |------------------||------------------|
L298NX2 myMotors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);
```

```
// Without Enable pin and jumper in place

                  motor A      motor B
              |------------||------------|
L298NX2 myMotors(IN1_A, IN2_A, IN1_B, IN2_B);
```

## L298N Methods

| Method           | Params                                                                     | Description                                                                                                                                     |
| :--------------- | :------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------- |
| **setSpeed**     | unsigned short pwmVal                                                      | Set the PWM value used to determine the motor speed. Value from 0 to 255.                                                                       |
| **getSpeed**     | none                                                                       | Get the speed previously set.                                                                                                                   |
| **forward**      | none                                                                       | Run motor in forward direction (depends on wiring).                                                                                             |
| **forwardFor**   | unsigned long delay                                                        | Run motor in forward direction for a time specified by delay.                                                                                   |
| **forwardFor**   | unsigned long delay, CallBackFunction callback                             | Run motor in forward direction for a time specified by delay, after moving execute a callback function.                                         |
| **backward**     | none                                                                       | Run motor in backward direction (depends on wiring).                                                                                            |
| **backwardFor**  | unsigned long delay                                                        | Run motor in backward direction for a time specified by delay.                                                                                  |
| **backwardFor**  | unsigned long delay, CallBackFunction callback                             | Run motor in backward direction for a time specified by delay, after moving execute a callback function.                                        |
| **run**          | uint8_t direction                                                          | Move motor. To specify the direction use one of _L298N::FORWARD_, _L298N::BACKWARD_ or _L298N::STOP_.                                           |
| **runFor**       | unsigned long delay, L298N::Direction direction                            | Like _forwardFor_ or _backwardFor_ but more flexible. To specify the direction use one of _L298N::FORWARD_, _L298N::BACKWARD_ or _L298N::STOP_. |
| **runFor**       | unsigned long delay, L298N::Direction direction, CallBackFunction callback | Like previous with the ability to execute a callback function.                                                                                  |
| **stop**         | none                                                                       | Stop the motor.                                                                                                                                 |
| **reset**        | none                                                                       | Used to re-enable motor movements after the use of _runFor_, _forwardFor_ or _backwardFor_ methods.                                             |
| **isMoving**     | none                                                                       | Returns a boolean indicating if motor is running or not.                                                                                        |
| **getDirection** | none                                                                       | Returns the current **L298N::Direction**.                                                                                                       |

#### Direction

| Constant        | Int Value |
| :-------------- | :-------: |
| L298N::FORWARD  |     0     |
| L298N::BACKWARD |     1     |
| L298N::STOP     |    -1     |

## L298NX2 Methods

L298NX2 have the same methods of L298N identified by A or B suffix to drive each motor. For example setSpeed for motor A is setSpeedA and setSpeedB for motor B.

Methods without suffix, will affects both motors.

| Method      | Params                                                                     |
| :---------- | :------------------------------------------------------------------------- |
| setSpeed    | unsigned short pwmVal                                                      |
| forward     | none                                                                       |
| forwardFor  | unsigned long delay, CallBackFunction callback                             |
| forwardFor  | unsigned long delay                                                        |
| backward    | none                                                                       |
| backwardFor | unsigned long delay, CallBackFunction callback                             |
| backwardFor | unsigned long delay                                                        |
| run         | uint8_t direction                                                          |
| runFor      | unsigned long delay, L298N::Direction direction                            |
| runFor      | unsigned long delay, L298N::Direction direction, CallBackFunction callback |
| stop        | none                                                                       |
| reset       | none                                                                       |

## Examples

Examples can be founds in the examples folder or if installed in Arduino IDE, by the Menu -> File -> Example -> L298N.

Wiring schema can be found in _schema_ folder.

## Donations

Coffees are accepted!
:coffee: [PayPal Donations Here](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=GRNEA99RCC3U4) :coffee:

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=GRNEA99RCC3U4)
