#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

DFRobotDFPlayerMini mp3;
BluetoothSerial SerialBT;

//volatile int nosong = 1;
//bool pauseState = false; 
//const int playButton = 3;
const int pauseButton = 25;
const int nextButton = 33;
const int prevButton = 26;
const int pinpotensio = 34;
int potensio = 0;
volatile int volume = 0;
bool modeplay=0;
bool modepause=1;

void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600);
  delay(100);

  pinMode(nextButton, INPUT);
  pinMode(prevButton, INPUT);
//pinMode(playButton, INPUT);
  pinMode(pauseButton, INPUT);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!mp3.begin(Serial2)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));
  mp3.setTimeOut(500); //Set serial communictaion time out 500ms
  mp3.volume(30);  //Set volume value (0~30).
//  delay(1000);
//  mp3.play(98);  //Play the first mp3

  SerialBT.begin("ESP32DF"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  delay(1000);
}
void loop()
{
  if (SerialBT.available()) {
    //Serial.write(SerialBT.read());
    char dataPlay = SerialBT.read();
    switch(dataPlay){
      case '1': mp3.start(); break;
      case '0': mp3.pause(); break;
      case 'P': mp3.previous(); break;
      case 'N': mp3.next(); break;
    }
    Serial.write(dataPlay); 
  }
  potensio = analogRead(pinpotensio);
  /*Serial.println("potensio = ");
  Serial.println(potensio);*/
  volume = map(potensio, 0, 4095, 0, 100);
  mp3.volume(volume);
  //Serial.println("volume : ");
  //Serial.println(volume);
  
  byte Nbuttonstate = digitalRead(nextButton);
  byte Pvbuttonstate = digitalRead(prevButton);
  byte Pbuttonstate = digitalRead(pauseButton);
  //byte Plbuttonstate = digitalRead(playButton);

  if (Nbuttonstate == HIGH){
    Serial.println("testnext");
    mp3.next();
    delay(300);
  }
  else if (Pvbuttonstate == HIGH){
    Serial.println("testprev");
    mp3.previous();
    delay(300);
  }
  else if (Pbuttonstate == HIGH){
    /*Serial.println("testpause");
    mp3_pause();
    delay(300);*/
    if(modeplay == 0 && modepause == 1){
      Serial.println("testplay");
      mp3.start();
      modeplay = 1;
      modepause = 0;
      delay(300);
    }else if(modeplay == 1 && modepause == 0){
      Serial.println("testpause");
      mp3.pause();
      modeplay = 0;
      modepause = 1;
      delay(300);
    }
  }
}
