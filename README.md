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
The project consisted of two scripts that allowed for serial Bluetooth communication between the Raspberry Pi and the ESP32:

* An Arduino script that setup the ESP32 for serial Bluetooth communication with the Raspberry Pi. The ESP32 would acquire three input values from the user/environment; two capacitive touch sensors and one photoresistor. One capacitive touch sensor would sense for a "double tap" while the other touch sensor would sense for any touch occurrence. The photoresistor would sense the amount of light in its environment. While on, the ESP32 would send messages to the Raspberry Pi based on the current input values.
* A python script that ran on the Raspberry Pi. The script would setup a connection over Bluetooth with the ESP32. Once the connection is made the Raspberry Pi would start receiving messages from the ESP32. These messages would be used to control both the fireplace and the music.

# Running the Simulator
In order to run this program, you first need to setup the hardware. Start by plugging in the ESP32 into the breadboard's GPIO at the top of the board. Then plug in the two capacitive touch sensor wires, the LED, and the photoresistor into the GPIOS of your ESP32. Once the hardware is setup, edit any input pin numbers in the SmartCandle.ino file to the GPIO pin numbers you used for your inputs. Then, follow the instructions below to setup Bluetooth communication on your ESP32 and Raspberry Pi. After that you want to install [vlc-ctrl](https://pypi.org/project/vlc-ctrl/) and [omxplayer](https://github.com/popcornmix/omxplayer) on the Raspberry Pi for control of the music and fireplace video. Then upload your favorite music to your Raspberry Pi and create a playlist in the VLC app. After that you have to upload a video for your fireplace. Finally, run an updated version of SmartCandle.py on your Raspberry Pi with the bluetooth address of your ESP32 and the file path to both your fireplace video and music playlist.

# Technical Issues
The hardest thing for me was building a "conveyer belt" system that would not fall apart and break every second and one that can hold/balance the weight of the mini hoop! Another issue I had was trying to figure out a way to sense a ball going through the hoop. I ended up using a photoresistor and a piece of cardboard that would cover the photoresistor when a ball went through but this way of sensing was very inconsistent. Finally, I tried using the ESP32 to communicate serially with the Arduino Uno(over their respective serial pins) so the ESP32 could tell the Arduino Uno(does not have WIFI onboard and thus could not read from web-server/API) when the web-server/API read "true". However, this was not working at all so I decided not to do it.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=fLeUoNfXLaA).
