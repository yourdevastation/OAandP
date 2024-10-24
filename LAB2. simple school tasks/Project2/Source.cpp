#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float a; // длина
	printf("¬ведите длину в метрах=");
	scanf_s("%f", &a);

	float b; //ширина
	printf("¬ведите ширину в метрах=");
	scanf_s("%f", &b);

	float S = a * b; //площадь

	printf("ѕлощадь пр€моугольника = %f", S);


}