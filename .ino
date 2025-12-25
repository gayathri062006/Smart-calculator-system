#include <Keypad.h>
#include <LiquidCrystal.h>

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '=', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// LCD configuration (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, A0, A1, A2, A3);

// Calculator variables
String input = "";
float num1 = 0;
char operation = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Calculator Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey) {
    Serial.print(customKey);
    lcd.print(customKey);
    
    // Number input (0-9)
    if (customKey >= '0' && customKey <= '9') {
      input += customKey;
    }
    
    // Decimal point input
    else if (customKey == '.' && input.indexOf('.') == -1) {
      input += customKey;
    }
    
    // Operator input (+, -, *, /)
    else if (customKey == '+' || customKey == '-' || 
             customKey == '*' || customKey == '/') {
      if (input.length() > 0) {
        num1 = input.toFloat();
        operation = customKey;
        input = "";
        lcd.setCursor(0, 1);  // Move to second line
      }
    }
    
    // Calculate result when '=' pressed
    else if (customKey == '=') {
      if (input.length() > 0) {
        float num2 = input.toFloat();
        float result = 0;
        
        switch (operation) {
          case '+':
            result = num1 + num2;
            break;
          case '-':
            result = num1 - num2;
            break;
          case '*':
            result = num1 * num2;
            break;
          case '/':
            if (num2 != 0) {
              result = num1 / num2;
            } else {
              lcd.clear();
              lcd.print("Error: Div by 0");
              delay(2000);
              lcd.clear();
              input = "";
              return;
            }
            break;
        }
        
        Serial.println(result);
        lcd.clear();
        lcd.print("Result:");
        lcd.setCursor(0, 1);
        lcd.print(result);
        delay(3000);
        lcd.clear();
        input = "";
        num1 = 0;
        operation = 0;
      }
    }
  }
}
