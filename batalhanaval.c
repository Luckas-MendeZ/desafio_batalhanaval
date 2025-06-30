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

// Função que cria a matriz da habilidade "Cone"
void habilidade_cone(int cone[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 2) {
                cone[i][j] = 1;
            } else if (i == 1 && (j >= 1 && j <= 3)) {
                cone[i][j] = 1;
            } else if (i == 2) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função que cria a matriz da habilidade "Cruz"
void habilidade_cruz(int cruz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função que cria a matriz da habilidade "Octaedro"
void habilidade_octaedro(int octa[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int di = i - 2;
            int dj = j - 2;
            if ((di < 0 ? -di : di) + (dj < 0 ? -dj : dj) <= 2) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }
}

// Função que aplica a matriz da habilidade sobre o tabuleiro
void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int origem_linha, int origem_coluna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Calcula a posição no tabuleiro
            int linha_tab = origem_linha + (i - 2);
            int coluna_tab = origem_coluna + (j - 2);

            // Verifica se está dentro dos limites
            if (linha_tab >= 0 && linha_tab < TAM && coluna_tab >= 0 && coluna_tab < TAM) {
                // Aplica o efeito se a habilidade marcar 1 e a posição não for navio
                if (habilidade[i][j] == 1 && tabuleiro[linha_tab][coluna_tab] == AGUA) {
                    tabuleiro[linha_tab][coluna_tab] = 5;
                }
            }
        }
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
    int linha = 7;
    int coluna = 0;

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
        // Matrizes de habilidades
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // Gerar formas
    habilidade_cone(cone);
    habilidade_cruz(cruz);
    habilidade_octaedro(octaedro);

    // Aplicar habilidades no tabuleiro
    aplicar_habilidade(mar, cone, 2, 2);       // Cone no centro (2,2)
    aplicar_habilidade(mar, cruz, 5, 6);       // Cruz no centro (5,6)
    aplicar_habilidade(mar, octaedro, 7, 2);   // Octaedro no centro (7,2)
    
    imprimir_tabuleiro(mar);

    return 0;
}