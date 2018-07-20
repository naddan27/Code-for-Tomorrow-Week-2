//initializing and declaring led rows
int cLength = 16;
int lLength = 4;
int column[] = {A4, 11, 12, 13, A5, 8, 9, 10, 3, 6, 5, 7, 2, 1, 0, 4};
//initializing and declaring led layers
int layer[] = {A0, A1, A2, A3};

int activatedColumnIndex = 0;
int activatedLayerIndex = 0;
int time = 1;

void setup() {
  // put your setup code here, to run once:
  //setting rows to ouput
  for (int i = 0; i < 16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting layers to output
  for (int i = 0; i < 4; i++)
  {
    pinMode(layer[i], OUTPUT);
    digitalWrite(layer[i], OUTPUT);
  }
//    Serial.begin(9600);
//    Serial.println("flush");

}

void loop() {
  for (int i = 0; i < 2; i++){
    expandingBox();
  }
  for (int i = 0; i < 3; i++){
    iLoveYou();
  }
  for (int i = 0; i < 3; i++){
    inOut();
  }
  for (int i = 0; i < 20; i++){
    scattered();
  }
}

void expandingBox() {
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
      lightOne(column, layer);
      delayMicroseconds(300);
    }
  }
}

void lightOne(int columnI, int layerI) {
  digitalWrite(layer[activatedLayerIndex], HIGH);
  digitalWrite(column[activatedColumnIndex], LOW);
  activatedLayerIndex = layerI;
  activatedColumnIndex = columnI;
  digitalWrite(column[activatedColumnIndex], HIGH);
  digitalWrite(layer[activatedLayerIndex], LOW);
}

void lightAll() {
  int all[][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  for (int i = 0; i < 4; i++) {
    lightSheet(i, all);
    delayMicroseconds(500);
  }
}

void oneByOne() {
  for (int z = 0; z < 4; z++) {
    activateLayer(z);
    for (int x = 0; x < 16; x++) {
      activateColumn(x);
      delay(time);
    }
  }
}

void slowOneByOne() {
  time = 250;
  oneByOne();
}

void fastOneByOne() {
  time = 100;
  oneByOne();
}

void scattered() {
  time = 1;
  oneByOne();
}

void lightLayer(int a) {
  time = 1;
  activateLayer(a);
  for (int i = 0; i < 16; i++) {
    activateColumn(i);
    delay(time);
  }
}

void lightColumn(int a) {
  time = 1;
  activateColumn(a);
  for (int i = 0; i < 4; i++) {
    activateLayer(i);
    delay(time);
  }
}



void iLoveYou() {
  int hold = 20;
  for (int k = 0; k < hold; k++) {
    for (int j = 0; j < 10; j++) {
      for (int i = 0; i < 4; i++) {
        letterI(i);
      }
    }
  }

  for (int k = 0; k < hold; k++) {
    for (int j = 0; j < 10; j++) {
      for (int i = 0; i < 4; i++) {
        heart(i);
      }
    }
  }

  for (int k = 0; k < hold; k++) {
    for (int j = 0; j < 10; j++) {
      for (int i = 0; i < 4; i++) {
        letterU(i);
      }
    }
  }
}

void letterI(int sheet) {
  //[layer][column]
  int activated[][4] = {{1, 1, 1, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 1}};
  lightSheet(sheet, activated);
}

void heart(int sheet) {
  //[layer][column]
  int activated[][4] = {{0, 0, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 0, 1}};
  lightSheet(sheet, activated);
}

void letterU(int sheet) {
  int activated[][4] = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}};
  lightSheet(sheet, activated);
}

void lightSheet(int sheet, int activated[][4]) {
  int adjust = 4 * sheet;
  for (int i = 0; i < 4; i++) {
    activateLayer(3-i);
    for (int j = 0; j < 4; j++) {
      if (activated[i][j] == 1)
        activateColumn(j + adjust);
      delayMicroseconds(100);
    }
    turnColumnsOff();
  }
}

void activateLayer(int a) {
  digitalWrite(layer[activatedLayerIndex], HIGH);
  activatedLayerIndex = a;
  digitalWrite(layer[activatedLayerIndex], LOW);
}

void activateColumn(int a) {
  digitalWrite(column[activatedColumnIndex], LOW);
  activatedColumnIndex = a;
  digitalWrite(column[activatedColumnIndex], HIGH);
}

void turnColumnsOff() {
  digitalWrite(column[activatedColumnIndex], LOW);
}

void inOut() {
  //in
  for (int i = 0; i < 100; i++) {
    int in[][4] = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    lightSheet(1, in);
    delayMicroseconds(100);
    lightSheet(2, in);
  }

  //out
  for (int i = 0; i < 50; i++) {
    int out0[][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    lightSheet(0, out0);
    delayMicroseconds(100);

    int out1[][4] = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}};
    lightSheet(1, out1);
    delayMicroseconds(100);

    int out2[][4] = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}};
    lightSheet(2, out2);
    delayMicroseconds(100);

    int out3[][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    lightSheet(3, out3);
    delayMicroseconds(100);
  }

}

