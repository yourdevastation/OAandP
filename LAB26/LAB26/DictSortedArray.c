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
/*
INSERT � ��������� ������� � ���������.
��������� � �������� ������ ���������� ��������.
��� ��������� ���������� �������� � ���������, ��������� �� ����������.
*/
void Insert(wchar_t* word) {

	// ������� � ����� ������� ������ ����� ���� ����� �������� �����
	// ������� �������� � ��������������� ������
	// ������� �������� ���, ����� ����� ������� ������ ��� ������������
	int i = numWords;
	while ((i > 0) && (wcscmp(word, words[i - 1]) < 0)) {
		wcscpy(words[i], words[i - 1]);
		i--;
	}
	wcscpy(words[i], word);
	++numWords;
}
/*
MEMBER � ��������, �������� �� ��������� ������� ������ ������� ��������� ��� ���.
���� �������� - ���������� 1, ����� - ���������� 0
*/
int  Member(wchar_t* word) {
	// ������������ �������� ��������� ������ ����� � ��������������� �������
	int left = 0;
	int right = numWords - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		int dif = wcscmp(words[middle], word);
		if (dif == 0) {
			return 1;
		}
		else if (dif < 0) {
			left = middle + 1;
		}
		else if (dif > 0) {
			right = middle - 1;
		}
	}
	return 0;
}

