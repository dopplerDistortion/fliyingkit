/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  PWM test - this will drive 16 PWMs in a 'wave'

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These drivers use I2C to communicate, 2 pins are required to  
  interface.

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(&Wire, 0x40);

int s0 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel PWM test!");

  pwm.begin();
  pwm.setPWMFreq(60);  // This is the maximum PWM frequency

  // if you want to really speed stuff up, you can go into 'fast 400khz I2C' mode
  // some i2c devices dont like this so much so if you're sharing the bus, watch
  // out for this!
  Wire.setClock(400000);
}

void loop() {

  static int v = 0;

  if(Serial.available()){
    char ch = Serial.read();
    

    switch(ch){
    
      case '0'...'9':
        v = v * 10 + ch - '0';
        break;

      case 'a':
        pwm.setPWM(0, 0, v);
        v = 0;
        break;

      case 'b':
        pwm.setPWM(1, 0, v);
        v = 0;
        break;

      case 'c':
        pwm.setPWM(2, 0, v);
        v = 0;
        break;

      case 'd':
        pwm.setPWM(3, 0, v);
        v = 0;
        break;

      case 'e':
        pwm.setPWM(4, 0, v);
        v = 0;
        break;

      case 'f':
        pwm.setPWM(5, 0, v);
        v = 0;
        break;
      }
  
//  pwm.setPWM(0, 0, 240);
//  delay(1000);
//  pwm.setPWM(0, 0, 380);
//  delay(1000);
  }
}

