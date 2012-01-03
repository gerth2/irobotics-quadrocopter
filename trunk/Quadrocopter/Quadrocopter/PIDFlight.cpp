#pragma once
#include "stdafx.h"
#include "Header.h"
#include "math.h"

int PIDFlight(datalog * log) //entry point to multithreading for pid
{
	_beginthread( &PIDFlight_thread, 0, (void*)log); //start a new thread for the PID, pass the log structure pointer so it has access to both logging and multithreading flags
	return 0;
}

void _cdecl PIDFlight_thread(void * input) //main pid thread function
{

    /*this function allows for indirect user control of the motors*/

    /*the left toggle allows this mode to be enabled, throwing the toggle*/
    /*forces all motors to zero and returns to the caller*/

    /*first, make sure the toggle is set up correctly*/
    joystick joystickin;
    quadcopter copter1; //for first sensor reading
	quadcopter copter2; //for second sensor reading
	quadcopter copter3; //for third sensor reading
    int i, j;
    int exitflag;
    double PYMotor, NYMotor, PXMotor, NXMotor;
    double pitchdelta, rolldelta, yawdelta, altitudeabsolute;
	datalog * log;

	log = (datalog*) input;
	log->PIDThreadRunning = 1;

    printf("\n\n\nProgram is now running in PID-Assisted Flight Mode\n\n");
    Read_Joystick(&joystickin); //get initial reading
    if(joystickin.activate_height != 0)//detect case where left toggle is not in proper position to start
    {
        printf("please flip left toggle\n"); //tell the idiot user what to do
        while(1) //loop until he does it
        {
            Read_Joystick(&joystickin);
			if( (int)log->KillPIDThread == 1 || (int)log->KillAllThreads == 1)//check to see if thread exit flag is high
			{
				printf("Thread exiting due to exterior exit signal\n"); //if a kill is requested, notify user
				log->KillPIDThread = 0;  //reset kill flag
				log->PIDThreadRunning = 0; //set indicator flags to show the thread is no longer running
				if(log->enabledatalogging) //close out the log if it is running
					EndDataLogging(log);
				Teardown_Hardware(); //close out hardware ports
				_endthread();//kill the thread
			}
            if(joystickin.activate_height == 0)
            {
                printf("thank you.\n\n"); //and we're good...
                break;
            }
        }
    }

    printf("This mode adjusts motor values based on sensor readings and joystick input.\n");
    printf("Throw the right toggle to deactivate all motors and exit.\n");
    printf("Right Toggle executes Kill Code.\n");
    printf("X joystick controls roll, Y joystick controls pitch\n");
    printf("Z joystick controls yaw, H joystick controls altitude\n\n\n");

    wait(3);
    i = 0;

	if( (int)log->KillPIDThread == 1 || (int)log->KillAllThreads == 1)//check to see if thread exit flag is high
	{
		printf("Thread exiting due to exterior exit signal\n"); //see comments above for explination (code is copied and pasted)
		log->KillPIDThread = 0;
		log->PIDThreadRunning = 0;
		if(log->enabledatalogging)
			 EndDataLogging(log);
		 Teardown_Hardware();
		_endthread();
	}

	//---------------------------//
	//-----DECLARE PID ERRORS----//
	//---------------------------//
	double XZTiltP; //roll
	double XZTiltI;
	double XZTiltD;
	double XZTiltError;

	double YZTiltP; //pitch
	double YZTiltI;
	double YZTiltD;
	double YZTiltError;

	double YawP;
	double YawI;
	double YawD;
	double YawError;

	double AltP;
	double AltI;
	double AltD;
	double AltError;
	//--------------------------------------//
	//-------------END REGION---------------//
	//--------------------------------------//

	//----------------------------------//
	//-----DEFINE  PID ERROR WEIGHTS----//
	//----------------------------------//
	double XZTiltPWeight=1;
	double XZTiltIWeight=1;
	double XZTiltDWeight=1;

	double YZTiltPWeight=1;
	double YZTiltIWeight=1;
	double YZTiltDWeight=1;

	double YawPWeight=1;
	double YawIWeight=1;
	double YawDWeight=1;

	double AltPWeight=1;
	double AltIWeight=1;
	double AltDWeight=1;
	//--------------------------------------//
	//-------------END REGION---------------//
	//--------------------------------------//

	//----------------------------------//
	//-----DECLARE CURRENT STATE VARS---//
	//----------------------------------//
	double currentXZtilt=0;
	double currentYZtilt=0;
	
	double current_clock = clock();
	double previous_clock;
	double time_diff;

	double currentAltitudeVelocity; //expressed in m/sec
	double currentAltitude; //expressed in m
	//--------------------------------------//
	//-------------END REGION---------------//
	//--------------------------------------//
	
	//----------------------------------//
	//-----DECLARE CONSTANTS------------//
	//----------------------------------//
	double const gyroscopeConversion=.00875; //gyroscope measurement has .00875 degrees per unit
	double const accelerometerConversion=9.81/4000; //9.81 m/sec^2
	double const compassConversion=10.0;
	double const motorScale=5;
	double const toRadianConversion=.0174444;
	//--------------------------------------//
	//-------------END REGION---------------//
	//--------------------------------------//

	//--------------------------------------//
	//-----------DEFINE MAXES---------------//
	//--------------------------------------//
	double maxXZAngle=15; //degrees
	double maxYZAngle=15; //degrees
	double maxAltitude=3; //meters
	//--------------------------------------//
	//-------------END REGION---------------//
	//--------------------------------------//

	//--------------------------------------//
	//----DEFINE REACTIVITY COEFFICIENTS----//
	//--------------------------------------//
	double rollReactivityCubicCoefficient=0;
	double rollReactivityQuadraticCoefficient=0;
	double rollReactivityProportionalCoefficient=1;
	double rollReactivityConstantCoefficient=0;

	double pitchReactivityCubicCoefficient=0;
	double pitchReactivityQuadraticCoefficient=0;
	double pitchReactivityProportionalCoefficient=1;
	double pitchReactivityConstantCoefficient=0;

	double yawReactivityCubicCoefficient=0;
	double yawReactivityQuadraticCoefficient=0;
	double yawReactivityProportionalCoefficient=1;
	double yawReactivityConstantCoefficient=0;

	double altReactivityCubicCoefficient=0;
	double altReactivityQuadraticCoefficient=0;
	double altReactivityProportionalCoefficient=1;
	double altReactivityConstantCoefficient=0;
	//--------------------------------------//
	//-------------END REGION---------------//
	//--------------------------------------//

	//define base magnetic orientation
	Read_Magno(&copter1);
	Read_Magno(&copter2);
	Read_Magno(&copter3);

	double avgBaseMagnoX=(copter1.magno_x+copter2.magno_x+copter3.magno_x)/3;
	double avgBaseMagnoY=(copter1.magno_y+copter2.magno_y+copter3.magno_y)/3;
	double avgBaseMagnoZ=(copter1.magno_z+copter2.magno_z+copter3.magno_z)/3;

	double baseXZTilt=atan(avgBaseMagnoZ/avgBaseMagnoX);
	double baseYZTilt=atan(avgBaseMagnoZ/avgBaseMagnoY);
	double baseYaw=atan(avgBaseMagnoY/avgBaseMagnoX);

    /*main control loop*/
    while(1)
    {

		if( (int)log->KillPIDThread == 1 || log->KillAllThreads == 1)//check to see if thread exit flag is high
		{
			printf("Thread exiting due to exterior exit signal\n");
			log->KillPIDThread = 0;
			log->PIDThreadRunning = 0;
			if(log->enabledatalogging)
			 EndDataLogging(log);
			 Teardown_Hardware();
			_endthread();
		}

        Read_Joystick(&joystickin);
        CorrectJoystick(&joystickin);

		//take three sensor readings to smooth the operation
		Read_Sensors(&copter1);
		//Read_Magno(&copter1);
		//Read_Sensors(&copter2);
		//Read_Magno(&copter2);
		//Read_Sensors(&copter3);
		//Read_Magno(&copter3);

        #ifdef DEBUGPRINTSFLIGHT
        printf("corrected joystick values:\nx %d\ny %d\nz %d\nh %d\n", joystickin.x, joystickin.y, joystickin.rotation, joystickin.altitude);
        #endif

        altitudeabsolute = (double)(joystickin.altitude);
		rolldelta = (double)(127 - joystickin.x); //roll is XZ tilt
		pitchdelta = (double)(127 - joystickin.y); //pitch is YZ tilt
        yawdelta = (double)(127 - joystickin.rotation);

        #ifdef DEBUGPRINTSFLIGHT
        printf("deltas:\npitch %lf\nroll %lf\nyaw %lf\n", pitchdelta, rolldelta, yawdelta);
        #endif

		previous_clock=current_clock;
		current_clock=clock();
		time_diff = difftime(current_clock, previous_clock)/CLOCKS_PER_SEC; //calculate current time

		//--------------------------------------//
		//-----------TILT PID CALCULATIONS------//
		//--------------------------------------//

		//double avg_ang_vel_y=(copter1.ang_vel_y+copter2.ang_vel_y+copter3.ang_vel_y)/3.0+171;
		//double avg_ang_vel_x=(copter1.ang_vel_x+copter2.ang_vel_x+copter3.ang_vel_x)/3.0+36;
		//double avg_ang_vel_z=(copter1.ang_vel_z+copter2.ang_vel_z+copter3.ang_vel_z)/3.0-36;
		double avg_ang_vel_y=(copter1.ang_vel_y+171);
		double avg_ang_vel_x=(copter1.ang_vel_x+36);
		double avg_ang_vel_z=(copter1.ang_vel_z-36);
		//gyroscope integration of tilt

		/*
		if (currentXZtilt>10 || currentXZtilt<-10)
		{
			//XZ tilt
			currentXZtilt+=avg_ang_vel_y*time_diff*gyroscopeConversion; //gyroscope measures in 
		}
		else
		{
			currentXZtilt+=avg_ang_vel_y*time_diff*gyroscopeConversion; //gyroscope measures in 
			//use accelerometer to recalibrate
		}
		if (currentYZtilt>10 || currentYZtilt<-10)
		{
			//YZ tilt
			currentYZtilt+=avg_ang_vel_x*time_diff*gyroscopeConversion;
		}
		else
		{
			//use accelerometer to recalibrate
			currentYZtilt+=avg_ang_vel_x*time_diff*gyroscopeConversion;
		}
		*/

		//calculate tilt based on magnetometer
		//double avgCurrentMagnoX=(copter1.magno_x+copter2.magno_x+copter3.magno_x)/3;
		//double avgCurrentMagnoY=(copter1.magno_y+copter2.magno_y+copter3.magno_y)/3;
		//double avgCurrentMagnoZ=(copter1.magno_z+copter2.magno_z+copter3.magno_z)/3;

		double avgCurrentMagnoX=(copter1.magno_x);
		double avgCurrentMagnoY=(copter1.magno_y);
		double avgCurrentMagnoZ=(copter1.magno_z);


		double currentXZTilt=atan(avgCurrentMagnoZ/avgCurrentMagnoX)-baseXZTilt;
		double currentYZTilt=atan(avgCurrentMagnoZ/avgCurrentMagnoY)-baseYZTilt;
		double currentHeading=atan(avgCurrentMagnoY/avgCurrentMagnoX)-baseYaw;

		XZTiltP=currentXZtilt-(rolldelta/128.0)*maxXZAngle;
		XZTiltI=XZTiltI+XZTiltP;
		XZTiltD=avg_ang_vel_y*gyroscopeConversion;

		YZTiltP=currentYZtilt-(rolldelta/128.0)*maxYZAngle;
		YZTiltI=YZTiltI+YZTiltP;;
		YZTiltD=avg_ang_vel_x*gyroscopeConversion;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

		//--------------------------------------//
		//------------YAW PID CALCULATIONS------//
		//--------------------------------------//
		//currentHeading=(copter1.heading/compassConversion+copter2.heading/compassConversion+copter3.heading/compassConversion)/3.0-180.0; //adjust so it has a -180 to +180 degree range
		currentHeading=(copter1.heading/compassConversion-180.0); //adjust so it has a -180 to +180 degree range
		YawP=currentHeading+(yawdelta/128.0)*180.0;
		YawI=YawI+YawP;
		YawD=avg_ang_vel_z*gyroscopeConversion;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

		//--------------------------------------//
		//-------HEIGHT PID CALCULATIONS--------//
		//--------------------------------------//
		//double avg_accel_x=(copter1.accel_x+copter2.accel_x+copter3.accel_x)/3.0;
		//double avg_accel_y=(copter1.accel_y+copter2.accel_y+copter3.accel_y)/3.0;
		//double avg_accel_z=(copter1.accel_z+copter2.accel_z+copter3.accel_z)/3.0;
		double avg_accel_x=(copter1.accel_x);
		double avg_accel_y=(copter1.accel_y);
		double avg_accel_z=(copter1.accel_z);
		double avg_accel_total=pow(pow(avg_accel_x,2)+pow(avg_accel_y,2)+pow(avg_accel_z,2),.5);

		//double currentAltitudeAcceleration=
		//find first component
		double firstAccelComponent=(cos(currentXZtilt*toRadianConversion)*avg_accel_total);
		double totalAltitudeAccel=(cos(currentYZtilt*toRadianConversion)*firstAccelComponent)-4000;
		currentAltitudeVelocity=currentAltitudeVelocity+(totalAltitudeAccel*time_diff*accelerometerConversion);
		currentAltitude=currentAltitude+currentAltitudeVelocity*time_diff;
		//double currentSensorAltitude=((copter1.height+copter2.height+copter3.height)/3.0)/100.0; //average and convert from cm to m
		double currentSensorAltitude=(copter1.height)/100.0; //average and convert from cm to m

		//used to correct velocity drift due to integration
		double lastSensorAltitude;
		bool altitudeSensorValid;

		//if the tilt is small enough, use the height sensor measurement
		if ((currentXZtilt < 10 && currentXZtilt > -10) && (currentYZtilt < 10 && currentYZtilt > -10))
		{
			currentAltitude=currentSensorAltitude;
			//feature to correct the current altitude velocity as it will drift with the integration of acceleration
			if (altitudeSensorValid)
			{
				currentAltitudeVelocity=(currentSensorAltitude-lastSensorAltitude)/time_diff;
			}
			lastSensorAltitude=currentSensorAltitude;
			altitudeSensorValid=true;
		}
		else
		{
			//nothing, as the current altitude has already been set to the double integrated acceleration

			//invalidate the last altitude sensor reading
			altitudeSensorValid=false;
		}

		AltP=currentAltitude-(altitudeabsolute/256.0)*maxAltitude;
		AltI=AltI+AltP;
		AltD=currentAltitudeVelocity;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

		//--------------------------------------//
		//---------CALCULATE TOTAL ERRORS-------//
		//--------------------------------------//
		XZTiltError=XZTiltP*XZTiltPWeight+XZTiltI*XZTiltIWeight+XZTiltD*XZTiltDWeight;
		YZTiltError=YZTiltP*YZTiltPWeight+YZTiltI*YZTiltIWeight+YZTiltD*YZTiltDWeight;
		YawError=YawP*YawPWeight+YawI*YawIWeight+YawD*YawDWeight;
		AltError=AltP*AltPWeight+AltI*AltIWeight+AltD*AltDWeight;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

		//--------------------------------------//
		//-------APPLY REACTIVITY FUNCTION------//
		//--------------------------------------//
		XZTiltError=rollReactivityCubicCoefficient*pow(XZTiltError,3)+rollReactivityQuadraticCoefficient*pow(XZTiltError,2)+rollReactivityProportionalCoefficient*XZTiltError+rollReactivityConstantCoefficient;
		YZTiltError=pitchReactivityCubicCoefficient*pow(YZTiltError,3)+pitchReactivityQuadraticCoefficient*pow(YZTiltError,2)+pitchReactivityProportionalCoefficient*YZTiltError+pitchReactivityConstantCoefficient;
		YawError=yawReactivityCubicCoefficient*pow(YawError,3)+yawReactivityQuadraticCoefficient*pow(YawError,2)+yawReactivityProportionalCoefficient*YawError+yawReactivityConstantCoefficient;
		AltError=altReactivityCubicCoefficient*pow(AltError,3)+altReactivityQuadraticCoefficient*pow(AltError,2)+altReactivityProportionalCoefficient*AltError+altReactivityConstantCoefficient;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

		//--------------------------------------//
		//-------SET MOTORS---------------------//
		//--------------------------------------//
		//PY = +Y
		//NY = -Y
		//PX = +X
		//NX = -X
		double unscaledPYMotorChange = -AltError-YZTiltError-YawError;
		double unscaledNYMotorChange = -AltError+YZTiltError-YawError;
		double unscaledPXMotorChange = -AltError+XZTiltError+YawError;
		double unscaledNXMotorChange = -AltError-XZTiltError+YawError;

		//PYMotor = PYMotor + min(unscaledPYMotorChange/motorScale,40);
        //NYMotor = NYMotor + min(unscaledNYMotorChange/motorScale,40);
        //PXMotor = PXMotor + min(unscaledPXMotorChange/motorScale,40);
        //NXMotor = NXMotor + min(unscaledNXMotorChange/motorScale,40);

		PYMotor = unscaledPYMotorChange/motorScale;
        NYMotor = unscaledNYMotorChange/motorScale;
        PXMotor = unscaledPXMotorChange/motorScale;
        NXMotor = unscaledNXMotorChange/motorScale;

        /*ensure proper output range*/
		/*
        if(PYMotor > 255)
            PYMotor = 255;
        if(PYMotor < 0)
            PYMotor = 0;

        if(NYMotor > 255)
            NYMotor = 255;
        if(NYMotor < 0)
            NYMotor = 0;

        if(PXMotor > 255)
            PXMotor = 255;
        if(PXMotor < 0)
            PXMotor = 0;

        if(NXMotor > 255)
            NXMotor = 255;
        if(NXMotor < 0)
            NXMotor = 0;
		*/

        #ifdef DEBUGPRINTSFLIGHT
        printf("motor outputs : \n");
        printf("+Y %lf\-Y %lf\+X %lf\-X %lf\n", PYMotor, NYMotor, PXMotor, NXMotor);
        #endif

        copter1.north_motor = (int)PYMotor;
        copter1.south_motor = (int)NYMotor;
        copter1.east_motor = (int)PXMotor;
        copter1.west_motor = (int)NXMotor;
        //Set_Pwm(&copter1);
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

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
        if(log->enabledatalogging)
			 EndDataLogging(log);
		 Teardown_Hardware();
		_endthread();
			
        }

		/*log data*/
		if(log->enabledatalogging != 0)
			LogData(log, &copter1, &joystickin);

    }

    printf("Exiting to main menu...\n");
    copter1.north_motor = 0; //reset motor values to zero
    copter1.south_motor = 0;
    copter1.east_motor = 0;
    copter1.west_motor = 0;
    Set_Pwm(&copter1); // write values to copter
    wait(1.5);
	if(log->enabledatalogging) //close out the datalog if it's running
		 EndDataLogging(log);
	Teardown_Hardware(); //close out hardware ports
    _endthread(); //kill the thread
}