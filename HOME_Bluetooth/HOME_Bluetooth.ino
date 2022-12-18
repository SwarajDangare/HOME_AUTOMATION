/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use Arduino with HC-06/HC-05
  Bluetooth 2.0 Serial Port Profile (SPP) module
  to connect your project to Blynk.

  Note: This only works on Android! iOS does not support SPP :(
        You may need to pair the module with your smartphone
        via Bluetooth settings. Default pairing password is 1234

  Feel free to apply it to any other example. It's simple!

  NOTE: Bluetooth support is in beta!

 *************************************************************/

#define BLYNK_USE_DIRECT_CONNECT

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial BT(0,1 ); // RX, TX

#define BLYNK_PRINT BT
#include <BlynkSimpleSerialBLE.h>

char auth[] = "Xe2xHS5FEL_YwhWbJ_jVtCxhP758JfXl";

WidgetLCD lcd(V2);
String command = "";
void myTimer()
{
  Blynk.virtualWrite(V1,millis()/1000);
  }

void setup()
{
  // Debug console
  Serial.begin(9600);
  
  BT.begin(9600);
  BT.println("Waiting for connections...");
  
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
 
}

void loop()
{
  Blynk.run();
   if(Serial.available() > 0){ 
   lcd.clear();
   lcd.print(0,0,"Connected");
    command = Serial.read();
    Serial.print(command);
}
}
