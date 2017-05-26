## CU Digital Media - 104MC
### Twitter Controled Car - Jack Boyle, Callum Day & Jimmy Sodiya

A project to create a remote control that car that responds to tweets to the #104MCTest hashtag to move around.

A python script listens to the twitter stream and when it sees a tweet containing #104MCTest, and if it contains 'forward', 'backward', 'left', or 'right', it will send a message via serial usb to the Arduino. The Arduino will then turn the motors on to perform the command, whether that is moving forward, backward, turning left, or turning right.

#### Arduino INO file sources:
1. Arduino SRL (2015) *Arduino Projects Book Third Issue*. Torino: Arduino SRL
2. codebender_cc (2015) *How to Use the L293D Motor Driver - Arduino Tutorial: 4 Steps (with pictures)* [online] available from http://www.instructables.com/id/How-to-use-the-L293D-Motor-Driver-Arduino-Tutorial/(http://www.instructables.com/id/How-to-use-the-L293D-Motor-Driver-Arduino-Tutorial/) [26 May 2017]
3. robcannincCU (2017) *hacklab/arduino_python_serial_comms.ino at master · robcanningCU/hacklab* [online] available from https://github.com/robcanningCU/hacklab/blob/master/python_arduino_code/arduino_python_serial_comms/arduino_python_serial_comms.ino(https://github.com/robcanningCU/hacklab/blob/master/python_arduino_code/arduino_python_serial_comms/arduino_python_serial_comms.ino) [26 May 2017]

#### Python script sources: