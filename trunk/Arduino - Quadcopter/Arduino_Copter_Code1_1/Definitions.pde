/*function prototypes*/
int ReadHeading(void);
int HardwareSetup(void);
int ReadGyroX(void);
int ReadGyroY(void);
int ReadGyroZ(void);
int ReadGyroAll(int * gyrovals);
int ReadGyroTemp(void);
int ReadHeight(void);
int ReadMagno(void);
void ReadAccel(int outputarray[]);
void WritePWM(int north, int south, int east, int west);



/*I2C addresses*/
int compassAddress = 0x42 >> 1;
int gyroAddress = 0xD3 >> 1;
int accelAddress = 0x40;

/*analog in assignments*/
int sensor1 = 0;

/*accelerometer definitions*/
#define DEVICE ((byte)0x40)    //BMA180 device address

#define DATA_X0		0x02	//X-Axis Data 0
#define DATA_X1		0x03	//X-Axis Data 1
#define DATA_Y0		0x04	//Y-Axis Data 0
#define DATA_Y1		0x05	//Y-Axis Data 1
#define DATA_Z0		0x06	//Z-Axis Data 0
#define DATA_Z1		0x07	//Z-Axis Data 1
#define DATA_TEMP	0x08	//Temperature
#define SOFT_RESET	0x10	//soft_reset
#define SOFT_RESET_VAL	0xB6	//soft_reset value to reset

#define AXIS_SHIFT	2	//Amount to right shift data. The first 2 bits are status bits.

//define axis offsets to get near-zero readings when sitting still and level

#define XAXISOFFSET (-100)
#define YAXISOFFSET (-150)
#define ZAXISOFFSET (420)


//Define Magnometer address
#define magnoaddress 0x1E //0011110b, I2C 7bit address of HMC5883






