// C++ code
//
#include<Servo.h>
int batasNormal = 37;
Servo portal;
void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  portal.attach(13);
  portal.write(0);
}

void loop()
{
  int x=analogRead(A1); //baca suhu
  
  //ubah ke celsius:
  int celsius = map(((x - 20) * 3.04), 0, 1023, -40, 125);
  
  if(celsius<=batasNormal){
    digitalWrite(3,1);
    digitalWrite(4,0);
    portal.write(90); //portal terbuka 
    delay(2000);
  } else {
    digitalWrite(3,0);
    digitalWrite(4,1);
    portal.write(0); //portal tertutup
    delay(2000);
  }
  Serial.println(celsius);
  delay(250);
}
