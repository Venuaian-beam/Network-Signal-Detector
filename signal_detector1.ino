#include <Adafruit_LiquidCrystal.h>

int potPin = A0;  // Potentiometer connected to A0
Adafruit_LiquidCrystal lcd_1(0);



void setup() {
  lcd_1.begin(16, 2);
  lcd_1.print("Readings:");  // Print label
  pinMode (11,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (13,OUTPUT);
  
}

void loop() {
  int potValue = analogRead(potPin);  // Read potentiometer (0-1023)
  String signal_strength;
  
  
  if (potValue >=0 && potValue <=450)
  {
    signal_strength="Weak";
   	digitalWrite(13,HIGH);
 	delay(1000);
    digitalWrite(13,LOW);
   
    
  }
  
  else if(potValue >=451 && potValue <=750)
  {
    signal_strength="Better";
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
  	delay(1000);
  
  }
          else
          {
            signal_strength="Strong";
            digitalWrite(13,HIGH);
    		digitalWrite(12,HIGH);
            digitalWrite(11,HIGH);
            
  			}
   
     
  lcd_1.setCursor(0, 1);  // Move cursor to second row
  //lcd_1.print("        ");  // Clear previous value
  lcd_1.setCursor(0, 1);  // Reset cursor position
  lcd_1.print(signal_strength);  // Print potentiometer value
  

  //delay(500);  // Update every 0.5 seconds
  
 
}


void setColor(int red,int blue, int green)
{
  analogWrite(11,red);
  analogWrite(12,green);
  analogWrite(13,blue);
  
}
