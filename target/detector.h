#ifndef DETECTOR_H
#define DETECTOR_H

#include "arduinoFFT.h"

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

extern Detector detector;

#endif  // Header guard
