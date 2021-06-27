
//KIYANI'S LAB https://www.youtube.com/channel/UC-BVfBm27vcdQaH20dnfTpg/featured

#include <EEPROM.h>
int dl;
uint8_t eft,spd,dly,dl1;
uint16_t a,b,ah,al;
void dataWrite(uint16_t data);
bool st;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<16;i++){
pinMode(i,OUTPUT);

}
pinMode(16,INPUT_PULLUP);
pinMode(17,INPUT_PULLUP);
pinMode(18,INPUT_PULLUP);
pinMode(19,INPUT_PULLUP);
a=1;

dly=1;
eft=EEPROM.read(0);
spd=EEPROM.read(1);
if(spd>40){
  spd=0;}
  if(eft>7){
  eft=0;}
}

void loop() {
  
  // put your main code here, to run repeatedly:
if(!digitalRead(16)&st==0){
  st=1;   
  dataWrite(0);
  if(eft<7){
    eft++;
    }
      EEPROM.write(0, eft);
  }
  if(!digitalRead(17)&st==0){
    st=1;
    dataWrite(0);
  
  if(eft>0){
     eft--;
    }
    EEPROM.write(0, eft);
   }
    if(digitalRead(16)&digitalRead(17)&digitalRead(19)&digitalRead(18)){
        st=0;
    }
if(!digitalRead(18)&st==0){
   st=1;
  
  if(spd<40){
    spd++;
    }
    EEPROM.write(1, spd);
    }
    if(!digitalRead(19)&st==0){
 
    st=1;
  if(spd>1){
    spd--;
    }
     EEPROM.write(1, spd);
    }


//----------   
if(dly>spd){
  dly=0; 

if(eft==0){
 
 if(dl>16){
  dl=0;
  
  }
if(dl==0){a=1;}
dl++;
dataWrite(a);

if(dl<16)a=a<<1;

}
if(eft==1){
 
 if(dl>32){
  dl=0;
  a=2;
  }
  if(dl==0){a=2;}
  dl++;
   if(dl==16){
  
  a=32768;
  }
dataWrite(a);

if(dl<16)a=a<<1;
else a=a>>1;
}

if(eft==2){
      if(dl>8){
  dl=0;

  }
     if(dl==0){
  ah=0x8000;
  al=0x01;
  }
dl++;

a=ah|al;

dataWrite(a);
al=al<<1;
ah=ah>>1;

}

if(eft==3){
      if(dl>16){
  dl=0;

  }
     if(dl==0){
  ah=0x8000;
  al=0x01;
  }
dl++;

a=ah|al;

dataWrite(a);
al=al<<1;
ah=ah>>1;

}
if(eft==4){
      if(dl>16){
  dl=0;

  }
     if(dl==0){
  a=0;
  }
dl++;



dataWrite(a);
a=a<<1;
a=a|1;

}
if(eft==5){
      if(dl>32){
  dl=0;

  }
     if(dl==0){
  a=0;
  }
dl++;



dataWrite(a);
a=a<<1;
if(dl<16){
a=a|1;}
if(dl==16){
a=0xfffe;}

}
if(eft==6){
 
     if(dl1==0|dl>dl1){
      dl1=16;
      dl=0;
  a=1;
  b=0;
  }
dl++;


a=a|b;
dataWrite(a);
if(dl<dl1){
  
a=a<<1;}

if(dl==dl1){
  dl=0;
  dl1--;
  b=a;
   a=1;
  }

}

if(eft==7){


dataWrite(random(0,0xffff));
}

}
dly++;
delay(10);


}
void dataWrite(uint16_t data){
   for(int i=0;i<16;i++){
    digitalWrite(i,bitRead(data,i));}
   }
