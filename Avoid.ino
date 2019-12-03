#include "Avoid.h"
#include "bluetooth_data.h"
#include "movements.h"

#include <TimerOne.h>       // (Tane et al.)


Avoid::Avoid()
{
  dist_to_obst = get_obsticle_dist();
  phone_dir = get_bluetooth_dir();
  phone_dist = get_bluetooht_dist();

  // These get the initial states of the relevent navigation data. Because they will be needed once the program-loop starts, leaving them un-initialized will
  // create a runtime-error.
}


void Avoid::go_around()
{
  left();
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


void Avoid::drive()
{
  if(dist_to_obst <= avoid_dist){go_around();}
  else if(dist_to_obst > avoid_dist && phone_dist >= rest_dist){go_to_phone();}
  else{rest();}

  // This selects one of three navigation conditions which could occur: obsticle to go-around; no obsticle; and arrived at destination.
}
