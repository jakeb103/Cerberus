#include <IRremote.h>

IRsend irsend;

void setup() {
  pinMode (3,OUTPUT);
}

void loop() {
    irsend.sendNEC(0x68B92, 32);
    delay(100);
}
