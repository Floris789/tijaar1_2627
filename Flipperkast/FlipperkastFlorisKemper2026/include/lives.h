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
    if (ball > 1){ //als je meerdere ballen in het spel heb (van multibal) dan mag je geen safe.
        safe = false;
    }
    if ((((!digitalRead(clydeDetectiePin)) || (!digitalRead(blinkyDetectiePin)) || (!digitalRead(pinkyDetectiePin))) && startFrightenedGhost == false) || ir()){
        if (safe){ //als je in de poortjes gaat (zonder frightenedghost) of tussen de flippers valt dan raak je je safe kwijt
            safe = false;
            display = "ball saved!";
        }else if (ball > 1){ //of anders je extra bal
            if (ball == 2){ //maar je krijgt wel je safe als het je laatste extra bal was.
                safe = true;
            }
            ball --;
        }else{ //als je allebei niet hebt dan raak je toch je bal kwijt
            lives --;
            display = "lost ball :(";
            safe = true;
        }
    }
    if (safe){ //safe led aanzetten waneer safe waar is
        digitalWrite(safeLedPin, HIGH);

        //ccode
    }else{
        digitalWrite(safeLedPin, LOW);
    }
}

#endif