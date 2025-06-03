#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address may vary: 0x27, 0x3F, or 32 for Tinkercad.
LiquidCrystal_I2C lcd(32, 16, 2);  
int potPin = A0;  

int value = 0;
int lastValue = 0;

void setup() {
  lcd.init();         
  lcd.backlight();    
  lcd.clear();        

  lcd.setCursor(0, 0);
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Embedded Systems");

  delay(3000); 

  lcd.clear();  

  pinMode(potPin, INPUT);  
  Serial.begin(9600);      
}

void loop() {

  value = analogRead(potPin);

  Serial.print("Potentiometer value: ");
  Serial.println(value);

  lcd.setCursor(0, 0);
  lcd.print("Pot value:");

  lcd.setCursor(10, 0);
  lcd.print("     "); 
  lcd.setCursor(10, 0);
  lcd.print(value);
  lcd.setCursor(0, 1);
  if (value > lastValue) {
    lcd.print("Increasing     ");
  } else if (value < lastValue) {
    lcd.print("Decreasing     ");
  } else {
    lcd.print("Stable         ");
  }

 
  lastValue = value;

  delay(200);  
}
