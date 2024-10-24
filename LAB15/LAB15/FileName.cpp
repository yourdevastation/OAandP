#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define MAX_N 10
#define MAX_M 10

int arr[MAX_N][MAX_M] = {};

int n = 3;
int m = 4;

void print() {
	printf("���������� �������\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void fillIx10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}
void fillZero() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}
void fillRand() {
	srand(time(NULL));
	n = rand() % 10;
	m = rand() % 10;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 1)
				arr[i][j] *= 10;
		}
	}
}
void down10() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 10 == 0)
				arr[i][j] /= 10;
		}
	}
}
void input() {
	printf("\n������� ���������� ����� = ");
	scanf_s("%d", &n);

	printf("\n������� ���������� �������� = ");
	scanf_s("%d", &m);

	for (int i = 0; i < n; i++) {
		printf("������� %d ������ ������� ", i + 1);
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
}
void save() {
	FILE* fout;
	fout = fopen("c:\\test_saves\\arr1.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}

	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);
}
void load() {
	FILE* fin;
	fin = fopen("c:\\test_saves\\arr1.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	fscanf(fin, "%d ", &n);
	fscanf(fin, "%d\n", &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d ", &arr[i][j]);
		}
	}
	fclose(fin);
}
void deleteRow(int delrow) {
	for (int i = delrow; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}
void duplicateColumn(int dupcol) {
	for (int i = 0; i < n; i++) {
		for (int j = m; j > dupcol; j--) {
			arr[i][j] = arr[i][j - 1];
		}
	}
	for (int i = 0, j = 0; i < n; i++, j++) {
		if (j = dupcol) 
			arr[i][j + 1] = arr[i][j];
	}
	m++;
}

typedef struct element {
	int indexMax;
	int columnMax;
	int max;
};
element maxElement;
void findMax() {
	maxElement.max = arr[0][0];
	maxElement.indexMax = 0;
	maxElement.columnMax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > maxElement.max) {
				maxElement.max = arr[i][j];
				maxElement.indexMax = i;
				maxElement.columnMax = j;
			}
		}
	}
	printf("%d ������������ ������� %d ������ %d �������\n\n",
		maxElement.max, maxElement.indexMax, maxElement.columnMax);
}
int findMaxInColumn(int col) {
	int max = arr[0][col];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][col] > max) {
				max = arr[i][col];
			}
		}
	}
	return max;
}
void changeEvensUnderMaxToMaxElInColomn() {
	findMax();
	for (int i = maxElement.indexMax + 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int max = findMaxInColumn(j);
				if (arr[i][j] % 2 == 0 && arr[i][j] != 0) {
					arr[i][j] = max;
				}
			}
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int command;
	do {
		
		print();
		printf("=======================================");
		printf("\n�������� ������ ��� ��������:");
		printf("\n1: ��������� ���������� i * 10 + j");
		printf("\n2: ��������� ������");
		printf("\n3: ��������� ���������� ����������");
		printf("\n4: ��� �������� ��������� � 10 ���");
		printf("\n5: ��� ������� 10 ��������� � 10 ���");
		printf("\n6: ������ ������ � ����������");
		printf("\n7: ��������� ������ � �����");
		printf("\n8: ��������� ������ �� �����");
		printf("\n9: ������� �������� ������");
		printf("\n10: �������������� �������� �������");
		printf("\n11: ����� ������������ �������");
		printf("\n12: ��� �������� �������, ������� �����\n"
				"\t�� ������������� �������� �������,\n"
				"\t�������� �� ������������ ������� �������,\n"
				"\t� ������� ��� �����������\n");

		printf("\n0: ����� �� ���������");
		printf("\n��������� �������� >>>>> ");
		scanf_s("%d", &command);

		switch (command) {
		case 1:
			fillIx10();
			break;
		case 2:
			fillZero();
			break;
		case 3:
			fillRand();
			break;
		case 4:
			oddsX10();
			break;
		case 5:
			down10();
			break;
		case 6: 
			input();
			break;
		case 7:
			save();
			break;
		case 8:
			load();
			break;
		case 9:
		{
			int num;
			printf("������� ����� ������, ������� ����� ������� = ");
			scanf_s("%d", &num);
			deleteRow(num);
		}
			break;
		case 10:
		{
			int num;
			printf("������� ����� �������, ������� ����� �������������� = ");
			scanf_s("%d", &num);
			duplicateColumn(num);
		}
			break;
		case 11: 
			findMax();
			break;
		case 12:
			changeEvensUnderMaxToMaxElInColomn();
			break;
		default:
			break;
		}
	} while (command != 0);
}