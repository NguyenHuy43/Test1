const int led = 2;
String inputString ="";

// Hàm nhấp nháy LED
void flashLED() {
  for (int i = 0; i < 5; ++i) {
    digitalWrite(led, HIGH); // Turn on the LED
    delay(1000); // Wait for 1 second
    digitalWrite(led, LOW); // Turn off the LED
    delay(1000); // Wait for 1 second
  }
}
void processCommand(String text) {
    if (text == "OFF") {
      digitalWrite(led, LOW);
      Serial.println("LED is turned OFF");
    }
    if (text == "ON") {
      digitalWrite(led, HIGH);
      Serial.println("LED is turned ON");
    }
    if (text == "BLYNK") {
      flashLED();
      Serial.println("LED flash");
    }
}
void setup() {
  Serial.begin(115200); 
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}
void loop() {
  if (Serial.available() > 0) {
    String text = Serial.readStringUntil('\n'); // Read the entire line from Serial Monitor
    // Process the received command
    processCommand(text);
  }
}

