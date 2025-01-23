#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SLL_{
	int data;
	struct SLL_* next;
} SLL;

SLL* start = 0;
SLL* end = 0;

int size = 0;

void push();
int pop();
int front();
int empty();
int back();

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		char command[6];
		scanf("%s", &command);
		if (strcmp(command, "push") == 0) push();
		else if (strcmp(command, "pop") == 0) printf("%d\n", pop());
		else if (strcmp(command, "front") == 0) printf("%d\n", front());
		else if (strcmp(command, "back") == 0) printf("%d\n", back());
		else if (strcmp(command, "empty") == 0) printf("%d\n", empty());
		else printf("%d\n", size);
	}
}

void push() {
	size += 1;
	int value;
	scanf("%d", &value);
	SLL* new_node = (SLL*)malloc(sizeof(SLL));
	new_node->data = value;
	new_node->next = 0;
	if (start == 0) { start = new_node; end = new_node; }
	else {
		end->next = new_node;
		end = end->next;
	}
}

int pop() {
	if (start == 0) return -1;
	size -= 1;
	int ret_value = start->data;
	SLL* new_start = start->next;
	free(start);
	start = new_start;
	if (start == 0) end = 0;
	return ret_value;
}

int empty() {
	if (start == 0) return 1;
	else return 0;
}

int front() {
	if (start == 0) return -1;
	else return start->data;
}

int back() {
	if (end == 0) return -1;
	else return end->data;
}
