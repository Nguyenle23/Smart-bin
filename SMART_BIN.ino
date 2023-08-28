#include <Servo.h>                              //Khai báo thư viện điều khiển Servo
const int trig = 8;                             // chân trig của HC-SR04
const int echo = 9;                             // chân echo của HC-SR04

Servo myservo;                                  //Khai báo đối tượng Servo
int servoPin = 7;                               //Chân kết nối Servo với Arduino

void setup() {
  Serial.begin(9600);                           // giao tiếp Serial với baudrate 9600
  pinMode(trig, OUTPUT);                        // chân trig sẽ phát tín hiệu
  pinMode(echo, INPUT);                         // chân echo sẽ nhận tín hiệu
  myservo.attach(servoPin);                     //Khai báo chân kết nối Servo với Arduino
}

void loop() {
  unsigned long duration;  
  int distance;            

  digitalWrite(trig, 0);                        // tắt chân trig
  delayMicroseconds(2);                         // xung có độ dài 2 microSeconds
  digitalWrite(trig, 1);                        // phát xung từ chân trig
  delayMicroseconds(10);                        
  digitalWrite(trig, 0);                        

  duration = pulseIn(echo, HIGH);               // Đo độ rộng xung HIGH ở chân echo
  distance = int(duration / 2 / 29.412);        // Tính khoảng cách đến vật

  Serial.print(distance);
  Serial.println("cm");
  delay(200);

  if (distance <= 50) {
    for (int pos = 0; pos < 180; pos += 1) {
      myservo.write(pos);                       //Gán góc quay cho Servo
      delay(20);
    }
  }
}
