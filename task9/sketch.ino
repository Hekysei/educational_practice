const int redLedPin = 9;
const int greenLedPin = 5;
const int ldrPin = A0;

// const float GAMMA = 0.7;
// const float RL10 = 50;

const unsigned long openDuration = 2000;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  Serial.begin(9600);

  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  Serial.println("Система запущена. Дверь закрыта.");
}

bool isDoorOpen = false;

void loop() {
  int analogValue = analogRead(A0);
  // float voltage = analogValue / 1024. * 5;
  // float resistance = 2000 * voltage / (1 - voltage / 5);
  // float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  if (analogValue > 512) {
    if (!isDoorOpen) {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, HIGH);

      Serial.println("Дверь открывается");
      isDoorOpen = true;
    }

    delay(openDuration);
  } else {
    if (isDoorOpen) {
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);

      Serial.println("Дверь закрывается");
      isDoorOpen = false;
    }
    delay(100);
  }
}