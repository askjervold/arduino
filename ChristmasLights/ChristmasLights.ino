// Light pins
const byte red_one = 5;
const byte red_two = 7;
const byte red_three = 9;
const byte red_four = 11;
const byte green_one = 4;
const byte green_two = 6;
const byte green_three = 8;
const byte green_four = 10;
const byte green_five = 12;

// Other pins
const byte buttonPin = 2;

// Other constants
const int numLeds = 9;
const byte leds [numLeds] = {green_one, red_one, green_two, red_two, green_three, red_three, green_four, red_four, green_five};

// Variables that will change
int playingJingle = 0;
int inactiveLedCounter = 0;

void setup() {
  // Outputs
  pinMode(green_five, OUTPUT);
  pinMode(green_four, OUTPUT);
  pinMode(green_three, OUTPUT);
  pinMode(green_two, OUTPUT);
  pinMode(green_one, OUTPUT);
  pinMode(red_four, OUTPUT);
  pinMode(red_three, OUTPUT);
  pinMode(red_two, OUTPUT);
  pinMode(red_one, OUTPUT);
  
  // Inputs
  pinMode(buttonPin, INPUT);
  
  // Starting leds
  greensOn();
  redsOn();
}

void loop() {
  if (!playingJingle) {
    if (digitalRead(buttonPin) == HIGH) {
      playJingle();
    }
    loopLeds();
    delay(100);
  }
}

void loopLeds() {
  int turnOn = inactiveLedCounter - 1;
  if (turnOn != -1) {
    digitalWrite(leds[turnOn], HIGH);
  }
  else {
    digitalWrite(leds[numLeds], HIGH);
  }
  digitalWrite(leds[inactiveLedCounter], LOW);
  if (inactiveLedCounter++ == numLeds) {
    inactiveLedCounter = 0;
  }
}

void playJingle() {
  if (!playingJingle) {
      redsOn();
      greensOff();  
    }
    else {
      redsOff();
      greensOn();
    }
  playingJingle = !playingJingle;
  delay(250);
}

void greensOn() {
  digitalWrite(green_one, HIGH);
  digitalWrite(green_two, HIGH);
  digitalWrite(green_three, HIGH);
  digitalWrite(green_four, HIGH);
  digitalWrite(green_five, HIGH);
}

void greensOff() {
  digitalWrite(green_one, LOW);
  digitalWrite(green_two, LOW);
  digitalWrite(green_three, LOW);
  digitalWrite(green_four, LOW);
  digitalWrite(green_five, LOW);
}

void redsOn() {
  digitalWrite(red_one, HIGH);
  digitalWrite(red_two, HIGH);
  digitalWrite(red_three, HIGH);
  digitalWrite(red_four, HIGH);
}

void redsOff() {
  digitalWrite(red_one, LOW);
  digitalWrite(red_two, LOW);
  digitalWrite(red_three, LOW);
  digitalWrite(red_four, LOW);
}
