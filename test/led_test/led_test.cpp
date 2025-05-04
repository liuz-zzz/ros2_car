/*** 
 * @Author: liuz
 * @Date: 2025-05-04 21:55:53
 * @LastEditTime: 2025-05-04 21:56:11
 * @LastEditors: liuz
 * @Description: 使LED灯亮1s关闭1s,持续闪烁
 * @FilePath: /ros2_car/test/led_test/led_test.cpp
 * @liuz_z@163.com
 */

#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // 设置2号引脚模式为OUTPUT模式
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(2, LOW);  // 低电平，打开LED灯
  delay(1000);           // 休眠1000ms
  digitalWrite(2, HIGH); // 高电平，关闭LED灯
  delay(1000);           // 休眠1000ms
}
