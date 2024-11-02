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

void insert_beg(int data)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
    }
    else
    {
        node temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}

void insert_end(int data)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new_node->next = head;
    temp->next = new_node;
}

void insert_index(int data, int pos)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    temp = head;
    int x = 1;

    do
    {
        temp = temp->next;
        x++;
    } while (x < pos - 1);

    new_node->next = temp->next;
    temp->next = new_node;
}

int main()
{
    create_node(100);
    create_node(200);

    insert_beg(50);
    printf("After Inserting at Beginning:");
    print_node();

    insert_end(300);
    printf("After Inserting at End:");
    print_node();

    insert_index(150, 3);
    printf("After Inserting at Position 3:");
    print_node();

    return 0;
}
