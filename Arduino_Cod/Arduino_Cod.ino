#include "EmonLib.h"

EnergyMonitor emon1;
double totalKWh = 0;
unsigned long lastTime;
double pretKWh = 0.80;

void setup() {
  Serial.begin(9600);
  emon1.current(1, 100); 
  lastTime = millis();
  Serial.println("Sistem de monitorizare energie - ACTIV");
}

void loop() {
  double Irms = emon1.calcIrms(1480);
  

  if (Irms < 0.40) Irms = 0; 

  double putereW = Irms * 230.0;
  
  unsigned long currentTime = millis();
  double timpOre = (currentTime - lastTime) / 3600000.0;
  totalKWh += (putereW / 1000.0) * timpOre;
  lastTime = currentTime;

  Serial.print("Putere: ");
  Serial.print(putereW);
  Serial.print(" W | ");
  
  Serial.print("Energie: ");
  Serial.print(totalKWh, 5); 
  Serial.print(" kWh | ");
  
  Serial.print("Cost: ");
  Serial.print(totalKWh * pretKWh, 4);
  Serial.println(" RON");
  
  delay(2000); 
}