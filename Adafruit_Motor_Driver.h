//for adafruit motor shield

#include "Motor_Driver.h"

namespace ArduinoCar{

  class Motor: public MotorDriver{

    public:
//class constructor

  Motor(int number): MotorDriver(), motor(number), currentSpeed(0){    
  }

  void setSpeed(int speed){
    currentSpeed = speed;

    if(speed>=0){
      motor.setSpeed(speed);
      motor.run(FORWARD);
    }
    else{
      motor.setSpeed(-speed);
      motor.run(BACKWARD);
    }
  }

  int getSpeed() const
  {
    return currentSpeed;
  }

  private:

  AF_DCMotor motor;
  int currentSpeed;
  };
};
