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

const int buzzerPin = 6;     // buzzer pin

//=========================== blink without the delay ======
// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMicros = 0;        // will store last time LED was updated

// constants won't change:
const long intervalOn = 1;           // interval at which the laser is on (microseconds)
const long intervalOff = 1;           // interval at which the laser is off (microseconds)
long interval = intervalOff;
//=========================== ==========

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
unsigned long duration;
int health = 100;


void setup() {
  // initialize the LED pin as an output:
  pinMode(laserPin, OUTPUT);
  // initialize the buzzer pin as an output:
  pinMode(buzzerPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
    // initialize the solar Vsol pin as an input:
  pinMode(heartPin, INPUT);
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.println(duration);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  // if (buttonState == HIGH) {
  //   // turn LED on:
  //   blink1();
  // } else {
  //   // turn LED off:
  //   digitalWrite(laserPin, LOW);
  // }
  blink1();
  isHit();
}

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

void isHit(){
  
  //solarDC = analogRead(heartPin);   
  duration = pulseIn(heartPin, LOW, 1100);
  if (duration >= 300) {
    // beep:
    //tone(buzzerPin, solarDC*100, 2000);
    //health--;
  }
}
