
/* This file contains all the hardware io functions*/

#include "stdafx.h"
#include "Header.h"
/*function to cause pauses in the program execution*/
void wait(float s)
{
    clock_t endwait;
    endwait = (float)clock()+s*1000;
    while (clock() < endwait)
    {
    }

}

/*hardware setup*/

int Initalize_Hardware(void)
{ 

    /*print out some official-looking stuff for coolness factor*/
    printf("\n\n==================================================================\n");
    printf(    "===            IEEE MIDTERMINATORS QUADCOPTER - v1.0           ===\n");
    printf(    "===                                                            ===\n");
    printf(    "===    Hardware Design and Interface Software - Chris Gerth    ===\n");
    printf(    "===        Software and PID Algorithm - Michael Vilim          ===\n");
    printf(    "===    Consulting and Overall Awesomeness - Robbie Regalbuto   ===\n");
    printf(    "==================================================================\n");
    printf(    "===                    ---Sponsors---                          ===\n");
    printf(    "===                    --------------                          ===\n");
    printf(    "===                       UIUC IEEE                            ===\n");
    printf(    "===                    Caterpillar Inc.                        ===\n");
    printf(    "==================================================================\n\n\n");

    printf("\ninitalizing hardware....\n");
    /*open the three required comports*/
    int errorcode = 0;
    if(OpenComport(6, BAUDRATE))
    {
        printf("-- to computer-side Xbee radio\n");
        errorcode--;
    }

    if(OpenComport(7, BAUDRATE))
    {
        printf("-- to quadcopter\n");
        errorcode--;
    }
    if(OpenComport(5,BAUDRATE))
    {
        printf("-- to Joystick Input Arduino\n");
        errorcode--;
    }

    /*execute copter-side setup*/
    SendByte(CCOMPORT, 's');
    printf("initalization complete!\n\n");
    return errorcode;
}

int Set_Pwm(quadcopter * copter)
{
    int north, south, east, west;
    int i;
    unsigned char errorbuf[10];
    unsigned char outbuff[4];
    memset(errorbuf, '\0', sizeof(unsigned char)*10);
    memset(outbuff, '\0', sizeof(unsigned char)*4);

    SendByte(CCOMPORT, 'w'); //send pwm write command to copter

    north = copter->north_motor; //extract values from structure
    south = copter->south_motor;
    east = copter->east_motor;
    west = copter->west_motor;

    /*ensure proper input range*/
    if(north > 255 || north < 0 || south > 255 || south < 0 || east > 255 || east < 0 || west > 255 || west < 0)
    {
        printf("ERROR - attempt to write a pwm value out of valid range (0-255)\n");
        return -2;
    }

    /*convert values to proper range so ESC's recognize them*/
    north = (float)north * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    north = (int)north + LOWERLIMIT;
    south = (float)south * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    south = (int)south + LOWERLIMIT;
    east = (float)east * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    east = (int)east + LOWERLIMIT;
    west = (float)west * (float)((float)(UPPERLIMIT-LOWERLIMIT)/(float)255);
    west = (int)west + LOWERLIMIT;

    #ifdef DEBUGPRINTS
    printf("values written:\n");
    printf("north = %d\n", north);
    printf("south = %d\n", south);
    printf("east  = %d\n", east);
    printf("west  = %d\n", west);
    #endif




    /*send bytes and perform error checking*/

    if(SendByte(CCOMPORT, (char)north))
        printf("error in tranmission of PWM value\n");
    wait(PWM_WRITE_DELAY);
    if(SendByte(CCOMPORT, (char)south))
        printf("error in tranmission of PWM value\n");
    wait(PWM_WRITE_DELAY);
    if(SendByte(CCOMPORT, (char)east))
        printf("error in tranmission of PWM value\n");
    wait(PWM_WRITE_DELAY);
    if(SendByte(CCOMPORT, (char)west))
        printf("error in tranmission of PWM value\n");

    for(i = 0; i <100000; i++) /*wait some arbitrairly large time for success signal before continuing*/
    {
        memset(errorbuf, '\0', sizeof(unsigned char)*10);
        PollComport(CCOMPORT, errorbuf, sizeof(unsigned char)*10); /*request confirmation of sucessful write*/
        if(errorbuf[0] == 100)
        {
            #ifdef DEBUGPRINTS
            printf("errorbuff = %d %d %d %d %d\n", errorbuf[0], errorbuf[1], errorbuf[2], errorbuf[3], errorbuf[4]);
            #endif
            return 0;
        }
    }

    #ifdef DEBUGPRINTS
    printf("errorbuff = %d %d %d %d %d\n", errorbuf[0], errorbuf[1], errorbuf[2], errorbuf[3], errorbuf[4]);
    #endif
    printf("timeout on pwm write\n");
    return -1;

}


