#include <Keypad.h>

int d = 100; // Delay time
int counter = 0, _counter = 2; // Counter
int sw_state = 0; // Default switch status
int ON = 1, OFF = 0; // Cathode SSD
//int ON = 0, OFF = 1; // Anode SSD
unsigned long prevtime = 0;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

//keymap
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; // Keypad Rows assign to pin
byte colPins[COLS] = {4, 3, 2}; // Keypad Columns assign to pin

//Keypad instantiation
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  for(int i = 2;i<=13;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
}

void loop() {
  //getting the value of the key being pressed
  char keypress = myKeypad.getKey(); 

  //displaying the value of keypad pressed to SSD
  switch(keypress){
    case '0': zero(); break;
    case '1': one(); break;
    case '2': two(); break;
    case '3': three(); break;
    case '4': four(); break;
    case '5': five(); break;
    case '6': six(); break;
    case '7': seven(); break;
    case '8': eight(); break;
    case '9': nine(); break;
  }

  if(sw_state == HIGH){
    up();
  }else{
    down();
  }

}
void up(){
  zero();
  one();
  two();
  three();
  four();
  five();
  six();
  seven();
  eight();
  nine();
}
void down(){
  nine();
  eight();
  seven();
  six();
  five();
  four();
  three();
  two();
  one();
  zero();
}
void zero(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, HIGH);//SEGMENT D
  digitalWrite(13, HIGH);//SEGMENT E
  digitalWrite(A0, HIGH);//SEGMENT F
  digitalWrite(A1, LOW);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void one(){
  digitalWrite(9, LOW);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, LOW);//SEGMENT D
  digitalWrite(13, LOW);//SEGMENT E
  digitalWrite(A0, LOW);//SEGMENT F
  digitalWrite(A1, LOW);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void two(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, LOW);//SEGMENT C
  digitalWrite(12, HIGH);//SEGMENT D
  digitalWrite(13, HIGH);//SEGMENT E
  digitalWrite(A0, LOW);//SEGMENT F
  digitalWrite(A1, HIGH);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void three(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, HIGH);//SEGMENT D
  digitalWrite(13, LOW);//SEGMENT E
  digitalWrite(A0, LOW);//SEGMENT F
  digitalWrite(A1, HIGH);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void four(){
  digitalWrite(9, LOW);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, LOW);//SEGMENT D
  digitalWrite(13, LOW);//SEGMENT E
  digitalWrite(A0, HIGH);//SEGMENT F
  digitalWrite(A1, HIGH);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void five(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, LOW);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, HIGH);//SEGMENT D
  digitalWrite(13, LOW);//SEGMENT E
  digitalWrite(A0, HIGH);//SEGMENT F
  digitalWrite(A1, HIGH);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void six(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, LOW);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, HIGH);//SEGMENT D
  digitalWrite(13, HIGH);//SEGMENT E
  digitalWrite(A0, HIGH);//SEGMENT F
  digitalWrite(A1, HIGH);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void seven(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, LOW);//SEGMENT D
  digitalWrite(13, LOW);//SEGMENT E
  digitalWrite(A0, LOW);//SEGMENT F
  digitalWrite(A1, LOW);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void eight(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, HIGH);//SEGMENT D
  digitalWrite(13, HIGH);//SEGMENT E
  digitalWrite(A0, HIGH);//SEGMENT F
  digitalWrite(A1, HIGH);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
void nine(){
  digitalWrite(9, HIGH);//SEGMENT A
  digitalWrite(10, HIGH);//SEGMENT B
  digitalWrite(11, HIGH);//SEGMENT C
  digitalWrite(12, HIGH);//SEGMENT D
  digitalWrite(13, LOW);//SEGMENT E
  digitalWrite(A0, HIGH);//SEGMENT F
  digitalWrite(A1, HIGH);//SEGMENT G
  digitalWrite(A2, LOW);//DP
  delay(1000);
}
