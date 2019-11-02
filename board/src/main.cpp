#include "main.hpp"

DNSClient dns;
IPAddress server;
WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived
}

void(* resetFunc) (void) = 0;

void setup_pins() {
  pinMode(A0, INPUT);
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);

  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  setup_pins();

  WiFi.begin(WIFI_HOTSPOT, WIFI_PASSWORD);

  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(PIN_LED_RED, !digitalRead(PIN_LED_RED));
    delay(500);
    Serial.print(".");
  }
  digitalWrite(PIN_LED_RED, LOW);
  Serial.println();

  Serial.print("Conected, IP Address: ");
  Serial.println(WiFi.localIP());

  client.setServer(MQTT_HOST, 1883);
  client.setCallback(callback);

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), MQTT_USERNAME, MQTT_PASSWORD)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
//   test_publish(client);
  parse_input(client);
}