#pragma once
/* This file contains all the hardware io functions*/

#include "stdafx.h"
#include "Header.h"

/*function to cause pauses in the program execution*/
void wait(float s)
{
    clock_t endwait;//variable definition
    endwait = (float)clock()+s*1000;// determine time to end at (current time + requested wait)
    while (clock() < endwait) //main wait loop
    { //hold and do nada
    }

}

/*hardware setup*/

int Initalize_Hardware(void)
{ 

    /*print out some official-looking stuff for coolness factor*/
    printf("\n\n==================================================================\n");
    printf(    "===            IEEE MIDTERMINATORS QUADCOPTER - v2.3           ===\n");
    printf(    "===                                                            ===\n");
    printf(    "===    Hardware Design and Interface Software - Chris Gerth    ===\n");
    printf(    "===        Software and PID Algorithm - Michael Vilim          ===\n");
    printf(    "===    Consulting and Overall Awesomeness - Robby Regalbuto    ===\n");
    printf(    "==================================================================\n");
    printf(    "===                    ---Sponsors---                          ===\n");
    printf(    "===                    --------------                          ===\n");
    printf(    "===                       UIUC IEEE                            ===\n");
	printf(    "===                      Caterpillar                           ===\n");
	printf(    "===             Illinois Robotics Organization                 ===\n");
    printf(    "==================================================================\n\n\n");

    printf("\ninitalizing hardware....\n");
    /*open the three required comports, check for errors*/
	/*these are virtual serial ports assigned by the windows OS to all */
	/*USB devices which request a serial port. each device is awarded a unique comport.*/
	/*you will need to change the comports as the software is ported between computers.*/
    int errorcode = 0;
    if(OpenComport(coptercomport, BAUDRATE))
    {
        printf("-- to computer-side Xbee radio\n");
        errorcode--;
    }

  /*  if(OpenComport(wiredcomport, BAUDRATE))
    {
        printf("-- to quadcopter wired interface\n");
        errorcode--;
    }
	*/
    if(OpenComport(joystickcomport, BAUDRATE))
    {
        printf("-- to Joystick Input Arduino\n");
        errorcode--;
    }

    /*execute copter-side setup by sending setup command via serial*/
	/*no error checking currently possible*/
    SendByte(coptercomport, 's');
	wait(.5);
 /*   if(SetMaxDeltaMotors(MAXDELTAMOTORS)) //set up default maxdeltamotors value, check for error
    {
        printf("initalization not completed successfully \n");
        return -1;
    }*/
    printf("initalization complete!\n\n"); //return success
    return errorcode; //return number of unopened comports. Under normal operation, this should be -1.


}

