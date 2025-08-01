# 🔐 ESP8266 to ESP32 AES Encrypted Communication (Static Key)

This project is about securely transmitting data between two ESP boards using **AES-128 encryption** with a static key.  
The **ESP8266 acts as the Sender**, encrypting and sending data over Wi-Fi, and the **ESP32 acts as the Receiver**, decrypting and displaying the original message.

## 📌 Why AES? (And Why It Matters)

In today's world, even small IoT devices are exposed to security threats — especially when data is sent over Wi-Fi. That's where AES comes in.

**AES (Advanced Encryption Standard)** is one of the most trusted encryption methods used globally — from banks to military systems. It converts readable data (plaintext) into an unreadable format (ciphertext) using a key, and only someone with the correct key can turn it back into the original message.

In this project, we use **AES-128 ECB mode** with a **static 16-byte key** on both devices. This helps prevent unauthorized devices from reading or tampering with the transmitted data.

So basically — your ESP8266 encrypts a message, and only your ESP32 knows how to unlock it. Simple, safe, and reliable.


## 🔧 Project Overview

- **ESP8266 (Sender):**
  - Connects to Wi-Fi
  - Encrypts a custom message using AES
  - Sends the encrypted bytes to ESP32 over TCP

- **ESP32 (Receiver):**
  - Connects to the same Wi-Fi network
  - Listens for incoming TCP data
  - Decrypts the AES data
  - Prints the original message to Serial


## 🛠 Folder Structure
AES_Encryption/
├── ESP8266_Sender/
│ ├── src/
│ │ └── main.cpp
│ └── platformio.ini
│
└── ESP32_Receiver/
├── src/
│ └── main.cpp
└── platformio.ini

---

## ⚙️ Tech Details

- **Encryption**: AES-128 ECB Mode
- **Key Type**: Static 16-byte key (must be same on sender and receiver)
- **Library Used**: [rweather/Crypto](https://github.com/rweather/arduinolibs/tree/master/Crypto)
- **Communication**: TCP Socket over Wi-Fi


## 📝 How to Use

1. Clone this repo or download the ZIP
2. Open **ESP32_Receiver** folder in PlatformIO → Upload the code
3. Open **ESP8266_Sender** folder in PlatformIO → Upload the code
4. Make sure both boards are on the same Wi-Fi
5. Open Serial Monitors to see encrypted and decrypted messages

> ⚠️ Make sure to enter the same AES key and Wi-Fi credentials in both files

---

## 🔍 Example Output
### Sender (ESP8266)
Connecting to WiFi...
Connected to ESP32
Encrypted message sent: 7A 01 9F B3 ...

### Receiver (ESP32)
Client connected
Encrypted data received: 7A 01 9F B3 ...
Decrypted message: Hello ESP32!

## 🌱 What I Learned

- How to implement AES encryption on ESP devices
- How to communicate securely using Wi-Fi and TCP sockets
- How embedded systems handle encryption with limited resources

---

## 🚀 What’s Next?

- Dynamic key generation and key rotation every few seconds
- Timestamp verification to avoid replay attacks
- Adding HMAC (Hash-based Message Authentication Code) for integrity checks
- OTA firmware update support over Wi-Fi

  ## 👩‍💻 Author

**M.Sravanthi**  
Embedded Systems Engineer 
(Feel free to fork or suggest improvements!)


## 📜 License

MIT License








