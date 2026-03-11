#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define HEATER 7
#define COOLER 8

DHT dht(DHTPIN, DHTTYPE);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float upperLimit = 30.0;
float lowerLimit = 20.0;

void setup() {

  Serial.begin(9600);

  pinMode(HEATER, OUTPUT);
  pinMode(COOLER, OUTPUT);

  digitalWrite(HEATER, LOW);
  digitalWrite(COOLER, LOW);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {

  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Sensor error");
    return;
  }

  String mode = "NORMAL";

  if(temp > upperLimit) {

    digitalWrite(COOLER, HIGH);
    digitalWrite(HEATER, LOW);
    mode = "COOLING";

  }

  else if(temp < lowerLimit) {

    digitalWrite(HEATER, HIGH);
    digitalWrite(COOLER, LOW);
    mode = "HEATING";

  }

  else {

    digitalWrite(HEATER, LOW);
    digitalWrite(COOLER, LOW);
    mode = "STABLE";

  }

  display.clearDisplay();

  display.setCursor(0,10);
  display.setTextSize(2);
  display.print("Temp:");
  display.print(temp);
  display.print("C");

  display.setCursor(0,40);
  display.setTextSize(1);
  display.print("Mode: ");
  display.print(mode);

  display.display();

  delay(2000);
}
