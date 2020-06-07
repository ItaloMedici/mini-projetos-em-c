

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main(){
    while(!kbhit()){ //kbhit tem valor 0 para nada pressionado e valor != 0 se pressionarmos algo.
        printf("1\n");
        Sleep(300);
    }
    getch(); // para limpar o buffer de entrada
    fflush(stdin);
    /*
    while(!kbhit()){
        printf("2\n");
        Sleep(300);
    }
    
    getch();
    fflush(stdin);
    */
    return main();
}