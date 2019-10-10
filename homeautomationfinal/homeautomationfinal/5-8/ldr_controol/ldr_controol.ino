int push ;
int ldr ;
int led =13;
int Switch ;
int x = 0;
int p = 0;

void setup (){
  pinMode(A0,INPUT);
  pinMode(led,OUTPUT);
  pinMode(5,INPUT);
  pinMode(7,INPUT);
   Serial.begin(9600);
}
void loop(){
  ldr = analogRead(A0);
  push = digitalRead(7);
  Switch = digitalRead(5);
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
      digitalWrite(led,LOW);}}}
