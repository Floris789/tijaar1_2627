#include <Arduino.h>

// Arduino → 74HC595 pinnen
int dataPin = 11;   // DS
int clockPin = 12;  // SRCLK 
int latchPin = 8;   // RCLK

// Segmentdata voor cijfers 0–9 (a–g, dp)
byte digits[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(latchPin, LOW);                        // Latch laag
    shiftOut(dataPin, clockPin, MSBFIRST, digits[i]);   // Stuur bits naar register
    digitalWrite(latchPin, HIGH);                       // Latch hoog = zichtbaar maken
    delay(1000);
  }
}