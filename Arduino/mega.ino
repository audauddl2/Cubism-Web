#include <LiquidCrystal.h>
#include <stdlib.h>
#include <time.h>
#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(29,28);
SoftwareSerial ESP_wifi(13,12);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  // LCD 제어를 위한 핀 설정

int lcd_key     = 0;
int adc_key_in  = 0;
int set=0;
char c;
char d;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

// Serial3 to Serial0
String Serial3_String;            // Get Serial3 Message
// 메뉴 설정
String menu0="Comming Soon    ";  // Practice
String menu1="Comming Soon    ";  // Challenge
String menu2="Comming Soon    ";  // GuGuDan
String menu3="Comming Soon    ";  // Update
String menu4="Comming Soon    ";  // WiFi Connection
int menu_cnt;                     // Menu Count 4 or 5

int buzzer=36;
int button1=53;
int button2=51;
int button3=49;
int button4=47;
int button5=45;
int button6=43;
int button7=41;
int button8=39;
int vib1=52;
int vib2=50;
int vib3=48;
int vib4=46;
int vib5=44;
int vib6=42;
int vib7=40;
int vib8=38;
int melody[]={262,294,330,350,392,440,494,523};
long start_clock,mid_clock,end_clock;
long time_result=0;
int sec,mil;



void otaStatus(){
        delay(10);
        Serial.println("Updating Start");
        lcd.clear();
  
        while(Serial3.available() > 0) {
          char inChar = Serial3.read();
          Serial3_String += inChar;
          Serial.println(Serial3_String);
          delay(500);
          
          
           if (Serial3_String.indexOf("[OTA Start]")>0) {
             lcd.setCursor(4,0);
             lcd.print("Updating");
             delay(5000);
           }   
          Serial3_String = "";
          
          if (inChar == '>') {
            if (Serial3_String.indexOf("<OK>")>0) {
              lcd.setCursor(0,0);
              lcd.print("Update Success!");
              Serial.println("");
              Serial.println("Update Success!");
              delay(5000);
            }
            if (Serial3_String.indexOf("<FAILED>")>0) {
              lcd.setCursor(0,0);
              lcd.print("Update Faild");
              Serial.println("");
              Serial.println("Update Faild..");
              delay(3000);
            }
          Serial3_String = "";
          }
        }
      delay(1000);
      /*
      int update_count;   // Update Count 30 sec After reset message 
      lcd.setCursor(0,0);
      lcd.print("After ");
      lcd.setCursor(9,0);
      lcd.print("s later");
      lcd.setCursor(0,1);
      lcd.print("Press Reset...");
      for(update_count=40;update_count>0;update_count--){
        lcd.setCursor(7,0);
        if(update_count >= 10){
          lcd.print(update_count);
        }else{
          lcd.setCursor(7,0);
          lcd.print(" ");
          lcd.setCursor(8,0);
          lcd.print(update_count);
        }
        delay(2000);
      }
      lcd.clear();
      */
}

/*  
 * Serial3 to 0
 * Get Menu 
 * 
 */
// Serial3 상태 가져오기
 void getStatus(){
  while(Serial3.available() > 0) {
    char inChar = Serial3.read();
    Serial3_String += inChar;
    Serial.println(Serial3_String);
  delay(500);
  }
 }
