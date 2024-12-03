#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

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

int getNextWord(FILE* fp, char token[]) {
	int ch;
	int i = 0;

	while (((ch = getc(fp)) != EOF) && (i < MAX_LEN - 1)) {
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

char filenameIn[] = "C:\\Users\\socea\\source\\repos\\LAB23\\text_to_html_in.txt";
char filenameHTML[] = "C:\\Users\\socea\\source\\repos\\LAB23\\text_to_html_out.html";

void main() {
	printf("BEGIN!!!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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

	int ch;
	while ((ch = getc(fin)) != EOF) {
		fprintf(fout, "%c", ch);

		if (ch == '\n')
			fprintf(fout, "<br>");
	}

	fprintf(fout, "</body>");
	fprintf(fout, "</html>");

	fclose(fin);
	fclose(fout);
	printf("END!");
}