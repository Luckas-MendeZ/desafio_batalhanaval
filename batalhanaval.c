#include <stdio.h>
#define TAM 10 //tamanho do tabuleiro 
#define NAVIO 3 // tamanho do navio
#define OCUPADO 3 // valor para marcar os navios para evitar sobreposição
#define AGUA 0 // valor que representa a agua

// Função para imprimir o tambuleiro no console
void imprimir_tabuleiro(int mar [TAM][TAM]){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", mar[i][j]); // Imprime valor da célula com espaço para alinhamento
        }
        printf("\n"); // Quebra de linha ao final de cada linha do tabuleiro
    }
}
int main(){
    // Tabuleiro com alguns navios já posicionados ( Navio horizontal linha 1) ( Navio vertical coluna 7)
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

    // Coordenadas iniciais para o navio diagonal principal
    int linha = 4;
    int coluna = 2;

    // Verifica se o navio cabe no tabuleiro na diagonal principal e se as posições estão livres
    if (linha + 2 < TAM && coluna + 2 < TAM)
    {
        if (mar[linha][coluna] == AGUA &&
        mar[linha+1][coluna+1] == AGUA &&
        mar[linha+2][coluna+2] == AGUA)
    {
        // Marca as posições do navio
        mar[linha][coluna] = OCUPADO;
        mar[linha+1][coluna+1] = OCUPADO;
        mar[linha+2][coluna+2] = OCUPADO;
    }
    }

    int linha2 = 0;
    int coluna2 = 9;
    if (linha2 + 2 < TAM && coluna2 - 2 >= 0)
    {
        if (mar[linha2][coluna2] == AGUA &&
        mar[linha2+1][coluna2-1] == AGUA &&
        mar[linha2+2][coluna2-2] == AGUA)

    {  
        mar[linha2][coluna2] = OCUPADO;
        mar[linha2+1][coluna2-1] = OCUPADO;
        mar[linha2+2][coluna2-2] = OCUPADO;
    }
    }
    
    imprimir_tabuleiro(mar);
    return 0;
}