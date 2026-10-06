#ifndef ghost_h
#pragma once
#define ghost_h
#include <Arduino.h>
#include <Servo.h>
#include "config.h"
#include "lives.h"

bool ghostsNotDetectie[3] = {true, true, true};
bool ghostsLocked[3] = {false, false, false}; // pinky is 0, blinky is 1 en ClydeLocked is 2. is true waneer je je ball in de spook hebt terwijl hij bang is.
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
    for (int i = 0; i<3; i++){
      ghosts[i].write(servoGhostLockAngle); //servos in middenpositie zetten
    }

  }
  for (int i = 0; i < 3; i++){
    ghostsLocked[i] = !digitalRead(ghostsDetectiePinnen[i]);
  }
  for (int i = 0; i < 3; i++){
    if (ghostsLocked[i] && ghostsNotDetectie[i]){
      score += scoreGhost;
      display = "ball locked!";
      ghostsNotDetectie[i] = false;
    }
    if (!ghostsLocked[i]){
      ghostsNotDetectie[i] = true;
    }
  }
  if (ghostsLocked[0] && ghostsLocked[1] && ghostsLocked[2]){ //multiball code
    score += scoreMultibal;
    ball += 2;
    display = "multiball!";
    for (int i = 0; i < 3; i++){
      ghosts[i].write(servoGhostReleaseAngle);
      ghostsLocked[i] = false;
    }
    endOfMultibal = true; // ook de frightenedGhost eindigd wanneer je multibal hebt
  }
  if((beginFrightenedGhost + frightenedGhostTime < millis()) || endOfMultibal == true){ // stopt de frightenedghost code, nadat de tijd voorbij is of multibal
    endOfMultibal = false;
    startFrightenedGhost = false;
    for(int i = 0; i < 3; i++){
      if (!ghostsLocked[i]){
        ghosts[i].write(servoGhostDownAngle);
      }
    }
    return false;
  }
  return true;
}

#endif