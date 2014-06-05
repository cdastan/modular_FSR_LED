
/* FSR testing sketch. 
 
 Connect one end of FSR to 5V, the other end to Analog 0.
 Then connect one end of a 10K resistor from Analog 0 to ground
 Connect LED from pin 11 through a resistor to ground ( 
 
 For more information see www.ladyada.net/learn/sensors/fsr.html */

int fsrAnalogPin = 0; // FSR is connected to analog 0
int fsrAnalogPin1 = 1; // FSR is connected to analog 1  
int fsrAnalogPin2 = 2; // FSR is connected to analog 2 
int fsrAnalogPin3 = 3; // FSR is connected to analog 3
int fsrAnalogPin4 = 4; // FSR is connected to analog 4
int LEDpin = 11;      // connect ___ LED to pin 11 (PWM pin)
int LEDpin2 = 10;      // connect ___ LED to pin 10 (PWM pin)
int LEDpin3 = 9;      // connect ___ LED to pin 9 (PWM pin)
int LEDpin4 = 6;      // connect ___ LED to pin 6 (PWM pin)
int LEDpin5 = 5;      // connect ___ LED to pin 5 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int fsrReading2;     // the analog reading from the second FSR resistor divider
int fsrReading3;     // the analog reading from the third FSR resistor divider
int fsrReading4;     // the analog reading from the fourth FSR resistor divider
int fsrReading5;     // the analog reading from the fifth FSR resistor divider
int LEDbrightness, LEDbrightness2, LEDbrightness3, LEDbrightness4, LEDbrightness5;

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
  pinMode(LEDpin4, OUTPUT);
  pinMode(LEDpin5, OUTPUT);
}

void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  fsrReading2 = analogRead(fsrAnalogPin1);
  fsrReading3 = analogRead(fsrAnalogPin2);
  fsrReading4 = analogRead(fsrAnalogPin3);
  fsrReading5 = analogRead(fsrAnalogPin4);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
  Serial.println(fsrReading2);
  Serial.println(fsrReading3);
  Serial.println(fsrReading4);
  Serial.println(fsrReading5);

  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  LEDbrightness2 = map(fsrReading2, 0, 1023, 0, 255);
  LEDbrightness3 = map(fsrReading3, 0, 1023, 0, 255);
  LEDbrightness4 = map(fsrReading4, 0, 1023, 0, 255);
  LEDbrightness5 = map(fsrReading5, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness);
  analogWrite(LEDpin2, LEDbrightness2);
  analogWrite(LEDpin3, LEDbrightness3);
  analogWrite(LEDpin4, LEDbrightness4);
  analogWrite(LEDpin5, LEDbrightness5);

  delay(100);
}

