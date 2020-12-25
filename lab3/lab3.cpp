﻿// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
#define SIZE 5

void rand_Zap(int k, int* mat, int n) {
	srand(time(NULL) * k);
	printf("G%d \n", k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) {
				mat[i * n + j] = 0;
			}
			if (i < j) {
				mat[i * n + j] = rand() % 2;
				mat[j * n + i] = mat[i * n + j];
			}
		}
}

void print_G(int* mat, int n) {

	printf("  ");
	for (int i = 0; i < n; i++) {

		printf("%3d", i + 1);
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("%2d", i + 1);
		for (int j = 0; j < n; j++) {

			printf("%3d", mat[i * n + j]);
		}
		printf("\n");
	}
	printf("\n");


}

void copy(int(&mat1)[SIZE][SIZE], int(&mat2)[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			mat2[i][j] = mat1[i][j];
}

void otj(int(&constant)[SIZE][SIZE], int(&work)[SIZE][SIZE], int x1, int x2, int st) {
	int G[SIZE - 1][SIZE - 1], i, j, i1, j1;

	copy(constant, work);
	for (i = 0; i < SIZE; i++) {
		work[i][x1] = constant[i][x1] || constant[i][x2];
	}

	for (j = 0; j < SIZE; j++) {
		work[x1][j] = constant[x1][j] || constant[x2][j];
	}

	for (i = 0, i1 = x2 + 1; i < SIZE - 1; i++) {
		for (j = 0, j1 = x2; j < SIZE - 1; j++) {
			if (j >= x2)
				j1++;
			if (i < x2 && j < x2)
				G[i][j] = work[i][j];
			if (i < x2 && j >= x2)
				G[i][j] = work[i][j1];
			if (i >= x2 && j < x2)
				G[i][j] = work[i1][j];
			if (i >= x2 && j >= x2)
				G[i][j] = work[i1][j1];
		}
		if (i >= x2) i1++;
	}
	if (constant[x1][x2] == 1 && st == 0)
		G[x1][x1] = 1;
	else
		G[x1][x1] = 0;
	printf("Результат:\n");
	print_G(&G[0][0], SIZE - 1);
}

void ras(int(&constant)[SIZE][SIZE], int x) {
	int i, j, i1, mat[SIZE + 1][SIZE + 1];
	x--;

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			mat[i][j] = constant[i][j];
		}
	}
	for (i = 0; i < SIZE + 1; i++) {
		for (j = 0; j < SIZE + 1; j++) {
			if (i == 5 || j == 5) {
				mat[5][j] = 0;
				mat[j][5] = 0;
			}
		}
	}
	for (j = 0; j < SIZE; j++) {
		if (mat[x][j] == 1)
			if (j % 2 == 0) {
				mat[5][j] = 1;
				mat[j][5] = 1;
				mat[x][j] = 0;
				mat[j][x] = 0;
			}

	}
	mat[x][5] = 1;
	mat[5][x] = 1;
	printf("Результат расщепления\n\n");
	print_G(&mat[0][0], SIZE + 1);
}

void obed(int(&mat1)[SIZE][SIZE], int(&mat2)[SIZE][SIZE]) {
	int res[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			res[i][j] = mat1[i][j] || mat2[i][j];
		}
	printf("Результат объединения G1 и G2\n");
	print_G(&res[0][0], SIZE);
}
void perseh(int(&mat1)[SIZE][SIZE], int(&mat2)[SIZE][SIZE]) {
	int res[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			if (mat1[i][j] == 1 && mat2[i][j] == 1)
				res[i][j] = 1;
			else
				res[i][j] = 0;
		}
	printf("Результат пересечения G1 и G2\n");
	print_G(&res[0][0], SIZE);
}
void kolc_sum(int(&mat1)[SIZE][SIZE], int(&mat2)[SIZE][SIZE]) {
	int res[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			if ((mat1[i][j] == 1 && mat2[i][j] == 0) || (mat1[i][j] == 0 && mat2[i][j] == 1))
				res[i][j] = 1;
			else
				res[i][j] = 0;
		}
	printf("Результат кольцевой суммы G1 и G2\n");
	print_G(&res[0][0], SIZE);
}

int main() {
	int G1[SIZE][SIZE], G2[SIZE][SIZE], work[SIZE][SIZE], i, x1, x2, j, A[20][20];
	setlocale(LC_ALL, "Rus");
	rand_Zap(1, &G1[0][0], SIZE);
	print_G(&G1[0][0], SIZE);
	rand_Zap(2, &G2[0][0], SIZE);
	print_G(&G2[0][0], SIZE);

	printf("Отождествление 1 графа - Введите 2 вершины: ");
	scanf("%d%d", &x1, &x2);
	if (x1 > x2) {
		i = x1;
		x1 = x2;
		x2 = i;
	}

	if ((x1 >= 1) && (x2 <= SIZE)) {
		x1--; x2--;
		otj(G1, work, x1, x2, 0);
	}
	else
		printf("\nНет вершин(ы)\n");

	printf("Отождествление 2 графа - Введите 2 вершины: ");
	scanf("%d%d", &x1, &x2);
	if (x1 > x2) {
		i = x1;
		x1 = x2;
		x2 = i;
	}

	if ((x1 >= 1) && (x2 <= SIZE)) {
		x1--; x2--;
		otj(G2, work, x1, x2, 0);
	}
	else
		printf("\nНет вершин(ы)\n");

	printf("Стягивание ребра в 1 графе - Введите 2 вершины: ");
	scanf("%d%d", &x1, &x2);
	if (x1 > x2) {
		i = x1;
		x1 = x2;
		x2 = i;
	}
	if ((x1 >= 1) && (x2 <= SIZE)) {
		if (G1[x1 - 1][x2 - 1] == 1)
		{
			x1--; x2--;
			otj(G1, work, x1, x2, 1);
		}
		else printf("\nНет ребра\n");
	}
	else
		printf("\nНет вершин(ы)\n");

	printf("Стягивание ребра во 2 графе - Введите 2 вершины: ");
	scanf("%d%d", &x1, &x2);
	if (x1 > x2) {
		i = x1;
		x1 = x2;
		x2 = i;
	}
	if ((x1 >= 1) && (x2 <= SIZE)) {
		if (G2[x1 - 1][x2 - 1] == 1)
		{
			x1--; x2--;
			otj(G2, work, x1, x2, 1);
		}
		else printf("\nНет ребра\n");
	}
	else
		printf("\nНет вершин(ы)\n");

	printf("Введите вершину для расщепления в 1 графе: ");
	scanf("%d", &x1);
	ras(G1, x1);
	getchar();

	printf("Введите вершину для расщепления во 2 графе: ");
	scanf("%d", &x1);
	ras(G2, x1);
	getchar();

	obed(G1, G2);
	getchar();

	perseh(G1, G2);
	getchar();

	kolc_sum(G1, G2);
	getchar();
}