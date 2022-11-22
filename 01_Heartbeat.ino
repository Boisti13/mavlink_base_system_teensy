void MavLink_heartbeat() {
  mavlink_message_t msg;
  mavlink_status_t status;

  while (Serial1.available()) {
    uint8_t c = Serial1.read();

    //Get new message
    if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {

      //Handle new message from autopilot
      switch (msg.msgid) {

          //handle heartbeat message
        case MAVLINK_MSG_ID_HEARTBEAT:
          {
            mavlink_heartbeat_t hb;
            mavlink_msg_heartbeat_decode(&msg, &hb);
            /*
        Serial.print(millis());
        Serial.print("\nFlight Mode: (10 is auto)");Serial.println(hb.custom_mode);
        Serial.print("Type: ");                     Serial.println(hb.type);
        Serial.print("Autopilot: ");                Serial.println(hb.autopilot);
        Serial.print("Base Mode: ");                Serial.println(hb.base_mode);
        Serial.print("System Status: ");            Serial.println(hb.system_status);
        Serial.print("Mavlink Version: ");          Serial.println(hb.mavlink_version);
        Serial.println();
      */
          }
          break;
      }
    }
  }
}