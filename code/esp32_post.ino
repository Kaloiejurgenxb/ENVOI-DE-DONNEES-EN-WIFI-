#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "TPSN035";
const char* password = "BTSSN2022";

const char* serverName = "http://<IP_UBUNTU>/btsciel/data.php";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    int valeur = random(0,100);

    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String donnee = "valeur=" + String(valeur);
    Serial.print("Donnée transmise : ");
    Serial.println(donnee);

    int httpReponse = http.POST(donnee);
    Serial.print("HTTP Response code: ");
    Serial.println(httpReponse);

    if (httpReponse > 0) {
      String payload = http.getString();
      Serial.print("Réponse serveur: ");
      Serial.println(payload);
    }

    http.end();
  }

  delay(5000);
}
