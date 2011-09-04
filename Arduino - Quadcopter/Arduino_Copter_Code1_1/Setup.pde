int HardwareSetup(void)
{
  int serialclear, i;
  Serial.flush();
  for(i = 0; i <100; i++)
  {
    serialclear = Serial.read();
  }
  
  ///////////////////////////////////////////////////
  /*gyro setup*/
  /*setup control registers to turn the device on*/
  Wire.beginTransmission(gyroAddress);
  Wire.send(0x20); /*set the device enable regester to start readings*/
  Wire.send(0x4F); /*set bandwith and sample rate here*/
  Wire.endTransmission();
  
  ///////////////////////////////////////////////////
  /*accel. setup*/
  //this code was copied from an open-source project for building a seismograph (hence the references to earthquakes)
  
    // Wait for readings to settle down.
  // 10ms Pause is required to write registers.
  delay(15);

//  writeOptionallyTo(0x0D, 0x10, 0x10); // Enable register write

  // I can't figure out how to modify the EEPROM.
  // So we reset upon startup.

  // Change calibration values based on new mode.
  // Each chip will need their own calibration.
  // Note: some offset values affect the spikiness of the values. You should test your values.
//  writeOptionallyTo(0x3A, 0x78, 0xFF); // original offset MSB z=0x78 when mode_config=0
//  writeOptionallyTo(0x39, 0x60, 0xFF); // original offset MSB y=0x60 when mode_config=0
//  writeOptionallyTo(0x38, 0x70, 0xFF); // original offset MSB x=0x70 when mode_config=0
//  writeOptionallyTo(0x36, 0x4C, 0xFF); // original offset LSB z=0x4, y=0xC when mode_config=0
  // Need a range of existing gravity + 1 G movment to get up to a 9.0M earthquake.
//  writeOptionallyTo(0x35, 0x14, 0x0F); // original offset LSB x=0x1, range+12bit=0x4 when mode_config=0 /*CHANGE RANGE HERE!!!*/

//  writeOptionallyTo(0x30, 0x01, 0x03); // Change mode_config to lower noise mode
//  writeOptionallyTo(0x21, 0x00, 0x04); // Turn off adv_int
  
  /* Earthquakes have a nominal frequency range of 0.001–50 Hz. The P and S
   * waves of >2.0M earthquakes usually have a frequency of 0.1-10 Hz. The
   * higher frequencies are attenuated by the bedrock. So you need to be
   * close to the epicenter to measure the higher frequencies. In order to
   * accurately record the lower frequencies, the bandwidth measurement must
   * be lowered in the sensor. When equal to 0x8 or 0x9, the gravity will be
   * cancelled out.
   */
//  writeOptionallyTo(0x20, 0x00, 0xF0); // Change bandwidth. 0x2=40Hz 0x3=75Hz Originally 0x4

//  writeOptionallyTo(0x0D, 0x00, 0x10); // Disable register write for protection
  
  ///////////////////////////////////////////////////////////////////////
  
  return 0;
  
}
