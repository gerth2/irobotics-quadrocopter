
#include "stdafx.h"
#include "Header.h"

int ManFlight(datalog * log)
{
    /*this function allows for direct user control of the motors*/
    /*it maps differentials to each of the joystick axes, */
    /*allowing the pilot to control pitch, yaw, roll, and altitude*/

    /*the left toggle allows this mode to be enabled, throwing the toggle*/
    /*forces all motors to zero and returns to the caller*/

    /*first, make sure the toggle is set up correctly*/
    joystick joystickin;
    quadcopter copter;
    int i, j;
    int exitflag;
    double northmotor, southmotor, eastmotor, westmotor;
    double pitchdelta, rolldelta, yawdelta, throttle;


    printf("\n\n\nProgram is now running in Manual Flight Control Mode!!!\n\n");
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

    printf("This mode allows for direct Pilot control of motor outputs.\n");
    printf("Throw the left toggle to deactivate all motors and exit.\n");
    printf("Right Toggle executes Kill Code.\n");
    printf("X joystick controls roll, Y joystick controls pitch\n");
    printf("Z joystick controls yaw, H joystick controls altitude\n\n\n");
    printf("Enter anything to continue.");
    scanf("%d", &i);
    i = 0;

    /*main control loop*/
    while(1)
    {
        Read_Joystick(&joystickin);
        CorrectJoystick(&joystickin);

        #ifdef DEBUGPRINTSFLIGHT
        printf("corrected joystick values:\nx %d\ny %d\nz %d\nh %d\n", joystickin.x, joystickin.y, joystickin.rotation, joystickin.altitude);
        #endif

        throttle = (double)(joystickin.altitude);
        pitchdelta = (double)((127 - joystickin.y) *(0.5)); /*generate deltas - final decimal is a scalaing factor*/
        rolldelta = (double)((127 - joystickin.x) * (0.5)); /*change scalaing factor to change sensitivity*/
        yawdelta = (double)((127 - joystickin.rotation) * 0.9);

        #ifdef DEBUGPRINTSFLIGHT
        printf("deltas:\npitch %lf\nroll %lf\nyaw %lf\n", pitchdelta, rolldelta, yawdelta);
        #endif

        northmotor = throttle + pitchdelta + yawdelta;
        southmotor = throttle - pitchdelta + yawdelta;
        eastmotor  = throttle + rolldelta  - yawdelta;
        westmotor  = throttle - rolldelta  - yawdelta;

        /*ensure proper output range*/
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

        #ifdef DEBUGPRINTSFLIGHT
        printf("motor outputs : \n");
        printf("north %lf\nsouth %lf\neast %lf\nwest %lf\n", northmotor, southmotor, eastmotor, westmotor);
        #endif

        copter.north_motor = (int)northmotor;
        copter.south_motor = (int)southmotor;
        copter.east_motor = (int)eastmotor;
        copter.west_motor = (int)westmotor;
        Set_Pwm(&copter);

        /*check for exit status*/
        if(exitflag == 1)
            break;
        exitflag = 0;
        if(joystickin.activate_height == 1)
        {
            wait(.01);
            if(joystickin.activate_height == 1)
                exitflag = 1;
        }
        /*check for kill status*/
        if(joystickin.button1 == 1)
        {
            wait(.03);
            if(joystickin.button1 == 1)
            {
                j = Kill();
                while(j)
                    j = Kill(); //continue to attempt to kill until successful
            }
            return -1; //report exit due to kill status
        }

		/*log data*/
		if(log != NULL)
			LogData(log, &copter, &joystickin);

    }

    printf("exiting...\n");
    copter.north_motor = 0;
    copter.south_motor = 0;
    copter.east_motor = 0;
    copter.west_motor = 0;
    Set_Pwm(&copter);
    wait(1.5);
    return 0;
}

int CorrectJoystick(joystick * joystickin)
{
    double xval, yval, zval, hval;

    /*extract values from structure*/
    xval = (double)joystickin->x;
    yval = (double)joystickin->y;
    zval = (double)joystickin->rotation;
    hval = (double)joystickin->altitude;

    xval = xval - XMIN; // adjust offset
    xval = xval * (255)/(XMAX-XMIN); // rescale
    if(xval > 255)
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
