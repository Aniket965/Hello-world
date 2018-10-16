// Line-Following Algorithm
// By Connor L. (Ibaeni)

//Pins 0,1 Used for Bluetooth
//Pins 2,3 Used for Ultrasonic Rangefinder
int sensleft = A0;
int sensright = A1;

// Motor 1 Vars (9v Battery Side)
// Forward (1:2) == (LOW, HIGH))
// a1 = 8; a2 = 9; velPin1 = 7;
int motor1pins[] = {8, 9, 7};
int vel1;

// Motor 2 Vars (USB Side)
// Forward (1:2) == (LOW, HIGH)
// b1 = 12; b2 = 10; velPin2 = 11;
int motor2pins[] = {12, 10, 11};
int vel2;

void setup() {
  Serial.begin(9600);

  pinMode(sensleft, OUTPUT);
  pinMode(sensright, OUTPUT);
  
  for (int i = 0; i < 3; i++) {
    pinMode(motor1pins[i], OUTPUT);
    pinMode(motor2pins[i], OUTPUT);
  }
  
}

void loop() {
  delay(50);
  unsigned int left = analogRead(sensleft);
  unsigned int right = analogRead(sensright);
  Serial.println(String(left));
  Serial.println(String(right));

  if (left == HIGH and right == HIGH) {
    forwards(200);
  }
  else if (left == HIGH and right == LOW) {
    turn_left(100);
  }
  else if (left == LOW and right == HIGH) {
    turn_right(100);
  }
  else {
    motors_stop();
  }
}

// Motor functions
void backwards(int vel)
{
  digitalWrite(motor1pins[0], HIGH);
  digitalWrite(motor1pins[1], LOW);
  analogWrite(motor1pins[2], vel);

  digitalWrite(motor2pins[0], HIGH);
  digitalWrite(motor2pins[1], LOW);
  analogWrite(motor2pins[2], vel);
}

void forwards(int vel)
{
  digitalWrite(motor1pins[0], LOW);
  digitalWrite(motor1pins[1], HIGH);
  analogWrite(motor1pins[2], vel);

  digitalWrite(motor2pins[0], LOW);
  digitalWrite(motor2pins[1], HIGH);
  analogWrite(motor2pins[2], vel);
}

void turn_left(int vel) {
  digitalWrite(motor1pins[0], HIGH);
  digitalWrite(motor1pins[1], LOW);
  analogWrite(motor1pins[2], vel);

  digitalWrite(motor2pins[0], LOW);
  digitalWrite(motor2pins[1], HIGH);
  analogWrite(motor2pins[2], vel);
}

void turn_right(int vel) {
  digitalWrite(motor1pins[0], LOW);
  digitalWrite(motor1pins[1], HIGH);
  analogWrite(motor1pins[2], vel);

  digitalWrite(motor2pins[0], HIGH);
  digitalWrite(motor2pins[1], LOW);
  analogWrite(motor2pins[2], vel);
}

void motors_stop(){
  digitalWrite(motor1pins[0], LOW);
  digitalWrite(motor1pins[1], LOW);
  analogWrite(motor1pins[2], 0);

  digitalWrite(motor2pins[0], LOW);
  digitalWrite(motor2pins[1], LOW);
  analogWrite(motor2pins[2], 0);
}
