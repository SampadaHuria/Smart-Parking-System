#include <Servo.h> //includes the servo library

Servo S1,S2;

int ir_entry = 2;
int ir_exit = 7;

int ir_s1=5;
int ir_s2=6;

int Slots=2;
int Space=2;


void setup() 
{
  Serial.begin(9600);                      
pinMode(ir_entry, INPUT);                        //INITIALIZE DIGITAL PINS AS INPUT.
pinMode(ir_exit, INPUT);

pinMode(ir_s1,INPUT);
pinMode(ir_s2,INPUT);
  
S1.attach(3);    //SERVO MOTOR PIN CONNECTED TO pin 3 
S1.write(100);   //SETS THE SERVO AT 100 DEGREE POSITION

S2.attach(4);    //SERVO MOTOR PIN CONNECTED TO pin 4 
S2.write(100);   //SETS THE SERVO AT 100 DEGREE POSITION
 
Serial.println("ARDUINO PARKING SYSTEM");

delay(2000);
}

void loop()
{ 
  Serial.println("WELCOME");
Serial.println("Total Slot :");
Serial.println(Slots);
Serial.println("Available Slots");
Serial.println(Space);
  Serial.println("Slot 1 :");
  if(digitalRead (ir_s1)== LOW)     // read digital data from IR sensor present at slot 1
  {
    Serial.println("Not Available");
  }
  else
  {
    Serial.println("Empty");
  }
  Serial.println("Slot 2 :");
  if(digitalRead (ir_s2)== LOW)      // read digital data from IR sensor present at slot 2
  {
    Serial.println("Not Available");
  }
  else
  {
    Serial.println("Empty");
  }
if(digitalRead (ir_entry) == LOW)     // read digital data from IR sensor present on the entrance
{
              
    if(Space>0)
    {
       S1.write(0);   // sets the servo at 0 degree position
      Space=Space-1;
      delay(100);
   S1.write(100);
  Serial.println("Car Entered");
  }
  else
  {
    Serial.println("Not Enough Space");
  }
}
if(digitalRead (ir_exit) == LOW)     // read digital data from IR sensor present at the exit
{
                  
  if(Space<2)
  {
    S2.write(0);         // sets the servo at 0 degree position
    Space=Space+1;
    delay(100);
  S2.write(100);
  Serial.println("Car Exit");
  }
  else
  {
    Serial.println("Enough Space");
  }
}
delay(1000);
}
