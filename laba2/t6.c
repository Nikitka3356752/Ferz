#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 20
#define STACK_OVERFLOW  -100
 
typedef int T;

typedef struct Stack_tag {
    T data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;

void push(Stack_t *stack, const T value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}

T pop(Stack_t *stack) {
    if (stack->size == 0) {
        exit(0);
    }
    stack->size--;
    return stack->data[stack->size];
}

void printStack(const Stack_t *stack, void (*peek)(const T)) {
    int i;
    int len = stack->size - 1;
    printf("stack %ld > ", stack->size);
    for (i = 0; i < len; i++) {
        peek(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0) {
        peek(stack->data[i]);
    }
    printf("\n");
}

void peek(const T value) {
    printf("%d", value);
}

void main() {
    Stack_t stack;
    stack.size = 0;
 
    push(&stack, 3);
    printStack(&stack, peek);

    // push(&stack, 5);
    // printStack(&stack, peek);
    
    // push(&stack, 7);
    // printStack(&stack, peek);
    
    // printf("%d\n", pop(&stack));
    // printf("%d\n", pop(&stack));

    // printStack(&stack, peek);
    printf("%d\n",pop(&stack));
    printf("%d\n",pop(&stack));
    push(&stack, 3);
   
}