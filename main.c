#include <kipr/wombat.h>
#include <stdlib.h>
/*cmpc(0); clears the position of the motor 0, or whatever port is in the ().
This is important because if we don't clear it every time we use this function the wombat/wallaby will not move. */

/*gmpc, or get_motor_position_counter checks the position of the motor */

/*abs means that the robot will move in the way that we want it to*/

/*This means that the robot will keep moving, assuming that it's position is greater than the distance we set */

/* mav stands for move at velocity. This is important because it tends to be more precise.
values for mav is -1500 to 1500*/

void drive (int distance,int velocity){
 cmpc(0);
 while (abs(gmpc(0)) < distance){
  mav(0,velocity);
  mav(1,velocity+10);
 }
 mav(0,0);
 mav(1,0);
 msleep(34);
}																						


void turn_right (int distance,int velocity){
 cmpc(0);
 while (abs(gmpc(0)) < distance){
  mav(0, velocity);
  mav(1,-velocity);
 }
 mav(0,0);
 mav(1,0);
 msleep(34);
}


void turn_left (int distance,int velocity){
 cmpc(0);
 while (abs(gmpc(0)) < distance){
  printf("%d\n", gmpc(0));
  mav(0,-velocity);
  mav(1, velocity);
 }
 mav(0,0);
 mav(1,0);
 msleep(34);
}

void wait(int time)
{
 mav(0,0);
 mav(1,0);
 msleep(time);
}


void line_follow(int distance, int velocity){
 cmpc(0);
 while (abs(gmpc(0)) < distance){
  if (analog(0) < 1650){
   mav(0,1000);
   mav(1,500);
  }
  if (analog(0) > 1650){
   mav(0,500);
   mav(1,1000);
  }
   mav(0,0);
   mav(1,0);
   msleep(34);   
 }
}

void servo( int port, int target_position, int pause_time)
{
 int current_position = get_servo_position(port);
  while (current_position != target_position)
  {
      if (current_position < target_position) 
      {
          current_position++;
      }
      else 
      {
          current_position--; 
      }

      set_servo_position(port, current_position);
      msleep(pause_time);
  }
}
int arm_center = 320;//arm is port 0
int arm_left = 784;
int arm_right =10;

int claw_close = 1262; // claw is port 1
int claw_open = 1208;
 // port 0 is left
 // port 1 is right





int main()
{
	enable_servos();
    set_servo_position(1,claw_close);
    msleep(100);
    turn_left(1200, 1000);//from starting box turning a 90* angle turn
    servo(0,300,3.5);
    msleep(100);
    
    drive(9350, 800);//drives foward for apporxiamtely 7300 ticks
    
    turn_right(1100,6500);//turns right from roomba starting box
    drive(1920,1000);//drives foward to align itself with the black line in order to line follow(facing foward)
    while (analog(0) < 500)
    {
       mav(0, 650);
       mav(1,-650);
    }
    mav(0,0);
    mav(1,0);
    msleep(34);
   
    //turn_left(260,100);
    
    drive(1990, 1000); // meets second red pom 
    servo(0,arm_left, 3.5); // prepares the arm to sort the green pom
    
    drive(1990, 1000); // drives forward to collect green pom. 
    servo(0, arm_right, 3.5); // prepares the arm to sort the red poms
    
    drive(1990, 1000); // meets second red pom 
    servo(0,arm_left, 3.5); // prepares the arm to sort the green poms
    
    drive(1990, 1000); // drives forward to collect green pom. 
    servo(0, arm_right, 3.5); // prepares the arm to sort the red pom
        
    turn_right(150,500);
    
    drive(1990, 1000); // meets second red pom 
    servo(0,arm_left, 3.5); // prepares the arm to sort the green pom.     
   
    // the way the arm moves is in this order 
    // straight, left, right, left, right, left, after is the two poms that need to be sorted.
    
    
   
   
    
    return 0;
}
