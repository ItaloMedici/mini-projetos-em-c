#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int scoreX = 0, scoreO = 0;

void score(int x, int y){
    printf("\tX: %d vs O: %d\n\n", x,y);
}

void tabuleiro (char x[3][3]){
    system("cls"); 
    score(scoreX, scoreO);
    
    printf("\t %c | %c | %c \n", x[0][0], x[0][1], x[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", x[1][0], x[1][1], x[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", x[2][0], x[2][1], x[2][2]);

    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char jogo[3][3] {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}, resp;
    int i, j, coluna, linha, jogadas = 0, jogador = 0;
    bool venX = false, venO = false;

    do{
        jogadas = 1;
        jogador = 0;

        for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    jogo[i][j] = ' ';
                }
            }
            
        do {
            tabuleiro(jogo);    

            printf("Player: %c", jogador%2==0?'X':'O');
            printf("\nDigite a linha: ");
            scanf("%d", &linha);
            printf("Digite a coluna: ");
            scanf("%d", &coluna);

            if (linha < 1 || coluna < 1 || linha > 3 || coluna > 3){
                coluna = 0;
                linha = 0;
            }

            else if (jogo[linha - 1][coluna - 1] != ' '){
                coluna = 0;
                linha = 0;
            }

            else {
                if (jogador % 2 == 0){
                    jogo[linha - 1][coluna - 1 ] = 'X';
                }

                else {
                    jogo[linha - 1][coluna - 1] = 'O';
                }

                jogador ++;
                jogadas ++;
            }

            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X') {venX = true; jogadas = 12; }
                    if(jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') {venX = true; jogadas = 12; }
                    if(jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') {venX = true; jogadas = 12; }
                    if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') {venX = true; jogadas = 12; }
                    if(jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') {venX = true; jogadas = 12; }
                    if(jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') {venX = true; jogadas = 12; }
                    if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') {venX = true; jogadas = 12; }
                    if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X') {venX = true; jogadas = 12; }
                    
                    if(jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O') {venO = true; jogadas = 12; }
                    if(jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') {venO = true; jogadas = 12; }
                    if(jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O') {venO = true; jogadas = 12; }
                    if(jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') {venO = true; jogadas = 12; }
                    if(jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') {venO = true; jogadas = 12; }
                    if(jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O') {venO = true; jogadas = 12; }
                    if(jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') {venO = true; jogadas = 12; }
                    if(jogo[0][2] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O') {venO = true; jogadas = 12; }
                }
            }            
       
        } while(jogadas <= 9);

        tabuleiro(jogo);

        if (venX){
            printf("\n\tJogador X venceu!");
            scoreX++;
        }

        if (venO){
            printf("\n\tJogador O venceu!");
            scoreO++;
        }


        if (jogadas == 10){
            printf("\n\tEmpate!");
        }
    
        printf("\n\nQuer jogar novamente? [s - sim / n - não] ");
        scanf("%s", &resp);
        
    }while (resp == 's') ;   

    printf("\n\n\n");
    system("pause");
    return 0;
}