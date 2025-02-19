PROJECT :- OBJECT DISTANCE DETECTOR & DISPLAY IT ON I2C LCD
OVERVIEW
The Object Detection system pairs an ultrasonic ranging module with the CH32V003 RISC-V microcontroller to identify proximate objects. The sensor determines proximity by generating high-frequency sound pulses and measuring the interval between emission and echo reception. This duration is processed by the microcontroller, which calculates physical distance using the known speed of sound. A compact I2C-interfaced LCD screen provides real-time feedback through a simplified two-wire serial connection, visualizing either precise distance metrics or binary detection alerts. This configuration leverages the microcontroller's computational capabilities to transform temporal measurements into spatial data while maintaining low-power operation through efficient peripheral communication protocols.


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
