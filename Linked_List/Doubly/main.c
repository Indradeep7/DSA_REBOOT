#include <stdio.h>
#include <stdlib.h>

// Node structure definition with `prev` and `next` pointers
typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} *node;

node head = NULL, temp;

// Function to create and insert a node at the end of the doubly linked list
void create_node(int data) {
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        new_node->prev = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        new_node->prev = temp;
        temp->next = new_node;
    }
}

// Function to insert a node at the beginning of the doubly linked list
void insert_beg(int data) {
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    }
}

// Function to insert a node at a specific position
void insert_index(int data, int pos) {
    node new_node = (node)malloc(sizeof(struct node));
    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    } else {
        temp = head;
        int x = 1;

        // Traverse to the node before the target position
        while (temp->next != NULL && x < pos - 1) {
            temp = temp->next;
            x++;
        }

        // Inserting the new node between temp and temp->next
        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;

        if (new_node->next != NULL) { // If not inserting at end
            new_node->next->prev = new_node;
        }
    }
}

// Function to delete the first node (beginning of the list)
void delete_beg() {
    if (head == NULL) {
        return; // Empty list check
    } else {
        node to_delete = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        free(to_delete); // Free the removed node
    }
}

// Function to delete a node at a specific position
void delete_index(int pos) {
    if (head == NULL || pos < 1) { // Check if list is empty or pos is invalid
        return;
    }

    if (pos == 1) { // Special case for deleting the head
        delete_beg();
        return;
    }

    temp = head;
    int x = 1;

    // Traverse to the node before the target position
    while (temp->next != NULL && x < pos - 1) {
        temp = temp->next;
        x++;
    }

    // If position is out of bounds
    if (temp->next == NULL) {
        return;
    }

    // Standard deletion
    node to_delete = temp->next;
    temp->next = to_delete->next;

    if (to_delete->next != NULL) {
        to_delete->next->prev = temp;
    }

    free(to_delete); // Free the removed node
}

// Function to delete the last node (end of the list)
void delete_end() {
    if (head == NULL) {
        return; // List is empty, nothing to delete
    }

    if (head->next == NULL) { // Only one node in the list
        free(head); // Free the only node
        head = NULL; // Update head to NULL (empty list)
    } else {
        temp = head;
        
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Adjust the previous node's next pointer to NULL
        temp->prev->next = NULL;

        // Free the last node
        free(temp);
    }
}



// Function to print all nodes in the list
void print_node() {
    int sno = 1;
    temp = head;
    while (temp != NULL) {
        printf("%d.data = %d\n",sno, temp->data);
        temp = temp->next;
        sno++;
    }
}

int main(int argc, char const *argv[]) {
    // Create initial nodes and print the list
    printf("Initial creation of nodes:\n");
    create_node(5);
    create_node(7);
    create_node(6);
    print_node();

    // Insert at the beginning and print the list
    printf("\nInsert 18 at the beginning:\n");
    insert_beg(18);
    print_node();

    // Insert at a specific index (position 4 in this case) and print the list
    printf("\nInsert 45 at position 4:\n");
    insert_index(45, 4);
    print_node();

    // Delete a node at a specific position (position 4 in this case) and print the list
    printf("\nDelete node at position 4:\n");
    delete_index(4);
    print_node();

    // Delete the first node and print the list
    printf("\nDelete the first node:\n");
    delete_beg();
    print_node();

    // Delete the last node and print the list
    printf("\nDelete the last node:\n");
    delete_end();
    print_node();

    // Insert new nodes at the end to reset the list to a few items and print
    printf("\nInsert 10, 20, and 30 at the end:\n");
    create_node(10);
    create_node(20);
    create_node(30);
    print_node();

    return 0;
}
