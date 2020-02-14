#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <ThingsBoard.h>
#define WIFI_AP "IER"
#define WIFI_PASSWORD "acadier2014"
#define TOKEN "1HVYQrDTzDzwmKFuLDRu"
char thingsboardServer[] = "iot.ier.unam.mx";
// Initialize the Ethernet client object
WiFiEspClient espClient;
ThingsBoard tb(espClient);
SoftwareSerial soft(2, 3); // RX, TX
int status = WL_IDLE_STATUS;
unsigned long lastSend;
#include <Filters.h> //Easy library to do the calculations
#include <Wire.h>
float testFrequency = 60; // test signal frequency (Hz)
float windowLength = 40.0 / testFrequency; // how long to average the signal, for statistist
int Sensor = 0; //Sensor analog input, here it's A0
float intercept = -0.04; // to be adjusted based on calibration testing
float slope = 0.0405; // to be adjusted based on calibration testing
float current_Volts; // Voltage
float voltajeSensor;
float corriente = 0;
float Sumatoria = 0;
long tiempo = millis();
int pin = 13;
int N = 0;
unsigned long printPeriod = 1000; //Refresh rate
unsigned long previousMillis = 0;
float rads = 57.29577951; // 1 radian = aprox. 57 grados
float degree = 360;
float frequency = 60;
float nano = 1 * pow (10, -6); // Factor de multiplicación para convertir nano segundos en segundos
// Definir flotantes para contener cálculos
float pf;
float angle;
float pf_max = 0;
float angle_max = 0;
int ctr;
// Definir flotantes para contener cálculos
void setup() { // initialize serial for debugging
  Serial.begin(9600);
  InitWiFi();
  lastSend = 0;
  pinMode(pin, INPUT);
}
void loop() {
  status = WiFi.status();
  if ( status != WL_CONNECTED) {
    while ( status != WL_CONNECTED) {
      Serial.print("Attempting to connect to WPA SSID: ");
      Serial.println(WIFI_AP);
      // Connect to WPA/WPA2 network
      status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      delay(500);
    }
    Serial.println("Connected to AP");
  }
  if ( !tb.connected() ) {
    reconnect();
  }
  if ( millis() - lastSend > 1000 ) { // Update and send only after 1 seconds
    getcorriente();
    getvoltaje();
    getpower();
    lastSend = millis();
  }
  tb.loop();
}
//potencia
void getvoltaje()
{
  Serial.println("Collecting energy data.");
  RunningStatistics inputStats; //Easy life lines, actual calculation of the RMS requires a load of coding
  inputStats.setWindowSecs( windowLength );
  float Irms = getcorriente();
  float pf = getpower();
  Sensor = analogRead(A1); // read the analog in value:
  inputStats.input(Sensor); // log to Stats function
  if ((unsigned long)(millis() - previousMillis) >= printPeriod) {
    previousMillis = millis(); // update time every second
    current_Volts = intercept + slope * inputStats.sigma(); //Calibartions for offset and amplitude
    current_Volts = current_Volts; //Further calibrations for the amplitude
  }
  if (isnan(current_Volts)) {
    Serial.println("Failed to read from sensor!");
    return;
  }
  Serial.println("Sending data to ThingsBoard:"); Serial.print("voltaje");
  Serial.println(" corriente "); Serial.println(Irms);
  tb.sendTelemetryFloat("voltaje", current_Volts);
  tb.sendTelemetryFloat("corriente", Irms);
  tb.sendTelemetryFloat("factor_p", pf);
}
float getcorriente()
{
  float voltajeSensor;
  float corriente = 0;
  float Sumatoria = 0;
  long tiempo = millis();
  int N = 0;
  while (millis() - tiempo < 500) //Duración 0.5 segundos(Aprox. 30 ciclos de 60Hz)
  {
    voltajeSensor = analogRead(A3) * (1.1 / 1023.0); //voltaje del sensor de corriente alterna
    corriente = voltajeSensor; //corriente=VoltajeSensor*(100A/1V)
    Sumatoria = Sumatoria + sq(corriente); //Sumatoria de Cuadrados
    N = N + 1;
    delay(1);
  }
  Sumatoria = Sumatoria * 2; //Para compensar los cuadrados de los semiciclos negativos.
  corriente = sqrt((Sumatoria) / N); //Ecuación del RMS corriente=corriente;
  return;
}
float getpower()
{ for (ctr = 0; ctr <= 4; ctr++) // Realice 4 mediciones y luego reinicie
  {
    // 1ª línea calcula el ángulo de fase en grados a partir del impulso de tiempo diferenciado
    // La función COS usa radianes no grados. Por lo tanto, la conversión se realizó dividiendo el ángulo / 57.2958
    angle = ((((pulseIn(pin, HIGH)) * nano) * degree) * frequency);
    pf = cos (angle / rads);
    if (angle > angle_max) // Probar si el ángulo es el ángulo máximo
    {
      angle_max = angle; // Si el registro máximo en la variable "angle_max"
      pf_max = cos(angle_max / rads); // Calc PF de "angle_max"
    }
  }
  if (angle_max > 360) // Si el cálculo es mayor que 360, haga lo siguiente
  {
    angle_max = 0; // asigna el 0 a "angle_max"
    pf_max = 1; // Asigna el Unity PF a "pf_max"
  }
  if (angle_max == 0) // Si el cálculo es más alto que 360, haga lo siguiente
  {
    angle_max = 1; // asigna el 0 a "angle_max"
    pf_max = 0; // Asigna el Unity PF a "pf_max"
  }
  pf_max = pf_max;
  return;
}
void InitWiFi()
{
  // initialize serial for ESP module
  soft.begin(9600);
  // initialize ESP module
  WiFi.init(&soft);
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }
  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(WIFI_AP);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    delay(500);
  }
  Serial.println("Connected to AP");
}
void reconnect() {
  // Loop until we're reconnected
  while (!tb.connected()) {
    Serial.print("Connecting to ThingsBoard node ...");
    // Attempt to connect (clientId, username, password)
    if ( tb.connect(thingsboardServer, TOKEN) ) {
      Serial.println( "[DONE]" );
    } else {
      Serial.print( "[FAILED]" );
      Serial.println( " : retrying in 5 seconds" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}
