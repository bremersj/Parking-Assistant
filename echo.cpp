#include "echo.h"
#include <arduino.h>
#include <stdlib.h>

int echo_locate() {
  long old_duration, duration, avg_duration;
  int dist_cm, avg_dist;

  // Send pulses
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(LOW_HIGH_DELAY);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(PULSE_TM);
  digitalWrite(TRIG_PIN, LOW);

//  avg_duration = 0;
//  for (int i = 0; i <= PULSE_AVERAGE; i++) {
//  // Get echo delay and corresponding distance
//    duration = pulseIn(ECHO_PIN, HIGH);
//    avg_duration += duration;
//  }
//  avg_duration = avg_duration/PULSE_AVERAGE;
////  Serial.print("avg_duration: ");
////  Serial.println(avg_duration);
//  dist_cm = avg_duration*0.034/2;

  duration = pulseIn(ECHO_PIN, HIGH);
  dist_cm = duration*0.034/2;
  return dist_cm;
}
