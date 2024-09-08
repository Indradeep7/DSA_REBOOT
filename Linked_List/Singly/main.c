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
    new_node = (node)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
    }
    else {
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
        printf("data = %d\n",temp->data); 
        temp = temp->next;
    }
    printf("\n-------------------$\n");
}

void insert_beg(int data) {

    node new_node = NULL;
    new_node = (node)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    new_node->data = head->data;
    head->data = data;

    new_node->next = head->next; 
    head->next = new_node;

}

void insert_index(int data,int position) {

    node new_node = NULL;
    new_node = (node)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    current = head;
    position--;
    while (--position) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    
}

void insert_end(int data) {

    node new_node = NULL;
    new_node = (node)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    
}


void delete_beg() {

    head = head->next;

}
void delete_index(int position) {
    current = head;
    position--;
    while(--position) {
        current = current->next;
    }

    current->next = current->next->next;
    
}

// for deleting or inserting a node, we need to move to the position before the (wanna be inserted/deleted position)

void delete_all() {

    head = NULL;

}

node reverse_node() {

    current = head;
    node prev = NULL;

    while(current != NULL) {

        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    
    }
    head = prev;
    
}

node recursive_reverse_node(node current) {
    if (current == NULL || current->next == NULL) {
        return current;
    }

    node new_head = recursive_reverse_node(current->next);

    node nextnode = current->next;
    nextnode->next = current;
    current->next = NULL;

    return new_head;
}



int main(int argc, char const *argv[])
{
    create_node(45);
    create_node(55);   
    insert_end(60); 
    insert_beg(70);
    insert_index(69,3);
    // delete_beg();
    // delete_index(3);
    // delete_all();
    // reverse_node();
    print_node();
    head = recursive_reverse_node(head);
    print_node();
    return 0;
}