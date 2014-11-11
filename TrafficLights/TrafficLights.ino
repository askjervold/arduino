/* An implementation of a pedestrian crossing
  Pressing a button will after a few seconds give a red light to the traffic
  and a green light to the pedestrians. After some more seconds, the pedestrian
  green light will start to blink and the speaker will beep. After a few seconds of this
  the pedestrian light will turn red and the traffic lights will turn green again.
*/ 

// Pedestrian lights
const byte pedRedPin = 2;
const byte pedGreenPin = 3;

// Traffic lights
const byte trafficRedPin = 11;
const byte trafficYellowPin = 12;
const byte trafficGreenPin = 13;

// Sound
const byte speakerPin = 7;

// Input
const byte buttonPin = 8;

void setup() {
  // Read from the button
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  
  // Output to the diodes and speaker
  pinMode(pedRedPin, OUTPUT);
  pinMode(pedGreenPin, OUTPUT);
  pinMode(trafficRedPin, OUTPUT);
  pinMode(trafficYellowPin, OUTPUT);
  pinMode(trafficGreenPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  
  // Default is traffic has green light, pedestrians have red
  digitalWrite(trafficGreenPin, HIGH);
  digitalWrite(pedRedPin, HIGH);
}

void loop() {
  Serial.println(digitalRead(buttonPin));
  delay(50);
  if (digitalRead(buttonPin) == HIGH) {
    // When the button is pressed, wait 3.5 seconds, then switch the lights
    delay(3000);
    pedestrianRedToGreen();
    
    // After 5 seconds, let switch back
    delay(3000);
    trafficRedToGreen();
  }
}

void trafficRedToGreen() {
  // Give the pedestrians red and wait a few seconds
  pedestrianGreenToRed();
  delay(2000);
  
  // Turn on the yellow light
  digitalWrite(trafficYellowPin, HIGH);
  delay(1000);
  
  // Turn off red and yellow, turn on green
  digitalWrite(trafficRedPin, LOW);
  digitalWrite(trafficYellowPin, LOW);
  digitalWrite(trafficGreenPin, HIGH);
}

void trafficGreenToRed() {
  digitalWrite(trafficGreenPin, LOW);
  digitalWrite(trafficYellowPin, HIGH);
  delay(1500);
  digitalWrite(trafficYellowPin, LOW);
  digitalWrite(trafficRedPin, HIGH);
}

void pedestrianRedToGreen() {
  // Give the traffic red light and wait a second
  trafficGreenToRed();
  delay(1000);
  
  // Turn off the red and on the green
  digitalWrite(pedRedPin, LOW);
  digitalWrite(pedGreenPin, HIGH);
}

void pedestrianGreenToRed() {
  // We should have some sound as well
  for (int beeps = 0; beeps < 7; beeps++) {
    delay(200);
    digitalWrite(pedGreenPin, HIGH);
    delay(300);
    tone(speakerPin, 300, 200);
    digitalWrite(pedGreenPin, LOW);
  }
  
  digitalWrite(pedGreenPin, LOW);
  digitalWrite(pedRedPin, HIGH);
}
