#include <stdio.h>
typedef struct{
    char name[25];
    float gpa;
}Student;


int main(void){
    Student student1={"Hoss",3.0};
    Student student2={"Goss",4.0};
    Student student3={"Moss",1.0};
    Student students[3] = {student1,student2,student3};
    for(size_t i=0; i<sizeof(students)/sizeof(students[0]);i++){
        printf("%-12s\t",students[i].name);
        printf("%.2f\n",students[i].gpa);
        fflush(stdout);
    }
    system("pause");
    return 0;
}