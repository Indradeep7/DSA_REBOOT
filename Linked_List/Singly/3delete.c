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


int main()
{
    create_node(70);
    create_node(45);
    create_node(69);
    create_node(55);   
    create_node(60); 
    print_node();

    delete_index(3);
    delete_beg();
    print_node();

    delete_all();
    print_node();


    return 0;
}