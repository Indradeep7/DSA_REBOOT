#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// *node helps to declare a node as a pointer directly, which simplifies working with linked lists where nodes are dynamically allocated.

typedef struct node
{
    int data;
    struct node *next;
} *node;

node head, temp, current;

void create_node(int data)
{
    node new_node = NULL;
    new_node = (node)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_node()
{
    temp = head;
    printf("\n$-------------------\n");
    while (temp != NULL)
    {
        printf("data = %d\n", temp->data);
        temp = temp->next;
    }
    printf("\n-------------------$\n");
}

bool check_loop()
{
    current = head;
    temp = head;
    while (temp && temp->next)
    {
        current = current->next;
        temp = temp->next->next;

        if (current == temp)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    create_node(45);
    create_node(55);
    create_node(60);
    create_node(70);
    create_node(69);
    print_node();

    bool flag = check_loop();
    printf("Loop in node: %s", flag ? "true" : "false");

    return 0;
}