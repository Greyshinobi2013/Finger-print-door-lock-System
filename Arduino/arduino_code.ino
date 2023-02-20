#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Servo.h>
SoftwareSerial SIM900(2,3);
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo servoMotor;
int pos = 0;
int i = 0;
int x;

int count=5;
void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  servoMotor.attach(5);
  SIM900.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
   lcd.setCursor(0, 0);
  lcd.print("Enter passcode");
  Serial.println("Enter passcode: ");

}

void loop() {
  while(count>0){
dex:
  if (Serial.available()) {
  String input = Serial.readString();
   Serial.println(input); 
   if(input=="123") {
      digitalWrite(6, LOW);
      lcd.clear();
      delay(100);
      lcd.setCursor(3, 0);
      lcd.print("unlocked");
      lcd.setCursor(1, 1);
      lcd.print("---welcome---");

      delay(100);
      digitalWrite(7, HIGH);
      for (pos = 0; pos <= 180; pos += 1) {
       // delay(5);
        servoMotor.write(pos);
      delay(10);
      }
     
      lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("locked for ");
     lcd.setCursor(3, 1);
    lcd.print("safety");
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    }



else {

   String input = " ";
   lcd.clear();
   delay(100);
      lcd.setCursor(0, 0);
      lcd.print("please try again");
      lcd.setCursor(0, 1);
      lcd.print(count-1);
      lcd.print(" attemt left");
      digitalWrite(6, HIGH);  
      if(count==1) break; 
  Serial.println("Enter passcode again: ");
  count--; 
      goto dex;
      }
}}
     lcd.clear();
     delay(100);
      lcd.setCursor(0, 0);
      lcd.print("NO MORE ATTEMPT");
      
      Serial.print("NO MORE ATTEMPT");
      digitalWrite(6, HIGH);
      
    SIM900.println("AT + CMGS = \"+251xxxxxxxxx\"");// recipient's mobile number with country code
      SIM900.print("SOMEONE IS TRYING TO BREAK INTO YOUR HOUSE");
      delay(100000);
}
