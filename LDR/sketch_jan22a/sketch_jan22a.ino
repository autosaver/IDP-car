int s= A0;
int val=0;
void setup() {Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(13,OUTPUT);
analogWrite(5,150);
}

void loop() {
  val=analogRead(s);
  if(val!=0)
  {Serial.println(val);
  if(val<1000)
  digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);
  }
   delay(200);
}
