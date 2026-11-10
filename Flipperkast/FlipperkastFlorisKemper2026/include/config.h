

#ifndef config_h
#define config_h
#pragma once 
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PCF8574.h>
#include <Wire.h>
#include <Adafruit_PCF8574.h>
#include <Servo.h>
const int leftButtonFlipperPin = 1;  // PCF8574 P0
const int rightButtonFlipperPin = 0; // PCF8574 P1
const int leftUpFlipperPin = 13;
const int rightUpFlipperPin = 12;
const int leftFlipperPin = 5;
const int rightFlipperPin = 6;
const int proximityPin = 2;
const int rightIrPin = 7;
const int ldrPin = A2;
const int pinkyServoPin = 8;
const int blinkyServoPin = 4;
const int clydeServoPin = 11;
const int ghostsDetectiePinnen[3] = {2, 3, 4}; //PCF8574 P2, P3, P4: pinky, blinky en clyde
const int safeLedPin = 3;
extern Adafruit_PCF8574 pcf; //zorgt voor extra pinnen
extern bool ghostsLocked[3];
extern bool startFrightenedGhost;
volatile bool proximityFlag = false;   // true als de inductieve sensor de bal heeft gezien

void proximityISR(){ //De ISR (=Interrupt Service Routine) code. deze word alleen uitgevoerd door de interupt. 
    proximityFlag = true;
}

void pinModes(){
    pinMode(safeLedPin, OUTPUT);
    pinMode(rightIrPin, INPUT);
    pinMode(proximityPin, INPUT_PULLUP);
    pcf.pinMode(leftButtonFlipperPin, INPUT_PULLUP);
    pcf.pinMode(rightButtonFlipperPin, INPUT_PULLUP);
    for (int i = 0; i < 3; i++) pcf.pinMode(ghostsDetectiePinnen[i], INPUT_PULLUP);
    pinMode(rightIrPin, INPUT);
    pinMode(proximityPin, INPUT_PULLUP);
    pcf.pinMode(leftButtonFlipperPin, INPUT_PULLUP);
    pcf.pinMode(rightButtonFlipperPin, INPUT_PULLUP);
    for (int i = 0; i < 3; i++) pcf.pinMode(ghostsDetectiePinnen[i], INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(proximityPin), proximityISR, FALLING);
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


Servo leftUpFlipper;
Servo rightUpFlipper;
Servo leftFlipper;
Servo rightFlipper;
Servo blinky; //de middelste poort
Servo clyde; //de rechter poort
Servo pinky; //de linker port
Servo ghosts[3] = {pinky, blinky, clyde};
#endif

//Adafruit_PCF8574 
//Tech Explorations, “10. The interrupt service routine and volatile variables - Tech Explorations,” Tech Explorations, Mar. 05, 2024. https://techexplorations.com/guides/arduino/programming/interrupts-volatile/ 
//“attachInterrupt(),” arduino.cc, Apr. 24, 2025. https://docs.arduino.cc/language-reference/en/functions/external-interrupts/attachInterrupt/ (accessed Nov. 10, 2026).