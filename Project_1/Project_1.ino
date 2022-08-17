/* CONTROL LED'S ON AND OFF*/

void setup() {
  // put your setup code here, to run once:
  /*pinMode(pin, mode)
    Function：设置一个引脚（pin）作为GPIO时的I/O模式.
    Parameters：
            pin：# of pin
            mode：GPIO的I/O模式，取值有3种
                  1.INPUT ：作为数字输入
                  2.OUTPUT ：作为数字输出
                  3.INPUT_PULLUP：作为数字输入，且使能引脚的内部上拉电阻
  */
  pinMode(2, OUTPUT);
  pinMode(0, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*digitalWrite(pin,value)
    Function：设置一个数字输出引脚的输出电平值，HIGH或者LOW
    Parameters：
            pin：引脚编号。此引脚必须在之前使用pinMode设置为OUTPUT模式
            value：2个值
                  1.LOW：输出低电平
                  2.HIGH：输出高电平

    int digitalRead(pin)
    Function：读取一个数字输入引脚的电平值
    Return：HIGH（高电平）或者LOW（低电平）
    Parameters：
            pin：引脚编号。
  */
  if (digitalRead(0))
  {
    while (digitalRead(0));
    digitalWrite(2, !digitalRead(2));
  }

}
