#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int char_value(char c) {
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else if(c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else return -1;
}

char value_char(int value) {
    if(value >= 0 && value <= 9)
        return '0' + value;
    else if(value >= 10 && value <= 35)
        return 'A' + (value - 10);
    else return '?';
}

int is_valid(char *number, int base) {
    int i = 0;

    if(number[0] == '-' || number[0] == '+')
        i = 1;

    for(; number[i] != '\0'; i++) {
        int value = char_value(number[i]);
        if (value == -1 || value >= base) {
            return 0;
        }
    }

    if(i == 0 || (i == 1 && (number[0] == '-' || number[0] == '+')))
        return 0;
        
    return 1;
}

// Function to convert from any base to decimal
long long convert_to_decimal(char *number, int from_base) {
    long long result = 0;
    int i = 0;
    int negative = 0;

    if(number[0] == '-') {
        negative = 1;
        i = 1;
    } else if(number[0] == '+') {
        i = 1;
    }

    for(; number[i] != '\0'; i++) {
        int value = char_value(number[i]);
        result = result * from_base + value;
    }
    
    return negative ? -result : result;
}

// Function to convert decimal to any base
void convert_from_decimal(long long decimal, int to_base, char *result) {
    char temp[100];
    int index = 0;
    int negative = 0;

    if(decimal < 0) {
        negative = 1;
        decimal = -decimal;
    }

    if(decimal == 0) {
        temp[index++] = '0';
    } 
    else {
        while(decimal > 0) {
            int remainder = decimal % to_base;
            temp[index++] = value_char(remainder);
            decimal /= to_base;
        }
    }

    if(negative) {
        result[0] = '-';
        result++;
    }

    for(int i = 0; i < index; i++) {
        result[i] = temp[index - i - 1];
    }
    result[index] = '\0';

    if(negative) {
        result--;
    }
}

// Function to directly convert between two bases
void direct_conversion(char *number, int from_base, int to_base, char *result) {
    long long decimal = convert_to_decimal(number, from_base);
    convert_from_decimal(decimal, to_base, result);
}

// Function to display available digit symbols for a base
void display_info(int base) {
    printf("Base %d uses the following digits: ", base);
    for (int i = 0; i < base; i++) {
        if (i < base) {
            printf("%c", value_char(i));
            if (i < base - 1) printf(" ");
        }
    }
    printf("\n");
}

void clear_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF) {
    
    }
}

int main() {
    char number[100];
    char result[100];
    char choice;
    int from_base, to_base;

    do {
        while(1) {
            printf("Enter the base to convert from: ");
            if(scanf("%d", &from_base) != 1) {
                printf("~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Invalid input format!\n");
                printf("~~~~~~~~~~~~~~~~~~~~~\n");
                clear_buffer();
                continue;
            }
        
            if(from_base < 2 || from_base > 36) {
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Error: Source base must be between 2 and 36.\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                continue;
            }
            break;
        }

        while(1) {
            printf("Enter the number in that base: ");
            if(scanf("%s", number) != 1) {
                printf("~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Invalid input format!\n");
                printf("~~~~~~~~~~~~~~~~~~~~~\n");
                clear_buffer();
                continue;
            }
        
            if(!is_valid(number, from_base)) {
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Error: '%s' is not a valid number in base %d.\n", number, from_base);
                display_info(from_base);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                continue;
            }
            break;
        }
        
        while(1) {
            printf("Enter wanted base to convert to: ");
            if(scanf("%d", &to_base) != 1) {
                printf("~~~~~~~~~~~~~~\n");
                printf("Invalid input!\n");
                printf("~~~~~~~~~~~~~~\n");
                clear_buffer();
                continue;
            }
        
            if(to_base < 2 || to_base > 36) {
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Error: Target base must be between 2 and 36.\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                continue;
            }
            break;
        }
        
        if(from_base == to_base) {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Same base - no conversion needed!\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        }
        else {
            direct_conversion(number, from_base, to_base, result);
            printf("~~~~~~~~~~~~~~~~~~~~\n");
            printf("Converted number: %s\n", result);    
            printf("~~~~~~~~~~~~~~~~~~~~\n");
        }
        clear_buffer();
        
        printf("Do you want to perform another conversion? (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice);
        
        clear_buffer();
        
        } while(choice == 'y'); 
        
    return 0;
}
