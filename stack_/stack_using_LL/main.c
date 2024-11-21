// stack using LL
// we need:
// An array, Size of that Array, Top pointer pointing to the topmost/recently inserted element
// we insert elements from the left side of the LL as its O(1) or else O(n)
// Therefore, Only Insert_beg()
// If stack Empty, top = NULL
// If stack Full,  Heap is full(no further creation of any node)
// Therefore,
//          node n1 = (node)malloc(sizeof(struct node));
//          (n1 == NULL) ---------> True

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} *node;

node top = NULL;

void push(int data)
{
    node t = (node)malloc(sizeof(struct node));
    if (t == NULL) // If no node is created
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        t->data = data;
        t->next = top;
        top = t;
        printf("Pushed %d onto stack\n", data);
    }
}

int pop()
{
    node pop_node = NULL;
    int pop_data = -1;
    if (top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        pop_node = top;
        top = top->next;
        pop_data = pop_node->data;
        free(pop_node);
        printf("Popped %d from stack\n", pop_data);
    }
    return pop_data;
}

int peek(int pos)
{
    node peek_node = top;
    int i = 0;
    while (peek_node != NULL && i < pos - 1)
    {
        peek_node = peek_node->next;
        i++;
    }
    if (peek_node != NULL)
    {
        return peek_node->data;
    }
    else
    {
        return -1;
    }
}

int stack_top()
{
    if (top)
    {
        return top->data;
    }
    return -1;
}

int isEmpty()
{
    return top == NULL ? 1 : 0;
}

int isFull()
{
    node test_node = (node)malloc(sizeof(struct node));
    int x = test_node ? 1 : 0;
    free(test_node);
    return !x;
}

void display()
{
    node temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value, position;

    do
    {
        printf("\nStack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Check if Stack is Empty\n");
        printf("6. Check if Stack is Full\n");
        printf("7. Display Top Element\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Enter position to peek: ");
            scanf("%d", &position);
            value = peek(position);
            if (value != -1)
                printf("Element at position %d is %d\n", position, value);
            else
                printf("Invalid position\n");
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
            break;
        case 6:
            printf("Is stack full? %s\n", isFull() ? "Yes" : "No");
            break;
        case 7:
            value = stack_top();
            if (value != -1)
                printf("Top element is %d\n", value);
            else
                printf("Stack is empty\n");
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
