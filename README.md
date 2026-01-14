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
