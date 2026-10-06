 #include <stdio.h>

int main(){
    int blokken = 0;
    int j = 0;
    while(blokken <= 10){
        printf("waaaaaah!\n");
        if (blokken %3 == 0){
            if(blokken/7 == 0){
                while(blokken !=9){
                    printf("voeg een blauw blok toe. %d blokken totaal\n", ++blokken);
                }       
        }
        else{
            while(j<6){
                if(j%2 == 0){
                    printf("voeg groen blok toe. %d blokken totaal", blokken);
                }
                else{
                    printf("voeg rood blok toe. %d blokken totaal", blokken);
                }
                j++;
                blokken++;
            }
            }
        }
    }
}