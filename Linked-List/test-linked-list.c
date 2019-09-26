#include "linked-list.h"
#include "test-linked-list.h"
#include <stdlib.h>
#include <assert.h>

void testLength() {
	struct Node *head1 = createList(15);
	struct Node *head2 = createList(0);
	struct Node *head3 = createList(-1);
	
	assert(listLen(head1) == 15);
	assert(listLen(head2) == 0);
	assert(listLen(head3) == 0);
	
	deleteList(head1);
	deleteList(head2);
	deleteList(head3);
}

void testPtr() {
	struct Node *node = createNode();
	struct Node *head = node;
	
	int *data = node->data;
	*(data) = 5;
	
	assert(head == node);
	assert(*(head->data) == *(node->data));
}

void testInitDeinit() {
	struct Node *head = createList(10);
	
	deleteList(head);
	
	assert(head != NULL);
}
