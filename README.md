# Base Converter
Terminal-based C program that performs number conversions between **any base from 2 to 36**, handling both conventional and unconventional bases with input validation and error handling.

This project focuses on **string parsing, input validation, base arithmetic, and clean user interaction in C**. 
## Features
*   **Arbitrary Base Conversion**: Convert numbers between any base from 2 to 36.
*   **Extended Character Set**: Supports digits 0-9 and letters A-Z (case-insensitive).
*   **Error Handling & Recovery**: Detects invalid bases, malformed numbers, and overflow conditions with clear error messages.
*   **Input Validation**: Shows available digit sets for each base to help users understand valid inputs.

## How to Compile and Run
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/danilojonic/base-converter.git
    cd base-converter
    ```
2.  **Compile the program:**
    ```bash
    gcc base_converter.c -o base_converter -Wall -Wextra
    ```
3.  **Run the executable:**
    ```bash
    ./base_converter        # On Linux/macOS
    ```
## Interaction example
```
Enter the base to convert from: 16
Enter the number in that base: F
Enter wanted base to convert to: 2
~~~~~~~~~~~~~~~~~~~~
Converted number: 1111
~~~~~~~~~~~~~~~~~~~~
Do you want to perform another conversion? (y/n): y
Enter the base to convert from: 36
Enter the number in that base: ZzZ
Enter wanted base to convert to: 36
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Same base - no conversion needed!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Do you want to perform another conversion? (y/n): y
Enter the base to convert from: 35
Enter the number in that base: Z
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Error: 'Z' is not a valid number in base 35.
Base 35 uses the following digits: 0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W X Y
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Enter the number in that base: y
Enter wanted base to convert to: 15
~~~~~~~~~~~~~~~~~~~~
Converted number: 24
~~~~~~~~~~~~~~~~~~~~
Do you want to perform another conversion? (y/n): n
```
