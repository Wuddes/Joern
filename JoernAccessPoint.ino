/*
 * Open browser, visit 192.168.4.1
 */
 #include "Commands.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "Joern";
const char *password = "password";

ESP8266WebServer server(80);

void handleRoot() {
    response();
}

void handleAugen() {
  Serial.println("A");
  response();
}

void handleOhren() {
  Serial.println("B");
  response();
}

void handleKippen() {
  Serial.println("C");
  response();
}

void handleSchwenken() {
    Serial.println("D");
  response();
}

const String HtmlHtml = "<html><head>"
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /></head>";
const String HtmlHtmlClose = "</html>";
const String HtmlTitle = "<h1>Joern:AP WebServer-Bewegungen</h1><br/>\n";
const String HtmlButtons = 
    "<a href=\"Augen\"><button style=\"display: block; width: 100%;\">Augen</button></a><br/>"
    "<a href=\"Ohren\"><button style=\"display: block; width: 100%;\">Ohren</button></a><br/>"
    "<a href=\"Schwenken\"><button style=\"display: block; width: 100%;\">Schwenken</button></a><br/>"
    "<a href=\"Kippen\"><button style=\"display: block; width: 100%;\">Kippen</button></a><br/>";

void response(){
  String htmlRes = HtmlHtml + HtmlTitle;
  htmlRes += HtmlButtons;
  htmlRes += HtmlHtmlClose;

  server.send(200, "text/html", htmlRes);
}

void setup() {
    delay(1000);
    Serial.begin(9600);
    Serial.println();

    WiFi.softAP(ssid, password);

    IPAddress apip = WiFi.softAPIP();
    Serial.print("visit: \n");
    Serial.println(apip);
    server.on("/", handleRoot);
    server.on("/Augen", handleAugen);
    server.on("/Ohren", handleOhren);
    server.on("/Kippen", handleKippen);
    server.on("/Schwenken", handleSchwenken);
    server.begin();
}

void loop() {
    server.handleClient();
}
