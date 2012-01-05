#pragma once
#include "stdafx.h"
#include "Header.h"


int PWM_Time_Test(datalog * log)
{
	quadcopter copter; //local variable definitions
    joystick joystickin;
	unsigned long int starttime, endtime;
	unsigned int errorcount = 0;
	int i;
	
	printf("will perform 500 writes to pwm values (0, 255 ,0 , 255, ...)\n");
    wait(3);
    copter.north_motor = 0; //initalize values
    copter.east_motor = 0;
    copter.west_motor = 0;
    copter.south_motor = 0;

	
    printf("writing...\n");
	errorcount = 0;
	starttime = clock();
    for(i = 0; i < 250; i++)//loop for 500 total writes
    {
        copter.north_motor = 0;
		copter.south_motor = 0;
		copter.east_motor = 0;
		copter.west_motor = 0;
        while(Set_Pwm(&copter) < 0) //write low with error checking
		{
			errorcount++;
			printf("bad PWM write on low write %d, retrying...\n", i);
		}
        copter.north_motor = 255;
		copter.south_motor = 255;
		copter.east_motor = 255;
		copter.west_motor = 255;

        while(Set_Pwm(&copter) < 0) //write high with error checking
		{
			errorcount++;
			printf("bad PWM write on high write %d, retrying...\n", i);
		}
        printf("write cycle # %d\n",i);
		if(log != NULL) //write data to log if applicable
			LogData(log, &copter, &joystickin);
//		Form1.toolStripProgressBar1->Value = i*100/250;
    }

	endtime = clock();

	printf("\n\n\n");
	printf("===============================\n");
	printf("==========Test Results=========\n");
	printf("===============================\n");
	printf("Time elapsed = %d ms\n", (int)(endtime - starttime));
	printf("Writes per second = %lf\n", (double)((double)1000 * (double)500.0 / (double)(endtime-starttime)));
	printf("Errors = %d\n", errorcount);
	printf("Error Probability = %lf percent\n", (double)((double)errorcount/(double)500 * (double)100));
	printf("===============================\n");

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
		if(north > 255 || south > 255 || east > 255 || west > 255 || north < 0 || south < 0 || east < 0 || west < 0)
		{
			printf("invalid input\n");
			continue;
		}
        copter.north_motor = north;
        copter.south_motor = south;
        copter.east_motor = east;
        copter.west_motor = west;
        while(Set_Pwm(&copter) < 0 ) //perform error check, write values to copter
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
	_beginthread( &Sensor_Test_Thread, 0, (void*)log);
	return 0;

}

