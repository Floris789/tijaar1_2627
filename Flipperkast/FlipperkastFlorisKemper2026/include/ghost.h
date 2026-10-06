#ifndef ghost_h
#pragma once
#define ghost_h
#include <Arduino.h>
#include <Servo.h>
#include "config.h"
#include "lives.h"

bool clydeNotDetectie = true;
bool pinkyNotDetectie = true;
bool blinkyNotDetectie = true;
bool blinkyLocked = false; //is true waneer je je ball in blinky hebt terwijl hij  bang is
bool pinkyLocked = false; //is true waneer je je   in pinky hebt terwijl hij bang is
bool clydeLocked = false; //is true waneer je je ball in clyde hebt terwijl hij bang is
bool startFrightenedGhost; //de frightenedGhost word geloopt zolang deze true is.
bool endOfMultibal = false;
unsigned long beginFrightenedGhost = 0; //de begintijd waar frightenedghost begint
extern int score;
extern int ball;
extern String display;


bool frightenedGhost(){
  if (startFrightenedGhost == false){ //zorgt dat deze code maar 1 word afgespeelt voor elke keer frightenedGHost word geactiveerd.
    beginFrightenedGhost = millis();
    startFrightenedGhost = true;
    score += scoreEnegizer;
    blinky.write(servoGhostLockAngle); //servos in middenpositie zetten
    pinky.write(servoGhostLockAngle);
    clyde.write(servoGhostLockAngle);
  }
  blinkyLocked = !digitalRead(blinkyDetectiePin);
  pinkyLocked = !digitalRead(pinkyDetectiePin);
  clydeLocked = !digitalRead(clydeDetectiePin); 
  // kijk later of de code hieronder beter kan
  if (!digitalRead(clydeDetectiePin) && (clydeNotDetectie == true)){ //balllocked
    score += scoreGhost;
    display = "ball locked!";
    clydeNotDetectie = false;
  }
  if (digitalRead(clydeDetectiePin)){ //zorgen dat het maar 1 keer balllocked doet totdat het niet meer zo is
    clydeNotDetectie = true;
  }

  if (!digitalRead(pinkyDetectiePin) && (pinkyNotDetectie == true)){ //ook voor pinky
    score += scoreGhost;
    display = "ball locked!";
    pinkyNotDetectie = false;
  }
  if (digitalRead(pinkyDetectiePin)){
    pinkyNotDetectie = true;
  }

  if (!digitalRead(blinkyDetectiePin) && (blinkyNotDetectie == true)){ //ook voor blinky
    score += scoreGhost;
    display = "ball locked!";
    blinkyNotDetectie = false;
  }
  if (digitalRead(blinkyDetectiePin)){
    blinkyNotDetectie = true;
  }
  if (blinkyLocked && pinkyLocked && clydeLocked){ //multiball code
    score += scoreMultibal;
    ball += 2;
    display = "multiball!";
    blinky.write(servoGhostReleaseAngle);
    pinky.write(servoGhostReleaseAngle);
    clyde.write(servoGhostReleaseAngle);
    clydeLocked = false;
    pinkyLocked = false;
    blinkyLocked = false;
    endOfMultibal = true; // ook de frightenedGhost eindigd wanneer je multibal hebt
  }
  if((beginFrightenedGhost + frightenedGhostTime < millis()) || endOfMultibal == true){ // stopt de frightenedghost code, nadat de tijd voorbij is of multibal
    endOfMultibal = false;
    startFrightenedGhost = false;
    if (blinkyLocked == false){
      blinky.write(servoGhostDownAngle);
    }
    if (pinkyLocked == false){
      pinky.write(servoGhostDownAngle);
    }
    if (clydeLocked == false){
      clyde.write(servoGhostDownAngle);
    }
    return false;
  }
  return true;
}

#endif