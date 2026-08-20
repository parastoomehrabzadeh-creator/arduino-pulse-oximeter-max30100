# Arduino Pulse Oximeter with MAX30100 and I2C LCD

This project is an educational pulse oximeter prototype developed with an Arduino UNO, a MAX30100 pulse oximeter sensor module, and a 16x2 I2C LCD display.

The system reads heart rate and blood oxygen saturation (SpO2) values from the MAX30100 sensor and displays them on an LCD screen. The project was originally developed as a bachelor's project in Computer Hardware Engineering and has been cleaned and reorganized for GitHub portfolio presentation.

> Important: This project is an educational prototype. It is not a certified medical device and must not be used for medical diagnosis, treatment, or clinical decision-making.

## Project Overview

Pulse oximetry is a non-invasive method for estimating arterial blood oxygen saturation. A pulse oximeter typically uses red and infrared light to estimate SpO2 and detect pulse-related changes in blood volume.

This project demonstrates how a microcontroller-based system can acquire pulse oximetry data from a sensor module and display the results in real time.

## Key Features

- Arduino-based pulse oximeter prototype
- Heart rate measurement
- SpO2 measurement
- MAX30100 sensor integration
- 16x2 LCD output using I2C
- Serial Monitor output for debugging
- Clean and readable Arduino code
- GitHub-ready project structure

## Hardware Components

- Arduino UNO / ATmega328P
- MAX30100 pulse oximeter sensor module
- 16x2 character LCD
- I2C LCD adapter module
- Jumper wires
- Breadboard or prototype wiring setup

## Wiring

### MAX30100 to Arduino UNO

| MAX30100 Pin | Arduino UNO Pin |
|-------------|-----------------|
| VIN         | 3.3V            |
| GND         | GND             |
| SCL         | A5              |
| SDA         | A4              |
| INT         | D2              |

### I2C LCD to Arduino UNO

| I2C LCD Pin | Arduino UNO Pin |
|------------|-----------------|
| VCC        | 5V              |
| GND        | GND             |
| SCL        | A5              |
| SDA        | A4              |

Note: Many I2C LCD modules use address `0x27`, but some use `0x3F`. If the LCD does not show text, scan the I2C address and update `LCD_I2C_ADDRESS` in the code.

## Software Requirements

Install the following Arduino libraries before uploading the code:

- `MAX30100lib` or a compatible `MAX30100_PulseOximeter` library
- `LiquidCrystal_I2C`
- `Wire` library, included with Arduino IDE

## Project Structure

    arduino-pulse-oximeter-max30100/
    ├── arduino/
    │   └── pulse_oximeter_lcd/
    │       └── pulse_oximeter_lcd.ino
    ├── docs/
    │   └── project-summary.md
    ├── hardware/
    │   └── wiring.md
    ├── README.md
    ├── .gitignore
    └── LICENSE

## How to Run

1. Install the Arduino IDE.
2. Install the required libraries.
3. Connect the MAX30100 sensor and I2C LCD according to the wiring table.
4. Open `arduino/pulse_oximeter_lcd/pulse_oximeter_lcd.ino` in Arduino IDE.
5. Select the correct board, for example `Arduino UNO`.
6. Select the correct COM port.
7. Upload the code.
8. Open the Serial Monitor at `115200 baud`.
9. Place a finger gently on the MAX30100 sensor.

## Notes on Code Cleanup

The original code extracted from the thesis appendix contained formatting issues caused by PDF conversion. The Arduino sketch in this repository has been cleaned and improved by:

- Fixing invalid syntax from PDF extraction
- Adding proper initialization for the LCD and MAX30100 sensor
- Adding error handling when the sensor is not detected
- Adding Serial Monitor output
- Improving code readability with helper functions
- Adding comments and project structure for GitHub presentation

## Limitations

- The prototype is not medically validated.
- Sensor readings may be affected by finger placement, motion, ambient light, poor contact, low perfusion, or module quality.
- MAX30100 modules can be sensitive to voltage levels and pull-up resistors.
- The project is intended for educational and portfolio purposes only.

## Future Improvements

- Add a buzzer alarm for low SpO2 values
- Add moving average filtering for more stable readings
- Add OLED display support
- Add battery-powered enclosure design
- Add data logging to SD card
- Add calibration and signal-quality indicators
- Design a custom PCB for a more compact prototype

## Repository Description

Educational Arduino pulse oximeter prototype using MAX30100 sensor and 16x2 I2C LCD for heart rate and SpO2 monitoring.

## Topics

arduino, pulse-oximeter, max30100, embedded-systems, biomedical-engineering, medical-device-prototype, i2c, lcd-display, heart-rate-monitor, spo2

## Author

Bachelor's project in Computer Hardware Engineering, redesigned and documented for GitHub portfolio presentation.
