#include <stdio.h>

#define IN 1   // Defines the state where we are inside a comment
#define OUT 0  // Defines the state where we are outside a comment

void remove_comments();  // Declare the function to remove comments

int main() {
    remove_comments();  // Call the function to start removing comments
    return 0;  // Program ends successfully
}

void remove_comments() {
    int c, next;           // `c` stores the current character, `next` stores the next character
    int state = OUT;       // `state` keeps track of whether we are inside or outside a comment
    int in_string = 0;     // `in_string` is 1 if we are inside a string literal, 0 otherwise
    int in_char = 0;       // `in_char` is 1 if we are inside a character constant, 0 otherwise

    while ((c = getchar()) != EOF) {  // Keep reading characters from input until end of file (EOF)
        
        // Check if we are inside a string literal (we skip comment detection inside strings)
        if (c == '"' && in_char == 0) {  // If we see a double-quote and we are NOT in a character constant
            in_string = !in_string;  // Toggle `in_string`: if it's 0, set to 1, if 1, set to 0
            putchar(c);  // Print the quote since it's part of the string
            continue;  // Continue to the next character without further checks
        }

        // Check if we are inside a character constant (we skip comment detection inside character constants)
        if (c == '\'' && in_string == 0) {  // If we see a single quote and we are NOT inside a string
            in_char = !in_char;  // Toggle `in_char`: if it's 0, set to 1, if 1, set to 0
            putchar(c);  // Print the quote since it's part of the character constant
            continue;  // Continue to the next character without further checks
        }

        // Handle comments only when we are NOT inside a string or character constant
        if (!in_string && !in_char) {
            // Handle single-line comments (//)
            if (c == '/') {  // If we see a slash (/), we need to check if it's the start of a comment
                next = getchar();  // Read the next character to see if it's another slash or an asterisk
                if (next == '/') {  // It's a single-line comment (//)
                    // Skip all characters until we hit a newline
                    while ((c = getchar()) != EOF && c != '\n');
                    putchar('\n');  // Print the newline to end the single-line comment
                } else if (next == '*') {  // It's a multi-line comment (/* */)
                    // Skip all characters until we find the closing */
                    while ((c = getchar()) != EOF) {
                        if (c == '*') {  // If we find an asterisk (*), it might be the end of the comment
                            next = getchar();  // Check the next character
                            if (next == '/') {  // If the next character is a slash (/), the comment ends
                                break;  // Exit the comment skipping loop
                            }
                        }
                    }
                } else {
                    // It's not a comment, so print both the slash (/) and the next character
                    putchar(c);
                    putchar(next);
                }
            } else {
                putchar(c);  // If it's not part of a comment, just print the character
            }
        } else {
            // If we are inside a string or character constant, just print the character
            putchar(c);
        }
    }
}