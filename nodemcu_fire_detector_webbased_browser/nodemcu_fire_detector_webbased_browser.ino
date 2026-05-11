#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// 🌐 WiFi Credentials
const char* ssid = "Galaxy A15 5G 3703_s";
const char* password = "********";


// 🔌 Pin definitions
#define FLAME_SENSOR D5
#define BUZZER D6

WiFiServer server(80);

void setup() {
  Serial.begin(9600);

  pinMode(FLAME_SENSOR, INPUT);   // use INPUT (not pullup for now)
  pinMode(BUZZER, OUTPUT);

  // 🌐 Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // 🚀 Start server
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  int flame = digitalRead(FLAME_SENSOR);

  // 🔔 Buzzer control
  if (flame == LOW) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  // 🌐 When browser connects
  if (client) {
    Serial.println("Client Connected");

    String html = "<!DOCTYPE html><html><head>";
    html += "<meta http-equiv='refresh' content='2'>";
    html += "<style>body{text-align:center;font-family:Arial;}</style>";
    html += "</head><body>";

    if (flame == LOW) {
      html += "<h1 style='color:red;'>-------FIRE DETECTED!-----------</h1>";
    } else {
      html += "<h1 style='color:green;'> SAFE</h1>";
    }

    html += "</body></html>";

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println(html);
    client.println();
  }
}