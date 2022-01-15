#define m11 11
#define m12 12
#define m21 10
#define m22 9
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
void setup()
{
Serial.begin(9600);
pinMode(m11, OUTPUT);
pinMode(m12, OUTPUT);
pinMode(m21, OUTPUT);
pinMode(m22, OUTPUT);
}
void loop()
{
while(Serial.available())
{
char data = Serial.read();
switch(data)
{
  case 'f':
     forward();
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
     default:
     stops();
}
}
}
