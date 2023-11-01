
// #include <Arduino.h>
// #include "NTP.h"
// #include <WiFi.h>

// const char *ssid     = "Lekker coffee"; // your network SSID
// const char *password = "NasiGoreng23"; // your network PW

// WiFiUDP wifiUdp;
// NTP ntp(wifiUdp);
// void setup()
// {
// Serial.begin(9600);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.println("Connecting ...");
//     delay(500);
//     }
//   Serial.println("Connected");  
//  ntp.ruleSTD("UTC", Second, Fri, Jul, 14, 420);
//  ntp.begin();
//   Serial.println("start NTP");
// }

// void loop()
// {
//  ntp.update();
//   Serial.println(ntp.formattedTime("%d. %B %Y - %T")); // dd. Mmm yyyy
//   delay(1000);
// }
// #include <Arduino.h>
// #include <WiFi.h>
// #include <time.h>

// #define TIME_ZONE_OFFSET_HRS 7 

// void setup() {
//   Serial.begin(115200);
  
//   // Connect to WiFi
//   WiFi.begin("Lekker coffee", "NasiGoreng23");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(100);
//     Serial.println("Connecting to WiFi...");
//   }
  
//   // Set hostname
//   WiFi.setHostname("ESP-NTP");

//   // Initialize time
//   configTime(TIME_ZONE_OFFSET_HRS * 3600, 0, "pool.ntp.org");
// }

// void loop() {
//   delay(1000);
  
//   time_t now = time(nullptr);
  
//   if (now > 0) {
//     Serial.println("Time sinkronisasi dengan NTP");
    
//     struct tm *timeInfo;
//     timeInfo = localtime(&now);
    
//     // Format the date and time for Indonesia (GMT+7)
//     char timeString[40];
//     strftime(timeString, sizeof(timeString), "%A, %d-%m-%Y %H:%M:%S", timeInfo);
    
//     Serial.println("Hari,Tanggal,Jam: " + String(timeString));
//   } else {
//     Serial.println("# Time tidak sinkron dengan NTP !");
//     return; // Do not print time
//   }
// }
// #include <Arduino.h>
// #include <Wire.h>
// #include <RTClib.h>

// RTC_DS3231 rtc;

// const char* daysOfWeek[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

// void setup() {
//   Serial.begin(115200);
//   Wire.begin();

//   if (!rtc.begin()) {
//     Serial.println("RTC tidak terdeteksi!");
//     while (1);
//   }

  // Uncomment baris di bawah ini jika ingin mengatur waktu RTC secara manual
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
// }

// void loop() {
//   DateTime now = rtc.now();

//   Serial.print("Hari: ");
//   Serial.println(daysOfWeek[now.dayOfTheWeek()]);

//   Serial.print("Tanggal: ");
//   Serial.print(now.day());
//   Serial.print(" ");
//   Serial.print(now.month());
//   Serial.print(" ");
//   Serial.println(now.year());

//   Serial.print("Waktu: ");
//   Serial.print(now.hour());
//   Serial.print(":");
//   Serial.print(now.minute());
//   Serial.print(":");
//   Serial.println(now.second());

//   delay(1000);
// }

#include <ESP32Time.h>


//ESP32Time rtc;
ESP32Time rtc(3600);  // offset in seconds GMT+1

void setup() {
  Serial.begin(115200);
  rtc.setTime(15, 22 , 15, 14, 7, 2023);  // 17th Jan 2021 15:24:30
  //rtc.setTime(1609459200);  // 1st Jan 2021 00:00:00
  //rtc.offset = 7200; // change offset value

/*---------set with NTP---------------*/
//  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
//  struct tm timeinfo;
//  if (getLocalTime(&timeinfo)){
//    rtc.setTimeStruct(timeinfo); 
//  }
}

void loop() {
//  Serial.println(rtc.getTime());          //  (String) 15:24:38
//  Serial.println(rtc.getDate());          //  (String) Sun, Jan 17 2021
//  Serial.println(rtc.getDate(true));      //  (String) Sunday, January 17 2021
//  Serial.println(rtc.getDateTime());      //  (String) Sun, Jan 17 2021 15:24:38
//  Serial.println(rtc.getDateTime(true));  //  (String) Sunday, January 17 2021 15:24:38
//  Serial.println(rtc.getTimeDate());      //  (String) 15:24:38 Sun, Jan 17 2021
//  Serial.println(rtc.getTimeDate(true));  //  (String) 15:24:38 Sunday, January 17 2021

//  Serial.println(rtc.getMicros());        //  (long)    723546
//  Serial.println(rtc.getMillis());        //  (long)    723
//  Serial.println(rtc.getEpoch());         //  (long)    1609459200
//  Serial.println(rtc.getSecond());        //  (int)     38    (0-59)
//  Serial.println(rtc.getMinute());        //  (int)     24    (0-59)
//  Serial.println(rtc.getHour());          //  (int)     3     (0-12)
//  Serial.println(rtc.getHour(true));      //  (int)     15    (0-23)
//  Serial.println(rtc.getAmPm());          //  (String)  pm
//  Serial.println(rtc.getAmPm(true));      //  (String)  PM
//  Serial.println(rtc.getDay());           //  (int)     17    (1-31)
//  Serial.println(rtc.getDayofWeek());     //  (int)     0     (0-6)
//  Serial.println(rtc.getDayofYear());     //  (int)     16    (0-365)
//  Serial.println(rtc.getMonth());         //  (int)     0     (0-11)
//  Serial.println(rtc.getYear());          //  (int)     2021

//  Serial.println(rtc.getLocalEpoch());         //  (long)    1609459200 epoch without offset
  // Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));   // (String) returns time with specified format 
  // formating options  http://www.cplusplus.com/reference/ctime/strftime/


  struct tm timeinfo = rtc.getTimeStruct();
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  
  delay(1000);
}


