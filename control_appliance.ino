#define BLYNK_TEMPLATE_ID "TMPL3LjM0bpfc"
#define BLYNK_TEMPLATE_NAME "Controlling Appliances with wifi"
#define BLYNK_AUTH_TOKEN "AdeQfJS8hGEjgk2HTzShwmzaOk-u9ovo"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial  // Debug prints

// WiFi credentials
char ssid[] = "RJ";
char pass[] = "123456789";

// Define LED and Bulb pins
#define WIFI_LED D5  // Turns on when WiFi is connected
#define LED2 D6  // White Bulb Indicator
#define LED3 D8  // Yellow Bulb Indicator
#define LED4 D7  // Red Bulb Indicator

#define WHITE_BULB D1
#define YELLOW_BULB D3
#define RED_BULB D4

void setup() {
  Serial.begin(115200);  // Correct baud rate for ESP8266
  
  pinMode(WIFI_LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  pinMode(WHITE_BULB, INPUT);
  pinMode(YELLOW_BULB, INPUT);
  pinMode(RED_BULB, INPUT);

  digitalWrite(WIFI_LED, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");

  int retryCount = 0;
  while (WiFi.status() != WL_CONNECTED && retryCount < 20) {  
    delay(1000);
    Serial.print(".");
    retryCount++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(WIFI_LED, HIGH);
    Serial.println("WiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi Connection Failed!");
  }

  Blynk.config(BLYNK_AUTH_TOKEN);  
  Serial.println("Connecting to Blynk...");
  Blynk.connect();  
}

void loop() {
  if (Blynk.connected()) {
    Blynk.run();
  } else {
    Serial.println("Blynk Not Connected!");
  }

  // Check Bulb States and Control LEDs
  if (digitalRead(WHITE_BULB) == HIGH) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (digitalRead(YELLOW_BULB) == HIGH) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  if (digitalRead(RED_BULB) == HIGH) {
    digitalWrite(LED4, HIGH);
  } else {
    digitalWrite(LED4, LOW);
  }
}
