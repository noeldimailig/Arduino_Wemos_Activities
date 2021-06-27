int d = 800;
int counter = -1;
int sw = 0;

void setup() {
  for(int i = 2;i<=9;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(13, INPUT);

}

void loop() {
  sw=digitalRead(13);
    if(sw==1){
      
      counter++;
      switch(counter){
      case 0: zero(); break;
      case 1: one();break;
      case 2: two();break;
      case 3: three();break;
      case 4: four();break;
      case 5: five();break;
      case 6: six();break;
      case 7: seven();break;
      case 8: eight();break;
      case 9: nine(); break;}
      }
    else{
       switch(counter){
      case 0: zero(); break;
      case 1: one();break;
      case 2: two();break;
      case 3: three();break;
      case 4: four();break;
      case 5: five();break;
      case 6: six();break;
      case 7: seven();break;
      case 8: eight();break;
      case 9: nine(); break;}
    }
  
  if(counter>9){counter=-1;} 
}

void zero(){
  for(int i = 2;i <= 9;i++){
    if(i==8){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void one(){
  for(int i = 2;i <= 9;i++){
    if(i==3 || i==4 || i==9){
      digitalWrite(i, HIGH);
    }else{
      digitalWrite(i, LOW);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void two(){
  for(int i = 2;i <= 9;i++){
    if(i==4 || i==7){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void three(){
  for(int i = 2;i <= 9;i++){
    if(i==6 || i==7){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void four(){
  for(int i = 2;i <= 9;i++){
    if(i==2 || i==5 || i==6){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void five(){
  for(int i = 2;i <= 9;i++){
    if(i==3 || i==6){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void six(){
  for(int i = 2;i <= 9;i++){
    if(i==3){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void seven(){
  for(int i = 2;i <= 9;i++){
    if(i==5 || i==6 || i==7 || i==8){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void eight(){
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, HIGH);
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
void nine(){
  for(int i = 2;i <= 9;i++){
    if(i==6){
      digitalWrite(i, LOW);
    }else{
      digitalWrite(i, HIGH);
    }
  }
  delay(d);
  for(int i = 2;i <= 9;i++){
    digitalWrite(i, LOW);
  }
}
