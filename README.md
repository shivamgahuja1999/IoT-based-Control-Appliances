# 🔌 IoT Based Control Appliances

This project demonstrates an **IoT-based smart home automation system** using the **NodeMCU ESP8266** microcontroller and the **Blynk IoT platform**. The goal is to control and monitor multiple electrical appliances (represented by bulbs) remotely via WiFi.

---

## 📱 Features

- Control **White**, **Yellow**, and **Red** bulbs remotely using the **Blynk App**.
- **WiFi connectivity indicator** using an onboard LED (D5) to show connection status.
- Visual status indicators (LEDs) for each bulb based on input signals.
- Efficient retry mechanism for WiFi connection during startup.
- Real-time status updates via the Blynk cloud platform.

---

## 🧰 Tech Stack & Components

- **Microcontroller**: NodeMCU ESP8266
- **IoT Platform**: Blynk (Legacy)
- **Programming Language**: C++ (Arduino IDE)
- **Network**: WiFi
- **Hardware Components**:
  - 3 LEDs for status indication
  - 3 bulbs (simulated via digital input)
  - WiFi Indicator LED

---

## ⚙️ Pin Configuration

| Appliance       | Input Pin | LED Indicator |
|----------------|-----------|----------------|
| White Bulb     | D1        | D6             |
| Yellow Bulb    | D3        | D8             |
| Red Bulb       | D4        | D7             |
| WiFi Status    | -         | D5             |

---

## 📲 How it Works

1. On startup, the NodeMCU attempts to connect to the specified WiFi network.
2. Once connected, it connects to the Blynk cloud using the auth token.
3. Based on the state of each bulb's input pin, the corresponding LED is turned on/off.
4. The WiFi connection status is shown using a dedicated LED.

---

## 📝 Setup Instructions

1. Open the project in the **Arduino IDE**.
2. Replace the placeholder values:
   - `ssid[] = "Your WiFi Name"`
   - `pass[] = "Your WiFi Password"`
   - `BLYNK_AUTH_TOKEN = "Your Blynk Token"`
3. Upload the code to the **NodeMCU ESP8266**.
4. Set up your **Blynk App** interface.
5. Power on your device and monitor logs using the **Serial Monitor (baud: 115200)**.

---


## 👨‍💻 Author

**Shivam Ahuja**
**Rohit Jaiswal**  
[MCA | Cloud Computing & DevOps] - Chandigarh University  
[GitHub](https://github.com/shivamgahuja1999)

---

> Feel free to ⭐️ this repository if you found it helpful!
