PROJECT :- OBJECT DISTANCE DETECTOR & DISPLAY IT ON I2C LCD
OVERVIEW
The Object Detector project integrates an ultrasonic sensor with the CH32V003 RISC-V processor to detect nearby objects. An ultrasonic sensor measures the distance to an object by emitting ultrasonic waves and calculating the time it takes for the waves to return after bouncing off the object. This time is then converted into a distance measurement.The I2C LCD display allows for efficient communication between the microcontroller and the display, enabling the system to present the measured distance or object detection status.
Components Required:
Microcontroller: CH32V003F4U6

Ultrasonic Sensor: HC-SR04

I2C LCD Display: 16x2

Jumper Wires

Breadboard

HARDWARE CONNECTION
Pin Connections:
Ultrasonic Sensor (HC-SR04) Connections:
VCC: Connect to 5V power supply on VSDSquadron Mini

GND: Connect to ground on VSDSquadron Mini

TRIG PIN to PA1 on VSDSquadron Mini

ECHO PIN to PA2 on VSDSquadron Mini

I2C LCD Display Connections:
VCC: Connect to 5V power supply

GND: Connect to ground

SDA: Connect to GPIO pin to PC1

SCL: Connect to GPIO pin to PC2
