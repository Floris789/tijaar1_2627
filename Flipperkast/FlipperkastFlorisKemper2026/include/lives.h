#ifndef lives_h
#define lives_h
#pragma once
#include <Arduino.h>
#include <Servo.h>

int ball = 1; // de hoeveelheid speelballen in het veld
bool safe = true; //als deze true is dan  verlies je geen leven als je een bal verliest
int lives = 3; //de hoeveelheid keer dat je je ball kan verliest

//else if  ((blinky or pinky or clyde is detected and frightenedGhosts = false) or (ldr is laag)) and safe = false

void life(){
    //if (!digitalRead((clydeDetectiePin) || !digitalRead(blinkyDetectiePin) || !digitalRead(pinkyDetectiePin))){
        //dd
}

#endif