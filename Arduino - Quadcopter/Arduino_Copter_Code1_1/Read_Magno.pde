int ReadMagno(int * magnovalues)
{
    
  int x,y,z; //triple axis data
  int checksum;

  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(magnoaddress);
  Wire.send(0x03); //select register 3, X MSB register
  Wire.endTransmission();
  
 
 //Read data from each axis, 2 registers per axis
  Wire.requestFrom(magnoaddress, 6);
  if(6<=Wire.available()){
    x = Wire.receive()<<8; //X msb
    x |= Wire.receive(); //X lsb
    z = Wire.receive()<<8; //Z msb
    z |= Wire.receive(); //Z lsb
    y = Wire.receive()<<8; //Y msb
    y |= Wire.receive(); //Y lsb
  }
  
  magnovalues[0] = x;
  magnovalues[1] = y;
  magnovalues[2] = z;
  
  return 0;  
  
}
