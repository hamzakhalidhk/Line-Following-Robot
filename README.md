# Line-Following-Robot
This is an arduino code for a line following robot made using Arduino UNO and three IR sensors. You edit it to make it for any number of sensors.

# Sensors' values
The following lines of code is used to read the sensor values and display on the arduino's serial monitor so that calibration may become easier:

    S0sensor = digitalRead(2);
    S2sensor = digitalRead(3);
    S1sensor = digitalRead(4); 
    Serial.print("Signal: "); Serial.print(S0sensor); Serial.print(" "); 
    Serial.print(S1sensor);  Serial.print(" ");    
    Serial.print(S2sensor); Serial.print(" "); Serial.print(" "); 
    
# Decisions   
The following lines of code is used to help robot make decisions to stop, to turn left or right, to move backward and forward:

     if ((S0sensor == LOW)&&(S1sensor == HIGH)&&(S2sensor == LOW))
     motfwd();
     else if ((S0sensor == HIGH)&&(S1sensor == LOW)&&(S2sensor == LOW))
     motright();
     else if ((S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == HIGH))
     motleft();
     else if ((S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == LOW))
     motfwd();
     else if ((S0sensor == HIGH)&&(S1sensor == HIGH)&&(S2sensor == HIGH))
     motstop();
     else if ((S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == LOW))
     motbwd();
    
*Note that the logic used here is that the sensor gives '1' when it is on the line and '0' when it is not. It can be reverse in your case.

# How to make it using six IR sensors?
If you want to use six IR sensors for accuracy. You need can make decisions in the following manner:

     if ((S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == HIGH)&&(S3sensor == HIGH)&&(S4sensor == LOW)&&(S5sensor == LOW))
     motfwd();
     else if (S0sensor == HGH)&&(S1sensor == HIGH)&&(S2sensor == LOW)&&(S3sensor == LOW)&&(S4sensor == LOW)&&(S5sensor == LOW))
     motright();
     else if (S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == LOW)&&(S3sensor == LOW)&&(S4sensor == HIGH)&&(S5sensor == HIGH))
     motleft();
     else if (S0sensor == HIGH)&&(S1sensor == HIGH)&&(S2sensor == HIGH)&&(S3sensor == HIGH)&&(S4sensor == HIGH)&&(S5sensor == HIGH))
     motstop();
     else if (S0sensor == LOW)&&(S1sensor == LOW)&&(S2sensor == LOW)&&(S3sensor == LOW)&&(S4sensor == LOW)&&(S5sensor == LOW))
     motbwd();
