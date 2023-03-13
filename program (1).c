#include <stdio.h>
#include <kipr/wombat.h>

int main()
{ 
  printf("Hello, World!\n");
 enable_servo(0);

set_servo_position(0,1000);
 //drives into blue box
 msleep(2000); 
 
 motor(0,100);
 motor(3,100);
 msleep(5000);

 motor(0,-100);
 motor(3,100);
 msleep(400);

 motor(0,100);
 motor(3,100);
 msleep(1800);

motor(0,0);
motor(3,0);

 set_servo_position(0,2000);

 msleep(2000);
 return 0;
 
}
