/* Get all possible data from MPU6050
 * Accelerometer values are given as multiple of the gravity [1g = 9.81 m/s²]
 * Gyro values are given in deg/s
 * Angles are given in degrees
 * Note that X and Y are tilt angles and not pitch/roll.
 *
 * License: MIT
 */

 #include "Wire.h"
 #include <MPU6050_light.h>
 
// 声明一个MPU6050对象，使用Wire作为通信接口
 MPU6050 mpu(Wire);
 
 unsigned long timer = 0;
 
 void setup() {
   // 初始化串口通信
   Serial.begin(115200);
   // 初始化I2C通信
   Wire.begin();
   
   // 初始化MPU6050
   byte status = mpu.begin();
   // 打印MPU6050的状态
   Serial.print(F("MPU6050 status: "));
   Serial.println(status);
   // 如果无法连接到MPU6050，停止所有操作
   while(status!=0){ } // stop everything if could not connect to MPU6050
   
   // 计算偏移量，不要移动MPU6050
   Serial.println(F("Calculating offsets, do not move MPU6050"));
   delay(1000);
   // 计算陀螺仪和加速度计的偏移量
   mpu.calcOffsets(true,true); // gyro and accelero
   Serial.println("Done!\n");
   
 }
 
 void loop() {
   mpu.update();
 
   if(millis() - timer > 1000){ // print data every second
     Serial.print(F("TEMPERATURE: "));Serial.println(mpu.getTemp());
     Serial.print(F("ACCELERO  X: "));Serial.print(mpu.getAccX());
     Serial.print("\tY: ");Serial.print(mpu.getAccY());
     Serial.print("\tZ: ");Serial.println(mpu.getAccZ());
   
     Serial.print(F("GYRO      X: "));Serial.print(mpu.getGyroX());
     Serial.print("\tY: ");Serial.print(mpu.getGyroY());
     Serial.print("\tZ: ");Serial.println(mpu.getGyroZ());
   
     Serial.print(F("ACC ANGLE X: "));Serial.print(mpu.getAccAngleX());
     Serial.print("\tY: ");Serial.println(mpu.getAccAngleY());
     
     Serial.print(F("ANGLE     X: "));Serial.print(mpu.getAngleX());
     Serial.print("\tY: ");Serial.print(mpu.getAngleY());
     Serial.print("\tZ: ");Serial.println(mpu.getAngleZ());
     Serial.println(F("=====================================================\n"));
     timer = millis();
   }
 
 }
 