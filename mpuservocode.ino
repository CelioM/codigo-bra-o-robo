#include "Wire.h"
#include "I2Cdev.h" 
#include "MPU6050.h" 


MPU6050 mpu; 
int16_t ax, ay, az; 
int16_t gx, gy, gz; 

#include <Servo.h>

Servo arm1; 
Servo arm2;
Servo arm3;
Servo arm4;

const int pinoSensor = 2;
bool state;


void setup() 
{ 
  Wire.begin(); 
  Serial.begin(38400); 
  Serial.println("Initialize MPU"); 
  mpu.initialize(); 
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed"); 
  arm1.attach(6); 
  arm2.attach(9); 
  arm3.attach(11); 
  arm4.attach(10);
  pinMode(pinoSensor,INPUT);

} 

void loop() 
{ 
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
  Serial.print("\t");
  Serial.print("ax=  ");
  Serial.println(ax);
 
  Serial.print("\t");
  Serial.print("ay=  ");
  Serial.print(ay);

  
 Serial.print("\t");
  Serial.print("az=  ");
 Serial.print(az);


   Serial.print("\t");
  Serial.print("gx=  ");
  Serial.print(gx);

   Serial.print("\t");
  Serial.print("gy=  ");
  Serial.print(gy);

  Serial.print("\t");
  Serial.print("gz=  ");
  Serial.print(gz);

  arm1.write(map(ax, -17000, 17000, 0, 179));  
  arm2.write(map(az, -17000, 17000, 0, 59));  
  arm3.write(map(ay, -17000, 17000, 0, 59));  

  state = true;
  
  if (digitalRead(pinoSensor) == HIGH and state == true){ 
    arm4.write(60);
    state = false; 
  }
  
  else{ 
    arm4.write(0);
    state = true; 
  } 
  
  

  delay(60);

}
