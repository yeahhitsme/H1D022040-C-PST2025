#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "internet cepat buat apa";
const char* password = "321qwedsa";

ESP8266WebServer server(80);
String webpage;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(D0, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);

  Serial.println();
  Serial.println("Konfigurasi akses poin...");

  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid, password);

  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());

  webpage+= "<h1> Web Control ESP8266<h1>";
  webpage+= "<h2> Fahmi<H2>";
  webpage+= "<p> LED 1: ";
  webpage+= "<a href= \"LED1ON\"\"><button>LED ON</button></a><a href= \"LED1OFF\"\"><button>LED OFF</button></a></p><br>";
  webpage+= "<p> LED 2: ";
  webpage+= "<a href= \"LED2ON\"\"><button>LED ON</button></a><a href= \"LED2OFF\"\"><button>LED OFF</button></a></p><br>";
  webpage+= "<p> LED 3: ";
  webpage+= "<a href= \"LED3ON\"\"><button>LED ON</button></a><a href= \"LED3OFF\"\"><button>LED OFF</button></a></p>";

  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  server.on("/LED1ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, HIGH);
    delay(1000);
  });
  server.on("/LED2ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, HIGH);
    delay(1000);
  });
  server.on("/LED3ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D5, HIGH);
    delay(1000);
  });
  server.on("/LED1OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, LOW);
    delay(1000);
  });
  server.on("/LED2OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, LOW);
    delay(1000);
  });
  server.on("/LED3OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D5, LOW);
    delay(1000);
  });

  server.begin();
  Serial.println("Webserver dijalankan");
}

void loop() {
  server.handleClient();
}
