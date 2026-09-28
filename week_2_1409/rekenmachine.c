#include <stdio.h>

int main(){
    float num1;
    float num2;
    float result;
    int choice;
    printf("🧮 Welkom bij de Rekenmachine!\nVoer een berekening in de vorm: getal operator getal\nVoorbeeld: 5 * 4\nEerste getal:");
    scanf("%f", &num1);
    printf("Operator (1 = +, 2 = -, 3 = *, 4 = /): ");
    scanf("%d", &choice);
    printf("Tweede getal:");
    scanf("%f", &num2);
    printf("%0.2f", num1);
    switch(choice){
        case 1:
            printf(" + ");
            result = num1 + num2;
            break;
        case 2:
            printf(" - ");
            result = num1 - num2;
            break;
        case 3:
            printf(" * ");
            result = num1 * num2;
            break;
        case 4:
            printf(" / ");
            result = num1 / num2;
            break;
        default:
            printf("geen geldige waarde");
            break;
    }
    printf("%0.2f = ", num2);
    printf("%0.2f\n", result);
}