
//Method for main motorDriver


namespace ArduinoCar{

  class MotorDriver{

  public:

  //Changes the motor speed
  //Positive and Negative/Zero are used
  
  virtual void setSpeed(int speed) =0;

    //Return the current speed of the motor
    //Between -255 and 255

  virtual int getSpeed() const=0;
  };
};
