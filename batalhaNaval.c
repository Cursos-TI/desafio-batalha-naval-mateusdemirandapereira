#include <stdio.h>


void preecherMatrix(int * matrix, int linha,int coluna ) {

	for (int i = 0; i < linha; i++) {

		for (int j = 0; j < coluna; j++) {
			*(matrix + i * coluna + j) = 0;
		}


	}


}


void adicionarNaviosVertical(int * matrix, int linha, int coluna) {
	int posicao = 3;

	for (int i = 0; i < linha; i++) {

		for (int j = 0; j < coluna; j++) {

			if (i >= 3) {
				if (j == 4 && posicao > 0) {

					*(matrix + i * coluna + j) = 3;
					posicao--;
				}

			}

		}


	}


}

void adicionarNaviosHorizontal(int * matrix, int linha, int coluna) {
	int posicao = 3;

	for (int i = 0; i < linha; i++) {

		for (int j = 0; j < coluna; j++) {

			if (i == 1) {
				if (j >= 3 && posicao > 0) {

					*(matrix + i * coluna + j) = 3;
					posicao--;
				}

			}

		}


	}


}



void mostrarMatrix(int * matrix, int linha ,int coluna ) {


	for (int i = 0; i < linha; i++) {

		for (int j = 0; j < coluna; j++) {
			printf("%d", *(matrix + i * coluna + j));
		}

		printf("\n");

	}


}


int main() {

	int  matrix[10][10];

	const int linha = sizeof(matrix)/ sizeof(matrix[0]);
	const int coluna = sizeof(matrix[0]) / sizeof(matrix[0][0]);

	preecherMatrix((int *) matrix, linha, coluna);

	adicionarNaviosVertical((int *)matrix, linha, coluna);

	adicionarNaviosHorizontal((int *)matrix, linha, coluna);

	mostrarMatrix((int *) matrix, linha, coluna);
	return 0;

}
