#include <stdio.h>
#include <string.h>
#include <Windows.h>

int strlen_my(char s[]) {
	char* p = s;
	while (*p) p++;
	return p - s - 1;
}

int strlen_my2(char* s) {
	char* p = s;
	while (*p) p++;
	return p - s - 1;
}

int strcmp_my(char s1[], char s2[]) {
	int i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}

int strcmp_my2(char* s1, char* s2) {
	while (*s1 && *s2 && *s1 == *s2) {
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

void strcpy_my(char dest[], char src[]) {
	int i = 0;
	while (dest[i] >= 0 || src[i] >= 0) {
		dest[i] = src[i];
		i++;
	}
}

void strcat_my(char* dest, char* src) {
	while (*dest) dest++;
	while (*dest++ = *src++);
}

int strcspn_my(char s1[], char s2[]) {
	int i = 0;
	int j = 0;
	for (i = 0; s1[i] != 0; i++) {
		for (j = 0; s2[j] != 0; j++) {
			if (s1[i] == s2[j])
				return i;
		}
	}
	return 0;
}

void main() {
	/*char str1[50];
	char str2[50];
	char str3[50];
	char str4[50];

	printf("Enter 1st string: ");
	fgets(str1, _countof(str1), stdin);
	printf("Enter 2nd string: ");
	fgets(str2, _countof(str2), stdin);
	printf("Enter 3rd string: ");
	fgets(str3, _countof(str3), stdin);
	printf("Enter 4th string: ");
	fgets(str4, _countof(str4), stdin);
	printf("%s", str1);
	printf("\n%s", str2);
	printf("\n%s", str3);
	printf("\n%s", str4);

	printf("len = %d\n", strlen_my(str1));

	printf("len = %d\n", strlen_my(str2));
	///////////////////////////////////

	printf("len = %d\n", strlen_my2(str1));

	printf("len = %d\n", strlen_my2(str2));
	/////////////////////////////////

	char* max1 = str1;
	char* min1 = str1;
	if (strcmp_my(str2, max1) > 0) max1 = str2;
	if (strcmp_my(str3, max1) > 0) max1 = str3;
	if (strcmp_my(str4, max1) > 0) max1 = str4;

	if (strcmp_my(str2, min1) < 0) min1 = str2;
	if (strcmp_my(str3, min1) < 0) min1 = str3;
	if (strcmp_my(str4, min1) < 0) min1 = str4;

	printf("\nmin = %s", min1);
	printf("\nmax = %s", max1);
	/////////////////////////////////////

	char* max2 = str1;
	char* min2 = str1;
	if (strcmp_my2(str2, max2) > 0) max2 = str2;
	if (strcmp_my2(str3, max2) > 0) max2 = str3;
	if (strcmp_my2(str4, max2) > 0) max2 = str4;

	if (strcmp_my2(str2, min2) < 0) min2 = str2;
	if (strcmp_my2(str3, min2) < 0) min2 = str3;
	if (strcmp_my2(str4, min2) < 0) min2 = str4;

	printf("\nmin = %s", min2);
	printf("\nmax = %s", max2);
	//////////////////////////////////////////

	char strcpy1[100];
	printf("Enter the line u want to copy to: ");
	fgets(strcpy1, _countof(strcpy1), stdin);
	printf("%s", strcpy1);

	char strcpy2[100];
	printf("Enter the line u want to paste: ");
	fgets(strcpy2, _countof(strcpy2), stdin);
	printf("%s", strcpy2);

	strcpy_my(strcpy1, strcpy2);
	printf("The 1st string after processing: %s", strcpy1);
	//////////////////////////////////////////////////////

	char strcat1[100];
	printf("Enter the line at the end of which u want to copy: ");
	fgets(strcat1, _countof(strcat1), stdin);
	printf("%s", strcat1);

	char strcat2[100];
	printf("Enter the line u want to paste: ");
	fgets(strcat2, _countof(strcat2), stdin);
	printf("%s", strcat2);

	strcat_my(strcat1, strcat2);
	printf("The 1st string after processing: %s", strcat1);
	//////////////////////////////////////////////////////
	*/
	/*char strcspn1[100];
	printf("Enter the line u want to find a position of the char from the next one: ");
	fgets(strcspn1, _countof(strcspn1), stdin);
	printf("%s", strcspn1);

	char strcspn2[100];
	printf("Enter the line for searching the position of the 1st matching char: ");
	fgets(strcspn2, _countof(strcspn2), stdin);
	printf("%s", strcspn2);

	int x = strcspn_my(strcspn1, strcspn2);
	if (x != 0)
		printf("The position of the 1st matching char: %d", x);
	else printf("No matching chars!");*/
	char str1[50];
char str2[50];
char str3[50];
char str4[50];

printf("Enter 1st string: ");
fgets(str1, _countof(str1), stdin);
printf("Enter 2nd string: ");
fgets(str2, _countof(str2), stdin);
printf("Enter 3rd string: ");
fgets(str3, _countof(str3), stdin);
printf("Enter 4th string: ");
fgets(str4, _countof(str4), stdin);
printf("%s", str1);
printf("\n%s", str2);
printf("\n%s", str3);
printf("\n%s", str4);

	char* max2 = str1;
	char* min2 = str1;
	if (strcmp_my(str2, max2) > 0) max2 = str2;
	if (strcmp_my(str3, max2) > 0) max2 = str3;
	if (strcmp_my(str4, max2) > 0) max2 = str4;

	if (strcmp_my(str2, min2) < 0) min2 = str2;
	if (strcmp_my(str3, min2) < 0) min2 = str3;
	if (strcmp_my(str4, min2) < 0) min2 = str4;

	printf("\nmin = %s", min2);
	printf("\nmax = %s", max2);
}