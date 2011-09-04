//Code to run the arduino which interfaces the joystick with the computer
//order of axis transmission: x, y, z, h, l.tog, r.tog, l. slide, r. slide
int xaxis = 0;
int yaxis = 1;
int zaxis = 3;
int haxis = 2;
int lefttoggle = 7;
int righttoggle = 4;
int leftslide = 6;
int rightslide = 5;
int in = -1;

void setup()
{
  Serial.begin(115200);

}

void loop()
{
    
  int xaxisval, yaxisval, zaxisval, haxisval;
  boolean lefttoggleval, righttoggleval, leftslideval, rightslideval;
  
  /*hold with nothing on the serial line*/
  do
  {
    in = Serial.read();
  }
  while (in == -1);

  /*read and transmit if command is recieved*/
  if(in == 'J');
  {
    in = -1;
    xaxisval = analogRead(xaxis); //read analog inputs
    yaxisval = analogRead(yaxis);
    zaxisval = analogRead(zaxis); 
    haxisval = analogRead(haxis);
    lefttoggleval = digitalRead(lefttoggle); //read digital inputs
    righttoggleval = digitalRead(righttoggle);
    leftslideval = digitalRead(leftslide);
    rightslideval = digitalRead(rightslide);
    Serial.print(xaxisval); //write analog values to serial port
    Serial.write(':');
    Serial.print(yaxisval);
    Serial.write(':');
    Serial.print(zaxisval);
    Serial.write(':');
    Serial.print(haxisval);
    Serial.write(':');
    if(lefttoggleval == HIGH) //write digital values to serial
    {
      Serial.write('1');
    }
    else
    {
      Serial.write('0');
    }
    Serial.write(':');
  
    if(righttoggleval == HIGH)
    {
      Serial.write('1');
    }
    else
    {
      Serial.write('0');
    }
    Serial.write(':'); 
 
    if(leftslideval == HIGH) //write digital slide values to serial
    {
      Serial.write('1');
    }
    else
    {
      Serial.write('0');
    }
    Serial.write(':');
  
    if(rightslideval == HIGH)
    {
      Serial.write('1');
    }
    else
    {
      Serial.write('0');
    }
    Serial.write(':'); 
  }
}

