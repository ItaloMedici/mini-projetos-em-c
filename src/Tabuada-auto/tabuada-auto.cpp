/**/

#include<stdlib.h>
#include<stdio.h>

void tabuada(float x){
    for(float i=1;i<11;i++){
        printf("%.2f x %2.f = %.2f\n", x, i, x*i);
    }
}

int main () {
    float num;
    printf("Digite um numero para tabuada: ");
    scanf("%f", &num);

    tabuada(num);

    system("pause");
    return 0;
}