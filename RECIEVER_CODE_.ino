#include <IRremote.h>
#include <Servo.h>
Servo servo1;
const int left = 0; //extreme values for Servo position
const int right = 180; //The standard servo goes to a position
                       //specified. IT can take values in the 
                       //range from 0 to 180
int ButtonState = 0;
const int button = 4;
const int SERVO = 10;
const int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  servo1.attach(SERVO); //defining Pin for Servo object
                           //this is a method defined in Servo
                           //library

  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
  pinMode (button, INPUT);
}

void loop() {
  ButtonState = digitalRead (button);
  
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
  if (results.decode_type == NEC){
    digitalWrite (2, HIGH);
    digitalWrite (7, LOW);
  }
  else if (results.decode_type != NEC){
    digitalWrite (7, HIGH);
    digitalWrite (2, LOW);
  }
  if ((results.decode_type == NEC) && (ButtonState == HIGH)){
 servo1.write(left);
  }
  else {
    delay (10);
    servo1.write(right);
  }
}
