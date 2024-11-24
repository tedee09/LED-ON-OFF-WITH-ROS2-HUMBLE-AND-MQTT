#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Konfigurasi WiFi
const char* ssid = "ha";
const char* password = "password";

// Konfigurasi MQTT
const char* mqtt_server = "192.168.48.247" ; // Ganti dengan alamat komputer Anda
const int mqtt_port = 1883;
const char* mqtt_topic = "esp8266/led";

WiFiClient espClient;
PubSubClient client(espClient);

const int ledPin = 2; // Pin LED (GPIO5)

void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");

  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);

  if (message == "ON") {
    digitalWrite(ledPin, LOW); // LED menyala
    Serial.println("LED ON");
  } else if (message == "OFF") {
    digitalWrite(ledPin, HIGH); // LED mati
    Serial.println("LED OFF");
  }
}


void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("Connected to MQTT broker");
      client.subscribe(mqtt_topic);
      Serial.print("Subscribed to topic: ");
      Serial.println(mqtt_topic);
    } else {
      Serial.print("Failed to connect, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


void setup() {
  Serial.begin(115200); // Atur baud rate
  pinMode(ledPin, OUTPUT);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  Serial.println("Setup complete");
}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
