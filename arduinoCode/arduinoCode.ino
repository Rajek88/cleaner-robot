//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>


#define FIREBASE_HOST "stage-cleaner-default-rtdb.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "xdBy3YYyyL509HLeqT9tWbifppDsLRaN1eUW0Ki4"
#define WIFI_SSID "Mukund_Speed"
#define WIFI_PASSWORD "Five@Mitsoe"


//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;

#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
#define IN_1  15          // L298N in1 motors Rightx          GPIO15(D8)
#define IN_2  13          // L298N in2 motors Right           GPIO13(D7)
#define IN_3  2           // L298N in3 motors Left            GPIO2(D4)
#define IN_4  0           // L298N in4 motors Left            GPIO0(D3)
//int motor1pin1 = 15;
//int motor1pin2 = 13;
//
//int motor2pin1 = 2;
//int motor2pin2 = 0;

int speedCar = 950;         // 400 - 1023.
int speed_Coeff = 3;

void applyBreak(){
        digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
}

void goAhead(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goBack(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goRight(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goLeft(){

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void setup()
{

  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT); 
//  pinMode(motor1pin1, OUTPUT);
//  pinMode(motor1pin2, OUTPUT);
//  pinMode(motor2pin1, OUTPUT);
//  pinMode(motor2pin2, OUTPUT);
   pinMode(IN_1, OUTPUT);
   pinMode(IN_2, OUTPUT);
   pinMode(IN_3, OUTPUT);
   pinMode(IN_4, OUTPUT);

  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}


void loop() {
  
  if (Firebase.getString(ledData, "/x/cmd")){
//    Serial.println(ledData.stringData());
    String cmd =  ledData.stringData() ;
//    String left = "left1";
//    cmd.trim();
    Serial.println(cmd);
    
    if (cmd == "\"left\"") {
//      Serial.println("LEFT");
//    digitalWrite(led, HIGH);
//        digitalWrite(motor1pin1, HIGH);
//        digitalWrite(motor1pin2, LOW);
//        digitalWrite(motor2pin1, HIGH);
//        digitalWrite(motor2pin2, LOW);
      goLeft();
      Serial.println("LEFT");
    }
  else if (ledData.stringData() == "\"right\""){
//    digitalWrite(led, LOW);
      goRight();
      Serial.println("RIGHT");
    }
  else if (ledData.stringData() == "\"forward\""){
//    digitalWrite(led, LOW);
      goAhead();
      Serial.println("FORWARD");
    }
  else if (ledData.stringData() == "\"backward\""){
//    digitalWrite(led, LOW);
      goBack();
      Serial.println("BACKWARD");
    }
    else{
      applyBreak();
    }
  }
  delay(100);
}
