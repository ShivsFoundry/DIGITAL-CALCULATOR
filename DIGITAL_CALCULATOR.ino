/*
  ============================================================
   Digital Calculator using Arduino UNO
   Simulated in Tinkercad Circuits
  ============================================================
   Description:
   A simple 4-function calculator built with a 4x4 matrix
   keypad and a 16x2 LCD display. Supports addition,
   subtraction, multiplication, and division of two numbers.

   Hardware:
   - LCD (16x2) connected in 4-bit mode
   - 4x4 Matrix Keypad

   Note: Pin assignments and program logic are unchanged
   from the original implementation.
  ============================================================
*/

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

// ---------- LCD Setup ----------
// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// ---------- Calculator Variables ----------
long first  = 0;   // Stores the first number entered
long second = 0;   // Stores the second number entered
double total = 0;  // Stores the result of the calculation
char customKey;    // Stores the current key pressed

// ---------- Keypad Setup ----------
const byte ROWS = 4;
const byte COLS = 4;

// Keypad layout
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

byte rowPins[ROWS] = {7, 6, 5, 4}; // Row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0}; // Column pinouts of the keypad

// Create the keypad object
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ---------- Setup ----------
void setup()
{
  lcd.begin(16, 2); // Initialize the 16x2 LCD

  // Startup / welcome message
  lcd.setCursor(0, 0);
  lcd.print(" Calculator By");
  lcd.setCursor(0, 1);
  lcd.print(" ShivsFoundry");
  delay(4000);

  lcd.clear();
  lcd.setCursor(0, 0);
}

// ---------- Main Loop ----------
void loop()
{
  customKey = customKeypad.getKey();

  switch (customKey)
  {
    // Digits 0-9: build up the first number digit by digit
    case '0' ... '9':
      lcd.setCursor(0, 0);
      first = first * 10 + (customKey - '0');
      lcd.print(first);
      break;

    // Addition
    case '+':
      first = (total != 0 ? total : first); // Allow chained calculations
      lcd.setCursor(0, 1);
      lcd.print("+");
      second = getSecondNumber();            // Read the second number
      total = first + second;
      lcd.setCursor(0, 3);
      lcd.print(total);
      first = 0;
      second = 0;                            // Reset for next calculation
      break;

    // Subtraction
    case '-':
      first = (total != 0 ? total : first);
      lcd.setCursor(0, 1);
      lcd.print("-");
      second = getSecondNumber();
      total = first - second;
      lcd.setCursor(0, 3);
      lcd.print(total);
      first = 0;
      second = 0;
      break;

    // Multiplication
    case '*':
      first = (total != 0 ? total : first);
      lcd.setCursor(0, 1);
      lcd.print("*");
      second = getSecondNumber();
      total = first * second;
      lcd.setCursor(0, 3);
      lcd.print(total);
      first = 0;
      second = 0;
      break;

    // Division
    case '/':
      first = (total != 0 ? total : first);
      lcd.setCursor(0, 1);
      lcd.print("/");
      second = getSecondNumber();
      lcd.setCursor(0, 3);
      if (second == 0)
        lcd.print("Invalid");       // Prevent division by zero
      else
        total = (float)first / (float)second;
      lcd.print(total);
      first = 0;
      second = 0;
      break;

    // Clear: reset everything
    case 'C':
      total = 0;
      lcd.clear();
      break;
  }
}

// ---------- Helper Function ----------
// Reads the second number entered on the keypad,
// displaying digits as they are pressed, until '=' is pressed.
long getSecondNumber()
{
  while (true)
  {
    customKey = customKeypad.getKey();

    if (customKey >= '0' && customKey <= '9')
    {
      second = second * 10 + (customKey - '0');
      lcd.setCursor(0, 2);
      lcd.print(second);
    }

    if (customKey == '=')
      break; // Finished entering the second number
  }

  return second;
}
