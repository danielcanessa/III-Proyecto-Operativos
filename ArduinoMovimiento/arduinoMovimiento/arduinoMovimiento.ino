
#include <Servo.h>
Servo servoY; 
Servo servoX;

/*Initial Data */
int isMove;
int board;
String inputInstruction = "";         // a string to hold incoming data
int posIni = 0; //contains the initial position
int posFin = 0; //contains the final position
int nextMove = 0; //contains the next move
int sizeBoard = 0; //contains the size of the board
boolean instructionComplete = false;  // whether the string is complete


void setup()
{
   Serial.begin(9600);
   //servoY.attach(10);
   //servoX.attach(11); 
   isMove=1;
   board=1;
   inputInstruction.reserve(200);
}


//Servo y, 1cm=10
//180 arriba
//45 abajo

//Servo x, 1cm=6
//180 derecha
//45 izquierda

void moveX(int posIni, int posFin, int separation)
{
  servoY.detach();
  servoX.attach(11); 
  if(posFin>posIni)
  {
    int cantMov=(posFin-posIni)*separation;
    for (int i=0; i < cantMov; i++)
    {
      servoX.write(180); 
      delay(1000);
    }    
  }
  else if(posFin<posIni)
  {
    int cantMov=(posIni-posFin)*separation;
    for (int i=0; i < cantMov; i++)
    {
      servoX.write(45); 
      delay(1000);
    }       
  }  
  servoY.detach();
  servoX.detach();  
}

void moveY(int posIni, int posFin, int separation)
{
  servoX.detach();
  servoY.attach(10); 
  if(posFin>posIni)
  {
    int cantMov=(posFin-posIni)*separation;
    for (int i=0; i < cantMov; i++)
    {
      servoY.write(45); 
      delay(1000);
    }    
  }
  else if(posFin<posIni)
  {
    int cantMov=(posIni-posFin)*separation;
    for (int i=0; i < cantMov; i++)
    {
      servoY.write(180); 
      delay(1000);
    }       
  }  
  servoY.detach();
  servoX.detach();  
}


int castNumberY(int number)
{
   if(number>=0 && number<=3)
    {
       return 0;
    }
    else if(number>=4 && number<=7)
    {
       return 1;
    }
    else
    {
       return 2;
    }  
}

int castNumberX(int number)
{
  if(number==4 || number==8)
  {
    return 0;    
  }
  else if(number==5 || number==9)
  {
    return 1;    
  }
  else if(number==6)
  {
    return 2;    
  }
  else if(number==7)
  {
    return 3;    
  }   
  else
  {
    return number;
  }  
}

void move(int posIni, int posFin)
{
  if(isMove && board==1)
  {
    moveX(castNumberX(posIni),castNumberX(posFin),6);
    moveY(castNumberY(posIni), castNumberY(posFin), 10);  
    isMove=0;  
  }
     
}

//int itera=1;
void loop()
{
//  if(itera)
//  {  
//    //362960
//    move(0,3);
//    delay(1000);
//    isMove=1;
//    move(3,6);
//    delay(1000);
//    isMove=1;
//    move(6,2);
//    delay(1000);
//    isMove=1;
//    move(2,9);
//    delay(1000);
//    isMove=1;
//    move(9,6);
//    delay(1000);
//    isMove=1;
//    move(6,0);
//    delay(1000);
//    itera=0;
//}
//   delay(1000); 
}

/*
 * This method is going to run simultaneously with the loop()
 */
void serialEventRun(void) {
  serialEvent();
}

/*
 * This method is going to see if there is new data in the USB Port
 * 
 */
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputInstruction += inChar;
    instructionComplete = false;
    
    if(inputInstruction.length() == 5 && inputInstruction != "Board"){ 
      posIni = inputInstruction[0] - '0';
      posFin = inputInstruction[2] - '0';
      nextMove = inputInstruction[4] - '0';
      isMove=1;
      move(posIni,posFin);
    //  isMove=1;
      Serial.write("L");
      inputInstruction = "";
    }
  if(inputInstruction.length() == 7){ 
      sizeBoard = inputInstruction[6] - '0';
      board = sizeBoard;
      Serial.write("L");
      inputInstruction = "";
    }
  }
 
}
