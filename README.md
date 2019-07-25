# California
Stepper Motor Control

by Joe Zawisa

## Commands
Using a serial monitor, one-letter commands can be sent to the machine.

### Speed
~~~
S <mmPerSecond>
~~~
Sets the speed of the motor to `<mmPerSecond` millimeters per second. Accepts positive values.

### Rotate
~~~
R <numberOfSteps>
~~~
Rotates the motor `<numberOfSteps>` steps. Accepts positive and negative values.

### Revolve
~~~
V <numberOfRevs>
~~~
Revolves the motor `<numberOfRevs>` revolutions. Accepts positive and negative values.

### Move
~~~
M <distance>
~~~
Moves the motor `<distance>` millimeters. Accepts positive and negative values.

### Square
~~~
Q <distance> <hold> <cycles>
~~~
Powers the motor with a square wave. Repeats `<cycles>` times:
1. Move +`<distance>` millimeters.
2. Pause for `<hold>` milliseconds.
3. Move -`<distance>` millimeters.
4. Pause for `<hold>` milliseconds.

Accepts positive or negative values for `<distance>` and only positive values for `<hold>` and `<cycles>`.
