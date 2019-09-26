#ifndef _linked_list_h
#define _linked_list_h

struct Node* createNode();
void insertNode(struct Node *place, struct Node *node);
void insertNodeAtIndex(struct Node *head, struct Node *node, int index);
void freeNode(struct Node *node);
void deleteNode(struct Node *node);
void deleteList(struct Node *node);
int listLen(struct Node *node);
void printList(struct Node *head);
struct Node* createList(int size);

struct Node {
	int *data;
	struct Node *next;
	struct Node *prev;
};

struct LinkedList {
	struct Node *head;
	struct Node *tail;
};

#endif