// 메뉴 가져오기
void getMenu(){
  Serial.println("getMenu");
  if(!Serial3.available()){
    Serial.println("Serial3 not available");
    delay(2000);
    Serial3.begin(115200);
    delay(1000);
    getMenu();
  }else{
    Serial.println("Serial3 available");
  }
  while (Serial3.available()) {
    char inChar = Serial3.read();
    //Serial.write(inChar);
    Serial3_String += inChar;
    if (inChar == '.') {
      
        if (Serial3_String.indexOf("4Menu.")>0) {
          menu_cnt = 4;
          menu0="Practice Mode   ";
          menu1="Challenge Mode  ";
          menu3="Update          ";
          menu4="WiFi Connect    ";
          Serial.println("4 Mode");
          delay(500);
        }
        else if (Serial3_String.indexOf("5Menu.")>0) {
          menu_cnt = 5;
          menu0="Practice Mode   ";
          menu1="Challenge Mode  ";
          menu2="GUGUDAN Mode    ";
          menu3="Update          ";
          menu4="WiFi Connect    ";
          Serial.println("5 Mode");
          delay(500);
        }
        
    }
  }
}
void getWiFi(){
  delay(10);
  Serial.println("WiFi Connection");
  lcd.clear();
  
  if(!Serial3.available()){
    Serial.println("Serial3 not available");
    delay(4000);
    Serial3.begin(115200);
    delay(1000);
    getWiFi();
  }else{
    Serial.println("Serial3 available");
  }
  
  while (Serial3.available()) {
    
    char inChar = Serial3.read();
    //Serial.write(inChar);
    Serial3_String += inChar;
    //lcd.setCursor(0,1);
    //Serial.println(" inChar : "+ inChar);
    if (inChar == '>') {
      if (Serial3_String.indexOf("<Connecting>")>0) {
        lcd.setCursor(0,0);
        lcd.print("WiFi Connecting");
        Serial.println("");
        Serial.println("WiFi Connecting");
        delay(5000);
      }
      if (Serial3_String.indexOf("<Connected>")>0) {
        lcd.setCursor(0,0);
        lcd.print("WiFi Connected!");
        Serial.println("");
        Serial.println("WiFi Connected!");
        delay(3000);
      }
      Serial3_String = "";
      
    }
  }
  delay(5000);
  lcd.clear();
}



int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // AO 핀으로부터 아날로그값을 읽어옴
 // 읽어온 아날로그의 값에 따라 눌려진 버튼을 판단함
 if (adc_key_in > 1000) return btnNONE; 
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 400)  return btnDOWN; 
 if (adc_key_in < 600)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  
 return btnNONE;  // when all others fail, return this...
}

