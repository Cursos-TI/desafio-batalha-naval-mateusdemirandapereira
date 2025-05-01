#include <stdio.h>
#include <stdlib.h>

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
    }
}

void posicionarVertical(int *matrix, int linha, int coluna, int l, int c) {
    if (podePosicionarVertical(matrix, linha, coluna, l, c)) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            *(matrix + (l + i) * coluna + c) = 3;
        }
    }
}

void posicionarDiagonalPrincipal(int *matrix, int linha, int coluna, int l, int c) {
    if (podePosicionarDiagonalPrincipal(matrix, linha, coluna, l, c)) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            *(matrix + (l + i) * coluna + (c + i)) = 3;
        }
    }
}

void posicionarDiagonalSecundaria(int *matrix, int linha, int coluna, int l, int c) {
    if (podePosicionarDiagonalSecundaria(matrix, linha, coluna, l, c)) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            *(matrix + (l + i) * coluna + (c - i)) = 3;
        }
    }
}

void aplicarHabilidade(int *matrix, int linha, int coluna, int centro_l, int centro_c, int tipo) {
    int tam_hab = 5;
    int offset = tam_hab / 2;

    for (int i = 0; i < tam_hab; i++) {
        for (int j = 0; j < tam_hab; j++) {
            int r = centro_l - offset + i;
            int c = centro_c - offset + j;

            if (r >= 0 && r < linha && c >= 0 && c < coluna) {
                int aplicar = 0;
                switch (tipo) {
                    case 1: // Cone
                        if (i >= j - offset && i >= offset - j) aplicar = 1;
                        break;
                    case 2: // Cruz
                        if (i == offset || j == offset) aplicar = 1;
                        break;
                    case 3: // Octaedro
                        if (abs(i - offset) + abs(j - offset) <= offset) aplicar = 1;
                        break;
                }
                if (aplicar && *(matrix + r * coluna + c) == 0) {
                    *(matrix + r * coluna + c) = 5;
                }
            }
        }
    }
}

void mostrarMatrix(int *matrix, int linha, int coluna) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%d ", *(matrix + i * coluna + j));
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int matrix[TAM][TAM];
    const int linha = TAM, coluna = TAM;

    preencherMatrix((int *)matrix, linha, coluna);

    // Posicionar navios
    posicionarHorizontal((int *)matrix, linha, coluna, 0, 2);
    posicionarVertical((int *)matrix, linha, coluna, 2, 5);
    posicionarDiagonalPrincipal((int *)matrix, linha, coluna, 6, 0);
    posicionarDiagonalSecundaria((int *)matrix, linha, coluna, 6, 9);

    // Aplicar habilidades
    aplicarHabilidade((int *)matrix, linha, coluna, 2, 2, 1); // Cone
    aplicarHabilidade((int *)matrix, linha, coluna, 4, 5, 2); // Cruz
    aplicarHabilidade((int *)matrix, linha, coluna, 7, 5, 3); // Octaedro

    // Mostrar tabuleiro final
    mostrarMatrix((int *)matrix, linha, coluna);

    return 0;
}
