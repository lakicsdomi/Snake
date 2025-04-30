#ifndef APPLE_H
#define APPLE_H

#include "Snake.h"

class Apple{
    public:
        Apple(int rows, int cols); // Constructor to initialize the apple's position and grid size
        void spawnApple(const Snake &snake); // Spawn a new apple at a random position
        bool isEaten(int snakeHeadX, int snakeHeadY); // Check if the apple is eaten by the snake
        int getX() const; // Get the X position of the apple
        int getY() const; // Get the Y position of the apple

    private:
        int x, y;  // Position of the apple
        int rows, cols;  // Grid size
};
#endif  // APPLE_H
