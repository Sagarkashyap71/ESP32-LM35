/*
  TemperatureSensor

  Read the LM35 connected to an ESP with the ESP_LM35 library.

  The circuit:
  * LM35 signal pin to GPIO36
  * LM35 +5V pin to 3.3V
  * LM35 GND pin to GND

  Created 12 march 2019
  By ArnyminerZ

  https://github.com/CMakerA/ESP_LM35

*/

#define BLYNK_TEMPLATE_ID "TMPL3mr6Bkq8v"
#define BLYNK_TEMPLATE_NAME "ESP32"
#define BLYNK_AUTH_TOKEN "-xaPtqkuf6bgKSjQWxNj7JLVgrMews4i"

#include <ESP_LM35.h>
#include <Wifi.h>
#include <blynkSi mpleEsp32.h>

ESP_LM35 temp(36);
float t;
char ssid[] = "Embsoft";
char pass[] = "eprd@0172"

BLYNK_WRITE(V1);
{int value = param.asINT();
digitalWrite(13, value);
}

BLYNK_WRITE(V2){
  int value - params.asINT();
  digitalWrite(17, value);
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(17, OUTPUT);
  Wifi.begin(ssid, pass);

while(Wifi.status() != WL_CONNECTED){
  digitakWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
  Serial.println("Connecting to wifi...");
  serial.println(ssid);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  delay(1000);
}

}

void loop() {
  Blynk.run();
  t = temp.tempC();
  Serial.print("Temperature-C:");
  Serial.println(t);
  Blynk.virtualWrite(V0, t);
  delay(1000);  



  // Serial.print("Temperature: ");
  // Serial.print(temp.tempC());
  // Serial.print("ºC ");
  // Serial.print(temp.tempF());
  // Serial.print("ºF ");
  // Serial.print(temp.tempK());
  // Serial.println("K ");

  // delay(1000);
}