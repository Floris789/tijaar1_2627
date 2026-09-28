#include <stdio.h>
int pin1 = 0;
int pin2 = 0;
int pin3 = 0;
int main(){
    if ((pin1 == 1 && pin2 ==1) == (pin2 || pin3)){
        printf("fik erin\n");
    }
}