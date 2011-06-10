extern "C"{
/*library inclusions*/
#include <stdio.h>
#include <stdlib.h>
#include "rs232.h"
#include <time.h>
#include <windows.h>
#include <string.h>
#include <dos.h>

/*comport definitions*/
#define BAUDRATE 115200
#define CCOMPORT 6 /*7 for direct link to computer, 6 for xbee wireless link*/
#define JCOMPORT 5

/*delay definitions (in seconds)*/
#define SENSOR_READ_DELAY .093
#define JOYSTICK_READ_DELAY .008
#define PWM_WRITE_DELAY .0011

/*Test debugging definitions*/
//#define JOYSTICK_READ_TEST
//#define SENSOR_READ_TEST
//#define PWM_TIME_TEST
//#define PWM_WRITE_TEST
//#define ESC_PROGRAM
//#define DEBUGPRINTS
#define DEBUGPRINTSFLIGHT
//#define MANFLIGHTCONTROL

/*define output limits for Write_Pwm*/
/*do not alter - these allow the Arduino to successfully communicate with the ESC's*/
#define UPPERLIMIT 140
#define LOWERLIMIT 50

/*define Observed joystick max/mins on analog inputs*/
/*used for correcting joystick values*/
#define XMAX 866
#define XMIN 158
#define YMAX 875
#define YMIN 146
#define ZMAX 853
#define ZMIN 150
#define HMAX 811
#define HMIN 256

/*Structure definitions*/

typedef struct datalogging_t
{
    time_t clock_init;
    FILE * outputfile;
    int firstwrite;

}datalog;

typedef struct quadcopter_t
{
    /*Rangefinder*/
    int height; /*returns value between 0 and 1023*/

    /*Gyroscope*/
    float gyrorange; /*contains a value of 250, 500, or 2000 (deg/sec), depending on current setting for range*/
                 /*DO NOT alter this value, it is set up by the Set_Gyro_Range function*/
    int ang_vel_x; /*expressed in 2's compliment*/
    int ang_vel_y;
    int ang_vel_z;
    int temperature;

    /*Accelerometer - currently unused*/
    float accelrange; /*contains a value of 1,1.5,2,3,4,8,or 16 (+/- g), depending on current setting for accelerometer range.*/
                 /*DO NOT alter this value, it is set up by the Set_Acc_Range function. only read from it.*/
    int accel_x; /*returns 2's compliment values*/
    int accel_y;
    int accel_z;

    /*compass*/
    int heading; /*measured in tenths of degrees, value between 0 and 3599*/

    /*motors*/
    int north_motor; /*motor pwm values*/
    int south_motor; /*can be used for bookkeeping, only written to quadcopter once*/
    int east_motor; /*"set_motors" has been called. valid range 0-255*/
    int west_motor;


} quadcopter;


typedef struct joystick_t /*contains current value for all user inputs*/
{
    int x; /*four joystick axes - when the joysticks are centered, they return around 512*/
    int y; /*range is 0 -> 1023*/
    int rotation;
    int altitude;
    int activate_height; /*1 or 0, depending on whether the user wants to utilize or disable the ultrasonic height rangefinder*/
    int button1; /*reserved input for future use*/
    int button2;
    int button3;
    int button4;


} joystick;


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
/*returns 0 on success, negative error code on failure*/

int Read_Joystick(joystick * joystickin);
/*populates joystick struct with newest input values*/
/*returns 0 on success, negative error code on failure*/

int Set_Pwm( quadcopter * copter);
/*writes the pwm values in the quadcopter structure to the actual quadcopter*/
/*returns 0 on success, negative error code on failure*/
/*error codes - -1: error on transmission via serial - pwm value not guarnteed written to copter*/
/*              -2: input value to write is out of valid range*/

int Teardown_Hardware(void);
/*deinitalize all hardware. call just before program exits*/
/*returns 0 on success, negative error code on failure*/

void wait(float s);
/*creates a pause in the program execution*/

int ESC_Program(void);
/*puts program in a mode to configure the ESC's as outlined in the manual*/
/*h axis controls all four PWM output values, pushing them either to 0 or 255*/
/* returns zero on completion*/

int ManFlight(void);
/* allows pilot to have direct control of the motor outputs*/

int CorrectJoystick(joystick * joystickin);
/*adjusts all joystick ouputs to approprate range (0-255)*/

int StartDataLogging(datalog * log);
/* initalizes logging of a comma-separated value set of data*/
/*prints to a standard text file.*/
/* the file is created and data logging begins when this function is called*/
/* returns -1 on failure to create log file and open filestream -*/

int LogData(datalog * log, quadcopter * copter, joystick * joystickin);
/* saves current frame of data to file. should be called every loop through main execution*/

int EndDataLogging(datalog * log);
/*saves the file and stops data logging*/

int SetMaxDeltaMotors(int maxdeltamotor);
/*sends the argument to the quadcopter to adjust the maximum rate of motor speed change*/

int Kill(void);
/*sends killcode to quadcopter, and listens on serial to confirm successful kill*/

/*the following are test procedure function prototypes*/
int PWM_Time_Test(void);
int PWM_Write_Test(void);
int Sensor_Read_Test(void);
int Joystick_Read_Test(void);

}