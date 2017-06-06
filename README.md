# L298N Library
A easy to use L298N library to control DC Motors with Arduino.

## NOTICE
As you know, any L298N module have the ability to drive two motors at once, but you may know that any instance of the library is intended to pilot only one motor. So if you need to drive two motros, you have to instance two L298N object (one for each motor).

## INSTALL THE LIBRARY
Download this repository as a .zip file and from the Arduino IDE go to *Sketch -> Include library -> Add .ZIP Library*

## IMPORT
You can import the library in your code using the Arduino IDE going to *Sketch -> Include library -> L298N*
or directly writing the include statement in your code:

```
#include <L298N.h>
```
## INSTANCE THE MODULE
To drive a motor the first think is to create an istance of the library.
```
L298N myMotor(EN, IN1, IN2);
```
* EN = is the Arduino pin (required PWM pin) connected to the pin Enable of the module
* IN1 and IN2 are two digital pin connected to IN1 and IN2 of the module

*writing documentation stay tuned*