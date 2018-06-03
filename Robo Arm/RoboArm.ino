#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
int val;
int val2;
int val3;
int potpin = A0;
int potpin2 = A1;
int potpin3 = A2;


void setup()
{
myservo1.attach(3);
myservo2.attach(5);
myservo3.attach(6);


}

void loop()
{
 
val = analogRead(potpin);        
val = map(val, 0, 1023, 0, 179);
myservo1.write(val);
delay(5);
val2 = analogRead(potpin2);
val2 = map(val2, 0, 1023, 0, 179);
myservo2.write(val2);
delay(5);
val3 = analogRead(potpin3);   
val3 = map(val3, 0, 1023, 0, 180);
myservo3.write(val3);
delay(5);

}

