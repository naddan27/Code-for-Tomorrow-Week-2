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

void expandingBox(){
  int delayC = 400;
  String on = "";

  on = addString(on, delayC, "111,");
  on = addString(on, delayC, "242,");
}

void expandingBox2() {
  int delayC = 400;
  String on = "";
  on = addString(on, delayC, "111,");
  on = addString(on, delayC, "121,112,211,");
  on = addString(on, delayC, "131,113,311,");
  on = addString(on, delayC, "141,114,411,");

  on = addString(on, delayC, "142,241,214,124,412,421,");
  on = addString(on, delayC, "143,341,314,134,413,431,");
  on = addString(on, delayC, "144,441,414,144,414,441,");

  on = addString(on, delayC, "442,244,424,");
  on = addString(on, delayC, "443,344,434,");
  on = addString(on, delayC, "444,");

  on = removeString(on, delayC, 1);
  on = removeString(on, delayC, 3);
  on = removeString(on, delayC, 3);
  on = removeString(on, delayC, 6);
  on = removeString(on, delayC, 6);
  on = removeString(on, delayC, 6);
  on = removeString(on, delayC, 3);
  on = removeString(on, delayC, 3);
  on = removeString(on, delayC, 3);
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
