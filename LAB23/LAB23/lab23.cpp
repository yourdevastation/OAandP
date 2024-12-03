#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_LEN 80
char s[MAX_LEN];

void text1() {
	printf("Власенко Олег\n");
	printf("ЛР23 Задача 1\n");

	FILE* fin;
	fin = fopen("C:\\Users\\socea\\source\\repos\\LAB23\\text1.txt", "rt");
	if (fin == NULL) {
		printf("File text1.txt is not found");
		return;
	}

	FILE* fout;
	fout = fopen("C:\\Users\\socea\\source\\repos\\LAB23\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Can not create file");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == '\t')
					s[i] = '%';
			}
			fprintf(fout, "%s", s);
			printf(">>>%s<<<\n", s);
		}
	}
	fclose(fin);
	fclose(fout);
	printf("ЛР23 Задача 1 FINISH\n");
}

void text2() {
	FILE* fin;
	fin = fopen("C:\\Users\\socea\\source\\repos\\LAB23\\text2.txt", "rt");
	if (fin == NULL) {
		printf("File text2.txt is not found");
		return;
	}
	FILE* fout;
	fout = fopen("C:\\Users\\socea\\source\\repos\\LAB23\\out2.txt", "wt");
	if (fout == NULL) {
		printf("Can not create file");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				s[i] = toupper(s[i]);
			}
		}
		fprintf(fout, "%s", s);
		printf("===%s===", s);
	}
	fclose(fin);
	fclose(fout);
	printf("now the letters are BIGGER!!!");
}

void text4() {
	FILE* fin;
	fin = fopen("C:\\Users\\socea\\source\\repos\\LAB23\\text4.txt", "rt");
	if (fin == NULL) {
		printf("File text2.txt is not found");
		return;
	}
	FILE* fout;
	fout = fopen("C:\\Users\\socea\\source\\repos\\LAB23\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Can not create file");
		return;
	}
	while (!feof(fin)) {
		if (fgets(s, MAX_LEN, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (ispunct(s[i]))
					s[i] = '_';
			}
		}
		fprintf(fout, "%s", s);
		printf("===%s===", s);
	}
	fclose(fin);
	fclose(fout);
	printf("fuck punctuation!!!");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	text1();

	text2();

	text4();
}