//Tech Trends Shameer
//Control LED Using Blynk 2.0/Blynk IOT
#define BLYNK_TEMPLATE_ID "TMPLFck2226g"
#define BLYNK_DEVICE_NAME "Control LED"
#define BLYNK_AUTH_TOKEN "47huPqiyh7SAurQMZ-ZIrjxgeubE8zNh"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";  // Enter your Wifi Username
char pass[] = "";  // Enter your Wifi password
int analogPin = A0; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5
int val = 0;
int ledpin = D4;
int ledPin = D0;

void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin,OUTPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{ 
  val = analogRead(analogPin);
  Serial.print("val = ");
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  if (val < 900) { // ค่า 900 สามารถกำหนดปรับได้ตามค่าแสงในห้องต่างๆ
    digitalWrite(ledPin, LOW); // สั่งให้ LED ที่ Pin2 ดับ
  }
  else {
    digitalWrite(ledPin, HIGH); // สั่งให้ LED ที่ Pin2 ติดสว่าง
    
  }
  delay(100);
  Blynk.run(); 
}