int Set_Pwm(quadcopter * copter)
{
    int north, south, east, west; //local variable definitons
    unsigned long int i, checksum;
    unsigned char errorbuf[10];
    unsigned char outbuff[4];
    memset(errorbuf, '\0', sizeof(unsigned char)*10); //clear out buffers
    memset(outbuff, '\0', sizeof(unsigned char)*4);

    SendByte(coptercomport, 'w'); // send pwm write command to copter
							 // copter is now preparing to recieve values from computer

    north = copter->north_motor; //extract values from structure
    south = copter->south_motor;
    east = copter->east_motor;
    west = copter->west_motor;

    /*ensure proper input range (all inputs need to be between 0 and 255 inclusive)*/
    if(north > 255 || north < 0 || south > 255 || south < 0 || east > 255 || east < 0 || west > 255 || west < 0)
    {
        printf("ERROR - attempt to write a pwm value out of valid range (0-255)\n");
        return -2;
    }

    /*convert values to proper range so ESC's recognize them*/
	/*these ranges are hardcoded, defined as UPPERLIMIT and LOWERLIMIT in Header.h*/
    north = (float)north * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    north = (int)north + LOWERLIMIT;
    south = (float)south * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    south = (int)south + LOWERLIMIT;
    east = (float)east * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    east = (int)east + LOWERLIMIT;
    west = (float)west * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    west = (int)west + LOWERLIMIT;

	checksum = (north %10 + south%10 + east%10 + west%10);

    #ifdef DEBUGPRINTS /*print out additional debugging information, if requested*/
    printf("values written:\n");
    printf("north = %d\n", north);
    printf("south = %d\n", south);
    printf("east  = %d\n", east);
    printf("west  = %d\n", west);
	printf("checksum = %d\n", checksum);
    #endif

    /*send bytes and perform error checking*/
    if(SendByte(coptercomport, (char)north))
        printf("error in tranmission of PWM value\n");
    wait(PWM_WRITE_DELAY); //delay to account for difference in processor speeds
    if(SendByte(coptercomport, (char)south))
        printf("error in tranmission of PWM value\n");
    wait(PWM_WRITE_DELAY);
    if(SendByte(coptercomport, (char)east))
        printf("error in tranmission of PWM value\n");
    wait(PWM_WRITE_DELAY);
    if(SendByte(coptercomport, (char)west))
        printf("error in tranmission of PWM value\n");
	wait(PWM_WRITE_DELAY);
	if(SendByte(coptercomport, (char)checksum))
		printf("error in transmisison of checksum\n");

    for(i = 0; i <1000000; i++) /*wait some arbitrairly large time for success signal before continuing*/
    {
        memset(errorbuf, '\0', sizeof(unsigned char)*10);
        PollComport(coptercomport, errorbuf, sizeof(unsigned char)*10); /*verify confirmation of sucessful write*/
        if(errorbuf[0] == 'd') /*case - confirmation character successfully recieved. PWM values have been written*/
        {
            #ifdef DEBUGPRINTS //print out additional debugging info if requested
            printf("errorbuff = %d %d %d %d %d\n", errorbuf[0], errorbuf[1], errorbuf[2], errorbuf[3], errorbuf[4]);
            #endif
            return 0; //return success
        }
		if(errorbuf[0] == 'e') //case - recieved write request was too large to be written, output changed by MAXDELTAMOTORS
		{
			printf("Checksum Error detected, motor values not written.\n");
			return -3; //return approprate message
		}
		if(errorbuf[0] == 't')
		{
			printf("Copter-side Timeout on PWM write, motor vals not written.\n");
			return -4;
		}
    }

    #ifdef DEBUGPRINTS /*print out additional debugging information, if requested*/
	/*case - confirmation character not recieved. PWM values may not have been properly written*/
    printf("errorbuff = %d %d %d %d %d\n", errorbuf[0], errorbuf[1], errorbuf[2], errorbuf[3], errorbuf[4]);
    #endif
    printf("timeout on pwm write\n");
    return -1;

}


int Read_Sensors(quadcopter *copter)
{
    unsigned char inbuffer[100]; /*recieves serial from arduino*/
    const char *valueinastring;
	char * context; // helps strtok_s keep track of where it is in the string it is parsing
	long unsigned int checksum=0;
	long unsigned int localchecksum = 1;

	SendByte(coptercomport, 'r'); /*request sensor values*/
	memset(inbuffer, '\0', sizeof(unsigned char)*100); //clear input buffer
	wait(SENSOR_READ_DELAY); /*wait for data to be read and sent*/

	PollComport(coptercomport, inbuffer, sizeof(unsigned char)*100); /*read in serial data*/

	/*data is recieved in the following format - (data):(data):(data):(data):...*/
	/*where each (data) is an ascii string represinting the inputted value*/
	/*the funciton strtok_s searches for the : and parses the string accordingly*/
	/*the function atoi changes the parsed ascii values to decimal integers*/

	/*Note: as of 9/3/2011, a checksum system is used for error detection*/

	/*read gyrox data*/
	valueinastring = strtok_s((char *)inbuffer, ":", &context);
	if(valueinastring == NULL) // check for a lack of a : (usually an indicator of a bad input string)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->ang_vel_x = atoi(valueinastring); //write integer value to the structure
    
	/*read gyroy data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->ang_vel_y = atoi(valueinastring);
    
	/*read gyroz data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->ang_vel_z = atoi(valueinastring);


	/*read accelx data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->accel_x = atoi(valueinastring);
    
	/*read accely data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->accel_y = atoi(valueinastring);
    
	/*read accelz data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->accel_z = atoi(valueinastring);


	/*read altitude data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->height = atoi(valueinastring);

	/*read magno x data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->magno_x = atoi(valueinastring);
    
	/*read magno y data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->magno_y = atoi(valueinastring);

	/*read magno z data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->magno_z = atoi(valueinastring);
    
	/*read heading data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->heading = atoi(valueinastring);
    
	/*read checksum data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	checksum = atoi(valueinastring);

	//calculate the value that the checksum ought to be
	localchecksum = (abs(copter->ang_vel_x) + abs(copter->accel_y) + abs(copter->accel_z) + (copter->height) + (copter->heading)) %10;


	if(checksum !=3 || copter->heading != 0 /*localchecksum*/) /*hardcoded checksum*/
	{
		return -2; /*return error code on checksum disagreement*/
	}
	else
	{
		return 0; //return success
	}
}

