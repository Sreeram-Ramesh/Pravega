#include <SparkFun_TB6612.h>

#define AIN1 D21
#define BIN1 D25
#define AIN2 D22
#define BIN2 D33
#define PWMA D23
#define PWMB D32
#define STBY D19

const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

int lsp, rsp;
int lfspeed = 125;

int speed = 205 ;

int a = 0 ;

void setup() {
  // put your setup code here, to run once:

}

void Left (){
  lsp = 0; rsp = lfspeed;
  motor1.drive(lsp);
  motor2.drive(155);
}

void Straight (){
  motor1.drive(lfspeed);
  motor2.drive(lfspeed);
}

void Backward (){
  lsp = -lfspeed; rsp = lfspeed;
  motor1.drive(155);
  motor2.drive(-155);
}

void Right (){
  lsp = lfspeed; rsp = 0;
  motor1.drive(155);
  motor2.drive(rsp);
}

void halt () {
  motor1.drive(0);
  motor2.drive(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Straight();
  delay(500);
  Right();
  delay(500);
  Left();
  delay(500);
  Backward();
  delay(500);
  halt();
  delay(5000);
}
