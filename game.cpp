#include "Game.h"

Game::Game(int rows, int cols, int initSize) : snake(3), apple(rows, cols), gameRunning(false), rows(rows), cols(cols), initSize(initSize) {}

void Game::startGame() {
    gameRunning = true;
    snake = Snake(initSize);  // Reset the snake
    apple = Apple(rows,cols);
    apple.spawnApple(snake);
    
}

void Game::stopGame() {
    // Reset the game state
    gameRunning = false;
}

int  Game::update(char direction) {
    if (!gameRunning) return -1; // Skip updates if the game is not running

    int intDirection;
    switch (direction) {
        case 'W': intDirection = 0; break; // Up
        case 'D': intDirection = 1; break; // Right
        case 'S': intDirection = 2; break; // Down
        case 'A': intDirection = 3; break; // Left
        default: return -1; // Invalid direction, skip update
    }

    // Move the snake
    snake.move(intDirection);

    // Check for collisions
    if (snake.checkCollision(rows, cols)) {
        stopGame();
        return 1;
    }

    // Check if the snake eats the apple
    if (apple.isEaten(snake.getHeadX(), snake.getHeadY())) {
        snake.grow();
        apple.spawnApple(snake); // Ensure apple avoids the snake's body
        return 2;
    }
    return 0;
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
