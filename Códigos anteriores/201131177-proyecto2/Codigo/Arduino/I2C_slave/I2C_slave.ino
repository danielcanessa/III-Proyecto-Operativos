#include <Wire.h>
#include <string.h>



char mensajeRobot[100];
int cantidadMovimiento = 0;
int cantidadCaracteres = 0;



boolean esperaNumero = false;


void setup() {
    Serial.begin( 9600 ) ;
    while ( !Serial ) ;
    // run as I2C Slave with id = 1
    int slaveId = 1 ;
    
    strcpy(mensajeRobot,"");
    Wire.begin( slaveId ) ;
    // setup callback function
    Wire.onReceive( onWireReceive ) ;
    
}



void loop() {
    // nothing to do
}


char* tipoAccion(int cantidadCaracteres){
  char accion[1];
  switch(cantidadCaracteres){
    case 1:
      strcpy(accion,"U");
      break;
    case 2:
      strcpy(accion,"D");
      break;
    case 3:
      strcpy(accion,"R");
      break;
    case 4:
      strcpy(accion,"L");
      break;
    case 5:
      strcpy(accion,"P");
      break;
    case 6:
      strcpy(accion,"O");
      break;
    case 7:
      strcpy(accion,"C");
      break;
    case 8:
      strcpy(accion,"*");
      cantidadMovimiento++;
      break;
    case 9:
      strcpy(accion,"&");
      break;
    case 10:
      strcpy(accion,"X");
      break;
    case 11:
      strcpy(accion,"Y");
      break;  
    case 12:
      strcpy(accion,"Z");
      break;
    case 13:
      strcpy(accion,"M");
      break;
  }
  return accion;
}

void onWireReceive( int howMany ) {
    cantidadCaracteres = 0;
  
 
    
    if(Wire.available()){ // Si hay datos disponibles  para leer.
        while(Wire.available()) {
            delay(2);
            cantidadCaracteres = Wire.read();
            
        }

         //logica tratar mensajes
        if(esperaNumero != true){
         //verifa accion
         
          strcat(mensajeRobot,tipoAccion(cantidadCaracteres));
          //Serial.println(mensajeRobot);
           
          if((cantidadCaracteres <= 4 || cantidadCaracteres > 9) && cantidadCaracteres != 13 ){ //significa que es un movimiento
             esperaNumero = true;
            cantidadCaracteres = 0;
           
          }
          
          if(cantidadMovimiento==4){
            //Serial.println(" ");
            //Serial.println("Lenght: ");
            Serial.println(mensajeRobot);
            delay(1500);
            Serial.println("");
            cantidadMovimiento = 0;
            strcpy(mensajeRobot,"");
          }
      
          
        }
        else{
          //guardar numero de movimientos
          char str[4];
          
          sprintf(str, "%d", cantidadCaracteres);
          strcat(mensajeRobot,str); 
          //Serial.println(mensajeRobot);
          esperaNumero = false;      
        }
        
       
     
    }
}

