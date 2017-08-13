#include "arduinoFFT.h"

void center(double *values, int len) {
  double sum = 0;
  for (int i = 0; i < len; i++) {
    sum += values[i];
  }
  double mean = sum / len;
  for (int i = 0; i < len; i++) {
    values[i] -= mean;
  }
}

class Detector {
 public:
  static const short NUM_SAMPLES = 128;
 
  void addSample(short sample, long startTime) {
    if (sampleCount < NUM_SAMPLES) {
      if (sampleCount == 0) {
        this->startTime = startTime;
      }
      vReal[sampleCount] = sample;
      vImag[sampleCount] = 0;
      sampleCount++;
    }
  }

  double samplingFreq(long endTime) {
    return 1000000.0 * NUM_SAMPLES / (endTime - startTime);
  }

  bool isFull() {
    return sampleCount >= NUM_SAMPLES;
  }

  void reset() {
    fftRun = false;
    sampleCount = 0;
  }

  void runFFT();

  double *getResult() { return vReal; }
  short numFreqs() { return NUM_SAMPLES / 2; }

 private:
  arduinoFFT fft;
  double vReal[NUM_SAMPLES];
  double vImag[NUM_SAMPLES];
  long startTime;
  short sampleCount;
  bool fftRun;
};

void Detector::runFFT() {
  if (fftRun) {
    return;
  }
  center(vReal, NUM_SAMPLES);
  fft.Windowing(vReal, NUM_SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  fft.Compute(vReal, vImag, NUM_SAMPLES, FFT_FORWARD);
  fft.ComplexToMagnitude(vReal, vImag, NUM_SAMPLES);
  fftRun = true;
}

Detector detector;

//bool checkForShot() {
  
//}

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

  for (int i = 0; i < 100; i++) {
    Serial.println(0);
  }

  double samplingFrequency = detector.samplingFreq(endTime);
  for (int i = 0; i < detector.numFreqs(); i++) {
    //Serial.print(i * samplingFrequency / Detector::NUM_SAMPLES);
    //Serial.print(" ");
    Serial.println(detector.getResult()[i]);
  }

  detector.reset();
}
