//
// Реализация АТД «Словарь» на Структуре данных «Односвязанный список»
// 
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

#include "Dict.h"


// элемент односвязанного списка
struct Node {
	wchar_t* word;
	struct Node* next;
};


// Первый элемент списка
struct Node* first = NULL;

/* MEMBER – сообщает, является ли указанный элемент членом данного множества или нет. */
int  Member(wchar_t* word) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (wcscmp(ptr->word, word) == 0) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

/* INSERT – добавляет элемент в множество.
Множество – содержит только уникальные элементы.
При повторном добавлении элемента в множество, множество не изменяется.
ЗДЕСЬ НЕТ ПРОВЕРКИ НА ДУБЛИРОВАНИЕ!!!!
*/
void Insert(wchar_t* word) {

	if (Member(word))
		return;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) {
		fwprintf(stderr, L"Не удалось выделить память для нового узла\n");
		exit(1);
	}

	newNode->word = (wchar_t*)calloc(wcslen(word) + 1, sizeof(wchar_t));
	if (!newNode->word) {
		fwprintf(stderr, L"Не удалось выделить память для строки\n");
		free(newNode);
		exit(1);
	}
	wcscpy(newNode->word, word);
	newNode->next = first;
	first = newNode;
}

/* CREATE - создает словарь.
Вызывается перед началом использования словаря. */
void Create() {
	first = NULL;
}

/* DESTROY - уничтожает словарь.
Вызывается после окончания использования словаря. */
void Destroy() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;

		free(delNode->word);
		free(delNode);
	}
}