#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *node;

node head = NULL;

void create_node(int data)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        node temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }
}

void reverse_iterative()
{
    node current = head;
    node temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
}

node reverse_recursive(node current)
{
    if (current == NULL || current->next == NULL)
        return current;

    node new_head = reverse_recursive(current->next);

    current->next->next = current;
    current->prev = current->next;
    current->next = NULL;

    return new_head;
}

void print_node()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node temp = head;
    int sno = 65;
    while (temp != NULL)
    {
        printf("%c. data = %d\t", sno, temp->data);
        temp = temp->next;
        sno++;
    }
    printf("\n");
}

int main()
{
    printf("\n\nInitial creation of nodes:\n");
    create_node(5);
    create_node(7);
    create_node(6);
    print_node();

    printf("\n\nReverse Doubly Linked List (Iterative):\n");
    reverse_iterative();
    print_node();

    printf("\n\nReverse Doubly Linked List (Recursive):\n");
    head = reverse_recursive(head);
    print_node();

    return 0;
}
