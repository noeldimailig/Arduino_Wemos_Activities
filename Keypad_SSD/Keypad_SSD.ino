#include <Keypad.h>

//int d = 800;

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
//  for(int i = 2;i<=9;i++){
//    pinMode(i, OUTPUT);
//  }
  Serial.begin(9600);
}

void loop() {
  char pindotKey = customKeypad.getKey();
  
  if (pindotKey != NO_KEY){
    Serial.println(pindotKey);
  }
  
//  zero();
//  one();
//  two();
//  three();
//  four();
//  five();
//  six();
//  seven();
//  eight();
//  nine();
}

//void zero(){
//  for(int i = 2;i <= 9;i++){
//    if(i==8){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void one(){
//  for(int i = 2;i <= 9;i++){
//    if(i==3 || i==4 || i==9){
//      digitalWrite(i, HIGH);
//    }else{
//      digitalWrite(i, LOW);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void two(){
//  for(int i = 2;i <= 9;i++){
//    if(i==4 || i==7){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void three(){
//  for(int i = 2;i <= 9;i++){
//    if(i==6 || i==7){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void four(){
//  for(int i = 2;i <= 9;i++){
//    if(i==2 || i==5 || i==6){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void five(){
//  for(int i = 2;i <= 9;i++){
//    if(i==3 || i==6){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void six(){
//  for(int i = 2;i <= 9;i++){
//    if(i==3){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void seven(){
//  for(int i = 2;i <= 9;i++){
//    if(i==5 || i==6 || i==7 || i==8){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void eight(){
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, HIGH);
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
//void nine(){
//  for(int i = 2;i <= 9;i++){
//    if(i==6){
//      digitalWrite(i, LOW);
//    }else{
//      digitalWrite(i, HIGH);
//    }
//  }
//  delay(d);
//  for(int i = 2;i <= 9;i++){
//    digitalWrite(i, LOW);
//  }
//}
