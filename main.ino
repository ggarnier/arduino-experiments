const int green = 12;
const int yellow =10;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  digitalWrite(green, HIGH);
  digitalWrite(yellow, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  delay(1000);
}
