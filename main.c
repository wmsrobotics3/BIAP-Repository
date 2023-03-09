#include <kipr/wombat.h>
#include <stdlib.h>
/*This means this function will accept two numbers, one is distance the other speed*/

/* set_create_distance means the robot will set the number of registered ticks to 0. 
This is important to if you were to make the robot move more than once.*/

/*On the next line, it says while the distance is less than the distance set, it will move until that point. */

/*The next two lines make sure the robot is accurate to your directions */

void drive/*name*/(int distance, int speed)
{
    set_create_distance(0);
    while (abs(get_create_distance()) < distance)
    {
        create_drive_direct(speed,speed);
        
    }
    create_drive_direct(0,0);
    msleep(34);
}


/*create_drive_direct(-speed, speed) means the robot will mean that the robot's wheels will turn two different directions  */
void turn_left(int distance, int speed){
 set_create_total_angle(0);
    while (get_create_total_angle() < distance){
    
     create_drive_direct(-speed,speed);            
    }

    create_drive_direct(0,0);
    msleep(34);
    
}

void turn_right(int distance,int speed){
    
 set_create_total_angle(0);
    
    while (get_create_total_angle() < distance){
     
        create_drive_direct(speed,-speed);      
    }
    create_drive_direct(0,0);
    msleep(34);
}


/* get_create_rfcliff_amt refers to a sensor on the Create bot that can detect black and white. 
Here, it says if the Create bot detects a color lower than 1690, a dark color, it will do the following */

/**/

void line_follow(int distance, int speed){
 set_create_distance(0);
 while (abs(get_create_distance()) < distance){
  if (get_create_rfcliff_amt() < 1690){
   create_drive_direct(speed-25,speed+25);
  }
  if (get_create_rfcliff_amt() > 1690){
      create_drive_direct(speed+25,speed-25);   
  }
  }
}
    

    
    
 



int main()
{
    create_connect();
    
    
	

    
    
    
    
    
    
    
    create_disconnect();
    return 0;
}
