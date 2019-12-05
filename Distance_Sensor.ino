
//Method to report the distance to the nearest object


namespace ArduinoCar{

  class DistanceSensorDriver{

  public:

  //Return the ditance to the nearest obstacle
  
  DistanceSensorDriver(unsigned int distance): maxDistance(distance){}

  //Returns maxDistance if there is no object detection
  
  virtual unsigned int getDistance()=0;

    //accessible to subclasses
    protected:

    unsigned int maxDistance;
  };
};
