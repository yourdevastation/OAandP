#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float S0; // сумма вклада
	printf("Введите сумму вклада RUB=");
	scanf_s("%f", &S0);

	float n; // количество лет
	printf("На сколько лет сделан вклад =");
	scanf_s("%f", &n);

	float p; // годовая ставка
	printf("Введите годовую ставку банка =");
	scanf_s("%f", &p);

	float Sn = S0 * ( 1 + ( p * n / 100)); // сумма вклада через n лет

	printf("Сумма на счете через %f лет = %f", n, Sn);


}