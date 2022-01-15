#include<Servo.h>
const int trigPin = 6;
const int echoPin = 7;
Servo myservo;
#define m11 11
#define m12 12
#define m21 10
#define m22 9
// defines variables
#define LS A3 // left sensor
#define RS A0 // right sensor
long duration,x=0,y=0;
int distance;
void backward()
{
digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
}
void right()
{
digitalWrite(m11, LOW);
digitalWrite(m12, HIGH);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
}
void forward()
{
digitalWrite(m11, LOW);
digitalWrite(m12, HIGH);
digitalWrite(m21, LOW);
digitalWrite(m22, HIGH);
}
void left()
{
digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, HIGH);
}
void stops()
{
digitalWrite(m11, LOW);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, LOW);
}
int lookRight()
{
    myservo.write(0); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
}

int lookLeft()
{
    myservo.write(180); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
    delay(100);
}
void setup() {
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(A5,OUTPUT);
pinMode(A4,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
myservo.attach(4);
pinMode(m11, OUTPUT);
pinMode(m12, OUTPUT);
pinMode(m21, OUTPUT);
pinMode(m22, OUTPUT);
Serial.begin(9600); 
}
int readPing()
{
  digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
long du = pulseIn(echoPin, HIGH);
int d= du*0.034/2;
delay(200);
return d;
}
void A()
{
  for(int i=0;1;i++)
  {
    char data2=Serial.read();
    if(data2=='c')break;
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
  distance=0;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
myservo.write(90);
distance=readPing();
delay(200);
if(distance<40)
{
   stops();
   delay(100);
   distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);
if(distanceR>=distanceL)
  {
    right();
    delay(1000);
    forward();
  }else
  {
    left();
    delay(1000);
    forward();
  }
 }
 else
  forward();
}
}
void B()
{
for(int i=0;1;i++)
{
  Serial.println(i);
char data1 = Serial.read();
if(data1=='c')
break;
switch(data1)
{
  case 'f':
     forward();Serial.println("forward press");
     break;
     case 'b':
     backward();
     break;
     case 'l':
     left();
     break;
     case 'r':
     right();
     break;
     case 's':
     stops();
     break;
}
}
}
void C()
{
  
  digitalWrite(A5,HIGH);
  digitalWrite(A1,HIGH);
digitalWrite(A4, LOW);
digitalWrite(A2, LOW);  
for(int i=0;1;i++)
  {
    char data2=Serial.read();
    if(data2=='c')break;
  x=digitalRead(LS);
  y=digitalRead(RS);
if(!x && !y)
{ forward(); delay(200); stops();}
if(!x && (y)) right();
if((x) && !y) left();
if((x) && (y))stops();
delay(100);
}

digitalWrite(A5, LOW);
digitalWrite(A1, LOW);
}

void loop() 
{
  while(Serial.available()>0)
  {
   char data=Serial.read(); 
   Serial.println("first step");
if(data=='A')
A();
else if(data=='B')
{B();Serial.println("b called");}
else if(data=='C')
C();
}
}
  
  