long practiceMode(int rep){
  int answer[rep]={0,};
  int trying[rep]={0,};
  int result=0;
  int i=0;
  int ran;

  for(i=0;i<rep;i++){
    ran=rand()%8;
    answer[i]=ran;
    switch(ran)
    {
      case 0:
        analogWrite(vib1,150);
        tone(buzzer,melody[0],200);
        delay(300);
        analogWrite(vib1,0);
        break;
        
      case 1:
        analogWrite(vib2,150);
        tone(buzzer,melody[1],200);
        delay(300);
        analogWrite(vib2,0);
        break;

      case 2:
        analogWrite(vib3,150);
        tone(buzzer,melody[2],200);
        delay(300);
        analogWrite(vib3,0);
        break;

      case 3:
        analogWrite(vib4,150);
        tone(buzzer,melody[3],200);
        delay(300);
        analogWrite(vib4,0);
        break;

      case 4:
        analogWrite(vib5,150);
        tone(buzzer,melody[4],200);
        delay(300);
        analogWrite(vib5,0);
        break;

      case 5:
        analogWrite(vib6,150);
        tone(buzzer,melody[5],200);
        delay(300);
        analogWrite(vib6,0);
        break;

      case 6:
        analogWrite(vib7,150);
        tone(buzzer,melody[6],200);
        delay(300);
        analogWrite(vib7,0);
        break;

      case 7:
        analogWrite(vib8,150);
        tone(buzzer,melody[7],200);
        delay(300);
        analogWrite(vib8,0);
        break;
    }
  }
  
  i=0;
  start_clock=millis();
  while(i<rep){
    mid_clock=millis();
    if(mid_clock-start_clock>100000){
      mp3_play(22);
      delay(2000);
      mp3_play(23);
      delay(4000);
      return 0;
    }
   if(!digitalRead(button1)||!digitalRead(button2)||!digitalRead(button3)||!digitalRead(button4)||!digitalRead(button5)||!digitalRead(button6)||!digitalRead(button7)||!digitalRead(button8)){
      if(!digitalRead(button1)) {
        trying[i++]=0;
        tone(buzzer,melody[0],200);
        delay(300);
     }
     if(!digitalRead(button2)) {
       trying[i++]=1;
       tone(buzzer,melody[1],200);
       delay(300);
      }
     if(!digitalRead(button3)) {
       trying[i++]=2;
       tone(buzzer,melody[2],200);
       delay(300);
     }
      if(!digitalRead(button4)) {
        trying[i++]=3;
        tone(buzzer,melody[3],200);
       delay(300);
      }
      if(!digitalRead(button5)) {
        trying[i++]=4;
        tone(buzzer,melody[4],200);
       delay(300);
      }
      if(!digitalRead(button6)) {
        trying[i++]=5;
        tone(buzzer,melody[5],200);
       delay(300);
      }
      if(!digitalRead(button7)) {
        trying[i++]=6;
        tone(buzzer,melody[6],200);
       delay(300);
      }
      if(!digitalRead(button8)) {
        trying[i++]=7;
        tone(buzzer,melody[7],200);
       delay(300);
      }
   }
  }

  end_clock=millis();
  for(i=0;i<rep;i++){
    if(answer[i]==trying[i]) result++;
  }

  if(result==rep){
    lcd.setCursor(10,1);
    time_result=end_clock-start_clock;
    sec=time_result/1000;
    mil=time_result%1000;
    lcd.print(sec);
    lcd.print(".");
    lcd.print(mil);
    tone(buzzer,melody[0],200);
    delay(300);
    tone(buzzer,melody[2],200);
    delay(300);
    tone(buzzer,melody[4],200);
    delay(300);
    tone(buzzer,melody[7],200);
    delay(300);
    delay(1000);
    mp3_play(21);
    delay(1500);
    mp3_play(19);
    delay(1500);
    if(sec<10){
      mp3_play(sec);
      delay(1500);
    }
    else if(sec>=10&&sec<20){
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=20&&sec<30){
      mp3_play(2);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=30&&sec<40){
      mp3_play(3);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=40&&sec<50){
      mp3_play(4);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=50&&sec<60){
      mp3_play(5);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=60&&sec<70){
      mp3_play(6);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>70&&sec<80){
      mp3_play(7);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=80&&sec<90){
      mp3_play(8);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=90&&sec<100){
      mp3_play(9);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=100){
      mp3_play(22);
      delay(2000);
      mp3_play(23);
      delay(4000);
    }
    if(sec<100){
    mp3_play(20);
    delay(1500);
    }
    lcd.setCursor(10,1);
    lcd.println("       ");
    return time_result;
  }else{
    lcd.setCursor(10,1);
    lcd.print("WRONG");
    tone(buzzer,melody[6],200);
    delay(300);
    tone(buzzer,melody[6],200);
    delay(300);
    tone(buzzer,melody[6],200);
    delay(300);
    delay(1000);
    lcd.setCursor(10,1);
    lcd.println("       ");
    return 0;
  }
}

