#pragma once
extern "C"
{   //enforce c standard over c++ compilation
	/*library inclusions*/
	#include <stdio.h>
	#include <stdlib.h>
	#include "rs232.h"
	#include <time.h>
	#include <windows.h>
	#include <string.h>
	#include <dos.h>
	#include <process.h>
	#include <math.h>



	/*comport definitions*/
	#define BAUDRATE 115200
	#define CCOMPORT 6 /*7 for direct link to computer, 6 for xbee wireless link*/
	#define JCOMPORT 5

	/*delay definitions (in seconds)*/
	#define SENSOR_READ_DELAY .090
	#define GYRO_READ_DELAY .0714
	#define JOYSTICK_READ_DELAY .010
	#define PWM_WRITE_DELAY .0110
	#define MAGNO_READ_DELAY .045

	/*Test debugging definitions*/
	#define DEBUGPRINTS
	#define DEBUGPRINTSFLIGHT

	/*define output limits for Write_Pwm*/
	/*do not alter - these allow the Arduino to successfully communicate with the ESC's*/
	#define UPPERLIMIT 140
	#define LOWERLIMIT 50

	/*define Observed joystick max/mins on analog inputs*/
	/*used for correcting joystick values*/
	/*calibrated as of 6-23-11*/

	#define XMAX 866
	#define XMIN 158
	#define YMAX 875
	#define YMIN 146
	#define ZMAX 853
	#define ZMIN 150
	#define HMAX 811
	#define HMIN 256

	/*define limits on maximum rate of motor speed change*/
	#define MAXDELTAMOTORS 40

	/*Structure definitions*/


	typedef struct pidweights_t 
	{
		//this structure contains all the PID weights and acts as the central holding mechanism for them.
		//each time the PID thread executes, it reads in these values to start.
		//PID profiles are saved and loaded from this structure
		//The GUI reads from and edits this structure to get user input into the PID thread

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
		double XZTiltPWeight;
		double XZTiltIWeight;
		double XZTiltDWeight;

		double YZTiltPWeight;
		double YZTiltIWeight;
		double YZTiltDWeight;

		double YawPWeight;
		double YawIWeight;
		double YawDWeight;

		double AltPWeight;
		double AltIWeight;
		double AltDWeight;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

	
		//----------------------------------//
		//-----DECLARE CONSTANTS------------//
		//----------------------------------//
		static double const gyroscopeConversion; //gyroscope measurement has .00875 degrees per unit
		static double const accelerometerConversion; //9.81 m/sec^2
		static double const compassConversion;
		static double const motorScale;
		static double const toRadianConversion;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

		//--------------------------------------//
		//-----------DEFINE MAXES---------------//
		//--------------------------------------//
		double maxXZAngle; //degrees
		double maxYZAngle; //degrees
		double maxAltitude; //meters
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//

		//--------------------------------------//
		//----DEFINE REACTIVITY COEFFICIENTS----//
		//--------------------------------------//
		double rollReactivityCubicCoefficient;
		double rollReactivityQuadraticCoefficient;
		double rollReactivityProportionalCoefficient;
		double rollReactivityConstantCoefficient;

		double pitchReactivityCubicCoefficient;
		double pitchReactivityQuadraticCoefficient;
		double pitchReactivityProportionalCoefficient;
		double pitchReactivityConstantCoefficient;

		double yawReactivityCubicCoefficient;
		double yawReactivityQuadraticCoefficient;
		double yawReactivityProportionalCoefficient;
		double yawReactivityConstantCoefficient;

		double altReactivityCubicCoefficient;
		double altReactivityQuadraticCoefficient;
		double altReactivityProportionalCoefficient;
		double altReactivityConstantCoefficient;
		//--------------------------------------//
		//-------------END REGION---------------//
		//--------------------------------------//


	}PIDweightsstruct;



	typedef struct datalogging_t //datalog structure - contains sufficent info to enable both datalogging and multi-threaded flag control
	{
		time_t clock_init;
		FILE * outputfile;
		int firstwrite;
		int enabledatalogging;
		int KillPIDThread;
		int PIDThreadRunning;
		int KillManualThread;
		int ManualThreadRunning;
		int KillTestThread;
		int TestThreadRunning;
		int KillAllThreads;
		float progress;
		PIDweightsstruct * PIDweights;

	}datalog;



	typedef struct quadcopter_t
	{
		/*Rangefinder*/
		int height; /*returns value between 0 and 1023*/

		/*Gyroscope*/
		float gyrorange; /*contains a value of 250, 500, or 2000 (deg/sec), depending on current setting for range*/
						 /*DO NOT alter this value, it is set up by the Set_Gyro_Range function*/
		int ang_vel_x;   /*expressed in 2's compliment*/
		int ang_vel_y;
		int ang_vel_z;
		int temperature;
		int prevtemp; //used for comparison against current temperature values to check for a bad sensor read

		/*Accelerometer*/
		float accelrange; /*contains a value of 1,1.5,2,3,4,8,or 16 (+/- g), depending on current setting for accelerometer range.*/
						  /*DO NOT alter this value, it is set up by the Set_Acc_Range function. only read from it.*/
		int accel_x; /*expressed in 2's compliment values*/
		int accel_y;
		int accel_z;

		/*Magnometer*/
		int magno_x;
		int magno_y;
		int magno_z;

		/*compass*/
		int heading; /*measured in tenths of degrees, value between 0 and 3599*/

		/*motors*/
		int north_motor; /*motor pwm values*/
		int south_motor; /*can be used for bookkeeping, only written to quadcopter once*/
		int east_motor;  /*"set_motors" has been called. valid range 0-255*/
		int west_motor;


	} quadcopter;


	typedef struct joystick_t /*contains current value for all user inputs*/
	{
		int x; /*four joystick axes - when the joysticks are centered, they return around 512*/
		int y; /*range is 0 -> 1023*/
		int rotation;
		int altitude;
		int activate_height; /*1 or 0, depending on whether the user wants to utilize or disable the ultrasonic height rangefinder*/
		int button1; // right toggle
		int button2; // left slide switch
		int button3; // right slide switch


	} joystick;

		typedef struct multithreadingflags_t
	{
		int KillPIDThread;
		int PIDThreadRunning;
		int KillManualThread;
		int ManualThreadRunning;
		int KillTestThread;
		int TestThreadRunning;
		int KillAllThreads;

	}ThreadFlagsStruct;

	/*global variables (kinda - i'm really not sure where you declare global variables. here seemed a good as place as any)*/
	static int logdata = 0; //flag to tell whether datalogging is requested or not
	static int joystickcomport = 5; //comport to which joystick arduino is attached
	static int coptercomport = 6; //comport used to communicate between copter and computer (either the wireless or wired comport)
	static ThreadFlagsStruct Threadflags;
	static datalog GlobalDataLog;



	/*function prototypes*/
	int mainFunc(void);
	//main function

	int Initalize_Hardware(void);
	/*performs all hardware-related initalization. must be called at the begining of a program*/
	/*returns 0 on success, negative error code on failure. will attempt to open all possible comports,*/
	/*so if something is not plugged in, an error code will result. obviously, this may or may not be an actual problem*/

	int Set_Gyro_Range(int range, quadcopter * copter); //currently unimplimented
	/*changes the range of the readings read in from the gyroscope. valid values are 250, 500, or 2000 (deg/sec)*/
	/*returns 0 on success, negative error code on failure. also, setting is updated within quadcopter structure*/

	int Set_Acc_Range(float range, quadcopter * copter); //currently unimplimented
	/*changes the range of reading from the Accelerometer. valid inputs are 1,1.5,2,3,4,8,16*/
	/*returns 0 on success, negative error code on failure. also, setting is updated within quadcopter structure*/


	int Read_Sensors( quadcopter * copter);
	/*reads in sensor values and writes the results to the structure pointed to*/
	/*returns 0 on success */
	/*error codes - -1: Read considered bad due to abnormally short input string (error on parsing) */
	/*              -2: Read considered bad due to signifigant change in temperature reading */

	int Read_Joystick(joystick * joystickin);
	/*populates joystick struct with newest input values*/
	/*returns 0 on success, -1 if input read is unsuccessful.*/

	int Set_Pwm( quadcopter * copter);
	/*writes the pwm values in the quadcopter structure to the actual quadcopter*/
	/*returns 0 on success, negative error code on failure*/
	/*error codes - -1: error on transmission via serial - pwm value not guarnteed written to copter*/
	/*              -2: input value to write is out of valid range*/
	/*              -3: Checksum mismatch - error somewhere in transmission*/

	int Teardown_Hardware(void);
	/*deinitalize all hardware. call just before program exits*/
	/*returns 0 on success - no error checking possible*/

	void wait(float s);
	/*creates a pause in the program execution, blocks until time has elapsed.*/

	int ESC_Program(void);
	/*puts program in a mode to configure the ESC's as outlined in the manual*/
	/*h axis controls all four PWM output values, pushing them either to 0 or 255*/
	/* returns zero on completion*/

	/*this comment is named Joe. He serves no purpose. Say 'Hi' to Joe! It helps his self-esteem*/

	void ManFlight(void * inlog);
	/* allows pilot to have direct control of the motor outputs*/
	/* returns 0 on exit success, -1 on exit from Kill*/

	int PIDFlight(datalog * log);
	/*call to this function intializes thread to start PID control of copter*/
	
	void _cdecl PIDFlight_thread(void * log);
	/* allows pilot to have indirect control of the motor outputs*/
	/* contains the main flight control algorithms*/


	int CorrectJoystick(joystick * joystickin);
	/*adjusts all joystick ouputs to approprate range (0-255)*/

	int StartDataLogging(datalog * log);
	/* initalizes logging of a comma-separated value set of data*/
	/* prints to a standard text file.*/
	/* the file is created and data logging begins when this function is called*/
	/* returns -1 on failure to create log file and open filestream, 0 on success */

	int LogData(datalog * log, quadcopter * copter, joystick * joystickin);
	/* saves current frame of data to file. should be called every loop through main execution*/
	/* returns 0 on success, -1 on bad filepointer reference*/

	int EndDataLogging(datalog * log);
	/*saves the file and stops data logging*/
	/*returns 0 on success, -1 on bad filepointer reference*/

	/*int SetMaxDeltaMotors(int maxdeltamotor);*/
	/*sends the argument to the quadcopter to adjust the maximum rate of motor speed change*/
	/*DECOMISISONED AS OF 9/3/2011 */

	int Read_Gyro(quadcopter * copter);
	/*reads the sensor values of ONLY the gyro*/
	/*it's just designed to run faster when you don't need all the data*/

	int Read_Magno(quadcopter *copter);
	/*This function reads only the magnometer values*/

	int Kill(void);
	/*sends killcode to quadcopter, and listens on serial to confirm successful kill*/

	void _cdecl TestThread(void * input);
	void _cdecl Sensor_Test_Thread(void * input);

	/*the following are test procedure function prototypes*/
	/*pass pointer to datalog/thread flags structure*/
	int PWM_Time_Test(datalog * log);
	int PWM_Write_Test(datalog * log);
	int Sensor_Read_Test(datalog * log);
	int Joystick_Read_Test(datalog * log);
	int Gyro_Read_Test(datalog * log);
	int Magno_Read_Test(datalog * log);
}
