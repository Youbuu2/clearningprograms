#include <stdio.h>

int main(void){
    int a[50],size,i,pos;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    printf("Enter elements of array\n");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
     //print statement
    for (i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    //end of print statement
    printf("Enter position you want to delete\n");
    scanf("%d",&pos);
    if (pos<0||pos>size+1)
    {
        printf("Invalid input\n");
    }
    else{
    for(i=(pos-1);i<size;i++){
        a[i]=a[i+1];
    }
    size--;
    for (i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    }
    return 0;
}

/*
 //print statement
    for (i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    //end of print statement
*/