#include <stdio.h>

#define MAX_SIZE 20

/* a function 
 * ex: int push(int STACK[], int *top) { }
 *int STACK[] has address of stack (arrays can be passed without pointers)
 * here *top is the address of top that is defiend in main function
 * keep this in mind
 * */

// check if stack is empty by checking if top == -1
// 1 indicate true, 0 false
int isEmpty(int * top) {
  if ( * top == -1)
    return 1;
  return 0;
}

// check if stack is full by checking if top == max size or > maz size
//1: true 0 false
int isFull(int * top) {
  if ( * top >= MAX_SIZE - 1)
    return 1;
  return 0;
}

/*
 * if(1) {
 *	if 1 means it is true and if block executes 
 *	if (!isFull(top)) means is there space to insert 
 *	! makes the output flipped is isFull returns 0 (nor full) then flipped to 1 makes the if block run
 *	and thereby inserting an element at top
 *	top is incremented and data is inserted
 * } */
void push(int STACK[], int * top, int elem) {
  if (!isFull(top)) {
    STACK[++( * top)] = elem;
  }
}

/* check if stack is empty or not
 * if stack is Empty() meaning it returns 1 we flip to 0 then we cant pop 
 * else isEmpty() returns 0 meaning stack is is not empty we can pop an element
 * while popping top element is stored to item variable for returing 
 * then top in decremented by 1
 * */
int pop(int STACK[], int * top) {
  int item;
  if (!isEmpty(top)) {
    item = STACK[( * top) --];
    return item;
  }
  return 0;
}

int main() {
  int top = -1;
  int STACK[MAX_SIZE];
  push(STACK, & top, 1);
  printf("%d\n", pop(STACK, & top));
  return 0;
}
