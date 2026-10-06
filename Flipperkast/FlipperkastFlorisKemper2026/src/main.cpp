#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"
#include "ghost.h"
#include "config.h"
bool start = false; //of de game is begonnen.
bool enegizer1Available = true; //of je de linker enegizer kan gebruiken
bool enegizer2Available = true; //of je de rechter enegizer kan gebruiken
int score = 0; //Je hoeveelheid punten

bool frightenedGhost();
void setup() {
  displaySetup();
  Serial.begin(9600);
  leftFlipper.attach(leftFlipperPin);
  rightFlipper.attach(rightFlipperPin);
  blinky.attach(blinkyServoPin);
  clyde.attach(clydeServoPin);
  pinky.attach(pinkyServoPin);
}
bool gameStart(){
  return ((start == false) && !digitalRead(leftButtonFlipperPin) && !digitalRead(rightButtonFlipperPin));
}
void flippers(){
  if (digitalRead(leftButtonFlipperPin))leftFlipper.write(90);
  else leftFlipper.write(0);
}
void enegizers(){
  if (enegizer1Available && digitalRead(leftIrPin)){
    enegizer1Available = false;
    frightenedGhost(); //zorgt ervoor dat je in de spoken moet nadat je over een enegizer bent gegaan
  }
  if (enegizer2Available && digitalRead(rightIrPin)){
    enegizer2Available = false;
    frightenedGhost();
  }
}
void lock(){
}
void ballSafe(){
}
void lose(){
}
void loop() {
  delay(1000);
  lives -= 1;
  if (lives == -1) lives = 5;
  if (gameStart()){
    start = true;
    Serial.print("game started");
    flippers();
    life();
    displayLoop();
    if (startFrightenedGhost) frightenedGhost();
  }
}