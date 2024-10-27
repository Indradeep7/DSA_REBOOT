#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// *node helps to declare a node as a pointer directly, which simplifies working with linked lists where nodes are dynamically allocated.

typedef struct node
{
    int data;
    struct node *next;
} *node;

node head = NULL, temp, current;

void create_node(int data)
{
    node new_node = NULL;
    new_node = (node)malloc(sizeof(struct node));
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
        new_node->next = head;
    }
}

void print_node()
{
    temp = head;
    printf("\n$-------------------\n");
    do
    {
        printf("data = %d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n-------------------$\n");
}

void insert_index(int data, int pos)
{

    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

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

int main()
{
    create_node(45);
    create_node(55);
    insert_index(60, 3);
    // create_node(60);
    create_node(70);
    // create_node(69);
    insert_index(69, 5);

    insert_beg(420);
    print_node();

    return 0;
}