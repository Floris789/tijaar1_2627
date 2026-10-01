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
bool start = false;
bool clydeNotDetectie = true;
bool pinkyNotDetectie = true;
bool blinkyNotDetectie = true;
bool enegizer1Available = true; //of je de linker enegizer kan gebruiken
bool enegizer2Available = true; //of je de rechter enegizer kan gebruiken
int score = 0; //Je hoeveelheid punten
const int scoreEnegizer = 50; //de score die je krijgt van een (available) enegizer te raken
const int scoreGhost = 200; //de hoeveelheid punten die je krijgt als je je ball locked
const int scoreMultibal = 500; //de hoeveelheid punten die je krijgt als alle ghosts gelocked zijn.
int lives = 3; //de hoeveelheid keer dat je je ball kan verliest
bool safe = true; //als deze true is dan  verlies je geen leven als je een bal verliest
const unsigned long safeDelay = 60000; //de tijd die je hebt om je safe te gebruiken
bool blinkyLocked = false; //is true waneer je je ball in blinky hebt terwijl hij  bang is
bool pinkyLocked = false; //is true waneer je je ball in pinky hebt terwijl hij bang is
bool clydeLocked = false; //is true waneer je je ball in clyde hebt terwijl hij bang is
bool startFrightenedGhost;
unsigned long beginFrightenedGhost = 0;
const unsigned long frightenedGhostTime = 30000; // de hoeveelheid seconde die de ghosts bang voor je zijn
const int servoGhostDownAngle = 0;// de fase waarin de servo van de ghost is. 0 betekent beneden, 1 betekent in lock fase en 2 in release fase.
const int servoGhostLockAngle = 0;// de fase waarin de servo van de ghost is. 0 betekent beneden, 1 betekent in lock fase en 2 in release fase.
const int servoGhostReleaseAngle = 0;// de fase waarin de servo van de ghost is. 0 betekent beneden, 1 betekent in lock fase en 2 in release fase.
int ball = 1; // de hoeveelheid speelballen in het veld
Servo leftFlipper;
Servo rightFlipper;
Servo blinky;
Servo clyde;
Servo pinky;
bool frightenedGhost();
void setup() {
  Serial.begin(9600);
  pinMode(leftButtonFlipperPin, INPUT_PULLUP);
  pinMode(rightButtonFlipperPin, INPUT_PULLUP);
  pinMode(blinkyDetectiePin, INPUT_PULLUP);
  pinMode(clydeDetectiePin, INPUT_PULLUP);
  pinMode(pinkyDetectiePin, INPUT_PULLUP);
  leftFlipper.attach(leftFlipperPin);
  rightFlipper.attach(rightFlipperPin);
  blinky.attach(blinkyServoPin);
  clyde.attach(clydeServoPin);
  pinky.attach(pinkyServoPin);
}
bool gameStart(){
  return ((start == false) && !digitalRead(leftButtonFlipperPin) && !digitalRead(rightButtonFlipperPin));
}
void flippers(){
  if (digitalRead(leftButtonFlipperPin)){
    leftFlipper.write(90);
  }else{
    leftFlipper.write(0);
  }
}
void enegizers(){
  if (enegizer1Available && digitalRead(leftIrPin)){
    enegizer1Available = false;
    frightenedGhost(); //zorgt ervoor dat je in de spoken moet nadat je over een enegizer bent gegaan
  }
  if (enegizer2Available && digitalRead(rightIrPin)){
    enegizer2Available = false;
    frightenedGhost();
  }
}
bool frightenedGhost(){
  if (startFrightenedGhost == false){
    beginFrightenedGhost = millis();
    startFrightenedGhost = true;
  }
  score += scoreEnegizer;
  blinky.write(servoGhostLockAngle);
  pinky.write(servoGhostLockAngle);
  clyde.write(servoGhostLockAngle);
  blinkyLocked = !digitalRead(blinkyDetectiePin);
  pinkyLocked = !digitalRead(pinkyDetectiePin);
  clydeLocked = !digitalRead(clydeDetectiePin); 
  // kijk later of de code hieronder beter kan
  if (!digitalRead(clydeDetectiePin) && (clydeNotDetectie == true)){ //balllocked
    score += scoreGhost;
    //zet de display naar ball locked
    clydeNotDetectie = false;
  }
  if (digitalRead(clydeDetectiePin)){
    clydeNotDetectie = true;
  }

  if (!digitalRead(pinkyDetectiePin) && (pinkyNotDetectie == true)){
    score += scoreGhost;
    //zet de display naar ball locked
    pinkyNotDetectie = false;
  }
  if (digitalRead(pinkyDetectiePin)){
    pinkyNotDetectie = true;
  }

  if (!digitalRead(blinkyDetectiePin) && (blinkyNotDetectie == true)){ 
    score += scoreGhost;
    //zet de display naar ball locked
    blinkyNotDetectie = false;
  }
  if (digitalRead(blinkyDetectiePin)){
    blinkyNotDetectie = true;
  }
  if (blinkyLocked && pinkyLocked && clydeLocked){ //multiball
    score += scoreMultibal;
    ball += 2;
    //zet de display naar multibal
    blinky.write(servoGhostReleaseAngle);
    pinky.write(servoGhostReleaseAngle);
    clyde.write(servoGhostReleaseAngle);
    clydeLocked = false;
    pinkyLocked = false;
    blinkyLocked = false;
    delay(200);
  }
  if(beginFrightenedGhost + frightenedGhostTime >= millis()){
  startFrightenedGhost = false;
  return false;
  }
  return true;
}
void lock(){
}
void ballSafe(){
}
void lose(){
}
void loop() {
  if (gameStart()){
    start = true;
    Serial.print("game started");
    flippers();
    if (startFrightenedGhost){
      frightenedGhost();
    }
  }
}
