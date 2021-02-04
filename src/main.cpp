/* 
- TEST_TEENSY41_PWM
- Author: takurx, taku3wr@gmail.com
- Ref. https://www.pjrc.com/teensy/td_pulse.html
*/

#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  //analogWriteFrequency(3, 375000); // Teensy 3.0 pin 3 also changes to 375 kHz
  analogWriteResolution(8);  // analogWrite value 0 to 255, or 256 for high
  //analogWriteResolution(12);  // analogWrite value 0 to 4095, or 4096 for high
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(3, 128);
}