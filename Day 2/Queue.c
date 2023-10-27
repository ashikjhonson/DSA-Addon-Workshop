#include<stdio.h>

#define MAX_SIZE 10 // we set the queue size to 10 (maximum)

int QUEUE[MAX_SIZE];
int front = -1;
int rear = -1;

//front and rear are global

// Check is QUEUE is Empty
int isEmpty() {
  // if front and rear are -1 then no element were inserted
  if (front == -1 && rear == -1) {
    return 1; // is EMPTY
  } else
    return 0; // Not Empty
}

// Check is QUEUE is Full

int isFull() {
  // if rearis equal to max size then we hit limit and queue is full
  if (rear == MAX_SIZE - 1) {
    printf("QUEUE Full!!! \n");
    return 1; // FULL
  } else
    return 0;

}
// ADD elements to QUEUE

int Enqueue(int element) {
  // 1 check if queue is full
  if (!isFull()) {
    // check if element is being inserted for the first time
    if (rear == -1 && front == -1) {
      rear++;
      front++;
      QUEUE[rear] = element;
      printf("ADDED f = %d b = %d elem = %d \n", front, rear, QUEUE[rear]);
    }
    // if not then append to end of array
    else {
      QUEUE[++rear] = element;
      printf("ADDED f = %d b = %d elem = %d \n", front, rear, QUEUE[rear]);
    }
  }
}

// DELETE elements from QUEUE
int Dequeue() {
  if (!isEmpty()) {
    // check if queue is empty then no dequeue
    if (front == -1 && rear == -1) {
      printf("QUEUE EMPTY!! \n");
    }
    // only one element can be present so front == rear 
    else if (front == rear) {
      printf("DELETED = %d b = %d elem = %d \n", front, rear, QUEUE[front]);
      front = 0;
      rear = 0;
    } else {
      printf("DELETED f = %d b = %d elem = %d \n", front, rear, QUEUE[front]);
      front++;
    }

  }

}
// DISPLAY THE QUEUE
void display() {
  if (front == -1 && rear == -1)
    printf("EMPTY!!/n");
  else {
    // queue if from front to rear so we display those contents
    for (int i = front; i <= rear; i++) {
      printf("ELEMENT at %d : %d\n", front++, QUEUE[i]);
    }
  }

}

int main() {
  Enqueue(10);
  Enqueue(440);
  Enqueue(26);
  Enqueue(27);
  Enqueue(208);
  Enqueue(233);
  Enqueue(201);
  Enqueue(20);
  Enqueue(0);
  Enqueue(4);
  Enqueue(10);
  Enqueue(90);
  Enqueue(40);
  Enqueue(20);
  Enqueue(30);
  Dequeue();
  Dequeue();
  Dequeue();
  Dequeue();
  display();
}