long practiceMode2(int rep, long sum_time){
  int answer[rep]={0,};
  int trying[rep]={0,};
  int result=0;
  int i=0;
  int ran;

  for(i=0;i<rep;i++){
    ran=rand()%8;
    answer[i]=ran;
    switch(ran)
    {
      case 0:
        analogWrite(vib1,150);
        tone(buzzer,melody[0],200);
        delay(300);
        analogWrite(vib1,0);
        break;
        
      case 1:
        analogWrite(vib2,150);
        tone(buzzer,melody[1],200);
        delay(300);
        analogWrite(vib2,0);
        break;

      case 2:
        analogWrite(vib3,150);
        tone(buzzer,melody[2],200);
        delay(300);
        analogWrite(vib3,0);
        break;

      case 3:
        analogWrite(vib4,150);
        tone(buzzer,melody[3],200);
        delay(300);
        analogWrite(vib4,0);
        break;

      case 4:
        analogWrite(vib5,150);
        tone(buzzer,melody[4],200);
        delay(300);
        analogWrite(vib5,0);
        break;

      case 5:
        analogWrite(vib6,150);
        tone(buzzer,melody[5],200);
        delay(300);
        analogWrite(vib6,0);
        break;

      case 6:
        analogWrite(vib7,150);
        tone(buzzer,melody[6],200);
        delay(300);
        analogWrite(vib7,0);
        break;

      case 7:
        analogWrite(vib8,150);
        tone(buzzer,melody[7],200);
        delay(300);
        analogWrite(vib8,0);
        break;
    }
  }
  
  i=0;
  start_clock=millis();
  while(i<rep){
    mid_clock=millis();
    if(mid_clock-start_clock+sum_time>100000){
      mp3_play(22);
      delay(2000);
      mp3_play(23);
      delay(4000);
      return 0;
    }
    if(!digitalRead(button1)||!digitalRead(button2)||!digitalRead(button3)||!digitalRead(button4)||!digitalRead(button5)||!digitalRead(button6)||!digitalRead(button7)||!digitalRead(button8)){
      if(!digitalRead(button1)) {
        trying[i++]=0;
        tone(buzzer,melody[0],200);
        delay(300);
     }
     if(!digitalRead(button2)) {
       trying[i++]=1;
       tone(buzzer,melody[1],200);
       delay(300);
      }
     if(!digitalRead(button3)) {
       trying[i++]=2;
       tone(buzzer,melody[2],200);
       delay(300);
     }
      if(!digitalRead(button4)) {
        trying[i++]=3;
        tone(buzzer,melody[3],200);
       delay(300);
      }
      if(!digitalRead(button5)) {
        trying[i++]=4;
        tone(buzzer,melody[4],200);
       delay(300);
      }
      if(!digitalRead(button6)) {
        trying[i++]=5;
        tone(buzzer,melody[5],200);
       delay(300);
      }
      if(!digitalRead(button7)) {
        trying[i++]=6;
        tone(buzzer,melody[6],200);
       delay(300);
      }
      if(!digitalRead(button8)) {
        trying[i++]=7;
        tone(buzzer,melody[7],200);
       delay(300);
      }
   }
  }

  end_clock=millis();
  for(i=0;i<rep;i++){
    if(answer[i]==trying[i]) result++;
  }

  if(result==rep){
    lcd.setCursor(10,1);
    time_result=end_clock-start_clock;
    sec=time_result/1000;
    mil=time_result%1000;
    lcd.print(sec);
    lcd.print(".");
    lcd.print(mil);
    tone(buzzer,melody[0],200);
    delay(300);
    tone(buzzer,melody[2],200);
    delay(300);
    tone(buzzer,melody[4],200);
    delay(300);
    tone(buzzer,melody[7],200);
    delay(300);
    delay(1000);
    lcd.setCursor(10,1);
    lcd.println("       ");
    return time_result+sum_time;
  }else{
    lcd.setCursor(10,1);
    lcd.print("WRONG");
    tone(buzzer,melody[6],200);
    delay(300);
    tone(buzzer,melody[6],200);
    delay(300);
    tone(buzzer,melody[6],200);
    delay(300);
    delay(1000);
    lcd.setCursor(10,1);
    lcd.println("       ");
    return 0;
  }
}

