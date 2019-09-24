#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
  int *data;
  struct Node *next;  
};

struct LinkedList {
  struct Node *head;
  struct Node *tail; 
};

struct Node* createNode() {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node*));
	node->data = (int*)malloc(sizeof(int));
	node->next = NULL;
	
	return node;
}

void freeNode(struct Node *node) {
	free(node->data);
	free(node);
}

void printList(struct Node *head) {
	struct Node *curr = head;
	
	while(curr != NULL) {
		printf("*(curr->data): %d\n", *(curr->data));
		curr = curr->next;
	}
}

struct Node* dummyData() {
	struct Node *head = NULL;
  	struct Node *curr = NULL;
  	struct Node *prev = NULL;
  	int i;
  
  	for (i = 0; i < 10; i++) {
  		curr = (struct Node*)malloc(sizeof(struct Node));
		curr->data = (int*)malloc(sizeof(int));
  		*(curr->data) = i;

		if(prev != NULL) {
  			prev->next = curr;
  		}
		if(i == 0) {
			head = curr;
		}
  		prev = curr;
  	}
	
  	return head;
}

void testPtr() {
	struct Node *node = createNode();
	struct Node *head = node;

	*(node->data) = 5;
	
	assert(head == node);
	assert(*(head->data) == *(node->data));
}

int main(void) {

	testPtr();
	struct Node *head = dummyData();
	printList(head);
	
  	return 0;
}
