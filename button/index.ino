// docs functions; https://docs.arduino.cc/language-reference/#functions
#define BUTTON_PIN 12

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);
  delay(200);
}