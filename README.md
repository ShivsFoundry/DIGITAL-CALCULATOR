# 🧮 Digital Calculator using Arduino UNO

A simple yet powerful **Digital Calculator** built using an **Arduino UNO**, a **4×4 Matrix Keypad**, and a **16×2 LCD Display**. This project demonstrates how a microcontroller can process user input, perform arithmetic operations, and display results in real time.

Designed and tested using **Tinkercad Circuits**, this project is ideal for beginners learning Arduino programming, embedded systems, and digital electronics. The calculator supports the four basic arithmetic operations—**Addition**, **Subtraction**, **Multiplication**, and **Division**—through an intuitive keypad interface with instant output on the LCD.

---

# 📖 Project Overview

The **Digital Calculator using Arduino UNO** is an educational embedded systems project that replicates the functionality of a basic handheld calculator using commonly available electronic components.

The Arduino continuously scans the keypad for user input, interprets the entered numbers and mathematical operators, performs the requested calculation, and immediately displays the result on a **16×2 LCD**. The project demonstrates important embedded programming concepts such as keypad interfacing, LCD communication, conditional statements, functions, loops, and user input handling.

This project was developed primarily for learning purposes and is suitable for:

- Engineering Students
- Diploma Students
- Arduino Beginners
- Electronics Hobbyists
- STEM Learning
- Embedded Systems Practice

---

# ✨ Features

- 🧮 Performs basic arithmetic operations
  - Addition (+)
  - Subtraction (-)
  - Multiplication (×)
  - Division (÷)

- 🔢 Supports multi-digit number input.

- ⌨️ User-friendly 4×4 matrix keypad interface.

- 📟 Real-time result display on a 16×2 LCD.

- 🚫 Prevents division by zero by displaying an error message.

- 🔄 Supports continuous calculations using the previous result.

- 🧹 One-key calculator reset using the **C** button.

- 💻 Fully compatible with Arduino IDE.

- 🌐 Simulated and tested in Tinkercad Circuits.

- 🎓 Beginner-friendly source code with clear program structure.

---

# 🛠 Hardware Components

| Component | Quantity | Purpose |
|-----------|:--------:|---------|
| Arduino UNO | 1 | Main microcontroller |
| 16×2 LCD Display | 1 | Displays numbers and results |
| 4×4 Matrix Keypad | 1 | User input device |
| 220Ω Resistor | 1 | LCD backlight current limiting |
| Breadboard | 1 | Circuit assembly |
| Jumper Wires | As Required | Electrical connections |
| USB Cable | 1 | Power supply and program uploading |

---

# 💡 Component Functions

## Arduino UNO

The Arduino UNO acts as the brain of the calculator. It continuously reads the keypad input, processes mathematical operations, and sends the calculated result to the LCD display.

---

## 4×4 Matrix Keypad

The keypad serves as the input device of the calculator. It allows the user to enter numbers and mathematical operators.

Available keys include:

- Numbers (0–9)
- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)
- Equals (=)
- Clear (C)

---

## 16×2 LCD Display

The LCD provides a simple interface for displaying:

- Entered numbers
- Selected operator
- Final calculation result
- Error messages

---

## 220Ω Resistor

The resistor is connected to protect the LCD backlight by limiting the current flowing through it.

---

# ⚙ Software Requirements

Before building the project, install the following software:

| Software | Version |
|----------|---------|
| Arduino IDE | Latest Recommended |
| Tinkercad Circuits | Online |
| Arduino AVR Board Package | Installed through Board Manager |

---

# 📚 Required Libraries

This project uses only standard Arduino libraries.

```cpp
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
```

These libraries are responsible for:

| Library | Purpose |
|----------|---------|
| Keypad.h | Reads key presses from the 4×4 matrix keypad |
| LiquidCrystal.h | Controls the 16×2 LCD display |
| Wire.h | Included for compatibility (not actively used in this project) |

---

# 📂 Project Structure

