#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int valTemp;
int valPulse;

int tempPin = A1;
int pulsePin = A2;
int buttonPin = 7;
int buttonState = 0;
int counter = 0;
bool displayStandby = false;
bool scanning = false;
String seconds;

void setup() {
  Wire.begin(9);
  pinMode(buttonPin, INPUT);
  
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
  displayStandby = true;
  Wire.onRequest(sendData);
}

void loop() {
  ScanData();
}

void ScanData(){
  lcd.clear();
  lcd.print("TEMP: ");
  valTemp = analogRead(tempPin);
  float mv = ( valTemp/1024.0)*5000; 
  float cel = mv/10;
  valTemp = cel;
  lcd.print(valTemp);
  lcd.print(" CELSIUS");
  lcd.print("   ");
  lcd.setCursor(0, 2);
  lcd.print("BPM: ");
  valPulse = analogRead(pulsePin);
  valPulse = valPulse/6;
  lcd.print(valPulse);
  lcd.print(" pulse");
  lcd.print("  ");
  delay(1000);
}

void sendData() {
  Serial.println(valPulse);
  Wire.write(valTemp);
  Wire.write(valPulse);
}
 
 