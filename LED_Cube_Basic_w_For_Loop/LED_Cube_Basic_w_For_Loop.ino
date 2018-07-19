int columns[] = {A4, 11, 12, 13, A5, 8, 9, 10, 3, 6, 5, 7, 2, 1, 0, 4};
int layers[] = {A0, A1, A2, A3};
void setup() {
  setDefaultSettings();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(columns[3], HIGH);
  digitalWrite(layers[0], LOW);
}

void setDefaultSettings(){
  //Declaring all of the columns as OUTPUT pins
  for (int i = 0; i < 16; i++){
    pinMode(columns[i], OUTPUT);
    digitalWrite(columns[i], LOW);
  }
  //Declaring all of the layers as OUTPUT pins
  for (int i = 0; i <4 ; i++){
    pinMode(layers[i], OUTPUT);
    digitalWrite(layers[i], HIGH);
  }
}

