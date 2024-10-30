#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// *node helps to declare a node as a pointer directly, which simplifies working with circular linked lists where nodes are dynamically allocated.

typedef struct node
{
    int data;          // Holds the data for each node
    struct node *next; // Pointer to the next node in the circular linked list
} *node;

node head = NULL, temp, current; // Global pointers for the head, temp, and current nodes

// Function to create a new node and add it at the end of the circular linked list
void create_node(int data)
{
    node new_node = NULL;
    new_node = (node)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = data;
    new_node->next = head; // New node points to head to maintain the circular structure

    if (head == NULL) // Case for an empty list
    {
        head = new_node;
        new_node->next = head; // Point to itself to make it circular
    }
    else // Case for a non-empty list
    {
        current = head;
        while (current->next != head) // Traverse to the last node
        {
            current = current->next;
        }
        current->next = new_node; // Last node points to the new node
        new_node->next = head;    // New node points to head
    }
}

// Function to print all nodes in the circular linked list starting from the head
void print_node()
{
    int sno = 1;
    temp = head;
    printf("\n$-------------------\n");
    do
    {
        printf("%d. data = %d\n", sno++, temp->data); // Print the data in the current node
        temp = temp->next;                            // Move to the next node
    } while (temp != head); // Continue until we reach the head node again
    printf("\n-------------------$\n");
}

// Function to insert a new node at a specific position in the circular linked list
void insert_index(int data, int pos)
{
    node new_node = (node)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = data;
    new_node->next = NULL;

    temp = head;
    int x = 1;

    // Traverse to the node before the target position
    do
    {
        temp = temp->next;
        x++;
    } while (x < pos - 1);

    // Insert the new node at the specified position
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to insert a new node at the beginning of the circular linked list
void insert_beg(int data)
{
    node new_node = (node)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = data;

    // Case for an empty list
    if (head == NULL)
    {
        new_node->next = new_node; // Point to itself to make it circular
        head = new_node;
    }
    else // Case for a non-empty list
    {
        node temp = head;
        while (temp->next != head) // Traverse to the last node
        {
            temp = temp->next;
        }

        // Insert the new node at the beginning
        new_node->next = head; // New node points to the current head
        temp->next = new_node; // Last node points to the new node
        head = new_node;       // Update head to the new node
    }
}

// Function to insert a new node at the end of the circular linked list
void insert_end(int data)
{
    node new_node = (node)malloc(sizeof(struct node)); // Allocate memory for the new node
    new_node->data = data;

    temp = head;
    while (temp->next != head) // Traverse to the last node
    {
        temp = temp->next;
    }
    // Insert the new node at the end
    new_node->next = head; // New node points to head
    temp->next = new_node; // Last node points to the new node
}

// Function to delete the first node of the circular linked list
void delete_beg()
{
    if (head == NULL)
        return; // Empty list, nothing to delete

    if (head->next == head) // Only one node in the list
    {
        free(head);
        head = NULL;
    }
    else // More than one node
    {
        temp = head;
        while (temp->next != head) // Traverse to the last node
        {
            temp = temp->next;
        }

        node to_delete = head;
        temp->next = head->next; // Last node now points to the second node
        head = head->next;       // Update head to the next node
        free(to_delete);         // Free the old head
    }
}

// Function to delete a node at a specific index in the circular linked list
void delete_index(int pos)
{
    if (head == NULL || pos < 1)
        return; // Check for empty list or invalid position

    temp = head;
    if (pos == 1) // Special case for deleting the first node
    {
        delete_beg();
        return;
    }

    int x = 1;
    while (x < pos - 1 && temp->next != head) // Traverse to the node before the target position
    {
        temp = temp->next;
        x++;
    }

    if (temp->next == head)
        return; // Position out of bounds

    // Store the node to delete in a temporary pointer
    node to_delete = temp->next;  // The node to delete
    temp->next = to_delete->next; // Update link to skip the deleted node
    free(to_delete);              // Free the memory for the deleted node
}

// Function to delete the last node in the circular linked list
void delete_end()
{
    if (head == NULL)
        return; // Empty list, nothing to delete

    temp = head;
    if (head->next == head) // Only one node in the list
    {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next->next != head) // Traverse to the second-last node
    {
        temp = temp->next;
    }

    node to_delete = temp->next; // The last node
    temp->next = head;           // Update the second-last node to point to head
    free(to_delete);             // Free the memory for the last node
}

int main()
{
    create_node(45); // Create initial nodes
    create_node(55);
    insert_index(60, 3); // Insert at a specific index
    create_node(70);
    insert_index(69, 5); // Insert at another specific index

    insert_beg(420); // Insert at the beginning
    insert_end(7);   // Insert at the end

    printf("Original List:");
    print_node(); // Print the entire circular linked list

    delete_beg(); // Delete the beginning node
    printf("After Deleting Beginning Node:");
    print_node();

    delete_index(3); // Delete node at position 3
    printf("After Deleting Node at Position 3:");
    print_node();

    delete_end(); // Delete the last node
    printf("After Deleting Last Node:");
    print_node();

    return 0;
}
