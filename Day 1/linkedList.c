#include <stdio.h>
#include <stdlib.h> // for using malloc()

struct node
{
    int data;          // datafield, can have values for int, char etc
    struct node *next; // stores the pointer to next node
} *head, *new, *ptr;

void createNode(int value) // to create a node in memory
{
    new = malloc(sizeof(struct node)); // allocates memory required for a node
    new->data = value;                 // assigning parameter passed in function as value of node's data field
    new->next = NULL;                  // initializing next pointer with NULL value
}

void insertFront(int value)
{
    createNode(value); // calling createNode() for creating a node
    if (head != NULL)  // head is empty or not, only executes if block when head is not empty
    {
        new->next = head; // for pointing new node's next to initial head
    }
    head = new; // setting linkedlist head as new
}

void display()
{
    printf("Linked List -->  ");
    ptr = head;         // setting pointer to linked list head
    while (ptr != NULL) // if pointer is not empty
    {
        printf("%d\t", ptr->data); // printing data value
        ptr = ptr->next;           // ptr becomes value stored in current ptr's next field
    }
}

void main()
{
    insertFront(50); // inserting 50
    insertFront(40); // 40 --> 50
    insertFront(30); // 30 --> 40 --> 50
    insertFront(20); // 20 --> 30 --> 40 --> 50
    insertFront(10); // 10 --> 20 --> 30 --> 40 --> 50
    display();       // print linked list to terminal
}