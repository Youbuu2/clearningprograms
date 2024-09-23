#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8


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




void copy(char to[], char from[]) {
    int i = 0, j = 0, space_count = 0;
    
    while (from[j] != '\0') {//while the second string hasn't hit the null terminator do the following
        if (from[j] == ' ') {//while it reads spaces count the spaces and increment through the second string
            space_count++;//count spaces
            j++;
        } else { //count up the counted spaces after the fact
            if (space_count > 0) {
                int tabs = space_count / TABSTOP;
                int spaces = space_count % TABSTOP;
                
                while (tabs > 0) {
                    to[i++] = '\t';
                    tabs--;
                }
                
                while (spaces > 0) {
                    to[i++] = ' ';
                    spaces--;
                }
                
                space_count = 0;
            }
            to[i++] = from[j++];
        }
    }
    
    if (space_count > 0) {//counts the trailing spaces and turns them into tabs and spaces
        int tabs = space_count / TABSTOP;
        int spaces = space_count % TABSTOP;
        
        while (tabs > 0) {
            to[i++] = '\t';
            tabs--;
        }
        
        while (spaces > 0) {
            to[i++] = ' ';
            spaces--;
        }
    }
    
    to[i] = '\0';
}
// void copy(char to[], char from[]){
//     int i,j,div,mod,Ti,Tj;
//     i=j=div=mod=0;
//     while((to[i]=from[j])!='\0'){
//     ++i;
//     ++j;
//     while((to[i]=from[j])==' ')
//     {
//         ++div;
//         ++mod;
//     }
//    }
// }