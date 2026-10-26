

#ifndef config_h
#define config_h
#pragma once 
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PCF8574.h>
#include <Servo.h>
const int leftButtonFlipperPin = 1;  // PCF8574 P0
const int rightButtonFlipperPin = 0; // PCF8574 P1
const int leftFlipperPin = 5;
const int rightFlipperPin = 6;
const int leftIrPin = 2;
const int rightIrPin = 7;
const int ldrPin = A4;
const int pinkyServoPin = 8;
const int blinkyServoPin = 4;
const int clydeServoPin = 11;
const int ghostsDetectiePinnen[3] = {2, 3, 4}; //PCF8574 P2, P3, P4: pinky, blinky en clyde
const int safeLedPin = 13;
extern Adafruit_PCF8574 pcf; //zorgt voor extra pinnen
extern bool ghostsLocked[3];
extern bool startFrightenedGhost;
void pinModes(){
    pinMode(safeLedPin, OUTPUT);
    pinMode(rightIrPin, INPUT);
    pinMode(leftIrPin, INPUT_PULLUP);
    pcf.pinMode(leftButtonFlipperPin, INPUT_PULLUP);
    pcf.pinMode(rightButtonFlipperPin, INPUT_PULLUP);
    for (int i = 0; i < 3; i++) pcf.pinMode(ghostsDetectiePinnen[i], INPUT_PULLUP);
}
const int scoreEnegizer = 50; //de score die je krijgt van een (available) enegizer te raken.
const int scoreGhost = 200; //de hoeveelheid punten die je krijgt als je je ball locked.
const int scoreMultibal = 500; //de hoeveelheid punten die je krijgt als alle ghosts gelocked zijn.
const unsigned long safeTime = 60000; //de tijd die je hebt om je safe te gebruiken.
const unsigned long frightenedGhostTime = 30000; // de hoeveelheid seconde waar de ghosts bang voor je zijn.
const unsigned long displayTime = 6000; //hoelang tekst zichtbaar blijft op het scherm.
const int servoGhostDownAngle = 180;// Dit is de hoek waar de servo in moet staan om de ball in de ghost naar beneden te brengen.
const int servoGhostLockAngle = 90;// Dit is de hoek waar de servo in moet staan om de ball in de ghost te locken.
const int servoGhostReleaseAngle = 0;// Dit is de hoek waar de servo in moet staan om de ball in de ghost te release.
//boven down down
//midden midden midden

//boven midden midden
//laag laag laag

Servo leftFlipper;
Servo rightFlipper;
Servo blinky; //de middelste poort
Servo clyde; //de rechter poort
Servo pinky; //de linker port
Servo ghosts[3] = {pinky, blinky, clyde};
#endif

//Adafruit_PCF8574 