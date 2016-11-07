
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
    stringComplete = false;
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
    inputString += inChar;
 
    Serial.println(inputString);
    if(inputString.equals("Hola")){ 
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println(inputString);
    delay(1000);
    inputString = "";
   }
   digitalWrite(LED_BUILTIN, LOW);
  }

  
  
}
