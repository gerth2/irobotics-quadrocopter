
/*polls the compass and returns the current heading*/
//code copied from another open-source project online

int ReadHeading(void)
{
  int reading = 0;
  Wire.beginTransmission(compassAddress);
  Wire.send('A'); //send read command
  Wire.endTransmission();

  delay(7); //wait for read to actually occur

  Wire.requestFrom(compassAddress, 2); //two bytes should be recieved
  if(2 <= Wire.available())
  {
    reading = Wire.receive(); //get the most signifigant byte
    reading = reading << 8; //bitshift it
    reading += Wire.receive(); //add in the least signifigant byte
  }
  
  return reading;
  
  
}