int Read_Sensors(quadcopter *copter)
{
	int i;
    unsigned char inbuffer[100]; /*recieves serial from arduino*/
    const char *valueinastring;
	char * context;

    SendByte(CCOMPORT, 'r'); /*request sensor values*/
    memset(inbuffer, '\0', sizeof(unsigned char)*100);
    wait(SENSOR_READ_DELAY); /*wait for data to be read and sent*/

    PollComport(CCOMPORT, inbuffer, sizeof(unsigned char)*100); /*read in serial data*/

    /*read gyrox data*/
    valueinastring = strtok_s((char *)inbuffer, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    copter->ang_vel_x = atoi(valueinastring);
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
    /*read heading data*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    copter->heading = atoi(valueinastring);
    /*read temperature data*/
    valueinastring = strtok_s(NULL, ":", &context);
	if(valueinastring == NULL)
	{
		printf("error - input string is abnormally small\n");
		return -1;
	}
    copter->temperature = atoi(valueinastring);


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
    unsigned char inbuffer[100]; /*recieves serial from arduino*/
    const char *valueinastring;
	char * context;

    SendByte(JCOMPORT, 'J'); /*request sensor values*/
    memset(inbuffer, '\0', sizeof(unsigned char)*100);
    wait(JOYSTICK_READ_DELAY); /*wait for data to be read and sent*/

    PollComport(JCOMPORT, inbuffer, sizeof(unsigned char)*100); /*read in serial data*/

    /*read x axis data*/
    valueinastring = strtok_s((char*)inbuffer, ":", &context);
	if(valueinastring == NULL)
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
    CloseComport(5);
    CloseComport(6);
    CloseComport(7);
    printf("done!\n\n");
    return 0;
}

int ESC_Program(void)
{
    int exitflag = 0;
    joystick joystickin;
    quadcopter copter;
    int value = 0;
    double valuefloat;

    printf("\n\n\nProgram is now running in ESC Program Mode!!!\n\n");
    Read_Joystick(&joystickin);
    if(joystickin.activate_height != 0)
    {
        printf("please flip left toggle\n");
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

    printf("to exit this mode, flip left toggle.\n");
    printf("The h axis will now control the value of all 4 pwm's\n");
    printf("no sensor readings will be taken, and no additional values will be read in\n");
    printf("enter anything to continue\n\n");
    scanf("%d", &value);

    while(1)
    {
        Read_Joystick(&joystickin); /*read in value*/
        value = joystickin.altitude;
        value = value - 260; /*adjust and scale output*/
        valuefloat = value * 255 / 540;
        value = (int)(valuefloat);
        value = 255 - value;
        if(value > 255) /*ensure proper range*/
            value = 255;
        if(value < 0)
            value = 0;
            /*range now 0-255*/

        copter.east_motor = value;
        copter.west_motor = value;
        copter.north_motor = value;
        copter.south_motor = value;
        printf("output value = %d\n", value);
        Set_Pwm(&copter);
        if(exitflag == 1)
            break;
        exitflag = 0;
        if(joystickin.activate_height == 1)
        {
            wait(.01);
            exitflag = 1;
        }

    }
    copter.east_motor = 0;
    copter.west_motor = 0;
    copter.north_motor = 0;
    copter.south_motor = 0;
    Set_Pwm(&copter);
    printf("\n\n Now exiting to Normal Mode\n\n");
    wait(3);
    return 0;


}

int StartDataLogging(datalog * log)
{
    time_t currenttime;
    char filename[100];
    struct tm * timeinfo;


    time(&currenttime); /*get current date and time from system*/
    log->firstwrite = 1;
    printf("Data Logging Started %s\n",ctime(&currenttime));

    /*generate filename and path*/
    timeinfo = localtime ( &currenttime );
    strftime(filename, sizeof(char)*100, "datalogs/QUADCOPTER DATALOG %b%d %I-%M-%S%p.txt", timeinfo );
    printf("filename will be %s\n", filename);


    /*open datalog file*/
    log->outputfile = fopen(filename, "w");
    if(log->outputfile == NULL)
    {
        printf("Error on creating dataloging file\n");
        printf("Please verify that a folder named 'datalogs' exists in the same directory as the executable\n");
        return -1;
    }

    return 0;
}

int LogData(datalog * log, quadcopter *copter, joystick * joystickin)
{
    FILE * file;
    file = log->outputfile;
    double time;
	if(file == NULL) /*check for uninitalized fileptr*/
		return -1;
    if(log->firstwrite)
    {
        log->clock_init = clock();
        log->firstwrite = 0;
    }
    time = difftime(clock(), log->clock_init);
    /*order of values: */
    /* time, gyrox, gyroy, gyroz, accelx, accely, accelz, altitude, heading, temperatuer, motorN, motorS, motorE, motorW, joystickx, joysticky, joystickz, joystickh, joystick-activate height, joystick - right toggle, joystick - left  slide, joystick - right slide*/
    fprintf(file,"%lf,", time);
    fprintf(file,"%d,", copter->ang_vel_x);
    fprintf(file,"%d,", copter->ang_vel_y);
    fprintf(file,"%d,", copter->ang_vel_z);
    fprintf(file,"%d,", copter->accel_x);
    fprintf(file,"%d,", copter->accel_y);
    fprintf(file,"%d,", copter->accel_z);
    fprintf(file,"%d,", copter->height);
    fprintf(file,"%d,", copter->heading);
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
    fprintf(file,"\n");
    return 0;
}

int EndDataLogging(datalog * log)
{
	if(log->outputfile == NULL)
		return -1; /*check for lack of an open filestream*/
    fclose(log->outputfile);
    return 0;
}

int Kill(void)
{
    unsigned char inbuffer[10];

    SendByte(CCOMPORT, 'K');
    wait(.2);
    PollComport(CCOMPORT, inbuffer, sizeof(unsigned char)*10);
    if((int)inbuffer[0] == 'x')
    {
        printf("Kill Successful - manual reset of copter required\n\n\n");
        return 0;
    }
    else
    {
        printf("KILL UNSCCESSFUL!!!!!!!!\n");
        return -1;
    }

}



