#include <stdio.h>
#include <stdlib.h>

// *node helps to declare a node as a pointer directly, which simplifies working with linked lists where nodes are dynamically allocated. 
typedef struct node
{
    int data;
    struct node *next;
} *node;

node head, temp , current;

void create_node(int data) {
    node new_node = NULL;
    // Allocate memory for the node itself (not for the pointer)
    new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_node() {
    temp = head;
    printf("\n$-------------------\n");
    while (temp != NULL) {
        printf("data = %d\n", temp->data); 
        temp = temp->next;
    }
    printf("\n-------------------$\n");
}

// Iterative reverse function
node reverse_node() {
    current = head;
    node prev = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}

// Recursive reverse function that takes the head node as an argument
node recursive_reverse_node(node current) {
    // Base case: If the list is empty or has only one node, or list has ended, return the current node (new head)
    if (current == NULL || current->next == NULL) {
        return current;
    }

    // Recursively reverse the rest of the list from the next node onward
    // next node is the new_head
    node new_head = recursive_reverse_node(current->next);

    // After recursion, reverse the current node's next pointer
    node nextnode = current->next;//starts with last node
    nextnode->next = current;// reverses the next

    // Set the current node's next to NULL (as it will become the last node in upcoming round)
    current->next = NULL;

    // Return the new head (which is the last node in the original list)
    return new_head;
}


int main()
{
    // Creating a sample linked list
    create_node(45);
    create_node(55);   
    create_node(60); 
    create_node(70);
    create_node(69);

    // Print the original list
    print_node();

    // Reverse the linked list recursively and assign the returned head to 'head'
    head = recursive_reverse_node(head);

    // Print the reversed linked list
    print_node();

    return 0;
}
