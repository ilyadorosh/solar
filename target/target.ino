#include "detector.h"

const int redPin =  10;        // the number of the redLED pin
const int greenPin =  9;      // the number of the greenLED pin
const int solarPin =  A0;      // the number of the solar pin
const int buzzerPin = 4;

int health = 255;

void setLeds(int health) {
  if (health < 0) {
    health = 0;
  }
  if (health > 255) {
    health = 255;
  }
  analogWrite(redPin, health);
  analogWrite(greenPin, 255 - health);
}

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  // while (!Serial) {}
  //Serial.println("Waiting for the button ...");
  setLeds(health);
}

bool prevHit = false;

void loop() {
  long startRead = micros();
  short val = analogRead(A0);
  
  //bool buttonOff = digitalRead(2);
  //if (buttonOff) {
  //  detector.reset();
 //   return;
 // }

  long endTime = micros();
  detector.addSample(val, startRead);

  if (!detector.isFull()) {
    return;
  }

  detector.runFFT();
  bool curHit = checkForShot(detector) && !prevHit;
  prevHit = curHit;
  
  if (curHit) {
    //Serial.println("SHOT!!!!!!!!!!!!!!!!!");
    if (health > 0) {
      tone(buzzerPin, 400, 50);
      health -= 30;
    }   
  }

  setLeds(health);

  /*

  for (int i = 0; i < 100; i++) {
    Serial.println(0);
  }

  double samplingFrequency = detector.samplingFreq(endTime);
  for (int i = 0; i < detector.numFreqs(); i++) {
    //Serial.print(i * samplingFrequency / Detector::NUM_SAMPLES);
    //Serial.print(" ");
    Serial.println(detector.getResult()[i]);
  }
  */

  detector.reset();
}
