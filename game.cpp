#include "Game.h"

Game::Game(int rows, int cols, int initSize) : snake(3), apple(rows, cols), gameRunning(false), rows(rows), cols(cols), initSize(initSize) {}

void Game::startGame() {
    snake = Snake(initSize);  // Reset the snake
    apple = Apple(rows,cols);
    apple.spawnApple();
    gameRunning = true;
}

void Game::stopGame() {
    // Reset the game state
    gameRunning = false;
}

void Game::update(char direction) {
  // Update the snake's position based on the given direction
  snake.move(direction);  // Move the snake based on the current direction

  // Check if the snake collides with the wall or itself
  if (snake.checkCollision(rows, cols)) {
    stopGame();  // Stop the game if collision happens
  }

  // Check if the snake eats an apple
  if (apple.isEaten(snake.getHeadX(), snake.getHeadY())) {
    snake.grow();   // Grow the snake
    apple.spawnApple();  // Spawn a new apple
  }
}

void Game::getSnakeBody(int body[MAX_LENGTH][2], int &lengthOut) const {
  // Get the snake's body coordinates and length
  snake.getBody(body,lengthOut);
}

int Game::getAppleX() {
  // Get the apple's X position
  return apple.getX();  // Get the apple's X position
}

int Game::getAppleY() {
  // Get the apple's Y position
  return apple.getY();  // Get the apple's Y position
}

void Game::restart() {
  // Restart the game
    startGame();
}

bool Game::isRunning(){
  // Check if the game is running
  return gameRunning;
}