void Gugudan(){
  int a,b,c,result,result2;
  char _operator='*';
  int trying[2]={0,};
  int i=0;
  do{
    a=rand()%9+1;
    b=rand()%9+1;
    c=rand()%3;
    result=a*b;
  }while(result<10||result%10==0);

  lcd.setCursor(0,1);
  lcd.print("                ");
  
  lcd.setCursor(0,1);
  lcd.print(a);
  lcd.print(_operator);
  lcd.print(b);
  
  while(i<2){
   if(!digitalRead(button1)||!digitalRead(button2)||!digitalRead(button3)||!digitalRead(button4)||!digitalRead(button5)||!digitalRead(button6)||!digitalRead(button7)||!digitalRead(button8)){
      if(!digitalRead(button1)) {
        trying[i++]=1;
        tone(buzzer,melody[0],200);
        delay(300);
     }
     if(!digitalRead(button2)) {
       trying[i++]=2;
       tone(buzzer,melody[1],200);
       delay(300);
      }
     if(!digitalRead(button3)) {
       trying[i++]=3;
       tone(buzzer,melody[2],200);
       delay(300);
     }
      if(!digitalRead(button4)) {
        trying[i++]=4;
        tone(buzzer,melody[3],200);
       delay(300);
      }
      if(!digitalRead(button5)) {
        trying[i++]=5;
        tone(buzzer,melody[4],200);
       delay(300);
      }
      if(!digitalRead(button6)) {
        trying[i++]=6;
        tone(buzzer,melody[5],200);
       delay(300);
      }
      if(!digitalRead(button7)) {
        trying[i++]=7;
        tone(buzzer,melody[6],200);
       delay(300);
      }
      if(!digitalRead(button8)) {
        trying[i++]=8;
        tone(buzzer,melody[7],200);
       delay(300);
      }
   }
  }
  
  result2=10*trying[0]+trying[1];
  Serial.println(trying[0]);
  Serial.println(trying[1]);
  if(result==result2){
    lcd.setCursor(7,1);
    lcd.print("CORRECT!!");
    tone(buzzer,melody[0],200);
    delay(300);
    tone(buzzer,melody[2],200);
    delay(300);
    tone(buzzer,melody[4],200);
    delay(300);
    tone(buzzer,melody[7],200);
    delay(300);
    delay(1000);
    lcd.setCursor(7,1);
    lcd.println("       ");
  }else{
    lcd.setCursor(10,1);
    lcd.print("WRONG");
    tone(buzzer,melody[6],200);
    delay(300);
    tone(buzzer,melody[6],200);
    delay(300);
    tone(buzzer,melody[6],200);
    delay(300);
    delay(1000);
    lcd.setCursor(10,1);
    lcd.println("       ");
  }
}

