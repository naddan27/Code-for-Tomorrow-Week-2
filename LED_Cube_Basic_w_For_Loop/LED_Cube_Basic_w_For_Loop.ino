int columns[] = {A4, 11, 12, 13, A5, 8, 9, 10, 3, 6, 5, 7, 2, 1, 0, 4};
int layers[] = {A0, A1, A2, A3};
int activatedColumn = 0;
int activatedLayer = 0;

void setup() {
  setDefaultSettings();
}

void loop() {
  int repeat = 1000;
  for (int i = 0; i < repeat; i++) {
    innerBox();
  }
  for (int i = 0; i < repeat; i++) {
    outerBox();
  }
}

void interestingPattern() {
  int columnPatterns[] = {5, 6, 9, 10, 5, 6, 9, 10};
  int layerPatterns[] = {1, 1, 1, 1, 2, 2, 2, 2};

  for (int i = 0; i < 8; i++) {
    turnLEDOn(columnPatterns[i], layerPatterns[i]);
    delay(500);
  }
}

void innerBox() {
  int columnsPattern[] = {5, 6, 9, 10, 5, 6, 9, 10};
  int layersPattern[] = {1, 1, 1, 1, 2, 2, 2, 2};

  for (int i = 0; i < 8; i ++) {
    turnLEDOn(columnsPattern[i], layersPattern[i]);
    delayMicroseconds(100);
  }
}

void outerBox() {
  int columnsPattern[] = {0, 12, 3, 15, 0, 12, 3, 15};
  int layersPattern[] = {0, 0, 0, 0, 3, 3, 3, 3};

  for (int i = 0; i < 8; i ++) {
    turnLEDOn(columnsPattern[i], layersPattern[i]);
    delayMicroseconds(100);
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
