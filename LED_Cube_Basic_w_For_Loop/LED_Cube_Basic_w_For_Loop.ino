int columns[] = {A4, 11, 12, 13, A5, 8, 9, 10, 3, 6, 5, 7, 2, 1, 0, 4};
int layers[] = {A0, A1, A2, A3};
int activatedColumn = 0;
int activatedLayer = 0;

void setup() {
  setDefaultSettings();
}

void loop() {
  // put your main code here, to run repeatedly:
  turnLEDOn(3, 2);

  
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

void turnLEDOn(int column, int layer){
  //code to turn the old led off
  digitalWrite(columns[activatedColumn], LOW);
  digitalWrite(layers[activatedLayer], HIGH);

  //code to redefine what is the activated column and layer
  activatedColumn = column;
  activatedLayer = layer;

  //turn what we want turned on, on
  digitalWrite(columns[activatedColumn], HIGH);
  digitalWrite(layers[activatedLayer], LOW);
}

