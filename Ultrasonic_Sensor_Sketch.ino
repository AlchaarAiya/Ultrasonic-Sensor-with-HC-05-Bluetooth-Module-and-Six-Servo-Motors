#include <Servo.h>

#define echoPin 3 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 4 //attach pin D3 Arduino to pin Trig of HC-SR04

int servoPin0 = 7;
int servoPin1 = 8;
int servoPin2 = 9;
int servoPin3 = 10;
int servoPin4 = 11;
int servoPin5 = 12;
 
Servo servo0;  
Servo servo1;  
Servo servo2;  
Servo servo3;  
Servo servo4;  
Servo servo5;  
 
int angle = 0;   // servo position in degrees 
 
void setup() 
{ 
  servo0.attach(servoPin0); 
  servo1.attach(servoPin1); 
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  
  //Initial Position (90 degrees)
  servo0.write(90);               
  servo1.write(90);               
  servo2.write(90);               
  servo3.write(90);               
  servo4.write(90);               
  servo5.write(90);
  
  delay(5000);
    
  //Ultrasonic Sensor Setup
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
} 
 
 
void loop() 
{ 
  int distance = findDistance();
  
  if (distance < 20) //Robot detected something in front of it
  {
    delay(3000); //Wait for 3 seconds
    distance = findDistance(); //Calculate the distance again
    
    if(distance < 20) //if the person is still standing in front of the robot
    {
      servo0.write(180);
      servo5.write(180);

      serial.println("Hello Human! Welcome");
    }
  }
}

int findDistance()
{
  digitalWrite(trigPin,LOW);
  delay(5);
  digitalWrite(trigPin,HIGH);
  delay(50);
  digitalWrite(trigPin,LOW);
  int duration= pulseIn(echoPin,HIGH);

  int cm=duration/29/2;
  Serial.println(cm);
  
  return cm;
}
