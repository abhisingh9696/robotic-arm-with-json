#include <SoftwareSerial.h> // TX RX software library for bluetooth
#include <ArduinoJson.h>
#include <Servo.h> // servo library 
Servo servo1; // servo name
Servo servo2;
Servo servo3;
Servo servo4;

void setup()
{
  servo1.attach(3); // attach servo signal wire to pin 9
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  //Setup usb serial connection to computer
  Serial.begin(9600);
}

void loop()
{
    while (!Serial) continue;
  StaticJsonBuffer<512> jsonBuffer;
  String json = Serial.readStringUntil('\r');
  if(json != ""){
    Serial.println(json);
    JsonObject& root = jsonBuffer.parseObject(json);
     if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
    }
  int s1 = root["s1"];
  int s2 = root["s2"];
  int s3 = root["s3"];
  int s4 = root["s4"];    
  //{"s1":"90","s2":"90","s3":"90","s4":"90"}
  servo1.write(s1);
  servo2.write(s2);
  servo3.write(s3);
  servo4.write(s4);
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
 }
}
