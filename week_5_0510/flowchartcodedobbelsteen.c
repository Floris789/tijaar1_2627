#include <stdio.h>
char naam;
int nummer;
int main(){
    while (1){
        printf("naam: ");
        scanf(" %c", &naam);
        printf("nummer gedobbeld: ");
        scanf("%d", &nummer);
        switch (nummer) {
            case 1:
                printf("shank\n");
                printf("shank\n");
                break;
            case 2:
                printf("vuurbal\n");
                printf("ice ball\n");
                break;
            case 3:
                printf("iceball\n");
                printf("vuurbal\n");
                break;
            case 4:
                printf("koe\n");
                printf("die of cringe\n");
                break;
        }
    }
}