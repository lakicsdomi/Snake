# Snake Game using Arduino Uno

This project is a simple implementation of the classic Snake game using an Arduino Uno. The game is programmed in C++ and designed to run on Arduino hardware. It is an excellent project for beginners in electronics and programming, as well as for enthusiasts looking to recreate a nostalgic game on Arduino.

## Youtube video
[Snake game console for Arduino](https://www.youtube.com/watch?v=QkUwiWnua5w)

## Features

- **Classic Snake Gameplay:** Enjoy the timeless Snake game mechanics, where the snake grows longer as it eats food.
- **Button Controls:** Navigate the snake using Joystick inputs for up, down, left, and right movements.
- **Customizable Display:** Visualize the game using an LED matrix or other display modules for a more interactive experience.
- **Compact Design:** The circuit is simple and designed to fit on a breadboard, making it portable and easy to assemble.

## Requirements

To build and run this project, you will need the following components:

- **Hardware:**
  - Arduino Uno
  - Breadboard
  - Jumper wires
  - Joystick (to move the snake)
  - LED matrix or other display module (optional, for game visualization)
  - Push buttons (to turn the game on and off)
  - Buzzer (for audio feedback)

- **Software:**
  - Arduino IDE (for writing and uploading the code)

Ensure you have all the components and the Arduino IDE installed before proceeding.

## Wiring diagram:
![wiring_diagram](https://github.com/user-attachments/assets/6b1227a5-8a61-47e0-9f84-a24511b1e269)


## Installation

Follow these steps to set up the project:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/lakicsdomi/Snake.git
   ```
2. **Open the Code in Arduino IDE:**
   - Launch the Arduino IDE and open the `.ino` file located in the repository.
3. **Upload the Code:**
   - Connect your Arduino Uno to your computer via USB.
   - Select the correct board and port from the "Tools" menu.
   - Click on the "Upload" button in the Arduino IDE to upload the code to the Arduino.

## How to Play

1. Once the circuit is assembled and the code is uploaded, power on the Arduino Uno.
2. To turn on the game, use the push button. Same for turning it off.
3. Use the joystick to control the snake's movement:
   - Up, Down, Left, and Right correspond to the snake's direction.
4. The objective of the game is to eat the apples appearing on the display without colliding with the snake's own body or the walls.
5. The game ends when the snake crashes.

## Troubleshooting

- **No Response from Buttons or Joystick:** 
  - Ensure the buttons or joystick are properly connected to the Arduino.
  - Check the code to ensure the correct pins are defined for the buttons or joystick. 
- **Display Not Working:**
  - Verify the wiring of the LED matrix or display module.
  - Consult the datasheet for the correct pin configuration.
- **Code Compilation Errors:**
  - Ensure you have installed the necessary libraries in the Arduino IDE.

## Future Improvements

- Add more sound effects using a buzzer for a more engaging experience.
- Implement different levels with increasing difficulty.
- Use a larger display module for better visibility.
- Implement score system.
- Include a pause feature for convenience during gameplay.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests if you have ideas for improving the project.

## License

This project is open-source and available under the MIT License. Feel free to use, modify, and distribute it as per the license terms.
