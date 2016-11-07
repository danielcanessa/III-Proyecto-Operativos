/*
  Serial Event example
 
 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
 clears it.
 
 A good test for this is to try it with a GPS receiver 
 that sends out NMEA 0183 sentences. 
 
 Created 9 May 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */

// include the library code:
//#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

 
// Control de movimiento lateral
int puertoIzquierdaLateral = 2;
int puertoDerechaLateral = 3;

// Control de movimiento horizontal
int puertoIzquierdaHorizontal = 4;
int puertoDerechaHorizontal = 5;

// Control de movimiento del lapiz
int puertoArribaLapiz = 6;
int puertoAbajoLapiz = 7;

// Arreglo encriptado de datos
char listaEncrypt[17];
// Si ya fue configurado
boolean configurado = false;
// Posicion actual
int posicionActual = 0;

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

//Posiciones inciales
int posiciones[3];
int puntoPosicion = 0;

// Posicion Actual
int XActual = 0;
int YActual = 0;
int ZActual = 0;

void setup() {

  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(50);
  
  // Asiganamos los siguientes puertos como salidas
  // Movimiento Lateral
  pinMode(puertoIzquierdaLateral, OUTPUT);
  pinMode(puertoDerechaLateral, OUTPUT);
  
  // Movimiento Horizontal
  pinMode(puertoIzquierdaHorizontal, OUTPUT);
  pinMode(puertoDerechaHorizontal, OUTPUT);
  
  // Movimiento del lapiz
  pinMode(puertoArribaLapiz, OUTPUT);
  pinMode(puertoAbajoLapiz, OUTPUT);
  
  //Mandamos a negativo a todos los valores
  // Movimiento Lateral
  digitalWrite(puertoIzquierdaLateral, LOW);
  digitalWrite(puertoDerechaLateral, LOW);
  
   // Movimiento Horizontal
  digitalWrite(puertoIzquierdaHorizontal, LOW);
  digitalWrite(puertoDerechaHorizontal, LOW);
  
  // Movimiento del lapiz
  digitalWrite(puertoArribaLapiz, LOW);
  digitalWrite(puertoAbajoLapiz, LOW);
  
  //Prueba
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
}

void loop() {

  // print the string when a newline arrives:
  if (stringComplete) {
    
    // Sacamos el movimiento relativo
    int movimientoX =  posiciones[0] - XActual;
    int movimientoY =  posiciones[1] - YActual;
    
    // Asignamos los valores nuevos de posicionActual
    XActual = movimientoX; 
    YActual = movimientoY;
    
    // Preguntamos si el movimiento es a la derecha o a la izquierda
    if( movimientoX > 0 ){
    
       // Nos movemos la derecha
      digitalWrite(puertoDerechaLateral, HIGH);
      delay(50*movimientoX);
      digitalWrite(puertoDerechaLateral, LOW);
    
    }else if ( movimientoX < 0 ){
    
      // Si no nos movemos a la izquierda
      digitalWrite(puertoIzquierdaLateral, HIGH);
      delay(-50*movimientoX);
      digitalWrite(puertoIzquierdaLateral, LOW);
      
    }
    
    // Preguntamos si nos movemos hacia la derecha o izquierda
    // En este caso en el eje Y
    if( movimientoY > 0 ){
    
      // Nos movemos a la derecha
      digitalWrite(puertoDerechaHorizontal, HIGH);
      delay(400*movimientoY);
      digitalWrite(puertoDerechaHorizontal, LOW);
    
    }else if ( movimientoY < 0 ){
    
      // Nos movemos a la izquierda
      digitalWrite(puertoIzquierdaHorizontal, HIGH);
      delay(-400*movimientoY);
      digitalWrite(puertoIzquierdaHorizontal, LOW);
      
    }
    
    // Preguntamos nuestra situacion en el eje Z
    if( posiciones[2] == 0 ){
    
      // Si el eje ya esta en uno signfinica que bajo, pero no subio.
      if( ZActual  != 1  ){
        
        digitalWrite(puertoAbajoLapiz, HIGH);
        delay(30);  
        digitalWrite(puertoAbajoLapiz, LOW);
        
      }
    
      // Subimos el lapiz
      digitalWrite(puertoArribaLapiz, HIGH);
      delay(100);  
      digitalWrite(puertoArribaLapiz, LOW);
      
     // Si es arrastre entonces solo bajamos le lapiz
    }else if ( posiciones[2] == 1 ){
    
      digitalWrite(puertoAbajoLapiz, HIGH);
      delay(30);  
      digitalWrite(puertoAbajoLapiz, LOW);
    
    }
    
    // Actualizamos la posiciones
    ZActual = posiciones[2];
    
    // Encendemos un led para indicar la finalizacion del proceso
    digitalWrite(13, HIGH); 
    delay(1000);
    digitalWrite(13, LOW); 
    
    // limpiamos las banderas y el texto de entrada
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  
  // Avanzamos si el puerto serial esta dispobible
  while (Serial.available()) {
    
    // get the new byte:
    char inChar = (char)Serial.read(); 
    
    // Preguntar si esta configurado
    if(!configurado){
    
      // Ahora agregamos la posicionActual
      listaEncrypt[posicionActual] = inChar;
      
      //Sumamos la posicion actual
      posicionActual++;
      
      // Preguntamos si es 16
      if(posicionActual >= 17){
   
        // Pasamos a la configuración a true
        configurado = true;
        //Limpiamos la posición actual
        posicionActual = 0;
        
      }
  
    }// Si ya esta configurado
    else{
      
      if (inChar == listaEncrypt[posicionActual] ){
        
         // add it to the inputString:
         inputString += inChar;
         // Aumentamos el puntero
         posicionActual++;
    
      }else if(inChar == listaEncrypt[0]){
      
         // Posicion del arreglo y lo posicionamos con un offset de 2
         posiciones[puntoPosicion] = inputString.length() - 2;
         
         // El mensaje es igual a la primera letra
         inputString = String(inChar);
         // La posicion acutal es de 1
         posicionActual = 1;
         // Sumamos al punto de la posicion
         puntoPosicion++;
         
         // Si ya tenemos las 3 posiciones
         if(puntoPosicion == 3){
           
           //Si el string esta completo
           stringComplete = true;
           // Reiniciamos la posicion
           puntoPosicion = 0;
           // Limpiamos la posicion actual 
           posicionActual = 0;
           
         }
        
      }else{

         //lcd.clear();
         // Si no es un error
         //lcd.setCursor(0, 1);
         //Si es un error
         //lcd.print("Error");
         //Limpiamos las variables
         inputString = "";
         posicionActual = 0;
         puntoPosicion = 0;
         
        
      }
      
    }
  }
}
