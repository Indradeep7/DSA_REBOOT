#include <stdio.h>
#include <stdlib.h>

// Node structure definition with `prev` and `next` pointers
typedef struct node
{
    struct node *prev; // Pointer to the previous node in the list
    int data;          // Data held by the node
    struct node *next; // Pointer to the next node in the list
} *node;

// Head of the doubly linked list
node head = NULL, temp;

// Function to create and insert a node at the end of the doubly linked list
void create_node(int data)
{
    // Allocate memory for the new node and set data
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    // Case 1: Empty list, new node becomes the head
    if (head == NULL)
    {
        head = new_node;
        new_node->prev = NULL;
    }
    // Case 2: Traverse to end and insert new node
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node->prev = temp;
        temp->next = new_node;
    }
}

// Function to insert a node at the beginning of the doubly linked list
void insert_beg(int data)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    // Case 1: Empty list, new node becomes the head
    if (head == NULL)
    {
        head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    // Case 2: Link the new node at the start
    else
    {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    }
}

// Function to insert a node at a specific position
void insert_index(int data, int pos)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    // Invalid position check
    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // Insert at beginning if pos = 1
    if (pos == 1)
    {
        insert_beg(data);
        return;
    }

    // Empty list case
    if (head == NULL)
    {
        head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    else
    {
        temp = head;
        int x = 1;

        // Traverse to node before target position
        while (temp->next != NULL && x < pos - 1)
        {
            temp = temp->next;
            x++;
        }

        // Insert the new node
        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;

        // Update the prev pointer of the next node, if it exists
        if (new_node->next != NULL)
        {
            new_node->next->prev = new_node;
        }
    }
}

// Function to delete the first node (beginning of the list)
void delete_beg()
{
    if (head == NULL)
    { // Empty list check
        return;
    }
    else
    {
        node to_delete = head;
        head = head->next;

        // Update head's prev if the list is not empty now
        if (head != NULL)
        {
            head->prev = NULL;
        }

        free(to_delete); // Free the removed node
    }
}

// Function to delete a node at a specific position
void delete_index(int pos)
{
    // Empty list or invalid position check
    if (head == NULL || pos < 1)
    {
        return;
    }

    // Special case for deleting the head
    if (pos == 1)
    {
        delete_beg();
        return;
    }

    temp = head;
    int x = 1;

    // Traverse to node before target position
    while (temp->next != NULL && x < pos - 1)
    {
        temp = temp->next;
        x++;
    }

    // Position is out of bounds
    if (temp->next == NULL)
    {
        return;
    }

    // Standard deletion
    node to_delete = temp->next;
    temp->next = to_delete->next;

    // Update the prev pointer if not deleting the last node
    if (to_delete->next != NULL)
    {
        to_delete->next->prev = temp;
    }

    free(to_delete); // Free the removed node
}

// Function to delete the last node (end of the list)
void delete_end()
{
    if (head == NULL)
    { // Empty list
        return;
    }

    if (head->next == NULL)
    { // Only one node
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        // Traverse to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Adjust the previous node's next pointer to NULL
        temp->prev->next = NULL;

        free(temp); // Free the last node
    }
}

// Iterative function to reverse the doubly linked list
void reverse_node_iterative()
{
    node current = head;
    node temp = NULL;

    // Traverse through the list and swap `next` and `prev` for each node
    while (current != NULL)
    {
        // Swap `next` and `prev` pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (originally the previous one due to swapping)
        current = current->prev;
    }

    // Adjust head to point to the new front of the list
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

// Recursive function to reverse the doubly linked list
node reverse_node_recursive(node current)
{
    // Base case: end of list
    if (current == NULL || current->next == NULL)
    {
        return current;
    }

    // Recursive call
    node new_head = reverse_node(current->next);

    // Reverse the links
    current->next->next = current;
    current->prev = current->next;
    current->next = NULL;

    // Update head's prev pointer
    new_head->prev = NULL;

    return new_head;
}

// Function to print all nodes in the list
void print_node()
{
    if (head == NULL)
    { // Empty list check
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
}

int main()
{
    // Create initial nodes and print the list
    printf("\n\nInitial creation of nodes:\n");
    create_node(5);
    create_node(7);
    create_node(6);
    print_node();

    // Insert at the beginning and print the list
    printf("\n\nInsert 18 at the beginning:\n");
    insert_beg(18);
    print_node();

    // Insert at a specific index (position 4 in this case) and print the list
    printf("\n\nInsert 45 at position 4:\n");
    insert_index(45, 4);
    print_node();

    // Delete a node at a specific position (position 4 in this case) and print the list
    printf("\n\nDelete node at position 4:\n");
    delete_index(4);
    print_node();

    // Delete the first node and print the list
    printf("\n\nDelete the first node:\n");
    delete_beg();
    print_node();

    // Delete the last node and print the list
    printf("\n\nDelete the last node:\n");
    delete_end();
    print_node();

    // Insert new nodes at the end to reset the list to a few items and print
    printf("\n\nInsert 10, 20, and 30 at the end:\n");
    create_node(10);
    create_node(20);
    create_node(30);
    print_node();

    // Reverse and print the list
    printf("\n\nReverse Doubly LL\n");
    head = reverse_node_recursive(head); // Reverse the list and update head
    print_node();

    return 0;
}
