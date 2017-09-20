//By: Austin Greisman
#include <stdio.h>
#include <stdlib.h>

//Same header file from Question 2.
#include "LinkedListStack.h"

//Need to create the structure of a Queue. Which is basically a LinkedList
typedef struct Queue {
	LinkedList ll;
} Queue;

void initQ(Queue *q) {
	init(&(q->ll));
}

//Adds to the end of the line
void enqueue(Queue *q, int x) {
	x = (double)x;
	addFront(&(q->ll), x);

}

//Removes from the front of the line
int dequeue(Queue *q, int *res) {
	removeEnd(&(q->ll), res);
	return 0;

}

int isEmptyQueue(Queue *q) {
	if (q->ll.head->value == 0)
	{
		return 1;
	}
	return 0;
}

int main(void) {

	Queue q;

	initQ(&q);
	int x;

	if (isEmptyQueue(&q) == 1) {
		printf("The Queue is Empty!\n");
	}

	enqueue(&q, 13);
	enqueue(&q, 69);
	enqueue(&q, 96);
	enqueue(&q, 11);
	enqueue(&q, 77);

	printf("Back");
	print(&(q.ll));
	printf("Front\n");

	dequeue(&q, &x);

	printf("%d Was first in the Queue\n", x);

	printf("Back");
	print(&(q.ll));
	printf("Front\n");

	return 0;

}