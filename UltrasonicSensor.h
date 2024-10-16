#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h

#include "Arduino.h"

class UltrasonicSensor {
  public:
    // Constructor
    UltrasonicSensor(int triggerPin, int echoPin);

    // Initialize the sensor
    void begin();

    // Get distance in centimeters
    float getDistanceCM();

  private:
    int _triggerPin;
    int _echoPin;
};

#endif
