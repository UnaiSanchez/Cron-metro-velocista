#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
boolean i=false;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int sensor;
int t;
int segundos;
void setup()
{
	lcd.begin();
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
	lcd.backlight();
  digitalWrite(2,HIGH);
  delay(500);  
}
void loop(){
  sensor = analogRead(A0);
  lcd.setCursor(0, 1);
  lcd.print(sensor);
  lcd.print("   ");
  lcd.print(i);  
  if(sensor<750){       
    if(i==false){
        t=millis();
        lcd.setCursor(0, 1);
        lcd.clear();
        lcd.print("contando...");
        delay(1000);       
      }
      if(i==true){
        lcd.clear();
        lcd.setCursor(0, 1);
        segundos=millis()- t;
        lcd.print("Tardo:"); 
        lcd.print(" ");   
        lcd.print(segundos);
    }
    i=!i;
    sensor=750;
    delay(1000);
    lcd.clear();
  }
}

