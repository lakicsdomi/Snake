#ifndef SNAKE_H
#define SNAKE_H

#define MAX_LENGTH 100 // Max length for the snake (assuming maximum body size)

class Snake {
public:
    Snake(int initialLength);                                   // Constructor to initialize the snake with a given length
    void move(int direction);                                   // Move the snake in the specified direction (0: up, 1: right, 2: down, 3: left)
    void grow();                                                // Grow the snake by one unit
    bool checkCollision(int rows = 8, int cols = 8);            // Check for collision with walls or itself
    void getBody(int body[MAX_LENGTH][2], int &length) const;   // Get the snake's body coordinates
    int getLength() const;                                      // Get the current length of the snake               
    int getHeadX() const;                                       // Get the X coordinate of the snake's head
    int getHeadY() const;                                       // Get the Y coordinate of the snake's head

private:
    int snake[MAX_LENGTH][2];   // Snake body coordinates (max length is 100)
    int length;                 // Current length of the snake
};

#endif
