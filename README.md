# Humidity Controller Mini Project (Arduino Based)
## 📌 Project Overview
This project is an Automatic Humidity Controller designed using Arduino Uno.
It monitors humidity using a DHT11 sensor and automatically controls a mist maker (humidifier) using a relay module.

### The system is useful for:
- 🍄 Mushroom cultivation
- 🌱 Greenhouses
- 🏠 Indoor humidity control
- 🧪 Laboratory environments

## Objective
To maintain humidity automatically by:
- Reading real-time humidity values
- Comparing with preset threshold
- Switching ON/OFF humidifier accordingly
- Displaying values on LCD

## 🛠 Components Used
| Component                | Quantity    |
| ------------------------ | ----------- |
| Arduino Uno              | 1           |
| DHT11 Humidity Sensor    | 1           |
| 5V Relay Module          | 1           |
| 16x2 I2C LCD Display     | 1           |
| 5V Ultrasonic Mist Maker | 1           |
| Jumper Wires             | As required |
| Power Supply             | 1           |

## Working Principle
- The DHT11 sensor reads humidity and temperature.
- Arduino compares humidity with threshold (70%).
- If humidity drops below threshold → Relay turns ON mist maker.
- If humidity exceeds threshold → Relay turns OFF mist maker.
- LCD displays real-time temperature & humidity.

## Circuit Connections
DHT11
- VCC → 5V
- GND → GND
- DATA → Pin 2

Relay
- IN → Pin 7
- VCC → 5V
- GND → GND

I2C LCD
- SDA → A4
- SCL → A5
- VCC → 5V
- GND → GND

## Code
Upload the following code into Arduino UNO:
```
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// -------------------- DHT Setup --------------------
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// -------------------- Relay Setup --------------------
#define RELAY_PIN 7
int humidityThreshold = 70;   // Set desired humidity level

// -------------------- LCD Setup --------------------
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change to 0x3F if needed

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Humidity Control");
  delay(2000);
  lcd.clear();
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  // Display Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);  // Degree symbol
  lcd.print("C   ");

  // Display Humidity
  lcd.setCursor(0, 1);
  lcd.print("Hum : ");
  lcd.print(humidity, 1);
  lcd.print("%   ");

  // Control Mist Maker using Relay
  if (humidity < humidityThreshold) {
    digitalWrite(RELAY_PIN, HIGH);   // Turn ON humidifier
  } else {
    digitalWrite(RELAY_PIN, LOW);    // Turn OFF humidifier
  }

  delay(2000);
}
```
## Features
- ✔ Real-time humidity monitoring
- ✔ Automatic control system
- ✔ LCD display output
- ✔ Low cost
- ✔ Easy to build
- ✔ Suitable for agriculture projects

## 📈 Applications
- 🍄 Mushroom farming humidity control
- 🌾 Greenhouse automation
- 🧪 Laboratory humidity management
- 🏠 Smart home environment systems

## 🚀 Future Improvements
- Add WiFi (ESP8266) for IoT monitoring
- Mobile App Integration
- Data logging system
- Adjustable threshold using keypad
- Buzzer alert system

## 🏆 Author
Koushik Reddy
- Embedded systems & IOT Entusiast
