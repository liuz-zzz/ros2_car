#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  // 初始化串口通信，波特率为115200
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.printf("Hello World!\n"); // prints Hello World! on the Serial Monitor
}