#include <stdio.h>

#define IN 1   /* inside a word */
#define OUT 0  /* outside a word */

/* count lines, words, and characters in input */
int main(void)
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            printf("\n");
        }
        else if (state == OUT) {
            state = IN;
            printf("*");
        }
        else
        printf("*");
    }
    return 0;
}
