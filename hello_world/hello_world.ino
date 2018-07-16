int gChromeBook = 100;
void setup() {
  Serial.begin(9600);
  Serial.println("test");
  int localVariable = 1;
  Serial.println(gChromeBook);
  Serial.println(localVariable);
  Serial.println(localVariableNOTICE);
}

void loop() {
  int localVariableNOTICE = 2;
  Serial.println(gChromeBook);
  Serial.println(localVariableNOTICE);
}
