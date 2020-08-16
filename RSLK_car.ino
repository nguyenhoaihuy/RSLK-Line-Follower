#include <ECE3.h>

uint16_t sensorValues[8];

const int left_nslp_pin=31; // nslp ==> awake & ready for PWM
const int left_dir_pin=29;
const int left_pwm_pin=40;

const int right_nslp = 11;
const int right_dir = 30;
const int right_pwm = 39;

const int LED_RF = 41;
const int LF = 51;
 
const int SPEED = 50;

double left_spd = SPEED;
double right_spd = SPEED;

double kp = 6.5;
double kd = 0.55;
double last_error;
int counter = 0;

void setup()
{
 ECE3_Init();
//  Serial.begin(9600); // set the data rate in bits per second for serial data transmission
//  delay(2000);
// put your setup code here, to run once:
  pinMode(left_nslp_pin,OUTPUT);
  pinMode(left_dir_pin,OUTPUT);
  pinMode(left_pwm_pin,OUTPUT);

   pinMode(right_nslp,OUTPUT);
  pinMode(right_dir,OUTPUT);
  pinMode(right_pwm,OUTPUT);

//left
  digitalWrite(left_dir_pin,LOW);
  digitalWrite(left_nslp_pin,HIGH);
  
  digitalWrite(right_dir,LOW);
  digitalWrite(right_nslp,HIGH);


  pinMode(LED_RF, OUTPUT);
  pinMode(LF, OUTPUT);
  // ECE3_Init();
  
  
//  ECE3_Init();

// set the data rate in bits/second for serial data transmission
  Serial.begin(9600); 
  delay(2000); //Wait 2 seconds before starting 
}

bool isEnd()
{ int sum = 0; 
  for (int i = 0; i < 8; i++)
  {
    sum +=  sensorValues[i];
  }
  //Serial.println(sum);
  
   if (sum > 15500){
    return true;
   }
   else 
      return false;
}

bool isAtInter(){
  int sum = 0; 
  for (int i = 0; i < 8; i++)
  {
    sum +=  sensorValues[i];
  }
  Serial.println(sum);
  
   if (sum > 8000){
    return true;
   }
   else 
      return false;
}

void loop()
{
  //if ( !isAtInter() ){
    // read raw sensor values
    ECE3_read_IR(sensorValues);
    // print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
    // 2500 means minimum reflectance
    double error = 0;
    
    for (unsigned char i = 0; i < 8; i++)
    {
      //Serial.print(sensorValues[i]);
      error += (i*1.0-3.5)*(sensorValues[i]*1.0/1000);
      //Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
    }
  
    //Serial.print(error-0.5);
    //Serial.println();
    error -= 0.3;
    left_spd = SPEED-(error*kp+(error-last_error)/0.05*kd);
    right_spd = SPEED+(error*kp+(error-last_error)/0.05*kd);
    last_error = error;
    if ( !isAtInter()){
      analogWrite(left_pwm_pin,left_spd);
      analogWrite(right_pwm,right_spd);
    } else{
      if (!isEnd()){
       analogWrite(left_pwm_pin,SPEED);
      analogWrite(right_pwm,SPEED);
      }
    }
  //}
   

  
  if ( isEnd())
  {
    counter++;
    if (counter==2){
      analogWrite(left_pwm_pin,0);
      analogWrite(right_pwm,0);
       delay(10000);
    }
    left_spd = 128;
   right_spd = 125;
   digitalWrite(right_dir,HIGH);
   analogWrite(left_pwm_pin,left_spd);
  analogWrite(right_pwm,right_spd); 
  
  delay(350);
  digitalWrite(right_dir,LOW);
  } 

  delay(50);
}