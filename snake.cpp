#include "Snake.h"

Snake::Snake(int initialLength) : length(initialLength) {
    // Initialize snake body at (0, 0)
    for (int i = 0; i < length; i++) {
        snake[i][0] = 0;  // Row
        snake[i][1] = i;  // Column (horizontal alignment)
    }
}

void Snake::move(int direction) {
    // Update the snake's position based on the direction
    // Directions: Up (0), Right (1), Down (2), Left (3)
    int dx[] = {0, 1, 0, -1}; // Directions: Up, Right, Down, Left
    int dy[] = {-1, 0, 1, 0}; // Directions: Up, Right, Down, Left

    // Move the head
    snake[0][0] += dx[direction];
    snake[0][1] += dy[direction];

    // Move the body
    for (int i = length - 1; i > 0; i--) {
        snake[i][0] = snake[i - 1][0];
        snake[i][1] = snake[i - 1][1];
    }
}

bool Snake::checkCollision(int rows, int cols) {

    // Check for collision with walls
    if (snake[0][0] < 0 || snake[0][0] >= rows || snake[0][1] < 0 || snake[0][1] >= cols) {
        return true;
    }

    // Check for collision with itself
    for (int i = 1; i < length; i++) {
        if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
            return true;
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


