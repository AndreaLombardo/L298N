# L298N Library
A easy to use L298N library to control DC Motors with Arduino.

## NOTICE
As you know, any L298N module has the ability to drive two motors at once, but you may not know that one instance of the library is intended to pilot only one motor. So if you need to drive two motors, you have to instantiate two L298N objects (one for each motor).

## INSTALL THE LIBRARY
Download this repository as a .zip file and from the Arduino IDE go to *Sketch -> Include library -> Add .ZIP Library*

## IMPORT
You can import the library in your code using the Arduino IDE going to *Sketch -> Include library -> L298N*
or directly writing the include statement in your code:
```
#include <L298N.h>
```

## INSTANTIATE THE MODULE
To drive a motor the first thing is to create an instance of the library.
```
L298N myMotor(EN, IN1, IN2);
```
* EN = is the Arduino pin (requires a PWM pin) connected to the Enable pin of the module
* IN1 and IN2 are the two digital pins connected to IN1 and IN2 pins of the module

## Methods
| Method | Params | Description
| :----- | :---------- | :------
|**setSpeed**|unsigned short pwmVal| Set the PWM value used to determine the motor speed. Value from 0 to 255.
|**getSpeed**|none| Get the speed previously set.
|**forward**|none| Run motor in forward direction (depends on wiring).
|**forwardFor**|unsigned long delay| Run motor in forward direction for a time specified by delay.
|**forwardFor**|unsigned long delay, CallBackFunction callback| Run motor in forward direction for a time specified by delay, after moving execute a callback function.
|**backward**|none| Run motor in backward direction (depends on wiring).
|**backwardFor**|unsigned long delay| Run motor in backward direction for a time specified by delay.
|**backwardFor**|unsigned long delay, CallBackFunction callback| Run motor in backward direction for a time specified by delay, after moving execute a callback function.
|**run**|uint8_t direction| Move motor. To specify the direction use *L298N::FORWARD* or *L298N::BACKWARD*.
|**stop**|none| Stop the motor.
|**reset**|none| Used to re-enable motor movements after the use of forwardFor and backwardFor methods.
|**isMoving**|none| Returns a boolean indicating if motor is running or not.

## Donations
Coffees are accepted!
:coffee: [PayPal Donations Here](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=GRNEA99RCC3U4) :coffee:

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=GRNEA99RCC3U4)

*writing examples stay tuned*
