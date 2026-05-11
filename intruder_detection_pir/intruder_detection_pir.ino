#include <LiquidCrystal.h>

// ===== LCD Setup =====
// RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// ===== Sensor Pins =====
#define PIR_PIN 2
#define TRIG_PIN 3
#define ECHO_PIN 4

// ===== Parameters =====
int distanceThreshold = 50; // in cm
long duration;
int distance;
int pirState = LOW;

void setup() {
  // Start Serial Monitor
  Serial.begin(9600);

  // PIR pin
  pinMode(PIR_PIN, INPUT);

  // Ultrasonic pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // LCD setup
  lcd.begin(16, 2);
  lcd.print("System Ready");
  Serial.println("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  // ---- Read PIR ----
  pirState = digitalRead(PIR_PIN);

  // ---- Read Ultrasonic Distance ----
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // distance in cm

  // ---- Determine Status ----
  lcd.clear();
  if (pirState == HIGH && distance < distanceThreshold) {
    lcd.setCursor(0, 0);
    lcd.print("⚠ INTRUDER ALERT");
    Serial.println("⚠ INTRUDER ALERT");
  }
  else if (pirState == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Motion Detected");
    Serial.println("Motion Detected");
  }
  else if (distance < distanceThreshold) {
    lcd.setCursor(0, 0);
    lcd.print("Object Detected");
    Serial.println("Object Detected");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("Area Safe");
    Serial.println("Area Safe");
  }

  // ---- Debug Distance & PIR Values ----
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | PIR: ");
  Serial.println(pirState);

  delay(500); // half-second update
}