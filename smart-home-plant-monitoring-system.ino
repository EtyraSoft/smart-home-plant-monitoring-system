/*
  Project: Smart Home Plant Monitoring System
  Description: This project monitors the soil moisture levels using a Soil Moisture Sensor connected to an ESP32 Development Board. 
               It sends notifications to a smartphone when the soil is dry and needs watering. The system uses a 1-Channel 5V Relay Module 
               to control an external device such as a water pump.
  Components: ESP32 Development Board, Soil Moisture Sensor, 1-Channel 5V Relay Module, Breadboard, Arduino Uno (not used in this code),
              Dupont Jumper Wires
*/

#include <WiFi.h>           // Include the WiFi library for ESP32
#include <HTTPClient.h>     // Include HTTPClient library for sending notifications

// Pin Definitions
const int soilMoisturePin = 34; // Analog pin connected to the soil moisture sensor
const int relayPin = 23;        // Digital pin connected to the relay module

// WiFi Credentials
const char* ssid = "your_SSID";          // Replace with your WiFi SSID
const char* password = "your_PASSWORD";  // Replace with your WiFi password

// Notification settings
const char* serverName = "http://example.com/notify"; // Replace with your notification server URL

// Thresholds
const int moistureThreshold = 500; // Threshold value for dry soil

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Initialize the soil moisture sensor pin
  pinMode(soilMoisturePin, INPUT);

  // Initialize the relay pin
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Turn off relay initially

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi");
}

void loop() {
  // Read the soil moisture level
  int soilMoistureValue = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  // Check if soil is dry
  if (soilMoistureValue > moistureThreshold) {
    Serial.println("Soil is dry, activating relay and sending notification...");
    
    // Activate relay
    digitalWrite(relayPin, HIGH);

    // Send notification
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverName);
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("Notification sent, response code: ");
        Serial.println(httpResponseCode);
      } else {
        Serial.print("Error in sending notification, error code: ");
        Serial.println(httpResponseCode);
      }
      http.end();
    } else {
      Serial.println("Error: WiFi not connected");
    }
  } else {
    Serial.println("Soil is moist, no action required");
    digitalWrite(relayPin, LOW);
  }

  // Wait for 10 seconds before the next reading
  delay(10000);
}