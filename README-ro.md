![Project Image](https://res.cloudinary.com/dhmxvivgg/image/upload/v1778973726/etyra_seo/projects/project_14fdad61-d4cf-4275-b856-3ca02f4ba6c9.jpg)

[English](README.md) | [Romanian](README-ro.md)

# 🌿 Sistem de Monitorizare a Plantelor pentru Casă Inteligentă

## 🚀 Obiectivele Proiectului
Obiectivul acestui proiect este dezvoltarea unui sistem de monitorizare a plantelor pentru casă inteligentă care utilizează un [Senzor de Umiditate a Solului](https://electronicmarket.ro/product/soil-moisture-detection-module) și o [Placă de Dezvoltare ESP32](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) pentru a monitoriza nivelurile de umiditate ale solului. Sistemul va trimite notificări către un smartphone atunci când nivelul de umiditate scade sub un prag predefinit, indicând că planta are nevoie de apă.

---

## 💡 Teorie de Fundal
Senzorii de umiditate a solului funcționează prin măsurarea conținutului volumetric de apă din sol. Senzorul emite o tensiune corespunzătoare nivelului de umiditate, pe care [Placa de Dezvoltare ESP32](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) o poate procesa. [Modulul Releu 5V cu 1 Canal](https://electronicmarket.ro/modul-releu-5v-1-canal) este utilizat pentru a controla o pompă de apă externă sau un sistem de alarmă.

---

## 🔧 Lista de Materiale

| Componentă | Descriere | Funcție |
|------------|-----------|---------|
| [ESP32 Development Board](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) | Microcontroler | Procesează datele senzorului și controlează releul |
| [Senzor Umiditate Sol](https://electronicmarket.ro/product/soil-moisture-detection-module) | Senzor | Detectează nivelul de umiditate |
| [Modul Releu 5V 1 Canal](https://electronicmarket.ro/modul-releu-5v-1-canal) | Releu | Controlează pompa de apă |
| [Breadboard 400 puncte](https://electronicmarket.ro/product/400-puncte-fara-lipire-breadboard) | Breadboard | Prototipare fără lipire |
| [Jumper Wires Dupont](https://electronicmarket.ro/product/cabluri-jumper-de-20-cm-cu-40-de-pini-de-la-tata-la-tata) | Cabluri | Conectare componente |

---

## 🛠️ Instrucțiuni de Asamblare

### Conexiuni Pin

**ESP32**
- GND → GND breadboard
- VIN → +5V / USB alimentare

**Senzor umiditate sol**
- VCC → +5V
- GND → GND
- AO → GPIO 34

**Releu**
- VCC → +5V
- GND → GND
- IN → GPIO 27

---

## 💻 Cod ESP32

```cpp
#include <WiFi.h>

#define SOIL_SENSOR_PIN 34
#define RELAY_PIN 27

void setup() {
  Serial.begin(115200);

  pinMode(SOIL_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  WiFi.begin("SSID", "PASSWORD");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
}

void loop() {
  int soilMoistureValue = analogRead(SOIL_SENSOR_PIN);

  Serial.println(soilMoistureValue);

  if (soilMoistureValue < 500) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(2000);
}
