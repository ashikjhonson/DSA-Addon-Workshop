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

void insertAfterPos(int key, int data) // Function to Insert a node after specified node
{
    ptr = head;
    if (ptr != NULL) // only if linked list is not empty, we can add items with it.
    {
        while (ptr->next) // current ptr->next is not a NULL
        {
            if (ptr->data == key) // searching match for key in existing linked list
                break;            // if found break loop
            ptr = ptr->next;      // iterating linkedlist
        }
        if (ptr->data != key) // there is no match for key in LL
        {
            printf("Key not found\n");
            return; // return from this function()
        }
        createNode(data);      // if there is a match, create a node for it.
        new->next = ptr->next; // new node's next becomes current ptr's next
        ptr->next = new;       // current ptr's next stores address of new node.
    }
    else
    {
        printf("\nEmpty, try inserting some values first.\n"); // the LL is empty
    }
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
    insertFront(50);        // inserting 50
    insertFront(40);        // 40 --> 50
    insertFront(30);        // 30 --> 40 --> 50
    insertFront(20);        // 20 --> 30 --> 40 --> 50
    insertFront(10);        // 10 --> 20 --> 30 --> 40 --> 50
    insertAfterPos(50, 60); // 10 --> 20 --> 30 --> 40 --> 50 --> 60
    insertAfterPos(10, 15); // 10 --> 15 --> 20 --> 30 --> 40 --> 50 --> 60
    display();              // print linked list to terminal
}