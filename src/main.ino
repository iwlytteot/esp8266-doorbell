#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>   

IPAddress ip( 255, 255, 255, 255 );
int port = 2345;
volatile bool isr = false;
WiFiUDP udp;

void send_udp ( const char *s ) {
  udp.beginPacket( ip, port );
  udp.write( s );
  while ( !udp.endPacket() );
} 

void ICACHE_RAM_ATTR inter() {
  isr = true;
}

void setup() {
  Serial.begin( 115200 );

  WiFiManager wifiManager;
  wifiManager.setConfigPortalTimeout( 900 );
  wifiManager.autoConnect( "Doorbell", "esp8266-doorbell-ap" );
  
  pinMode( 13, INPUT );
  attachInterrupt( digitalPinToInterrupt( 13 ), inter, FALLING );
}

void loop() {
  if ( isr ) {
    send_udp( "ring" );
    isr = false;
  }
}
