#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>

void charsUP20() {

	printf("Enter a char = ");
	int ch = getchar();

	for (int c = ch; c <= ch + 19; c++) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}

void charsDOWN29() {

	printf("Enter a char = ");
	int ch = getchar();

	for (int c = ch; c >= ch - 29; c--) {
		printf("'%c' (%d)\n", c, c);
	}
	printf("\n\n\n");
}

void countSpaces() {

	char s[80];
	printf("Enter a string: ");
	fgets(s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			cnt++;
	}
	printf("\n There are %d spaces in the string", cnt);
}

void changeSpaces() {
	char s[100];
	printf("Enter a string: ");
	fgets(s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			s[i] = '#';
	}
	printf("\nThe string after processing: \"%s\"", s);
}

void changeDigits() {
	unsigned char s[100];
	printf("Enter a string: ");
	fgets((char *)s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i]))
			s[i] = '$';
	}
	printf("\nThe string after processing: \"%s\"", s);
}

int isdigit_my(int c) {
	return (c >= '0' && c <= '9');
}
void changeDigits2() {
	unsigned char s[100];
	printf("Enter a string: ");
	fgets((char*)s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit_my(s[i]))
			s[i] = '$';
	}
	printf("\nThe string after processing: \"%s\"", s);
}

void lowerToUpper() {
	char s[100];
	printf("Enter a string: ");
	fgets(s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toupper(s[i]);
	}
	printf("\nThe string after processing: \"%s\"", s);
}

int toupper_my(int c) {
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A');
	if (c >= 'à' && c <= 'ÿ')
		return c - ('à' - 'À');
	if (c == '¸')
		return c = '¨';
	else return c;
}
void lowerToUpperRU_edition() {
	char s[100];
	printf("Enter a string: ");
	fgets(s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toupper_my(s[i]);
	}
	printf("\nThe string after processing: \"%s\"", s);
}

void allDigitsToX() {
	unsigned char s[100];
	printf("Enter a string: ");
	fgets((char*)s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isdigit(s[i]))
			s[i] = 'X';
	}
	printf("\nThe string after processing: \"%s\"", s);
}

int isvowel_my(int c) {
	return (c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'o' || c == 'i' ||
		c == 'A' || c == 'E' || c == 'Y' || c == 'U' || c == 'O' || c == 'I');
}
void allVowelsUpperLatinTO$() {
	unsigned char s[100];
	printf("Enter a string: ");
	fgets((char*)s, _countof(s), stdin);

	printf("U entered the string: \"%s\"", s);

	for (int i = 0; s[i] != '\0'; i++) {
		if (isupper(s[i]) && isvowel_my(s[i]))
			s[i] = '$';
	}
	printf("\nThe string after processing: \"%s\"", s);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*charsUP20();*/

	/*charsDOWN29();*/

	/*countSpaces();*/

	//changeSpaces();

	//changeDigits();

	//changeDigits2();

	//lowerToUpper();

	//lowerToUpperRU_edition();

	//allDigitsToX();

	allVowelsUpperLatinTO$();

}




//do {
	//	printf("1. Print 19 chars up"
	//		"\n2. Print 29 chars down");

	//	printf("\nChoose operation = ");
	//	scanf_s("%d", &opp);

	//	switch (opp) {
	//		case 1:
	//		charsUP20();
	//			break;
	//		case 2:
	//		charsDOWN29();
	//			break;
	//	}
	//} while (opp != 0);