#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} *stack;

// Function to check if stack is full
int isFull(stack st)
{
    return st->top == st->size - 1;
}

// Function to check if stack is empty
int isEmpty(stack st)
{
    return st->top == -1;
}

// Function to push an element onto the stack
void push(stack st, int data)
{
    if (isFull(st))
    {
        printf("\nStack Overflow!\n");
    }
    else
    {
        st->top++;
        st->arr[st->top] = data;
        printf("\nPushed %d onto stack\n", data);
    }
}

// Function to pop an element from the stack
int pop(stack st)
{
    int deleted_data = -1;
    if (isEmpty(st))
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        deleted_data = st->arr[st->top];
        st->top--;
        printf("\nPopped %d from stack\n", deleted_data);
    }
    return deleted_data;
}

// Function to peek at an element at a specific position
int peek(stack st, int pos)
{
    //(pos,index):- (1,3) (2,2) (3,1) (4,0)
    // index = top - pos + 1
    int index = st->top - pos + 1;
    if (index < 0 || index > st->top)
    {
        printf("\nInvalid Position\n");
        return -1;
    }
    else
    {
        return st->arr[index];
    }
}

// Function to return the top element
int stack_top(stack st)
{
    if (isEmpty(st))
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    {
        return st->arr[st->top];
    }
}

// Function to display the stack elements
void stack_display(stack st)
{
    int i = st->top;
    while (i != -1)
    {
        printf("%d ", st->arr[i]);
        i--;
    }
    printf("\n");
}

int main()
{
    struct stack st;

    printf("\nEnter size of stack: ");
    scanf("%d", &st.size);

    // Allocate memory for the array of integers
    st.arr = (int *)malloc(st.size * sizeof(int));
    if (st.arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    st.top = -1; // Initialize the stack as empty

    int choice, value, position;
    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Push\t2. Pop\t3. Peek\t4. Stack Top\t5. Is Empty\t6. Is Full\t7. Display Stack\t8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&st, value);
            break;

        case 2:
            pop(&st);
            break;

        case 3:
            printf("Enter position to peek: ");
            scanf("%d", &position);
            value = peek(&st, position);
            if (value != -1)
            {
                printf("Peeked value at position %d is %d\n", position, value);
            }
            break;

        case 4:
            value = stack_top(&st);
            if (value != -1)
            {
                printf("Top element is %d\n", value);
            }
            break;

        case 5:
            if (isEmpty(&st))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;

        case 6:
            if (isFull(&st))
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;

        case 7:
            printf("Stack contents: ");
            stack_display(&st);
            break;

        case 8:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (choice != 8);

    // Free allocated memory
    free(st.arr);

    return 0;
}
