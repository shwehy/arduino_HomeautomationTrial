#include <LiquidCrystal.h>


#include <IRremote.h>


#include <SoftwareSerial.h>


#include <Servo.h>

LiquidCrystal lcd(7,6,5,4,3,2);


SoftwareSerial Team(10,11);


Servo myservo;


int lock = 0;


int tempPin = A1;

int pirq=0;


int pir =16;

int pira = 20;


int Open=0;



int Close=1;


int mga;


int Pusha;


int pos = 0;


int push ;



int ldr ;



int led =13;



int Switch ;



int x = 0;



int p = 0;


int value = 0 ;



int sec = 0;


int RECV_PIN = 18;


 IRrecv irrecv(RECV_PIN);
 
 
decode_results results;



void setup (){
  pinMode(A0,INPUT);
  
  
  pinMode(pir ,INPUT);
  
  pinMode(tempPin,INPUT);
  
  pinMode(led,OUTPUT);
  
  
  pinMode(25,OUTPUT);
  
  
  pinMode(42,INPUT_PULLUP);
  
  
  pinMode(43,INPUT_PULLUP);
  
  
  pinMode(44,INPUT_PULLUP);
  
  
  pinMode(45,INPUT_PULLUP);
  
  lcd.begin(16,2);
  
  myservo.attach(50);
  
  
  Team.begin(9600);
  
  
  irrecv.enableIRIn();
  
  

}


void loop(){


LCDS();
  ldr = analogRead(A0);
  

  push = digitalRead(42);
  
 
  Switch = digitalRead(43);
  
  
  mga =  digitalRead(44);
  
  
  Pusha = digitalRead(45);
 
  
    if (Team.available()){
      
      
      
    char c;
    
    
    c=Team.read();
    
    
    if (c==55){
      
      
      value = 2;
      
      
    }
    
    
    
    else if (c==35){
      
      
      value = 3; 
      
      
    }
    
 else if (c==15){
   
   
      value = 4;}
      
     else if (c==20){
       
       
      value = 5;
      
     }
     
     
   else if (c==24){
     
     
      value = 6; }  
      
      
 //if (value == 3){
   
   
 if (c==64){
   
   
      digitalWrite(led,HIGH);
      
      
    }
    else if (c==50){
      
      
      digitalWrite(led,LOW);
      
      
    }
    
    
    
    
    
    // }
    
    }
    
if (irrecv.decode(&results)){ 
  
  
   if (results.value == 0x80BF3BC4){ value = 1;}
   
   
   else  if (results.value == 0x80BF7B84){digitalWrite(led,HIGH);}
   
   
 else if (results.value == 0x80BF6B94){digitalWrite(led,LOW);
 
 
 }
   else if (results.value == 0x80BF916E){
     
     
     
     value = 2;}
     
     
 
       
     irrecv.resume();
}


if (value==2){
  
  
if (push == 0 ) { 
  
  
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
  
  
  
  if (Switch == 0) {
    x = 1;
  }
    
    
   else if ( Switch ==1){
     
     
    x=2;
  }
    
    
    
     
     if (x==1){
       
       
      digitalWrite(led,HIGH);
      
      
      
     }
     
     
    else if (x==2){
      
      
      digitalWrite(led,LOW);
    }
  }
}
  
      
      
if (value == 4){
  
  
p = p+1;}


if (value == 5){
  
  
 lock = 2;
 
 
}

if (value == 6){
  
  
  lock = 1;}
  
  
if (lock == 2){
  
  sec=0;
  
  
 garage(); 
 
 
}

if (lock == 1){
  
  
Security();
  }
}
void garage(){

  
  
  if ((digitalRead(pir) == HIGH)) {
    
    
    
if (Open == 0 && Close == 1){
  
  
  for(pos = 0; pos < 120; pos += 1)

 
  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  Close =0; Open =1;
}
}
  else if 
((digitalRead(pir) == LOW) && (digitalRead(45) == LOW))
{
  if (Open == 1 && Close == 0){
    for(pos = 120; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  Close = 1; Open = 0;

      }
    }
  }
  void Security(){
    if ((digitalRead(44) == LOW) && sec == 0 ){
      digitalWrite(25,LOW);
    }
      else if ((digitalRead(44) == HIGH)){
       digitalWrite(25,HIGH);
      sec = 1 ; 
      }
    } 
    void LCDS(){
      float temp = analogRead(tempPin);
      temp = temp * 0.48828125;
      lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("welcome");
        lcd.setCursor(7, 0);
         Serial.print(temp);
        Serial.print("*C");
    }
