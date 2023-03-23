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
int claw_close = 2047;//1 is claw

int arm_up = 2047;
int arm_middle = 1441;
int arm_down = 0;//0 is arm


void servos(int port,int target_position, int pause_time)
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





int main()
{
    create_connect();
    printf("Roomba connected successfully\n");
    enable_servos();
    set_servo_position(0,arm_up);
    msleep(50);

    /* alternative 1, rings aren't moved and are scored with the Roomba in the Data Center

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
 	*/

    // alternative 2, rings are moved to the bottom left corner of the analysis lab
    drive (500, 600);
    turn_right (93, 70);
    while (get_create_rbump() ==0 && get_create_lbump() == 0)
           {
           	create_drive_direct(400,400);
        	msleep(100);
           }  
    // drive(1925, 275);
    turn_right(52, 70);
    /*servos(0,arm_down,1);
    msleep(1000);*/
   drive(1000,-500);
    
    wait(100);





    create_disconnect();
    return 0;
}
