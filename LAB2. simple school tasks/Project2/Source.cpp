#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float a; // �����
	printf("������� ����� � ������=");
	scanf_s("%f", &a);

	float b; //������
	printf("������� ������ � ������=");
	scanf_s("%f", &b);

	float S = a * b; //�������

	printf("������� �������������� = %f", S);


}