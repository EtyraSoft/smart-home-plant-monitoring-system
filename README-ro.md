

![Project Image](https://res.cloudinary.com/dhmxvivgg/image/upload/v1778973726/etyra_seo/projects/project_14fdad61-d4cf-4275-b856-3ca02f4ba6c9.jpg)

[English](README.md) | [Romanian](README-ro.md)

---

```markdown
# 🌿 Sistem de Monitorizare a Plantelor pentru Casă Inteligentă

## 🚀 Obiectivele Proiectului
Obiectivul acestui proiect este dezvoltarea unui sistem de monitorizare a plantelor pentru casă inteligentă care utilizează un [Senzor de Umiditate a Solului [RO Market]](https://electronicmarket.ro/product/soil-moisture-detection-module) și o [Placă de Dezvoltare ESP32 [RO Market]](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) pentru a monitoriza nivelurile de umiditate ale solului. Sistemul va trimite notificări către un smartphone atunci când nivelul de umiditate scade sub un prag predefinit, indicând că planta are nevoie de apă.

---

## 💡 Teorie de Fundal
Senzorii de umiditate a solului funcționează prin măsurarea conținutului volumetric de apă din sol. Senzorul emite o tensiune corespunzătoare nivelului de umiditate, pe care [Placa de Dezvoltare ESP32 [RO Market]](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) o poate procesa. [Modulul Releu 5V cu 1 Canal [RO Market]](https://electronicmarket.ro/modul-releu-5v-1-canal) este utilizat pentru a controla o pompă de apă externă sau un sistem de alarmă.

### Concepte Cheie
- **Atenuarea Semnalului**: Reducerea puterii semnalului care poate apărea din cauza factorilor de mediu ce afectează citirile senzorului.
- **IoT (Internetul Lucrurilor)**: Acest proiect se încadrează în IoT, deoarece implică microcontrolere conectate în rețea pentru a gestiona datele și alertele.

---

## 🔧 Lista de Materiale
| Componentă | Descriere | Funcție |
|------------|-----------|---------|
| [Placă de Dezvoltare ESP32 [RO Market]](https://electronicmarket.ro/esp32-wroom-32-development-board-38-pins) | Microcontroler | Procesează datele senzorului și controlează releul |
| [Senzor de Umiditate a Solului [RO Market]](https://electronicmarket.ro/product/soil-moisture-detection-module) | Senzor | Detectează nivelurile de umiditate din sol |
| [Modul Releu 5V cu 1 Canal [RO Market]](https://electronicmarket.ro/modul-releu-5v-1-canal) | Releu | Controlează dispozitive externe precum pompe de apă |
| [Breadboard cu 400 de Puncte (Jumătate de Dimensiune) [RO Market]](https://electronicmarket.ro/product/400-puncte-fara-lipire-breadboard) | Breadboard | Oferă o platformă fără lipire pentru asamblarea circuitului |
| [Cabluri Jumper Dupont (Tată-la-Tată) [RO Market]](https://electronicmarket.ro/product/cabluri-jumper-de-20-cm-cu-40-de-pini-de-la-tata-la-tata) | Cabluri de Conectare | Conectează componentele pe breadboard |

---

## 🛠️ Instrucțiuni de Asamblare

### Conexiuni Pin
Conectați componentele astfel:

- **Placă de Dezvoltare ESP32**
  - `GND` -> Șina comună de masă pe breadboard
  - `Vin` -> Șina pozitivă pe breadboard (alimentată prin USB)
  
- **Senzor de Umiditate a Solului**
  - `VCC` -> Șina pozitivă
  - `GND` -> Șina de masă
  - `Signal` -> GPIO 34 pe ESP32

- **Modul Releu 5V cu 1 Canal**
  - `VCC` -> Șina pozitivă
  - `GND` -> Șina de masă
  - `IN` -> GPIO 27 pe ESP32

### Descrierea Diagramei de Cablare
ESP32 servește ca unitate centrală de procesare. Senzorul de umiditate a solului se conectează la GPIO 34, în timp ce modulul releu este conectat la GPIO 27. Releul poate controla dispozitive precum pompe de apă, declanșate când umiditatea solului scade sub un prag setat.

---

## 💻 Explicația Codului

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

  if (soilMoistureValue < 500) { // Ajustați pragul după nevoie
    digitalWrite(RELAY_PIN, HIGH); // Activează releul
    Serial.println("Relay Activated");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Dezactivează releul
    Serial.println("Relay Deactivated");
  }
  delay(2000);
}
```

### Exemplu de Ieșire Serială:
```
Connecting to WiFi...
Connected to WiFi
Soil Moisture Value: 300
Relay Activated
Soil Moisture Value: 700
Relay Deactivated
```

---

## ⚠️ Depanare

1. **Probleme de Conexiune WiFi**:
   - Asigurați-vă că SSID-ul și parola sunt corecte.
   - Verificați setările routerului sau obstacolele care cauzează atenuarea semnalului.

2. **Defecțiuni ale Senzorului**:
   - Verificați conexiunile pentru a vă asigura că nu există fire slăbite.
   - Verificați funcționalitatea senzorului testând cu un multimetru.

3. **Modulul Releu Nu Se Activează**:
   - Asigurați-vă că modulul releu este alimentat corect.
   - Verificați configurațiile pinului GPIO în cod.

---

## 🔍 Ghid de Debugging
- **Monitor Serial**: Utilizați pentru depanare în timp real. Imprimați valorile senzorului și starea releului.
- **Indicatoare LED**: Conectați un LED pentru a arăta starea releului pentru feedback vizual rapid.
- **Testare cu Multimetru**: Testați nivelurile de tensiune în puncte cheie pentru a verifica funcționarea componentelor.

---

## 🌟 Idei de Îmbunătățire
1. **Adăugați Senzori de Umiditate și Temperatură**: Integrați senzori de mediu suplimentari pentru a oferi un sistem de îngrijire a plantelor mai cuprinzător.
2. **Automatizați Udarea**: Încorporați o valvă solenoidă și o pompă de apă pentru a automatiza procesul de udare pe baza datelor senzorului.
3. **Integrare cu Aplicația Mobilă**: Dezvoltați o aplicație mobilă pentru a primi notificări și a controla sistemul de la distanță.

---

```
