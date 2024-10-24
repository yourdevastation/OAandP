#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float U; // напряжение в сети
	printf("Введите напряжение сети В=");
	scanf_s("%f", &U);

	float R; // сопротивление в сети
	printf("Введите сопротивление в сети в Ом =");
	scanf_s("%f", &R);

	float I = ( U / R) ; // сила тока

	printf("Сила тока при напряжении %f В и сопротивлении %f Ом = %f", U, R, I);


}