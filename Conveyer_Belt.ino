/**********************************************************************
  Filename    : Control_Motor_by_L293D
  Description : Use PWM to control the direction and speed of the motor.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid = "";
const char* password = "";
String serverName = "http://165.227.76.232:3000/UNI/running";
unsigned long lastTime = 0;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;
int in1Pin = 12;      // Define L293D channel 1 pin
int in2Pin = 14;      // Define L293D channel 2 pin
int enable1Pin = 13;  // Define L293D enable 1 pin
int channel = 0;
boolean isTrue;

boolean rotationDir;  // Define a variable to save the motor's rotation direction
int rotationSpeed;    // Define a variable to save the motor rotation speed

void setup() {
  Serial.begin(115200); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(25, OUTPUT);
  
  ledcSetup(channel,1000,11);         //Set PWM to 11 bits, range is 0-2047
  ledcAttachPin(enable1Pin,channel);
}

void loop() {
  while(isTrue == false){
    //Send an HTTP POST request every 10 minutes
    if ((millis() - lastTime) > timerDelay) {
      //Check WiFi connection status
      if(WiFi.status()== WL_CONNECTED){
        HTTPClient http;
  
        String serverPath = serverName;
        
        // Your Domain name with URL path or IP address with path
        http.begin(serverPath.c_str());
        
        // Send HTTP GET request
        int httpResponseCode = http.GET();
        
        if (httpResponseCode>0) {
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
          String payload = http.getString();
          Serial.println(payload);
          if (payload.equals("true")){
            isTrue = true;
            //digitalWrite(32, LOW);
          }
          else if (payload.equals("false")){
            isTrue = false;
            //digitalWrite(32, HIGH);
          }
        }
        else {
          Serial.print("Error code: ");
          Serial.println(httpResponseCode);
        }
        // Free resources
        http.end();
      }
      else {
        Serial.println("WiFi Disconnected");
      }
      lastTime = millis();
    }    
  }
  rotationSpeed = 1800;
  rotationDir = false;
  driveMotor(rotationDir, constrain(rotationSpeed,0,2048));
  delay(700);
  rotationSpeed = 1800;
  rotationDir = true;
  driveMotor(rotationDir, constrain(rotationSpeed,0,2048));  
  delay(700); 
}

void driveMotor(boolean dir, int spd) {
  // Control motor rotation direction
  if (rotationDir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
  else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  // Control motor rotation speed
  ledcWrite(channel, spd);
}
