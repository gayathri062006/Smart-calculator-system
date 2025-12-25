# Smart Basic Arithmetic Calculator System
Goal: Implement a simple calculator that performs basic arithmetic operations (addition, subtraction, multiplication, and division) using a microcontroller, keypad, and display.
## Features
A 4x4 keypad is used to enter numbers and select operators (+, −, ×, ÷) and the equals/cancel keys.
A 16x2 LCD (or similar display) shows the typed expression and the computed result in real time.
The microcontroller reads key presses, builds multi‑digit operands, performs the chosen arithmetic operation in code, and handles basic error cases (such as division by zero).
The design can be extended later with additional functions like clear entry, decimal support, or memory operations (M+, M−, recall).
##nHardware & Tools
Arduino Uno or Arduino Nano (or any similar microcontroller board).
4x4 matrix keypad for numeric and operator input.
16x2 LCD display (parallel or I2C) to show inputs and results.
Resistors, potentiometer (for LCD contrast), breadboard, and jumper wires.
Optional: USB power supply and simulation environment (such as an online Arduino simulator) for testing.
## How It Works
The keypad is connected to the microcontroller; each key press is scanned and mapped to a corresponding digit or operator.
The first sequence of digits forms operand 1; after an operator is pressed, the next sequence forms operand 2.
When the equals key is pressed, the microcontroller performs the selected arithmetic operation on the two operands and sends the result to the LCD for display.
A clear/reset key lets the user clear the display and start a new calculation without resetting the entire system.
## Simulation
Simulator project link: https://wokwi.com/projects/451317515949973505
## Code
Main code file: smart_basic_calculator.ino​
