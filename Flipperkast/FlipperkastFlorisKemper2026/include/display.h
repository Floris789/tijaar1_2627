#ifndef display_h
#pragma once 
#define display_h
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "lives.h"
#include "config.h"
extern int score;
extern int lives;
extern bool blinkyLocked;
extern bool pinkyLocked;
extern bool clydeLocked;
unsigned long beginDisplay = 0;
String display = " ";
String displayBefore =  " ";

LiquidCrystal_I2C lcd(0x27,16,2);
byte pacmen[] = {
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
blinkyLocked = true;
pinkyLocked = true;
clydeLocked = true;
lcd.init();
lcd.backlight();
//lcd.createChar(0, pacmen);
lcd.home();
//lcd.write(0);
lcd.createChar(0, pacmen);
lcd.createChar(1, ghost);
}
void displayLoop(){
  lcd.home();
  lcd.print(score);
  lcd.setCursor(11,0);
  lcd.print("     ");
  for (int i = 0; i < lives; i++){
    lcd.setCursor(15 - i,0); //print een pacmen 
    lcd.write(0);
  }
  lcd.setCursor(13,1);
  lcd.print("   ");
  if (pinkyLocked){
    lcd.setCursor(13,1);
    lcd.write(1);
  }
  if (blinkyLocked){
    lcd.setCursor(14,1);
    lcd.write(1);
  }
  if (clydeLocked){
    lcd.setCursor(15,1);
    lcd.write(1);
  }
  lcd.print(display);
  if (displayBefore != display){
    displayBefore = display;
    beginDisplay = millis();
    lcd.setCursor(0,1);
    lcd.print(display);
  }
  if (beginDisplay + displayTime >= millis()){
    lcd.print("             ");
  }
  //f(beginFrightenedGhost + frightenedGhostTime >= millis())
}
#endif

//https://github.com/johnrickman/LiquidCrystal_I2C
//https://maxpromer.github.io/LCD-Character-Creator/