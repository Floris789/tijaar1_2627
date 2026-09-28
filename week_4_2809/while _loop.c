#include <stdio.h>

int main(){
    int studentenInKlas = 23;
    int studentenMetDruif = 1;

    while(studentenMetDruif <= studentenInKlas){
        printf("\nstudenten met druif. %d studenten hebben nu een druif", studentenMetDruif);
        studentenMetDruif++;
    }
}