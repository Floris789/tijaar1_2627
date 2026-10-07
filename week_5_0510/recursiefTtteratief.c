#include <stdio.h>

// int andwoord = 1;
int faculteit(int p){
    if (p <= 1) return p;
    printf("p: %d\n", p);
    return p * faculteit(p-1);
    printf("p: %d\n", p);
}
int main(){
    printf("teksts: %d\n", faculteit(30)); 
}

int andwoord;
int main(){
    printf("nummer gedobbeld: ");
    scanf("%d", &andwoord);

    for (int i=andwoord -1; i >=1 ; i--){
        andwoord = andwoord * i;
        printf("Resultaat: %d\n", andwoord);
    }
}