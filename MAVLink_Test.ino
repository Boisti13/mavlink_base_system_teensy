#include <PixhawkArduinoMAVLink.h>


void setup() {
  Serial.begin(57600);
  Serial1.begin(57600);
  request_datastream();
}

void loop() {
  MavLink_heartbeat();
  MavLink_receive();
}