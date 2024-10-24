#include <stdio.h>
#include <windows.h>

//void Task1() {
//
//	printf("Task1() START\n");
//
//	int N;
//	int M;
//
//	printf("number of rows N = ");
//	scanf_s("%d", &N);
//
//	printf("number of columns M = ");
//	scanf_s("%d", &M);
//
//	int i = 1;
//	int j = 1;
//
//	while (i <= N) {
//		while (j <= M) {
//			printf("%d ", i * 10 + j);
//			j++;
//		}
//		printf("\n");
//		i++;
//		j = 1;
//	}
//	
//	printf("Task1() FINISH");
//}

void Task1() {

	printf("Task1() START\n");

	int N;
	int M;

	printf("number of rows N = ");
	scanf_s("%d", &N);

	printf("number of columns M = ");
	scanf_s("%d", &M);

	int i = 1;
	
	do {
		int j = 1;

		do {
			printf("%3d ", i * 10 + j);
			j++;
		} while (j <= M);

		printf("\n");
		i++;

	} while (i <= N);

	printf("Task1() FINISH");
}

//void Task2() {
//
//	printf("Task1() START\n");
//
//	int i = 1;
//	int j = 1;
//
//	do {
//
//		int A = i;
//
//		do {
//			printf("%3d ", A);
//			A = A + j;
//		} while (A <= i * 10);
//
//		printf("\n");
//		j++;
//		i++;
//	} while (j <= 10);
//
//	printf("Task1() FINISH");
//}

void Task2() {

	printf("Task2() START\n");

	int i = 1;

	do {

		int j = 1;

		do {
			printf("%3d ", i * j);
			j++;
		} while (j <= 10);

		printf("\n");
		i++;

	} while (i <= 10);

	printf("Task2() FINISH");
}

void Task3() {

	printf("Task3() START\n");

	int N;

	printf("������� ������ ����� � ������� = ");
	scanf_s("%d", &N);

	int i = 1;

	do {
		int j = 0;
		do {
			printf("%d ", i - j);
			j++;
		} while (i - j >= 1);
		printf("\n");
		i++;
	} while (i <= N);
	printf("Task2() FINISH");
}

void Task4() {

	int N;
	printf("������� ������ ����� = ");
	scanf_s("%d", &N);

	int first_number = 1;

	int counter = N;

		do {
			int gap = 0;
			do {
				printf("  ");
				gap++;
			} while (gap < counter);

			int summand = N - counter;
			do {
				printf("%2d\t", first_number + summand);
				summand--;
			} while (summand >= 0);
			printf("\n");
			counter--;
		} while (counter > 1);
	
		do {
		int gap = 0;
			do {
				printf("  ");
				gap++;
			} while (gap < counter);

			int summand = N - counter;
			do {
				printf("%2d", first_number + summand);
				summand--;
			} while (summand >= 0);
			printf("\n");
			counter++;
		} while (counter <= N);
	}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;

	do {

		printf("\n\n�������� ������ ��� ��������:");
		printf("\n1: ������ 1 (i * 10 + j)");
		printf("\n2: ������ 2 ������� ��������");
		printf("\n3: ������ 3 ������� �� ���������");
		printf("\n4: ������ 4 ���� �� ����� �� ���������");

		printf("\n\n0: ����� �� ���������\n");
		scanf_s("%d", &n);

		switch (n)
		{
			case 1:
				Task1();
				break;
			case 2:
				Task2();
				break;
			case 3:
				Task3();
				break;
			case 4:
				Task4();
				break;
			default:
				break;
		}
	} while (n != 0);
	return 0;
}