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
bool gameOver = false;
unsigned long beginSafeTime = 0;
unsigned long graceUntil = 0; //tot dit tijdstip telt een bal in een poortje niet als verloren
extern String display;
bool ldr(){
    if (analogRead(ldrPin) < 1000){
        return true;
    }else return false;
    
    // code voor de ldr, moet nog doen
}
void life(){
    if (gameOver) return;

    if (ball > 1) safe = false; //als je meerdere ballen in het spel heb (van multibal) dan mag je geen safe.

    //een bal in een poortje telt alleen als verloren als dat poortje niet vastgehouden wordt
    bool gate = false;
    for (int i = 0; i < 3; i++){
        if (!digitalRead(ghostsDetectiePinnen[i]) && !ghostsLocked[i]) gate = true;
    }
    bool graceOver = millis() >= graceUntil;
    bool lost = (gate && startFrightenedGhost == false && graceOver) || ldr();

    if (lost && dying == false){
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
    } else if (!lost) dying = false;

    if (safe){
        if (!startSafe){
            startSafe = true;
            beginSafeTime = millis();
            digitalWrite(safeLedPin, HIGH);
        }
        if (millis() - beginSafeTime >= safeTime) safe = false;
    } else {
        startSafe = false;
        digitalWrite(safeLedPin, LOW);
    }
    if (lives <= 0){
        gameOver = true;
        display = "game over";
        startSafe = false;
        digitalWrite(safeLedPin, LOW);
    }
}
#endif