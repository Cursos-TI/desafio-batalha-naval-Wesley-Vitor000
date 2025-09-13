#include <stdio.h>

/* ---------------------------------------------------------------------
   BATALHA NAVAL – MateCheck
   Wesley Vitor – solução compacta com 3 níveis (Novato, Aventureiro, Mestre)
   Obs.: valores inseridos “no código”, como o enunciado pede.
------------------------------------------------------------------------*/

// ---- utilitário simples pra imprimir matriz int NxM
void imprime_matriz(const int *m, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", *((m + i*colunas) + j));
        }
        printf("\n");
    }
}

/* ========================= NÍVEL NOVATO ============================== */
/* Dois navios em um tabuleiro 5x5: um horizontal e um vertical.
   Exibe as coordenadas (linha, coluna) de cada parte dos navios. */
void nivel_novato(void) {
    int mar[5][5] = {0};

    // Navio horizontal (tamanho 3) – linha 2, colunas 1..3
    int h_lin = 2, h_ini = 1, h_tam = 3;
    for (int c = h_ini; c < h_ini + h_tam; c++) mar[h_lin][c] = 3;

    // Navio vertical (tamanho 3) – coluna 4, linhas 0..2
    int v_col = 4, v_ini = 0, v_tam = 3;
    for (int l = v_ini; l < v_ini + v_tam; l++) mar[l][v_col] = 3;

    printf("=== NÍVEL NOVATO ===\n");
    printf("Coordenadas do navio horizontal (valor 3):\n");
    for (int c = h_ini; c < h_ini + h_tam; c++)
        printf("(linha=%d, coluna=%d)\n", h_lin, c);

    printf("Coordenadas do navio vertical (valor 3):\n");
    for (int l = v_ini; l < v_ini + v_tam; l++)
        printf("(linha=%d, coluna=%d)\n", l, v_col);

    // (opcional) mostra o 5x5 só pra ficar claro visualmente
    printf("\nTabuleiro 5x5 (0=livre, 3=navio):\n");
    imprime_matriz(&mar[0][0], 5, 5);
    printf("\n");
}

/* ======================= NÍVEL AVENTUREIRO =========================== */
/* Tabuleiro 10x10, quatro navios, incluindo dois na diagonal.
   Exibe o tabuleiro completo (0 livre / 3 ocupado).                   */

static void coloca_horizontal(int m[10][10], int lin, int col_ini, int tam) {
    for (int c = col_ini; c < col_ini + tam; c++) m[lin][c] = 3;
}
static void coloca_vertical(int m[10][10], int col, int lin_ini, int tam) {
    for (int l = lin_ini; l < lin_ini + tam; l++) m[l][col] = 3;
}
static void coloca_diag_dr(int m[10][10], int lin_ini, int col_ini, int tam) { // diagonal “descendo à direita”
    for (int k = 0; k < tam; k++) m[lin_ini + k][col_ini + k] = 3;
}
static void coloca_diag_ur(int m[10][10], int lin_ini, int col_ini, int tam) { // diagonal “subindo à direita”
    for (int k = 0; k < tam; k++) m[lin_ini - k][col_ini + k] = 3;
}

void nivel_aventureiro(void) {
    int mar[10][10] = {0};

    // 4 navios (dois “retos” e dois diagonais)
    coloca_horizontal(mar, 1, 2, 4);       // linha 1, colunas 2..5
    coloca_vertical(mar, 7, 4, 3);         // col 7, linhas 4..6
    coloca_diag_dr(mar, 0, 0, 3);          // (0,0)->(2,2)
    coloca_diag_ur(mar, 6, 1, 4);          // (6,1)->(3,4) subindo à direita

    printf("=== NÍVEL AVENTUREIRO ===\n");
    printf("Tabuleiro 10x10 (0=livre, 3=navio):\n");
    imprime_matriz(&mar[0][0], 10, 10);
    printf("\n");
}

/* ========================= NÍVEL MESTRE ============================== */
/* Habilidades (matrizes 0/1): cone, cruz, octaedro – exibidas como
   “áreas atingidas” (1) vs “não atingidas” (0).                        */
void nivel_mestre(void) {
    // máscaras 5x5 (iguais ao modelo do enunciado)
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    int octaedro[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    int cruz[5][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    printf("=== NÍVEL MESTRE ===\n");
    printf("Habilidade: CONE (1=atingido)\n");
    imprime_matriz(&cone[0][0], 5, 5);
    printf("\nHabilidade: OCTAEDRO (1=atingido)\n");
    imprime_matriz(&octaedro[0][0], 5, 5);
    printf("\nHabilidade: CRUZ (1=atingido)\n");
    imprime_matriz(&cruz[0][0], 5, 5);
    printf("\n");
}

/* ============================== MAIN ================================= */
int main(void) {
    nivel_novato();
    nivel_aventureiro();
    nivel_mestre();
    return 0;
}
