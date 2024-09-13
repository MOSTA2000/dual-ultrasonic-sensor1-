#define BLYNK_TEMPLATE_ID "TMPL6IFPYvaDL"
#define BLYNK_TEMPLATE_NAME "Dual Ultrasonic Sensors"
#define BLYNK_AUTH_TOKEN "gwEznwC3-HkghOED1-Nf1YqGlFcKEfTL" // Same token for both ESP8266 modules

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "AliNet(03426440)";          
char pass[] = "1234567$";        

const int trigPin = D1;          
const int echoPin = D2;          

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Blynk.run();
  measureDistance();
  Blynk.virtualWrite(V1, distance);  // Send data to Virtual Pin V1
  delay(1000);                       
}

void measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}
