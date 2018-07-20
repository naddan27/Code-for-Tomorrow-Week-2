int columns[] = {A4, 11, 12, 13, A5, 8, 9, 10, 3, 6, 5, 7, 2, 1, 0, 4};
int layers[] = {A0, A1, A2, A3};
int activatedColumn = 0;
int activatedLayer = 0;

void setup() {
  setDefaultSettings();
}


void loop() {
  // put your main code here, to run repeatedly:
  expandingBox();
}



String removeString(String on, int delayC, int repeat) {
  for (int i = 0; i < repeat; i++) {
    on = on.substring(4, on.length());
    lightArray(on, delayC);
  }
  return on;
}

String addString(String on, int hold, String add) {
  on += add;
  lightArray(on, hold);
  return on;
}

void lightArray(String on, int hold) {
  for (int i = 0; i < hold; i += on.length()) {
    for (int i = 0; i < on.length(); i += 4) {
      //the number is going to be xyz
      int x = on.substring(i, i + 1).toInt();

      //Find y
      int y = on.substring(i + 1, i + 2).toInt();

      //Find z
      int z = on.substring(i + 2, i + 3).toInt();

      x = x - 1;
      y = y - 1;
      z = z - 1;

      int column = x + (y * 4);
      int layer = z;
      turnLEDOn(column, layer);
      delayMicroseconds(300);
    }
  }
}

void setDefaultSettings() {
  //Declaring all of the columns as OUTPUT pins
  for (int i = 0; i < 16; i++) {
    pinMode(columns[i], OUTPUT);
    digitalWrite(columns[i], LOW);
  }
  //Declaring all of the layers as OUTPUT pins
  for (int i = 0; i < 4 ; i++) {
    pinMode(layers[i], OUTPUT);
    digitalWrite(layers[i], HIGH);
  }
}

void turnLEDOn(int column, int layer) {
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
