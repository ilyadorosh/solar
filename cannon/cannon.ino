/*
  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int laserPin =  12;      // the number of the LED pin
const int heartPin =  A1;      // the number of the LED pin

// const int buzzerPin = 6;     // buzzer pin


const long firePeriodMs = 300;


//=========================== blink without the delay ======

//=========================== ==========

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
unsigned long duration;
int health = 100;


class Shooter {
 public:
  void shoot() {
    if (millis() - startShootingMs > shootPeriod) {
      shooting = true;
      startShootingMs = millis();
      // Force it to turn on the laser on the next cycle:
      lastActionTimeUs = micros() - intervalOff - 1;
    }
  }

  long getStartShootingMs() { 
    return startShootingMs;
  }

  void cycle();
 private:
  static const long intervalOn = 1000;           // interval at which the laser is on (microseconds)
  static const long intervalOff = 1000;          // interval at which the laser is off (microseconds)
  static const long shootIntervalMs = 80;        // Shooting interval.
  static const long shootPeriod = 100;           // Must be greater than 'shootIntervalMs'.

  bool shooting;
  bool laserOn;
  long startShootingMs;
  long lastActionTimeUs;
  long curWaitUs;
};

void Shooter::cycle() {
  if (!shooting) {
    return;
  }

  if (!laserOn && millis() - startShootingMs > shootIntervalMs) {
    shooting = false;
    return;
  }

  long curTime = micros();

  if (curTime - lastActionTimeUs > curWaitUs) {
    curTime = lastActionTimeUs;
    laserOn = !laserOn;
    digitalWrite(laserPin, laserOn);
    curWaitUs = laserOn ? intervalOn : intervalOff;
  }
}

Shooter shooter;

void setup() {
  // initialize the LED pin as an output:
  pinMode(laserPin, OUTPUT);
  // initialize the buzzer pin as an output:
  //pinMode(buzzerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
    // initialize the solar Vsol pin as an input:
  pinMode(heartPin, INPUT);
  // initialize serial communication:
  Serial.begin(115200);
}

// bool prevButtonState = false;

void loop() {
  // read the state of the pushbutton value:
  // buttonState = digitalRead(buttonPin);
  // bool shoot = (!buttonState && prevButtonState);
  // prevButtonState = buttonState;

  if (millis() - shooter.getStartShootingMs() > firePeriodMs) {
    shooter.shoot();
  }
  
  shooter.cycle();
}

/*
void blink1(){
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMicros = micros();

  if (currentMicros - previousMicros >= interval) {
    // save the last time you blinked the LED
    previousMicros = currentMicros;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      interval = intervalOn;
    } else {
      ledState = LOW;
      interval = intervalOff;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(laserPin, ledState);
  }
}
*/

