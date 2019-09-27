/* LCD pins- Arduino pins
       vss-gnd
       vdd-5v
       vo-6
       rs-12
       rw-gnd
       e-11
       d4-5
       d5-4
       d6-3
       d7-2
       A-5v
       K-gnd

       Red,Green,Blue = 8,9,10
       Cathode = GND
 */
#include <LiquidCrystal.h> 

int Contrast=110;
int redPin = 8;
int greenPin = 9;
int bluePin = 10;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

void setup(){
    analogWrite(6,Contrast);
    lcd.begin(16,2);
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void loop(){
    lcd.clear(); 
    setColor(255, 0, 0); // Red Color
    lcd.setCursor(0,0);
    lcd.print("Light Colour : ");
    lcd.setCursor(0,1);
    lcd.print("RED : (ON)");
    delay(3000);
    lcd.clear();

    setColor(0, 255, 0); // Green Color
    lcd.setCursor(0,0);
    lcd.print("Light Colour : ");
    lcd.setCursor(0,1);
    lcd.print("GREEN : (ON)");
    delay(3000);
    lcd.clear();

    setColor(0, 0, 255); // Blue Color
    lcd.setCursor(0,0);
    lcd.print("Light Colour : ");
    lcd.setCursor(0,1);
    lcd.print("BLUE : (ON)");
    delay(3000);
    lcd.clear();
    blink();  
}

void blink(){
  lcd.setCursor(0,0);
  lcd.print("...Light BLINK...");
  
  for(int i=0; i<30; i++){
      setColor(255, 0, 0); // Red Color
      delay(100);
      setColor(0, 255, 0); // Green Color
      delay(100);
      setColor(0, 0, 255); // Blue Color
      delay(100);
      setColor(255, 255, 255); // White Color     
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("...THANK YOU...");
  delay(4000);
}

void setColor(int redValue, int greenValue, int blueValue){
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
