
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwmRight = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwmLeft = Adafruit_PWMServoDriver(0x41);


#define SERVOMIN 150   // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600   // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600      // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2400     // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50  // Analog servos run at ~50 Hz updates

#define PHOTORESISTOR_COUNT 8

long DELAY_SHORT = 500;
long DELAY_LONG = 1000;
long DELAY_BEETWEEN_CHECKS = 10 * 1000;


#define S2_DOWN 110
#define S2_UP 65
#define S2_REST 110

#define S3_DOWN 30
#define S3_UP 160
#define S3_REST 150

//Standard Servo
#define SHOULDER_MID 90
#define SHOULDER_OFFSET 45

//Servo Number
uint8_t servoL1S1 = 0;
uint8_t servoL1S2 = 1;
uint8_t servoL1S3 = 10;

uint8_t servoL2S1 = 11;
uint8_t servoL2S2 = 12;  //Left pwm
uint8_t servoL2S3 = 2;

uint8_t servoL3S1 = 9;
uint8_t servoL3S2 = 3;
uint8_t servoL3S3 = 8;


uint8_t servoL4S1 = 7;
uint8_t servoL4S2 = 13;
uint8_t servoL4S3 = 14;

uint8_t servoL5S1 = 15;
uint8_t servoL5S2 = 12;  //Right pwm
uint8_t servoL5S3 = 6;

uint8_t servoL6S1 = 5;
uint8_t servoL6S2 = 4;
uint8_t servoL6S3 = 3;

uint8_t servoArray[18] = {
  servoL1S1, servoL1S2, servoL1S3,
  servoL2S1, servoL2S2, servoL2S3,
  servoL3S1, servoL3S2, servoL3S3,
  servoL4S1, servoL4S2, servoL4S3,
  servoL5S1, servoL5S2, servoL5S3,
  servoL6S1, servoL6S2, servoL6S3
};
/*
LEGS:
  3     6
2         5
  1     4
*/


//Photoresistors
// 14, 27, 26, 25, 33, 32, 35, 34
int photoResistor1 = 14;
int photoResistor2 = 27;
int photoResistor3 = 26;
int photoResistor4 = 25;
int photoResistor5 = 33;
int photoResistor6 = 32;
int photoResistor7 = 35;
int photoResistor8 = 34;

int photoresistorArray[] = {
  photoResistor1,
  photoResistor2,
  photoResistor3,
  photoResistor4,
  photoResistor5,
  photoResistor6,
  photoResistor7,
  photoResistor8
};


void setup() {
  Serial.begin(9600);
  Serial.println("Starting with 18 Servos and 8 Light Sensors");

  initPWM(pwmRight);
  initPWM(pwmLeft);

  delayShort();
  allServoResetPos();
}

void loop() {
  for (int i = 0; i < (sizeof(photoresistorArray) / sizeof(photoresistorArray[0])); i++) {
    Serial.println("Photoresistor " + i + ": " + analogRead(photoresistorArray[i]))
  }
  delayShort();
}


void initPWM(Adafruit_PWMServoDriver pwm) {
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
}

void moveServo(Adafruit_PWMServoDriver pwm, uint8_t servoName, uint8_t degree) {
  pwm.setPWM(servoName, 0, degreeToPulse(degree));
}


void allServoResetPos() {
  for (int i = 0; i < (sizeof(servoArray) / sizeof(servoArray[0])); i++) {
    int angle;
    int leg = (i / 3) + 1;
    int servo = i % 3;
    if (servo == 1) {              //Leg X Servo 1 (Shouler)
      if (leg == 1 || leg == 4) {  // Legs in front
        angle = SHOULDER_MID - SHOULDER_OFFSET;
      }
      if (leg == 2 || leg == 5) {  // Legs in mid
        angle = SHOULDER_MID;
      }
      if (leg == 3 || leg == 6) {  // Legs in back
        angle = SHOULDER_MID + SHOULDER_OFFSET;
      }
    }
    if (servo == 2) {  // Middle Servo
      angle = S2_REST;
    }
    if (servo == 0) {  // Ground Servo
      angle = S3_REST;
    }

    if (leg <= 3) {
      moveServo(pwmLeft, servoArray[i], angle);
    } else {
      moveServo(pwmRight, servoArray[i], angle);
    }
  }
}


uint16_t degreeToPulse(uint8_t degree) {
  return map(degree, 0, 180, SERVOMIN, SERVOMAX);
}