```
Digital-Calculator/
│
├── Arduino Source Code
├── README.md
├── LICENSE
├── SECURITY.md
└── CONTRIBUTING.md
```

---

# 🔌 Arduino Pin Connections

The following table lists all Arduino pin connections used in this project.

| Arduino Pin | Connected Component |
|-------------|--------------------|
| D13 | LCD RS |
| D12 | LCD Enable |
| D11 | LCD D4 |
| D10 | LCD D5 |
| D9 | LCD D6 |
| D8 | LCD D7 |
| D7 | Keypad Row 1 |
| D6 | Keypad Row 2 |
| D5 | Keypad Row 3 |
| D4 | Keypad Row 4 |
| D3 | Keypad Column 1 |
| D2 | Keypad Column 2 |
| D1 | Keypad Column 3 |
| D0 | Keypad Column 4 |
| 5V | LCD VCC |
| GND | LCD GND |

---

# 🔍 Project Workflow

The calculator follows a simple sequence of operations:

1. The Arduino waits for a key press.
2. The first number is entered.
3. The desired arithmetic operator is selected.
4. The second number is entered.
5. Press the **=** key.
6. The Arduino performs the calculation.
7. The result is displayed on the LCD.
8. Press **C** at any time to clear the calculator and start a new calculation.

# 🔧 Building the Circuit in Tinkercad

This project was designed and tested using **Tinkercad Circuits**, allowing users to simulate the complete calculator before implementing it on physical hardware.

Follow the steps below to recreate the circuit exactly as used in this project.

---

# Step 1 – Create a New Circuit

1. Open **Tinkercad**.
2. Navigate to **Circuits**.
3. Click **Create New Circuit**.
4. Drag an **Arduino UNO** onto the workspace.
5. Place a **Large Breadboard** next to the Arduino.
6. Add the following components:
   - 16×2 LCD Display
   - 4×4 Matrix Keypad
   - 220Ω Resistor
   - Jumper Wires

Arrange the components neatly to make wiring easier and improve readability.

---

# Step 2 – Power Connections

Before connecting individual components, establish common power rails.

### Arduino Power

- Connect the **5V** pin of the Arduino UNO to the breadboard's positive (+) rail.
- Connect one **GND** pin of the Arduino UNO to the breadboard's negative (−) rail.

These rails will be used to power the LCD.

> **Note:** The keypad used in this project does not require separate power connections.

---

# Step 3 – Connect the LCD Display

The LCD operates in **4-bit mode**, reducing the number of Arduino pins required.

### LCD Connections

| LCD Pin | Connect To |
|----------|------------|
| VSS | GND |
| VDD | 5V |
| V0 | Contrast Adjustment (as shown in the circuit) |
| RS | Arduino D13 |
| RW | GND |
| E | Arduino D12 |
| D4 | Arduino D11 |
| D5 | Arduino D10 |
| D6 | Arduino D9 |
| D7 | Arduino D8 |
| LED+ | 5V through 220Ω Resistor |
| LED− | GND |

The LCD displays:

- Entered numbers
- Selected operator
- Final calculation result
- Error messages

---

# Step 4 – Connect the 4×4 Matrix Keypad

The keypad consists of **8 terminals**:

- Four Row Pins
- Four Column Pins

Connect them exactly as shown below.

### Row Connections

| Keypad Pin | Arduino Pin |
|------------|-------------|
| Row 1 | D7 |
| Row 2 | D6 |
| Row 3 | D5 |
| Row 4 | D4 |

### Column Connections

| Keypad Pin | Arduino Pin |
|------------|-------------|
| Column 1 | D3 |
| Column 2 | D2 |
| Column 3 | D1 |
| Column 4 | D0 |

These connections match the Arduino program exactly.

---

# Step 5 – Verify the Wiring

Before starting the simulation, ensure that:

