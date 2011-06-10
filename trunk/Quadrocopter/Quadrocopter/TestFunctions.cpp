#include "stdafx.h"
#include "Header.h"


int PWM_Time_Test(void)
{
	quadcopter copter;
    joystick joystickin;
	int i;
	printf("will perform 500 writes to pwm values (0, 30 ,0 , 30, ...)\n");
    wait(3);
    copter.north_motor = 0;
    copter.east_motor = 0;
    copter.west_motor = 0;
    copter.south_motor = 0;

    printf("writing...\n");
    for(i = 0; i < 250; i++)
    {
        copter.north_motor = 0;
        Set_Pwm(&copter);
        copter.north_motor = 30;
        Set_Pwm(&copter);
        printf("write cycle # %d\n",i);
    }

    printf("done!\n");
	return 0;
}

int PWM_Write_Test(void)
{
	 /*analog write test*/
	int north, south, east, west;
	quadcopter copter;
    joystick joystickin;
	int i;


    printf("analog write test - ten writes will be performed\n");
    for(i = 0; i < 10; i++)
    {
        printf("enter pwm values north, south, east, west");
        scanf("%d %d %d %d", &north, &south, &east, &west);
        copter.north_motor = north;
        copter.south_motor = south;
        copter.east_motor = east;
        copter.west_motor = west;
        Set_Pwm(&copter);
    }
	return 0;
}

int Sensor_Read_Test(void)
{
	quadcopter copter;
    joystick joystickin;
	int i;
	 /*sensor read test*/
    printf("\nSensor Read test - will read 1000 times\n");
    wait(3);
    for(i = 0; i<1000; i++)
    {
        Read_Sensors(&copter);
        printf("\n\n======================\n");
        printf("values read in:\n\n");
        printf("gyrox = %d\ngyroy = %d\ngyroz = %d\naccelx = %d\naccely = %d\naccelz = %d\naltitude = %d\nheading = %d\ntemperature = %d\n", copter.ang_vel_x, copter.ang_vel_y, copter.ang_vel_z, copter.accel_x, copter.accel_y, copter.accel_z, copter.height, copter.heading, copter.temperature);
        printf("\n======================\n\n");
    }
	return 0;
}

int Joystick_Read_Test(void)
{
	quadcopter copter;
    joystick joystickin;
	int i;
	   /*joystick read test*/
    printf("\nJoystick Read test - will read 3000 times\n");
    wait(3);
    for(i = 0; i<3000; i++)
    {
        Read_Joystick(&joystickin);
        printf("\n\n======================\n");
        printf("values read in:\n\n");
        printf("x axis = %d\ny axis = %d\nz axis = %d\nh axis = %d\nLeft Toggle = %d\nRight Toggle = %d\nLeft Slide = %d\nRight Slide = %d\n", joystickin.x, joystickin.y, joystickin.rotation, joystickin.altitude, joystickin.activate_height, joystickin.button1, joystickin.button2, joystickin.button3);
        printf("\n======================\n\n");
    }
	return 0;
}