#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <AES.h>

const char* ssid = "AMARCA";
const char* password = "Cajio@0847";
IPAddress serverIP(192, 168, 31, 73);
const uint16_t port = 1234;

WiFiClient client;
uint8_t key[16] = { '1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6' };
AES128 aes;
bool connectedOnce = false;

// Function prototype declaration
void connectToReceiver();

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("ESP8266 IP Address: ");
  Serial.println(WiFi.localIP());

  aes.setKey(key, sizeof(key));

  connectToReceiver();  //  Now this call is valid
}

void loop() {
  if (!client.connected()) {
    if (!connectedOnce) {
      connectToReceiver();
    } else {
      Serial.println("Disconnected from receiver");
      client.stop();
      delay(2000);
      Serial.println("Attempting to reconnect...");
      connectToReceiver();
    }
    return;
  }

  const char* message = "HELLO ESP32!";
  uint8_t plain[16] = {0};
  uint8_t encrypted[16];

  memcpy(plain, message, strlen(message));
  aes.encryptBlock(encrypted, plain);

  if (client.write(encrypted, 16) == 16) {
    Serial.println("Encrypted message sent");
  } else {
    Serial.println("Failed to send message. Will reconnect.");
    client.stop();
  }

  delay(5000);
}

//  Full function definition
void connectToReceiver() {
  if (client.connect(serverIP, port)) {
    Serial.println("Connected to ESP32 receiver");
    connectedOnce = true;
  } else {
    Serial.println("Connection to receiver failed");
  }
}
