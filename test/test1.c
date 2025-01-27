#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int top;
    int *arr;
    int size;
} *stack;

bool isfull(stack st) {
    return st->top == st->size - 1;
}

bool isempty(stack st) {
    return st->top == -1;
}

void push(stack st,int data) {

    if(isfull(st)) {
        printf("Stack OverFlow\n");
    }
    else {
        st->top++;
        st->arr[st->top] = data;
        printf("\nPushed %d onto stack\n", data);
    }

}
int pop(stack st) {
    int pop_data;
    if (isempty(st)) {
        printf("\nStack Underflow\n");
    }
    else {
        pop_data = st->arr[st->top];
        st->top--;
    }
    return pop_data;
}

void display(stack st) {

    int i = st->top;

    while(i != -1) {
        printf("st->arr[i] = %d",st->arr[i]);
        i--;
    }
    printf("\n");

}

int main() {

    stack st;
    printf("Enter Size of the stack:\n");
    scanf("%d",&st->size);

    st->arr = (int*) malloc(st->size * sizeof(int));
    st->top = -1;

    push(st,5);
    push(st,4);
    push(st,7);
    display(st);

}