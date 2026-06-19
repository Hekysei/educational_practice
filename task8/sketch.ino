#include "Adafruit_NeoPixel.h"

#define LED_PIN 3
#define NUMPIXELS 64
#define SWITCH_BUTTON_PIN 2
#define GAME_BUTTONS_PIN 8

// strip.Color(0, 0, 255)
#define BLUE (uint32_t)255

Adafruit_NeoPixel strip(NUMPIXELS, LED_PIN, NEO_GRB | NEO_KHZ800);

struct Position {
  int x;
  int y;
};

Position get_pos(int j) {
  int y = j / 8;
  int x = j % 8;

  if (y % 2 == 0) {
    x = 7 - x;
  }

  return {x, y};
}

// SNAKE ANIMATION
void SnakeInit(size_t i) {
  int mode = (i / NUMPIXELS) % 3;
  i %= NUMPIXELS;
  int prev_mode = (mode + 2) % 3;

  uint32_t color = BLUE << (mode * 8);
  for (int j = 0; j < NUMPIXELS; j++) {
    strip.setPixelColor(j, color);
    if (j == i)
      color = BLUE << (prev_mode * 8);
  }
}
void SnakeStep(size_t i) {
  int mode = (i / NUMPIXELS) % 3;
  i %= NUMPIXELS;

  strip.setPixelColor(i, BLUE << (mode * 8));
}

// LOL ANIMATION
void LOLInit(size_t i) {
}
void LOLStep(size_t i) {
  uint32_t color_on = 0x00FF0000;
  uint32_t color_off = 0;
  for (int j = 0; j < NUMPIXELS; j++) {
    bool is_on = false;
    Position pos = get_pos(j);
    int y = pos.y;
    int x = pos.x;

    if (y != 0 && y != 7) {
      x += i;
      x %= 13;

      if (y == 6) {
        if (x % 4 != 0)
          is_on = true;
      } else if (y == 1) {
        if (x % 8 == 1 || (x >= 5 && x <= 7))
          is_on = true;
      } else {
        if (x % 2 == 1 && (x % 4 == 1 || x == 7))
          is_on = true;
      }
    }

    strip.setPixelColor(j, (is_on) ? color_on : color_off);
  }
}

// GAME
int player_x = 3;
int player_y = 3;
int prev_buttons[4] = {HIGH, HIGH, HIGH, HIGH};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
void GameInit(size_t i) {
}
void GameStep(size_t i) {
  uint32_t color_on = 0x0000FF00;
  uint32_t color_off = 0;

  for (int j = 0; j < 4; j++) {
    bool state = digitalRead(GAME_BUTTONS_PIN + j);
    if (state == LOW && prev_buttons[j] == HIGH) {
      player_x = (player_x + dx[j] + 8) % 8;
      player_y = (player_y + dy[j] + 8) % 8;
    }
    prev_buttons[j] = state;
  }

  for (int j = 0; j < NUMPIXELS; j++) {
    bool is_on = false;
    Position pos = get_pos(j);
    if (pos.y == player_y && pos.x == player_x)
      is_on = true;
    strip.setPixelColor(j, (is_on) ? color_on : color_off);
  }
}

void setup() {
  strip.begin();
  strip.setBrightness(255);
  pinMode(SWITCH_BUTTON_PIN, INPUT_PULLUP);
  for (int j = 0; j < 4; j++)
    pinMode(GAME_BUTTONS_PIN + j, INPUT_PULLUP);
}

size_t i = 0;
int matrix_mode = 0;
bool prev_switch_button_state = HIGH;

void loop() {
  bool switch_button_state = digitalRead(SWITCH_BUTTON_PIN);

  if (switch_button_state == LOW && prev_switch_button_state == HIGH) {
    matrix_mode = (matrix_mode + 1) % 3;

    if (matrix_mode == 0)
      SnakeInit(i);
    if (matrix_mode == 1)
      LOLInit(i);
    if (matrix_mode == 2)
      GameInit(i);
  }
  prev_switch_button_state = switch_button_state;

  if (matrix_mode == 0)
    SnakeStep(i);
  if (matrix_mode == 1)
    LOLStep(i);
  if (matrix_mode == 2)
    GameStep(i);

  strip.show();
  delay(70);
  i++;
}
