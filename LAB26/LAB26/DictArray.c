#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <wchar.h>
#include "Dict.h"

#define MAX_WORDS 10000

// ����� 
wchar_t words[MAX_WORDS][MAX_LEN_WORD + 1];
// ���������� ���� � �������
int numWords = 0;

/* CREATE - ������� �������.
���������� ����� ������� ������������� �������. */
void Create() {
	numWords = 0;
}

/* DESTROY - ���������� �������.
���������� ����� ��������� ������������� �������. */
void Destroy() {
	numWords = 0;
}

/* INSERT � ��������� ������� � ���������.
��������� � �������� ������ ���������� ��������.
��� ��������� ���������� �������� � ���������, ��������� �� ����������. */
void Insert(wchar_t* word) {
	if (!Member(word)) {
		if (numWords < MAX_WORDS) {
			wcscpy(words[numWords], word);
			numWords++;
		}
	}
}

/* MEMBER � ��������, �������� �� ��������� ������� ������ ������� ��������� ��� ���.
���� �������� - ���������� 1, ����� - ���������� 0 */
int  Member(wchar_t* word) {
	for (int i = 0; i < numWords; i++) {
		if (wcscmp(words[i], word) == 0) {
			return 1;
		}
	}
	return 0;
}