int Read_Gyro(quadcopter *copter)
{
    unsigned char inbuffer[100]; /*recieves serial from arduino*/
    const char *valueinastring;
	char * context; // helps strtok_s keep track of where it is in the string it is parsing
	int checksum=0;
	int localchecksum = 1;

	SendByte(coptercomport, 'o'); /*request sensor values for gyro only*/
	memset(inbuffer, '\0', sizeof(unsigned char)*100); //clear input buffer
	wait(GYRO_READ_DELAY); /*wait for data to be read and sent*/

	PollComport(coptercomport, inbuffer, sizeof(unsigned char)*100); /*read in serial data*/

	/*data is recieved in the following format - (data):(data):(data):(data):...*/
	/*where each (data) is an ascii string represinting the inputted value*/
	/*the funciton strtok_s searches for the : and parses the string accordingly*/
	/*the function atoi changes the parsed ascii values to decimal integers*/

	/*Note: as of 9/3/2011, a checksum system is used for error detection*/

	/*read gyrox data*/
	valueinastring = strtok_s((char *)inbuffer, ":", &context);
	if(valueinastring == NULL) // check for a lack of a : (usually an indicator of a bad input string)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->ang_vel_x = atoi(valueinastring); //write integer value to the structure
    
	/*read gyroy data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->ang_vel_y = atoi(valueinastring);
    
	/*read gyroz data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->ang_vel_z = atoi(valueinastring);

	/*read checksum data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	checksum = atoi(valueinastring);

	//localchecksum = (copter->ang_vel_z%10 + copter->ang_vel_y%10 + copter->ang_vel_x%10);

	if(checksum != 3)
	{
		printf("Error - checksums disagree\n");
		return -2;
	}
	else
		return 0;
}


int Set_Gyro_Range(int range, quadcopter * copter) //currently unimplimented
{
	return 0;
}

int Set_Acc_Range(float range, quadcopter * copter) //currently unimplimented
{
	return 0;
}

int Read_Joystick(joystick * joystickin)
{
	/*local variable definitions*/
    unsigned char inbuffer[100]; /*recieves serial from arduino*/
    const char *valueinastring;
	char * context;

    SendByte(joystickcomport, 'J'); /*request sensor values*/
    memset(inbuffer, '\0', sizeof(unsigned char)*100); //clear out input buffer
    wait(JOYSTICK_READ_DELAY); /*wait for data to be read and sent*/

    PollComport(joystickcomport, inbuffer, sizeof(unsigned char)*100); /*read in serial data*/

    /*read x axis data*/
    valueinastring = strtok_s((char*)inbuffer, ":", &context);
	if(valueinastring == NULL) /*error checking on input string*/
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->x = atoi(valueinastring);
    /*read y axis data*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->y = atoi(valueinastring);
    /*read z axis data*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->rotation = atoi(valueinastring);
    /*read height axis data*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->altitude = atoi(valueinastring);

    /*read toggle L (activate height hold)*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->activate_height = atoi(valueinastring);

    /*read toggle R (button 1)*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->button1 = atoi(valueinastring);

    /*read slide L (button 2)*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->button2 = atoi(valueinastring);

    /*read slide R (button 3)*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    joystickin->button3 = atoi(valueinastring);

    return 0;

}

int Teardown_Hardware(void)
{
    printf("\ntearing down hardware...");
    /*close serial links*/
    CloseComport(coptercomport);
    CloseComport(joystickcomport);
    printf("done!\n\n");
    return 0;
}

