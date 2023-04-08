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
  mav(1,velocity+15);
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
int arm = 0;
int arm_center = 320;//arm is port 0
int arm_left = 784;
int arm_right =0;

int claw = 1;
int claw_close = 2047; // claw is port 1
int claw_open = 0;
 // port 0 is left
 // port 1 is right
int left_wheel = 0;
int right_wheel = 1;

int left = 1200;
int right = 1200;
int black_line = 1600;
int white_line = 300;
int main()
{
	enable_servos();
   
    set_servo_position(1,claw_close);
    msleep(100);
    servo(0,320,3.5);
    turn_left(1150, 1000);//from starting box turning a 90* angle turn (step 1) 1240
    msleep(100);
    
   drive(9400, 1000);//drives foward for apporxiamtely 9600 ticks(step 2)
    
   turn_right(1070,650);//turns right from roomba starting box
    
   drive(1790,1000);//drives foward to align itself with the black line in order to line follow(facing foward)

  
    mav(0,0);
    mav(1,0);
    msleep(34);
    wait(100);
    
   drive(300,650);//300

   turn_right(1100,1000);//turns right on the black line
   
 
   servo(arm,arm_right,1);
    
   drive(1900, 1000); // meets second red pom (1990)
   servo(0,arm_left, 1.5); // prepares the arm to sort the green pom
    
   drive(1900, 1000); // drives forward to collect green pom. 
   servo(0, arm_right, 1.5); // prepares the arm to sort the red poms

   drive(1900, 1000); // meets second red pom 
   servo(0,arm_left, 1.5); // prepares the arm to sort the green poms
   
    /*while (analog(0) < white_line)
    {
     mav( right_wheel,-650);
     mav(left_wheel,650);
    }*/
    //turn_left(20,650);
    
   drive(1900, 1500); // drives forward to collect green pom. 
   servo(0, arm_right, 1.5); // prepares the arm to sort the red pom
   
    turn_left(20,650);
   
   
   drive(1900, 1000); // meets second red pom 
   servo(0,arm_left, 1.5); // prepares the arm to sort the green pom.     
   
   servo(claw, claw_open, 0.1);
   drive(1800, 650); // drives forward to collect green pom. 

   wait(100);
    
   servo(arm, 439 , 1);//576
   drive(290,650);
   wait(500);
   drive(25,1000);
   servo(claw, claw_close, 1);
   set_servo_position(claw,claw_close);
   msleep(100);
   
   
   
    
    return 0;
}
