#include <SoftwareSerial.h>

// Define pins
const int pirPin = 2;        // PIR sensor input pin
const int buzzerPin = 9;     // Buzzer output pin

// Create SoftwareSerial object for Bluetooth communication
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize SoftwareSerial for Bluetooth
  mySerial.begin(9600);
  
  // Set pin modes
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Notify that the system is ready
  mySerial.println("System ready. Awaiting motion detection...");
  Serial.println("System ready. Awaiting motion detection...");
}

void loop() {
  // Read PIR sensor
  int motionDetected = digitalRead(pirPin);

  if (motionDetected == HIGH) { // Motion detected
    // Sound the buzzer
    digitalWrite(buzzerPin, HIGH);
    
    // Send Bluetooth notification
    mySerial.println("Detected!!!");
    Serial.println("Motion detected! Buzzer ON. Notification sent via Bluetooth.");
    
    // Optional: Keep the buzzer on for a while (e.g., 1 second) and then turn it off
    delay(1000);
    digitalWrite(buzzerPin, LOW);
    
    // Wait for a while to avoid multiple notifications
    delay(2000);
  } else {
    // No motion detected
    digitalWrite(buzzerPin, LOW);
  }
}
