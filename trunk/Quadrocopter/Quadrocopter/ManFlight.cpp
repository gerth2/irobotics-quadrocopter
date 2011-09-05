#pragma once
#include "stdafx.h"
#include "Header.h"

void _cdecl ManFlight(void * inlog)
{
    /*this function allows for direct user control of the motors*/
    /*it maps differentials to each of the joystick axes, */
    /*allowing the pilot to control pitch, yaw, roll, and altitude*/

    /*the left toggle allows this mode to be enabled, throwing the toggle*/
    /*forces all motors to zero and returns to the caller*/

    /*first, make sure the toggle is set up correctly*/
    joystick joystickin; //local variable definitions
    quadcopter copter;
	datalog * log;
    int i, j;
    int exitflag;
    double northmotor, southmotor, eastmotor, westmotor;
    double pitchdelta, rolldelta, yawdelta, throttle;

	log = (datalog *)inlog; //typecast the input variable so it can be used


    printf("\n\n\nProgram is now running in Manual Flight Control Mode!!!\n\n");
    Read_Joystick(&joystickin); //get initial reading
    if(joystickin.activate_height != 0)//detect case where left toggle is not in proper position to start
    {
        printf("please flip left toggle\n"); //tell the idiot user what to do
        while(1) //loop until he does it
        {
            Read_Joystick(&joystickin);
            if(joystickin.activate_height == 0)
            {
                printf("thank you.\n\n"); //and we're good...
                break;
            }
        }
    }

    printf("This mode allows for direct Pilot control of motor outputs.\n"); //again, describe what's gonna happen.
    printf("Throw the left toggle to deactivate all motors and exit.\n");
    printf("Right Toggle executes Kill Code.\n");
    printf("X joystick controls roll, Y joystick controls pitch\n");
    printf("Z joystick controls yaw, H joystick controls altitude\n\n\n");
    printf("Enter anything to continue.");
    scanf("%d", &i); //hold until the user is ok to continue, and do nothing with that variable
    i = 0;//see? i told you we'd do nothing with it.

    /*main control loop*/
    while(1)
    {
        Read_Joystick(&joystickin); //get joystick input
        CorrectJoystick(&joystickin); //make it look nice
		Read_Sensors(&copter);

        #ifdef DEBUGPRINTSFLIGHT //print out pretty looking debug info if the user wants it
        printf("corrected joystick values:\nx %d\ny %d\nz %d\nh %d\n", joystickin.x, joystickin.y, joystickin.rotation, joystickin.altitude);
        #endif

        throttle = (double)(joystickin.altitude); //establish the base value for all the motors
        pitchdelta = (double)((127 - joystickin.y) *(0.5)); /*generate deltas - final decimal is a scalaing factor*/
        rolldelta = (double)((127 - joystickin.x) * (0.5)); /*change scalaing factor to change sensitivity*/
        yawdelta = (double)((127 - joystickin.rotation) * 0.9);

        #ifdef DEBUGPRINTSFLIGHT //print out more debug info if it's wanted
        printf("deltas:\npitch %lf\nroll %lf\nyaw %lf\n", pitchdelta, rolldelta, yawdelta);
        #endif

        northmotor = throttle + pitchdelta + yawdelta; //this block o' code maps each delta to the motors, with negatives as approprate
        southmotor = throttle - pitchdelta + yawdelta;
        eastmotor  = throttle + rolldelta  - yawdelta;
        westmotor  = throttle - rolldelta  - yawdelta;

        /*ensure proper output ranges, so the quadcopter doesn't complain*/
        if(northmotor > 255)
            northmotor = 255;
        if(northmotor < 0)
            northmotor = 0;

        if(southmotor > 255)
            southmotor = 255;
        if(southmotor < 0)
            southmotor = 0;

        if(eastmotor > 255)
            eastmotor = 255;
        if(eastmotor < 0)
            eastmotor = 0;

        if(westmotor > 255)
            westmotor = 255;
        if(westmotor < 0)
            westmotor = 0;

        #ifdef DEBUGPRINTSFLIGHT //print out more useful info to the user (but only if he/she wants it)
        printf("motor outputs : \n");
        printf("north %lf\nsouth %lf\neast %lf\nwest %lf\n", northmotor, southmotor, eastmotor, westmotor);
        #endif

        copter.north_motor = (int)northmotor; //migrate all the values back to the quadcopter structure
        copter.south_motor = (int)southmotor;
        copter.east_motor = (int)eastmotor;
        copter.west_motor = (int)westmotor;
        Set_Pwm(&copter); //and write them to the quadcopter

        /*check for exit status - the complexish nature of the code effectively acts as a debouncing mechanism*/
		/*we had problems with excessive bounce in the switches earlier*/
        if(exitflag == 1)
            break;
        exitflag = 0;//reset the flag if the code gets to this point
        if(joystickin.activate_height == 1) //if the computer thinks that the switch might have been thrown,
        {
            wait(.01); //wait for a real short time,
            if(joystickin.activate_height == 1) //check again, and only set the flag if it's still thrown
                exitflag = 1;
        }

        /*check for kill status - exact same debouncing scheme*/
        if(joystickin.button1 == 1)
        {
            wait(.03); //wait a bit longer this time - we definitely don't want any premature kills
            if(joystickin.button1 == 1)
            {
                j = Kill();
                while(j)
                    j = Kill(); //error checking - continue to attempt to kill until successful
            }
            return; //report exit due to kill status
        }

		/*log data, but again only if requested*/
		if(log != NULL)
			LogData(log, &copter, &joystickin);

    }

    printf("exiting...\n"); //alert user that exit status has been triggered
    copter.north_motor = 0; //reset all motor values to zero before exiting
    copter.south_motor = 0;
    copter.east_motor = 0;
    copter.west_motor = 0;
    Set_Pwm(&copter); //write zeroed values to copter

	if(log != NULL)
		EndDataLogging(log);

    wait(1.5);//hold for a second and a half before returning control to the caller

}

int CorrectJoystick(joystick * joystickin)
{
    double xval, yval, zval, hval; //local var. definitions
	/*macroed values defined in header.h, are from observed max/min values produced from full sweeps of the remote's joysticks*/
	/*they are inconsistant because of physical differences in the potentiometers inside the controller*/

    /*extract values from structure*/
    xval = (double)joystickin->x;
    yval = (double)joystickin->y;
    zval = (double)joystickin->rotation;
    hval = (double)joystickin->altitude;

    xval = xval - XMIN; // adjust offset
    xval = xval * (255)/(XMAX-XMIN); // rescale
    if(xval > 255) //ensure proper range (essentially creates a small deadzone at the extreme ranges of travel)
        xval = 255;
    if(xval < 0)
        xval = 0;

    yval = yval - YMIN; // adjust offset
    yval = yval * (255)/(YMAX-YMIN); // rescale
    yval = 255 - yval; //invert
    if(yval > 255)
        yval = 255;
    if(yval < 0)
        yval = 0;

    zval = zval - ZMIN; // adjust offset
    zval = zval * (255)/(ZMAX-ZMIN); // rescale
    if(zval > 255)
        zval = 255;
    if(zval < 0)
        zval = 0;

    hval = hval - HMIN; // adjust offset
    hval = hval * (255)/(HMAX-HMIN); // rescale
    hval = 255 - hval; //invert
    if(hval > 255)
        hval = 255;
    if(hval < 0)
        hval = 0;

    /*re-write values after adjustment*/
    joystickin->x = (int)xval;
    joystickin->y = (int)yval;
    joystickin->rotation = (int)zval;
    joystickin->altitude = (int)hval;

    return 0;

}
