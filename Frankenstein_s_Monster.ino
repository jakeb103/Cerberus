#include <IRremote.h>
// include the servo library
#include <Servo.h>

//initializing Servo object
Servo servo1;
 //Declare pin functions on RedBoard
#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define EN  6

//Declare variables for functions
char user_input;
int x;
int y;
int i =0;
int state;
int EventVal = 0;
int Event = 0;
const int servoPin = 10; //Servo motor(white wire)
const int left = 0; //extreme values for Servo position
const int right = 180; //The standard servo goes to a position
                       //specified. IT can take values in the 
                       //range from 0 to 180
const int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  resetEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
   servo1.attach(servoPin); //defining Pin for Servo object
                           //this is a method defined in Servo
}

void loop() {
  delay (50);
  digitalWrite(EN, LOW);
  Event = analogRead (A0);
  if (irrecv.decode(&results)) {
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  if ((results.decode_type == NEC) && (Event > 0)){
 digitalWrite(dir, HIGH); //Pull direction pin low to move "forward"
  for(x= 0; x<100; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
  }
 i = i++;
Serial.print ("i is: ");
Serial.print (i);
Serial.print ("|| Event is ");
Serial.println (Event);
if (i++ >= Event/12) {
  delay (2000);
  servo1.write(right);
  delay (1000);
  while(1){
    
  }
}
  }
  else {
    delay (10);

  
  }
}

void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}
