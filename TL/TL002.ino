// Geração do gráfico de newton por segundo  

#include "HX711.h"

HX711 balanca;

float sck, dt, calibra; 
float peso, newton;

void setup(){
  Serial.begin(9600);
  sck = 2; 
  dt = 3; 
  calibra = 130000.00;
  balanca.begin(dt, sck);
  balanca.set_scale(calibra);
  balanca.tare();
  long zero_factor = balanca.read_average();
}

void loop(){
  peso = balanca.get_units(), 10;
  float Newton = peso * 9.81; 
  Serial.println(Newton);
  delay(250); 
}