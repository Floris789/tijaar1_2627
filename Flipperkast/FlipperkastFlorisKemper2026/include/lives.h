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
bool dying = false;
bool startSafe = false;
unsigned long beginSafeTime = 0;
extern String display;
bool ldr(){
    if (analogRead(ldrPin) < 1000){
        return true;
    }else return false;
    
    // code voor de ldr, moet nog doen
}
void life(){

    if (ball > 1) safe = false; //als je meerdere ballen in het spel heb (van multibal) dan mag je geen safe.
    //later nog beter maken:
    if (((((!digitalRead(ghostsDetectiePinnen[0])) || (!digitalRead(ghostsDetectiePinnen[1])) || (!digitalRead(ghostsDetectiePinnen[2]))) && startFrightenedGhost == false) || ldr()) && dying == false){
        dying = true;
        if (safe){ //als je in de poortjes gaat (zonder frightenedghost) of tussen de flippers valt dan raak je je safe kwijt
            safe = false;
            display = "ball saved!";
        }else if (ball > 1){ //of anders je extra bal
            if (ball == 2) safe = true; //maar je krijgt wel je safe als het je laatste extra bal was.
            ball --;
        }else{ //als je allebei niet hebt dan raak je toch je bal kwijt
            lives --;
            display = "lost ball :(";
            safe = true;
        }
    } else dying = false;
    if (safe){ //safe led aanzetten waneer safe waar is
        if (!startSafe){
            startSafe = true;
            beginSafeTime = millis();
            digitalWrite(safeLedPin, HIGH);
        }
        if (beginSafeTime + safeTime <= millis()){
            safe = false;
            startSafe = false;
        }
        //ccode
    }else digitalWrite(safeLedPin, LOW);
    if (lives <= 0){
        display = "game over";
        startSafe = false;
    }
}
#endif