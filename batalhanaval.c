#include <stdio.h>
#define TAM 10 //tamanho do tabuleiro 
#define NAVIO 3 // tamanho do navio
#define OCUPADO 3 // valor para marcar os navios para evitar sobreposição
#define AGUA 0 // valor que representa a agua

int main(){
    int mar [10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,3,3,3,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,3,0,0},
        {0,0,0,0,0,0,0,3,0,0},
        {0,0,0,0,0,0,0,3,0,0}
    };

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", mar[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}