/*BREATH LIGHT*/

bool add_status = true;
void setup()
{
  /*设置通道:
   *ledcSetup(channel,freq,bit_num)
            Parameters:
                    1.channel : LEDC的PWM通道参数,可选0~15
                    2.freq : 10Hz到40MHz , 但较高的频率精确度低 
                    3.bit_num: 占空比分辨率(可选1~16), 比如bit_num=8 则范围 0~2的8次方 , 也就是0~255

                    频率  位深  过渡的可用步骤
                    1220赫兹  16  65536
                    2441赫兹  15  32768
                    4882赫兹  14  16384
                    9765Hz  13  8192
                    19531赫兹 12  4096
                    
    通道与引脚映射:
    ledcAttachPin(pin,channel)
    
    取消引脚的PWM映射:
    ledcDetachPin(pin)
  */
  pinMode(2, OUTPUT);
  ledcSetup(2, 1200, 8);
  ledcAttachPin(2, 2);
}

void loop()
{
  /*向指定通道写入占空比: 
    ledcWrite(channel,duty)
   */
  for (int i = 0 ; i < 256; i++)
  {
    if (add_status)
    {
      ledcWrite(2, i);
    }
    else
    {
      ledcWrite(2, 256 - i);
    }
    delay(5);
  }
  add_status = !add_status;
}
