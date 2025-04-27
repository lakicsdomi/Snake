#include "Apple.h"
#include <stdlib.h>  // for rand and srand
#include <time.h>    // for seeding the random number generator

Apple::Apple(int rows, int cols) : rows(rows), cols(cols), x(-1), y(-1) {}

void Apple::spawnApple() {
    // Generate a random position for the apple
    x = rand() % cols;  // random X position within the width
    y = rand() % rows;  // random Y position within the height
}

bool Apple::isEaten(int snakeHeadX, int snakeHeadY) {
    // Check if the apple is eaten by comparing its position with the snake's head position
    return (x == snakeHeadX && y == snakeHeadY);
}

int Apple::getX() const { return x; } // Get the X position of the apple
int Apple::getY() const { return y; } // Get the Y position of the apple
