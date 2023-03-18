#include <kipr/wombat.h>

//takes left, right, and msleep
void move(int l, int r, int t)
{
    create_drive_direct(l,r);
    msleep(t);
}

	//takes servo position and time
void servo(int a, int a_p, int a_t)
{
    set_servo_position(a,a_p);
    msleep(a_t);
    
}

	//turns left
void tl()
{
    set_create_total_angle(0);
   while(get_create_total_angle()<90)
   {
    printf("%d\n",get_create_total_angle());
    create_drive_direct(-100,100);
   }
    
}

	//turns right
void tr()
{
   set_create_total_angle(0);
   while(get_create_total_angle()>-90)
   {
       
    	create_drive_direct(100,-100);
   }
    
}

int claw = 1;
int arm = 0;

 
int main()
{ 
    
    create_connect();
    //robot off the line:2913. robot on the line:r.
   
    //wait_for_light(0);
    shut_down_in(112);
    set_create_distance(0);
    enable_servos(0);
    enable_servos(1);
    servo(arm,133,1000);
    servo(claw,1376,1000);
    
	//drive a bit
    move(100,100,4500);
    //turn right
    tr();
    msleep(1000);
    //drive forward until line
    while( (get_create_lfcliff_amt()>2000) || (get_create_rfcliff_amt()>2000) )
    { 
         if( (get_create_lfcliff_amt()<2000))
         {
             printf('turn right');
             move(-100,100,0);
         }
         
         else if( (get_create_rfcliff_amt()<2000) );
         {
             printf('turn left');
             move(100,-100,0);
         }
         
         if( (get_create_lfcliff_amt()>2000) && (get_create_rfcliff_amt()>2000) )
         {
             printf('move forward');
             move(100,100,0);
         }
     
     }
    //drive a bit
    move(100,100,800);
   
    //turn left
    tl();
    
    //drive forward till bump    
    while(get_create_lbump()== 0 && get_create_rbump()==0)
    {
        move(200,200,0);
    }
    //back up
    move(-100,-100,1000);
     //arms up
    servo(arm,1910,1000);
    servo(claw,1407,1000);
   
    create_disconnect();
    
    
    
    
    
    return 0;
}
