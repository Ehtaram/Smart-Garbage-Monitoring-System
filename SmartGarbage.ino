#include <SoftwareSerial.h>

#define DEBUG true

SoftwareSerial esp8266(10, 11);

const int trigPin = 8;
const int echoPin = 9;

long duration;
int distance;

String sendData(String command, const int timeout, boolean debug);

void setup() {
    Serial.begin(9600);
    esp8266.begin(9600);
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    sendData("AT+RST\r\n", 2000, DEBUG);
    sendData("AT+CWMODE=2\r\n", 1000, DEBUG);
    sendData("AT+CIFSR\r\n", 1000, DEBUG);
    sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);
    sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    
    distance = duration * 0.034 / 2;
    
    if (distance > 400 || distance < 2) {
        distance = -1;
    }

    if (esp8266.available()) {
        if (esp8266.find("+IPD,")) { 
            delay(100);
            
            int connectionId = esp8266.read() - '0';
            
            String webpage = "<h1>IoT Garbage Monitoring System</h1>";
            webpage += "<p><h2>";
            if (distance != -1 && distance < 5) {
                webpage += "Trash can is Full";
            } else {
                webpage += "Trash can is Empty";
            }
            webpage += "</h2></p></body>";

            String cipSend = "AT+CIPSEND=";
            cipSend += connectionId;
            cipSend += ",";
            cipSend += webpage.length();
            cipSend += "\r\n";

            sendData(cipSend, 1000, DEBUG);
            sendData(webpage, 1000, DEBUG);

            String closeCommand = "AT+CIPCLOSE=";
            closeCommand += connectionId;
            closeCommand += "\r\n";
            sendData(closeCommand, 3000, DEBUG);
        }
    }
}

String sendData(String command, const int timeout, boolean debug) {
    String response = "";
    esp8266.print(command);
    long int time = millis();
    
    while ((time + timeout) > millis()) {
        while (esp8266.available()) {
            char c = esp8266.read();
            response += c;
            delay(10);
        }
    }
    
    if (debug) {
        Serial.print(response);
    }
    
    return response;
}
