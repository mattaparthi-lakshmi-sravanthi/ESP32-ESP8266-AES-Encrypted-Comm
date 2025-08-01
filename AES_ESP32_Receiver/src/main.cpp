#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <AES.h>  // from rweather/Crypto

const char* ssid = "AMARCA";          // Wi-Fi SSID
const char* password = "Cajio@0847";  // Wi-Fi password

WiFiServer server(1234);
WiFiClient client;

// AES-128 static key (must match ESP8266)
uint8_t key[16] = { '1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6' };
AES128 aes;

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
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  aes.setKey(key, sizeof(key));
  Serial.println("Server started. Waiting for encrypted data...");
}

void loop() {
  // Accept new client if not connected
  if (!client || !client.connected()) {
    client = server.available();
  }

  if (client && client.connected() && client.available() >= 16) {
    uint8_t encrypted[16];
    uint8_t decrypted[16];

    client.read(encrypted, 16);               // Read encrypted block
    aes.decryptBlock(decrypted, encrypted);   // Decrypt AES block

    // Check if decrypted data starts with known prefix
    const char* expectedPrefix = "HELLO";
    if (memcmp(decrypted, expectedPrefix, strlen(expectedPrefix)) == 0) {
      Serial.print("Decrypted message: ");
      for (int i = 0; i < 16; i++) {
        Serial.print((char)decrypted[i]);
      }
      Serial.println();
    } else {
      Serial.println("Key mismatch or corrupted message");
    }
  }
}
