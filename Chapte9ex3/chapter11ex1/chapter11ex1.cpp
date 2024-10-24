#include <stdio.h>
#define CURRENTYEAR 2024

int main() {

	int yearBorn, age;

	printf("What year were u born?\n");
	scanf_s(" %d", &yearBorn);

	if (yearBorn > CURRENTYEAR) {
		printf("Really? Have u not been born yet?");
		printf("\nWould u like to enter another year?");
		printf("What year were u born?\n");
		scanf_s(" %d", &yearBorn);
	}
	age = CURRENTYEAR - yearBorn;
	printf("U'll be %d years old this year!", age);

	if (yearBorn % 4 == 0) {
		printf("\nCongratulations! U were born in a leap year!");
	}
	return 0;

}