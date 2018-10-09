int trigPin = 12; //triggor pin
int echoPin = 11; // echo pin
int led = 9;// led1
int led1 = 8;// led2
int led2= 7;// led3

long timeperiod, cm, inches; 


void setup()
{
  Serial.begin(9600); //serial port communication
  pinMode(trigPin, OUTPUT); // defining pinmode for trig
  pinMode(echoPin, INPUT);  // defining pinmode for echo pin
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);// sending 10 us pulse
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  timeperiod = pulseIn(echoPin, HIGH);  // integrating pulse 

  inches = microsecondsToInches(timeperiod);
  cm = microsecondsToCentimeters(timeperiod);

  if(cm >= 20 && cm < 40){
    digitalWrite(led,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    }
  else if(cm >= 40 && cm < 70){
    digitalWrite(led1,HIGH);
    digitalWrite(led,LOW);
    digitalWrite(led2,LOW);
    }
 else if(cm >= 70){
    digitalWrite(led2,HIGH);
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
    }

    else{
      digitalWrite(led2,LOW);
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
      }
  
  Serial.print("distcance in inches=");
  Serial.print(inches);
  Serial.print("   distance in centimeters=");
  Serial.print(cm);
  Serial.println();
 
  
  delay(1);
}
long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 29 / 2;
}
