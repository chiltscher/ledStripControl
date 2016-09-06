#include <SoftwareSerial.h>
#define SSID "charlieHotel"

SoftwareSerial dbgSerial(2, 3); // RX, TX for debugging

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(5000);
  dbgSerial.begin(9600);
  dbgSerial.println("Debugging Interface");

  Serial.println("AT+RST"); //reset and test if module is ready
  delay(1000);
  if(Serial.find("ready")){
    dbgSerial.println("WiFi - Module is ready");
  }
  else{
    dbgSerial.println("Module dosn’t respond.");
  }
  while(1);
}

void loop() {
}
