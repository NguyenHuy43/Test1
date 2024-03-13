const int led = 2;
const int button = 0;
bool isPress = false;
bool state = false;
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
      Serial.println("BLYNK");

    }
}
void ARDUINO_ISR_ATTR isr() {
    isPress = true;
    state = !digitalRead(led); // Cập nhật trạng thái LED khi nút được nhấn
    digitalWrite(led, state);
}
void setup() {
  Serial.begin(115200); 
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(button, isr, FALLING);
  digitalWrite(led, LOW);
}
void loop() {
  if (Serial.available() > 0) {
    String text = Serial.readStringUntil('\n'); // Read the entire line from Serial Monitor
    // Process the received command
    processCommand(text);
  }
  if (isPress) {
    Serial.println("Done interrupt"); // In ra trạng thái LED
    isPress = false;
  }
}

