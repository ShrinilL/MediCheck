#include <LiquidCrystal.h>
#include <Servo.h>

#define AlarmSND 6
#define buzzer 13

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo_7;

int Hours = 0, Minutes = 0, Seconds = 0;
int alarmHours = 0, alarmMinutes = 0;
bool alarmSet = false;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(AlarmSND, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(13, OUTPUT);
  servo_7.attach(7);

  lcd.setCursor(0, 0);
  lcd.print("Set Alarm Time:");
  setAlarmTime();
}

void loop() {
  delay(1000);
  Seconds++;

  lcd.setCursor(0, 0);
  lcd.print("Pill Dispenser");

  if (alarmSet && Hours == alarmHours && Minutes == alarmMinutes) {
    activateAlarm();
  }

  if (Seconds == 60) {
    Minutes++;
    Seconds = 0;
  }
  if (Minutes == 60) {
    Minutes = 0;
    Hours++;
  }
  if (Hours == 24) {
    Hours = 0;
  }

  displayTime();
}

void setAlarmTime() {
  Serial.println("Enter Alarm Hour (0-23): ");
  while (Serial.available() == 0);
  alarmHours = Serial.parseInt();
  Serial.read();

  Serial.println("Enter Alarm Minute (0-59): ");
  while (Serial.available() == 0);
  alarmMinutes = Serial.parseInt();
  Serial.read();

  Serial.print("Alarm Set for: ");
  Serial.print(alarmHours);
  Serial.print(":");
  Serial.println(alarmMinutes);

  lcd.setCursor(0, 1);
  lcd.print("Alarm: ");
  lcd.print(alarmHours);
  lcd.print(":");
  lcd.print(alarmMinutes);

  alarmSet = true;
  delay(2000);
  lcd.clear();
}

void activateAlarm() {
  lcd.clear();
  lcd.print("Take Your Pill!");
  digitalWrite(13, HIGH);
  servo_7.write(90);

  for (int i = 0; i < 2; i++) {
    tone(buzzer, 500);
    delay(1000);
    noTone(buzzer);
    delay(1000);
  }

  digitalWrite(13, LOW);
  servo_7.write(0);
  lcd.clear();
  lcd.print("Next Dose?");
  delay(2000);
}

void displayTime() {
  lcd.setCursor(0,1);
  lcd.print(Hours < 10 ? "0" : "");
  lcd.print(Hours);
  lcd.print(":");
  lcd.print(Minutes < 10 ? "0" : "");
  lcd.print(Minutes);
  lcd.print(":");
  lcd.print(Seconds < 10 ? "0" : "");
  lcd.print(Seconds);
}
