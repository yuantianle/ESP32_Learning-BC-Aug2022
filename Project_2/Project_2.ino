/*BREATH LIGHT*/

bool add_status = true;
void setup()
{
  pinMode(2,OUTPUT);
  ledcSetup(2,1200,8);
  ledcAttachPin(2,2);
}

void loop()
{
   for(int i = 0 ; i<256; i++)
   {
    if(add_status)
    {
      ledcWrite(2,i);
    }
    else
    {
      ledcWrite(2,256-i);
    }
    delay(5);
  }
  add_status = !add_status;
}
