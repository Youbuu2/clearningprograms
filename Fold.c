#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define FOLDLENGTH 10  // Maximum number of characters before folding

int getline(char line[], int maxline);
void fold(char line[], int fold_length);

int main(void) {
    char line[MAXLINE];
    
    // Read the input line
    while ((getline(line, MAXLINE)) > 0) {
        // Fold the line
        fold(line, FOLDLENGTH);
        printf("%s", line);  // Output the folded line
    }
    
    return 0;
}

// Read input line into 'line[]', return its length
int getline(char line[], int maxline) {
    int c, i;
    
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';  // Null-terminate the line
    return i;
}

// Fold long lines into shorter ones
void fold(char line[], int fold_length) {
    int i = 0, counter = 0, last_space_index = -1;
    char temp[MAXLINE];
    int temp_index = 0;

    while (line[i] != '\0') {
        temp[temp_index++] = line[i];

        // Update the last space index
        if (line[i] == ' ') {
            last_space_index = temp_index - 1;
        }

        counter++;

        // If we've hit the fold length, we need to fold the line
        if (counter >= fold_length) {
            if (last_space_index != -1) {
                // If we found a space, fold at the space
                temp[last_space_index] = '\n';  // Replace space with newline
                counter = temp_index - last_space_index - 1;  // Reset counter after the newline
                last_space_index = -1;  // Reset the last space index
            } else {
                // If no space was found, fold at the current position
                temp[temp_index++] = '\n';  // Insert newline
                counter = 0;  // Reset counter
            }
        }
        
        i++;
    }

    // Copy the folded text back to the original line array
    temp[temp_index] = '\0';
    strcpy(line, temp);  // Copy temp back into the original line array
}
