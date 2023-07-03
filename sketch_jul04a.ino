const int ledPin = 5; // digital pin 5 
const int ldrPin = A0; // analog pin 0

double Light (int RawADC0)
{
  double Vout=RawADC0*0.0048828125;
  int lux=500/(10*((5-Vout)/Vout));//use this equation if the LDR is in the upper part of the divider
  //int lux=(2500/Vout-500)/10;
  return lux;
}
void setup() { // The setup() function will only run once, after each powerup or reset of the Arduino board.
Serial.begin(9600);
pinMode(ledPin, OUTPUT); // Here LED is determined as an output or an indicator.
pinMode(ldrPin, INPUT); // Here LDR sensor is determined as input.
digitalWrite(ledPin, LOW); 
}
void loop() { // Void loop is ran again and again and contains main code.
int ldrStatus = analogRead(ldrPin); //A functon to read the intensity reaching the ldr (it is an analog signal)
if(Light(ldrStatus)<65){
  digitalWrite(ledPin, HIGH); // sets the digital pin 5 on
  delay(550);
}
else{
  digitalWrite(ledPin, LOW); // sets the digital pin 5
  delay(550);
}
Serial.print("The intensity is: \n");
Serial.println(Light(ldrStatus));
Serial.print(" LUX \n");
delay(850);
}
