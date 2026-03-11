# Dual Mode Temperature Controlled Device using Arduino

## Overview
This project implements a Dual Mode Temperature Control System using Arduino. 
The system monitors ambient temperature using a DHT22 sensor and automatically 
switches between heating and cooling modes depending on the temperature.

An OLED display shows the real-time temperature and system status.

## Features
- Real-time temperature monitoring
- Automatic heating and cooling control
- OLED display output
- Low-cost and energy-efficient design

## Components Used
- Arduino Uno
- DHT22 Temperature Sensor
- 0.96" OLED Display (I2C)
- Relay Module (2 Channel)
- Cooling Fan
- Heating Element
- Jumper Wires
- Breadboard

## Working Principle
1. The DHT22 sensor reads the surrounding temperature.
2. Arduino processes the temperature data.
3. If the temperature exceeds the upper limit, the cooling fan is activated.
4. If the temperature falls below the lower limit, the heater is activated.
5. The OLED display shows the current temperature and operating mode.

## Pin Connections

| Component | Arduino Pin |
|----------|-------------|
| DHT22 Data | D2 |
| Heater Relay | D7 |
| Cooler Relay | D8 |
| OLED SDA | A4 |
| OLED SCL | A5 |
| VCC | 5V |
| GND | GND |

## Applications
- Smart home temperature control
- Server room monitoring
- Greenhouse automation
- Industrial temperature regulation

## Future Improvements
- IoT based remote monitoring
- Mobile app integration
- Temperature data logging
