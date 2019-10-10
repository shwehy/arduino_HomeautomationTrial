#include <LiquidCrystal.h>
#include <IRremote.h>
#include <SoftwareSerial.h>
#include <Servo.h>
LiquidCrystal lcd(7,6,5,4,3,2);
SoftwareSerial Team(10,11);
Servo myservo;
int pos=0;
int Open=0;
int Close=1;
int value=0;
int sec=0;
int lock=0;
int count=0;
int magwindowa=14;
int magwindowb=15;
int magwindowc=16;
int magdoora=17;
int limitdoora=18;
int limitdoorb=19;
int limitdoorc=20;
int limitdoord=21;
int limitdoorf=22;
int limitgarage=23;
int Buzzer=48;
int lampa=24;
int lampb=25;
int lampc=26;
int lampgarage=27;
int LDR=A0;
int PushLDR=28;
int Switch=29;
int ledind=30;
int pirgarage=31;
int pirsec=32;
int LM=A1;
int fan=33;
int Pushring=34;
int RECV_PIN = 35;
 IRrecv irrecv(RECV_PIN);
decode_results results;




void setup(){
  pinMode(fan,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(ledind,OUTPUT);
  pinMode(lampa,OUTPUT);
  pinMode(lampb,OUTPUT);
  pinMode(lampc,OUTPUT);
  pinMode(lampgarage,OUTPUT);
  pinMode(LM,INPUT);
  pinMode(LDR,INPUT);
  pinMode(pirgarage,INPUT);
  pinMode(pirsec,INPUT);
  pinMode(magwindowa,INPUT_PULLUP);
  pinMode(magwindowb,INPUT_PULLUP);
  pinMode(magwindowc,INPUT_PULLUP);
  pinMode(magdoora,INPUT_PULLUP);
  pinMode(limitdoora,INPUT_PULLUP);
  pinMode(limitdoorb,INPUT_PULLUP);
  pinMode(limitdoorc,INPUT_PULLUP);
  pinMode(limitdoord,INPUT_PULLUP);
  pinMode(limitdoorf,INPUT_PULLUP);
  pinMode(limitgarage,INPUT_PULLUP);
  pinMode(PushLDR,INPUT_PULLUP);
  pinMode(Switch,INPUT_PULLUP);
  pinMode(Pushring,INPUT_PULLUP);
  lcd.begin(16,2);  
  myservo.attach(36);  
  Team.begin(9600);  
  irrecv.enableIRIn();
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Welcome");}
 /* pinMode(,INPUT_PULLUP);
  pinMode(,INPUT_PULLUP);
  pinMode(,INPUT_PULLUP);*/
  void loop(){
    float temp = analogRead(LM);
      temp = temp * 0.48828125;
    
    lcd.setCursor(8,0);
    lcd.print(temp);
    lcd.setCursor(11,0);
    lcd.print("*c");
    //int lm = analogRead(LM);
    int ldr = analogRead(LDR);
    int sswitch = digitalRead(Switch);
    int ppushLDR = digitalRead(PushLDR);
    if (Team.available()){     
    char c;    
    c=Team.read();
    if (c==64){
      digitalWrite(lampa,HIGH);
    }
     else if (c==50){
       digitalWrite(lampa,LOW);
     }
    else  if (c==27){
       digitalWrite(lampb,HIGH);
     }
     else if (c==29){
       digitalWrite(lampb,LOW);
     }
  else  if (c==78){
  digitalWrite(lampc,HIGH);  
  }
  else if (c==22){
    digitalWrite(lampc,LOW);
  }
  else if (c==35){
    value=2;}
    else if (c==55){
      value=3;}
      else if (c==15){
        count=count+1;}
        else if (c==24){
          lock=1;}
          else if (c==20){
            lock=2;
          }
          else if (c==19){
            sec=0;}
    }
    if (irrecv.decode(&results)){ 
      if (results.value ==0x20DF10EF){ //power
        value =3;}
        else if (results.value ==0x20DF3EC1){ //smart
        value=2;
        }
        else if (results.value ==0x20DF906F){ //mute
        sec=0;}
        else if (results.value ==0x20DF42BD){ //myapps
        lock=1;}
          else if (results.value ==0x20DF14EB){  //back
          lock=2;
          }
            else if (results.value ==0x20DF40BF){ //v+
            count=count+1;}
             else if (results.value ==0x20DF8877){//1
             digitalWrite(lampa,HIGH);}
             
              else if (results.value ==0x20DF48B7){//2
                digitalWrite(lampb,HIGH);}
                
               else if (results.value ==0x20DFC837){//3
                 digitalWrite(lampc,HIGH);}
               else if (results.value ==0x20DFA857){//5
               digitalWrite(lampa,LOW);}
               else if (results.value ==0x20DF6897){//6
               digitalWrite(lampb,LOW);
               }
               else if (results.value ==0x20DFE817){//7
               digitalWrite(lampc,LOW);
               }
                 delay(100);
 irrecv.resume();}
 //if (
}


  
  void garage(){
     if ((digitalRead(pirgarage) == HIGH)) {
    
    
    
if (Open == 0 && Close == 1){
  
  
  for(pos = 0; pos < 100; pos += 1)

 
  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  Close =0; Open =1;
}
}
  else if 
((digitalRead(pirgarage) == LOW) && (digitalRead(limitgarage) == LOW))
{
  if (Open == 1 && Close == 0){
    for(pos = 100; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  Close = 1; Open = 0;

      }
}
  }
