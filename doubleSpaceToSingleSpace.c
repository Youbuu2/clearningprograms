#include<stdio.h>
int main(void){
    int c,eS=0;//setting eS or empty space to 0 means it is also false 
    while((c=getchar())!=EOF){
        if(c== ' '){//checks for the getchar being a space
            if (!eS){//if empty space is false or 0 this if statement will happen
                putchar(c); //take in the character
                eS=1;//set the empty space temp to 1 so it doesn't go through this if on the very next space
            }
            }//when the getchar is the second space it breaks out of the if c==' ' and restarts the while loop with a eS variable set to 1 so it skips the first if statement indefinitely until it hits a non space character. when it hits a non space character it prints the non space character and resets the eS to 0 so it can check again
            else{ //this one happens whenever the character is not a space
                putchar(c);
                eS=0;
            }
        }
    return 0;
}