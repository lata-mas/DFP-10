//----Librerias-------------------//
#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"
#include <ThingsBoard.h>
#include "EmonLib.h" 
//-------------------------------//

#define VOLT_CAL 148.7
EnergyMonitor emon1;

//-----datos de la red-------//
//#define WIFI_AP "IER"
//#define WIFI_PASSWORD "acadier2014"
#define WIFI_AP "INFINITUMjpdm"
#define WIFI_PASSWORD "5cbbb04d21"

#define TOKEN "asm8CrU6nQfGsW3Xl7Fn"  //--------Dispositivo tb-------//  

char thingsboardServer[] = "iot.ier.unam.mx"; //------Servidor ThingsBoard--------//

// Initialize the Ethernet client object
WiFiEspClient espClient;                                     
ThingsBoard tb(espClient);                                    

SoftwareSerial soft(2, 3); // RX, TX                          
int status = WL_IDLE_STATUS;
unsigned long lastSend;

#include <Filters.h> //Easy library to do the calculations
#include <Wire.h>

float testFrequency = 60; // Frecuencia (Hz)
float windowLength = 40.0 / testFrequency; // promedio de la señal

int SensorVolts = 0; //Variable para la lectura del sensor de voltaje

//----------constantes para funcion getvoltage-----------------------------//
float intercept = -0.04; // to be adjusted based on calibration testing
float slope = 0.0405; // to be adjusted based on calibration testing
float voltaje; // Voltaje real

unsigned long periodo = 1000; //Refresh rate
unsigned long tiempoAnterior = 0;
//-----------------------------------------------------------------------//

float Sensordecorriente;
float corriente = 0;
float Sumatoria = 0;
long tiempo = millis();
int pin = 7;
int N = 0;

//----constantes para funcion getpower-----------------------------------------------------------------//
float rads = 57.29577951; // 1 radian = aprox. 57 grados
float degree = 360;
float frequency = 60;
float nano = 1 * pow (10, -6); // Factor de multiplicación para convertir nano segundos en segundos

float pf;
float angle;
float pf_max = 0;
float angle_max = 0;
int ctr;
//----------------------------------------------------------------------------------------------------//

//------------------------------------------------------------//
void setup() { 
  // initialize serial for debugging
  Serial.begin(9600);
  InitWiFi();                         
  lastSend = 0;                        
  pinMode(pin, INPUT);
  emon1.voltage(1, VOLT_CAL, 1.7);  // Voltage: input pin, calibration, phase_shift
}
//------------------------------------------------------------//

//-------------------------------------------------------------//
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

    
    float Irms = getcorriente();
    float volts = getvoltaje();
    float pf = getpower();


    //Serial.println("Sending data to ThingsBoard:"); 
    Serial.print("voltaje --> ");
    Serial.println(volts);
    Serial.print("corriente --> "); 
    Serial.println(Irms);
    Serial.print("factor_p --> ");
    Serial.println(pf);
    tb.sendTelemetryFloat("voltaje", volts);
    tb.sendTelemetryFloat("corriente", Irms);
    tb.sendTelemetryFloat("factor_p", pf);
    
    lastSend = millis();
  }
  tb.loop();
}
//..........................................................//


//-------------------------------------------------------------------------------------------------------//
float getvoltaje()
{
  emon1.calcVI(20,2000);
  float supplyVoltage = emon1.Vrms;
  return supplyVoltage; 
}
//-------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------------//
float getcorriente()
{
  float Sensordecorriente;
  float corriente = 0;
  float Sumatoria = 0;
  long tiempo = millis();
  int N = 0;
  while (millis() - tiempo < 500) //Duración 0.5 segundos(Aprox. 30 ciclos de 60Hz)
  {
    Sensordecorriente = analogRead(A3) * (1.0 / 1023.0); //voltaje del sensor de corriente alterna
    corriente = Sensordecorriente; //corriente=VoltajeSensor*(100A/1V)
    Sumatoria = Sumatoria + sq(corriente); //Sumatoria de Cuadrados
    N = N + 1;
    delay(1);
  }
  //Sumatoria = Sumatoria * 2; //Para compensar los cuadrados de los semiciclos negativos.
  corriente = sqrt((Sumatoria) / N); //Ecuación del RMS corriente=corriente;
  
  return corriente;
}
//-----------------------------------------------------------------------------------------------------//

//-----------------------------------------------------------------------------------------------------//
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

  return pf_max;
}
//---------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------//
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
//---------------------------------------------------------------------------------------------------------------//

//---------------------------------------------------------------------------------------------------------------//
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
//-------------------------------------------------------------------------------------------------------------------//
