#include <stdio.h>
#include <Windows.h>

void aboutMe() {
	printf("�������\n");
	printf("������\n");
	printf("����������\n");
	printf("\n");
	printf("������: ����-12\n");
	printf("���� 25.09.2024\n");
	printf("�������: ����\n");
	printf("������������ ������ �8\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();
}