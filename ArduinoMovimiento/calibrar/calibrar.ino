#include <Servo.h>
Servo servoX; // Define our Servo
Servo servoY;

int incomingByte = 0; // almacena el dato serie

void setup()
{

   Serial.begin(9600);
}

void loop()
{
      // envía datos sólo si los recibe:
    if (Serial.available() > 0) {
      char inChar = (char)Serial.read();
        if( inChar == 'a'){
          servoX.attach(10);
          servoX.write(45);
        }
        else if( inChar == 'd'){
          servoX.attach(10);
          servoX.write(180);
        }
        else if( inChar == 'w'){
          servoY.attach(11);
          servoY.write(45);
        }
        else if( inChar == 's'){
          servoY.attach(11);
          servoY.write(180);
        }
        else if( inChar == 'x'){
          servoX.detach();
          servoY.detach();
        }
        
    }
  
}
