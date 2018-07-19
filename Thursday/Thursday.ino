String letters[] = {"a", "b", "c", "d", "e", "f", "g"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 6; i >= 0; i++){
    Serial.println(letters[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
