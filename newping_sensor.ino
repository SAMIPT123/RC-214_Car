
//Make a sub class and include the parent class
#include "Distance_Sensor"

namespace ArduinoCar{

class DistanceSensor : public DistanceSensorDriver{

  public: 
  DistanceSensor(int triggerPin, int echoPin, int maxDistance)
    :DistanceSensorDriver(maxDistance),
      sonar(triggerPin, echoPin, maxDistance){
  }

  virtual unsigned int getDistance(){

    int distance=sonar.ping_cm();
    if(distance<=0) 
      return maxDistance;
    return distance;
  }
  private:
  NewPing sonar;
};
  
};
