int gChromeBook = 100;
void setup(){
 Serial.begin(9600);
 Serial.println("test");
 int localVariable = 1;
 Serial.println(gChromeBook);
 Serial.println(localVariable);
}

void loop(){
  int localVariable1 = 2;
  Serial.println(gChromeBook);
  Serial.println(localVariable1);
  delay(100000);
}
