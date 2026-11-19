/*
 * DATA ACQUISITION SYSTEM (DAS) FOR VEHICLE MONITORING
 * Academic Year: 2025-2026
 *
 * Hardware used in the supplied project:
 * - Arduino Uno
 * - DHT22 temperature and humidity sensor (data pin 12)
 * - DS3231 RTC module (I2C address 0x68)
 * - 16x2 I2C LCD (I2C address 0x27)
 *
 * Required Arduino libraries:
 * - DHT sensor library
 * - uRTCLib
 * - LiquidCrystal_I2C
 * - TimerOne
 */

#include <DHT.h>
#include "Arduino.h"
#include "uRTCLib.h"
#include "Wire.h"
#include "uEEPROMLib.h"       // Included in the supplied sketch; not currently used.
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>

// Sensor configuration
#define DHTPIN 12
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
uRTCLib rtc(0x68);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Retained from the supplied sketch.
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
int chk;
float hum = 0.0;
float temp = 0.0;

// Incremented once per second by the TimerOne interrupt.
volatile int counter = 0;

void count()
{
  counter++;
}

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" WELCOME 1.2");

  Wire.begin();
  URTCLIB_WIRE.begin();
  dht.begin();

  delay(3000);

  // Set a 1-second interval (1,000,000 microseconds).
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(count);
}

void loop()
{
  lcd.clear();

  if (counter < 5)
  {
    // Read the current date and time from the RTC.
    rtc.refresh();

    Serial.print("Current Date & Time: ");
    Serial.print(rtc.day());
    Serial.print('/');
    Serial.print(rtc.month());
    Serial.print('/');
    Serial.print(rtc.year());
    Serial.print(' ');
    Serial.print(rtc.hour());
    Serial.print(':');
    Serial.print(rtc.minute());
    Serial.print(':');
    Serial.println(rtc.second());

    // Read both DHT22 measurements before displaying them.
    temp = dht.readTemperature();       // Celsius
    hum = dht.readHumidity();

    if (isnan(temp) || isnan(hum))
    {
      Serial.println("Failed to read from DHT22 sensor.");
      lcd.setCursor(0, 0);
      lcd.print("DHT22 read error");
      lcd.setCursor(0, 1);
      lcd.print("Check sensor");
    }
    else
    {
      float tempF = dht.readTemperature(true);  // Fahrenheit

      lcd.setCursor(0, 0);
      lcd.print("T:");
      lcd.print(temp, 1);
      lcd.print("C ");
      lcd.print(tempF, 1);
      lcd.print("F");

      lcd.setCursor(0, 1);
      lcd.print("H: ");
      lcd.print(hum, 1);
      lcd.print("%");

      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.print(" C / ");
      Serial.print(tempF);
      Serial.println(" F");
      Serial.print("Humidity: ");
      Serial.print(hum);
      Serial.println(" %");
    }
  }
  else if (counter > 9)
  {
    counter = 0;
  }

  delay(1000);
}
