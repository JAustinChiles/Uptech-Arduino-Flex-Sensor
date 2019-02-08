#include <Servo.h>
Servo myServo;

const int flexPin = A0; 
const int ledPin = 7; 
int closed = 0;
int handOpenCount = 0;
int maxOpen = 700;
int minOpen = 890;
int handClosed = 700;
int handOpen = 890;
void setup() 
{ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
} 

void loop() 
{ 
  
  // Stores and displays the current flex value of sensor
  int flexValue;  
  flexValue = analogRead(flexPin);
  Serial.print("sensor: ");
  Serial.println(flexValue);



  // Counts number of times hand has been open
  if(flexValue<handClosed){
    closed = 1;}
  if(closed=1){
    if(flexValue>handOpen){
      handOpenCount = handOpenCount + 1;
      closed = 0;}
  }

  //Keeps track of max hand length open
  if(flexValue>maxOpen){
    maxOpen = flexValue;
  }
  
  // Keeps track of farthest closed hand has been
  if(flexvalue<minOpen){
    minOpen = flexValue;
  }

  //display hand opens
  Serial.print("Number of times hand was opened: ");
  Serial.println(handOpenCount);

  //LED light test
  if(flexValue>890)
     digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);
  
  delay(20);
} 
