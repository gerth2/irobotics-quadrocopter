/***********************************************/
/***********************************************/
// iRobotics Quadcopter 2011-2012 Arduino Code v1.1
//
//
// Main control Code - this segment is the main
// entry point for the program. It handles
// Serial I/O and calls approprate functions
// to read sensors as requested.
//
// valid input codes:
// 's' - execute setup routine
// 'r' - read sensor values
//       - returns the following values in ascii integer format - 
//         gyrox gyroy, gyroz, accelx, accely, accelz, altitude, magnox, magnoy, magnoz, heading, checksum,
// 'o' - read gyro values only
//       - returns the following values as ascii integers - 
//         gyrox, gyroy, gyroz
// 'w' - write pwm values to motors (returns 'd' on success and 'e' on checksum error, 't' on timeout)
// 'n' - write new maxdeltamotors value (returns the value the variable is set to)
// 'K' - Killcode - all motors shut down, no more serial transmissions will be listened to. manual reset required.
// 'm' - Read Magnometer values. Returns them as x, y, z in standard ascii
// 'a' - write new value to range of accelerometer (unimplimented)
// 'g' - write new value to range of gyroscope (unimplimented)
/***********************************************/
/***********************************************/

#define AUTOKILL
#define CPU_FREQ 8000000L
/*note on autokill - after three seconds without sensor transmission, */
/* the copter will automatically, slowly decrease the speed of the motors to zero*/
/* and hold them at zero until a new motor write transmission is recieved. */
/* NOT the same as the kill sequence - kill requires a manual reset, autokill */
/* can be undone simply by transmitting a new set of pwm values*/
#include <Wire.h>

/*global vars*/
int in;
int gyrox, gyroy, gyroz;
int accelx, accely, accelz;
int altitude;
int heading;
int temperature;
int north = 50, south = 50, east = 50, west = 50; /*motor pwm values*/
long unsigned int checksum, localchecksum;
int prevpwm[4] = {50,50,50,50}; /*array for previous motor values*/
int maxdeltamotors = 100;
unsigned long int zerotime;
int autokill_flag;
int accelaxes[3] = {0, 0, 0};
int gyrovals[3] = {0, 0, 0};
int magnovals[3] = {0, 0, 0};

int loopcounter = 0, resetloopcount = 0;
int timeoutcounter = 0;

//internal setup sequence
void setup()
{
  Serial.begin(115200);
  Wire.begin();
  TWBR = ((CPU_FREQ / 400000L) - 16) / 2;
  zerotime = millis();
  autokill_flag = 0;
  pinMode(13, OUTPUT);
}

