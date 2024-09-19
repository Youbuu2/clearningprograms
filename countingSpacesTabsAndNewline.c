#include<stdio.h>
int main(void){
    int c, nL, tB,Sp;
    //remember to initialize the counting variables in c
    // nL,tB,Sp=0; this line doesn't actually initialize all of these variable to 0
    nL=tB=Sp=0;
    while((c=getchar())!=EOF){
        if(c=='\n'){
            nL++;
        }
        else if(c=='\t'){
            tB++;
        }
        else if(c==' '){
            Sp++;
        }
    }
    printf("%d %d %d\n",nL,tB,Sp);
    return 0;
}