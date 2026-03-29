// Pin Definitions
const int stepPin = 18;
const int dirPin = 19;

// Timing Variables
unsigned long previousMillis = 0;
const long interval = 10 * 60 * 1000; // 10 minutes in milliseconds
const int stepsPerRevolution = 2048;   // Specific to 28BYJ-48 (geared)

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  // Set initial direction
  digitalWrite(dirPin, HIGH); 
}

void moveStepper(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000); // Adjust speed here (lower = faster)
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if 10 minutes have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Move the motor (e.g., one full rotation)
    moveStepper(stepsPerRevolution);
  }
}