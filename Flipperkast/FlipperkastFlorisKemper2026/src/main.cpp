#include <Arduino.h>
#include <Servo.h>
#include "display.h"
#include "ghost.h"
#include "config.h"
bool start = false; //of de game is begonnen.
bool enegizer1Available = true; //of je de linker enegizer kan gebruiken
bool enegizer2Available = true; //of je de rechter enegizer kan gebruiken
int score = 0; //Je hoeveelheid punten
void setup() {
  pinModes();
  displaySetup();
  Serial.begin(9600);
  leftFlipper.attach(leftFlipperPin);
  rightFlipper.attach(rightFlipperPin);
  ghosts[0].attach(pinkyServoPin);
  ghosts[1].attach(blinkyServoPin);
  ghosts[2].attach(clydeServoPin);
}
bool gameStart(){
return ((start == false) && !digitalRead(leftButtonFlipperPin) && !digitalRead(rightButtonFlipperPin));
}
void flippers(){
  if (!(digitalRead(leftButtonFlipperPin))) leftFlipper.write(90);
  else leftFlipper.write(0);
  if (!(digitalRead(rightButtonFlipperPin))) rightFlipper.write(90);
  else rightFlipper.write(0);
}
void enegizers(){
  if (enegizer1Available && !(digitalRead(leftIrPin))){
    enegizer1Available = false;
    frightenedGhost(); //zorgt ervoor dat je in de spoken moet nadat je over een enegizer bent gegaan
  } 
  if (enegizer2Available && !(digitalRead(rightIrPin))){
    enegizer2Available = false;
    frightenedGhost();
  }
}
void loop() {
  //servo test
  //blinky.write(0);
  //delay(1000);
  //blinky.write(90);
  //delay(1000);
  //blinky.write(180);
  //delay(1000);

  //display &ir test:
  // displayLoop();
  // if (!(digitalRead(rightIrPin))){
  //   display = "a";
  //   score ++;
  // }else display = "b";

  //cool display:
  // lives -= 1;
  // if (lives == -1) lives = 5;
  if (!start && gameStart()){
    start = true;
     display = "start";
    Serial.print("game started\n");
  }
  if (gameStart() || start == true){
    flippers();
    enegizers();
    life();
    displayLoop();
    if (startFrightenedGhost) frightenedGhost();
  }
}