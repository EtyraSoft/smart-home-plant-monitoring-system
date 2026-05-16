

![Project Image](https://res.cloudinary.com/dhmxvivgg/image/upload/v1778973726/etyra_seo/projects/project_14fdad61-d4cf-4275-b856-3ca02f4ba6c9.jpg)

[English](README.md) | [Romanian](README-ro.md)

---

```markdown
# 🌿 Smart Home Plant Monitoring System

## 🚀 Project Goals
The objective of this project is to develop a smart home plant monitoring system that utilizes a [Soil Moisture Sensor [EN Market]](https://electronicmarket.ro/product/soil-moisture-detection-module) and an [ESP32 Development Board [EN Market]](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) to monitor the moisture levels of soil. The system will send notifications to a smartphone when the moisture level drops below a predefined threshold, indicating that the plant needs watering.

---

## 💡 Background Theory
Soil moisture sensors operate by measuring the volumetric water content in the soil. The sensor outputs a voltage corresponding to the moisture level, which the [ESP32 Development Board [EN Market]](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) can process. The [1-Channel 5V Relay Module [EN Market]](https://electronicmarket.ro/modul-releu-5v-1-canal) is used to control an external water pump or alarm system.

### Key Concepts
- **Signal Attenuation**: Signal strength reduction that may occur due to environmental factors affecting sensor readings.
- **IoT (Internet of Things)**: This project falls under IoT, as it involves networked microcontrollers to handle data and alerts.

---

## 🔧 Bill of Materials
| Component | Description | Function |
|-----------|-------------|----------|
| [ESP32 Development Board [EN Market]](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) | Microcontroller | Processes sensor data and controls relay |
| [Soil Moisture Sensor [EN Market]](https://electronicmarket.ro/product/soil-moisture-detection-module) | Sensor | Detects moisture levels in soil |
| [1-Channel 5V Relay Module [EN Market]](https://electronicmarket.ro/modul-releu-5v-1-canal) | Relay | Controls external devices like water pumps |
| [400 Tie-Points Breadboard (Half Size) [EN Market]](https://electronicmarket.ro/product/400-puncte-fara-lipire-breadboard) | Breadboard | Provides a solderless platform for circuit assembly |
| [Dupont Jumper Wires (Male-to-Male) [EN Market]](https://electronicmarket.ro/product/cabluri-jumper-de-20-cm-cu-40-de-pini-de-la-tata-la-tata) | Connecting Wires | Connect components on the breadboard |

---

## 🛠️ Assembly Instructions

### Pin Connections
Connect the components as follows:

- **ESP32 Development Board**
  - `GND` -> Common ground rail on the breadboard
  - `Vin` -> Positive rail on the breadboard (powered through USB)
  
- **Soil Moisture Sensor**
  - `VCC` -> Positive rail
  - `GND` -> Ground rail
  - `Signal` -> GPIO 34 on ESP32

- **1-Channel 5V Relay Module**
  - `VCC` -> Positive rail
  - `GND` -> Ground rail
  - `IN` -> GPIO 27 on ESP32

### Wiring Diagram Description
The ESP32 serves as the central processing unit. The soil moisture sensor connects to GPIO 34, while the relay module is connected to GPIO 27. The relay can control devices like water pumps, triggered when the soil moisture falls below a set threshold.

---

## 💻 Code Walkthrough

```cpp
#include <WiFi.h>
#include <FirebaseESP32.h>

#define SOIL_SENSOR_PIN 34
#define RELAY_PIN 27

void setup() {
  Serial.begin(115200);
  pinMode(SOIL_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  WiFi.begin("SSID", "PASSWORD");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  int soilMoistureValue = analogRead(SOIL_SENSOR_PIN);
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  if (soilMoistureValue < 500) { // Adjust threshold as needed
    digitalWrite(RELAY_PIN, HIGH); // Activate relay
    Serial.println("Relay Activated");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Deactivate relay
    Serial.println("Relay Deactivated");
  }
  delay(2000);
}
```

### Example Serial Output:
```
Connecting to WiFi...
Connected to WiFi
Soil Moisture Value: 300
Relay Activated
Soil Moisture Value: 700
Relay Deactivated
```

---

## ⚠️ Troubleshooting

1. **WiFi Connection Issues**:
   - Ensure SSID and Password are correct.
   - Check router settings or obstacles causing signal attenuation.

2. **Sensor Malfunction**:
   - Verify connections to ensure no loose wiring.
   - Check sensor functionality by testing with a multimeter.

3. **Relay Module Not Activating**:
   - Ensure the relay module is powered correctly.
   - Check GPIO pin configurations in the code.

---

## 🔍 Debugging Guide
- **Serial Monitor**: Use for real-time debugging. Print sensor values and relay status.
- **LED Indicators**: Connect an LED to show relay status for quick visual feedback.
- **Multimeter Testing**: Test voltage levels at key points to verify component operation.

---

## 🌟 Enhancement Ideas
1. **Add Humidity and Temperature Sensors**: Integrate additional environmental sensors to provide a more comprehensive plant care system.
2. **Automate Watering**: Incorporate a solenoid valve and water pump to automate the watering process based on sensor data.
3. **Mobile App Integration**: Develop a mobile app to receive notifications and control the system remotely.

---

```
