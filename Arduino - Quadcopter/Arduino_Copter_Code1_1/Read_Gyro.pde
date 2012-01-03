int ReadGyroX(void)
{
  int xreading = 0;
  /*read x values*/
  Wire.beginTransmission(gyroAddress);
  Wire.send(0x29); /*request from x data high byte*/
  Wire.endTransmission();

  delay(5);

  Wire.requestFrom(gyroAddress, 1);
  if(1 <= Wire.available())
  {
    xreading = Wire.receive();
    xreading = xreading << 8; /*bitshift*/
  }

  Wire.beginTransmission(gyroAddress);
  Wire.send(0x28); /*request from x data low byte*/
  Wire.endTransmission();

  delay(5);

  Wire.requestFrom(gyroAddress, 1);
  if(1 <= Wire.available())
  {
    xreading += Wire.receive();
  }
  
  return xreading;
  
}


int ReadGyroY(void)
{
  int yreading = 0;
  /*read y values*/
  Wire.beginTransmission(gyroAddress);
  Wire.send(0x2B); /*request from y data high byte*/
  Wire.endTransmission();

  delay(5);

  Wire.requestFrom(gyroAddress, 1);
  if(1 <= Wire.available())
  {
    yreading = Wire.receive();
    yreading = yreading << 8; /*bitshift*/
  }

  Wire.beginTransmission(gyroAddress);
  Wire.send(0x2A); /*request from y data low byte*/
  Wire.endTransmission();

  delay(5);

  Wire.requestFrom(gyroAddress, 1);
  if(1 <= Wire.available())
  {
    yreading += Wire.receive();
  }

  return yreading;  

}


int ReadGyroZ(void)
{
  int zreading = 0;
  /*read z values*/
  Wire.beginTransmission(gyroAddress);
  Wire.send(0x2D); /*request from z data high byte*/
  Wire.endTransmission();

  delay(5);

  Wire.requestFrom(gyroAddress, 1);
  if(1 <= Wire.available())
  {
    zreading = Wire.receive();
    zreading = zreading << 8; /*bitshift*/
  }

  Wire.beginTransmission(gyroAddress);
  Wire.send(0x2C); /*request from z data low byte*/
  Wire.endTransmission();

  delay(5);

  Wire.requestFrom(gyroAddress, 1);
  if(1 <= Wire.available())
  {
    zreading += Wire.receive();
  }
  return zreading;  
}


//this function should remain unused as of 6-19
int ReadGyroTemp(void)
{
  /*read temperature*/
  Wire.beginTransmission(gyroAddress);
  Wire.send(0x26); /*request from temp. data byte*/
  Wire.endTransmission();

  delay(5);

  Wire.requestFrom(gyroAddress, 1);
  if(1 <= Wire.available())
  {
    temperature = Wire.receive();
  }
  return temperature;
  
}

int ReadGyroAll(int * gyrovals)
{
  int xlowbyte = 0;
  int ylowbyte = 0;
  int zlowbyte = 0;
  int loopcounter;
  
  /*address gyro and say we want to start reading from register 0x28 and auto incriment*/
  Wire.beginTransmission(gyroAddress);
  Wire.send(0xA8);
  Wire.endTransmission();
  
  /*get the six bytes back*/
  Wire.requestFrom(gyroAddress, 6);
  
  loopcounter = 0; //initalize a loopcounter
  while(Wire.available() < 6) //hold while recieveing values
  {
    if(loopcounter > 5000) //if we've held for too long, 
    {
      gyrovals[0] = 0xFFFF; //set up output values with errors
      gyrovals[1] = 0xFFFF;
      gyrovals[2] = 0xFFFF;
      return -1; //return errorcode and exit from function
    }
    loopcounter++; //incriment the loop counter to keep track of how long we've been waiting for new values
    
  }
    
  //when the data is ready, read in the values
  xlowbyte = Wire.receive(); //from register 0x28
  gyrovals[0] = Wire.receive(); //from register 0x29
  ylowbyte = Wire.receive(); //from register 0x2A
  gyrovals[1] = Wire.receive(); //from register 0x2B
  zlowbyte = Wire.receive(); //from register 0x2C
  gyrovals[2] = Wire.receive(); //from register 0x2D
  
  //assemble output vals
  gyrovals[0] << 8;
  gyrovals[1] << 8;
  gyrovals[2] << 8;
  
  gyrovals[0] += xlowbyte;
  gyrovals[1] += ylowbyte;
  gyrovals[2] += zlowbyte;
  
  return 0;
    
}
