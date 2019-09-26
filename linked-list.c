#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "linked-list.h"


struct Node* createNode() {
	struct Node *node = (struct Node*)malloc(sizeof(struct Node*));
	node->data = (int*)malloc(sizeof(int));
	node->next = NULL;
	node->prev = NULL;
	
	return node;
}
void insertNode(struct Node *place, struct Node *node) {
	if(place == NULL) { return; }
	
	if(place->prev != NULL) {
		place->prev->next = node;
	}
	
	place->prev = node;
}

void insertNodeAtIndex(struct Node *head, struct Node *node, int index) {
	struct Node *curr = node;
	
	while(curr != NULL) {
		if(index == 0) {
			// place node
			insertNode(curr,node);
		}
		
		index--;
	}
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

int listLen(struct Node *node) {
	int count = 0;
	struct Node *curr = node;
	
	while(curr != NULL) {
		count++;
		curr = curr->next;
	}

	return count;
}

void printList(struct Node *head) {
	struct Node *curr = head;
	
	while(curr != NULL) {
		curr = curr->next;
	}
}

struct Node* createList(int size) {
	if(size <= 0) { return NULL; }
	
	struct Node *head = NULL;
  	struct Node *curr = NULL;
  	struct Node *prev = NULL;
  	int i;
  
  	for (i = 0; i < size; i++) {
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