- Every LCD wire matches the pin connection table.
- The keypad rows and columns are connected correctly.
- The Arduino 5V pin supplies the LCD.
- All ground connections are common.
- The resistor is connected to the LCD backlight.
- No wires are loose or connected to the wrong pins.

A quick verification at this stage can prevent most common wiring errors.

---

# Circuit Summary

| Module | Connected To |
|---------|--------------|
| LCD Display | Digital Pins D8–D13 |
| Keypad | Digital Pins D0–D7 |
| Power | Arduino 5V & GND |

---

# 💻 Uploading the Arduino Program

After completing the wiring, upload the calculator program.

### Using Arduino IDE

1. Open **Arduino IDE**.
2. Create a new sketch.
3. Copy the source code from this repository.
4. Paste it into the new sketch.
5. Save the file.
6. Select **Arduino UNO** from **Tools → Board**.
7. Select the correct COM port from **Tools → Port**.
8. Click the **Upload** button.
9. Wait until the upload is completed successfully.

---

### Using Tinkercad

1. Open the project circuit.
2. Click the **Code** button.
3. Select **Text** mode.
4. Replace the default program with this project's source code.
5. Click **Start Simulation**.

The calculator will initialize automatically and display the welcome screen.

---

# ▶️ How to Use the Calculator

After powering the circuit or starting the simulation:

### Entering Numbers

Press the numeric keys (0–9) to enter the first number.

Example:

```
125
```

will display:

```
125
```

---

### Selecting an Operation

Choose one of the available operators:

```
+
-
*
/
```

The selected operator will appear on the LCD.

---

### Entering the Second Number

Type the second number using the keypad.

Example:

```
25
```

---

### Calculating the Result

Press:

```
=
```

The Arduino processes the calculation and immediately displays the result on the LCD.

---

### Clearing the Calculator

Press:

```
C
```

to:

- Clear the LCD
- Reset all stored values
- Start a new calculation

# ⚙️ Working Principle

The Digital Calculator operates by continuously scanning the **4×4 Matrix Keypad** for user input. When a numeric key is pressed, the Arduino stores the entered value as the first operand. After selecting an arithmetic operator (`+`, `-`, `*`, or `/`), the Arduino waits for the second operand to be entered. Once the **`=`** key is pressed, the Arduino performs the selected mathematical operation and immediately displays the result on the **16×2 LCD Display**.

The calculator also supports **continuous calculations**, allowing the previous result to be reused for the next operation without restarting the program. Additionally, the program prevents division by zero by displaying an **"Invalid"** message instead of attempting an undefined calculation.

---

# 🧠 Program Flow

The overall workflow of the calculator is shown below.

```
Start
   │
   ▼
Initialize LCD
   │
   ▼
Display Welcome Message
   │
   ▼
Wait for Number Input
   │
   ▼
Store First Number
   │
   ▼
Wait for Operator
   │
   ▼
Read Second Number
   │
   ▼
Press "="
   │
   ▼
Perform Calculation
   │
   ▼
Display Result
   │
   ▼
Wait for Next Operation
```

---

# ➗ Supported Arithmetic Operations

