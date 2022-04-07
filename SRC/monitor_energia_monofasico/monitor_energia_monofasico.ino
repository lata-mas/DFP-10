#include <WiFiNINA.h>

#include "PZEM004Tv30.h"
#include <SoftwareSerial.h>

#if defined(ESP32)
    #error "Software Serial is not supported on the ESP32"
#endif

/* Use software serial for the PZEM
 * Pin 12 Rx (Connects to the Tx pin on the PZEM)
 * Pin 13 Tx (Connects to the Rx pin on the PZEM)
*/
#if !defined(PZEM_RX_PIN) && !defined(PZEM_TX_PIN)
#define PZEM_RX_PIN 12
#define PZEM_TX_PIN 13
#endif

unsigned long previousMillis = 0;
unsigned long intervalSensors = 10000;

int e = 0;

#include <ArduinoHttpClient.h>


#include "arduino_secrets.h"
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)

WiFiClient wifiClient;
HttpClient httpClient = HttpClient(wifiClient, SECRET_SERVER, SECRET_PORT);

SoftwareSerial pzemSWSerial(PZEM_RX_PIN, PZEM_TX_PIN);
PZEM004Tv30 pzem(pzemSWSerial);

void setup() {
    /* Debugging serial */
    Serial.begin(9600);

  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(1000);
  }

  Serial.println("You're connected to the network");
}

void loop() {

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= intervalSensors) {
      previousMillis = currentMillis;

    Serial.print("Custom Address:");
    Serial.println(pzem.readAddress(), HEX);

    // Read the data from the sensor
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();

    // Check if the data is valid
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    } else if (isnan(current)) {
        Serial.println("Error reading current");
    } else if (isnan(power)) {
        Serial.println("Error reading power");
    } else if (isnan(energy)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {

        // Print the values to the Serial console
        Serial.print("Voltage: ");      Serial.print(voltage);      Serial.println("V");
        Serial.print("Current: ");      Serial.print(current);      Serial.println("A");
        Serial.print("Power: ");        Serial.print(power);        Serial.println("W");
        Serial.print("Energy: ");       Serial.print(energy,3);     Serial.println("kWh");
        Serial.print("Frequency: ");    Serial.print(frequency, 1); Serial.println("Hz");
        Serial.print("PF: ");           Serial.println(pf);

    Serial.println(" ");
    
    sendvolt();
    sendcurrent();
    sendpower();
    sendfp();
    } 

    Serial.println();
    }
}

void sendfp(){

    float pf = pzem.pf();

  if (pf>0) {
    
  
   String payload = "{";
    payload += "fp: ";
    payload += pf;
    payload += "}";

    Serial.println("POST... " + payload);

  
    httpClient.post(SECRET_TOPIC, "application/json", payload);

    int statusCode = httpClient.responseStatusCode();  
    String response = httpClient.responseBody();
    Serial.print("Status code: ");
    Serial.print(statusCode);
    Serial.print(" ");
    Serial.println(response);
    Serial.print(" ");

   }
   else {
    printf("no hay datos validos");
   }
}

void sendvolt(){

    float voltage = pzem.voltage();

     if (voltage>0) {

  
   String payload = "{";
    payload += "voltaje: ";
    payload += voltage;
    payload += "}";

    Serial.println("POST... " + payload);

  
    httpClient.post(SECRET_TOPIC, "application/json", payload);

    int statusCode = httpClient.responseStatusCode();  
    String response = httpClient.responseBody();
    Serial.print("Status code: ");
    Serial.print(statusCode);
    Serial.print(" ");
    Serial.println(response);
    Serial.print(" ");

    }
   else {
    printf("no hay datos validos");
   }
     
}

void sendcurrent(){

    float current = pzem.current();

  if (current>0) {
    
   String payload = "{";
    payload += "corriente: ";
    payload += current;
    payload += "}";

    Serial.println("POST... " + payload);

  
    httpClient.post(SECRET_TOPIC, "application/json", payload);

    int statusCode = httpClient.responseStatusCode();  
    String response = httpClient.responseBody();
    Serial.print("Status code: ");
    Serial.print(statusCode);
    Serial.print(" ");
    Serial.println(response);
    Serial.print(" ");

    }
   else {
    printf("no hay datos validos");
   }
     
}

void sendpower(){

    float power = pzem.power();

  if (power>0) {
  
   String payload = "{";
    payload += "potencia: ";
    payload += power;
    payload += "}";

    Serial.println("POST... " + payload);

  
    httpClient.post(SECRET_TOPIC, "application/json", payload);

    int statusCode = httpClient.responseStatusCode();  
    String response = httpClient.responseBody();
    Serial.print("Status code: ");
    Serial.print(statusCode);
    Serial.print(" ");
    Serial.println(response);
    Serial.print(" ");

    }
   else {
    printf("no hay datos validos");
   }
     
}
