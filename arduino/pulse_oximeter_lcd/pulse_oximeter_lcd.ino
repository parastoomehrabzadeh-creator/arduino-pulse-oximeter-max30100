/*
  Arduino Pulse Oximeter Prototype
  --------------------------------
  Hardware:
  - Arduino UNO / ATmega328P
  - MAX30100 pulse oximeter sensor module
  - 16x2 LCD with I2C backpack

  This code reads heart rate and SpO2 from the MAX30100 sensor and displays
  the values on a 16x2 I2C LCD. It is based on a bachelor project prototype
  and has been cleaned for GitHub portfolio use.

  Important:
  This is an educational prototype and is not intended for medical diagnosis,
  treatment, or clinical decision-making.
*/

#include <Wire.h>
#include <MAX30100_PulseOximeter.h>
#include <LiquidCrystal_I2C.h>

// -------------------- Configuration --------------------
#define REPORTING_PERIOD_MS 1000
#define LCD_I2C_ADDRESS 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS);
PulseOximeter pox;

uint32_t lastReportTime = 0;

// -------------------- Callback --------------------
void onBeatDetected() {
  Serial.println(F("Beat detected"));
}

// -------------------- LCD Helpers --------------------
void showStartupMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Pulse Oximeter"));
  lcd.setCursor(0, 1);
  lcd.print(F("Initializing..."));
}

void showSensorError() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("MAX30100 ERROR"));
  lcd.setCursor(0, 1);
  lcd.print(F("Check wiring"));
}

void showPlaceFingerMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Place finger"));
  lcd.setCursor(0, 1);
  lcd.print(F("on sensor"));
}

void printMeasurement(float heartRate, uint8_t spo2) {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(F("HR: "));
  if (heartRate > 0.0) {
    lcd.print(heartRate, 0);
  } else {
    lcd.print(F("--"));
  }
  lcd.print(F(" bpm"));

  lcd.setCursor(0, 1);
  lcd.print(F("SpO2: "));
  if (spo2 > 0 && spo2 <= 100) {
    lcd.print(spo2);
  } else {
    lcd.print(F("--"));
  }
  lcd.print(F(" %"));
}

void printSerialMeasurement(float heartRate, uint8_t spo2) {
  Serial.print(F("Heart rate: "));
  Serial.print(heartRate);
  Serial.print(F(" bpm | SpO2: "));
  Serial.print(spo2);
  Serial.println(F(" %"));
}

// -------------------- Arduino Setup --------------------
void setup() {
  Serial.begin(115200);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  showStartupMessage();

  delay(2000);

  if (!pox.begin()) {
    Serial.println(F("MAX30100 initialization failed. Check wiring and power."));
    showSensorError();

    // Keep the program alive so the error stays visible on LCD.
    while (true) {
      delay(1000);
    }
  }

  Serial.println(F("MAX30100 initialized successfully."));

  // LED current can be adjusted depending on sensor placement and signal quality.
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);

  showPlaceFingerMessage();
  delay(1500);
}

// -------------------- Main Loop --------------------
void loop() {
  // This function must be called as often as possible.
  pox.update();

  if (millis() - lastReportTime >= REPORTING_PERIOD_MS) {
    float heartRate = pox.getHeartRate();
    uint8_t spo2 = pox.getSpO2();

    printMeasurement(heartRate, spo2);
    printSerialMeasurement(heartRate, spo2);

    lastReportTime = millis();
  }
}