//main execution loop
void loop()
{
  loopstart: //label for goto's to start loop over again
  
  
  /*do nothing while serial line has nothing new on it*/
  do
  {
    
    #ifdef AUTOKILL
    if(autokill_flag)
      digitalWrite(13, HIGH);
    else
      digitalWrite(13, LOW);
      
//    Serial.print("diftime = ");
//    Serial.println((millis()-zerotime), DEC);
    
    if( millis()-zerotime > 1000) /*check if enough time has passed to enable autokill*/
    {
        autokill_flag = 1;
    }
    #endif
    in = Serial.read();
    
    #ifdef AUTOKILL
    if(autokill_flag)
    {
      if(north > 50 && loopcounter > 300) //slowly spool the motor speed down to zero (output on PWM of 50)
      {                                  //every 30 loops through, the motor speed will be decremented
        north--;
        resetloopcount = 1;
      }
      if(south > 50 && loopcounter > 300)
      {
        south--;
        resetloopcount = 1;
      }
      if(east > 50 && loopcounter > 300)
      {
        east--;
        resetloopcount = 1;
      }
      if(west > 50 && loopcounter > 300)
      {
        west--;
        resetloopcount = 1;
      }
      if(resetloopcount)
      {
        loopcounter = 0;
        resetloopcount = 0;
      }
      
      WritePWM(north, south, east, west);
      
      
//      Serial.print(north, DEC);
//      Serial.print(" ");
//      Serial.print(south, DEC);
//      Serial.print(" ");
//      Serial.print(east, DEC);
//      Serial.print(" ");
//      Serial.print(west,DEC);
//      Serial.print(" - ");
      
      loopcounter++;
    }
    #endif
      
  }
  while (in == -1);


  /*execute command to read sensors*/
  if(in == 'r')
  {
    digitalWrite(13, HIGH);
    

    //Serial.println("reading sensors...");
    //gyrox = ReadGyroX();
    //gyroy = ReadGyroY();
    //gyroz = ReadGyroZ();
    
    //Read gyroscope
    ReadGyroAll(gyrovals);
    //replace values
    gyrox = gyrovals[0];
    gyroy = gyrovals[1];
    gyroz = gyrovals[2];

    /*read accelerometer*/
    ReadAccel(accelaxes);
    /*replace values*/
    accelx = accelaxes[0];
    accely = accelaxes[1];
    accelz = accelaxes[2];
    
    /*read in magnometer values*/
    ReadMagno(magnovals);
    

    altitude = ReadHeight();

   // heading = ReadHeading();
    heading = 0;

    checksum = 3;//hardcode checksum/(abs(gyrox)+abs(accely)+abs(accelz)+altitude+heading)%10; /*calculate a checksum*/


    /*this code generates ascii output*/
    /*write values to serial port*/
    /*each value is separated by a ':' char*/
    Serial.print(gyrox, DEC);
    Serial.write(':');
    Serial.print(gyroy, DEC);
    Serial.write(':');
    Serial.print(gyroz, DEC);
    Serial.write(':');
    Serial.print(accelx, DEC);
    Serial.write(':');
    Serial.print(accely, DEC);
    Serial.write(':');
    Serial.print(accelz, DEC);
    Serial.write(':');
    Serial.print(altitude, DEC);
    Serial.write(':');
    Serial.print(magnovals[0], DEC);
    Serial.write(':');
    Serial.print(magnovals[1], DEC);
    Serial.write(':');
    Serial.print(magnovals[2], DEC);
    Serial.write(':');
    Serial.print(heading, DEC);
    Serial.write(':');
    Serial.print(checksum, DEC);
    Serial.write(':');


    /*end of ascii printout code*/

    #ifdef AUTOKILL
    zerotime = millis(); /*reset autokill stuff*/
    autokill_flag = 0;
    #endif 
    
    digitalWrite(13, LOW);


  }
  
   /*execute command to read only gyro*/
   if(in == 'o')
   {
     digitalWrite(13, HIGH); /*turn on activity light*/
     
     gyrox = ReadGyroX(); /*read in gyro values*/
     gyroy = ReadGyroY();
     gyroz = ReadGyroZ();
     
     checksum = 3;/*(gyrox % 10 + gyroy % 10 + gyroz % 10); *//*calculate the checksum*/ //hardcoded checksum
     
     Serial.print(gyrox, DEC); /*print out the colin-dilimeted values*/
     Serial.write(':');
     Serial.print(gyroy, DEC);
     Serial.write(':');
     Serial.print(gyroz, DEC);
     Serial.write(':');
     Serial.print(checksum, DEC);
     Serial.write(':');
     
     digitalWrite(13, LOW); /*turn off activity light*/
   }


  /*execute command to write pwm's*/
  if(in == 'w')
  {
    digitalWrite(13, HIGH);
    /*input sequence - north, south, east, west, checksum*/
    /*assumes 1-byte char's*/
    timeoutcounter = 0; //set up a timeout variable
    while(Serial.available() < 5)
    {
      timeoutcounter++;
      if(timeoutcounter > 50000)
      {
        Serial.write('t');
        goto loopstart;
      }
    }
    north = Serial.read();
    south = Serial.read();
    east = Serial.read();
    west = Serial.read();
    checksum = Serial.read();
    
    /* perform error checking with checksum*/
    
    localchecksum = (north%10 + south%10 + east%10 + west%10);
    
    if(localchecksum != checksum)
    {
       Serial.write('e'); //report unsuccessful write
    }
    else
    {
       WritePWM(north, south, east, west);
       Serial.write('d'); //report successful write
    }

    #ifdef AUTOKILL
    zerotime = millis(); /*reset autokill stuff*/
    autokill_flag = 0;
    #endif 
    digitalWrite(13, LOW);  
  }

  /*execute command to setup hardware*/
  if(in == 's')
  {
    digitalWrite(13, HIGH);
    // Serial.println("setting up hardware");
    HardwareSetup();
    // Serial.println("done with setup!");
    #ifdef AUTOKILL
    zerotime = millis(); /*reset autokill stuff*/
    autokill_flag = 0;
    #endif 
    digitalWrite(13, LOW);
  }

  /*execute command to set up a new deltamotors value*/
  if(in == 'n')
  { 
    digitalWrite(13, HIGH);
    do //do nothing while nothing is on the serial line
    {
      in = Serial.read();
    }
    while (in == -1);
    maxdeltamotors = in;
    Serial.print(maxdeltamotors, DEC);
    #ifdef AUTOKILL
    zerotime = millis(); /*reset autokill stuff*/
    autokill_flag = 0;
    #endif 
    digitalWrite(13, LOW);
  }

  /*execute Kill Code*/
  if(in == 'K')
  {
    while(1)
    { 
      digitalWrite(13, HIGH);
      WritePWM(50, 50, 50, 50);
      Serial.write('x');
      delay(500);
      digitalWrite(13, LOW);
      WritePWM(50, 50, 50, 50);
      Serial.write('x');
      delay(500);
    }
  }
  
    if(in == 'm')
  {
    
    /*execute test code*/
    digitalWrite(13, HIGH);
    ReadMagno(magnovals);
      
    //Print out values of each axis
    Serial.print(magnovals[0], DEC);
    Serial.print(":");
    Serial.print(magnovals[1], DEC);
    Serial.print(":");
    Serial.print(magnovals[2], DEC);
    Serial.print(":");
    
    //calculate checksum and transmit
    checksum = (magnovals[0] + magnovals[1] + magnovals[2]) % 10;
    Serial.print(checksum, DEC);
    Serial.print(":");
  
    digitalWrite(13, LOW);
  }



}

