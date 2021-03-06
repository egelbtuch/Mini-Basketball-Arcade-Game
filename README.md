# Mini Arcade Basketball Hoop
# Materials
* 2 Arduino Unos
* ESP32-Wrover-Dev
* 1 SPDT Switch
* 2 Breadboards
* Photoresistor
* Tons of Wires
* 9V Lithium Ion Battery Pack
* 5V Rechargeable Battery
* 2 18650 3.7V Rechargeable Lithium Battery
* 3 USB Cables
* 4-Digit 7-Segment Display
* 1 Servo Motor
* 1 DC Motor
* 1 Potentiometer w/ Knob
* L293D IC Chip with a 4-Channel Motor Drive
* Lots of Electrical Tape and Cardboard
* Rubber Bike Tire Tube 
* 4 Chopsticks
* 2 Small Plastic Spools 
* 1 Heavy Object (I used a heavy aux adapter)
* Mini Basketball Hoop w/ Balls
* Krazy Glue

# What does it do?
The basketball hoop system does a few things:

* The ESP32 controls the "conveyer belt system" which moves the hoop left and right. The hoop does not start moving until the ESP32 (connected to local WIFI) reads "true" from our class web-server/API. Once the ESP32 reads "true" the motors will start moving left and right in a loop until the ESP32 is shutoff or reset. If reset the ESP32 will again look for a "true" string on the web-server/API.
* One of the Arduino Unos controls the servo motor system which controls the ball shooting system. Once the Arduino is powered on it will continuously read the analog values coming from the potentiometer and move the servo accordingly.
* The second Arduino Uno controls the scoreboard system. Once the Arduino is powered on it will set the scoreboard to all zeros. It will then add 1 to the scoreboard every time the ball goes through the hoop (hitting a piece of cardboard that is covering the photoresistor). To reset the scoreboard to zeros the user needs to flip the SPDT switch behind the hoop(functioning as a flip flop switch).

# Project Overview
The project consisted of three scripts:

* The Arduino script Conveyer_Belt.ino that ran on the ESP32 which waited for the class web-server/API to return a string valued "true". I used this [link](https://randomnerdtutorials.com/esp32-http-get-post-arduino/) to setup the WIFI on the ESP32 and to setup the ESP32 for communication with the class web-server/API. Once the ESP32 reads "true" from the web-server/API the motors will start moving left and right in a loop until the ESP32 is shutoff or reset. If reset the ESP32 will again look for a "true" string on the web-server/API.
* The Arduino script Light_Sensor_and_LEDs.ino that ran on one of the Arduino Unos. The script was used to control the 4-digit 7-segment display(scoreboard) and took in two inputs. One input was from a SPDT switch and the other input was from a photoresistor located in the basket of the hoop. If the state of the switch changed the scoreboard would reset to zeros. The script would also check the analog input coming from the photoresistor and check if it was below a predefined threshold value, which would result in the scoreboard being updated to plus one of the current value(this signified a scored basket). I setup the 4-digit 7-segment display with the help of this [link](https://www.instructables.com/4-Digit-7-Segment-Timer-With-Reset-Button/).
* The Arduino script Servo-Potentiometer.ino that ran on the other Arduino Uno. It would continuously read the input analog signal from the potentiometer and would translate that value to an angle for the servo to move to.

# Technical Issues
The hardest thing for me was building a "conveyer belt" system that would not fall apart and break every second and one that can hold/balance the weight of the mini hoop! Another issue I had was trying to figure out a way to sense a ball going through the hoop. I ended up using a photoresistor and a piece of cardboard that would cover the photoresistor when a ball went through but this way of sensing was very inconsistent. Finally, I tried using the ESP32 to communicate serially with the Arduino Uno(over their respective serial pins) so the ESP32 could tell the Arduino Uno(does not have WIFI onboard and thus could not read from web-server/API) when the web-server/API read "true". However, this was not working at all so I decided not to do it.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=fLeUoNfXLaA).
