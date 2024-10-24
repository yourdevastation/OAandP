#include <stdio.h>
#include <Windows.h>

void aboutMe() {
	printf("Стрюков\n");
	printf("Андрей\n");
	printf("Алексеевич\n");
	printf("\n");
	printf("Группа: ПИбд-12\n");
	printf("Дата 25.09.2024\n");
	printf("Предмет: ОАиП\n");
	printf("Лабораторная работа №8\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	aboutMe();
}