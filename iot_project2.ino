#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool displayStandby=false;

void setup()
{
  Wire.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.clear();
  displayStandby = true;
}

void loop()
{
  Wire.requestFrom(8,1);
  while(Wire.available()) {
    int data=Wire.read();
    Serial.print("Pill Dispensed at: ");
    Serial.println(data);
  }
  Wire.requestFrom(9,2);
  while(Wire.available()) {
    int data=Wire.read();
    Serial.print("Temperature: ");
    Serial.println(data);
    int data2=Wire.read();
    Serial.print("BPM: ");
    Serial.println(data2);
  }
  
  delay(1000);
}

  
  