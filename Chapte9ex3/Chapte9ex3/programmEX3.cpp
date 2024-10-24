#include <stdio.h>;

int main() {

	int grade1, grade2, grade3, grade4;
	float AverageGrade, GradeDelta, percentDiff;

	grade1 = grade2 = 88;
	grade3 = 79;

	printf("Enter the 4th grade (An integer from 0 to 100) = ");
	scanf_s(" %d", &grade4);

	AverageGrade = (float)(grade1 + grade2 + grade3 + grade4) / 4;
	printf("Ur average grade is %.1f", AverageGrade);

	GradeDelta = 95 - AverageGrade;
	printf("\nUr grade is %.1f lower than the highes in the class", GradeDelta);

	percentDiff = 100 * ((95 - AverageGrade) / 95);
	printf("\nUr grade is %.1f worse than it!", percentDiff);

	return (0);
}