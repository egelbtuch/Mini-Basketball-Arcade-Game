/**********************************************************************
  Filename    : Control Servo by Potentiometer
  Description : Use potentiometer to control the rotation of servo motor.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 9;      // GPIO pin used to connect the servo control (digital out)
int potPin = 0;        // GPIO pin used to connect the potentiometer (analog in)
int potVal;             //variable to read the value from the analog pin

void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  potVal = analogRead(potPin);            // reads the value of the potentiometer (value between 0 and 1023)
  potVal = map(potVal, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(potVal);           
  delay(15);// wait for the servo to get there
}
