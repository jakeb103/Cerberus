# Cerberus
A smart dog feeder that would release food at a trickle when the proper dog was in front of the feeder

 The project is called cerberus because of the idea that this device could feed multiple dogs simoultaneously. The way it works is the feeder itself has an IR receiver and a stepper motor that controls dog food output. The dog food is all in a container with the motor shoveling it out. We had two different IR transmitters (one transmitting a sony frequency and the other transmitting NEC), and when the right dog stepped in front of the transmitter, the feeding would commence at a slow rate. If the signal was mixed or came from the wrong dog, feeding would stop. Then, we also added an IOT component. We used the MIT IOT app, and had a button that would activate if it was the right time of day for feeding. This would add a current to an input pin on the board, and only when that "button" was pressed could the dogs eat.

To see it in action, go to jake-brooks.com
