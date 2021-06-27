/*---------- Made by Noel M. Dimailig ----------*/

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

//keymap
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; // Pins assigned to keypad rows
byte colPins[COLS] = {4, 3, 2}; // Pins assigned to keypad columns

int Sw_State=0;
int interval=1000; // Time interval between changing of display
unsigned long prev_time=0; // Initial time value
int counter=0; // Counter initial value
int ON=1, OFF=0; // Cathode SSD
//int ON=0, OFF=1; // Anode SSD

// Keypad instantiation
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {

  // Setting pin 2  to 13 as OUTPUT
  for (int i=2; i<=13; i++){ 
    pinMode(i, OUTPUT);
  }

  // Using anlog pin as OUTPUT
  pinMode(A0, OUTPUT); // Segment F
  pinMode(A1, OUTPUT); // Segment G
  pinMode(A2, OUTPUT); // Segment DP
  pinMode(A3, INPUT); // Switch common
  
}

void loop() {
  
  //Getting the value of the key being pressed
  char keypress = myKeypad.getKey(); 

  //Displaying the value of keypad pressed to SSD
  Sw_State=digitalRead(A3);

  if(Time(interval)){
      if(Sw_State==HIGH){ // Display count up if Swicth is ON/HIGH
        SevenSegments(counter); // Call method to display the current value of counter
        counter++; // Increment counter value by 1
        if(counter>9)counter=0; // Check counter value if it exceeds 9 then set again to its initial value
      }else { // Display count up if Swicth is OFF/LOW
        SevenSegments(counter); // Call method to display the current value of counter
        counter--; // Decrement counter value by 1
        if(counter<0)counter=9; // Check counter value if it's lower than 0 then set again to its max value
      }
  }

  // Execute when a key in keypad is pressed
  if(keypress != NO_KEY){ //Check if a key is pressed
    if(keypress != '#' || keypress != '*') //Check if the key pressed is either * or #
      counter = Press_Value(keypress); // Change value of counter based on the pressed key
    Pressed(keypress); // Call the method to display the key that is pressed
  }
}

// Function to get the value of key that is pressed then output it
void Pressed(char keypress){ 

  // Switch case to display the specific key that is pressed from 0 - 9 inluding * as Dot and # as letter H
   switch(keypress) {
    case '0': 
      for(int x=0; x<=4; x++){ 
        digitalWrite(x+9, ON); digitalWrite(A0, ON); 
        digitalWrite(A1, OFF); digitalWrite(A2, ON);
      } break;
    case '1': 
      for(int x=0; x<=4; x++){
        if(x==1 || x==2) digitalWrite(x+9, ON); else digitalWrite(x+9, OFF);
        digitalWrite(A0, OFF); digitalWrite(A1, OFF); digitalWrite(A2, ON);
      } break;
    case '2': 
      for(int x=0; x<=4; x++){
        if(x==2) digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, OFF); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case '3': 
      for(int x=0; x<=4; x++){
        if(x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, OFF); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case '4': 
      for(int x=0; x<=4; x++){
        if(x==1 || x==2)digitalWrite(x+9, ON); else digitalWrite(x+9, OFF); 
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case '5': 
      for(int x=0; x<=4; x++){ 
        if(x==1 || x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case '6': 
      for(int x=0; x<=4; x++){ 
        if(x==1)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case '7': 
      for(int x=0; x<=4; x++){ 
        if(x==3 || x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, OFF); digitalWrite(A1, OFF); digitalWrite(A2, ON);
      } break;
    case '8': 
      for(int x=0; x<=4; x++){ 
        digitalWrite(x+9, ON); digitalWrite(A0, ON);
        digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case '9': 
      for(int x=0; x<=4; x++){
        if(x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case '*': 
      for(int x=0; x<=4; x++){ 
        digitalWrite(x+9, OFF); digitalWrite(A0, OFF); 
        digitalWrite(A1, OFF); digitalWrite(A2, ON);
      } break;
    case '#': 
      for(int x=0; x<=4; x++){
        if(x==0 || x==3)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON);
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, OFF);
      } break;
  }
}

// Funtion that display count numbers from 0 - 9 or 9 - 0 depending on the switch value
void SevenSegments(int count){

  switch(count) {
    case 0: 
      for(int x=0; x<=4; x++){
        digitalWrite(x+9, ON); digitalWrite(A0, ON);
        digitalWrite(A1, OFF); digitalWrite(A2, ON);
      } break;
    case 1: 
      for(int x=0; x<=4; x++){
        if(x==1 || x==2) digitalWrite(x+9, ON); else digitalWrite(x+9, OFF);
        digitalWrite(A0, OFF); digitalWrite(A1, OFF); digitalWrite(A2, ON);
      } break;
    case 2: 
      for(int x=0; x<=4; x++){ 
        if(x==2)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, OFF); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case 3: 
      for(int x=0; x<=4; x++){
        if(x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, OFF); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case 4: 
      for(int x=0; x<=4; x++){ 
        if(x==1 || x==2)digitalWrite(x+9, ON); else digitalWrite(x+9, OFF);
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case 5: 
      for(int x=0; x<=4; x++){
        if(x==1 || x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case 6: 
      for(int x=0; x<=4; x++){
        if(x==1)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case 7: 
      for(int x=0; x<=4; x++){
        if(x==3 || x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, OFF); digitalWrite(A1, OFF); digitalWrite(A2, ON);
      } break;
    case 8: 
      for(int x=0; x<=4; x++){
        digitalWrite(x+9, ON); digitalWrite(A0, ON); 
        digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
    case 9: 
      for(int x=0; x<=4; x++){
        if(x==4)digitalWrite(x+9, OFF); else digitalWrite(x+9, ON); 
        digitalWrite(A0, ON); digitalWrite(A1, ON); digitalWrite(A2, ON);
      } break;
  }
}

// Function that checks if the interval time is met before displaying the next counter value
bool Time(int interval){
  unsigned long cur_time = millis(); // Gets the current time the board is running using built in function millis()
  if((cur_time-prev_time)>=interval){ // Check if the difference between current time and previous time is greater than the interval
    prev_time = cur_time; // Assign the value of current time as previous time new value
    return true; // Return true which means the value of the counter is ready to be displayed
  }
  else return false; // Return false meaning cannot display the next value of counter at the moment
}

// Function that returns an integer value of the key that is pressed on the keypad
int Press_Value(char keypress){
  int value = 0;
  switch(keypress){
    case '0': return value = 0;break;
    case '1': return value = 1;break;
    case '2': return value = 2;break;
    case '3': return value = 3;break;
    case '4': return value = 4;break;
    case '5': return value = 5;break;
    case '6': return value = 6;break;
    case '7': return value = 7;break;
    case '8': return value = 8;break;
    case '9': return value = 9;break;
  }
}
