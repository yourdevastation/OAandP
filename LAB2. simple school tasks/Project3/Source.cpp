#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float S0; // ����� ������
	printf("������� ����� ������ RUB=");
	scanf_s("%f", &S0);

	float n; // ���������� ���
	printf("�� ������� ��� ������ ����� =");
	scanf_s("%f", &n);

	float p; // ������� ������
	printf("������� ������� ������ ����� =");
	scanf_s("%f", &p);

	float Sn = S0 * ( 1 + ( p * n / 100)); // ����� ������ ����� n ���

	printf("����� �� ����� ����� %f ��� = %f", n, Sn);


}