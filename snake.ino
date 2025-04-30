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
  lc.shutdown(0, false);  // Wake up MAX7219
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);

  pinMode(SW_pin, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(SW_pin, HIGH);
  pinMode(button, INPUT_PULLUP);
  doBlink();
  Serial.begin(9600);

  Serial.println("Setup complete. Game ready to start.");
}

void loop() {
  if (digitalRead(button) == LOW && !isOn) {
    Serial.println("Game ON button pressed.");
    gameOn();

  } else if (digitalRead(button) == LOW && isOn) {
    Serial.println("Game OFF button pressed.");
    gameOff();
  }

  if (isOn) {
    runSnakeGame();
  }
}

void gameOn() {
  doLoadInAnimation();
  isOn = true;
  Serial.println("Game started.");
  gameObj.startGame();
  currentDirection = 'S';
  refreshGame();
}

void gameOff() {
  isOn = false;
  Serial.println("Game stopped.");
  gameObj.stopGame();
  lc.clearDisplay(0);
}

void getDirection() {
  X_axis = analogRead(X_pin);
  Y_axis = analogRead(Y_pin);

  Serial.print("Joystick X: ");
  Serial.print(X_axis);
  Serial.print(", Y: ");
  Serial.println(Y_axis);

  char newDirection = joystick.getDirection(X_axis, Y_axis);

  if ((currentDirection == 'W' && newDirection == 'S') ||
      (currentDirection == 'S' && newDirection == 'W') ||
      (currentDirection == 'A' && newDirection == 'D') ||
      (currentDirection == 'D' && newDirection == 'A')) {
    Serial.println("Invalid direction change ignored.");
    newDirection = ' ';
  }

  
  if (newDirection != ' ') {
    currentDirection = newDirection;
    Serial.print("Current direction updated to: ");
    Serial.println(currentDirection);
  }
  
  Serial.print("New direction: ");
  Serial.println(newDirection);

}

void runSnakeGame() {
  
  getDirection();
  int result = gameObj.update(currentDirection);
  if(result == 2){
      beepNTimes(1,50);
  }

  if (!gameObj.isRunning()) {   
    Serial.println("Game over detected.");
    doGameOverAnimation();
    gameOff();
    return;
  }

  refreshGame();
  delay(refreshRate);
}

void refreshGame() {
  lc.clearDisplay(0);
    int snakeBody[MAX_LENGTH][2];
    int snakeLength = 0;
    gameObj.getSnakeBody(snakeBody, snakeLength);

    // Turn on LEDs for the snake
    for (int i = 0; i < snakeLength; i++) {
        lc.setLed(0, snakeBody[i][0], snakeBody[i][1], true);
    }

    // Display the apple
    int appleX = gameObj.getAppleX();
    int appleY = gameObj.getAppleY();
    lc.setLed(0, appleX, appleY, true);
}


void beepNTimes(int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(buzzer, HIGH);
    delay(delayTime);
    digitalWrite(buzzer, LOW);
    delay(delayTime);
  }
}

void doBlink() {

  // Flashes the screen 5 times very fast.

  byte full[8] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111}; //Fills all dots on matrix
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, full[i]);
    }
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
    lc.clearDisplay(0);
    delay(50);
  }

}

void doLoadInAnimation() {

  // Starting animation

  for (int j = 3; j > 0; j--) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, B11111111);
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
    }
    lc.clearDisplay(0);
    delay(50);
  }

}

void doGameOverAnimation() {

  // Displays a trophy flashing

  byte cross[8] = {B10000001, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B10000001}; // 8 bytes that will display the trophy
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, cross[i]);
    }
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(buzzer, LOW);
    lc.clearDisplay(0);
    delay(250);
  }
  delay(300);
}
