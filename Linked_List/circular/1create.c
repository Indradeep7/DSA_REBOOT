#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} *node;

node head = NULL, temp, current;

void create_node(int data)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;

    if (head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_node()
{
    int sno = 1;
    temp = head;
    printf("\n$-------------------\n");
    do
    {
        printf("%d. data = %d\n", sno++, temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n-------------------$\n");
}

int main()
{
    create_node(10);
    create_node(20);
    create_node(30);
    create_node(40);

    printf("List after creation:");
    print_node();

    return 0;
}
