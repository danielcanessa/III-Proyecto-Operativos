#include <Wire.h>

int slaveId = 1;
void setup(){
    Serial.begin(9600) ;
    while(!Serial);
    // Run as I2C Master
    Wire.begin();
}


char cadena[24];
byte contador = 0;

void loop() {
  contador = 0;
  if(Serial.available()){ // Si hay datos disponibles  para leer.
   memset(cadena,0,sizeof(cadena));
   
  while(Serial.available()){
    delay(2);
    cadena[contador]= Serial.read(); // los almacena en un arreglo de char
    contador++;
  } 
 
 
  Wire.beginTransmission(slaveId);
  Wire.write(contador);
  Wire.endTransmission();
  
  contador = 0;
  
  }
}



