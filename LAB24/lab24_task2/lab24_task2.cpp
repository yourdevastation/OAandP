#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define MAX_LEN 40

int isalpha_my(unsigned char ch) {
	if (isalpha(ch))
		return 1;
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 223 && ch <= 255)
		return 1;
	return 0;
}

int islower_my(int c) {
	if (c >= 'a' && c <= 'z')
		return 1;
	if (c >= 'à' && c <= 'ÿ')
		return 1;
	if (c == '¸')
		return 1;
	return 0;
}

int getNextDelim(FILE* fp, char token[]) {
	int ch = getc(fp);

	if (ch == EOF)
		return 0;

	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
	return 1;
}

int getNextWord(FILE* fp, char token[], int maxLen) {
	int ch;
	int i = 0;

	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha_my((unsigned char)ch)) {
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

int islower_token(char token[]) {
	for (int i = 0; token[i] != '\0'; i++) {
		if (!islower_my(token[i]))
			return 0;
	}
	return 1;
}

char filenameIn[] = "C:\\Users\\socea\\source\\repos\\LAB23\\text_to_html_in2.txt";
char filenameHTML[] = "C:\\Users\\socea\\source\\repos\\LAB23\\text_to_html_out2.html";

void main() {
	printf("BEGIN!!!\n");
	/*setlocale(LC_ALL, "Russian");*/
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		printf("File %s doesn't opened!\n", filenameIn);
		return;
	}

	FILE* fout = fopen(filenameHTML, "wt");
	if (fout == NULL) {
		fclose(fin);
		printf("File %s doesn't opened!\n", filenameHTML);
		return;
	}

	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" "
		"content = \"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");

	char token[MAX_LEN];
	int ch;
	while (!feof(fin)) {
		while (getNextWord(fin, token, MAX_LEN)) {
			if (strlen(token) <= 3 && islower_token(token))
				fprintf(fout, "<i><b>%s</b></i>", token);
			else if (strlen(token) <= 3)
				fprintf(fout, "<b>%s</b>", token);
			else if (islower_token(token))
				fprintf(fout, "<i>%s</i>", token);
			else fprintf(fout, "%s", token);
		}

		if (getNextDelim(fin, token)) {
			if (token[0] == '\n')
				fprintf(fout, "<br>");
			fprintf(fout, "%s", token);
		}
	}

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");

	fclose(fin);
	fclose(fout);
	printf("END!");
}