#ifndef JOYSTICK_H
#define JOYSTICK_H

class Joystick {
    public:
        Joystick(int xPin, int yPin); // Constructor to initialize the joystick pins
        char getDirection(int X_axis, int Y_axis); // Get the direction based on joystick position
    
    private:
        int xPin, yPin; // Pins for X and Y axes
};

#endif //JOYSTICK_H