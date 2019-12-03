#include "Avoid.h"
#include "bluetooth_data.h"
#include "movements.h"
#include "ultra_sonic_data.h"

#include <TimerOne.h>       // (Tane et al.)


Avoid::Avoid()
{
  set_dist_to_obst();
  set_phone_dist();
  set_phone_dir();

  // These get the initial states of the relevent navigation data. Because they will be needed once the program-loop starts, leaving them un-initialized will
  // create a runtime-error.
}


void Avoid::drive()
{
  set_dist_to_obst();
  set_phone_dist();
  set_phone_dir(); // Updates the navigation-data.

  if(dist_to_obst <= avoid_dist){go_around();}
  else if(dist_to_obst > avoid_dist && phone_dist >= rest_dist){go_to_phone();}
  else{rest();}

  // This selects one of three navigation conditions which could occur: obsticle to go-around; no obsticle; and arrived at destination.
}


void Avoid::go_around()
{
  halt();
  delay(250);   // This lets us know that the car detected the object.
  
  left();
  delay(500);   // The car is fast--a half-second should be enough for it to get around it's obsticle.

  forwords();
  delay(1000);  // This moves the car along the "up-leg" of the avoid pattern
}

void Avoid::go_to_phone()
{
  if(phone_dir > 2){left();}
  else if(phone_dir < -2){right();}
  else{forwords();}
}


void Avoid::rest()
{
  halt();
}



// Getter and setter methods-----------------------------------------------------------------------
void Avoid::set_dist_to_obst(){dist_to_obst = get_obsticle_dist();}
void Avoid::set_phone_dist(){phone_dist = get_bluetooht_dist();}
void Avoid::set_phone_dir(){get_bluetooth_dir();}
// Getter and setter methods-----------------------------------------------------------------------
