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
  pinMode(28, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  //pinMode(12, OUTPUT);
  //pinMode(11, OUTPUT);
  //pinMode(10, OUTPUT);
  //pinMode( 9, OUTPUT);
  //digitalWrite(12, HIGH);
  //digitalWrite(11, LOW);
  //digitalWrite(10, LOW);
  //digitalWrite( 9, LOW);
  //analogWriteFrequency(3, 375000); // Teensy 3.0 pin 3 also changes to 375 kHz
  //analogWriteFrequency(3, 1000000); // Teensy 4.1 pin 3 also changes to 1000 kHz
  //analogWriteFrequency(3, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(29, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(28, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(25, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(24, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  //analogWriteResolution(8);  // analogWrite value 0 to 255, or 256 for high
  analogWriteResolution(15);  // analogWrite value 0 to 4095, or 4096 for high

  float pwm_width_percentage = 900.0 / 20000 * (1<<15);
  float pwm_width_percentage_28 = 500.0 / 20000 * (1<<15);
  float pwm_width_percentage_25 = 1500.0 / 20000 * (1<<15);
  float pwm_width_percentage_24 = 2000.0 / 20000 * (1<<15);
  //float pwm_width_percentage = 2000.0 / 20000 * (1<<15);
  int pwm_width = int(pwm_width_percentage); //(2<<15);
  int pwm_width_28 = int(pwm_width_percentage_28); //(2<<15);
  int pwm_width_25 = int(pwm_width_percentage_25); //(2<<15);
  int pwm_width_24 = int(pwm_width_percentage_24); //(2<<15);
  //int pwm_width = 2048;
  Serial.print("pwm_width: ");
  Serial.println( pwm_width);

  analogWrite(29, pwm_width); // analogWrite value 0 to 4095, or 4096 for high
  analogWrite(28, pwm_width_28); // analogWrite value 0 to 4095, or 4096 for high
  analogWrite(25, pwm_width_25); // analogWrite value 0 to 4095, or 4096 for high
  analogWrite(24, pwm_width_24); // analogWrite value 0 to 4095, or 4096 for high
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(3, 128); // analogWrite value 0 to 255, or 256 for high
  //analogWrite(3, 2048); // analogWrite value 0 to 4095, or 4096 for high
  /*
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite( 9, LOW);
  delay(30);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite( 9, LOW);
  delay(30);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite( 9, HIGH);
  delay(30);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite( 9, LOW);
  delay(30);
  */
}