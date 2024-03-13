const int led = 2;
const int button = 0;
bool ledState = LOW;      // Trạng thái ban đầu của đèn là tắt

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // Đọc trạng thái của nút nhấn
  int buttonState = digitalRead(button);
  // Nếu nút được nhấn (chân đọc là LOW)
  if (buttonState == LOW) {
    delay(100);  // Chờ ngắn để tránh đọc giá trị nhiễu
    if (digitalRead(button) == LOW) {
      // Đảo trạng thái của đèn
      ledState = !ledState;

      // Bật hoặc tắt đèn tùy thuộc vào trạng thái mới của nó
      digitalWrite(led, ledState);

      Serial.print("Đèn ");
      Serial.print(ledState ? "bật" : "tắt");
    }
  }
}
