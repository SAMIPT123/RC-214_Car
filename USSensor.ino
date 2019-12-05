#include <NewPing.h>

#define TRIGGER_PIN 0

#define ECHO_PIN 1

#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {

Serial.begin(9600);

}

void loop() {

delay(2000);

int dist = sonar.ping();

pinMode(ECHO_PIN,OUTPUT);

digitalWrite(ECHO_PIN,LOW);

pinMode(ECHO_PIN,INPUT);

Serial.print("Ping: ");

Serial.print(dist);

Serial.println("cm");

}