int challengeMode(){
  int c_success;
  int level=2;
  c_success=practiceMode2(level,0);
  time_result+=c_success;
  level+=1;
  if(c_success!=0) c_success=practiceMode2(level,time_result);
  else{
    mp3_play(31);
    delay(2200);
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
    return 0;
  }
  time_result+=c_success;
  level+=1;
  if(c_success!=0) c_success=practiceMode2(level,time_result);
  else{
    mp3_play(32);
    delay(2000);
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
    return 0;
  }
  time_result+=c_success;
  level+=1;
  if(c_success!=0) c_success=practiceMode2(level,time_result);
  else{
    mp3_play(33);
    delay(2000);
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
    return 0;
  }
  time_result+=c_success;
  level+=1;
  if(c_success!=0) c_success=practiceMode2(level,time_result);
  else{
    mp3_play(34);
    delay(2000);
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
    return 0;
  }
  time_result+=c_success;
  level+=1;
  if(c_success!=0) c_success=practiceMode2(level,time_result);
  else{
    mp3_play(35);
    delay(2000);
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
    return 0;
  }
  time_result+=c_success;
  level+=1;
  if(c_success!=0) c_success=practiceMode2(level,time_result);
  else{
    mp3_play(36);
    delay(2000);
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
    return 0;
  }
  if(c_success!=0){
    time_result+=c_success;
    sec=time_result/1000;
    mil=time_result%1000;
    lcd.setCursor(10,1);
    lcd.print(sec);
    lcd.print(".");
    lcd.print(mil);
    mp3_play(24);
    delay(3000);
    mp3_play(21);
    delay(1500);
    mp3_play(19);
    delay(1500);
    if(sec<10){
      mp3_play(sec);
      delay(1500);
    }
    else if(sec>=10&&sec<20){
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=20&&sec<30){
      mp3_play(2);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=30&&sec<40){
      mp3_play(3);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=40&&sec<50){
      mp3_play(4);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=50&&sec<60){
      mp3_play(5);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=60&&sec<70){
      mp3_play(6);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>70&&sec<80){
      mp3_play(7);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=80&&sec<90){
      mp3_play(8);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=90&&sec<100){
      mp3_play(9);
      delay(1500);
      mp3_play(10);
      delay(1500);
      mp3_play(sec%10);
      delay(1500);
    }
    else if(sec>=100){
      mp3_play(22);
      delay(3500);
      mp3_play(23);
      delay(4000);
    }
    if(sec<100){
    mp3_play(20);
    delay(1500);
    }
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
  }
  else{
    mp3_play(37);
    delay(2000);
    ESP_wifi.println("AT+CIPSTART=\"TCP\",\"13.209.19.186\",80");
    delay(3000);
    while (ESP_wifi.available()) {
    c = ESP_wifi.read();
    Serial.write(c);
      }
     String body = "GET /cubism_setdata.php?level=";
      body += level-1;
      body += "&time=";
      body += time_result;
      body += " HTTP/1.0\r\n";
      body += "Host: mycubism.c0rw1rrv8ptk.ap-northeast-2.rds.amazonaws.com\r\n\r\n";
      ESP_wifi.println("AT+CIPSEND=117");
      delay(1000);
      ESP_wifi.println(body);
      delay(2000);
      while (ESP_wifi.available()) {
        d = ESP_wifi.read();
        Serial.write(d);
      }
    delay(1000);
    return 0;
  }
  lcd.setCursor(10,1);
  lcd.println("       ");
}

void setup()
{
  lcd.begin(16, 2);              // LCD 초기화
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);
  pinMode(button4,INPUT_PULLUP);
  pinMode(button5,INPUT_PULLUP);
  pinMode(button6,INPUT_PULLUP);
  pinMode(button7,INPUT_PULLUP);
  pinMode(button8,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  pinMode(vib1,OUTPUT);
  pinMode(vib2,OUTPUT);
  pinMode(vib3,OUTPUT);
  pinMode(vib4,OUTPUT);
  pinMode(vib5,OUTPUT);
  pinMode(vib6,OUTPUT);
  pinMode(vib7,OUTPUT);
  pinMode(vib8,OUTPUT);
  Serial.begin(115200);  // This is Mega2560 Communication
  Serial3.begin(115200); // This is Esp Communication
  delay(5000);
  getMenu();              // 메뉴 가져오기
  delay(1000);
  getWiFi();             // 네트워크 설정
  delay(1000);
  mySerial.begin(9600);
  ESP_wifi.begin(9600);
  ESP_wifi.setTimeout(10000);
  mp3_set_serial(mySerial);
  delay(1);
  mp3_set_volume(24);
  srand(time(NULL));
  lcd.clear();
}
 
