int sw = 0;
void setup(){
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}
void loop(){
  sw=digitalRead(13);
  if(sw==0){
    digitalWrite(12, LOW);
  }else{
    digitalWrite(12, HIGH);
  }
}
