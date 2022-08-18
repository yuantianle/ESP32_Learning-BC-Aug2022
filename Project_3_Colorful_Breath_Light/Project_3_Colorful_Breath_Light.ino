#include <Arduino.h>

#define LED_R 32
#define LED_G 25
#define LED_B 33

void setup()
{
  /*ESP32共有3个UART端口, 其中UART1用于Flash读/写.

    串口名  Arduino名  TX  RX
    UART0 Serial  pin1  pin3
    UART1 Serial1 pin10 pin9
    UART2 Serial2 pin17 pin16

    串口初始化
    Serial.begin(speed, config)
            Parameters：
                    speed：波特率，一般取值9600,115200等。
                    config：设置数据位、校验位和停止位。默认SERIAL_8N1表示8个数据位，无校验位，1个停止位。


  */
  Serial.begin(115200);
  ledcSetup(1, 1200, 8);
  ledcSetup(2, 1200, 8);
  ledcSetup(3, 1200, 8);

  ledcAttachPin(LED_R, 1);
  ledcAttachPin(LED_G, 2);
  ledcAttachPin(LED_B, 3);

  ledcWrite(1, 255);
  ledcWrite(2, 255);
  ledcWrite(3, 255);
}

void loop()
{
  for (int i = 0; i < 510; i++)
  {
    if (i >= 0 && i < 255)
      ledcWrite(1, 255 - i);
    if (i >= 255 && i < 510)
      ledcWrite(1, i - 255);

    if (i >= 0 && i < 170)
      ledcWrite(2, 85 + i);
    if (i >= 170 && i < 425)
      ledcWrite(2, 425 - i);
    if (i >= 425 && i < 510)
      ledcWrite(2, i - 425);

    if (i >= 0 && i < 85)
      ledcWrite(3, 85 - i);
    if (i >= 85 && i < 340)
      ledcWrite(3, i - 85);
    if (i >= 340 && i < 510)
      ledcWrite(3, 595 - i);
    delay(10);
  }
}
