#include <stdio.h>
#include <Windows.h>

void print1_10() {
	int a = 1;
	do {
		printf("%d ", a);
		a++;
	} while (a <= 10);
}

void print10_1() {
	int a = 10;
	do {
		printf("%d ", a);
		a -= 1;
	} while (a >= 1);
}

void print5odds() {
	int a = 1;
	int i = 1;
	do {
		printf("%d ", a);
		a += 2;
		i += 1;
	} while (i <= 5);
}

void print100_10() {
	
	int a = 100;
	while (a >= 10) {
		printf("%d ", a);
		a -= 10;
	}
}

void print1000_100() {

	int a = 1000;
	while (a >= 100) {
		printf("%d ", a);
		a -= 100;
	}
}

float interest_rate(float R) {
	R = 1 + R / 100;
	return R;
}

int bank_account(int s, float R) {
	s = s * interest_rate(R);
	return s;
}

void print1000_0_25() {
	int a = 1000;
	while (a >= 0) {
		printf("%d ", a);
		a -= 25;
	}
}

int factorial(int N) {
	
	int f = 1;
	int counter = 1;
	while (counter <= N) {
		printf("%d ", f);
		counter++;
		f *= counter;
	}
	return 0;
}

int Fibonacci(int N) {

	int F = 1;
	int a = 1;
	int b = 0;
	int counter = 1;
	while (counter <= N) {
		printf("%d ", F);
		F = a + b;
		b = a;
		a = F;
		counter++;
	}
	return 0;
} 

int prime_factors(int N) {

	while (N % 2 == 0) {
		printf("2 * ");
		N /= 2;
	}
	while (N % 3 == 0) {
		printf("3 * ");
		N /= 3;
	}
	while (N % 5 == 0) {
		printf("5 * ");
		N /= 5;
	}
	while (N % 7 == 0) {
		printf("7 * ");
		N /= 7;
	}
	if (N != 1) printf("%d", N);
	else printf("1");

	return 0;
}

int factorial_GOTO(int N) {

	int f = 1;
	int counter = 1;
	label_while:
	if (counter <= N) {
		printf("%d ", f);
		counter++;
		f *= counter;
		goto label_while;
	}
	return 0;
}

int prime_factors_GOTO(int N) {

	label_while1:
	if (N % 2 == 0) {
		printf("2 * ");
		N /= 2;
		goto label_while1;
	}

	label_while2:
	if (N % 3 == 0) {
		printf("3 * ");
		N /= 3;
		goto label_while2;
	} 

	label_while3:
	while (N % 5 == 0) {
		printf("5 * ");
		N /= 5;
		goto label_while3;
	} 

	label_while4:
	if (N % 7 == 0) {
		printf("7 * ");
		N /= 7;
		goto label_while4;
	}

	if (N != 1) {
		printf("%d", N);
		goto label_end;
	}
	printf("1");
	label_end:
	return 0;
}


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	do {
		printf("\n\n�������� ������ ��� ��������:\n");
		printf("1: ������� ����� �� 1 �� 10\n");
		printf("2: ������� ����� �� 10 �� 1\n");
		printf("3: ������� ������ 5 �������� �����\n");
		printf("11: ������� ����� �� 100 �� 10 � ����� 10 ����� WHILE\n");
		printf("12: ������� ����� �� 1000 �� 100 � ����� 100 ����� WHILE\n");
		printf("13: ������� ��������� �����\n");
		printf("20: ������� ����� �� 1000 �� 0 � ����� 25\n");
		printf("21: ������� N ������ �����������\n");
		printf("22: ������� N ����� ���������\n");
		printf("23: ���������� ����� N �� ������� ���������\n");
		printf("24:  ������� N ������ ����������� (GOTO)\n");
		printf("25: ���������� ����� N �� ������� ��������� (GOTO)\n\n");
		printf("0: ����� �� ���������\n");

		scanf_s("%d", &n);

		switch (n)
		{
		case 1:
			print1_10();
			break;
		case 2:
			print10_1();
			break;
		case 3:
			print5odds();
			break;
		case 11:
			print100_10();
			break;
		case 12:
			print1000_100();
			break;
		case 13:
		{
			int sum;
			int rate;
			int years;
			int counter = 0;

			printf("������� ����� �� ����� S = ");
			scanf_s("%d", &sum);
			printf("\n������� ���������� ������ R = ");
			scanf_s("%d", &rate);
			printf("\n�� ������� ��� ������ ����� = ");
			scanf_s("%d", &years);

			do {
				printf("����� %d ��� �� ����� ����� %d �����\n", counter, sum);
				sum = bank_account(sum, rate);
				counter++;
			} while (counter <= years);
			break;
		}
		case 20:
			print1000_0_25();
			break;
		case 21:
		{
			int N;
			printf("������� N = ");
			scanf_s("%d", &N);

			factorial(N);
		}
			break;
		case 22:
		{
			int N;
			printf("������� N = ");
			scanf_s("%d", &N);

			Fibonacci(N);
		}
			break;
		case 23:
		{
			int N;
			printf("������� N = ");
			scanf_s("%d", &N);

			prime_factors(N);
			break;
		}
		case 24:
		{
			int N;
			printf("������� N = ");
			scanf_s("%d", &N);

			factorial_GOTO(N);
			break;
		}
		case 25:
		{
			int N;
			printf("������� N = ");
			scanf_s("%d", &N);

			prime_factors_GOTO(N);
			break;
		}
		}

	} while (n != 0);
}