/* 
- TEST_TEENSY41_PWM
- Author: takurx, taku3wr@gmail.com
- Ref. https://www.pjrc.com/teensy/td_pulse.html
*/

#include <Arduino.h>

int pwm_width;

int pin_control1 = 27;
int pin_control2 = 39;
int pin_control3 = 26;
int pin_control4 = 38;

int pin_pwm2      = 29;
int pin_pwm1_test = 28;
int pin_pwm3_test = 15;
int pin_pwm4_test = 14;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(3000);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  //pinMode(3, OUTPUT);
  pinMode(pin_pwm2, OUTPUT);
  pinMode(pin_pwm1_test, OUTPUT);
  pinMode(pin_pwm3_test, OUTPUT);
  pinMode(pin_pwm4_test, OUTPUT);
  
#if 1
  pinMode(pin_control1, OUTPUT);
  pinMode(pin_control2, OUTPUT);
  pinMode(pin_control3, OUTPUT);
  pinMode(pin_control4, OUTPUT);
  digitalWrite(pin_control1, LOW);
  //digitalWrite(pin_control1, HIGH);
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, LOW);
#endif

  //analogWriteFrequency(3, 375000); // Teensy 3.0 pin 3 also changes to 375 kHz
  //analogWriteFrequency(3, 1000000); // Teensy 4.1 pin 3 also changes to 1000 kHz
  //analogWriteFrequency(3, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(pin_pwm2, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(pin_pwm1_test, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(pin_pwm3_test, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  analogWriteFrequency(pin_pwm4_test, 50); // Teensy 4.1 pin 3 also changes to 50 kHz
  //analogWriteResolution(8);  // analogWrite value 0 to 255, or 256 for high
  analogWriteResolution(15);  // analogWrite value 0 to 4095, or 4096 for high

  //float pwm_width_percentage = 900.0 / 20000 * (1<<15);
  float pwm_width_percentage = 1000.0 / 20000 * (1<<15);
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

  analogWrite(pin_pwm2, pwm_width); // analogWrite value 0 to 4095, or 4096 for high
  analogWrite(pin_pwm1_test, pwm_width_28); // analogWrite value 0 to 4095, or 4096 for high
  analogWrite(pin_pwm3_test, pwm_width_25); // analogWrite value 0 to 4095, or 4096 for high
  analogWrite(pin_pwm4_test, pwm_width_24); // analogWrite value 0 to 4095, or 4096 for high
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(3, 128); // analogWrite value 0 to 255, or 256 for high
  //analogWrite(3, 2048); // analogWrite value 0 to 4095, or 4096 for high
  /*
  digitalWrite(pin_control1, LOW);
  digitalWrite(pin_control2, HIGH);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, LOW);
  delay(30);
  digitalWrite(pin_control1, LOW);
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, HIGH);
  digitalWrite(pin_control4, LOW);
  delay(30);
  digitalWrite(pin_control1, LOW);
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, HIGH);
  delay(30);
  digitalWrite(pin_control1, HIGH);
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, LOW);
  delay(30);
  */

  /*
  digitalWrite(pin_control1, HIGH);
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, LOW);
  delay(500);
  */
 Serial.print("test");
 Serial1.print("split");

 int delay_time = 1000;
#if 1
  digitalWrite(pin_control1, HIGH); //500
  digitalWrite(pin_control2, HIGH);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, LOW);
  delay(delay_time);

  digitalWrite(pin_control1, LOW); //1000
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, LOW);
  delay(delay_time);

  digitalWrite(pin_control1, HIGH); //1500
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, HIGH);
  digitalWrite(pin_control4, LOW);
  delay(delay_time);
  
  digitalWrite(pin_control1, HIGH); //2000
  digitalWrite(pin_control2, LOW);
  digitalWrite(pin_control3, LOW);
  digitalWrite(pin_control4, HIGH);
  delay(delay_time);
#endif
}