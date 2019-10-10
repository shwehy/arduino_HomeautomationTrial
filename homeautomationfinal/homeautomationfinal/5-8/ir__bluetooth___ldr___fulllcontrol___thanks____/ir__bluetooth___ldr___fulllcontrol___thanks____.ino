#include <IRremote.h>
#include <SoftwareSerial.h>
SoftwareSerial Team(10,11);

int push ;
int ldr ;
int led =13;
int Switch ;
int x = 0;
int p = 0;
int value = 0 ;
//int power = 3;
int RECV_PIN = 4;
 IRrecv irrecv(RECV_PIN);
decode_results results;

void setup (){
  pinMode(A0,INPUT);
  pinMode(led,OUTPUT);
  pinMode(5,INPUT);
  pinMode(7,INPUT);
//  pinMode(power,OUTPUT);
  Team.begin(9600);
  //digitalWrite(power,HIGH);
   irrecv.enableIRIn();
   //Serial.begin(9600);
}
void loop(){
  ldr = analogRead(A0);
  push = digitalRead(7);
  Switch = digitalRead(5);
    if (Team.available()){
    char c;
    c=Team.read();
    if (c==55){
      value = 2;
    }
    else if (c==35){
      value = 3; 
    }
  // if (value == 3){ 
 else if (c==64){
      digitalWrite(led,HIGH);
    }
    else if (c==50){
      digitalWrite(led,LOW);
    }
    }
    
if (irrecv.decode(&results)){ 
   if (results.value == 0x80BF3BC4){ value = 1;}
   else  if (results.value == 0x80BF7B84){digitalWrite(led,HIGH);}
 else if (results.value == 0x80BF6B94){digitalWrite(led,LOW);
 }
   else if (results.value == 0x80BF916E){
     value = 2;}
    //  else if (results.value == 0x80BFD12E){
     //  value = 3;}
       
     irrecv.resume();
}
if (value==2){
if (push == 1 ) { 
 p = p + 1;
}
if ((p%2)==0){
  if (ldr>500)
  {
    digitalWrite(led, LOW);
  }
  else if (ldr < 300){
    digitalWrite(led,HIGH);
  }
}
else if ((p%2)) {
  
  if (Switch == 1) {
    x = 1;}
   else if ( Switch ==0){
    x=2;}
    
     
     if (x==1){
      digitalWrite(led,HIGH);
     }
    else if (x==2){
      digitalWrite(led,LOW);}}}}

