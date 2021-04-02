/* 
- TEST_TEENSY41_PWM
- Author: takurx, taku3wr@gmail.com
- Ref. https://www.pjrc.com/teensy/td_pulse.html
*/

#include <Arduino.h>

int pwm_width;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(3000);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  //pinMode(3, OUTPUT);
  pinMode(29, OUTPUT);
  //analogWriteFrequency(3, 375000); // Teensy 3.0 pin 3 also changes to 375 kHz
  //analogWriteFrequency(3, 1000000); // Teensy 4.1 pin 3 also changes to 1000 kHz
  //analogWriteFrequency(3, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(29, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  //analogWriteResolution(8);  // analogWrite value 0 to 255, or 256 for high
  analogWriteResolution(15);  // analogWrite value 0 to 4095, or 4096 for high

  float pwm_width_percentage = 900.0 / 20000 * (1<<15);
  //float pwm_width_percentage = 2000.0 / 20000 * (1<<15);
  int pwm_width = int(pwm_width_percentage); //(2<<15);
  //int pwm_width = 2048;
  Serial.print("pwm_width: ");
  Serial.println( pwm_width);

  analogWrite(29, pwm_width); // analogWrite value 0 to 4095, or 4096 for high
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(3, 128); // analogWrite value 0 to 255, or 256 for high
  //analogWrite(3, 2048); // analogWrite value 0 to 4095, or 4096 for high
}