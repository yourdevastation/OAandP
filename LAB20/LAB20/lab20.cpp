#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d)->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int evenCount() {
	int cnt = 0;
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0 && ptr->data != 0) {
			cnt++;
		}
			ptr = ptr->next;
	}
	return cnt;
}

int sum() {
	int summary = 0;
	struct Node* sum = first;
	while (sum != NULL) {
		summary += sum->data;
		sum = sum->next;
	}
	return summary;
}

void oddsX10() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 == 1)
			ptr->data *= 10;
		ptr = ptr->next;
	}
}

void elementIx100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data *= 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

void elementLeftIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL && index < i) {
			ptr->data *= 10;
			index++;
			ptr = ptr->next;
	}
}

void elementRightIx10(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index > i)
			ptr->data *= 10;

		index++;
		ptr = ptr->next;
	}
}

void deleteElementI(int i) {
	if (first == NULL)
		return;
	
	if (i == 0) {
		deleteFromHead();
	}

	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int index = 1;

	while (ptr != NULL) {
		
		if (index == i) {
			prev_ptr->next = ptr->next;
			free(ptr);
			return;
		}
		prev_ptr = ptr;
		ptr = ptr->next;
		index++;
	}
}

void recursiveNode(Node* first) {

	if (first != NULL) {
		recursiveNode(first->next);
	}
		printf("NULL");
		printf(" <-(%d)", first->data);
}

void main() {
	first = NULL;
	printList();

	addToHead(10);
	printList();

	addToHead(20);
	printList();

	addToHead(30);
	printList();

	int x1 = deleteFromHead();
	printf("x1 = %d\n", x1);
	printList();

	int x2 = deleteFromHead();
	printf("x2 = %d\n", x2);
	printList();

	int x3 = deleteFromHead();
	printf("x3 = %d\n", x3);
	printList();


	addToHead(400);
	addToHead(300);
	addToHead(200);
	addToHead(100);
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));

	clearList();
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(150) = %d\n", contains(150));
	printf("contains(200) = %d\n", contains(200));

	addToHead(10);
	addToHead(20);
	addToHead(30);
	addToHead(100);
	printList();

	printf("sum = %d\n", sum());
	clearList();
	printList();
	printf("sum = %d\n", sum());

	addToHead(0);
	addToHead(1);
	addToHead(2);
	addToHead(3);
	addToHead(4);
	addToHead(5);
	addToHead(6);
	addToHead(7);
	addToHead(8);
	addToHead(9);
	printList();

	printf("even numbers = %d\n", evenCount());

	printList();
	oddsX10();
	printList();
	
	int ix100;
	printf("number of element u want to increase = ");
	scanf("%d", &ix100);

	elementIx100(ix100);
	printList();

	int leftix10;
	printf("number of element the elements to the left of which u want to increase = ");
	scanf("%d", &leftix10);

	elementLeftIx10(leftix10);
	printList();

	int rightix10;
	printf("number of element the elements to the right of which u want to increase = ");
	scanf("%d", &rightix10);

	elementRightIx10(rightix10);
	printList();

	int deli;
	printf("number of element u want to delete = ");
	scanf("%d", &deli);

	deleteElementI(deli);
	printList();
	/*recursiveNode(first);*/
}
