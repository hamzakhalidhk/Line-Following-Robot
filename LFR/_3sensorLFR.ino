int S0 = 2, S1 = 3, S2 = 4;
int S0sensor,S1sensor,S2sensor,S3sensor,S4sensor,S5sensor;

int motRight1= 7 ;
int motRight2= 8; 
int motRightpwm= 9 ;
int motLeft1= 12;
int motLeft2= 13 ;
int motLeftpwm= 11;

int rightPWM = 250;
int leftPWM = 68;

void motfwd();
void motbwd();
void motright();
void motleft();
void motstop();
void setup() {
  
  Serial.begin(9600);
  
  pinMode(S0, INPUT);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);

  pinMode(motRight1,OUTPUT);
  pinMode(motRight2,OUTPUT);
  pinMode(motRightpwm,OUTPUT);
  pinMode(motLeft1,OUTPUT);
  pinMode(motLeft2,OUTPUT);
  pinMode(motLeftpwm,OUTPUT);

}

void loop() {

  S0sensor = digitalRead(2);
  S2sensor = digitalRead(3);
  S1sensor = digitalRead(4); 

   Serial.print("Signal: "); Serial.print(S0sensor); Serial.print(" "); Serial.print(S1sensor);   Serial.print(" "); Serial.print(S2sensor);
   Serial.print(" "); Serial.print(" "); 

  //------------------- COMMANDS -------------------------//
  if ((S0sensor == LOW)&&(S1sensor == HIGH)&&(S2sensor == LOW))
  motfwd();
  else if ((S0sensor == HIGH)&&(S1sensor == LOW)&&(S2sensor == LOW))
  motright();
  else if ((S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == HIGH))
  motleft();
  else if ((S0sensor == HIGH)&&(S1sensor == HIGH)&&(S2sensor == HIGH))
  motstop();
  else if ((S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == LOW))
  motbwd();
}
void motfwd(){
digitalWrite(motRight1,LOW);
digitalWrite(motRight2, HIGH);
analogWrite(motRightpwm, rightPWM);
digitalWrite(motLeft1,HIGH);
digitalWrite(motLeft2, LOW);
analogWrite(motLeftpwm, leftPWM);
  }
void motleft(){
digitalWrite(motRight1,LOW);
digitalWrite(motRight2, HIGH);
analogWrite(motRightpwm, rightPWM);
digitalWrite(motLeft1,HIGH);
digitalWrite(motLeft2, HIGH);
analogWrite(motLeftpwm, leftPWM);
  }
  void motright(){
digitalWrite(motRight1,HIGH);
digitalWrite(motRight2, HIGH);
analogWrite(motRightpwm, rightPWM);
digitalWrite(motLeft1,HIGH);
digitalWrite(motLeft2, LOW);
analogWrite(motLeftpwm, leftPWM);
  }
  void motbwd()
  {
digitalWrite(motRight1,LOW);
digitalWrite(motRight2, HIGH);
analogWrite(motRightpwm, rightPWM);
digitalWrite(motLeft1,HIGH);
digitalWrite(motLeft2, LOW);
analogWrite(motLeftpwm, leftPWM);
  }
   void motstop()
  {
digitalWrite(motRight1,LOW);
digitalWrite(motRight2, LOW);
digitalWrite(motLeft1,LOW);
digitalWrite(motLeft2, LOW);

  }
