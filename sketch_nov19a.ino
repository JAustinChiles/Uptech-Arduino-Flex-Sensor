#include <Servo.h>
Servo myServo;


//This code uses voltages from a flex sensor to calculate the angle of the sensor, and the number of times
//a persons hand has been opened and closed. The data is saved as a CSV file to easily be graphed in excel,
//which is why the data is outputed as numbers seperated by commas.



const int flexPin = A0; 
const int ledPin = 7; 
bool closed = false;
int handOpenCount = 0;
int handClosed = 240;
int handOpen = 170;
double maxOpen = 0;
double minOpen = 0;
int angle = 0;
int tempAngle = 0;
double voltage = 0;
double Time = 0;
void setup() 
{ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
} 

void loop() 
{ 

  Time = (Time + 0.2);
  Serial.print(Time);
  Serial.print(", ");
  
  // Stores and displays the current flex value of sensor
  double flexValue;  
  flexValue = analogRead(flexPin);
  voltage = (flexValue * 5 / 1023);
  //Serial.println(" ");
  //Serial.print("Voltage of sensor: ");  
  Serial.print(voltage);
  Serial.print(", ");
  //Serial.print(flexValue);
  //Serial.print(", ");

  //calculates angle of sensor, using quadratic regression

  angle = ( 127.484 + ( -0.778 * flexValue) + (0.0122 * flexValue));



  // Counts number of times hand has been open
  if(flexValue>handClosed){
    closed = true;}
  if(closed == true){
    if(flexValue<handOpen){
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



  //display angle of sensor in degrees
  //Serial.print("Angle of flex sensor: ");
  Serial.print(angle);
  Serial.print(", ");

  //display hand opens
  //Serial.print("Number of times hand was opened: ");
  Serial.print(handOpenCount);
  Serial.print(", ");

  //Serial.print("Max hand opened angle: ");
  Serial.print(maxOpen);
  Serial.print(", ");

  //Serial.print("Max hand closed angle: ");
  Serial.println(minOpen);

  //LED light test
  //if(flexValu890)
  //   digitalWrite(ledPin,HIGH);
  //else
  //  digitalWrite(ledPin,LOW);
 
  delay(200);
} 