int ESC_Program(void)
{
    int exitflag = 0; /*local variable definitions*/
    joystick joystickin;
    quadcopter copter;
    int value = 0;
    double valuefloat;
	int j; //error counter

    printf("\n\n\nProgram is now running in ESC Program Mode!!!\n\n");
    Read_Joystick(&joystickin); /*read in values for initalization purposes*/
    if(joystickin.activate_height != 0) //confirm that toggle is in proper position to start out
    {
        printf("please flip left toggle\n"); //tell the user to change it if it's not
        while(1)
        {
            Read_Joystick(&joystickin);
            if(joystickin.activate_height == 0)
            {
                printf("thank you.\n\n");
                break;
            }
        }
    }

    printf("to exit this mode, flip left toggle.\n"); //print out instructions
    printf("The h axis will now control the value of all 4 pwm's\n");
    printf("no sensor readings will be taken, and no additional values will be read in\n");
    printf("enter anything to continue\n\n");
    scanf("%d", &value); //scan in a value to create a pause and wait until the user is ready

    while(1) //main program loop
    {
        Read_Joystick(&joystickin); /*read in value*/
        value = joystickin.altitude;
        value = value - 260; /*adjust and scale output on joystick h axis*/
        valuefloat = value * 255 / 540;
        value = (int)(valuefloat);
        value = 255 - value;
        if(value > 255) /*ensure proper range*/
            value = 255;
        if(value < 0)
            value = 0;
            /*range now 0-255*/

        copter.east_motor = value; //save values to the structure
        copter.west_motor = value;
        copter.north_motor = value;
        copter.south_motor = value;
        printf("output value = %d\n", value);
		j = 0; //reset error counter
        if(Set_Pwm(&copter) != 0) //write values with error checking
		{
			printf("error on writing PWM value, retrying (try #%d)...\n", j++); //print error message and incriment error counter
		}


		if(exitflag == 1) //check for exit status, exit if true
            break;

        exitflag = 0; //else, reset the flag
        if(joystickin.activate_height == 1) //if the switch has been flipped
        {
            wait(.01); //debounce the switch
			if(joystickin.activate_height == 1)
				exitflag = 1; //set flag if switch status is confirmed at high
        }

    }

    copter.east_motor = 0; //zero out all motor values before exiting
    copter.west_motor = 0;
    copter.north_motor = 0;
    copter.south_motor = 0;
    while(Set_Pwm(&copter) != 0)//stop motors, repeat if there's an error
	{
		printf("error on stopping motors before exiting, retrying...\n");
	}
    printf("\n\n Now exiting to Normal Mode\n\n");
    wait(3);
    return 0; //exit to caller


}

int StartDataLogging(datalog * log)
{
	/*local variable definitons*/
    time_t currenttime; 
    char filename[100];
    struct tm * timeinfo;


    time(&currenttime); /*get current date and time from system*/
    log->firstwrite = 1; //set firstwrite flag (allows for the definiton of "zero time")
    printf("Data Logging Started %s\n",ctime(&currenttime)); 

    /*generate filename and path*/
	/*note - filepat requires that a folder named "datalogs" exists in the same directory as the executable*/
    timeinfo = localtime ( &currenttime );//generate time structure from currenttime variable
    strftime(filename, sizeof(char)*100, "datalogs/QUADCOPTER DATALOG %b%d %I-%M-%S%p.txt", timeinfo ); //create filename string using current date and time
    printf("filename will be %s\n", filename); //print out that name for user reference


    /*open datalog file*/
    log->outputfile = fopen(filename, "w"); //create file and open filestream for writing
    if(log->outputfile == NULL) //verify successful open
    {
        printf("Error on creating dataloging file\n");
        printf("Please verify that a folder named 'datalogs' exists in the same directory as the executable\n");
        return -1;
    }

    return 0;
}

int LogData(datalog * log, quadcopter *copter, joystick * joystickin)
{
	/*local variable definitions*/
    FILE * file; //filestream pointer
    file = log->outputfile;
    double time;
	
	if(file == NULL) /*check for uninitalized fileptr*/
		return -1;
    if(log->firstwrite) //if this is the first time this function has been called on the current log file, it will define the current time as t = 0, and all other readings will be timed relative to this time
    {
        log->clock_init = clock();
        log->firstwrite = 0;
    }
    time = difftime(clock(), log->clock_init); //calculate current time
    /*order of values: */
    /* time, gyrox, gyroy, gyroz, accelx, accely, accelz, altitude, heading, temperatuer, motorN, motorS, motorE, motorW, joystickx, joysticky, joystickz, joystickh, joystick-activate height, joystick - right toggle, joystick - left  slide, joystick - right slide*/
    /*print values to the file, dilenated by commas*/
	fprintf(file,"%lf,", time);
    fprintf(file,"%d,", copter->ang_vel_x);
    fprintf(file,"%d,", copter->ang_vel_y);
    fprintf(file,"%d,", copter->ang_vel_z);
    fprintf(file,"%d,", copter->accel_x);
    fprintf(file,"%d,", copter->accel_y);
    fprintf(file,"%d,", copter->accel_z);
    fprintf(file,"%d,", copter->height);
    fprintf(file,"%d,", copter->heading);
	fprintf(file,"%d,", copter->magno_x);
	fprintf(file,"%d,", copter->magno_y);
	fprintf(file,"%d,", copter->magno_z);
    fprintf(file,"%d,", copter->temperature);
    fprintf(file,"%d,", copter->north_motor);
    fprintf(file,"%d,", copter->south_motor);
    fprintf(file,"%d,", copter->east_motor);
    fprintf(file,"%d,", copter->west_motor);
    fprintf(file,"%d,", joystickin->x);
    fprintf(file,"%d,", joystickin->y);
    fprintf(file,"%d,", joystickin->rotation);
    fprintf(file,"%d,", joystickin->altitude);
    fprintf(file,"%d,", joystickin->activate_height);
    fprintf(file,"%d,", joystickin->button1);
    fprintf(file,"%d,", joystickin->button2);
    fprintf(file,"%d,", joystickin->button3);
    fprintf(file,"\n"); //print a newline char. at the end of every reading

    return 0;
}

