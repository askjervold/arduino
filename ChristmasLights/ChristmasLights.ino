// Light pins
const byte red_one = 3;
const byte red_two = 5;
const byte red_three = 7;
const byte red_four = 9;
const byte red_five = 11;
const byte red_six = 13;
const byte green_one = 4;
const byte green_two = 6;
const byte green_three = 8;
const byte green_four = 10;
const byte green_five = 12;

// Other pins
const byte buttonPin = 2;

// Variables that will change
int playingJingle = 0;

void setup() {
  // Outputs
  pinMode(green_five, OUTPUT);
  
  // Inputs
  pinMode(buttonPin, INPUT);
}

void loop() {
  // When button is pressed ...
  if (digitalRead(buttonPin) == HIGH) {
    if (!playingJingle) {
      playJingle();
      redsOn();
      greensOff();  
    }
    else {
      playJingle();
      redsOff();
      greensOn();
    }
  }
}

void playJingle() {
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
  digitalWrite(red_five, HIGH);
  digitalWrite(red_six, HIGH);
}

void redsOff() {
  digitalWrite(red_one, LOW);
  digitalWrite(red_two, LOW);
  digitalWrite(red_three, LOW);
  digitalWrite(red_four, LOW);
  digitalWrite(red_five, LOW);
  digitalWrite(red_six, LOW);
}
