/*** 
 * @Author: liuz
 * @Date: 2025-05-04 21:30:58
 * @LastEditTime: 2025-05-04 21:34:40
 * @LastEditors: liuz
 * @Description: 初始化串口，当有数据过来的时候读取并将数据打印出来
 * @FilePath: /ros2_car/test/serial_read_byte.cpp
 * @liuz_z@163.com
 */

#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Serial test");
    
}

void loop() {
    if(Serial.available())
    {
        // // 读取一个字节
        // int c = Serial.read();
        // if(c != -1)
        // {
        //     Serial.printf("Read byte: %d\n",c);
        // }
        // 读取一行数据
        // 从串口读取一行字符串
        String line = Serial.readString();
        // 打印读取的字符串
        Serial.printf("Read line: %s\n",line.c_str());
    }
}