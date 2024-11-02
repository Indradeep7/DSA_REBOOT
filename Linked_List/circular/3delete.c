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

void delete_beg()
{
    if (head == NULL)
        return;

    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        node to_delete = head;
        temp->next = head->next;
        head = head->next;
        free(to_delete);
    }
}

void delete_end()
{
    if (head == NULL)
        return;

    temp = head;
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    node to_delete = temp->next;
    temp->next = head;
    free(to_delete);
}

void delete_index(int pos)
{
    if (head == NULL || pos < 1)
        return;

    temp = head;
    if (pos == 1)
    {
        delete_beg();
        return;
    }

    int x = 1;
    while (x < pos - 1 && temp->next != head)
    {
        temp = temp->next;
        x++;
    }

    if (temp->next == head)
        return;

    node to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

int main()
{
    create_node(15);
    create_node(25);
    create_node(35);
    create_node(45);

    printf("Original List:");
    print_node();

    delete_beg();
    printf("After Deleting Beginning Node:");
    print_node();

    delete_index(2);
    printf("After Deleting Node at Position 2:");
    print_node();

    delete_end();
    printf("After Deleting Last Node:");
    print_node();

    return 0;
}
