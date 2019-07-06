// Specify the electrical connections to the motor driver here
#define AA 5
#define NA 4
#define BB 3
#define NB 2

// Global variables
const int pause = 10;

void setup() {
  // Set the output pins to drive the motor
  pinMode(AA, OUTPUT);
  pinMode(NA, OUTPUT);
  pinMode(BB, OUTPUT);
  pinMode(NB, OUTPUT);
}

void loop() {
  // Step 4
  digitalWrite(AA, HIGH);
  digitalWrite(NA, LOW);
  digitalWrite(BB, LOW);
  digitalWrite(NB, HIGH);
  
  delay(pause);

  // Step 3
  digitalWrite(AA, LOW);
  digitalWrite(NA, HIGH);
  digitalWrite(BB, LOW);
  digitalWrite(NB, HIGH);

  delay(pause);

  // Step 2
  digitalWrite(AA, LOW);
  digitalWrite(NA, HIGH);
  digitalWrite(BB, HIGH);
  digitalWrite(NB, LOW);

  delay(pause);
  
  // Step 1
  digitalWrite(AA, HIGH);
  digitalWrite(NA, LOW);
  digitalWrite(BB, HIGH);
  digitalWrite(NB, LOW);

  delay(pause);
}
