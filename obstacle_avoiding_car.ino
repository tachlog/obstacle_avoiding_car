int trigPin = 12;  // trig pin of HC-SR04
int echoPin = 13;  // Echo pin of HC-SR04

int ena=6;   //Enables PWM signal for Left motor
int enb=11;  //Enables PWM signal for Right motor
int revleft4 = 3;   // reverse motion of Left motor
int fwdleft5 = 9;   // forward motion of Left motor
int revright6 = 5;  // reverse motion of Right motor
int fwdright7 = 10; // forward motion of Right motor

long duration, distance; // variable for the duration of sound wave travel and distance measurement

void setup()
{
    delay(random(500, 2000));  // delay for random time
    Serial.begin(9600);        // Serial Communication is starting with 9600 of baud rate speed
    pinMode(ena, OUTPUT);      // set Motor pins as output
    pinMode(enb, OUTPUT);      
    pinMode(revleft4, OUTPUT); 
    pinMode(fwdleft5, OUTPUT);
    pinMode(revright6, OUTPUT);
    pinMode(fwdright7, OUTPUT);
 
    pinMode(trigPin, OUTPUT);  // set trig pin as output to Transmit Waves
    pinMode(echoPin, INPUT);   // set echo pin as input to capture reflected waves
}

void loop()
{

    digitalWrite(trigPin, LOW); // Clears the trigPin condition
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);// send waves for 10 us (the trigPin HIGH (ACTIVE))
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH); // receive reflected waves
    // Calculating the distance
    distance = duration / 58.2;        // convert to distance
    delay(10);
   
    if (distance > 25)
    {   
        analogWrite(ena, 170); 
        analogWrite(enb, 150);
        digitalWrite(fwdright7, HIGH); // move forward
        digitalWrite(revright6, LOW);
        digitalWrite(fwdleft5, HIGH);
        digitalWrite(revleft4, LOW);
    }

    if (distance < 24)
    {   
        analogWrite(ena, 170); 
        analogWrite(enb, 150);
        digitalWrite(fwdright7, LOW); // Stop
        digitalWrite(revright6, LOW);
        digitalWrite(fwdleft5, LOW);
        digitalWrite(revleft4, LOW);
        delay(500);
        
        analogWrite(ena, 170); 
        analogWrite(enb, 150);
        digitalWrite(fwdright7, LOW); // movebackword
        digitalWrite(revright6, HIGH);
        digitalWrite(fwdleft5, LOW);
        digitalWrite(revleft4, HIGH);
        delay(500); 

        analogWrite(ena, 170); 
        analogWrite(enb, 150);
        digitalWrite(fwdright7, LOW); // Stop
        digitalWrite(revright6, LOW);
        digitalWrite(fwdleft5, LOW);
        digitalWrite(revleft4, LOW);
        delay(100);

        analogWrite(ena, 170); 
        analogWrite(enb, 150);
        digitalWrite(fwdright7, HIGH); //turn
        digitalWrite(revright6, LOW);
        digitalWrite(revleft4, LOW);
        digitalWrite(fwdleft5, LOW);
        delay(500);
    }
}
