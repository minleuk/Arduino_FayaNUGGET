//  ref HC-05與HC-06藍牙模組補充說明（三）：使用Arduino設定AT命令
// ref http://swf.com.tw/?p=712

#include <SoftwareSerial.h>   // 引用程式庫
#define SensorPin A0
String getdata ;  // 儲存接收資料的變數
int nowdata = 0 ;
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(11, 12); // 接收腳, 傳送腳

void setup() {
  
  
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");

  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
   delay(2000);

}

void loop() {
      int d1 = 0 ;
      int d2 = 0 ;
      int d3 = 0 ;
      
 //   getdata = "@" && String(analogRead(SensorPin)) &&"/" ; 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
      nowdata = analogRead(SensorPin)-273 ;
      d1 = (nowdata % 10 ) ;
      d2 = ((int)(nowdata /10) % 10) ;
      d3 = ((int)(nowdata /100) % 10) ;
      Serial.print(nowdata);     
//     BT.print("@");
     Serial.print("@");
     BT.write(d3);
     BT.write(d2);
     BT.write(d1);
      Serial.print(String(analogRead(SensorPin)-273));
  //   BT.print("/");
      Serial.print("/");
    Serial.print("\n");
    delay(30000);
  }

