const int led = 2;
const int button = 0;
bool isPress = false;
bool state = false;

void ARDUINO_ISR_ATTR isr() {
    isPress = true;
    state = !digitalRead(led); // Cập nhật trạng thái LED khi nút được nhấn
    digitalWrite(led, state);
}
void setup() {
    Serial.begin(115200);
    pinMode(button, INPUT_PULLUP);
    attachInterrupt(button, isr, RISING);
    pinMode(led, OUTPUT);
}
void loop() {
  if (isPress) {
    Serial.println(state ? "Led On" : "Led Off"); // In ra trạng thái LED
    isPress = false;
  }
}
