#include <Servo.h>
Servo myServo;

const int flexPin = A0; 
const int ledPin = 7; 
bool closed = false;
int handOpenCount = 0;
int handClosed = 150;
int handOpen = 250;
double maxOpen = 0;
double minOpen = 50;
int angle = 0;
double voltage = 0;
void setup() 
{ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
} 

void loop() 
{ 
  
  // Stores and displays the current flex value of sensor
  double flexValue;  
  flexValue = analogRead(flexPin);
  voltage = (flexValue * 5 / 1023);
  Serial.println(" ");
  Serial.print("Voltage of sensor: ");  
  Serial.println(voltage);

  //calculates angle of sensor

  angle = ((flexValue - 175 )/1.5);



  // Counts number of times hand has been open
  if(flexValue<handClosed){
    closed = true;}
  if(closed == true){
    if(flexValue>handOpen){
      handOpenCount = handOpenCount + 1;
      closed = false;}
  }

  //Keeps track of max hand length open
  if(angle>maxOpen){
    maxOpen = angle;
  }
  
  // Keeps track of farthest closed hand has been
  if(angle<minOpen){
    minOpen = angle;
  }




  //display angle of sensor
  Serial.print("Angle of flex sensor: ");
  Serial.print(angle);
  Serial.println(" degrees");

  //display hand opens
  Serial.print("Number of times hand was opened: ");
  Serial.println(handOpenCount);

  Serial.print("Max hand opened angle: ");
  Serial.println(maxOpen);

  Serial.print("Max hand closed angle: ");
  Serial.println(minOpen);

  //LED light test
  //if(flexValu890)
  //   digitalWrite(ledPin,HIGH);
  //else
  //  digitalWrite(ledPin,LOW);
 
  delay(200);
} 
