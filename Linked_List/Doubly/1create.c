#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *node;

node head = NULL, temp;

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
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        new_node->prev = temp;
        temp->next = new_node;
    }
}

void print_node()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int sno = 65;
    temp = head;
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
    create_node(5);
    create_node(7);
    create_node(6);
    print_node();

    return 0;
}
