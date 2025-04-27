#include "LedControl.h"  // for led
#include <stdlib.h>
#include "Game.h"
#include "Joystick.h"
#include "Apple.h"
#include "Snake.h"

#define LENGTH 8  // rows
#define WIDTH 8   // cols
#define LEN 3     // initial snake length
#define MAX_LENGTH 100 // Max length for the snake (assuming maximum body size)

// Pins
const int SW_pin = 2;                   // digital pin connected to switch output
const int X_pin = 0;                    // analog pin connected to X output
const int Y_pin = 1;                    // analog pin connected to Y output
const int button = 7;                   // button to toggle game
const int buzzer = 5;                   // digital pin connected to buzzer

// Game state
const int refreshRate = 200;            // refresh rate of the game
bool isOn = false;                      // true if the game is on
int X_axis;                             // X-axis value from joystick
int Y_axis;                             // Y-axis value from joystick
char field[LENGTH][WIDTH];              // Game field
char currentDirection = 'D';            // Initial movement direction

// Game objects
Game gameObj(LENGTH, WIDTH, LEN);            // Create Game object
Joystick joystick(X_pin, Y_pin);            // Create Joystick object
LedControl lc = LedControl(12, 10, 11, 1); // MAX7219 dotmatrix module

void setup() {
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);

  pinMode(SW_pin, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(SW_pin, HIGH);
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button) == LOW && !isOn) {
    gameOn();
  } else if (digitalRead(button) == LOW && isOn) {
    gameOff();
  }

  if (isOn) {
    runSnakeGame();
  }
}

void gameOn() {
  isOn = true;
  gameObj.startGame();  // Start the game by initializing the snake and apple
  currentDirection = 'D';  // Set initial direction
  refreshGame();
}

void gameOff() {
  isOn = false;
  gameObj.stopGame();  // Stop the game
  lc.clearDisplay(0);
}

char getDirection() {
  X_axis = analogRead(X_pin);
  Y_axis = analogRead(Y_pin);
  char newDirection = joystick.getDirection(X_axis, Y_axis);  // Get joystick direction

  // Prevent reversing direction directly
  if ((currentDirection == 'W' && newDirection == 'S') ||
      (currentDirection == 'S' && newDirection == 'W') ||
      (currentDirection == 'A' && newDirection == 'D') ||
      (currentDirection == 'D' && newDirection == 'A')) {
    return ' '; // Ignore invalid direction change
  }

  return newDirection;
}

void runSnakeGame() {
  // Read joystick values to get the movement direction
  char direction = getDirection();
  if (direction != ' ') {
    currentDirection = direction;
  }

  // Update the game state based on the joystick direction
  gameObj.update(currentDirection);

  // If the game is over, stop it
  if (!gameObj.isRunning()) {
    gameOff();
    return;
  }

  // Refresh the display with the current game state
  refreshGame();
  delay(refreshRate);  // Wait before the next update
}

void refreshGame() {
  lc.clearDisplay(0);  // Clear the display

  // Draw the snake on the display
  int snakeBody[MAX_LENGTH][2];
  int snakeLength = 0;
  gameObj.getSnakeBody(snakeBody, snakeLength);  // Get the snake's body

  // Loop through each part of the snake's body and display it
  for (int i = 0; i < snakeLength; i++) {
    lc.setLed(0, snakeBody[i][0], snakeBody[i][1], true);
  }

  // Draw the apple on the display
  int appleX = gameObj.getAppleX();
  int appleY = gameObj.getAppleY();
  lc.setLed(0, appleX, appleY, true);  // Draw the apple
}