int EndDataLogging(datalog * log)
{
	if(log->outputfile == NULL)
		return -1; /*check for lack of an open filestream*/
    fclose(log->outputfile); //close the filestream and save the file
    return 0;
}


/* The following function was used in the place of the new checksum system. 

It is no longer valid and is unused.

int SetMaxDeltaMotors(int maxdeltamotor)
{
    unsigned char inbuffer[5]; //local variable definitions
	char * context = NULL;
	const char * setvalptr;
    int setval = 0;
	memset(&inbuffer[0], '\0', sizeof(unsigned char)*5); //clear our input buffer

    if(maxdeltamotor > 255 || maxdeltamotor < 0) //ensure proper range on input
    {
        printf("invalid input to SetMaxDeltaMotors - outside range of 0-255\n");
        return -1;
    }

    SendByte(coptercomport, 'n'); //send maximum rate of motor change command
    SendByte(coptercomport, (char)maxdeltamotor); //send value
    wait(.1); //wait for response
    PollComport(coptercomport, &inbuffer[0], sizeof(unsigned char)*5); //get response from copter
	setval = atoi((const char *)inbuffer);
    if(setval != maxdeltamotor ) //detect if the set value is not the same as the requested one
    {
        printf("ERROR! - maxdeltamotor set to %d\n", setval);
        return -2;
    }
    return 0; //else, return success

}

*/

int Kill(void)
{
    unsigned char inbuffer[10]; //local variable definitions
    SendByte(coptercomport, 'K'); //send command to kill the quadcopter
	memset(inbuffer, '\0', sizeof(unsigned char)*10); //clear input buffer
    wait(.2); //pause while command is executed
    
	PollComport(coptercomport, inbuffer, sizeof(unsigned char)*10); //read incoming serial
    if(inbuffer[0] == 'x') //verify successful kill
    {
        printf("Kill Successful - manual reset of copter required\n\n\n");
        return 0;
    }
    else //report error on kill signal
    {
        printf("KILL UNSCCESSFUL!!!!!!!!\n");
        return -1;
    }

}

void _cdecl TestThread(void * input)
{
	int i;
	int value;
	printf("other thread is running\n");
	printf("value passed will be displayed in 10 seconds\n");

	value = (int)input;

	wait(10);

	printf("passed value was %d\n", value);

	for(i = 0; i++; i < 100)
	{
		printf("i = %d\n", i);
	}
	printf("thread exiting now\n");
}

int Read_Magno(quadcopter *copter)
{
    unsigned char inbuffer[100]; /*recieves serial from arduino*/
    const char *valueinastring;
	char * context; // helps strtok_s keep track of where it is in the string it is parsing
	int checksum=0;
	int localchecksum = 1;

	SendByte(coptercomport, 'm'); /*request sensor values for gyro only*/
	memset(inbuffer, '\0', sizeof(unsigned char)*100); //clear input buffer
	wait(MAGNO_READ_DELAY); /*wait for data to be read and sent*/

	PollComport(coptercomport, inbuffer, sizeof(unsigned char)*100); /*read in serial data*/

	/*data is recieved in the following format - (data):(data):(data):(data):...*/
	/*where each (data) is an ascii string represinting the inputted value*/
	/*the funciton strtok_s searches for the : and parses the string accordingly*/
	/*the function atoi changes the parsed ascii values to decimal integers*/

	/*Note: as of 9/3/2011, a checksum system is used for error detection*/

	/*read magnox data*/
	valueinastring = strtok_s((char *)inbuffer, ":", &context);
	if(valueinastring == NULL) // check for a lack of a : (usually an indicator of a bad input string)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->magno_x = atoi(valueinastring); //write integer value to the structure
    
	/*read magnoy data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->magno_y = atoi(valueinastring);
    
	/*read magnoz data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	copter->magno_z = atoi(valueinastring);

	/*read checksum data*/
	valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
	checksum = atoi(valueinastring);

	localchecksum = 3;/*(copter->magno_z + copter->magno_y + copter->magno_x) % 10;*/ //hardcoded checksum

	if(checksum != localchecksum)
	{
		printf("Error - checksums disagree\n");
		return -2;
	}
	else
		return 0;
}

