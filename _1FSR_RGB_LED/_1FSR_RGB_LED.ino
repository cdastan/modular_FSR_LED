
/* FSR testing sketch. 
 
 Connect one end of FSR to 5V, the other end to Analog 0.
 Then connect one end of a 10K resistor from Analog 0 to ground
 Connect LED from pin 11 through a resistor to ground ( 
 
 For more information see www.ladyada.net/learn/sensors/fsr.html */


int fsrAnalogPin = 0; // FSR is connected to analog 0

int LEDpin = 11;      // connect ___ LED to pin 11 (PWM pin)
int LEDpin2 = 10;      // connect ___ LED to pin 10 (PWM pin)
int LEDpin3 = 9;      // connect ___ LED to pin 9 (PWM pin)

int fsrReading;      // the analog reading from the FSR resistor divider

int LEDbrightness, LEDbrightness2, LEDbrightness3;

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
}

void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 

 
 //forum post code
// Thank you Rob Tillaart for helping create this missing chunk of code. (>'.')> <('.'<)
  // 20 is most blue;     400 is no blue
  int LEDbrightness3 = map(fsrReading, 20, 400, 255,  30);    // note the mapping is 'reverse'
  LEDbrightness3 = constrain(LEDbrightness3, 0, 255);  // keep the values within limits
 
  // green is max at 550 and less in both directions 
  int LEDbrightness2 =  255 - abs(fsrReading - 550);    //  see below (1)
  LEDbrightness2  = constrain(LEDbrightness2,  0, 255);   // keep the values within limits

  // red increases from 600 -- max.
  int LEDbrightness = map(fsrReading, 500, 1023, 0, 255);
  LEDbrightness = constrain(LEDbrightness, 0, 255);   // keep the values within limits


  
  // LED gets brighter the harder you press
 analogWrite(LEDpin, LEDbrightness);
 analogWrite(LEDpin2, LEDbrightness2);
 analogWrite(LEDpin3, LEDbrightness3);
 
  delay(100);
}

