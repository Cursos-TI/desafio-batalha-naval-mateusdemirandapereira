#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

void preencherMatrix(int *matrix, int linha, int coluna) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            *(matrix + i * coluna + j) = 0;
        }
    }
}

int podePosicionarHorizontal(int *matrix, int linha, int coluna, int l, int c) {
    if (c + TAM_NAVIO > coluna) return 0;
    for (int j = 0; j < TAM_NAVIO; j++) {
        if (*(matrix + l * coluna + (c + j)) != 0) return 0;
    }
    return 1;
}

int podePosicionarVertical(int *matrix, int linha, int coluna, int l, int c) {
    if (l + TAM_NAVIO > linha) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (*(matrix + (l + i) * coluna + c) != 0) return 0;
    }
    return 1;
}

int podePosicionarDiagonalPrincipal(int *matrix, int linha, int coluna, int l, int c) {
    if (l + TAM_NAVIO > linha || c + TAM_NAVIO > coluna) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (*(matrix + (l + i) * coluna + (c + i)) != 0) return 0;
    }
    return 1;
}

int podePosicionarDiagonalSecundaria(int *matrix, int linha, int coluna, int l, int c) {
    if (l + TAM_NAVIO > linha || c - (TAM_NAVIO - 1) < 0) return 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (*(matrix + (l + i) * coluna + (c - i)) != 0) return 0;
    }
    return 1;
}

void posicionarHorizontal(int *matrix, int linha, int coluna, int l, int c) {
    if (podePosicionarHorizontal(matrix, linha, coluna, l, c)) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            *(matrix + l * coluna + (c + j)) = 3;
        }
    } else {
        printf("Erro: navio horizontal não pôde ser posicionado.\n");
    }
}

void posicionarVertical(int *matrix, int linha, int coluna, int l, int c) {
    if (podePosicionarVertical(matrix, linha, coluna, l, c)) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            *(matrix + (l + i) * coluna + c) = 3;
        }
    } else {
        printf("Erro: navio vertical não pôde ser posicionado.\n");
    }
}

void posicionarDiagonalPrincipal(int *matrix, int linha, int coluna, int l, int c) {
    if (podePosicionarDiagonalPrincipal(matrix, linha, coluna, l, c)) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            *(matrix + (l + i) * coluna + (c + i)) = 3;
        }
    } else {
        printf("Erro: navio diagonal principal não pôde ser posicionado.\n");
    }
}

void posicionarDiagonalSecundaria(int *matrix, int linha, int coluna, int l, int c) {
    if (podePosicionarDiagonalSecundaria(matrix, linha, coluna, l, c)) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            *(matrix + (l + i) * coluna + (c - i)) = 3;
        }
    } else {
        printf("Erro: navio diagonal secundária não pôde ser posicionado.\n");
    }
}

void mostrarMatrix(int *matrix, int linha, int coluna) {
    printf("   ");
    for (int j = 0; j < coluna; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < linha; i++) {
        printf("%2d ", i);
        for (int j = 0; j < coluna; j++) {
            printf("%2d ", *(matrix + i * coluna + j));
        }
        printf("\n");
    }
}

int main() {
    int matrix[TAM][TAM];
    const int linha = TAM, coluna = TAM;

    preencherMatrix((int *)matrix, linha, coluna);

    // Posições fixas e válidas (sem sobreposição)
    posicionarHorizontal((int *)matrix, linha, coluna, 0, 0);       // Linha 0, colunas 0-2
    posicionarVertical((int *)matrix, linha, coluna, 2, 5);         // Coluna 5, linhas 2-4
    posicionarDiagonalPrincipal((int *)matrix, linha, coluna, 6, 0); // (6,0), (7,1), (8,2)
    posicionarDiagonalSecundaria((int *)matrix, linha, coluna, 6, 9); // (6,9), (7,8), (8,7)

    mostrarMatrix((int *)matrix, linha, coluna);

    return 0;
}
