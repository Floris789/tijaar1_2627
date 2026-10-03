#ifndef config_h
#define config_h
#pragma once 
#include <Arduino.h>
#include <Servo.h>

const int leftButtonFlipperPin = 0;
const int rightButtonFlipperPin = 0;
const int leftFlipperPin = 0;
const int rightFlipperPin = 0;
const int leftIrPin =0;
const int rightIrPin = 0;
const int blinkyServoPin = 0;
const int clydeServoPin = 0;
const int pinkyServoPin = 0;
const int blinkyDetectiePin = 0;
const int clydeDetectiePin = 0;
const int pinkyDetectiePin = 0;

const int scoreEnegizer = 50; //de score die je krijgt van een (available) enegizer te raken
const int scoreGhost = 200; //de hoeveelheid punten die je krijgt als je je ball locked
const int scoreMultibal = 500; //de hoeveelheid punten die je krijgt als alle ghosts gelocked zijn.
const unsigned long safeDelay = 60000; //de tijd die je hebt om je safe te gebruiken
const unsigned long frightenedGhostTime = 30000; // de hoeveelheid seconde die de ghosts bang voor je zijn
const unsigned long displayTime = 6000; //hoelang tekst zichtbaar blijft op het scherm
const int servoGhostDownAngle = 0;// de fase waarin de servo van de ghost is. 0 betekent beneden, 1 betekent in lock fase en 2 in release fase.
const int servoGhostLockAngle = 0;// de fase waarin de servo van de ghost is. 0 betekent beneden, 1 betekent in lock fase en 2 in release fase.
const int servoGhostReleaseAngle = 0;// de fase waarin de servo van de ghost is. 0 betekent beneden, 1 betekent in lock fase en 2 in release fase.
Servo leftFlipper;
Servo rightFlipper;
Servo blinky;
Servo clyde;
Servo pinky;

#endif