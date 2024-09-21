#include <stdio.h>

int FarenheitToCentigrade(int choose);
main(){
    int choice;
    printf("If you want to convert from Fahrenheit to Celsius press 1 to Exit press 2\n");
    scanf("%d",&choice);
    while (choice==1)
    {
        choice=FarenheitToCentigrade(choice);
    }
}
int FarenheitToCentigrade(int choose){
            float fahr, celsius;
            switch (choose)
        {
            case 1:
            printf("Enter Fahrenheit to be converted to Celsius.\n");
            scanf("%f",&fahr); 
            celsius = (5.0/9.0)*(fahr-32.0);
            printf("%f\n",celsius);
            printf("If you want to convert from Fahrenheit to Celsius press 1 to Exit press 2\n");
            scanf("%d",&choose);
            break;
            default:
            break;
        }
        return choose;    
}
