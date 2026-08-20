# Wiring Guide

## MAX30100 Sensor

| MAX30100 | Arduino UNO |
|----------|-------------|
| VIN      | 3.3V        |
| GND      | GND         |
| SCL      | A5          |
| SDA      | A4          |
| INT      | D2          |

## I2C LCD

| LCD I2C | Arduino UNO |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| SCL     | A5          |
| SDA     | A4          |

## Notes

- The Arduino UNO uses A4 for SDA and A5 for SCL.
- If the LCD does not display correctly, check the I2C address. Common addresses are `0x27` and `0x3F`.
- Some MAX30100 modules may require proper pull-up resistors or voltage-level compatibility checks.
