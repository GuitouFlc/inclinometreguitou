# inclinometreguitou

Thanks to camerontech for is great job 

my sketch is only an adaptation of his repo.
https://github.com/camerontech/inclinometer

need one pin more but project teh LCD screen is less expensive.

Arduino Inclinometer

This sketch uses an accelerometer and serial-enabled 16x2 LCD or serial i2c LCD screen to measure and display pitch and roll of a vehicle. An inclinometer is usually used in offroading to determine how close you are to having a very bad day.

And a quick video in action: http://www.youtube.com/watch?v=Q_Gq_8f8r2c
Features

The inclinometer reads the X and Y values from the accelerometer and translates them into PITCH (forward and back tilt) and ROLL (left and right tilt). However, since we're only measuring acceleration we will get false readings when the sensor itself is in motion (like when you're driving in a car). To get a "true" reading of your pitch and roll you'll need to stop moving.
Equipment

    1 x Arduino nano or compatible board https://www.amazon.fr/SODIAL-ATmega328-P-20AU-Carte-Module/dp/B00QPUEFNW/
    1 x 16x2 serial-enabled i2c LCD  https://www.amazon.fr/gp/product/B00V4ISZCW/
    1 x ADXL335 triple axis accelerometer https://www.amazon.fr/SODIAL-ADXL335-numerique-gravite-dinclinaison/dp/B00V4PRRO2/

Wiring

Connect the accelerometer to 3.3V, GND, X to analog pin 0 and Y to analog pin 1 and Z to analog pin 2.

Connect the LCD to 5V, GND. Connect to analog pin sda pin 4 and scl pin 5 to on the Arduino.

layout

HAVE FUN ;)
