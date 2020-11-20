//#include <SoftwareSerial.h>
//SoftwareSerial mybluetooth(0,1);

#include<Servo.h>

char dataBT;
int pin_kiri = 9;
int pin_kanan = 10;

Servo Myservo;
int pos;

void setup(){
  Serial.begin(9600);
  Myservo.attach(3);
}

void loop() {
  if(Serial.available() > 0){
    dataBT = Serial.read();
    Serial.print(dataBT);
    
    if(dataBT == '1'){
      analogWrite(pin_kiri, 0);
      analogWrite(pin_kanan, 255);
    }
    else if(dataBT == '2'){
      analogWrite(pin_kanan, 0);
      analogWrite(pin_kiri, 255);
    }
    else if(dataBT == '3'){
      analogWrite(pin_kiri, 255);
      analogWrite(pin_kanan, 255);
    }
    else if(dataBT == '0'){
      analogWrite(pin_kanan, 0);
      analogWrite(pin_kiri, 0);
    }
  }
}
