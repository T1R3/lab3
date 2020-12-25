// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
#include <queue>
using namespace std;

void NewGraph(int** G, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				G[i][j] = 0;
			}
			if (i < j) {
				G[i][j] = rand() % 2;
				G[j][i] = G[i][j];
			}
		}
	}
}

void print_G(int** G, int n) {

	printf("  ");
	for (int i = 0; i < n; i++) {

		printf("%3d", i + 1);
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++) {

			printf("%3d", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}

void otojd(int v1, int v2, int** G, int n) {
	int x1, x2;
	int** mat;
	mat = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)malloc(n * sizeof(int));
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = G[i][j];
		}
	}

	if (v1 > v2) {
		x1 = v1 - 1;
		x2 = v2 - 1;
	}
	else {
		x1 = v2 - 1;
		x2 = v1 - 1;
	}

	for (int i = 0; i < n; i++) {
		if (mat[x1][i] == 1)
			mat[x2][i] = 1;

		if (mat[i][x1] == 1)
			mat[i][x2] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = x1; j < n - 1; j++) {
			mat[i][j] = mat[i][j + 1];
		}
	}

	for (int i = x1; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = mat[i + 1][j];
		}
	}
	print_G(mat, n - 1);
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}

void obed(int**G1, int** G2, int n) {
	int** mat1, ** mat2, **res;
	mat1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat1[i] = (int*)malloc(n * sizeof(int));
	}
	mat2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat2[i] = (int*)malloc(n * sizeof(int));
	}
	res = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		res[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat1[i][j] = G1[i][j];
			mat2[i][j] = G2[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = mat1[i][j] || mat2[i][j];
		}
	}
	printf("Результат объединения графов: \n");
	print_G(res, n);
	for (int i = 0; i < n; i++) {
		free(mat1[i]);
	}
	free(mat1);
	for (int i = 0; i < n; i++) {
		free(mat2[i]);
	}
	free(mat2);
	for (int i = 0; i < n; i++) {
		free(res[i]);
	}
	free(res);
}

void perese4(int** G1, int** G2, int n) {
	int** mat1, ** mat2, ** res;
	mat1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat1[i] = (int*)malloc(n * sizeof(int));
	}
	mat2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat2[i] = (int*)malloc(n * sizeof(int));
	}
	res = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		res[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat1[i][j] = G1[i][j];
			mat2[i][j] = G2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat1[i][j] == 1 && mat2[i][j] == 1) {
				res[i][j] = 1;
		}
			else {
				res[i][j] = 0;
			}
		}
	}
	printf("Результат пересечения графов: \n");
	print_G(res, n);
	for (int i = 0; i < n; i++) {
		free(mat1[i]);
	}
	free(mat1);
	for (int i = 0; i < n; i++) {
		free(mat2[i]);
	}
	free(mat2);
	for (int i = 0; i < n; i++) {
		free(res[i]);
	}
	free(res);
}

void kolcsumm(int** G1, int** G2, int n) {
	int** mat1, ** mat2, ** res;
	mat1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat1[i] = (int*)malloc(n * sizeof(int));
	}
	mat2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat2[i] = (int*)malloc(n * sizeof(int));
	}
	res = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		res[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat1[i][j] = G1[i][j];
			mat2[i][j] = G2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((mat1[i][j] == 1 && mat2[i][j] == 1) || (mat1[i][j] == 0 && mat2[i][j] == 0)) {
				res[i][j] = 0;
			}
			if ((mat1[i][j] == 1 && mat2[i][j] == 0) || (mat1[i][j] == 0 && mat2[i][j] == 1)) {
				res[i][j] = 1;
			}
		}
	}
	printf("Кольцевая сумма графов: \n");
	print_G(res, n);

	for (int i = 0; i < n; i++) {
		free(mat1[i]);
	}
	free(mat1);
	for (int i = 0; i < n; i++) {
		free(mat2[i]);
	}
	free(mat2);
	for (int i = 0; i < n; i++) {
		free(res[i]);
	}
	free(res);
}

int main() {
	int** G1 = NULL, ** G2 = NULL;;
	int x1 = NULL, x2 = NULL;
	int n;
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	printf("Введите размер графа: ");
	scanf("%d", &n);
	G1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		G1[i] = (int*)malloc(n * sizeof(int));
	}
	G2 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		G2[i] = (int*)malloc(n * sizeof(int));
	}
	
	NewGraph(G1, n);
	print_G(G1, n);
	NewGraph(G2, n);
	print_G(G2, n);

	printf("Введите 2 вершины 1 графа для отождествления: ");
	scanf("%d %d", &x1, &x2);
	otojd(x1, x2, G1, n);

	printf("Введите 2 вершины 2 графа для отождествления: ");
	scanf("%d %d", &x1, &x2);
	otojd(x1, x2, G2, n);

	printf("\nВВедите 2  смежные вершины в матрице 1 для стягивания: ");
	for (;;) {
		scanf_s("%d", &x1);
		scanf_s("%d", &x2);
		if (G1[x1 - 1][x2 - 1] == 1)
			break;
		else
			printf("Ошибка, введите заново: ");
	}
	otojd(x1, x2, G1, n);
	
	printf("\nВведите 2 смежные вершины в матрице 2 для стягивания: ");
	for (;;) {
		scanf_s("%d", &x1);
		scanf_s("%d", &x2);
		if (G2[x1 - 1][x2 - 1] == 1)
			break;
		else
			printf("Ошибка, введите заново: ");
	}
	otojd(x1, x2, G2, n);

	obed(G1, G2, n);
	perese4(G1, G2, n);
	kolcsumm(G1, G2, n);

	for (int i = 0; i < n; i++) {
		free(G1[i]);
	}
	free(G1);
	for (int i = 0; i < n; i++) {
		free(G2[i]);
	}
	free(G2);
}