#include "Joystick.h"

Joystick::Joystick(int xPin, int yPin) : xPin(xPin), yPin(yPin) {} // Constructor to initialize the joystick pins

char Joystick::getDirection(int X_axis, int Y_axis) { 
    // Get the direction based on joystick position
    if (X_axis < 256) return 'A';  // Move Left
    if (X_axis > 768) return 'D';  // Move Right
    if (Y_axis < 256) return 'W';  // Move Up
    if (Y_axis > 768) return 'S';  // Move Down
    return ' ';  // No movement
}
