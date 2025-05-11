/*** 
 * @Author: liuz
 * @Date: 2025-05-11 14:54:38
 * @LastEditTime: 2025-05-11 14:59:35
 * @LastEditors: liuz
 * @Description: adc测量电压测试
 * @FilePath: /ros2_car/test/adc_test/adc_test.cpp
 * @liuz_z@163.com
 */

#include <Arduino.h>
void setup()
{
  Serial.begin(115200);
  pinMode(34, INPUT);
  analogSetAttenuation(ADC_11db);
}

void loop()
{
  int analogValue = analogRead(34);                     // 读取原始值0-4096
  int analogVolts = analogReadMilliVolts(34);           // 读取模拟电压，单位毫伏
  float realVolts = 5.02 * ((float)analogVolts * 1e-3); // 计算实际电压值，1e-3等于0.001，把mV转换为V

  Serial.printf("ADC analog value = %d\n", analogValue);
  Serial.printf("ADC millivolts value = %d\n", analogVolts);
  Serial.printf("realVolts value = %f\n", realVolts);
  delay(100);
}