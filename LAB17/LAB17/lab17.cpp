#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int fact2(int n) {
	if (n == 0)
		return 1;
	long res = fact2(n - 1) * n;
	return res;
}
void f1(int n) {
	printf("%d ", n);
	if (n > 1) {
		f1(n - 2);
	}
}
void f2(int n) {
	if (n > 1) {
		f2(n - 2);
	}
	printf("%d ", n);
}
void f3(int n) {
	printf("%d ", n);
	if (n > 1) {
		f3(n - 2);
		printf("%d ", n);
	}
}
void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}
void recEGE2(int n) {
	printf("%d ", n);
	if (n > 2) {
		recEGE2(n - 3);
		recEGE2(n - 4);
	}
}
void recEGE3(int n) {
	printf("%d ", n);
	if (n < 5) {
		recEGE3(n + 1);
		recEGE3(n + 3);
	}
}
void G3(int n);
void F3(int n) {
	if (n > 0)
		G3(n - 1);
}
void G3(int n) {
	printf("*");
	if (n > 1)
		F3(n - 3);
}
void task9(int n)
{
	if (n > 0) 
	{
		printf("<*");
		task9(n - 1);
		printf("%d>", n);
	}
}


void main()	{
	int n = 5;
	long fact = fact2(n);
	printf("%d! = %ld", n, fact);
	printf("\nfact FINISH\n\n");

	f1(11);
	printf("\nf1 FINISH\n\n");

	f2(11);
	printf("\nf2 FINISH\n\n");

	f3(11);
	printf("\nf3 FINISH\n\n");

	recEGE1(3);
	printf("\nrecEGE1 FINISH\n\n");

	recEGE2(10);
	printf("\nrecEGE2 FINISH\n\n");

	recEGE3(1);
	printf("\nrecEGE3 FINISH\n\n");

	F3(11);
	printf("\nF3 FINISH\n\n");

	task9(5);
	printf("\ntask9 FINISH\n\n");
}