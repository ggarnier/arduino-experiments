const int green = 12;
const int yellow = 10;
const int red = 7;
const int button = 2;
const int stateDuration = 4000;
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
  int now = millis();
  if (now - lightStart >= stateDuration) {
    lightStart = now;
    stateChange();
  }
  int reading = digitalRead(button);
  if (reading != lastButtonState) {
    lastDebounceTime = now;
  }

  if ((now - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH && currentState == 0) {
        lightStart = now;
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
    currentState = 1;
  } else if (currentState == 1) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    currentState = 2;
  } else {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    currentState = 0;
  }
}
