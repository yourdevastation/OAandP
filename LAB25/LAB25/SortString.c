#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "SortString.h"

// Максимальная длина слова в массиве
#define MAX_LEN_WORD 80
// Максимальное количество слов
#define MAX_WORDS 20000

// Слова, загруженные из файла 
char words[MAX_WORDS][MAX_LEN_WORD];
// Количество слов в массиве
int n = 0;

// Массив для сортировки 
char a[MAX_WORDS][MAX_LEN_WORD];

int isalpha_my(unsigned char ch) {

	if (isalpha(ch))
		return 1;

	// ANSI кодировка!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	return 0;
}


int getNextDelim(FILE* fp, char token[]) {
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
	return 1;

}
int getNextWord(FILE* fp, char token[], int maxLen) {
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
		if (i == 0)
			return 0;
	return 1;

}

int LoadWords(char* filename) {
	// открыть файл
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filename);
		return 0;
	}

	char token[MAX_LEN_WORD];
	// пока не конец файла
	while (!feof(fin)) {
		// пока есть разделитель - берем его
		while (getNextDelim(fin, token)) {
		}
		// если есть слово - берем его
		if (getNextWord(fin, token, MAX_LEN_WORD)) {
			if (n < MAX_WORDS) {
				strcpy(words[n], token);
				n++;
			}
			else {
				printf("Words are more than elements in array!!\n");
				fclose(fin);
				return 0;
			}
		}
	}
	// Закрываем файл с текстом
	fclose(fin);
	return 1;
}

void fillArrayStrings() {

	for (int i = 0; i < n; i++) {
		strcpy(a[i], words[i]);
	}

}

int isSortedStrings() {
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(a[i], a[i + 1]) > 0) {
			return 0;
		}
	}
	return 1;
}

int ArraysAreEqual() {
	static int counts_in_words[MAX_WORDS];
	static int counts_in_a[MAX_WORDS];

	for (int i = 0; i < n; i++) {
		counts_in_words[i] = 0;
		counts_in_a[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (strcmp(words[i], words[j]) == 0) {
				counts_in_words[i]++;
			}
			if (strcmp(words[i], a[j]) == 0) {
				counts_in_a[i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (counts_in_words[i] != counts_in_a[i]) {
			return 0;
		}
	}

	return 1;
}

void SelectionSortStrings() {
	for (int i = 0; i < n - 1; i++) {

		int iMin = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[j], a[iMin]) < 0) {
				iMin = j;
			}
		}

		if (i != iMin) {
			char tmp[MAX_LEN_WORD];
			strcpy(tmp, a[i]);
			strcpy(a[i], a[iMin]);
			strcpy(a[iMin], tmp);
		}
	}
}

void QuickSortStrings() {
	qsort(a, n, sizeof(a[0]), strcmp);
}

void BubbleSortStrings() {
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = (n - 1); j > i; j--) {
			if (strcmp(a[j - 1], a[j]) > 0) {
				char tmp[MAX_LEN_WORD];
				strcpy(tmp, a[j]);
				strcpy(a[j], a[j - 1]);
				strcpy(a[j - 1], tmp);
			}
		}
	}
}

void InsertSortStrings() {
	for (int pos = 1; pos < n; pos++) {
		char str[MAX_LEN_WORD];
		strcpy(str, a[pos]);
		int i = pos;
		while ((i > 0) && strcmp(str, a[i - 1]) < 0) {
			strcpy(a[i], a[i - 1]);
			i--;
		}
		strcpy(a[i], str);
	}
}

void vyvod() {
	for (int i = 0; i < n; i++) {
		printf("%s\n", a[i]);
	}
}