#ifndef ghost_h
#pragma once
#define ghost_h
#include <Arduino.h>
#include <Servo.h>
#include "config.h"

bool clydeNotDetectie = true;
bool pinkyNotDetectie = true;
bool blinkyNotDetectie = true;
bool blinkyLocked = false; //is true waneer je je ball in blinky hebt terwijl hij  bang is
bool pinkyLocked = false; //is true waneer je je ball in pinky hebt terwijl hij bang is
bool clydeLocked = false; //is true waneer je je ball in clyde hebt terwijl hij bang is
bool startFrightenedGhost;
unsigned long beginFrightenedGhost = 0;
extern int score;
extern int ball;

bool frightenedGhost(){
  if (startFrightenedGhost == false){
    beginFrightenedGhost = millis();
    startFrightenedGhost = true;
  }
  score += scoreEnegizer;
  blinky.write(servoGhostLockAngle);
  pinky.write(servoGhostLockAngle);
  clyde.write(servoGhostLockAngle);
  blinkyLocked = !digitalRead(blinkyDetectiePin);
  pinkyLocked = !digitalRead(pinkyDetectiePin);
  clydeLocked = !digitalRead(clydeDetectiePin); 
  // kijk later of de code hieronder beter kan
  if (!digitalRead(clydeDetectiePin) && (clydeNotDetectie == true)){ //balllocked
    score += scoreGhost;
    //zet de display naar ball locked
    clydeNotDetectie = false;
  }
  if (digitalRead(clydeDetectiePin)){
    clydeNotDetectie = true;
  }

  if (!digitalRead(pinkyDetectiePin) && (pinkyNotDetectie == true)){
    score += scoreGhost;
    //zet de display naar ball locked
    pinkyNotDetectie = false;
  }
  if (digitalRead(pinkyDetectiePin)){
    pinkyNotDetectie = true;
  }

  if (!digitalRead(blinkyDetectiePin) && (blinkyNotDetectie == true)){ 
    score += scoreGhost;
    //zet de display naar ball locked
    blinkyNotDetectie = false;
  }
  if (digitalRead(blinkyDetectiePin)){
    blinkyNotDetectie = true;
  }
  if (blinkyLocked && pinkyLocked && clydeLocked){ //multiball
    score += scoreMultibal;
    ball += 2;
    //zet de display naar multibal
    blinky.write(servoGhostReleaseAngle);
    pinky.write(servoGhostReleaseAngle);
    clyde.write(servoGhostReleaseAngle);
    clydeLocked = false;
    pinkyLocked = false;
    blinkyLocked = false;
    delay(200);
  }
  if(beginFrightenedGhost + frightenedGhostTime >= millis()){
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