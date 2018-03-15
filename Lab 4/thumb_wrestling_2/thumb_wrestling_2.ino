// include the library code:


#include <LiquidCrystal.h>



// initialize the library by associating any needed LCD interface pin


// with the arduino pin number it is connected to





LiquidCrystal lcd(7, 8, 9, 10, 11, 12);



int sensor1 = A0; // select the input pin for the potentiometer


int sensor2 = A1;


int Player1 = 0;


int Player2 = 0;



void setup() {


// set up the LCD's number of columns and rows:


lcd.begin(16, 2);


}



void loop() {


// read value from sensors:


Player1 = analogRead(sensor1);


Player2 = analogRead(sensor2);




Player1 = map(Player1, 0, 1024, 0, 10);


Player2 = map(Player2, 0, 1024, 0, 10);



// print outputs to the LCD screen:


lcd.setCursor(0,0);


lcd.print(Player1);


lcd.setCursor(0,1);


lcd.print(Player2);
}
