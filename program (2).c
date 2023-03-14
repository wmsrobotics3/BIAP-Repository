#include <stdio.h>
#include <kipr/wombat.h>

int main()
{
  printf("Hello, World!\n");
  
  int L=0;
  int R=3;
  enable_servo(0);

set_servo_position(0,1000);
 //drives into blue box
 msleep(1000); 
 
 motor(L,100);
 motor(R,100);
 msleep(5000);

 motor(L,-100);
 motor(R,100);
 msleep(400);

 motor(L,100);
 motor(R,100);
 msleep(1800);

motor(L,0);
motor(R,0);

// make it go to orenge
 set_servo_position(0,2000);

 msleep(1000);

 motor(L,-100);
 motor(R,-100);
 msleep(2000);

 motor(L,100);
 motor(R,-100);
 msleep(400);

 motor(L,100);
 motor(R,-100);
 msleep(300);

 motor(L,100);
 motor(R,100);
 msleep(1500);
 
 motor(L,100);
 motor(R,100);
 msleep(100);

 return 0;}
