#include <kipr/wombat.h>
#include <stdlib.h>

void drive(int distance, int speed){
    set_create_distance(0);
    while (abs(get_create_distance()) < distance){
        create_drive_direct(speed,speed);
        
    }
    create_drive_direct(0,0);
    msleep(34);
    }
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

void line_follow(int distance, int speed){
 set_create_distance(0);
 while (abs(get_create_distance()) < distance){
  if (get_create_rfcliff_amt() < 1690){
   create_drive_direct(speed-25,speed+25);
  }
  if (get_create_rfcliff_amt() < 1690){
      create_drive_direct(speed+25,speed-25);   
  }
  }
}
    

    
    
 



int main()
{
   create_connect();
   printf("biap");
    
    
	drive(1000,500);

    
    
    
    
    
    
    
    create_disconnect();
    return 0;
}
