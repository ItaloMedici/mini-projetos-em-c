#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

/*
float money(){
    float cash = 0;
    return money();
}
*/

int main(){
    float cash = 0, cent = 0.05; 
    bool pass = false;
    char resp;

    printf("\tDo ou wanna be a Billionaire?\n\n\t\tAperte qualquer tecla para iniciar");

    do{

        cash = 0;

        system("cls");

        if(!kbhit()){
            pass = true;
        }

        getch();
        fflush(stdin);

        if(pass){
            while(!kbhit()){
                system("cls");
                printf("===================+ Be a Billionaire +===================\n\n");
                if(cash >= 1000000 && cash < 1000000000) printf("\t\t\tMilionario\n\n");
                else if(cash >= 1000000000) printf("\t\t\tBILIONARIO!!\n\n");
                printf("\t\t\tR$%.2f", cash);
                Sleep(0.1);
                //cash += 0.55;
                cash += 1155;
            }

            getch(); 
            fflush(stdin);

            printf("\n\n\t\tVoce fez R$%.2f!!");
        }

        toupper(printf("\n\nGstaria de ir novamente? "));
        scanf("%c", &resp);

        if(resp == 'S') system("exit");

    }while(resp != 'S');
    

    system("Pause");

    return 0;
}