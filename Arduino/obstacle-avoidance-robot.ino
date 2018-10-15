// Import Library for Ultrasonic Rangefinder and define variables
// By Connor L. (Ibaeni)
#include <Servo.h>
#include <NewPing.h>
#define PING_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 200

Servo servo;
int pos = 0;

NewPing sonar(PING_PIN, ECHO_PIN, MAX_DISTANCE);

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

void setup()
{
  Serial.begin(9600);

  servo.attach(6);

  for (int i = 0; i < 3; i++) {
    pinMode(motor1pins[i], OUTPUT);
    pinMode(motor2pins[i], OUTPUT);
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

void left(int vel) {
  digitalWrite(motor1pins[0], HIGH);
  digitalWrite(motor1pins[1], LOW);
  analogWrite(motor1pins[2], vel);

  digitalWrite(motor2pins[0], LOW);
  digitalWrite(motor2pins[1], HIGH);
  analogWrite(motor2pins[2], vel);
}

void right(int vel) {
  digitalWrite(motor1pins[0], LOW);
  digitalWrite(motor1pins[1], HIGH);
  analogWrite(motor1pins[2], vel);

  digitalWrite(motor2pins[0], HIGH);
  digitalWrite(motor2pins[1], LOW);
  analogWrite(motor2pins[2], vel);
}

void stop(){
  digitalWrite(motor1pins[0], LOW);
  digitalWrite(motor1pins[1], LOW);
  analogWrite(motor1pins[2], 0);

  digitalWrite(motor2pins[0], LOW);
  digitalWrite(motor2pins[1], LOW);
  analogWrite(motor2pins[2], 0);
}

void loop()
{
  delay(50);
  unsigned int distance = sonar.ping_cm();
  Serial.println("Distance: " + String(distance) + "cm\n");

  if (distance >= 30 or distance == 0) {
    forwards(225);
  }
  else if (distance > 15 and distance < 30) {
    backwards(200);
    delay(500);
    left(180);
    delay(500);
  }
  else {
    stop();
    backwards(100);
    delay(250);
    for (pos = 0; pos<=180; pos += 1) {
      servo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(15);
    }
    backwards(200);
    delay(1000);
    left(200);
    delay(750);
  }
}
