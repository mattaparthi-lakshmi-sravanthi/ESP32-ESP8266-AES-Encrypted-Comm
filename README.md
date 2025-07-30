# ESP32-ESP8266-AES-Encrypted-Comm
Secure communication between ESP8266 and ESP32 using AES encryption

# 🔐 ESP32 & ESP8266 AES Encrypted Communication over Wi-Fi

This project demonstrates **secure communication** between an **ESP8266 (Sender)** and an **ESP32 (Receiver)** over Wi-Fi using **AES-128 encryption** with the [rweather/Crypto](https://github.com/rweather/arduinolibs) library.

> 💡 Ideal for secure sensor data transmission in IoT networks where data confidentiality is essential.

## 📦 Project Structure

ESP32-ESP8266-AES-Encrypted-Comm/
├── esp32_receiver/ # ESP32 receives encrypted data and decrypts
│ └── main.ino
├── esp8266_sender/ # ESP8266 sends encrypted data
│ └── main.ino
├── platformio.ini # PlatformIO configuration for both boards
└── README.md


## 📡 System Overview

- **ESP8266** connects to Wi-Fi, encrypts a message using AES-128, and sends it to the ESP32.
- **ESP32** listens for TCP connections on port `1234`, receives the AES-encrypted block, decrypts it, and displays the plaintext.

[ESP8266] Hello ESP32! --AES128--> [ESP32] Decrypted: Hello ESP32!


## 🔧 Requirements

### 📱 Hardware
- ESP32 DevKit v1 (or compatible)
- ESP8266 NodeMCU (ESP-12E or similar)
- Common Wi-Fi network (2.4GHz)

### 🧰 Software
- [PlatformIO](https://platformio.org/) (recommended) or Arduino IDE
- rweather/Crypto` library for AES support



## 🔐 AES Encryption Details

- **Encryption Type:** AES-128 (ECB mode, single block)
- **Block Size:** 16 bytes (padded with zeros if message < 16)
- **Symmetric Key:** Must be exactly 16 bytes and **identical** on both devices


uint8_t key[16] = { '1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6' };
⚙️ Setup Instructions
✅ 1. Clone the Repo
git clone 
cd ESP32-ESP8266-AES-Encrypted-Comm
✅ 2. Open with PlatformIO in VS Code
✅ 3. Update Wi-Fi Credentials
Edit in both main.ino files:


const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";
Also update the ESP32 IP in esp8266_sender/main.ino:


IPAddress serverIP(192, 168, 1, 100);  // Set to your ESP32's actual IP
✅ 4. Flash the Code
Upload esp8266_sender to the ESP8266 board.

Upload esp32_receiver to the ESP32 board.

📈 Serial Output
ESP8266:
WiFi connected
Connected to receiver
Encrypted message sent

ESP32:
arduino
WiFi connected!
ESP32 IP Address: 192.168.1.100
Server started. Waiting for encrypted data...
Decrypted: Hello ESP32!

🧪 Test & Validate
Power up both boards.
Open serial monitor at 115200 baud.
Observe encrypted transmission and decryption.
You can replace "Hello ESP32!" with any 16-byte message.

📌 Notes
This example uses ECB mode, which is simple but not secure for large or repeated data blocks. For production, use CBC/CTR/GCM modes.
AES block size is fixed to 16 bytes, so messages shorter than that are padded with zeros.

📜 License
This project is licensed under the MIT License.
Crypto library © rweather

🙌 Contributing
PRs, issues, and improvements welcome! Feel free to fork and modify for:

🔒 Sensor encryption
📶 Wi-Fi mesh secure comms
📡 OTA firmware update security

⭐ If you found this project useful, please give it a ⭐ on GitHub!





