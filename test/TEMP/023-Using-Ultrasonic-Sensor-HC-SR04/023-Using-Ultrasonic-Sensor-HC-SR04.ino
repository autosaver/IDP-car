#include<Servo.h>
const int trigPin = 6;
const int echoPin = 7;
Servo myservo;
#define m11 11
#define m12 12
#define m21 10
#define m22 9
// defines variables
long duration;
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
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
delay(200);
return distance;
}
void loop() 
{
   int distanceR = 0;
 int distanceL =  0;
 delay(40);
  distance=0;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
myservo.write(90);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
delay(200);
if(distance<30)
{
  stops();
  delay(100);
  backward();
  delay(400);
   stops();
   distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);
if(distanceR>=distanceL)
  {
    right();
    stops();
  }else
  {
    left();
    stops();
  }
 }else
 {
  forward();
 }
 distance = readPing();
}
