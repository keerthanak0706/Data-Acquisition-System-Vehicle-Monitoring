# Data Acquisition System for Vehicle Monitoring

## Project Overview
This project presents an Arduino-based Data Acquisition System (DAS) for vehicle monitoring. It uses sensors and modules to collect environmental and real-time clock information and display the readings on an LCD.

## Hardware Components
- Arduino Uno
- DHT22 Temperature and Humidity Sensor
- DS3231 Real-Time Clock (RTC) Module
- 16×2 I2C LCD Display
- Connecting wires and supporting components

## Software and Libraries
- Arduino IDE
- DHT Sensor Library
- uRTCLib
- LiquidCrystal_I2C
- TimerOne

## Project Files
- `DAS_Vehicle_Monitoring.ino` – Arduino source code
- `Data Acquisition System For Vehicle Monitoring.pdf` – Project report
- `final ppt.pptx` – Project presentation

## Working Principle
The Arduino Uno reads temperature and humidity data from the DHT22 sensor. The DS3231 RTC module provides date and time information. The collected information is processed by the Arduino and displayed on the 16×2 I2C LCD.

## Project Objective
To develop a simple data acquisition system that collects, processes, and displays vehicle-monitoring-related data using an embedded controller.

## Academic Year
2025–2026
## Required Arduino Libraries

The following libraries are included in the project source code:

| Library | Purpose |
|---|---|
| DHT Sensor Library | Reads temperature and humidity from the DHT22 sensor |
| uRTCLib | Communicates with the DS3231 RTC module |
| LiquidCrystal_I2C | Controls the I2C LCD display |
| TimerOne | Provides timer interrupt functionality |
| Wire | I2C communication |
| uEEPROMLib | EEPROM communication support |

### Installation Instructions

1. Open Arduino IDE.
2. Navigate to **Sketch → Include Library → Manage Libraries**.
3. Search for the required external libraries.
4. Install the appropriate libraries and any dependencies requested by the IDE.
5. Open `DAS_Vehicle_Monitoring.ino`.
6. Select the Arduino Uno board and the correct COM port.
7. Click Verify to compile the program.
