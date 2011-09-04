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
