/*
* Parking assistant signal lights
*
* by Steve Bremer
*
*/

#include "echo.h"

void setup() {
  Serial.begin(115200);
  Serial.println(F("\nEcho location test"));
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
int dist_cm, yellow_dist, red_dist;
int red_trim, yellow_trim;
// Light-based wake-up trigger


// begin echo_location
dist_cm = echo_locate();
//Serial.println(dist_cm);

// Read trim potentiometers for minor adjustments to yellow and red LED lighting distances
red_trim = analogRead(RED_POT_PIN);
yellow_trim = analogRead(YELLOW_POT_PIN);
yellow_dist = 50+(yellow_trim*.1); // 70 seemed to work well when prototyping
red_dist = 35+(red_trim*.1); // 45 seemed to work well when prototyping
Serial.print("Red: ");
Serial.println(red_dist);
Serial.print("Yellow: ");
Serial.println(yellow_dist);
//Serial.println(yellow_trim*.01);

if (dist_cm > yellow_dist) {
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
}
else if (dist_cm <= yellow_dist && dist_cm > red_dist+5) {
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(RED_LED, LOW);
}
else if (dist_cm <= red_dist){
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, HIGH);
}
else {
//  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
}
}

