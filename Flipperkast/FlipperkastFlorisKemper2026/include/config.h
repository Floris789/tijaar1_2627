#ifndef config_h
#define config_h
#pragma once 
#include <Arduino.h>
#include <Servo.h>
const int leftButtonFlipperPin = -1;
const int rightButtonFlipperPin = -1;
const int leftFlipperPin = -1;
const int rightFlipperPin = -1;
const int leftIrPin = -1;
const int rightIrPin = 7;
const int ldrPin = -1;
const int blinkyServoPin = 4;
const int clydeServoPin = -1;
const int pinkyServoPin = -1;
const int ghostsDetectiePinnen[3] = {-1, -1, -1}; //pinky, blinky en clyde
const int safeLedPin = -1;
void pinModes(){
    pinMode(safeLedPin, OUTPUT);
    pinMode(leftButtonFlipperPin, INPUT_PULLUP);
    pinMode(rightButtonFlipperPin, INPUT_PULLUP);
    for (int i = 0; i < 3; i++) pinMode(ghostsDetectiePinnen[i], INPUT_PULLUP);
}
const int scoreEnegizer = 50; //de score die je krijgt van een (available) enegizer te raken.
const int scoreGhost = 200; //de hoeveelheid punten die je krijgt als je je ball locked.
const int scoreMultibal = 500; //de hoeveelheid punten die je krijgt als alle ghosts gelocked zijn.
const unsigned long safeTime = 60000; //de tijd die je hebt om je safe te gebruiken.
const unsigned long frightenedGhostTime = 30000; // de hoeveelheid seconde waar de ghosts bang voor je zijn.
const unsigned long displayTime = 6000; //hoelang tekst zichtbaar blijft op het scherm.
const int servoGhostDownAngle = 0;// Dit is de hoek waar de servo in moet staan om de ball in de ghost naar beneden te brengen.
const int servoGhostLockAngle = 90;// Dit is de hoek waar de servo in moet staan om de ball in de ghost te locken.
const int servoGhostReleaseAngle = 180;// Dit is de hoek waar de servo in moet staan om de ball in de ghost te release.
Servo leftFlipper;
Servo rightFlipper;
Servo blinky;
Servo clyde;
Servo pinky;
Servo ghosts[3] = {pinky, blinky, clyde};
#endif