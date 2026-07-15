/*****************************************************************************************
 *                              DIGITAL CALCULATOR 
 *----------------------------------------------------------------------------------------
 * Project Description:
 * This project demonstrates a simple 4-function Digital Calculator using Arduino UNO.
 * A 4x4 matrix keypad is used for input, and a 16x2 LCD is used to display the
 * numbers entered and the final calculated result.
 *
 * Components Used:
 * 1. Arduino UNO
 * 2. 4x4 Matrix Keypad (Number & Operator Input)
 * 3. 16x2 LCD Display (Result Output)
 *
 * Developed Using:
 * Arduino IDE
 * Tinkercad Circuit Simulator
 *
 *****************************************************************************************/

#include <Keypad.h>          // Include Keypad Library
#include <Wire.h>            // Include Wire Library
#include <LiquidCrystal.h>   // Include LCD Library

//----------------------------------------------------------------------------------------
// LCD Setup
//----------------------------------------------------------------------------------------
// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

//----------------------------------------------------------------------------------------
// Variable Declaration
//----------------------------------------------------------------------------------------

long   first  = 0;      // Stores the first number entered
long   second = 0;       // Stores the second number entered
double total  = 0;       // Stores the result of the calculation
char   customKey;        // Stores the current key pressed

//----------------------------------------------------------------------------------------
// Keypad Configuration
//----------------------------------------------------------------------------------------

const byte ROWS = 4;      // Four Rows
const byte COLS = 4;      // Four Columns

// Keypad Layout
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

byte rowPins[ROWS] = {7, 6, 5, 4};   // Row Pinouts of the Keypad
byte colPins[COLS] = {3, 2, 1, 0};   // Column Pinouts of the Keypad

// Create the Keypad Object
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//----------------------------------------------------------------------------------------
// Setup Function
//----------------------------------------------------------------------------------------

void setup()
{
  lcd.begin(16, 2);                 // Initialize the 16x2 LCD

  // Display Startup / Welcome Message
  lcd.setCursor(0, 0);
  lcd.print(" Calculator By");
  lcd.setCursor(0, 1);
  lcd.print(" ShivsFoundry");
  delay(4000);

  lcd.clear();
  lcd.setCursor(0, 0);
}

//----------------------------------------------------------------------------------------
// Main Program Loop
//----------------------------------------------------------------------------------------

void loop()
{
  customKey = customKeypad.getKey();

  switch (customKey)
  {
    //==============================================================================
    // SECTION 1 : NUMBER ENTRY (DIGITS 0-9)
    //==============================================================================

    case '0' ... '9':
      lcd.setCursor(0, 0);
      first = first * 10 + (customKey - '0');   // Build up the first number
      lcd.print(first);
      break;

    //==============================================================================
    // SECTION 2 : ADDITION
    //==============================================================================

    case '+':
      first = (total != 0 ? total : first);      // Allow chained calculations
      lcd.setCursor(0, 1);
      lcd.print("+");

      second = getSecondNumber();                 // Read the second number
      total  = first + second;

      lcd.setCursor(0, 3);
      lcd.print(total);

      first = 0;
      second = 0;                                  // Reset for next calculation
      break;

    //==============================================================================
    // SECTION 3 : SUBTRACTION
    //==============================================================================

    case '-':
      first = (total != 0 ? total : first);
      lcd.setCursor(0, 1);
      lcd.print("-");

      second = getSecondNumber();
      total  = first - second;

      lcd.setCursor(0, 3);
      lcd.print(total);

      first = 0;
      second = 0;
      break;

    //==============================================================================
    // SECTION 4 : MULTIPLICATION
    //==============================================================================

    case '*':
      first = (total != 0 ? total : first);
      lcd.setCursor(0, 1);
      lcd.print("*");

      second = getSecondNumber();
      total  = first * second;

      lcd.setCursor(0, 3);
      lcd.print(total);

      first = 0;
      second = 0;
      break;

    //==============================================================================
    // SECTION 5 : DIVISION
    //==============================================================================

    case '/':
      first = (total != 0 ? total : first);
      lcd.setCursor(0, 1);
      lcd.print("/");

      second = getSecondNumber();
      lcd.setCursor(0, 3);

      if (second == 0)
        lcd.print("Invalid");                    // Prevent division by zero
      else
        total = (float)first / (float)second;

      lcd.print(total);

      first = 0;
      second = 0;
      break;

    //==============================================================================
    // SECTION 6 : CLEAR / RESET
    //==============================================================================

    case 'C':
      total = 0;
      lcd.clear();
      break;
  }
}

//----------------------------------------------------------------------------------------
// Helper Function : Read Second Number
//----------------------------------------------------------------------------------------
// Reads the second number entered on the keypad, displaying digits as they
// are pressed, until the '=' key is pressed.
//----------------------------------------------------------------------------------------

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
      break;                                      // Finished entering the second number
  }

  return second;
}

/*****************************************************************************************
 *
 *                              END OF PROGRAM
 *
 *----------------------------------------------------------------------------------------
 * Functional Summary:
 *
 * 1. Number Entry
 *    -> Digits (0-9) are collected and built into the first number on the LCD.
 *
 * 2. Operator Selection
 *    -> Pressing +, -, *, or / selects the arithmetic operation and displays
 *       the chosen symbol on the LCD.
 *
 * 3. Second Number Entry
 *    -> getSecondNumber() reads digits until '=' is pressed, showing the
 *       running value on the LCD's second line.
 *
 * 4. Result Display
 *    -> The calculated total is displayed on the LCD. Division by zero is
 *       caught and displayed as "Invalid".
 *
 * 5. Clear Function
 *    -> Pressing 'C' resets the total and clears the LCD for a new calculation.
 *
 *****************************************************************************************/
