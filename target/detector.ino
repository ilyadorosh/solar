#include "detector.h"

const double DETECT_THRESHOLD = 300;

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

bool checkForShot(const Detector& detector) {
  return detector.getResult()[8] > DETECT_THRESHOLD;
}
