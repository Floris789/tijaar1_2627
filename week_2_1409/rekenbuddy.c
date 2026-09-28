#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int num1;
int and;
int main(){
    srand(time(NULL));
    printf("geef een nummer 1 t/m 10:");
    scanf("%d", &num1);
    int num2 = (rand() % 10) +1;
    printf("%d x %d =", num1 , num2);
    scanf("%d", &and);
    if (num1 * num2 == and){
        printf("goed\n");
    }else{
        printf("fout\n");
    }
}