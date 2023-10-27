#include <stdio.h>

#define MAX_SIZE 20

int isEmpty(int * top) {
  if ( * top == -1)
    return 1;
  return 0;
}

int isFull(int * top) {
  if ( * top >= MAX_SIZE - 1)
    return 1;
  return 0;
}

void push(int STACK[], int * top, int elem) {
  if (!isFull(top)) {
    STACK[++( * top)] = elem;
  }
}

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
