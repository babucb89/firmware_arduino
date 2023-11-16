#include <TimerOne.h>
const int lm35Pin = A0;  // LM35 temperature sensor connected to analog pin A0
const int ledPin = 12;   // Onboard LED connected to digital pin 12
volatile int temperature = 0;  // Variable to hold temperature value as 0
volatile bool ledState = LOW;  // Variable to hold the LED state as low
void setup() 
{
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  attachInterrupt(digitalPinToInterrupt(lm35Pin), readTemperature, FALLING);  // Attach interrupt to LM35 pin on falling edge
  Timer1.initialize(500000);  // Initialize Timer1 with 500ms 
  Timer1.attachInterrupt(blinkLED);  // Add blinkLED function to Timer1 interrupt
}
void loop()
 {
   int sensorValue ;
   unsigned long interval;
}
void readTemperature()
 {
  int sensorValue = analogRead(lm35Pin); // Read temperature from LM35 sensor
  temperature = map(sensorValue, 0, 1023, 0, 50);  // Map the sensor value to temperature range (0 to 50 degrees Celsius)
}
void blinkLED()
 {
  unsigned long interval = (temperature < 30) ? 250 : 500; // Determine LED blink interval based on temperature
  ledState = !ledState; // Toggle the LED state
  digitalWrite(ledPin, ledState);

  // Set up Timer1 for the next interval
  Timer1.setPeriod(interval * 1000);  // Convert milliseconds to microseconds
}