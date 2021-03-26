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
The candle-fireplace system turns "on" when the light in its environment drops below a specified threshold value. When the system turns "on" a few things will happen immediately. The candle's light will begin to flicker, a music playlist will start playing on the Raspberry Pi and a video of a fireplace will begin playing on the display. While, the system is "on" the ESP32 will check for a double tap/touch on the left aluminum foil side wall and for a press and hold on the right aluminum foil side wall. A double tap/touch will result in the Raspberry Pi changing the song to the next one in the playlist. While, a press and hold will change the volume of the music playing on the Raspberry Pi. If the light in the system's environment becomes larger than the threshold value everything will immediately shutoff and the display will go black. The system can be turned on and off continuously due to changes in light.

# Project Overview
The project consisted of two scripts that allowed for serial Bluetooth communication between the Raspberry Pi and the ESP32:

* An Arduino script that setup the ESP32 for serial Bluetooth communication with the Raspberry Pi. The ESP32 would acquire three input values from the user/environment; two capacitive touch sensors and one photoresistor. One capacitive touch sensor would sense for a "double tap" while the other touch sensor would sense for any touch occurrence. The photoresistor would sense the amount of light in its environment. While on, the ESP32 would send messages to the Raspberry Pi based on the current input values.
* A python script that ran on the Raspberry Pi. The script would setup a connection over Bluetooth with the ESP32. Once the connection is made the Raspberry Pi would start receiving messages from the ESP32. These messages would be used to control both the fireplace and the music.

# Running the Simulator
In order to run this program, you first need to setup the hardware. Start by plugging in the ESP32 into the breadboard's GPIO at the top of the board. Then plug in the two capacitive touch sensor wires, the LED, and the photoresistor into the GPIOS of your ESP32. Once the hardware is setup, edit any input pin numbers in the SmartCandle.ino file to the GPIO pin numbers you used for your inputs. Then, follow the instructions below to setup Bluetooth communication on your ESP32 and Raspberry Pi. After that you want to install [vlc-ctrl](https://pypi.org/project/vlc-ctrl/) and [omxplayer](https://github.com/popcornmix/omxplayer) on the Raspberry Pi for control of the music and fireplace video. Then upload your favorite music to your Raspberry Pi and create a playlist in the VLC app. After that you have to upload a video for your fireplace. Finally, run an updated version of SmartCandle.py on your Raspberry Pi with the bluetooth address of your ESP32 and the file path to both your fireplace video and music playlist.

# Communicating Over Bluetooth
This link helped me setup the ESP32 for Bluetooth communication [here](https://www.instructables.com/ESP32-Bluetooth-Tutorial-How-to-Use-Inbuilt-Blueto/) and these two links helped me setup the Raspberry Pi for Bluetooth communication [here](https://helloraspberrypi.blogspot.com/2020/12/python-on-raspberry-pi-bluetooth.html) & [here](https://github.com/pybluez/pybluez).

# Technical Issues
It seemed like the capacitive sensors were causing a bunch of problems with the electronics that were in close proximity to them and even the Bluetooth connection (but I am not 100% sure). So I tried to steer those two wires away from the others as best as I could.

# Video
A video of my work can be found [here](https://www.youtube.com/watch?v=FdYzZxUisu8).
