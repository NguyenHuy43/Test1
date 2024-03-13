const int led = 2;
const int btn_PIN = 0;
bool lastResetState = false;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(btn_PIN, INPUT);
}

void loop() {
  bool resetState = digitalRead(btn_PIN);

  if (resetState == HIGH && lastResetState == LOW) {
    // Bật LED và nhấp nháy 2 lần
    flashLED();
    flashLED();
  }
  // Lưu trạng thái reset hiện tại
  lastResetState = resetState;
}

// Hàm nhấp nháy LED
void flashLED() {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}
