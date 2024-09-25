#include <stdio.h>

#define MAXSTR 10000  // Maximum input string size

#define TRUE (1 == 1)  // Define TRUE as 1
#define FALSE !TRUE    // Define FALSE as 0 (the opposite of TRUE)

int get_str(char str[], int limit);
void check_syntax(char str[]);

int main(void)
{
  char str[MAXSTR];  // Array to hold the input string

  get_str(str, MAXSTR);  // Read input into `str[]`
  check_syntax(str);  // Check the syntax of the input

  return 0;
}

int get_str(char str[], int limit)
{
  int c, i = 0;

  // Read characters into the string until EOF or the limit is reached
  while (i < limit - 1 && (c = getchar()) != EOF)
  {
    str[i++] = c;  // Store each character in the array
  }
  str[i] = '\0';   // Null-terminate the string

  return i;  // Return the number of characters read
}

void check_syntax(char str[])
{
  // Track the balance of parentheses, brackets, and braces
  int parentheses = 0;
  int brackets = 0;
  int braces = 0;

  // Flags to track if we're inside single or double quotes
  int single_quotes = FALSE;
  int double_quotes = FALSE;

  // Flags to track if we're inside block or line comments
  int block_comment = FALSE;
  int line_comment = FALSE;

  int i = 0;
  // Check each character in the string while making sure no unbalanced brackets/braces exist
  while (str[i] != '\0' && parentheses >= 0 && brackets >= 0 && braces >= 0)
  {
    // Only count braces, parentheses, and brackets if we're not in a comment or a quote
    if (!line_comment && !block_comment && !single_quotes && !double_quotes)
    {
      // Track parentheses
      if (str[i] == '(')
      {
        ++parentheses;
      }
      else if (str[i] == ')')
      {
        --parentheses;
      }

      // Track square brackets
      if (str[i] == '[')
      {
        ++brackets;
      }
      else if (str[i] == ']')
      {
        --brackets;
      }

      // Track curly braces
      if (str[i] == '{')
      {
        ++braces;
      }
      else if (str[i] == '}')
      {
        --braces;
      }
    }

    // Handle single and double quotes only when not in a comment
    if (!line_comment && !block_comment)
    {
      // Enter a single-quote context if not inside any quotes
      if (str[i] == '\'' && !single_quotes && !double_quotes)
      {
        single_quotes = TRUE;
      }
      // Exit single-quote context (handles escaped quotes properly)
      else if (single_quotes && str[i] == '\'' && (str[i - 1] != '\\' || str[i - 2] == '\\'))
      {
        single_quotes = FALSE;
      }

      // Enter a double-quote context if not inside any quotes
      if (str[i] == '"' && !single_quotes && !double_quotes)
      {
        double_quotes = TRUE;
      }
      // Exit double-quote context (handles escaped quotes properly)
      else if (double_quotes && str[i] == '"' && (str[i - 1] != '\\' || str[i - 2] == '\\'))
      {
        double_quotes = FALSE;
      }
    }

    // Handle block and line comments (only outside of quotes)
    if (!single_quotes && !double_quotes)
    {
      // Enter block comment if not already in a comment
      if (str[i] == '/' && str[i + 1] == '*' && !line_comment)
      {
        block_comment = TRUE;
      }
      // Exit block comment when "*/" is found
      else if (str[i] == '*' && str[i + 1] == '/')
      {
        block_comment = FALSE;
      }

      // Enter single-line comment (//)
      if (str[i] == '/' && str[i + 1] == '/' && !block_comment)
      {
        line_comment = TRUE;
      }
      // Exit single-line comment when a newline is encountered
      else if (str[i] == '\n')
      {
        line_comment = FALSE;
      }
    }

    ++i;  // Move to the next character
  }

  // If any unbalanced parentheses are detected
  if (parentheses)
  {
    printf("Error: unbalanced parentheses.\n");
  }

  // If any unbalanced brackets are detected
  if (brackets)
  {
    printf("Error: unbalanced brackets.\n");
  }

  // If any unbalanced braces are detected
  if (braces)
  {
    printf("Error: unbalanced braces.\n");
  }

  // If a single quote was opened but never closed
  if (single_quotes)
  {
    printf("Error: unbalanced single quotes.\n");
  }

  // If a double quote was opened but never closed
  if (double_quotes)
  {
    printf("Error: unbalanced double quotes.\n");
  }

  // If a block comment was opened but never closed
  if (block_comment)
  {
    printf("Error: block comment not closed.\n");
  }
}
