//By: Austin Greisman
#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
	int *a;
	int top;
	int maxSize;
} Deque;

void initS(Deque *q, int size) {
	//Creating the array in malloc
	q->a = malloc(sizeof(int) * size);
	q->top = 0;
	q->maxSize = size;
	return;
}

void EnqueueHead(Deque *q, int value) {
	//I'm assuming that the head is the side you add values to the array on.
	if (q->maxSize == q->top)
	{
		//Increases maxSize by 2
		q->maxSize *= 2;
		//Creates more space in the memory
		q->a = realloc(q->a, sizeof(int) * q->maxSize);
		//Assigns the value to the top
		q->a[q->top] = value;

		q->top++;
		return;
	}

	q->a[q->top] = value;
	q->top++;
	return;
}

void DequeueTail(Deque *q) {
	//Makes sure that it's not trying to remove nothing.
	if (q->top == 0)
	{
		printf("There are no more values!\n");
		return;
	}

	//Moves everything in the array down one (Overrights the Tail)
	for (int i = 0; i < q->top; ++i)
	{
		q->a[i] = q->a[i + 1];
	}
	//Need to remove the last value
	q->top--;
	return;
}

void Print(Deque *q) {
	if (q->top == 0)
	{
		printf("There is nothing to print!\n");
		return;
	}
	//Looping through the array using the top value
	printf("Tail [");
	for (int i = 0; i < q->top; ++i)
	 {
	 	printf("%d, ", q->a[i]);
	 }
	 printf("] Head\n");
	 return;
}

int main(void) {

	Deque q;

	initS(&q, 3);

	EnqueueHead(&q, 7);
	EnqueueHead(&q, 6);
	EnqueueHead(&q, 8);
	EnqueueHead(&q, 9);

	Print(&q);

	DequeueTail(&q);

	Print(&q);

	DequeueTail(&q);
	DequeueTail(&q);

	Print(&q);

	DequeueTail(&q);
	DequeueTail(&q);

	Print(&q);


	return 0;

}