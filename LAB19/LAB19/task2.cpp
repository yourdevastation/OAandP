#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int* pa;
int n;

void Load() {
	FILE* fin = fopen("c:\\Users\\socea\\source\\repos\\LAB19\\in2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}
	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}
	fclose(fin);
}

void SaveResult() {
	float sa = 0;
	float s = 0;
	for (int i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	int m = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			m++;
		}
	}
	FILE* fout = fopen("c:\\Users\\socea\\source\\repos\\LAB19\\out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		if (pa[i] > sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Hello! It is Task2!\n");

	Load();
	SaveResult();

	free(pa);
}
