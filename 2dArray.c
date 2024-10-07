#include <stdio.h>



int main(void){
    int i,j,a[2][3];
    printf("Enter the values for the 2d Array\n");
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%d",a[i][j]);
        }
    }
}
