#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

struct Node {
    int *data;
    struct Node *next;
	struct Node *prev;
};

struct LinkedList {
  	struct Node *head;
  	struct Node *tail;
};

struct Node* createNode() {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node*));
	node->data = (int*)malloc(sizeof(int));
	node->next = NULL;
	node->prev = NULL;
	
	return node;
}

void freeNode(struct Node *node) {
	free(node->data);
	free(node);
}

void deleteNode(struct Node *node) {
	if(node == NULL) { return; }
	
	if(node->prev != NULL) {
		node->prev->next = node->next;
	}
	if(node->next != NULL) {
		node->next->prev = node->prev;
	}
	
	freeNode(node);
}

void deleteList(struct Node *node) {
	if(node == NULL) { return; }
	
	struct Node *next;
	
	while(node != NULL) {
		next = node->next;
		deleteNode(node);
		node = next;
	}
}

void printList(struct Node *head) {
	struct Node *curr = head;
	
	while(curr != NULL) {
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
		curr->prev = prev;
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

void testInitDeinit() {
	struct Node *head = dummyData();
	
	deleteList(head);
}

int main(void) {

//	testPtr();
	testInitDeinit();
  	return 0;
}
