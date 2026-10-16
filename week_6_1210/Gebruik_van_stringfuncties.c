#include <stdio.h>

char value1[] = "teskt1";
char value2[] = "tekst2";
char anw[15];
int k = 6;
void functie(){
    for (int i = 0; value1[i] != '\0'; i++){
    anw[i] = value1[i];
    }
    for (int j = 0; value2[j] != '\0'; j++){
    anw[k + j] = value2[j];
    }
}
int main(){
    functie();
    printf("%s\n", anw);
    //functie
    

}

