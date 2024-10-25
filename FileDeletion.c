#include <stdio.h>

int main(void){
    if (remove("BilboBaggins.txt")==0)
    {
        printf("Got his ass outta here");
    }
    else{
        printf("His ass still here\n");
    }
    system("pause");
    return 0;
}