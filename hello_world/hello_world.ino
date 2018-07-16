void setup() {
  Serial.begin(9600);
  int truthCondition = 3;
  if (truthCondition == 7){
    Serial.println("Woohoo");
  }
  else if (truthCondition == 3){
    Serial.println("yahhhhh");
  }
  else{
    Serial.println("letsgetit");
  }
  
}

void loop() {
}
