#include <Servo.h>

#define Echo  A4
#define Trig  A3 
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define ENA 6
#define carSpeed 140

Servo myservo;

int rd = 0, ld = -1, md = -1;

void forward(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Back");
}

void left() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Left");
}

void right() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}

int getDistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  return (int)pulseIn(Echo, HIGH) / 58;
}

void setup() {
  myservo.attach(3);
  myservo.write(90);  // Set servo to the center
  delay(1000);
  
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  stop();
  Serial.begin(9600);
}

void loop() {
  md = getDistance();
  
  if(md < 35 && md >= 0) {
    stop();
    delay(500);
    back();
    delay(1000);
    stop();
    
    // Scan left
    myservo.write(180);
    delay(500);
    ld = getDistance();
    Serial.print("Left distance: ");
    Serial.println(ld);
    
    // Scan right
    myservo.write(0);
    delay(500);
    rd = getDistance();
    Serial.print("Right distance: ");
    Serial.println(rd);
    
    // Reset servo to center
    myservo.write(90);
    delay(500);
    
    // Choose turning direction based on sensor data
    if(ld > rd) {
      left();
      delay(600);
      stop();
      forward();
    } else if(ld < rd) {
      right();
      delay(600);
      stop();
      forward();
    }
    
    // Reset distance variables
    ld = -1;
    rd = -1;
  }
  
  if(md > 35) {
    forward();
  }
}
