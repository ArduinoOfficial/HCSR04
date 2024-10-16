#include "UltrasonicSensor.h"

// Constructor
UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin) {
  _triggerPin = triggerPin;
  _echoPin = echoPin;
}

// Initialize the sensor
void UltrasonicSensor::begin() {
  pinMode(_triggerPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

// Get distance in centimeters
float UltrasonicSensor::getDistanceCM() {
  // Clear the trigger
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond pulse to trigger
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_triggerPin, LOW);

  // Read the echo pin
  long duration = pulseIn(_echoPin, HIGH);

  // Calculate distance in cm (speed of sound = 34000 cm/s)
  float distanceCM = (duration / 2.0) * 0.0343;

  return distanceCM;
}
