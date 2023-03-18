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
    while (abs(get_create_total_angle()) < distance){

        create_drive_direct(-speed,speed);            
    }

    create_drive_direct(0,0);
    msleep(34);

}

void turn_right(int distance,int speed){

    set_create_total_angle(0);

    while (abs(get_create_total_angle()) < distance){

        create_drive_direct(speed,-speed);      
    }
    create_drive_direct(0,0);
    msleep(34);
}


/* get_create_rfcliff_amt refers to a sensor on the Create bot that can detect black and white. 
Here, it says if the Create bot detects a color lower than 1690, a dark color, it will do the following */

/**/

void wait(int time)
{
    create_drive_direct(0,0);
    msleep(time);
}


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
int claw_open = 524;
int claw_close = 2047;

int arm_up = 1678;
int arm_middle = 1035;
int arm_down = 0;








int main()
{
    create_connect();
    enable_servos();
    set_servo_position(1,arm_up);
    msleep(50);
    set_servo_position(0,claw_close);
    msleep(100);
    drive(80,-90);
    turn_right(90,50);
    wait(100);
    set_servo_position(1,arm_down);
    msleep(1);
    turn_left(1,50);
    turn_left(64,50);
    set_servo_position(0,claw_open);
    drive(350,100);
 
   
  




    create_disconnect();
    return 0;
}
