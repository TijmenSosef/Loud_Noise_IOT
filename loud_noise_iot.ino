const char* ssid = "SSID"; // Your Wifi name (SSID)
const char* pass = "password"; // Your Wifi Password
const int noisethreshold = 65; // Change this value for the sensitivity of the code
const char* apiCall = "http://maker.ifttt.com/trigger/{event}/with/key/{key}"; //MAKE SURE THIS IS HTTP NOT HTTPS ## Api call for IFTTT 

#define SENSOR_PIN A0 // The sensor input


#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

const int sampleWindow = 30;
unsigned int sample;


void setup() {

  Serial.begin(9600);
  pinMode (SENSOR_PIN, INPUT); // Set the signal pin as input  



  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf(" WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, pass);
}

void loop() {

   unsigned long startMillis= millis(); // Start of sample window
   float peakToPeak = 0; // peak-to-peak level
 
   unsigned int signalMax = 0; //minimum value
   unsigned int signalMin = 1024; //maximum value
 
  // collect data to calculate the noise level
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(SENSOR_PIN); //get reading from microphone
      if (sample < 1024) // Don't collect weird values
      {
         if (sample > signalMax)
         {
            signalMax = sample; // save just max value
         }
         else if (sample < signalMin)
         {
            signalMin = sample; // save the min value
         }
      }
   }
 
   peakToPeak = signalMax - signalMin; // max - min = peak-peak amplitude
   int noise = map(peakToPeak,20,900,49.5,90); //calibrate for deciBels
 

  // when the threshold is reached send a notification
  if (noise > noisethreshold){
    sendnotification();
    delay(100000); 
  }
   

  Serial.println(noise);
  delay(100); 
}


void sendnotification(){
    if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    Serial.print("API call Begining.\n");
    if (http.begin(client, apiCall)) {  // HTTP


      Serial.print("Making Get Call");
      // Send a http get
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("Response code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("Call failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.println("Unable to connect");
    }
  }
}
