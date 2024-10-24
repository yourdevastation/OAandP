#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define NUM_ELEMENTS 10

int n = 0;
int array[NUM_ELEMENTS];

void random() {
	printf("enter the number of elements = ");
	scanf_s("%d", &n);
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int a = rand();
		int b = rand();
		if (a > 1000) a %= 100;
		if (b > 1000) b %= 100;
		array[i] = a % b;
	}
}
void printElements() {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
}
void keyboardInput() {
	printf("enter the number of elements = ");
	scanf_s("%d", &n);

	printf("input %d elements ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &array[i]);
	}
}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 1) 
			array[i] *= 10;
	}

}
int findMin() {
	int min = array[0];
	for (int i = 0; i < n; i++) {
		if (array[i] < min)
			min = array[i];
	}
		return min;
}
int morethan10() {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] > 10) counter++;
	}
	return counter;
}
int findFirstEven() {
	for (int i = 0; i < n; i++) {
		if (array[i] != 0 && array[i] % 2 == 0)
			return i;
	}
	return -1;
}
int findLastEven() {
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 0)
			index = i;
	}
	return index;
}
int findIndexMin() {
	int min = array[0];
	int indexMin = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] < min) {
			min = array[i];
			indexMin = i;
		}
	}
	return indexMin;
}
int findIndexMax() {
	int max = array[0];
	int indexMax = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] > max) {
			max = array[i];
			indexMax = i;
		}
	}
	return indexMax;
}
void minusOne() {
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 0)
			array[i] *= -1;
	}
}
void change4() {
	for (int i = 0; i < n; i++) {
		if (array[i] < 4)
			array[i] = 4;
	}
}
void change1() {
	for (int i = 1; i < n - 1; i++) {
		if (array[i - 1] % 2 == 0 && array[i + 1] % 2 == 0)
			array[i] = 1;
	}
}
void X10fromMaxToMin() {
	int max = findIndexMax();
	int min = findIndexMin();
	for (int i = 0; i < n; i++) {
		if (i > max && i < min)
			array[i] *= 10;
		if (i < max && i > min)
			array[i] *= 10;
	}
}
void X100from1stTOlastEvens() {
	int first = findFirstEven();
	int last = findLastEven();
	for (int i = 0; i < n; i++) {
		if (i > first && i < last)
			array[i] *= 100;
	}
}

void deleteElement(int delindex) {
	for (int i = delindex; i < n - 1; i++) {
		array[i] = array[i + 1];
	}
	n--;
}
void insertElement(int insIndex, int value) {
	for (int i = n; i > insIndex; i--) {
		array[i] = array[i - 1];
	}
	n++;
	array[insIndex] = value;
}
int findMaxEven() {
	int firstEven = findFirstEven();
	if (firstEven >= 0) {
		int maxEven = array[firstEven];
		int indexMaxEven = firstEven;
		for (int i = 0; i < n; i++) {
			if (array[i] > maxEven && array[i] && 2 == 0) {
				maxEven = array[i];
				indexMaxEven = i;
			}
		}
		return indexMaxEven;
	}
	else printf("В массиве нет четных чисел");
}
void insertElementAfter(int insIndex, int value) {
	for (int i = n; i > insIndex + 1; i--) {
		array[i] = array[i - 1];
	}
	n++;
	array[insIndex + 1] = value;
}
void doubleEven() {
 
}


