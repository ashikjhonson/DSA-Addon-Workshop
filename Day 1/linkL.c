#include <stdio.h>
#include <stdlib.h> // contains functions like sizeof(), free(), malloc(), calloc()

typedef struct LL {
    int data;
    struct LL* next;
} node; // creates a structure named node 

int main() {

	node* head = NULL; //creates a variable head to store starting address of linked list 
	node* prev = NULL; // used to store address of previous node for linking logic

    int num;
    printf("***** LINKED LIST *****\n\n Enter Number Of nodes: ");
    scanf("%d",&num);
    int i = 0;
    // read data n number of times
    while (i<num) {

        int data = 0;
        printf("Enter Data: ");
        scanf("%d",&data);

        node* new = (node*) malloc(sizeof(node)); // creates a new node and return address is stored into variable new
        
	if(head == NULL) {
		/* first condition where no nodes are present then head will be NULL
		   	1 - create a new node	
		   	2 - set head as new nodes address
		   	3 - set previous as head (to trace back to the last address)
		   	4 - set data to new->data and new-> next is set to NULL*/

            new->data = data;
            new->next = NULL;
            head = new;
            prev = new;

        } 
	else {
		/* here a node is present so the old node (prev) has its next part null
		 we already saved the prev node address as prev, we now use it to alloacte prev->next to new 
		 thereby linking them.
		   1 - previous nodes next is set to new
		   2 - data and next of new is set or inserted 
		   3 - prev is set to new making newest node the previous node when a new node is inserted*/

            prev->next = new;
            new->data = data;
            new->next = NULL;
            prev = new;

        }
        i++;
    }

	/* A temporary variable temp is made this is to store the head address, 
	 * this is do so because if we loose the head address the linklist is unusable 
	 * so to traverse a linked list we copy head address to temp
 	* now temp is checked if it is NULL if not we increment temp to temp->next
 	* when temp is  NULL the list is over*/

    node * temp = head;
    while( temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
