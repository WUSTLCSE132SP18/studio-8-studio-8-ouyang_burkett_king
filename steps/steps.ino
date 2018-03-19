#include <Wire.h> // Must include Wire library for I2C
#include <SFE_MMA8452Q.h>
MMA8452Q accel;

int i = 0;

void setup()
{
  Serial.begin(9600);
  accel.init(); 
}

void loop()
{
  if(accel.available())
  {
    accel.read();
    double current [3];
    current [i % 3] = accel.cx; 
  
   
  }
  printCalculatedAccels();
//  printOrientation();
  Serial.println();

  
}

void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print(",");
  Serial.print(accel.y, 3);
  Serial.print(",");
  Serial.print(accel.z, 3);
  Serial.print(",");
}
void printCalculatedAccels()
{ 
  Serial.print(accel.cx, 3);
  Serial.print(",");
  Serial.print(accel.cy, 3);
  Serial.print(",");
  Serial.print(accel.cz, 3);
  Serial.print(",");
}

void printOrientation()
{
  // accel.readPL() will return a byte containing information
  // about the orientation of the sensor. It will be either
  // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
  // LOCKOUT.
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
