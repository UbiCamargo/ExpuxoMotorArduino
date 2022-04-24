//Printar no serial o valor do peso aplicado

#include "HX711.h"

HX711 balanca;

float sck = 2, dt = 3, calibra 130000.00; 
float peso, newton;

void setup(){
  Serial.begin(9600): 
  balanca.begin(dt, sck);
  balanca.set_scale(calibra);
  balanca.tare();
  long zero_factor = balanca.read_average();
}

void loop(){
  peso = balanca.get_units(), 10;
  Serial.println(peso);
  delay(500); 
}