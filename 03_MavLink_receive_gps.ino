//function called by arduino to read any MAVlink messages sent by serial communication from flight controller to arduino
void MavLink_receive() {
  mavlink_message_t msg;
  mavlink_status_t status;

  while (Serial1.available()) {
    uint8_t c = Serial1.read();

    //Get new message
    if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {

      //Handle new message from autopilot
      switch (msg.msgid) {

        case MAVLINK_MSG_ID_GPS_RAW_INT:
          {
            mavlink_gps_raw_int_t packet;
            mavlink_msg_gps_raw_int_decode(&msg, &packet);
            
            int gps_raw_lat = packet.lat;
            int gps_raw_lon = packet.lon;
            
            Serial.print("\nGPS Fix: ");
            Serial.println(packet.fix_type);
            Serial.print("GPS Latitude: ");
            Serial.println(gps_raw_lat);
            Serial.print("GPS Longitude: ");
            Serial.println(gps_raw_lon);
            Serial.print("GPS Speed: ");
            Serial.println(packet.vel);
            Serial.print("Sats Visible: ");
            Serial.println(packet.satellites_visible);
          }
          break;
      }
    }
  }
}