void loop()
{ 
 char wifi_Name[20][50];
 char filter_Name[20][30];
 String filter_last[20];
 int level[8]={1,2,3,4,5,6,7,8};
 int current_LEVEL=0;
 int current_WIFI=1;
 int play;
 int qwer;
 int a,i,j;
 int trash_a, trash_b, trash_c;
 char trash_d[50];

 lcd.setCursor(2,0);
 lcd.print("Select Menu!");     // LCD에 출력되는 글
 lcd.setCursor(0,1);            // 2번째 줄(1) 1번째(0) 패널에 위치하고
 lcd_key = read_LCD_buttons();  // 버튼이 눌려진 이름 출력하는 함수 호출
 switch (lcd_key)               // 버튼 판단
 {
   case btnRIGHT:
     {
     if(set<4) set++;
     else set=0;
     delay(200);
     break;
     }
     
   case btnLEFT:
     {
     if(set>0) set--;
     else set=4;
     delay(200);
     break;
     }
     
   case btnSELECT:
     {
     if(set==0){
       lcd.clear();
       lcd.setCursor(2,0);
       lcd.print("Select Level");
       delay(200);
       while(lcd_key!=btnDOWN){
        lcd_key=read_LCD_buttons();
        switch(lcd_key)
        {
          case btnRIGHT:
          {
            if(current_LEVEL==7) {
              current_LEVEL=0;
            }else current_LEVEL++;
            delay(200);
            break;
          }
          case btnLEFT:
          {
            if(current_LEVEL==0) {
              current_LEVEL=7;
            }else current_LEVEL--;
            delay(200);
            break;
           }
           case btnSELECT:
           {
             Serial.println(current_LEVEL);
             play=practiceMode(current_LEVEL+1);
             break;
           }
           case btnNONE:
           {
            lcd.setCursor(0,1);
            lcd.print(level[current_LEVEL]);
            break;
           }
        }
       }
     }
     else if(set==1) {
      qwer=challengeMode();
     }
     else if(set==2){     // This is GuGuDan - OTA TEST CASE
      if(menu_cnt == 5){
         Gugudan();       // GUGUDAN() 게임 실행
        }else if(menu_cnt == 4) {
          break;          // Menu 3 -> break    
      }
     }

     else if(set==3){     //  OTA 
      /* 
       * 버튼 누르고 약 13초 이후에 업데이트 시작함... 그리고 업데이트 완료 하는데 약 18초 총 약 31초 
       */
       Serial3.println("[Update]");  // Send Message to Serial3

       
     }
     else if(set==4){
      while(ESP_wifi.available()>0){
        ESP_wifi.read();
      }
      ESP_wifi.println("AT+CWLAP");
      delay(5000);
      a=0;
      i=0;
      while(ESP_wifi.available()>0){
        c=ESP_wifi.read();
        Serial.println(ESP_wifi.available());
        Serial.print(c);
        if(c=='\n'){
          a+=1;
          i=0;
          if(a=20) break;
        }else{
          wifi_Name[a][i]=c;
          i+=1;
        }
      }
      for(i=1;i<20;i++){
        sscanf(wifi_Name[i],"+CWLAP:(%d,\"%s\",%d,\"%s\",%d)",&trash_a,&filter_Name[i],&trash_b,&trash_d,&trash_c);
      }
      for(i=1;i<20;i++){
        for(j=0;j<30;j++){
          if(filter_Name[i][j]=='\"'){
            break;
          }else{
            filter_last[i]+=filter_Name[i][j];
          }
        }
      }
      while(lcd_key!=btnDOWN){
        lcd_key=read_LCD_buttons();
        switch(lcd_key)
        {
          case btnRIGHT:
          {
            if(current_WIFI==5) {
              current_WIFI=1;
            }else current_WIFI++;
            delay(200);
            break;
          }
          case btnLEFT:
          {
            if(current_WIFI==1) {
              current_WIFI=5;
            }else current_WIFI--;
            delay(200);
            break;
           }
           case btnSELECT:
           {
             ESP_wifi.print("AT+CWJAP=\"");
             ESP_wifi.print(filter_last[current_WIFI]);
             ESP_wifi.print("\",\"68699955A*\"");
             while(ESP_wifi.available()>0){
              c=ESP_wifi.read();
              Serial.print(c);
             }
             break;
           }
           case btnNONE:
           {
            lcd.setCursor(0,1);
            lcd.print(filter_last[current_WIFI]);
            break;
           }
        }
       }
     }
     break;
     }
     
     case btnNONE:
     {
     if(set==0) {
      lcd.print(menu0);
     }
     else if(set==1){
      lcd.print(menu1);
     }
     else if(set==2){
      lcd.print(menu2);
     }
     else if(set==3){
      lcd.print(menu3);
     }
     else if(set==4){
      lcd.print(menu4);
     }
     break;
     }
 }
}