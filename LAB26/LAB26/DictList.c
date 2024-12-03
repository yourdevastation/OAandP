//
// ���������� ��� ��������� �� ��������� ������ �������������� ������
// 
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

#include "Dict.h"


// ������� �������������� ������
struct Node {
	wchar_t* word;
	struct Node* next;
};


// ������ ������� ������
struct Node* first = NULL;

/* MEMBER � ��������, �������� �� ��������� ������� ������ ������� ��������� ��� ���. */
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

/* INSERT � ��������� ������� � ���������.
��������� � �������� ������ ���������� ��������.
��� ��������� ���������� �������� � ���������, ��������� �� ����������.
����� ��� �������� �� ������������!!!!
*/
void Insert(wchar_t* word) {

	if (Member(word))
		return;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) {
		fwprintf(stderr, L"�� ������� �������� ������ ��� ������ ����\n");
		exit(1);
	}

	newNode->word = (wchar_t*)calloc(wcslen(word) + 1, sizeof(wchar_t));
	if (!newNode->word) {
		fwprintf(stderr, L"�� ������� �������� ������ ��� ������\n");
		free(newNode);
		exit(1);
	}
	wcscpy(newNode->word, word);
	newNode->next = first;
	first = newNode;
}

/* CREATE - ������� �������.
���������� ����� ������� ������������� �������. */
void Create() {
	first = NULL;
}

/* DESTROY - ���������� �������.
���������� ����� ��������� ������������� �������. */
void Destroy() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;

		free(delNode->word);
		free(delNode);
	}
}