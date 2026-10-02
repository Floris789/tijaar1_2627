#include <Arduino.h>
#include <Servo.h>
#include "ghost.h"
#include "config.h"
bool start = false;
bool enegizer1Available = true; //of je de linker enegizer kan gebruiken
bool enegizer2Available = true; //of je de rechter enegizer kan gebruiken
int score = 0; //Je hoeveelheid punten
int lives = 3; //de hoeveelheid keer dat je je ball kan verliest
bool safe = true; //als deze true is dan  verlies je geen leven als je een bal verliest
int ball = 1; // de hoeveelheid speelballen in het veld

bool frightenedGhost();
void setup() {
  Serial.begin(9600);
  pinMode(leftButtonFlipperPin, INPUT_PULLUP);
  pinMode(rightButtonFlipperPin, INPUT_PULLUP);
  pinMode(blinkyDetectiePin, INPUT_PULLUP);
  pinMode(clydeDetectiePin, INPUT_PULLUP);
  pinMode(pinkyDetectiePin, INPUT_PULLUP);
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
  if (digitalRead(leftButtonFlipperPin)){
    leftFlipper.write(90);
  }else{
    leftFlipper.write(0);
  }
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
  if (gameStart()){
    start = true;
    Serial.print("game started");
    flippers();
    if (startFrightenedGhost){
      frightenedGhost();
    }
  }
}
