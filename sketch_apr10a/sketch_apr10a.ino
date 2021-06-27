
void setup() {
  for(int i = 4; i <= 13; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  divider(); // Pattern 1
  for(int i = 1; i <= 5; i++) { onOffTravel(); } // Pattern 2
  divider();
  for(int i = 1; i <= 5; i++) { seriesLR(); } // Pattern 3
  divider();
  for(int i = 1; i <= 5; i++) { seriesRL(); } // Pattern 4
  divider();
  for(int i = 1; i <= 5; i++) { even(); } // Pattern 5
  divider();
  for(int i = 1; i <= 5; i++) { odd(); } // Pattern 6
  divider();
  for(int i = 1; i <= 5; i++) { alternate(); } // Pattern 7
  divider();
  for(int i = 1; i <= 5; i++) { blinkAddEven(); } // Pattern 8
  divider();
  for(int i = 1; i <= 5; i++) { halfOnly(); } // Pattern 9
  divider();
  for(int i = 1; i <= 5; i++) { bounce(); } // Pattern 10
}

//----------------- METHODS -----------------//

//Pattern 1 - Close Open
void divider() {
  for(int i = 1; i <= 5; i++) {
    
    //Open LED 
    for(int i = 4; i <= 13; i++){
      digitalWrite(i, HIGH);
    }
    delay(100);
  
    //Close LED
    for(int i = 4; i <= 13; i++){
      digitalWrite(i, LOW);
    } 
    delay(100);
  }
}

//Pattern 2
void onOffTravel() {  
  for (int i = 4; i <= 13; i++) {
    digitalWrite(i, HIGH);
    delay(200);
    digitalWrite(i, LOW);
  }
  for (int i = 13; i >= 4; i--) {
    digitalWrite(i - 1, HIGH);
    delay(50);
    digitalWrite(i - 1, LOW);
  }
  for (int i = 4; i <= 13; i++) {
    digitalWrite(i, HIGH);
    delay(50);
    digitalWrite(i, LOW);
  }
}

//Pattern 3 - From Pin 4 -> Pin 13
void seriesRL() {
  for (int i = 13; i >= 4; i--) {
    digitalWrite(i, LOW);
    delay(50);
  }
  for (int i = 4; i <= 13; i++) {
    digitalWrite(i, HIGH);
    delay(50);
  }
}

//Pattern 4 - From Pin 13 -> Pin 4
void seriesLR() {
  for (int i = 13; i >= 4; i--) {
    digitalWrite(i, HIGH);
    delay(50);
  }
  for (int i = 4; i <= 13; i++) {
    digitalWrite(i, LOW);
    delay(50);
  }
}

//Pattern 5 - All even LED will OPEN
void even(){
  for(int i = 4;i <= 13; i++) {
    if(i % 2 == 0) {
      digitalWrite(i, HIGH);
      digitalWrite(i+1, LOW);
      delay(100);
    }
    digitalWrite(i, LOW);
  }
}

//Pattern 6 - All odd LED will OPEN
void odd(){
  for(int i = 13;i >4; i--) {
    if(i % 2 != 0) {
      digitalWrite(i, HIGH);
      digitalWrite(i-1, LOW);
      delay(100);
    }
    digitalWrite(i, LOW);
  }
}

//Pattern 7 - Combination of Pattern 5 and 6
void alternate() {
    even();
    odd();
}

//Pattern 8 - Blinking Odd and Even LED
void blinkAddEven(){ 
    for(int i=4; i<=13; i=i+2) {
      digitalWrite(i,HIGH);
      }
    for(int i=5; i<=13; i=i+2) {
      digitalWrite(i,LOW);
      }
    delay(100);
     for(int i=4; i<=13; i=i+2) {
      digitalWrite(i,LOW);
      }
    for(int i=5; i<=13; i=i+2) {
      digitalWrite(i,HIGH);
      }
    delay(100);
}

//Pattern 9 - Half only
void halfOnly(){
  for(int i=4; i<=8; i++) { //ON Pin 4 - 8
    digitalWrite(i,HIGH);
  }
  for(int i=9; i<=13; i++) { //OFF Pin 9 - 13
    digitalWrite(i,LOW);
  }
  delay(100); //Delay to ON/OFF all 5 LEDs
  
  for(int i=4; i<=8; i++) { //OFF Pin 4 - 8
    digitalWrite(i,LOW);
  }
  for(int i=9; i<=13; i++) { //ON Pin 9 - 13
    digitalWrite(i,HIGH);
  }
  delay(100); //Delay to ON/OFF all 5 LEDs
}

//Pattern 10 - Bounce Left-Right then Right-Left
void bounce() {
  for(int i=8; i>=4; i--) {
    digitalWrite(i,LOW);
    delay(50);
  }
  for(int i=4; i<=8; i++) {
    digitalWrite(i,HIGH);
    delay(50);
  }

  for(int i=9; i<=13; i++) {
    digitalWrite(i,LOW);
    delay(50);
  }
  for(int i=13; i>=9; i--) {
    digitalWrite(i,HIGH);
    delay(50);
  }
}
