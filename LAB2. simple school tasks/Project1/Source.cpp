#include <stdio.h>
#include <Windows.h>
#include <math.h>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float U; // ���������� � ����
	printf("������� ���������� ���� �=");
	scanf_s("%f", &U);

	float R; // ������������� � ����
	printf("������� ������������� � ���� � �� =");
	scanf_s("%f", &R);

	float I = ( U / R) ; // ���� ����

	printf("���� ���� ��� ���������� %f � � ������������� %f �� = %f", U, R, I);


}