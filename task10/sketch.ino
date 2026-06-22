#include <Servo.h>

const int32_t servoPin = 3;
int32_t servo_pos = 0;
int32_t targetAngle = 0;
const int32_t stepDelay = 5;

Servo myServo;

void setup() {
  myServo.attach(servoPin);
  myServo.write(servo_pos);

  Serial.begin(115200);
  Serial.println("Введите угол от 0 до 180:");
}

void RotateServo(int32_t target) {
  if (servo_pos < target) {
    for (; servo_pos <= target; servo_pos++) {
      myServo.write(servo_pos);
      delay(stepDelay);
    }
  } else {
    for (; servo_pos >= target; servo_pos--) {
      myServo.write(servo_pos);
      delay(stepDelay);
    }
  }
  servo_pos = target;
}

void loop() {
  String input = Serial.readStringUntil('\n');
  input.trim();
  if (input=='\n')
    return;

  bool valid = true;
  if (input.length() < 1 && input.length() > 3) {
    valid = false;
  } else {
    for (size_t i = 0; i < input.length(); i++) {
      if (!isDigit(input[i])) {
        valid = false;
        break;
      }
    }
  }

  if (valid) {
    int32_t target = input.toInt();
    if (target >= 0 && target <= 180) {
      RotateServo(target);
      Serial.println("Позиция достигнута.");
    } else {
      Serial.println("Ошибка: Допускаются только значения от 0 до 180.");
    }
  } else {
    Serial.println("Ошибка: Ввод должен быть строго числом.");
  }
}
