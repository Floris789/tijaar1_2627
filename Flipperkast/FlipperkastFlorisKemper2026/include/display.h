#ifndef display_h
#pragma once 
#define display_h
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "lives.h"
#include "config.h"
extern int score;
extern int lives;
extern bool ghostsLocked[3];
unsigned long beginDisplay = 0; //de tijd van het begin van een nieuwe tekst.
String display = " ";
String displayBefore =  " ";
LiquidCrystal_I2C lcd(0x27,16,2);
byte pacman[] = {
  B00000,
  B01110,
  B11100,
  B11000,
  B11100,
  B01110,
  B00000,
  B00000
};
byte ghost[] = {
  B00000,
  B01110,
  B10101,
  B11111,
  B11111,
  B10101,
  B00000,
  B00000
};
void displaySetup(){
//for (int i = 0; i<3; i++) ghostsLocked[i] = true;
lcd.init();
lcd.backlight();
lcd.home();
lcd.createChar(0, pacman);
lcd.createChar(1, ghost);
}
void displayLoop(){
  lcd.home();
  lcd.print(score);
  lcd.setCursor(11,0);
  lcd.print("     ");
  for (int i = 0; i < lives; i++){
    lcd.setCursor(15 - i,0); //print een pacmen voor elke leven die je hebt
    lcd.write(0);
  }
  lcd.setCursor(13,1);
  lcd.print("   "); //clear het scherm waar de ghost stonden.
  for (int i = 0; i < 3; i++){ //zet een ghost op het scherm voor elke ghost die gelocked is.
    if (ghostsLocked[i]){
      lcd.setCursor(13 + i, 1);
      lcd.write(1);
    }
  }
  if (displayBefore != display){
    displayBefore = display;
    beginDisplay = millis();
    lcd.setCursor(0,1);
    lcd.print(display);
  }
  if (beginDisplay + displayTime < millis()){ //cleart het scherm na een tijd van nadat het display is weergegeven
    lcd.setCursor(0,1);
    lcd.print("             ");
    display = " ";
  }
}
#endif
//https://github.com/johnrickman/LiquidCrystal_I2C
//https://maxpromer.github.io/LCD-Character-Creator/