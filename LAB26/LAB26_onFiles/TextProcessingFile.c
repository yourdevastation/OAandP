#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define MAX_LEN_WORD 80

wchar_t filenameDict[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Dictionaries\\dict0a.txt";
//wchar_t filenameDict[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Dictionaries\\dict0a.txt";
//wchar_t filenameDict[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Dictionaries\\dict0b.txt";

//wchar_t filenameIn[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Texts\\Alice.txt";
//wchar_t filenameOut[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Out\\Alice_out.html";

wchar_t filenameIn[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Texts\\Tolkien.txt";
wchar_t filenameOut[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Out\\Tolkien_out.html";

//wchar_t filenameIn[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Texts\\Tolkien2.txt";
//wchar_t filenameOut[] = L"c:\\Users\\socea\\source\\repos\\LAB26\\Lab_rabota_26\\Out\\Tolkien2_out.html";

int getNextDelim(FILE* fp, wchar_t token[]) {
	int ch = getwc(fp);

	if (ch == WEOF)
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

int TextProcessing(wchar_t* filenameIn, wchar_t* filenameOut) {
	// ������� ���� �������
	FILE* fin = _wfopen(filenameIn, L"rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		wprintf(L"File %s doesn't opened!\n", filenameIn);
		return 0;
	}

	// ������� ���� ��������
	FILE* fout = _wfopen(filenameOut, L"wt");
	if (fout == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		wprintf(L"File %s doesn't opened!\n", filenameOut);
		// � ��������� ������� ����
		fclose(fin);
		return 0;
	}

	// ������� � �������� ���� ��������� HTML ���������
	fwprintf(fout, L"<!DOCTYPE html>");
	fwprintf(fout, L"<html>");
	fwprintf(fout, L"<head>");
	fwprintf(fout, L"<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
	fwprintf(fout, L"<title>HTML Document</title>");
	fwprintf(fout, L"</head>");
	fwprintf(fout, L"<body>");
	wchar_t token[MAX_LEN_WORD];

	// ���� �� ����� �����
	while (!feof(fin)) {
		// ���� ���� ����������� - ����� ���
		while (getNextDelim(fin, token)) {
			// ������� ����������� 
			if (wcscmp(token, L"<") == 0) {
				fwprintf(fout, L"&lt");
			}
			else if (wcscmp(token, L">") == 0) {
				fwprintf(fout, L"&gt");
			}
			else if (wcscmp(token, L"\n") == 0) {
				fwprintf(fout, L"<br>");
			}
			fwprintf(fout, L"%s", token);
		}
		// ���� ���� ����� - ����� ���
		if (getNextWord(fin, token, MAX_LEN_WORD)) {
			// ���� ����� ���� � ������� � �� �������� ���
			if (Member(token)) {
				fwprintf(fout, L"<b>%s</b>", token);
			}
			else {
				fwprintf(fout, L"%s", token);
			}
		}
	}
	// ������� � HTML ����������� ���� ��������� HTML
	fwprintf(fout, L"</body>");
	fwprintf(fout, L"</html>");
	// ��������� ������� � �������� �����
	fclose(fin);
	fclose(fout);
	return 1;
}

// ��������, ���� �� ����� word � �������, ���������� � ����� filenameDict
int Member(wchar_t* word) {
	// ������� ����
	FILE* fin = _wfopen(filenameDict, L"rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		wprintf(L"File %s doesn't opened!\n", filenameDict);
		return 0;
	}

	wchar_t token[MAX_LEN_WORD];

	// ���� �� ����� �����
	while (!feof(fin)) {
		// ���� ���� ����������� - ����� ���
		while (getNextDelim(fin, token)) {
		}
		// ���� ���� ����� - ����� ���
		if (getNextWord(fin, token, MAX_LEN_WORD)) {
			if (wcscmp(token, word) == 0) {
				// ����� � ����� ����!
				fclose(fin);
				return 1;
			}
		}
	}
	// ��������� ���� � �������
	fclose(fin);
	return 0;
}


void main() {
	_wsetlocale(LC_ALL, L".utf-8");
	// �������� ����� ����� ��������������
	wprintf(L"HTML file %s\nis created from text file %s\nwith highlighting words from %s\ndictionary\n\n\n",
		filenameOut, filenameIn, filenameDict);

	// t0 - ������� ������ ������� �� ������ ��������� �� ������� ����� � ������� main()
	long t0 = clock();
	wprintf(L"t0 = %.3f sec \n", t0 / (float)CLOCKS_PER_SEC);

	// t1 - ������� ������ ������� �� ������ ��������� �� ��������� �������� �������
	int t1 = clock();
	wprintf(L"t1 = %.3f sec \n", t1 / (float)CLOCKS_PER_SEC);

	TextProcessing(filenameIn, filenameOut);

	// t2 - ������� ������ ������� �� ������ ��������� �� ��������� ����������� ������
	long t2 = clock();
	wprintf(L"t2 = %.3f sec \n", t2 / (float)CLOCKS_PER_SEC);

	// t3 - ������� ������ ������� �� ��������� ����������� ������ �� ��������� ����������� ������� 
	long t3 = clock();

	wprintf(L"t3 = %.3f sec \n", t3 / (float)CLOCKS_PER_SEC);
	wprintf(L"t1 - t0 = %.3f sec (Run time of dictionary loading)\n", (t1 - t0) / (float)CLOCKS_PER_SEC);
	wprintf(L"t2 - t1 = %.3f sec (Run time of HTML generating)\n", (t2 - t1) / (float)CLOCKS_PER_SEC);
	wprintf(L"t3 - t2 = %.3f sec (Run time of dictionary destroying)\n", (t3 - t1) / (float)CLOCKS_PER_SEC);
	wprintf(L"t3 - t0 = %.3f sec (Run time TOTAL)\n", (t3 - t0) / (float)CLOCKS_PER_SEC);
}

