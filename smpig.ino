#include <SoftwareSerial.h>

SoftwareSerial bt(RX_PIN, TX_PIN);

int sen500 = 7;
int sen100 = 6;
int sen50 = 5;
int sen10 = 4;
int led500 = 10;
int led100 = 11;
int led50 = 12;
int led10 = 13;
int buzzer = 9;

int readsen500 = 1;
int readsen100 = 1;
int readsen50 = 1;
int readsen10 = 1;

int totalMoney = 0;


// 톤 배열 수
int numTones = 8;
// 음계 표준 주파수(4옥타브) : 도, 레, 미, 파, 솔, 라, 시, 도
int tones[] = {261, 294, 330, 349, 392, 440, 494, 523};
//tone(buzzer,tone[0]); = 도
//tone(buzzer,tone[1]); = 레
//noTone(buzzer); = 끄기
//tone은 뒤에delay주는 만큼 소리남

void setup() {
  // put your setup code here, to run once:
  pinMode(sen500,INPUT);
  pinMode(sen100,INPUT);
  pinMode(sen50,INPUT);
  pinMode(sen10,INPUT);
  pinMode(led500,OUTPUT);
  pinMode(led100,OUTPUT);
  pinMode(led50,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  bt.begin(9600);

}

void loop() {  
  // put your main code here, to run repeatedly:
  readsen500 = digitalRead(sen500);
  readsen100 = digitalRead(sen100);
  readsen50 = digitalRead(sen50);
  readsen10 = digitalRead(sen10);

  Serial.print("500 : ");
  Serial.println(readsen500);
  Serial.print("100 : ");
  Serial.println(readsen100);
  Serial.print("50 : ");
  Serial.println(readsen50);
  Serial.print("10 : ");
  Serial.println(readsen10);
  
  if (readsen500 == 0) {
    Serial.println("500");
     bt.print("a");
     digitalWrite(led500, HIGH);
     tone(buzzer, tones[1]);
     delay(500);
     digitalWrite(led500, LOW);
     totalMoney+=500;
    
  } else if (readsen100 == 0) {
    Serial.println("100");
    bt.print("b");
      digitalWrite(led100, HIGH);
      tone(buzzer, tones[2]);
      delay(500);
      digitalWrite(led100, LOW);
      totalMoney+=100;
      
      
  } else if (readsen50 == 0) {
    Serial.println("50");
    bt.print("c");
    digitalWrite(led50, HIGH);
    tone(buzzer, tones[3]);
    delay(500);
    digitalWrite(led50, LOW);
    totalMoney+=50;
  } else if(readsen10 == 0) {
    Serial.println("10");
    bt.print("d");
    digitalWrite(led10, HIGH);
    tone(buzzer, tones[4]);
    delay(500);
    digitalWrite(led10, LOW);
    totalMoney+=10;
  } else
    noTone(buzzer);
}
