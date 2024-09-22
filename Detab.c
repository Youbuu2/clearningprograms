#include <stdio.h>
#define MAXLINE 1000
int TAB=4;

int getline(char line[], int maxline);
void copy(char to[],char from[]);

int main(void){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while((getline(line, MAXLINE))>0){
            copy(longest,line);
            printf("%s",longest);
        
    }
        return 0;
}

int getline(char line[],int maxline){
    int c, i;
    for (i=0; i<maxline-1 && (c=getchar())!=EOF && c!= '\n';++i){
        line[i]=c;
    }
    if (c=='\n'){
        line[i]=c;
        ++i;
    }
    line[i]='\0';
    return i;
}

void copy(char to[], char from[]){
    int i,j,TAB;
    i=j=0;
    while((to[i]=from[j])!='\0')
    if (to[i]!='\t')
    {
       ++i;
       ++j;
    }
    else{
        while(TAB){
            to[i]=' ';
            ++i;
            --TAB;
        }
        ++i;
        ++j;
    }
    
}