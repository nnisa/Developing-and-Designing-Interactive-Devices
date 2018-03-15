// include the library code:
#include <LiquidCrystal.h>
#include "pitches.h"

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int sensor_pin = A1;   

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};



void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Touch to set");
  lcd.setCursor(0,1);
  lcd.print("time!");
  pinMode(sensor_pin, INPUT);
}
 
void loop() {
  int sensor_value = analogRead(sensor_pin);
  if(sensor_value > 0)
  {
    for(int i = sensor_value; i>=0; i = i-1)
    {
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have:");
      lcd.setCursor(0,1);
      lcd.print(String(i) + " seconds left");
      if(i == 0)
      {
        music();
        lcd.setCursor(0,0);
        lcd.print("TIME'S UP");
        delay(2000);
        sensor_value = 0;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Touch to set");
        lcd.setCursor(0,1);
        lcd.print("time!");
      }
    }
  }
  else
  {
    delay(1000);
  }
}

void music() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}


