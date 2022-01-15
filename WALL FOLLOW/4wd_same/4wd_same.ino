#include <Servo.h> 
Servo myservo;
//-------------------------------------------- SETUP LOOP ----------------------------------------------------------------------------
void setup() { 
  myservo.attach(4);  // attaches the servo on pin 10 (SERVO_1 on the Motor Drive Shield to the servo object  
  myservo.write(90); // tells the servo to position at 90-degrees ie. facing forward.
  delay(4000); 
}
void loop() {
}
