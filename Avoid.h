# ifndef AVOID_H
# define AVOID_H


class Avoid
{
  private:
    float dist_to_obst;
    float phone_dist;
    float phone_dir; // Mesured in feet


    const float rest_dist = 2;        // This is the distance(measured in feet) from the phone at which the car will stop moving.
    const float avoid_dist = 2;       // This is the distance from an obsticle in the way that the car will be at when it switches modes to avoid the obsticle.
    const float phone_dir_max = 2;    // This is the max size of the angle, in degrees, of error for the car's direction to be off from the direction to the phone.
    const float phone_dir_min = -2;   // This is the min size of the angle, in degrees, of error for the car's direction to be off from the direction to the phone.



    // These are the movement-modes for the car; they determine what the car is doing
    void go_to_phone();
    void go_around();
    void rest();
    // These are the movement-modes for the car; they determine what the car is doing
    
    void drive_around();
    

  public:
    void drive();  // This method will be called repeatedly in order to select a navigation-mode every so-many cycles.
    Avoid();    // This is the constructor.
};



#endif