| Operator | Function | Example |
|-----------|----------|----------|
| **+** | Addition | 25 + 10 = 35 |
| **-** | Subtraction | 50 - 15 = 35 |
| **\*** | Multiplication | 7 × 5 = 35 |
| **/** | Division | 70 ÷ 2 = 35 |
| **C** | Clear Calculator | Resets all values |
| **=** | Calculate Result | Executes the selected operation |

---

# 🧪 Testing the Project

After uploading the Arduino program or starting the Tinkercad simulation, verify each function using the following procedure.

## Test 1 – Welcome Screen

When the calculator starts, the LCD should display:

```
Calculator By
ShivsFoundry
```

for approximately **4 seconds**, after which the screen will clear automatically.

---

## Test 2 – Number Entry

Press any numeric key.

Example:

```
1
2
3
```

The LCD should display:

```
123
```

confirming that multi-digit input is working correctly.

---

## Test 3 – Addition

Perform the following sequence:

```
15
+
25
=
```

Expected Result:

```
40
```

---

## Test 4 – Subtraction

```
50
-
18
=
```

Expected Result:

```
32
```

---

## Test 5 – Multiplication

```
12
*
8
=
```

Expected Result:

```
96
```

---

## Test 6 – Division

```
100
/
4
=
```

Expected Result:

```
25
```

---

## Test 7 – Division by Zero

```
50
/
0
=
```

Expected Result:

```
Invalid
```

This confirms that the calculator safely handles divide-by-zero conditions.

---

## Test 8 – Clear Function

Press:

```
C
```

The LCD should clear immediately, allowing a new calculation to begin.

---

# 📂 Code Overview

The Arduino program is divided into simple sections to improve readability and maintenance.

| Section | Purpose |
|----------|---------|
| Library Files | Includes required Arduino libraries |
| LCD Initialization | Configures the 16×2 LCD |
| Keypad Configuration | Defines keypad layout and pin mapping |
| Variable Declaration | Stores numbers and calculation results |
| Setup Function | Initializes the LCD and displays the welcome message |
| Loop Function | Reads keypad input and performs calculations |
| Helper Function | Reads the second number until the `=` key is pressed |

This modular structure makes the code easy to understand for beginners.

---

# ⚠️ Troubleshooting

If the calculator does not work as expected, verify the following:

### LCD is Blank

- Check LCD power connections.
- Verify the LCD pin mapping.
- Ensure the contrast pin is adjusted correctly.
- Confirm the 220Ω resistor is connected properly.

---

### Keypad Does Not Respond

- Verify all row and column connections.
- Ensure the keypad pin order matches the Arduino program.
- Check for loose jumper wires.

---

### Incorrect Calculation

- Confirm that the operator key is pressed before entering the second number.
- Press **`=`** after entering the second number.
- Use **`C`** to reset the calculator before starting a new calculation if necessary.

---

### Arduino Program Does Not Upload

- Verify that the correct board (**Arduino UNO**) is selected.
- Select the correct COM port.
- Ensure all required libraries are installed.
- Restart the Arduino IDE if upload errors persist.

---

# 🎯 Applications

This project demonstrates the practical use of Arduino in digital electronics and embedded systems. It can be used for:

- Arduino Learning Projects
- Embedded Systems Laboratory Experiments
- Engineering Mini Projects
- Diploma Electronics Projects
- STEM Education
- Digital Electronics Demonstrations
- Microcontroller Programming Practice
- Tinkercad Simulation Learning

---

# 🚀 Future Improvements

The calculator can be extended with additional features such as:

- Scientific calculator functions
- Percentage calculations
- Square root and power operations
- Decimal number support
- Memory storage (M+, M−, MR)
- Battery-powered portable design
- PCB implementation
- Custom enclosure using 3D printing

---

# 📸 Circuit Diagram

The circuit diagram used in this project is shown below.

> **Note:** The complete circuit has been designed and tested using **Tinkercad Circuits**. Refer to the repository image for the exact component placement and wiring configuration.

---

# 📜 License

This project is licensed under the **MIT License**.

You are free to use, modify, distribute, and build upon this project for educational or personal purposes in accordance with the terms of the license.

---

# 🤝 Contributing

Contributions are welcome. If you have ideas for improving the project, fixing issues, or enhancing the documentation, feel free to fork the repository and submit a Pull Request.

Please read the **CONTRIBUTING.md** and **SECURITY.md** files before contributing.

---

# ⭐ Support

If you found this project helpful, consider giving the repository a **⭐ Star** on GitHub.

Your support helps improve the project and encourages the development of more open-source Arduino projects.

---

## 👨‍💻 Author

**ShivsFoundry**

Arduino • Embedded Systems • Electronics • Open Source

---

### Thank you for visiting this repository!

If this project helped you learn something new, consider sharing it with others and exploring more Arduino-based projects.
