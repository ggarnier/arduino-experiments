const int green = 12;
const int yellow = 10;
const int red = 7;
const int button = 2;
int buttonState;
int lastButtonState = LOW;
int lightStart = 0;
int currentState = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  lightStart = millis();
}

void loop() {
  if (millis() - lightStart >= 3000) {
    lightStart = millis();
    stateChange();
  }
  int reading = digitalRead(button);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        currentState = 0;
        stateChange();
      }
    }
  }

  lastButtonState = reading;
}

void stateChange() {
  if (currentState == 0) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    currentState++;
  } else if (currentState == 1) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    currentState++;
  } else {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    currentState = 0;
  }
}