void _cdecl Sensor_Test_Thread(void * input)
{
	quadcopter copter; /*local var. definitions*/
    joystick joystickin;
	int i;
	datalog * log;
	double startclock = 0, endclock = 0;
	unsigned int badpackets = 0;
	 /*sensor read test*/

	log = (datalog *) input;
    printf("\nSensor Read test - will read 1000 times\n");
    wait(3); /*printf info and pause*/
	startclock = clock();
    for(i = 0; i<1000; i++) /*loop through sensor reads*/
    {
		log->progress = ((float)i / 10);
        while(Read_Sensors(&copter) != 0 ) //loop while waiting for good results
		{
			badpackets++;
			printf("bad sensor read on loop %d, retrying....\n", i);
			if( (int)log->KillTestThread == 1 || (int)log->KillAllThreads == 1)//check to see if exit flag is high
			{
				printf("Thread exiting due to exterior exit signal\n");
				log->KillTestThread = 0;
				log->TestThreadRunning = 0;
				_endthread();
			}
		}
        printf("\n\n======================\n"); //print out results
		printf("loop %d\n", i);
        printf("values read in:\n\n");
        printf("gyrox = %d\ngyroy = %d\ngyroz = %d\naccelx = %d\naccely = %d\naccelz = %d\naltitude = %d\nheading = %d\nmagno x = %d\nmagno y = %d\nmagno z = %d\ntemperature = %d\n", copter.ang_vel_x, copter.ang_vel_y, copter.ang_vel_z, copter.accel_x, copter.accel_y, copter.accel_z, copter.height, copter.heading, copter.magno_x, copter.magno_y, copter.magno_z, copter.temperature);
        printf("\n======================\n\n");
		if(log->enabledatalogging != 0) //log data if requested
			LogData(log, &copter, &joystickin);
		if(log->KillTestThread == 1 || (int)log->KillAllThreads == 1)// check to see if exit flag is high.
		{
			printf("Thread exiting due to exterior exit signal\n");
			log->KillTestThread = 0;
			log->TestThreadRunning = 0;
			_endthread();
		}

    }
	endclock = clock();
	
	//print out test results
	printf("\n\n\n\n\n================================\n");
	printf("================================\n");
	printf("==========Test Results==========\n");
	printf("================================\n\n");
	printf("Time elapsed = %lf ms\n", (double)(endclock-startclock));
	printf("Reads/Second = %lf\n\n", (double)((double)1000/(endclock-startclock)*(double)1000));
	printf("Bad packets = %d\n", badpackets);
	printf("error probablility = %lf percent \n", (double)((double)badpackets/(double)1000)*100);
	printf("================================\n\n");
	
		if(log->enabledatalogging)
		EndDataLogging(log);
	_endthread();
	log->progress = 0;
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
		printf("loop %d\n", i);
        printf("values read in:\n\n");
        printf("x axis = %d\ny axis = %d\nz axis = %d\nh axis = %d\nLeft Toggle = %d\nRight Toggle = %d\nLeft Slide = %d\nRight Slide = %d\n", joystickin.x, joystickin.y, joystickin.rotation, joystickin.altitude, joystickin.activate_height, joystickin.button1, joystickin.button2, joystickin.button3);
        printf("\n======================\n\n");
		if(log != NULL) //log data if requested
			LogData(log, &copter, &joystickin);

    }
	return 0;
}


int Gyro_Read_Test(datalog * log)
{
	quadcopter copter; /*local var. definitions*/
    joystick joystickin;
	int i;
	 /*sensor read test*/
    printf("\nGyro Read test - will read only the gyroscope 1000 times\n");
    wait(3); /*printf info and pause*/
    for(i = 0; i<1000; i++) /*loop through sensor reads*/
    {
        while(Read_Gyro(&copter) != 0 ) //loop while waiting for good results
		{
			printf("bad sensor read on loop %d, retrying....\n", i);
		}
        printf("\n\n======================\n"); //print out results
		printf("loop %d\n", i);
        printf("values read in:\n\n");
        printf("gyrox = %d\ngyroy = %d\ngyroz = %d\n", copter.ang_vel_x, copter.ang_vel_y, copter.ang_vel_z);
        printf("\n======================\n\n");
		if(log != NULL) //log data if requested
			LogData(log, &copter, &joystickin);

    }
	return 0;
}

int Magno_Read_Test(datalog * log)
{
	quadcopter copter; /*local var. definitions*/
    joystick joystickin;
	int i;
	 /*sensor read test*/
    printf("\nMagno Read test - will read only the magnometer 1000 times\n");
    wait(3); /*printf info and pause*/
    for(i = 0; i<1000; i++) /*loop through sensor reads*/
    {
        while(Read_Magno(&copter) != 0 ) //loop while waiting for good results
		{
			printf("bad sensor read on loop %d, retrying....\n", i);
		}
        printf("\n\n======================\n"); //print out results
		printf("loop %d\n", i);
        printf("values read in:\n\n");
        printf("magnox = %d\nmagnoy = %d\nmganoz = %d\n", copter.magno_x, copter.magno_y, copter.magno_z);
        printf("\n======================\n\n");
		if(log != NULL) //log data if requested
			LogData(log, &copter, &joystickin);

    }
	return 0;
}