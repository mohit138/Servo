#include <Adafruit_PWMServoDriver.h>
#include<Wire.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


float UpperServoAngle;
float LowerServoAngle;

float Time_loop=4000 ;
float T;

class servo
{
  public:
  float servoMin,servoMax,servoAngle;
  servo(int pin,float ServoMin,float ServoMax);
  void rotate(float angle);
}
servo Servo_L(1,100,570); //calliberate min and max values
servo Servo_U(2,100,590);

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  
  T=Time_loop/4;
  t_gate_up=T/10;
  t_gate_down=T/10;
  t_gate_ground=T/5;
  UpperServoAngle=45;
  LowerServoAngle=30;

  if(Servo_L.read()==LowerServoAngle)
}

void loop() {
  if((UpperServoAngle==45)&&(LowerServoAngle==30))
  { 
    flag_ground=1;
    flag_up=0;
    flag_ground=0;
  }
  if((UpperServoAngle==60)&&(LowerServoAngle==0))
  { 
    flag_ground=0;
    flag_up=1;
    flag_ground=0;
  }
  if((UpperServoAngle==65)&&(LowerServoAngle==65))
  { 
    flag_ground=0;
    flag_up=0;
    flag_down=1;
  }

  if(flag_ground==1)
  {.
      if((UpperServoAngle>45||UpperServoAngle>60)&&(LowerServoAngle>0||LowerServoAngle<30))
      {
        gate_ground();
      }
  }
  if(flag_up==1)
  {
      if((UpperServoAngle>60||UpperServoAngle>65)&&(LowerServoAngle>0||LowerServoAngle<65))
      {
        gate_up();
      }
  }
  if(flag_down==1)
  {
      if((UpperServoAngle>45||UpperServoAngle>65)&&(LowerServoAngle>30||LowerServoAngle<65))
      {
        gate_down();  
      }
  }
}

void gate_ground()
{
    LowerServoAngle=LowerServoAngle-2;
    UpperServoAngle++;
    delay(t_gate_ground);
}
void gate_up()
{
    LowerServoAngl=LowerServoAngle+13;
    UpperServoAngle++;
    delay(t_gate_up);
}
void gate_down()
{
    LowerServoAngl=LowerServoAngle-7;
    UpperServoAngle=UpperServoAngle+3;
    delay(t_gate_down);
}

////////////////////////////////////////////////////////////////////generalised functions/////////////////////////////////////////////

servo :: servo(int pin,float ServoMin,float ServoMax)
{
  servoNum=pin;
  servoMin=ServoMin;
  servoMax=ServoMax;
}
void servo :: rotate(float angle)
{
  servoAngle=((servoMax-servoMin)/180.0)*angle+servoMin;
  pwm.setPWM(servoNum,0,servoAngle);
}

