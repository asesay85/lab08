#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Voltage Measurement Setup

// vcc to vcc pin of arduino board, gnd to gnd, SCL to A5, SDA to A6
int voltageA = A0;
int voltageB = A1;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(voltageA, INPUT);
  pinMode(voltageB, INPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  int VoltageMsmtA = analogRead(voltageA);
  float VcalcA = (5.0/1023) *VoltageMsmtA;

  int VoltageMsmtB = analogRead(voltageB);
  float VcalcB = (5.0/1023) *VoltageMsmtB;

  lcd.setCursor(0,0);
  lcd.print("BATTERY ");
  lcd.print(VcalcA - VcalcB);
}