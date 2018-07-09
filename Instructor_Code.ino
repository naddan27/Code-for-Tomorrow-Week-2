//initializing and declaring led rows
int cLength = 16;
int lLength = 4;
int column[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, A0, A1};
//initializing and declaring led layers
int layer[] = {A2, A3, A4, A5};
int activatedColumnIndex = 0;
int time = 1;
int hold = 200;

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
  } 

  
}

void loop(){
  outCode();
}

void outCode(){
  /*        0   1   2  3
   *        4   5   6  7
   *        8   9   10 11
   *        12  13  14 15
   * 
   */
   int columnOrder[] = {0,1,2,3,7,11,15,14,13,12,8,4};
   int columnOrder2[] = {15,14,13,12,8,4,0,1,2,3,7,11};
   for (int i = 0; i < 12; i++){
      int repeatMax = 1000;
      for (int repeat = 0; repeat < repeatMax; repeat++){
        activateColumn(columnOrder[i]);
        delayMicroseconds(50);
        activateColumn(columnOrder2[i]);
        delayMicroseconds(50);
        if ((i % 2) == 1){
          turnColumnPins(6, 9);
        }
        else{
          turnColumnPins(5, 10);
        }
      }
   }
}

void inCode(){
  turnColumnPins(5, 10);
  turnColumnPins(6, 9);
}

void turnColumnPins(int pin1, int pin2){
    activateColumn(pin1);
    delayMicroseconds(50);
    activateColumn(pin2);
    delayMicroseconds(50);
}


//
//void lightRed(){
//  int repeatMax = 40000;
//  for (int repeat = 0; repeat < repeatMax; repeat
//}




//************************************
//Sam's Design Proposal
void activateSnake() {
  //light first row (top layer; columns 0, 4, 8,12)
  int rowOrder[] = {0, 1,2,3, 7,6,5,4, 8,9,10,11,15,14,13,12};

  for (int row = 0; row < 16; row++){
    turnRowOn(rowOrder[row]);
  }
}

void spiral(){
  int rowOrder[] = {0, 4, 8, 12, 13,14,15,11,7,3,2,1,5,9,10,6};

  for (int row = 0; row < 16; row++){
    turnRowOn(rowOrder[row]);
  }
}

void turnRowOn(int row) {
  activateLayer(3 - (row % 4));

  for (int repeat = 0; repeat < 1000; repeat++) {
    for (int columnAdjustment = 0; columnAdjustment < 4; columnAdjustment++) {
      activateColumn((columnAdjustment * 4) + (row / 4));
      delayMicroseconds(50);
    }
  }
}

//first row on
//columns: 0, 4, 8, 12
//layer: 3

//second row on
//columns: 0, 4, 8, 12
//layer: 2

//third row on
//colums: 0, 4, 8,12
//layer: 1

//fourth row on
//colums: 0, 4, 8,12
//layer: 0

//fifth row
//columns: 1, 5, 9, 13
//layer: 4






//***************************//////////////////////
//These methods are more complicated and can be called in the loop function for different arrangements

//Lights the specified LED
void lightOne(int column, int layer) {
  activateLayer(layer);
  activateColumn(column);
}

//Lights all of the LEDs
void lightAll() {
  int all[][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  for (int i = 0; i < 4; i++) {
    lightSheet(i, all);
    delayMicroseconds(1);
  }
}

//Lights a LED one by one
void oneByOne() {
  for (int z = 0; z < 4; z++) {
    activateLayer(z);
    for (int x = 0; x < 16; x++) {
      activateColumn(x);
      delay(100);
    }
  }
}

//Lights the specified layer
void lightLayer(int a) {
  time = 1;
  activateLayer(a);
  for (int i = 0; i < 16; i++) {
    activateColumn(i);
    delay(time);
  }
}

//Lights the specified column
void lightColumn(int a) {
  time = 1;
  activateColumn(a);
  for (int i = 0; i < 4; i++) {
    activateLayer(i);
    delay(time);
  }
}

//Lights all of the LEDs on the outside. Then lights all of the LEDs on the inside
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

void iLoveYou() {
  letterI();
  heart();
  letterU();
}

void heart() {
  //[layer][column]
  int activated[][4] = {{0, 0, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 0, 1}};
  produceLetter(activated);
}

void diagonaldiagonalflash() {
  diagonal();

}

void diagonal() {
  int activated1[][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 1}};
  produceLetter(activated1);

  int activated2[][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
  produceLetter(activated2);

  int activated3[][4] = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
  produceLetter(activated3);

  int activated4[][4] = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
  produceLetter(activated4);
}

//*******************************************
//This section will define all of the methods to produce letters
void produceLetter(int activated) {
  for (int k = 0; k < hold; k++) {
    for (int i = 0; i < 4; i++) {
      lightSheet(i, activated);
    }
  }
}

void letterU() {
  int activated[][4] = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}};
  produceLetter(activated);
}

void letterI() {
  //[layer][column]
  int activated[][4] = {{1, 1, 1, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 1}};
  produceLetter(activated);
}
//****************************************************
//Below are functions that provide foundational helper methods

/*This method activates a sheet based on a 2D array of on and offs
  For example: If I passed in [ [1,1,1,1] , [1,0,0,1], [1,0,1,0] , [1,0,0,0] ]
  The sheet if i look at it from the front will look like this: X is on, O is off

  LED sheet:
    X 0 0 0
    X O X X
    X O O X
    X X X X
*/
void lightSheet(int sheet, int activated[][4]) {
  int adjust = 4 * sheet;
  for (int i = 0; i < 4; i++) {
    activateLayer(i);
    for (int j = 0; j < 4; j++) {
      if (activated[i][j] == 1)
        activateColumn(j + adjust);
      delayMicroseconds(100);
    }
    turnColumnsOff();
  }
}

//This activates the layer associated with the passed number and deactivates everything else
void activateLayer(int a) {
  for (int i = 0; i < 4; i++) {
    if (i != a) {
      digitalWrite(layer[i], HIGH);
    }
    else
      digitalWrite(layer[i], LOW);
  }
}


//This deactivates the original activated column, sets the new activated column, and lights the new activated column
void activateColumn(int a) {
  digitalWrite(column[activatedColumnIndex], LOW);
  activatedColumnIndex = a;
  digitalWrite(column[activatedColumnIndex], HIGH);
}

//void activateColumn(int a){
//  for (int i = 0; i < 16; i++){
//    if (i == a){
//      digitalWrite(columns[i], HIGH);
//    }
//    else{
//      digitalWrite(columns[i], LOW);
//    }
//  }
//}

//Turns off the activated column
void turnColumnsOff() {
  digitalWrite(column[activatedColumnIndex], LOW);
}
