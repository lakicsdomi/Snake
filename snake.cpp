#include "Snake.h"

Snake::Snake(int initialLength) : length(initialLength) {
   // Initialize snake body with the head to the right
  for (int i = 0; i < length; i++) {
    snake[i][0] = 0;  // All segments are on the same row (row 0)
    snake[i][1] = length - i - 1;  // Columns decrease from right to left
  }
}

void Snake::move(int direction) {
    // Store the tail position before moving (optional if tail erasing is needed)
    int tailX = snake[length - 1][0];
    int tailY = snake[length - 1][1];

    // Move the body segments in reverse order
    for (int i = length - 1; i > 0; i--) {
        snake[i][0] = snake[i - 1][0];
        snake[i][1] = snake[i - 1][1];
    }

    // Update the head position based on direction
    int dx[] = {-1, 0, 1, 0};  // W (Up), D (Right), S (Down), A (Left)
    int dy[] = {0, 1, 0, -1};  // W (Up), D (Right), S (Down), A (Left)
    snake[0][0] += dx[direction];
    snake[0][1] += dy[direction];

}

bool Snake::checkCollision(int rows, int cols) {
    // Check for collision with walls
    if (snake[0][0] < 0 || snake[0][0] >= rows || snake[0][1] < 0 || snake[0][1] >= cols) {
        return true;
    }

    // Check for collision with itself (only if length > 1)
    if (length > 1) {
        for (int i = 1; i < length; i++) {
            if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
                return true;
            }
        }
    }

    return false;
}

void Snake::grow() {
    // Grow the snake by adding a new segment at the end
    if (length < MAX_LENGTH) {
        snake[length][0] = snake[length - 1][0];  // Copy last segment's position
        snake[length][1] = snake[length - 1][1];
        length++;
    }
}

void Snake::getBody(int body[MAX_LENGTH][2], int &lengthOut) const {
    // Copy the snake's body coordinates to the provided array and set the length
    lengthOut = length;
    for (int i = 0; i < length; i++) {
        body[i][0] = snake[i][0];
        body[i][1] = snake[i][1];
    }
}

int Snake::getLength() const {
    // Return the current length of the snake
    return length;
}

int Snake::getHeadX() const {
    // Return the X coordinate of the snake's head
    return snake[0][0];
}

int Snake::getHeadY() const {
    // Return the Y coordinate of the snake's head
    return snake[0][1];
}
