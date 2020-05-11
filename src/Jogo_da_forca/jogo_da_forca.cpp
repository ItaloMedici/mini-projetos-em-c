#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void palav_escond(char *x, int tam){
    int i;
    printf("\n\n\t    ");
    for(i=0;i<tam;i++){
        printf("%c",x[i]);
    }
    printf("\n\n");
}

void score(int x , int y, int z){
    printf("  Tentativas: %d   Acertos: %d   Tamanho palavra: %d", x,y,z);
}



int main (){
    char palavra[30], letra=' ', resp;
    int i, j, tam_palavra, max_tentativas, acertos, espc;
    bool correto, saida;

    do {
        max_tentativas = 0;
        tam_palavra = 0;
        espc = 0;
        acertos = 0;
        max_tentativas = 0;
        correto = false;
        saida = false;

        system("cls");

        printf("Digite uma palavra: ");
        fflush(stdin);
        gets(palavra);
        fflush(stdin);
        system("cls");

        tam_palavra = strlen(palavra);
        
        max_tentativas = tam_palavra / 2;

        char escondida[tam_palavra-1];

        for(i=0;i<tam_palavra;i++){
            escondida[i]='_';
            escondida[tam_palavra]=' ';
        }

        for(j=0;j<palavra[j] != '\0';j++){
            if(palavra[j]==' '){
                escondida[j]=' ';
                espc+1;
            }
        }

        char *escond = escondida;

        do{       
            correto = false;
            letra=' ';
            char aux = letra;

            score(max_tentativas,acertos, tam_palavra);

            palav_escond(escond, tam_palavra);

            tolower(printf("Digite uma letra: "));
            fflush(stdin);
            scanf("%c", &letra);
            fflush(stdin);

            for(i=0;i<palavra[i] != '\0';i++){
                if(palavra[i]==letra){
                    escondida[i] = letra;
                    acertos++;
                    correto = true;
                }
            }

            if(!correto){
                max_tentativas--;
            }

            if(max_tentativas == 0 || (acertos-espc) == (tam_palavra-espc)){
                saida = true;
            }

            system("cls");         

        }while(saida == false);

        score(max_tentativas, acertos, tam_palavra);

        palav_escond(escond, tam_palavra);

        if(!correto){
            printf("\tFORCA!\n      Voce perdeu!\n\n");
        }

        else{
            printf("\tParabens!\n      Voce venceu!\n\n");
        }

        tolower(printf("Quer jogar novamente? [s/n]: "));
        scanf("%s", &resp);

    } while(resp != 'n');

    printf("\n\n");
    system("pause");
    return 0;
}