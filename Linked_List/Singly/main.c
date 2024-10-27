#include <stdio.h>
#include <stdlib.h>

// *node helps to declare a node as a pointer directly, which simplifies working with linked lists where nodes are dynamically allocated.

typedef struct node
{
    int data;
    struct node *next;
} *node;

// Global pointers for the head, temporary, and current nodes in the list.
node head = NULL, temp, current;

// Function to create a new node and add it at the end of the list.
void create_node(int data) {
    node new_node = NULL;
    new_node = (node)malloc(sizeof(struct node));  // Allocate memory for the new node
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {  // If list is empty, set new_node as head
        head = new_node;
    } else {  // Traverse to the end and link new_node
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print all nodes in the list from head to the end.
void print_node() {
    temp = head;
    printf("\n$-------------------\n");
    while (temp != NULL) {  // Traverse until the end
        printf("data = %d\n", temp->data);
        temp = temp->next;
    }
    printf("\n-------------------$\n");
}

// Function to insert a new node at the beginning of the list.
void insert_beg(int data) {
    node new_node = NULL;
    new_node = (node)malloc(sizeof(struct node));  // Allocate memory for new node
    new_node->data = data;
    new_node->next = head;  // Link new_node to the head
    head = new_node;         // Update head to new_node
}

// Function to insert a node at a specific position in the list.
void insert_index(int data, int position) {
    node new_node = NULL;
    new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    current = head;
    position--;  // Adjust for zero-based index
    while (--position) {  // Traverse to the node before the target position
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

// Function to insert a node at the end of the list.
void insert_end(int data) {
    node new_node = NULL;
    new_node = (node)malloc(sizeof(struct node));  // Allocate memory for new node
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {  // If list is empty, set new_node as head
        head = new_node;
    } else {
        current = head;
        while (current->next != NULL) {  // Traverse to the end
            current = current->next;
        }
        current->next = new_node;  // Link the last node to new_node
    }
}

// Function to delete the first node from the list.
void delete_beg() {
    if (head != NULL) {
        head = head->next;  // Move head to the next node
    }
}

// Function to delete a node at a specific position.
void delete_index(int position) {
    current = head;
    position--;
    while (--position) {  // Traverse to the node before the target position
        current = current->next;
    }
    current->next = current->next->next;  // Bypass the target node
}

// Function to delete all nodes in the list by setting head to NULL.
void delete_all() {
    head = NULL;  // Removes the reference to the list
}

// Function to reverse the list iteratively.
node reverse_node() {
    current = head;
    node prev = NULL;

    while (current != NULL) {
        temp = current->next;   // Store the next node
        current->next = prev;   // Reverse the link
        prev = current;         // Move prev and current one step forward
        current = temp;
    }
    head = prev;  // Set the new head of the reversed list
}

// Function to reverse the list recursively.
node recursive_reverse_node(node current) {
    if (current == NULL || current->next == NULL) {  // Base case: end of list or single node
        return current;
    }

    node new_head = recursive_reverse_node(current->next);  // Recursively reverse the rest

    current->next->next = current;  // Reverse the link
    current->next = NULL;

    return new_head;
}

int main(int argc, char const *argv[]) {
    create_node(45);
    create_node(55);
    insert_end(60);
    insert_beg(70);
    insert_index(69, 3);

    print_node();  // Print the list before reversal

    head = recursive_reverse_node(head);  // Reverse the list recursively
    print_node();  // Print the list after reversal

    return 0;
}
