#include  "avoid.h"

Avoid route;  // This creates the path for the car to travel in order to reach its destination.


void setup() {
  // put your setup code here, to run once:
  loop();
}

void loop() {
  // put your main code here, to run repeatedly:
  route.drive();        // This repeatedly checks to see if either: A, the destination has been reached; or B, there is an obsticle which must be avoided. 
                        // It then changes the navigation mode to conform to the situation.
}
