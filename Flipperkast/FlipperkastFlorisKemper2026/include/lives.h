#ifndef lives_h
#define lives_h
#pragma once
#include <Arduino.h>
#include <Servo.h>
#include "config.h"
#include "ghost.h"

int ball = 1; // de hoeveelheid speelballen in het veld
bool safe = true; //als deze true is dan  verlies je geen leven als je een bal verliest
int lives = 3; //de hoeveelheid keer dat je je ball kan verliest
extern String display;
//else if  ((blinky or pinky or clyde is detected and frightenedGhosts = false) or (ldr is laag)) and safe = false
bool ir(){
    return true;
}
void life(){
    if (ball > 1){
        safe = false;
    }
    if ((((!digitalRead(clydeDetectiePin)) || (!digitalRead(blinkyDetectiePin)) || (!digitalRead(pinkyDetectiePin))) && startFrightenedGhost == false) || ir()){
        if (safe){
            safe = false;
            display = "ball saved!";
        }else{
            if (ball > 1){
                if (ball == 2){
                    safe = true;
                }
                ball --;
            }else{
                lives --;
                display = "lost ball :(";
                safe = true;
            }
        }
    }
    if (safe){
        digitalWrite(safeLedPin, HIGH);
        
        //ccode
    }else{
        digitalWrite(safeLedPin, LOW);
    }
}

#endif