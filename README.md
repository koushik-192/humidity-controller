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
