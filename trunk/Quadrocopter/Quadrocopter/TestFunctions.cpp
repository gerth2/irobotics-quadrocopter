#include "stdafx.h"
#include "Header.h"


int PWM_Time_Test(datalog * log)
{
	quadcopter copter; //local variable definitions
    joystick joystickin;
	int i;
	
	printf("will perform 500 writes to pwm values (0, 30 ,0 , 30, ...)\n");
    wait(3);
    copter.north_motor = 0; //initalize values
    copter.east_motor = 0;
    copter.west_motor = 0;
    copter.south_motor = 0;

    printf("writing...\n");
    for(i = 0; i < 250; i++)//loop for 500 total writes
    {
        copter.north_motor = 0;
        while(Set_Pwm(&copter) != 0) //write low with error checking
		{
			printf("bad PWM write on low write %d, retrying...\n", i);
		}
        copter.north_motor = 30;
        while(Set_Pwm(&copter) != 0) //write high with error checking
		{
			printf("bad PWM write on high write %d, retrying...\n", i);
		}
        printf("write cycle # %d\n",i);
		if(log != NULL)
			LogData(log, &copter, &joystickin);
    }

    printf("done!\n");
	return 0;
}

int PWM_Write_Test(datalog * log)
{
	 /*analog write test*/
	int north, south, east, west;//local variable definitions
	quadcopter copter;
    joystick joystickin;
	int i;


    printf("analog write test - ten writes will be performed\n");
    for(i = 0; i < 10; i++) //loop for ten times
    {
        printf("enter pwm values north, south, east, west"); //request values from user
        scanf("%d %d %d %d", &north, &south, &east, &west);
        copter.north_motor = north;
        copter.south_motor = south;
        copter.east_motor = east;
        copter.west_motor = west;
        while(Set_Pwm(&copter) != 0) //perform error check, write values to copter
		{
			printf("bad PWM write on loop %d, retrying...\n", i);
		}
		if(log != NULL) //log data if requested
			LogData(log, &copter, &joystickin);
    }
	return 0;
}

int Sensor_Read_Test(datalog * log)
{
	quadcopter copter; /*local var. definitions*/
    joystick joystickin;
	int i;
	 /*sensor read test*/
    printf("\nSensor Read test - will read 1000 times\n");
    wait(3); /*printf info and pause*/
    for(i = 0; i<1000; i++) /*loop through sensor reads*/
    {
        while(Read_Sensors(&copter) != 0 ) //loop while waiting for good results
		{
			printf("bad sensor read on loop %d, retrying....\n", i);
		}
        printf("\n\n======================\n"); //print out results
        printf("values read in:\n\n");
        printf("gyrox = %d\ngyroy = %d\ngyroz = %d\naccelx = %d\naccely = %d\naccelz = %d\naltitude = %d\nheading = %d\ntemperature = %d\n", copter.ang_vel_x, copter.ang_vel_y, copter.ang_vel_z, copter.accel_x, copter.accel_y, copter.accel_z, copter.height, copter.heading, copter.temperature);
        printf("\n======================\n\n");
		if(log != NULL) //log data if requested
			LogData(log, &copter, &joystickin);
    }
	return 0;
}

int Joystick_Read_Test(datalog * log)
{
	quadcopter copter; //local variable definitions
    joystick joystickin;
	int i;
	   /*joystick read test*/
    printf("\nJoystick Read test - will read 3000 times\n");
    wait(3);

    for(i = 0; i<3000; i++) //loop 3000 times
    {
        while(Read_Joystick(&joystickin) != 0 ) //read joystick values with error checking
		{
			printf("bad joystick read on loop %d, retrying...\n", i);
		}
        printf("\n\n======================\n"); //print out results
        printf("values read in:\n\n");
        printf("x axis = %d\ny axis = %d\nz axis = %d\nh axis = %d\nLeft Toggle = %d\nRight Toggle = %d\nLeft Slide = %d\nRight Slide = %d\n", joystickin.x, joystickin.y, joystickin.rotation, joystickin.altitude, joystickin.activate_height, joystickin.button1, joystickin.button2, joystickin.button3);
        printf("\n======================\n\n");
		if(log != NULL) //log data if requested
			LogData(log, &copter, &joystickin);
    }
	return 0;
}