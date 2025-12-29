#include <Servo.h>

Servo scanner;

// ========================= SERVO =========================
int servoPin = 4;

// ====================== Ultrasonic =======================
int trigPin = 13;
int echoPin = 12;

// ===================== Right Motor =======================
int enableRightMotor = 5;   // ENA
int rightMotorPin1  = 6;    // IN1
int rightMotorPin2  = 7;    // IN2

// ===================== Left Motor ========================
int enableLeftMotor = 8;    // ENB
int leftMotorPin1   = 9;    // IN3
int leftMotorPin2   = 10;   // IN4


// =====================================================
// Read Distance Function
// =====================================================
long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 50000);
  if (duration == 0) return 300;

  return duration * 0.034 / 2;
}


// =====================================================
// Motor Control Function
// =====================================================
void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  // ---------- Right Motor ----------
  if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  // ---------- Left Motor ----------
  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  // Speed Control
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}


// =====================================================
// Setup
// =====================================================
void setup() {
  Serial.begin(9600);

  scanner.attach(servoPin);
  scanner.write(90);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  rotateMotor(0, 0);   // Stop at Start
}


// =====================================================
// Loop
// =====================================================
void loop() {

  long distance = readDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  // ===== If obstacle detected =====
  if (distance < 20) {

    rotateMotor(0, 0);   // Stop

    // Scan Right
    scanner.write(30);
    delay(400);
    long right = readDistance();

    // Scan Left
    scanner.write(150);
    delay(400);
    long left = readDistance();

    scanner.write(90);

    // Decide Direction
    if (right > left) {
      // Turn Right
      rotateMotor(-180, 180);
    } else {
      // Turn Left
      rotateMotor(180, -180);
    }

    delay(500);
  }

  // ===== Else Move Forward =====
  else {
    rotateMotor(180, 180);
  }
}
