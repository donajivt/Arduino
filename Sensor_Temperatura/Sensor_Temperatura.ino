#include "DHT.h"
int PIN=12;
DHT dht(PIN, DHT22);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  double T=dht.readTemperature();
  double H=dht.readHumidity();
  Serial.print("Temperatura actual:");
  Serial.print(T);
  Serial.print("Humedad actual:");
  Serial.print(H);
  Serial.print("\n");
  delay(1000);
}
