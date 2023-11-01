#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist { 
		int data;
		struct linkedlist *next; 
	} node;

node *head = NULL;
node *prev = NULL;
node *new = NULL; 
node *ptr = NULL;

void create( int data) {
// Create a new node add data and set next part to NULL
	new = malloc(sizeof(node));
	new->data = data;
	new->next = NULL;
	
// if head == null (empty ll) then head = new node 
	if(head == NULL) {
		prev = new;
		head = new;
	} 
	else {
		prev->next = new;
		prev = new;
	}
}

void deleteFront() {
// check for ll or not
	if(head == NULL) {
		printf("No Nodes Found\n");
	} // delete first element
	else if (head != NULL && head->next != NULL) {
		head = head->next;
	}
	else if (head->next == NULL) {
		printf("Single Node Detected and Deleted....\n");
		head = NULL;
	} 
	else {
		return;
	}
}

void deleteEnd() {

	if (head == NULL) {
		printf("No Nodes To Delete\n");
	}
	else if(head->next != NULL) {
		ptr = head;
		while(ptr->next != NULL) {
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
	} 
	else {
		deleteFront();
	}
}

void deleteany(int target) {

}

void display() {
	if(head != NULL) {
		ptr = head;
	} else {
		printf("No Nodes TO Delete;");
	}
	printf("***** LINKED LIST *****\n");
	while(ptr != NULL) {
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void main() {
	create(1);
	create(11);
	create(111);
	create(1111);
	display();
	
	display();
}
