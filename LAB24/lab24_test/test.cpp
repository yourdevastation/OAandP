#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

#define MAX_LEN 40

int isalpha_my(int ch) {
	/*if (isalpha(ch))
		return 1;*/
	if (ch >= L'A' && ch <= L'Z')
		return 1;
	if (ch >= L'a' && ch <= L'z')
		return 1;
	if (ch >= L'À' && ch <= L'ß')
		return 1;
	if (ch >= L'à' && ch <= L'ÿ')
		return 1;
	if (ch == L'¨' || ch == L'¸')
		return 1;
	/*if (ch >= 1040 && ch <= 1071)
		return 1;
	if (ch >= 1072 && ch <= 1103)
		return 1;
	if (ch >= 65 && ch <= 90)
		return 1;
	if (ch >= 97 && ch <= 122)
		return 1;
	if (ch == 1025 || ch == 1105)
		return 1;*/
	return 0;
}

int islower_my(int c) {
	if (c >= L'a' && c <= L'z')
		return 1;
	if (c >= L'à' && c <= L'ÿ')
		return 1;
	if (c == L'¸')
		return 1;
	return 0;
}

int getNextDelim(FILE* fp, wchar_t token[]) {
	int ch = getwc(fp);

	if (ch == EOF)
		return 0;

	if (iswalpha((wchar_t)ch)) {
		ungetwc(ch, fp);
		return 0;
	}
	token[0] = (wchar_t)ch;
	token[1] = '\0';
	return 1;
}

int getNextWord(FILE* fp, wchar_t token[], int maxLen) {
	int ch;
	int i = 0;

	while (((ch = getwc(fp)) != WEOF) && (i < maxLen - 1)) {
		if (!iswalpha((wchar_t)ch)) {
			break;
		}
		token[i++] = ch;
	}
	ungetwc(ch, fp);
	token[i] = '\0';
	if (i == 0)
		return 0;
	return 1;
}

int islower_token(wchar_t token[]) {
	for (int i = 0; token[i] != '\0'; i++) {
		if (!iswlower(token[i]))
			return 0;
	}
	return 1;
}

wchar_t filenameIn[] = L"C:\\Users\\socea\\source\\repos\\LAB23\\text_to_html_in2.txt";
wchar_t filenameHTML[] = L"C:\\Users\\socea\\source\\repos\\LAB23\\text_to_html_out2.html";

void main() {
	printf("BEGIN!!!\n");
	_wsetlocale(LC_ALL, L".utf-8");
	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	FILE* fin = _wfopen(filenameIn, L"rt");
	if (fin == NULL) {
		wprintf(L"File %s doesn't opened!\n", filenameIn);
		return;
	}

	FILE* fout = _wfopen(filenameHTML, L"wt");
	if (fout == NULL) {
		fclose(fin);
		wprintf(L"File %s doesn't opened!\n", filenameHTML);
		return;
	}

	fwprintf(fout, L"<!DOCTYPE html>");
	fwprintf(fout, L"<html>");
	fwprintf(fout, L"<head>");
	fwprintf(fout, L"<meta http - equiv = \"Content-Type\" "
		"content = \"text/html; charset=utf-8\" />");
	fwprintf(fout, L"<title>HTML Document</title>");
	fwprintf(fout, L"</head>");
	fwprintf(fout, L"<body>");

	wchar_t token[MAX_LEN];
	int ch;
	while (!feof(fin)) {
		while (getNextWord(fin, token, MAX_LEN)) {
			if (wcslen(token) <= 3 && islower_token(token))
				fwprintf(fout, L"<i><b>%s</b></i>", token);
			else if (wcslen(token) <= 3)
				fwprintf(fout, L"<b>%s</b>", token);
			else if (islower_token(token))
				fwprintf(fout, L"<i>%s</i>", token);
			else fwprintf(fout, L"%s", token);
		}

		if (getNextDelim(fin, token)) {
			if (token[0] == '\n')
				fwprintf(fout, L"<br>");
			fwprintf(fout, L"%s", token);
		}
	}

	fwprintf(fout, L"</body>");
	fwprintf(fout, L"</html>");

	fclose(fin);
	fclose(fout);
	wprintf(L"END!");
}