void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int operation;

	do {
		printf("\n------------------------------------\n");
		printf("Содержимое массива: ");
		printf("< ");
		printElements();
		printf(">");

		printf("\nВыберите нужную вам операцию:");
		printf("\n999: Ввести рандомный массив");
		printf("\n1: Ввести с клавиатуры массив");
		printf("\n2: x10 для всех нечетных элементов");
		printf("\n3: Найти минимальный элемент");
		printf("\n4: Сколько элементов > 10");
		printf("\n5: x2 для последнего четного");
		printf("\n6: Сколько четных левее минимального");
		printf("\n7: x10 для нечетных правее минимального");
		printf("\n8: Переставить местами min и max");
		printf("\n9: Все четные элементы умножить на -1");
		printf("\n10: Элементы со значением < 4 заменить на 4");
		printf("\n11: Все элементы стоящие между четными заменить на 1");
		printf("\n12: Все элементы стоящие между max и min увеличить в 10 раз");
		printf("\n13: Все элементы между первым и последним четным увеличить в 100 раз");
		printf("\n14: Удалить заданный элемент");
		printf("\n15: Вставить новый элемент в заданное место");
		printf("\n16: Удалить минимальный элемент");
		printf("\n17: Перед минимальным поставить 0");
		printf("\n18: Удалить все четные элементы");
		printf("\n19: Продублировать все четные элементы");
		printf("\n22: После максимального из четных поставить 0");



		printf("\n\n0: Выйти из программы");
		printf("\nВыбранная операция >>>>> ");
		scanf_s("%d", &operation);

		switch (operation) {
		case 999:
			random();
		break;
		case 1:
			keyboardInput();
		break;
		case 2:
			oddsX10();
		break;
		case 3:
		{
			int min = findMin();
			printf("minimal element = %d\n", min);
		}
		break;
		case 4:
		{
			int mt10 = morethan10();
			printf("%d элементов больше чем 10\n", mt10);
		}
		break;
		case 5:
		{
			int index = findLastEven();
			if (index >= 0)
				array[index] *= 2;
		}
		break;
		case 6:
		{
			int indexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", indexMin);

			int counter = 0;
			for (int i = 0; i < indexMin; i++) {
				if (array[i] % 2 == 0)
					counter++;
			}
			printf("Левее минимального элемента %d четных элементов\n", counter);
		}
		break;
		case 7:
		{
			int indexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", indexMin);

			for (int i = 0; i < n; i++) {
				if (array[i] % 2 == 1 && i > indexMin) {
					array[i] = array[i] * 10;
				}
			}
		}
		break;
		case 8:
		{
			int indexMin = findIndexMin();
			printf("Индекс минимального элемента = %d\n", indexMin);
			int indexMax = findIndexMax();
			printf("Индекс максимального элемента = %d\n", indexMax);

			int temp = array[indexMax];
			array[indexMax] = array[indexMin];
			array[indexMin] = temp;

		}
		break;
		case 9:
			minusOne();
		break;
		case 10:
			change4();
		break;
		case 11:
			change1();
		break;
		case 12:
			X10fromMaxToMin();
		break;
		case 13:
			X100from1stTOlastEvens();
		break;
		case 14:
		{
			int index;
			printf("Индекс удаляемого элемента = ");
			scanf_s("%d", &index);
			deleteElement(index);
		}
		break;
		case 15: 
		{
			int index;
			int value;
			printf("Перед каким элементом нужно вставить новый\n Индекс = ");
			scanf_s("%d", &index);

			printf("Значение, которое нужно вставить = ");
			scanf_s("%d", &value);

			insertElement(index, value);
		}
		break;
		case 16:
		{
			int min = findIndexMin();
			printf("Индекс минимального элемента = %d\n", min);
			deleteElement(min);
		}
		break;
		case 17:
		{
			int min = findIndexMin();
			printf("Индекс минимального элемента = %d\n", min);
			insertElement(min, 0);
		}
		break;
		case 18: 
		{
			int even = 0;
			do {
				even = findFirstEven();
				if (even == -1)
					printf("Нет четных элементов для удаления\n\n");
				else
					deleteElement(even);
			} while (even >= 0);
		}
		break;
		case 19:
			doubleEven();
		break;
		case 22:
		{
			int max = findMaxEven();
			printf("Индекс максимального элемента = %d\n", max);
			insertElementAfter(max, 0);
		}
		break;
		default:
			break;
		}
	} while (operation != 0);
}