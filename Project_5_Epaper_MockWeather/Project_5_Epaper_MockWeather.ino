#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <ArduinoJson.h>

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16);
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4);

const char* mockWeatherData = "{\"main\":{\"temp\":25,\"humidity\":50},\"weather\":[{\"description\":\"Clear\"}]}";

void setup()
{
  Serial.begin(115200);

  display.init(115200);
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
}

void loop()
{
  // Parse mock weather data
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, mockWeatherData);

  float temperature = doc["main"]["temp"].as<float>();
  int humidity = doc["main"]["humidity"].as<int>();
  String weatherDescription = doc["weather"][0]["description"].as<String>();

  // Display mock weather data on the e-Paper
  display.setFont(&FreeMonoBold12pt7b);
  display.setCursor(10, 50);
  display.println("Temperature: " + String(temperature) + " °C");
  display.println("Humidity: " + String(humidity) + "%");
  display.println("Weather: " + weatherDescription);
  display.update();

  delay(60000); // Update mock weather data every 60 seconds
}