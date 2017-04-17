
#include <LiquidCrystal.h>
#include <Servo.h>
int num = 0;

int SOL_PIN = 7;
int SOL_OUT = 8;
int wheel;

int blueState = 0;
int yellowState = 0;
int blueBtn = 4;
int yellowBtn = 5;

Servo servo;
bool active;
int count;

// LCD
LiquidCrystal lcd(8, 13, 9, 10, 11, 12);


void setup() {
  // put your setup code here, to run once:

  pinMode(blueBtn, INPUT);
  pinMode(yellowBtn, INPUT);
  pinMode(SOL_PIN, OUTPUT);
  Serial.begin(115200);
  active = false;
  lcd.begin(16, 2);
  lcd.print("Waiting");
  count = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  blueState = digitalRead(blueBtn);

  if(blueState == LOW){
    active = true;

  }

  while(active){

    spin();
    delay(2000);
    can();
}

  
}

void spin() {
  servo.attach(6);
  servo.writeMicroseconds(1200);
  delay(150);
  servo.detach();
}

void can(){
  digitalWrite(SOL_PIN, HIGH);
  Serial.println("Pulling");
  print("pull");
  delay(1000);

  digitalWrite(SOL_PIN, LOW);
  Serial.println("Pushing");
  print("push");
  delay(2000);
  count++;

  // while(Serial.available()) {
  //       num = Serial.parseInt();
  // }

  // if(blueState == LOW){

  // }

  // if(num == 1){ // Pull In
  //   digitalWrite(SOL_PIN, HIGH);
  //   Serial.println("Pulling In");
  // }

  // else if(num == 0){ // Pull Out

  //   digitalWrite(SOL_PIN, LOW);
  //   Serial.println("Pushing Out");
  // }

}

void print(String str){
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(str);
   delay(50);
}