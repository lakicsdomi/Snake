#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Apple.h"

#define MAX_LENGTH 100 // Max length for the snake (assuming maximum body size)

class Game {
    public:
        Game(int rows, int cols, int initSize);                             // Constructor to initialize the game with grid size and initial snake length
        void startGame();                                                   // Start the game by initializing the snake and apple
        void stopGame();                                                    // Stop the game
        void update(char direction);                                        // Update game state
        void getSnakeBody(int body[MAX_LENGTH][2], int &lengthOut) const;   // Get snake body
        int getAppleX();                                                    // Get apple's X position
        int getAppleY();                                                    // Get apple's Y position
        void restart();                                                     // Restart the game
        bool isRunning();                                                   // Check if the game is running
    
    private:
        Snake snake;        // Snake object
        Apple apple;        // Apple object
        bool gameRunning;   // Flag to check if the game is running
        int rows, cols;     // Grid size
        int initSize;       // Initial size of the snake
};

#endif  // GAME_H
