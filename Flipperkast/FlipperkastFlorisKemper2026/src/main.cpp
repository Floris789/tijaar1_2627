#include <Arduino.h>
#include <Servo.h>
#include "display.h"
#include "ghost.h"
#include "config.h"
bool start = false; //of de game is begonnen.
bool enegizer1Available = true; //of je de linker enegizer kan gebruiken
bool enegizer2Available = true; //of je de rechter enegizer kan gebruiken
int score = 0; //Je hoeveelheid punten
Adafruit_PCF8574 pcf;
void setup() {
  Serial.begin(9600);

  if (!pcf.begin(0x20)) {
    Serial.println("PCF8574 niet gevonden!");
    while (true) {
      delay(100);
    }
  }
  pinModes();
  displaySetup();

  leftFlipper.attach(leftFlipperPin);   leftFlipper.write(5);
  rightFlipper.attach(rightFlipperPin); rightFlipper.write(120);
  ghosts[0].attach(pinkyServoPin);  ghosts[0].write(servoGhostDownAngle);
  ghosts[1].attach(blinkyServoPin); ghosts[1].write(servoGhostDownAngle);
  ghosts[2].attach(clydeServoPin);  ghosts[2].write(servoGhostDownAngle);
  //Wire.setClock(400000); als nodig
  Serial.println("setup done");
}
bool gameStart(){
  Serial.println(pcf.digitalRead(leftButtonFlipperPin));
  Serial.println(pcf.digitalRead(rightButtonFlipperPin));
  delay(100);
return ((start == false) && !pcf.digitalRead(leftButtonFlipperPin) && !pcf.digitalRead(rightButtonFlipperPin));
}
void flippers(){ // beweging van de flippers
  if (!(pcf.digitalRead(leftButtonFlipperPin))) leftFlipper.write(110);
  else leftFlipper.write(5);
  if (!(pcf.digitalRead(rightButtonFlipperPin))) rightFlipper.write(15);
  else rightFlipper.write(120);
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
  if (!start && gameStart()){
    start = true;
     display = "start";
    Serial.print("game started\n");
  } else display = "press buttons";
  if (start){
    if (!gameOver){
      flippers();
      enegizers();
      life();
      if (startFrightenedGhost) frightenedGhost();
    } else {
      leftFlipper.write(0);
      rightFlipper.write(0);
    }
  }
  displayLoop();
  
  //Ir test
  // Serial.print("left");
  // Serial.print(digitalRead(leftIrPin));
  // Serial.print("right");
  // Serial.println(digitalRead(rightIrPin));
  
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

  //pcf test:
  // Serial.print("Links: ");
  // Serial.print(!pcf.digitalRead(leftButtonFlipperPin));
  // Serial.print(" | Rechts: ");
  // Serial.println(!pcf.digitalRead(rightButtonFlipperPin));

  // delay(100);

}