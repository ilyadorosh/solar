#include "detector.h"

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT_PULLUP);
  while (!Serial) {}
  //Serial.println("Waiting for the button ...");
}

void loop() {
  long startRead = micros();
  short val = analogRead(A0);
  /*
  bool buttonOff = digitalRead(2);
  if (buttonOff) {
    detector.reset();
    return;
  }
  */

  long endTime = micros();
  detector.addSample(val, startRead);

  if (!detector.isFull()) {
    return;
  }

  detector.runFFT();

  if (checkForShot(detector)) {
    Serial.println("SHOT!!!!!!!!!!!!!!!!!");
  }

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
