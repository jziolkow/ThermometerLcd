#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int sensorPin = A0;

void setup()
{
  Serial.begin(9600);

  lcd.begin(16,2);
}

void loop()
{
  int sensorVal = analogRead(sensorPin);
  
  float voltage = (sensorVal/1024.0) * 5.0;

  float tempC = (voltage - .5) * 100;

  float tempF = ((tempC * 9) / 5) + 32;

  Serial.print("Sensor Value : ");
  Serial.print(sensorVal);
  Serial.print(" ");

  Serial.print(" Voltage: ");
  Serial.print(voltage);
  Serial.print(" ");

  Serial.print("Temp (C): ");
  Serial.print(tempC);
  Serial.print(" ");

  Serial.print("Temp (F): ");
  Serial.print(tempF);
  Serial.print(" ");

  Serial.println("");

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp (F): ");
  lcd.print(tempF);
  
  lcd.setCursor(0,1);
  lcd.print("Temp (C): ");
  lcd.print(tempC);
  
  delay(1000); 
}
