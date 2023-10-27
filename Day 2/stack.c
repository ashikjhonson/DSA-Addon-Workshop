#include <stdio.h>
int stack[10], top = -1, size; // initially top doesn't exist, so equals -1

void display()
{
    if (top > -1) // checks whether stack is not empty
    {
        printf("\n");
        for (int i = top; i >= 0; i--) // looping through elements
            printf("%d\t", stack[i]);
    }
    else
        printf("Stack Empty");
}

void push(int data)
{
    if (top < size - 1) // checking for stack overflow
    {
        stack[++top] = data; // insert at top & incrementing top value
        display();
    }
    else
        printf("Stack overflow\n");
}

void pop()
{
    if (top > -1)                             // checking whether there is any element to pop in stack
        printf("\n%d Removed", stack[top--]); // decrementing top value
    else
        printf("Stack underflow\n");
}

void main()
{
    int c = 0, d;
    printf("Enter stack size: "); // reading stack size
    scanf("%d", &size);
    push(10); // stack top here --> [10]
    push(20); // stack top here --> [20, 10]
    push(30); // stack top here --> [30, 20, 10]
    pop();    // stack top here --> [20, 10]
    pop();    // stack top here --> [10]
    push(40); // stack top here --> [40, 10]
}