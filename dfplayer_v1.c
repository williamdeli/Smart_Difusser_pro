#include <DFPlayer_Mini_Mp3.h>  //memanggil library DFPlayer mini 
#include <SoftwareSerial.h>    //memanggil library SoftwareSerial 

SoftwareSerial mSerial(3,2); // Declare pin RX & TX 
void setup () {  

 mSerial.begin (9600); 

 mp3_set_serial (mSerial); //set softwareSerial for DFPlayer 

delay(10);   // wait 1ms for respon command 

 mp3_set_volume (2);//et Volume module DFPlayer 

 delay(1000); 

} 

void loop () {    

mp3_play (1); //Play mp3 0001.mp3 dalam folder mp3 di memory 

mp3_next(); 

delay(279000); 

mp3_play(2); 

mp3_next(); 

delay(232000); 

mp3_play(3); 

mp3_next(); 

delay(176000); 

} 
