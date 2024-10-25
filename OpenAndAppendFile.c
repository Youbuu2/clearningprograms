#include <stdio.h>

int main(void){
    FILE *pF = fopen("BilboBaggins.txt","w");
    fprintf(pF, "Bilbo Baggins");
    fclose(pF);
    return 0;
}