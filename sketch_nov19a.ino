#include <Servo.h>
Servo myServo;

const int flexPin = A0; 
const int ledPin = 7; 

void setup() 
{ 
  Serial.begin(9600);
  pinMode(flexPin, INPUT);

  int closed = 0;
  int handOpenCount = 0;
  int maxOpen = 700;
  int minOpen = 890;
  int handClosed = 700;
  int handOpen = 890;
} 

void loop() 
{ 
  
  // Stores and displays the current flex value of sensor
  int flexValue;  
  flexValue = analogRead(flexPin);
  Serial.print("sensor: ");
  Serial.println(flexValue);


 
  // Counts number of times hand has been open
  int handOpenCounter(int x, int y, int z){
    int a
  if(x<y){
    closed = 1;}
  if(closed=1){
    if(x>z){
      a = a + 1;
      closed = 0;}
  }
  return a;
  }
  
  //Keeps track of max hand length open
  if(flexValue>maxOpen){
    maxOpen = flexValue;
  }
  
  // Keeps track of farthest closed hand has been
  if(flexValue<minOpen){
    minOpen = flexValue;
  }

  handOpenCount = handOpenCounter(flexValue, handClosed, handOpen);

  //display hand opens
  Serial.print("Number of times hand was opened: ");
  Serial.println(handOpenCount);

  //LED light test
  //if(flexValue>890)
  //   digitalWrite(ledPin,HIGH);
  //else
  //  digitalWrite(ledPin,LOW);
  
  delay(1000);
} 
