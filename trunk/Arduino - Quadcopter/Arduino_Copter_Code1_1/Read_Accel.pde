/*helper functions*/
//Writes val to address register on device
static void writeTo(byte address, byte val) {
  Wire.beginTransmission(DEVICE); //start transmission to device 
  Wire.send(address);        // send register address
  Wire.send(val);        // send value to write
  Wire.endTransmission(); //end transmission
}

//reads num bytes starting from address register on device in to buff array
static void readFrom(byte address, byte num, byte *buff) {
  Wire.beginTransmission(DEVICE); //start transmission to device 
  Wire.send(address);        //sends address to read from
  Wire.endTransmission(); //end transmission

  Wire.requestFrom(DEVICE, num);    // request num bytes from device
  num = Wire.available(); //device may send less than requested (abnormal)
  while(num-- > 0) {
    *(buff++) = Wire.receive(); // receive a byte
  }
}

/**
 * Writes val to address register on device if it's different from
 * the current value. This decreases the wear and tear on the EEPROM.
 */
static void writeOptionallyTo(byte address, byte val, byte mask) {
  byte value = 0;
  readFrom(address, sizeof(value), &value);
  if ((value & mask) != (val & mask)) {
    // Keep the unmasked values, and changed the masked values.
    writeTo(address, (value & ~mask) | (val & mask));
  }
}


//////////////////////////////////////////

/*main reading function*/
void ReadAccel(int outputarray[])
{
    // 2 byte endian marker
  // 6 byte buffer for saving data read from the device
  // 2 byte checksum in case there is a reset in the middle of a packet.
  int axis[5] = {0x8081, 0, 0, 0, 0};

  
  // Each axis reading comes in 14 bit resolution (2 bytes little endian).
  readFrom(DATA_X0, 6, (byte*)(axis+1)); //read the acceleration data

  // Remove status and 0 bits
  axis[1] = axis[1] >> AXIS_SHIFT;
  axis[2] = axis[2] >> AXIS_SHIFT;
  axis[3] = axis[3] >> AXIS_SHIFT;

  // Calculate checksum.
  axis[4] = axis[1] + axis[2] + axis[3];
//  // Write whole packet.
//  Serial.write((byte *)axis, sizeof(axis));
//  

  /*correct output values*/
  axis[1] = axis[1] - XAXISOFFSET;
  axis[2] = axis[2] - YAXISOFFSET;
  axis[3] = axis[3] - ZAXISOFFSET;

  /*write accel. values to output array*/
  outputarray[0] = axis[1];
  outputarray[1] = axis[2];
  outputarray[2] = axis[3];
    
  return;  
}


