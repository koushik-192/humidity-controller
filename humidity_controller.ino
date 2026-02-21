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
