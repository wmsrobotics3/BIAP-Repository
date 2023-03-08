#include <stdio.h>
#include <kipr/wombat.h>



int main()
{
  motor(0, 100);
  motor(3, 100);
  msleep(3000);


  mav(0, -1000);
  mav(3, 0);
  msleep (2850);
  //  Turn left
  motor(0, 100);
  motor(3, 100);
  msleep(4000);
  
  // Drive forward
  
  // Turn right to get onto line
  
  //
  return 0;
}

