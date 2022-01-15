#define LS A3 // left sensor
#define RS A0 // right sensor
#define LM1 10 // left motor M1a
#define LM2 9 // left motor M2a
#define RM1 11 // right motor M2a
#define RM2 12 // right motor M2b
void setup()
{
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(LM1, OUTPUT);
pinMode(LM2, OUTPUT);
pinMode(RM1, OUTPUT);
pinMode(RM2, OUTPUT);
pinMode(A5,OUTPUT);
pinMode(A4,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);
digitalWrite(A5, HIGH);
digitalWrite(A4, LOW);
digitalWrite(A1, HIGH);
digitalWrite(A2, LOW);
}
int x=0,y=0;
void loop()
{
  delay(10);
  x=digitalRead(LS);
  y=digitalRead(RS);
if(!x && !y) // Move Forward on line
{
digitalWrite(LM2, HIGH);
digitalWrite(LM1, LOW);
digitalWrite(RM2, HIGH);
digitalWrite(RM1, LOW);
}
if(!x && (y)) // turn left by rotationg left motors in forward and right ones in backward direction
{
digitalWrite(LM1, HIGH);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, HIGH);
}
if((x) && !y) // Turn right by rotating right motors in forward and left ones in backward direction
{
digitalWrite(LM1, LOW);
digitalWrite(LM2, HIGH);
digitalWrite(RM1, HIGH);
digitalWrite(RM2, LOW);
}

if((x) && (y)) // Finish line, stop both the motors
{
digitalWrite(LM1, LOW);
digitalWrite(LM2, LOW);
digitalWrite(RM1, LOW);
digitalWrite(RM2, LOW);
}
}
