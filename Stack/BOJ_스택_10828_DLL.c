/*
  https://www.acmicpc.net/problem/10828
  https://www.acmicpc.net/source/88995123
  구조체를 활용하여 구현한 스택
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* head = 0;

int size = 0;

void push();
int pop();
int top();
int empty();

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		char command[6];
		scanf("%s", &command);
		if (strcmp(command, "push") == 0) push();
		else if (strcmp(command, "pop") == 0) printf("%d\n", pop());
		else if (strcmp(command, "top") == 0) printf("%d\n", top());
		else if (strcmp(command, "empty") == 0) printf("%d\n", empty());
		else printf("%d\n", size);
	}
}

void push() {
	size += 1;
	int value;
	scanf("%d", &value);
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = value;
	new_node->left = 0;
	new_node->right = 0;
	if (head == 0) head = new_node;
	else {
		head->right = new_node;
		new_node->left = head;
		head = head->right;

	}
}

int pop() {
	if (head == 0) return -1;
	size -= 1;
	int ret_value = head->data;
	if (head->left == 0) { free(head); head = 0; }
	else { head = head->left; free(head->right); }
	return ret_value;
}

int empty() {
	if (head == 0) return 1;
	else return 0;
}

int top() {
	if (head == 0) return -1;
	else return head->data;
}
