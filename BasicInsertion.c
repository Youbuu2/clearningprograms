#include <stdio.h>

int main(void){
    int a[50],size,i,num,pos;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    printf("Enter elements of array\n");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter data you want to insert\n");
    scanf("%d",&num);
    printf("%d\n",num);
    printf("Enter position\n");
    scanf("%d",&pos);
    if (pos<0||pos>size+1)
    {
        printf("Invalid input\n");
    }
    else{
    for(i=(size-1);i>=(pos-1);i--){
        a[i+1]=a[i];
    }
    //print statement
    for (i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    //end of print statement
    a[pos-1]=num;
    size++;
    for (i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
    }
    return 0;
}