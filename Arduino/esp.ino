#include <ESP8266httpUpdate.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

// 네트워크 설정
const char* ssid = "";
const char* password = "12345678";
// OTA 설정
String version="final02";
String nextVersion="ota/final01.bin";
// Serial0 to Serial3
String Serial1_String;

void ota(void){
  
  Serial.println("[WiFi check]");
  checkWiFi(); // WiFi Connection Check
  delay(2000);
  
  Serial.println("[OTA Start]");
  String updateAddr="http://13.209.19.186:80/"+nextVersion;
  t_httpUpdate_return ret = ESPhttpUpdate.update(updateAddr);
  
  switch (ret) {
      case HTTP_UPDATE_FAILED:
      Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
      break;
  
      case HTTP_UPDATE_NO_UPDATES:
      Serial.println("HTTP_UPDATE_NO_UPDATES");
      break;
  
      case HTTP_UPDATE_OK:
      Serial.println("HTTP_UPDATE_OK");
      break;
    }
    delay(5000);
    Serial.print("<");
    Serial.println(ret);
    Serial.print(">");
}

void setWiFi(){ //WiFi 설정
  Serial.println("");
  Serial.println("<Connecting>");
  delay(5000);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); // WiFi 연결
  delay(5000);
  int WiFicnt = 0;
  while (WiFi.status() != WL_CONNECTED) { // 네트워크가 연결이 안되어있을때
    delay(1000);
    Serial.print(",");
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("<Connected>");
  }
  
  delay(5000);
  
}
void checkWiFi(){
  Serial.println("");
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("<Connected>");
    
  }else if(WiFi.status() != WL_CONNECTED){
    Serial.println("<Not Connected>");
    setWiFi(); // 네트워크 연결
  }
}

void setup() {
  delay(5000);
  Serial.begin(115200);
  delay(200);
  Serial.println("");
  Serial.println("5Menu.");
  
  delay(200);
  Serial.println("");
  Serial.println("<Connecting>");
  // *************************************************************8
  delay(2000); // <<<< 0729 delay 5000 -> 2000
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); // WiFi 연결
  delay(5000);

  while (WiFi.status() != WL_CONNECTED) { // 네트워크가 연결이 안되어있을때
    delay(1000);
    Serial.print(",");
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("<Connected>");
  }

  delay(5000);
}

void loop()
{
 while(Serial.available() > 0) {
  char inChar = Serial.read();
  Serial1_String += inChar;
  //Serial.println(Serial1_String);
  //Serial.println("");
  delay(500);
  
  if (inChar == ']') {
    if (Serial1_String.indexOf("[Update]")>0) {
      ota();
      delay(1000);
    }
  }
}
delay(1000);
}
// loop End=====================================================