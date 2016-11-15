/*Initial Data */
String inputInstruction = "";         // a string to hold incoming data
int posIni = 0; //contains the initial position
int posFin = 0; //contains the final position
int nextMove = 0; //contains the next move
int sizeBoard = 0; //contains the size of the board
boolean instructionComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  // reserve 200 bytes for the inputString:
  inputInstruction.reserve(200);
}

void loop() {
    instructionComplete = false;
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
      digitalWrite(LED_BUILTIN, HIGH);
      posIni = inputInstruction[0] - '0';
      posFin = inputInstruction[2] - '0';
      nextMove = inputInstruction[4] - '0';
      Serial.write("L");
      inputInstruction = "";
    }
  if(inputInstruction.length() == 7){ 
      digitalWrite(LED_BUILTIN, HIGH);
      sizeBoard = inputInstruction[6] - '0';
      Serial.write("L");
      inputInstruction = "";
    }
  }
 
}

void writeString(String stringData) { // Used to serially push out a String with Serial.write()

  for (int i = 0; i < stringData.length(); i++)
  {
    Serial.write(stringData[i]);   // Push each char 1 by 1 on each loop pass
  }

}// end writeString
