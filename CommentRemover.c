#include <stdio.h>

#define MAXSTR 10000  // Maximum length of the input string

#define TRUE (1 == 1)  // Define TRUE as 1
#define FALSE !TRUE    // Define FALSE as 0 (the opposite of TRUE)

// This is a test comment.

int get_str(char str[], int limit); // This is another test comment.
void remove_comments(char str[], char no_com_str[]);

int main(void)
{
  /**
   * This is a multiline
   * block
   * comment.
  */

  char str[MAXSTR];         // Array to hold the original string (input source code)
  char no_com_str[MAXSTR];   // Array to hold the comment-free version of the string

  get_str(str, MAXSTR);  // Read the input (source code) into `str[]`

  remove_comments(str, no_com_str);  // Remove comments from `str[]` and store result in `no_com_str[]`

  printf("%s", no_com_str);  // Output the comment-free code

  return 0;  // Program ends successfully
}

// Function to read the input into the array `str[]`
int get_str(char str[], int limit)
{
  int c, i = 0;

  // Read characters until EOF or limit is reached
  while (i < limit - 1 && (c = getchar()) != EOF)
  {
    str[i++] = c;  // Store each character in the array
  }
  str[i] = '\0';   // Null-terminate the string

  return i;  // Return the length of the input string
}

// Function to remove comments from the source code
void remove_comments(char str[], char no_com_str[])
{
  // Flags to track states
  int in_quote = FALSE;       // Whether we're inside a string literal
  int line_comment = FALSE;   // Whether we're inside a single-line comment (//)
  int block_comment = FALSE;  // Whether we're inside a block comment (/* */)

  int i = 0, j = 0;  // `i` for input string index, `j` for output string index

  // Process each character in the input string `str[]`
  while (str[i] != '\0')  // Continue until the end of the string
  {
    // Handle strings (preserve anything inside quotes)
    if (!block_comment)  // If we are not inside a block comment
    {
      if (!in_quote && str[i] == '"')  // Entering a string literal (")
      {
        in_quote = TRUE;  // Toggle `in_quote` to TRUE when entering a string
      }
      else if (in_quote && str[i] == '"')  // Exiting the string literal (")
      {
        in_quote = FALSE;  // Toggle `in_quote` to FALSE when exiting the string
      }
    }

    // If we are not inside a string
    if (!in_quote)
    {
      // Detect start of block comment (/*)
      if (str[i] == '/' && str[i + 1] == '*' && !line_comment)
      {
        block_comment = TRUE;  // Enter block comment
      }

      // Detect end of block comment (*/)
      if (str[i] == '*' && str[i + 1] == '/')
      {
        block_comment = FALSE;  // Exit block comment
        i += 2;  // Skip past the "*/"
        continue;  // Go to the next character
      }

      // Detect start of single-line comment (//)
      if (str[i] == '/' && str[i + 1] == '/')
      {
        line_comment = TRUE;  // Enter single-line comment
      }

      // Detect end of single-line comment (newline)
      if (str[i] == '\n')
      {
        line_comment = FALSE;  // Exit single-line comment
      }

      // Skip characters that are part of a comment
      if (line_comment || block_comment)
      {
        ++i;  // Skip this character if we are inside a comment
      }
      // If not in a comment, copy characters to the new string
      else
      {
        no_com_str[j++] = str[i++];  // Copy non-comment characters to the output array
      }
    }
    else
    {
      // If we are inside a string, copy everything to the new string
      no_com_str[j++] = str[i++];  // Copy characters inside the string as-is
    }
  }

  no_com_str[j] = '\0';  // Null-terminate the output string
}

// NOTE: run the program with: ./CommentRemover < Test.c
