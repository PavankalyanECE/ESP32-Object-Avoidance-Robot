#include <Servo.h> // Use <ESP32Servo.h> if you get compilation errors on the ESP32!

// --- Pin Definitions ---
// Ultrasonic Sensor Pins
#define TRIG 5
#define ECHO 18

// Motor Driver Pins (L298N or similar)
#define IN1 27 // Left Motor Forward
#define IN2 26 // Left Motor Backward
#define IN3 25 // Right Motor Forward
#define IN4 33 // Right Motor Backward

// Servo Motor Pin
#define SERVO_PIN 13

// --- Variables ---
Servo myservo; // Create servo object to control the sensor mount

long duration; // Stores the time taken for the ultrasonic wave to bounce back
int distance;  // Stores the calculated distance to the object

int leftDistance;  // Distance measured when the sensor looks left
int rightDistance; // Distance measured when the sensor looks right

void setup() {

  // Set up ultrasonic sensor pins
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Set up motor driver pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Attach the servo to the specified ESP32 GPIO pin
  myservo.attach(SERVO_PIN);

  // Center the servo to look straight ahead
  myservo.write(90);

  // Start serial communication
  Serial.begin(115200);
}

// Function to measure distance using ultrasonic sensor
int getDistance() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  // Read echo pulse duration
  duration = pulseIn(ECHO, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  return distance;
}

// Move robot forward
void forward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Stop robot
void stopRobot() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Turn robot left
void turnLeft() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(500);
}

// Turn robot right
void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(500);
}

void loop() {

  // Measure front distance
  distance = getDistance();

  // Print distance to Serial Monitor
  Serial.println(distance);

  // Path clear
  if (distance > 20) {

    forward();

  } else {

    // Obstacle detected
    stopRobot();
    delay(300);

    // Look left
    myservo.write(150);
    delay(500);

    leftDistance = getDistance();

    // Look right
    myservo.write(30);
    delay(500);

    rightDistance = getDistance();

    // Center servo
    myservo.write(90);

    // Decide best direction
    if (leftDistance > rightDistance) {

      turnLeft();

    } else {

      turnRight();
    }
  }
}
