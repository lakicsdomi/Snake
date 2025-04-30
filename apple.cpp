#include "Apple.h"
#include <stdlib.h>  // for rand and srand
#include <time.h>    // for seeding the random number generator
#include "Snake.h"
Apple::Apple(int rows, int cols) : rows(rows), cols(cols), x(-1), y(-1) {}

void Apple::spawnApple(const Snake &snake) {
    bool validPosition = false;
    while (!validPosition) {
        x = random(0, rows);  // Generate random position
        y = random(0, cols);
        validPosition = true;

        // Check if the new position overlaps with the snake
        int snakeBody[MAX_LENGTH][2];
        int snakeLength = 0;
        snake.getBody(snakeBody, snakeLength);

        for (int i = 0; i < snakeLength; i++) {
            if (snakeBody[i][0] == x && snakeBody[i][1] == y) {
                validPosition = false;
                break;
            }
        }
    }
}


bool Apple::isEaten(int snakeHeadX, int snakeHeadY) {
    // Check if the apple is eaten by comparing its position with the snake's head position
    return (x == snakeHeadX && y == snakeHeadY);
}

int Apple::getX() const { return x; } // Get the X position of the apple
int Apple::getY() const { return y; } // Get the Y position of the apple
