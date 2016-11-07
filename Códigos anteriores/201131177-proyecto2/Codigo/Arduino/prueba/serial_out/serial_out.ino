

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {

  // print the results to the serial monitor:
  Serial.println("X26Y29Z23&L1U1C*R1D2C*R1C*U2C*"); //1893
  //Serial.println("X26Y29Z23&D1C*L1U2C*C*R1D1C*"); //8115
  
  //Serial.println("X26Y29Z18&L1U1P*R2M*D2M*L2O*"); //1893 ARRASTRANDO

  delay(1000);
}
