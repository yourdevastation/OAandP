//
// ���������� ������� �� �������� ������ ������
// 

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include "Dict.h"


// ���� ������ 
struct NodeTree {
	wchar_t* word;
	struct NodeTree* left;
	struct NodeTree* right;
};

// ������ ������
struct NodeTree* root = NULL;

struct NodeTree* addElement(struct NodeTree* p, wchar_t* word)
{
	int cond;

	if (p == NULL) {
		p = (struct NodeTree*)malloc(sizeof(struct NodeTree));
		p->word = (wchar_t*)calloc(wcslen(word) + 1, sizeof(wchar_t));
		wcscpy(p->word, word);
		p->left = p->right = NULL;
	}
	else if ((cond = wcscmp(word, p->word)) == 0) {
		// ����������� ����� ���������
		// � ��� ���������  - ������ �� ������
	}
	else if (cond < 0) {
		// ����������� ����� ������ 
		// ����� ���������
		p->left = addElement(p->left, word);
	}
	else {
		// ����������� ����� ������ 
		// ����� ���������
		p->right = addElement(p->right, word);
	}
	return p;
}

void clearTree(struct NodeTree* p) {
	if (p != NULL) {
		clearTree(p->left);
		clearTree(p->right);
		free(p->word);
		free(p);
	}
}

int containElement(struct NodeTree* p, wchar_t* word) {
	int cond;
	if (p == NULL) {
		return 0;
	}
	else if ((cond = wcscmp(word, p->word)) == 0) {
		return 1;
	}
	else if (cond < 0) {
		return containElement(p->left, word);
	}
	else {
		return containElement(p->right, word);
	}
}

/* INSERT � ��������� ������� � ���������.
��������� � �������� ������ ���������� ��������.
��� ��������� ���������� �������� � ���������, ��������� �� ����������.*/
void Insert(wchar_t* word) {
	root = addElement(root, word);
}

/* MEMBER � ��������, �������� �� ��������� ������� ������ ������� ��������� ��� ���.*/
int  Member(wchar_t* word) {
	return containElement(root, word);
}

/* CREATE - ������� �������.
���������� ����� ������� ������������� �������. */
void Create() {
	root = NULL;
}

/* DESTROY - ���������� �������.
���������� ����� ��������� ������������� �������. */
void Destroy() {
	clearTree(root);
	root = NULL;
}
